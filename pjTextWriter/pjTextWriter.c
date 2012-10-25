/*******************************************************************************
* File Name: pjTextWriter.c
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-23 initial release version
*******************************************************************************/

#include "pjTextWriter.h"

/*******************************************************************************
* Version 
* version = major.minor.patch
            8-bits 8-bits 8-bits
*******************************************************************************/
										/***************************************
										* pjTextWriter_GetVersionPatch
										***************************************/
int pjTextWriter_GetVersionPatch( void ){
	return PJTEXTWRITER_VERSION_PATCH;	
}
										/***************************************
										* pjTextWriter_GetVersionMinor
										***************************************/
int pjTextWriter_GetVersionMinor( void ){
	return PJTEXTWRITER_VERSION_MINOR;	
}
										/***************************************
										* pjTextWriter_GetVersionMajor
										***************************************/
int pjTextWriter_GetVersionMajor( void ){
	return PJTEXTWRITER_VERSION_MAJOR;	
}
										/***************************************
										* pjTextWriter_GetVersion
										***************************************/
long int pjTextWriter_GetVersion( void ){
	return (PJTEXTWRITER_VERSION_MAJOR<<16) | (PJTEXTWRITER_VERSION_MINOR<<8) | PJTEXTWRITER_VERSION_PATCH;	
}

/*******************************************************************************
* Public Methods
*******************************************************************************/
                                        /***************************************
                                        * pjTextWriter_OpenFile
                                        ***************************************/
int pjTextWriter_OpenFile( pjTextWriter* textWriter, char* path ){
    textWriter->fileHandle = fopen( path, "w" );
    if( textWriter->fileHandle == NULL) 
        return 0;
    return 1;
}
                                        /***************************************
                                        * pjTextWriter_CloseFile
                                        ***************************************/
int pjTextWriter_CloseFile( pjTextWriter* textWriter ){
    if( textWriter->fileHandle != NULL ){
        fclose( textWriter->fileHandle );   
    }
}
                                        /***************************************
                                        * pjTextWriter_WriteChars
                                        ***************************************/
int pjTextWriter_WriteChars( pjTextWriter* textWriter, char* writeChars ){
    if( textWriter->fileHandle == NULL )
        return -1;
        
    char* p = writeChars;
    while( *p != '\0' ){
        if( !fwrite( p, sizeof(char), 1, textWriter->fileHandle ) )
            return 0;
        p++;  
    }
    
    return 1;
}
                                        /***************************************
                                        * pjTextWriter_WriteLine
                                        ***************************************/
int pjTextWriter_WriteLine( pjTextWriter* textWriter, char* writeLine ){
    if( textWriter->fileHandle == NULL )
        return -1;
        
    char* p = writeLine;
    while( *p != '\0' ){
        if( !fwrite( p, sizeof(char), 1, textWriter->fileHandle ) )
            return 0;
        p++;   
    }
    
    char c = '\r';
    char n = '\n';
    fwrite( &c, sizeof(char), 1, textWriter->fileHandle );
    fwrite( &n, sizeof(char), 1, textWriter->fileHandle );
    
    return 1;
}
                                        /***************************************
                                        * pjTextWriter_New
                                        ***************************************/
pjTextWriter* pjTextWriter_New( void ){
    return (pjTextWriter*)malloc( sizeof(pjTextWriter) );
}
                                        /***************************************
                                        * pjTextWriter_Delete
                                        ***************************************/
void pjTextWriter_Delete( pjTextWriter* textWriter ){
    if( textWriter != 0 ){
        free( textWriter );
        textWriter = 0;   
    }   
}
