/*******************************************************************************
* File Name: pjJpegFile.c
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-23 initial release version
*******************************************************************************/

#include "pjJpegFile.h"

/*******************************************************************************
* Version 
* version = major.minor.patch
            8-bits 8-bits 8-bits
*******************************************************************************/
                                        /***************************************
                                        * pjJpegFile_GetVersionPatch
                                        ***************************************/
int pjJpegFile_GetVersionPatch( void ){
	return PJJPEGFILE_VERSION_PATCH;	
}
                                        /***************************************
                                        * pjJpegFile_GetVersionMinor
                                        ***************************************/
int pjJpegFile_GetVersionMinor( void ){
	return PJJPEGFILE_VERSION_MINOR;	
}
                                        /***************************************
                                        * pjJpegFile_GetVersionMajor
                                        ***************************************/
int pjJpegFile_GetVersionMajor( void ){
	return PJJPEGFILE_VERSION_MAJOR;	
}
                                        /***************************************
                                        * pjJpegFile_GetVersion
                                        ***************************************/
long int pjJpegFile_GetVersion( void ){
	return (PJJPEGFILE_VERSION_MAJOR<<16) | (PJJPEGFILE_VERSION_MINOR<<8) | PJJPEGFILE_VERSION_PATCH;	
}
