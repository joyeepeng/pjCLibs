/*******************************************************************************
* File Name: pjTextReader.c
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-22 initial release version
*******************************************************************************/

#include "pjTextReader.h"

/*******************************************************************************
* Version 
* version = major.minor.patch
            8-bits 8-bits 8-bits
*******************************************************************************/
										/***************************************
										* pjTextReader_GetVersionPatch
										***************************************/
int pjTextReader_GetVersionPatch( void ){
	return PJTEXTREADER_VERSION_PATCH;	
}
										/***************************************
										* pjTextReader_GetVersionMinor
										***************************************/
int pjTextReader_GetVersionMinor( void ){
	return PJTEXTREADER_VERSION_MINOR;	
}
										/***************************************
										* pjTextReader_GetVersionMajor
										***************************************/
int pjTextReader_GetVersionMajor( void ){
	return PJTEXTREADER_VERSION_MAJOR;	
}
										/***************************************
										* pjTextReader_GetVersion
										***************************************/
long int pjTextReader_GetVersion( void ){
	return (PJTEXTREADER_VERSION_MAJOR<<16) | (PJTEXTREADER_VERSION_MINOR<<8) | PJTEXTREADER_VERSION_PATCH;	
}
/*******************************************************************************
* Public Methods
*******************************************************************************/
                                        /***************************************
                                        * pjTextReader_OpenFile
                                        ***************************************/
int pjTextReader_OpenFile( pjTextReader* textReader, char* path ){
    textReader->fileHandle = fopen( path, "r" );
    if( textReader->fileHandle == NULL ){
        return 0;   
    }
    
    return 1;
}
                                        /***************************************
                                        * pjTextReader_CloseFile
                                        ***************************************/
int pjTextReader_CloseFile( pjTextReader* textReader ){
    if( textReader->fileHandle != NULL ){
        fclose( textReader->fileHandle );   
    }   
}
                                        /***************************************
                                        * pjTextReader_GetLineNumber
                                        ***************************************/
int pjTextReader_GetLineNumber( pjTextReader* textReader ){
    int lineNumber = 0;
    
    if( textReader->fileHandle == NULL ) return -1;
    
    char ch = 0;
    char prevChar = 0;
    long int pos = ftell( textReader->fileHandle );
    while( fread( &ch, sizeof(char), 1, textReader->fileHandle ) ){
        prevChar = ch;
        if( ch == '\n' ) lineNumber++;   
    }
    
    if( prevChar != '\n' ) lineNumber++;
    
    fseek( textReader->fileHandle, pos, SEEK_SET );
    
    return lineNumber;
}
                                        /***************************************
                                        * pjTextReader_GetMaxLineLength
                                        ***************************************/
int pjTextReader_GetMaxLineLength( pjTextReader* textReader ){
    int maxLineLength = 0;
    
    if( textReader->fileHandle == NULL ) return -1;
    
    char ch = 0;
    char prevChar = 0;
    int currentLineLength = 0;
    long int pos = ftell( textReader->fileHandle );
    while( fread( &ch, sizeof(char), 1, textReader->fileHandle ) ){
        if( ch == '\n' ){
            if( prevChar == '\r' ) currentLineLength--;
            if( currentLineLength > maxLineLength ){
                maxLineLength = currentLineLength;
            }
            currentLineLength = 0;
        }else{
            currentLineLength++;
        }
        prevChar = ch;  
    }
    
    fseek( textReader->fileHandle, pos, SEEK_SET );
    
    return maxLineLength;
}
                                        /***************************************
                                        * pjTextReader_ReadChars
                                        ***************************************/
int pjTextReader_ReadChars( pjTextReader* textReader, int length, char* line ){
    char* p = line;
    
    if( textReader->fileHandle == NULL ) return -1;
    
    int len = 0;
    char ch = 0;
    while( len < length ){
        if( fread( &ch, sizeof(char), 1, textReader->fileHandle ) ){
            *p = ch;
            p++;
            len++;
        }else{
            break;
        }
    }
    *p = '\0';
    
    return 1;
}
                                       /****************************************
                                       * pjTextReader_ReadLine
                                       ****************************************/
int pjTextReader_ReadLine( pjTextReader* textReader, char* line ){
    if( textReader->fileHandle == NULL ) return -1;
    
    char ch = 0;
    char* p = line;
    while( fread( &ch, sizeof(char), 1, textReader->fileHandle ) ){
        if( ch != '\n' && ch != '\r' ){
            *p = ch;
            p++;
        }else{
            break; 
        }
    }
    *p = '\0';
    
    return 1;
}
