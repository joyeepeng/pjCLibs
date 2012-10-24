/*******************************************************************************
* File Name: pjJpegFile.h
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-23 initial release version
*******************************************************************************/

#ifndef __PJJPEGFILE_H__
#define __PJJPEGFILE_H__

#include <stdio.h>
#include <setjmp.h>

#include "jpeglib.h"

#define PJJPEGFILE_VERSION_PATCH	1
#define PJJPEGFILE_VERSION_MINOR	0
#define PJJPEGFILE_VERSION_MAJOR	0

typedef struct tagPjJpegColor{
	unsigned char R;
	unsigned char G;
	unsigned char B;
}pjJpegColor;

typedef struct tagPjJpegFile{
	unsigned char* Pixels;
	unsigned int Width;
	unsigned int Height;
	unsigned int Stride;
}pjJpegFile;

struct PjLibJpeg_error_mgr {
  struct jpeg_error_mgr pub;	/* "public" fields */

  jmp_buf setjmp_buffer;	/* for return to caller */
};

typedef struct PjLibJpeg_error_mgr * my_error_ptr;

/*******************************************************************************
* Version Control
*******************************************************************************/
long int pjJpegFile_GetVersion( void );
int pjJpegFile_GetVersionPatch( void );
int pjJpegFile_GetVersionMinor( void );
int pjJpegFile_GetVersionMajor( void );

/*******************************************************************************
* Public Methods
*******************************************************************************/
int pjJpegFile_ReadFile( char* fileName, pjJpegFile* jpegFile );
int pjJpegFile_WriteFile( const pjJpegFile* jpegFile, char* fileName, int quality );
pjJpegColor pjJpegFile_GetPixel( const pjJpegFile* jpegFile, unsigned int row, unsigned int col );
void pjJpegFile_SetPixel( pjJpegFile* jpegFile, unsigned int row, unsigned int col, pjJpegColor clr );
void pjJpegFile_SetRegionColor( pjJpegFile* jpegFile, unsigned int x, 
                                unsigned int y, 
                                unsigned int width, 
                                unsigned int height, 
                                pjJpegColor clr );
void pjJpegFile_Dispose( pjJpegFile* jpegFile );

#endif
