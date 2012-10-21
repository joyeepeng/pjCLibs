/*******************************************************************************
* File Name: pjString.h
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-20 initial release version
*******************************************************************************/
#ifndef __PJSTRING_H__
#define __PJSTRING_H__

#define PJSTRING_VERSION_PATCH		1
#define PJSTRING_VERSION_MINOR		0
#define PJSTRING_VERSION_MAJOR		0

/*******************************************************************************
* Version Control
*******************************************************************************/
long int pjString_GetVersion( void );
int pjString_GetVersionPatch( void );
int pjString_GetVersionMinor( void );
int pjString_GetVersionMajor( void );
/*******************************************************************************
* Public Methods
*******************************************************************************/
int pjString_Find( char* string, char findChar );
int pjString_Length( char* string );

#endif
