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
