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
int pjString_FindAll( char* string, char findChar, int* pos );
int pjString_Replace( char* string, char oldChar, char newChar );
int pjString_Length( char* string );
int pjString_Copy( char* string, char* fromString );
int pjString_CopyLimited( char* string, char* fromString, int length );
int pjString_Append( char* string, char* append );
int pjString_Substring( char* string, int start, int length, char* substring );
int pjString_Equals( char* str1, char* str2 );
int pjString_ToUpper( char* string );
int pjString_ToLower( char* string );

#endif
