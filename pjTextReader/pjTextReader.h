/*******************************************************************************
* File Name: pjTextReader.h
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-22 initial release version
*******************************************************************************/
#ifndef __PJTEXTREADER_H__
#define __PJTEXTREADER_H__

#define PJTEXTREADER_VERSION_PATCH		1
#define PJTEXTREADER_VERSION_MINOR		0
#define PJTEXTREADER_VERSION_MAJOR		0

/*******************************************************************************
* Version Control
*******************************************************************************/
long int pjTextReader_GetVersion( void );
int pjTextReader_GetVersionPatch( void );
int pjTextReader_GetVersionMinor( void );
int pjTextReader_GetVersionMajor( void );

#endif
