/*******************************************************************************
* File Name: pjParallelPort.c
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-26 initial release version
*******************************************************************************/

#include "pjParallelPort.h"

/*******************************************************************************
* Version 
* version = major.minor.patch
            8-bits 8-bits 8-bits
*******************************************************************************/
                                        /***************************************
                                        * pjParallelPort_GetVersionPatch
                                        ***************************************/
int pjParallelPort_GetVersionPatch( void ){
	return PJPARALLELPORT_VERSION_PATCH;	
}
                                        /***************************************
                                        * pjParallelPort_GetVersionMinor
                                        ***************************************/
int pjParallelPort_GetVersionMinor( void ){
	return PJPARALLELPORT_VERSION_MINOR;	
}
                                        /***************************************
                                        * pjParallelPort_GetVersionMajor
                                        ***************************************/
int pjParallelPort_GetVersionMajor( void ){
	return PJPARALLELPORT_VERSION_MAJOR;	
}
                                        /***************************************
                                        * pjParallelPort_GetVersion
                                        ***************************************/
long int pjParallelPort_GetVersion( void ){
	return (PJPARALLELPORT_VERSION_MAJOR<<16) | (PJPARALLELPORT_VERSION_MINOR<<8) | PJPARALLELPORT_VERSION_PATCH;	
}

/*******************************************************************************
* Public Methods
*******************************************************************************/
                                        /***************************************
                                        * pjParallelPort_Output
                                        ***************************************/
void pjParallelPort_Output( int address, unsigned char value ){
    HINSTANCE hDll = LoadLibrary( "inpout32.dll" );
    FARPROC lpfnOutput = GetProcAddress( hDll, "Out32" );
    (*lpfnOutput)( address, value );
    FreeLibrary( hDll );
}
                                        /***************************************
                                        * pjParallelPort_SetPinValue
                                        ***************************************/
void pjParallelPort_SetPinValue( int address, PARALLELPORT_PINS pin, 
                                 PARALLELPORT_VALUES value ){
    pjParallelPort_Output( address, (unsigned char)(value << pin) );
}
