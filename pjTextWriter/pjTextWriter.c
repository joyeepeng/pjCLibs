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
