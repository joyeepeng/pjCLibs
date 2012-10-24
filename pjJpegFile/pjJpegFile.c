/*******************************************************************************
* File Name: pjJpegFile.c
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-23 initial release version
*******************************************************************************/

#include "pjJpegFile.h"

static void PjLibJpeg_error_exit (j_common_ptr cinfo)
{
  /* cinfo->err really points to a my_error_mgr struct, so coerce pointer */
  my_error_ptr myerr = (my_error_ptr) cinfo->err;

  /* Always display the message. */
  /* We could postpone this until after returning, if we chose. */
  (*cinfo->err->output_message) (cinfo);

  /* Return control to the setjmp point */
  longjmp(myerr->setjmp_buffer, 1);
}

/*******************************************************************************
* Version 
* version = major.minor.patch
            8-bits 8-bits 8-bits
*******************************************************************************/
                                        /***************************************
                                        * pjJpegFile_GetVersionPatch
                                        ***************************************/
int pjJpegFile_GetVersionPatch( void ){
	return PJJPEGFILE_VERSION_PATCH;	
}
                                        /***************************************
                                        * pjJpegFile_GetVersionMinor
                                        ***************************************/
int pjJpegFile_GetVersionMinor( void ){
	return PJJPEGFILE_VERSION_MINOR;	
}
                                        /***************************************
                                        * pjJpegFile_GetVersionMajor
                                        ***************************************/
int pjJpegFile_GetVersionMajor( void ){
	return PJJPEGFILE_VERSION_MAJOR;	
}
                                        /***************************************
                                        * pjJpegFile_GetVersion
                                        ***************************************/
long int pjJpegFile_GetVersion( void ){
	return (PJJPEGFILE_VERSION_MAJOR<<16) | (PJJPEGFILE_VERSION_MINOR<<8) | PJJPEGFILE_VERSION_PATCH;	
}
/*******************************************************************************
* Public Methods
*******************************************************************************/
                                        /***************************************
                                        * pjJpegFile_ReadFile
                                        ***************************************/
int pjJpegFile_ReadFile( char* fileName, pjJpegFile* jpegFile ){
    struct jpeg_decompress_struct cinfo;
	struct PjLibJpeg_error_mgr jerr;

	FILE* infile;
	JSAMPROW row_pointer[1];
	int row_stride;

	int counter = 0;
	int i = 0;

	if( ( infile = fopen(fileName,"rb") ) == NULL ){
		fprintf( stderr,"can't open %s to read.\n", fileName );
		return 0;
	}

	cinfo.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = PjLibJpeg_error_exit;
	if( setjmp(jerr.setjmp_buffer) ){
		jpeg_destroy_decompress(&cinfo);
		fclose(infile);
		return 0;
	}

	jpeg_create_decompress(&cinfo);
	jpeg_stdio_src(&cinfo,infile);
	jpeg_read_header(&cinfo,TRUE);
	jpeg_start_decompress(&cinfo);
	row_stride = cinfo.output_width * cinfo.output_components;

	row_pointer[0] = (unsigned char*)malloc( cinfo.output_width * cinfo.num_components );	

	jpegFile->Width = cinfo.output_width;
	jpegFile->Height = cinfo.output_height;
	jpegFile->Stride = row_stride;
	jpegFile->Pixels = (unsigned char*)malloc( cinfo.output_width * cinfo.output_height * cinfo.output_components * sizeof(char) );
	
	while( cinfo.output_scanline < cinfo.output_height ){		
		jpeg_read_scanlines( &cinfo, row_pointer, 1 );
		
		for(i = 0;i < (cinfo.image_width * cinfo.num_components); i++)
			jpegFile->Pixels[counter++] = row_pointer[0][i];
	}

	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);

	fclose(infile);
	free(row_pointer[0]);

	return 1;  
}
                                        /***************************************
                                        * pjJpegFile_WriteFile
                                        ***************************************/
