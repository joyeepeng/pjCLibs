/*******************************************************************************
* File Name: pjTextWriter.h
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-23 initial release version
*******************************************************************************/
#ifndef __PJTEXTWRITER_H__
#define __PJTEXTWRITER_H__

#include <stdio.h>

typedef struct tagPjTextWriter{
    FILE* fileHandle;
}pjTextWriter;

#define PJTEXTWRITER_VERSION_PATCH		1
#define PJTEXTWRITER_VERSION_MINOR		0
#define PJTEXTWRITER_VERSION_MAJOR		0

/*******************************************************************************
* Version Control
*******************************************************************************/
long int pjTextWriter_GetVersion( void );
int pjTextWriter_GetVersionPatch( void );
int pjTextWriter_GetVersionMinor( void );
int pjTextWriter_GetVersionMajor( void );

/*******************************************************************************
* Public Methods
*******************************************************************************/
int pjTextWriter_OpenFile( pjTextWriter* textWriter, char* path );
int pjTextWriter_WriteChars( pjTextWriter* textWriter, char* writeChars );
int pjTextWriter_WriteLine( pjTextWriter* textWriter, char* writeLine );
int pjTextWriter_CloseFile( pjTextWriter* textWriter );

#endif
