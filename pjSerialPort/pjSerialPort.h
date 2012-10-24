/*******************************************************************************
* File Name: pjSerialPort.h
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-24 initial release version
*******************************************************************************/

#ifndef __PJSERIALPORT_H__
#define __PJSERIALPORT_H__

#include <windows.h>
#include <tchar.h>

#define PJSERIALPORT_VERSION_PATCH	1
#define PJSERIALPORT_VERSION_MINOR	0
#define PJSERIALPORT_VERSION_MAJOR	0

#define TIMEOUT_READ_INTERVAL           0xFFFFFFFF
#define TIMEOUT_READ_TOTAL_MULTIPLIER   0
#define TIMEOUT_READ_TOTAL_CONSTANT     0

#define TIMEOUT_WRITE_TOTAL_MULTIPLIER  0
#define TIMEOUT_WRITE_TOTAL_CONSTANT    0

#define BUFFER_INPUT_RECOMMEND          10000
#define BUFFER_OUTPUT_RECOMMEND         10000

#define TIMEOUT_READCOMM_EVENT          4000
#define TIMEOUT_WRITECOMM_EVENT         2000

#define FC_DTRDSR   0x01
#define FC_RTSCTS   0x02
#define FC_XONXOFF  0x04
#define ASCII_BEL   0x07
#define ASCII_BS    0x08
#define ASCII_LF    0x0A
#define ASCII_CR    0x0D
#define ASCII_XON   0x11
#define ASCII_XOFF  0x13

#define SP_ONE_STOPBIT      0
#define SP_ONE5_STOPBITS    1
#define SP_TWO_STOPBITS     2

#define SP_NO_PARITY        0
#define SP_ODD_PARITY       1
#define SP_EVEN_PARITY      2
#define SP_MARK_PARITY      3
#define SP_SPACE_PARITY     4

#define MAX_BUFFER_LENGTH   512

typedef void (*pjSerialPort_Callback)();

/*******************************************************************************
* Version Control
*******************************************************************************/
long int pjSerialPort_GetVersion( void );
int pjSerialPort_GetVersionPatch( void );
int pjSerialPort_GetVersionMinor( void );
int pjSerialPort_GetVersionMajor( void );

/*******************************************************************************
* Public Methods
*******************************************************************************/
void pjSerialPort_Initialize( void );
int pjSerialPort_OpenPort( int port, int baud_rate, int parity, int data_bits,
                           int stop_bits );
int pjSerialPort_ClosePort( void );

int pjSerialPort_ReadData( void* data, int length );
int pjSerialPort_WriteData( const char* data );
int pjSerialPort_BytesToRead( void );
int pjSerialPort_IsOpened( void );
int pjSerialPort_WriteChar( char ch );
int pjSerialPort_WriteLine( const char* line );
char* pjSerialPort_ReadLine( void );
char* pjSerialPort_ReadLineWithInterrupt( int pressKeyExit );
char* pjSerialPort_ReadLineWithCallback( char key, pjSerialPort_Callback callback );
char* pjSerialPort_ReadLineWithCallbacks( char* keys, pjSerialPort_Callback* callbacks );

#endif