int pjJpegFile_WriteFile( const pjJpegFile* jpegFile, char* fileName, int quality ){
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;
	FILE * outfile;		/* target file */
  	JSAMPROW row_pointer[1];	/* pointer to JSAMPLE row[s] */
  	int row_stride;		/* physical row width in image buffer */

	int counter = 0;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);

	if ((outfile = fopen(fileName, "wb")) == NULL) {
    	fprintf(stderr, "can't open %s to write.\n", fileName);
    	exit(1);
  	}
  	jpeg_stdio_dest(&cinfo, outfile);

  	cinfo.image_width = jpegFile->Width; 	/* image width and height, in pixels */
  	cinfo.image_height = jpegFile->Height;
  	cinfo.input_components = 3;		/* # of color components per pixel */
  	cinfo.in_color_space = JCS_RGB; 	/* colorspace of input image */
	jpeg_set_defaults(&cinfo);

	jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);
	jpeg_start_compress(&cinfo, TRUE);

  	while (cinfo.next_scanline < cinfo.image_height) {
    	/* jpeg_write_scanlines expects an array of pointers to scanlines.
     	* Here the array is only one element long, but you could pass
     	* more than one scanline at a time if that's more convenient.
     	*/
    	row_pointer[0] = & jpegFile->Pixels[cinfo.next_scanline * cinfo.image_width * cinfo.input_components];

    	(void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
  	}

	jpeg_finish_compress(&cinfo);
	fclose(outfile);

	jpeg_destroy_compress(&cinfo);

	return 1;  
}
                                        /***************************************
                                        * pjJpegFile_GetPixel
                                        ***************************************/
pjJpegColor pjJpegFile_GetPixel( const pjJpegFile* jpegFile, 
                                unsigned int row, unsigned int col ){
    pjJpegColor color;

	if( !(jpegFile->Height > row && row >= 0) ){
		fprintf(stderr, "row must be in 0 to %d.\r\n", jpegFile->Height-1);
		return color;
	}

	if( !( jpegFile->Width >col && col >= 0 ) ){
		fprintf(stderr, "col must be in 0 to %d.\r\n", jpegFile->Width-1);
		return color;
	}

	color.R = (unsigned char)*(jpegFile->Pixels+jpegFile->Stride*row+col*3);
	color.G = (unsigned char)*(jpegFile->Pixels+jpegFile->Stride*row+col*3+1);
	color.B = (unsigned char)*(jpegFile->Pixels+jpegFile->Stride*row+col*3+2);
	
	return color;                             
}
                                        /***************************************
                                        * pjJpegFile_SetPixel
                                        ***************************************/
void pjJpegFile_SetPixel( pjJpegFile* jpegFile, unsigned int row, 
                            unsigned int col, pjJpegColor clr ){
    if( !(jpegFile->Height > row && row >= 0) ){
		fprintf(stderr, "row must be in 0 to %d.\r\n", jpegFile->Height-1);
		return;
	}

	if( !( jpegFile->Width >col && col >= 0 ) ){
		fprintf(stderr, "col must be in 0 to %d.\r\n", jpegFile->Width-1);
		return;
	}

	*(jpegFile->Pixels+jpegFile->Stride*row+col*3) = clr.R;
	*(jpegFile->Pixels+jpegFile->Stride*row+col*3+1) = clr.G;
	*(jpegFile->Pixels+jpegFile->Stride*row+col*3+2) = clr.B;                               
}
                                        /***************************************
                                        * pjJpegFile_SetRegionColor
                                        ***************************************/
void pjJpegFile_SetRegionColor( pjJpegFile* jpegFile, unsigned int x, 
                                unsigned int y, 
                                unsigned int width, 
                                unsigned int height, 
                                pjJpegColor clr ){
    int i = 0, j = 0;
	for( i = x; i < (x + width); i++ ){
		for( j = y; j < (y + height); j++ ){
			pjJpegFile_SetPixel( jpegFile, j, i, clr );
		}
	}                         
}
                                        /***************************************
                                        * pjJpegFile_Dispose
                                        ***************************************/
void pjJpegFile_Dispose( pjJpegFile* jpegFile ){
    if( jpegFile->Pixels != NULL ){
       free(jpegFile->Pixels);
	   jpegFile->Pixels = 0;
    }
}
