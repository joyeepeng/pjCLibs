/*******************************************************************************
* File Name: pjParallelPort.h
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-26 initial release version
*******************************************************************************/

#ifndef __PJPARALLELPORT_H__
#define __PJPARALLELPORT_H__

#include <windows.h>

typedef enum{
    PARALLELPORT_D0 = 0,
    PARALLELPORT_D1,
    PARALLELPORT_D2,
    PARALLELPORT_D3,
    PARALLELPORT_D4,
    PARALLELPORT_D5,
    PARALLELPORT_D6,
    PARALLELPORT_D7
}PARALLELPORT_PINS;

typedef enum{
    PARALLELPORT_LOW = 0,
    PARALLELPORT_HIGH
}PARALLELPORT_VALUES;

#define PJPARALLELPORT_VERSION_PATCH	1
#define PJPARALLELPORT_VERSION_MINOR	0
#define PJPARALLELPORT_VERSION_MAJOR	0

/*******************************************************************************
* Version Control
*******************************************************************************/
long int pjParallelPort_GetVersion( void );
int pjParallelPort_GetVersionPatch( void );
int pjParallelPort_GetVersionMinor( void );
int pjParallelPort_GetVersionMajor( void );

/*******************************************************************************
* Public Methods
*******************************************************************************/
void pjParallelPort_Output( int address, unsigned char value );
void pjParallelPort_SetPinValue( int address, PARALLELPORT_PINS pin, 
                                 PARALLELPORT_VALUES value );

#endif
