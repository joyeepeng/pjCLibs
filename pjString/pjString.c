/*******************************************************************************
* File Name: pjString.c
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-20 initial release version
*******************************************************************************/

#include "pjString.h"

/*******************************************************************************
* Version 
* version = major.minor.patch
            8-bits 8-bits 8-bits
*******************************************************************************/
										/***************************************
										* pjPath_GetVersionPatch
										***************************************/
int pjString_GetVersionPatch( void ){
	return PJSTRING_VERSION_PATCH;	
}
										/***************************************
										* pjPath_GetVersionMinor
										***************************************/
int pjString_GetVersionMinor( void ){
	return PJSTRING_VERSION_MINOR;	
}
										/***************************************
										* pjPath_GetVersionMajor
										***************************************/
int pjString_GetVersionMajor( void ){
	return PJSTRING_VERSION_MAJOR;	
}
										/***************************************
										* pjPath_GetVersion
										***************************************/
long int pjString_GetVersion( void ){
	return (PJSTRING_VERSION_MAJOR<<16) | (PJSTRING_VERSION_MINOR<<8) | PJSTRING_VERSION_PATCH;	
}
/*******************************************************************************
* Public Methods
*******************************************************************************/
										/***************************************
										* pjString_Find
										***************************************/
int pjString_Find( char* string, char findChar ){
	char* p = string;
	int pos = 0;
	while( *p != '\0' ){
		if( *p == findChar ) break;	
		p++;
		pos++;
	}
	
	return (*p == '\0') ? -1 : pos;
}
										/***************************************
										* pjString_Length
										***************************************/
int pjString_Length( char* string ){
	char* p = string;
	int length = 0;
	while( *p != '\0' ) {
		length++;
		p++;
	}
	return length;
}
