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

#endif
