/*******************************************************************************
* File Name: pjSerialPort.c
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-20 initial release version
*******************************************************************************/

#include "pjSerialPort.h"

HANDLE pjSerialPort_hIDComDev;
OVERLAPPED pjSerialPort_overlappedRead;
OVERLAPPED pjSerialPort_overlappedWrite;
int pjSerialPort_isOpened;
char* pjSerialPort_buffer;

/*******************************************************************************
* Version 
* version = major.minor.patch
            8-bits 8-bits 8-bits
*******************************************************************************/
                                        /***************************************
                                        * pjSerialPort_GetVersionPatch
                                        ***************************************/
int pjSerialPort_GetVersionPatch( void ){
	return PJSERIALPORT_VERSION_PATCH;	
}
                                        /***************************************
                                        * pjSerialPort_GetVersionMinor
                                        ***************************************/
int pjSerialPort_GetVersionMinor( void ){
	return PJSERIALPORT_VERSION_MINOR;	
}
                                        /***************************************
                                        * pjSerialPort_GetVersionMajor
                                        ***************************************/
int pjSerialPort_GetVersionMajor( void ){
	return PJSERIALPORT_VERSION_MAJOR;	
}
                                        /***************************************
                                        * pjSerialPort_GetVersion
                                        ***************************************/
long int pjSerialPort_GetVersion( void ){
	return (PJSERIALPORT_VERSION_MAJOR<<16) | (PJSERIALPORT_VERSION_MINOR<<8) | PJSERIALPORT_VERSION_PATCH;	
}
/*******************************************************************************
* Public Methods
*******************************************************************************/
                                        /***************************************
                                        * pjSerialPort_Initialize
                                        ***************************************/
void pjSerialPort_Initialize( void ){
    memset( &pjSerialPort_overlappedRead, 0, sizeof(OVERLAPPED) );
    memset( &pjSerialPort_overlappedWrite, 0, sizeof(OVERLAPPED) );

    pjSerialPort_hIDComDev = NULL;
    pjSerialPort_isOpened = 0;
    
    pjSerialPort_buffer = (char*)malloc( sizeof(char) * MAX_BUFFER_LENGTH );
}
                                        /***************************************
                                        * pjSerialPort_OpenPort
                                        ***************************************/
/*
Parity: 
    0 - none
    1 - odd
    2 - even
    3 - mark
    4 - space
Stop Bits:
    0 - 1 bit
    1 - 1.5 bits
    2 - 2 bits
*/
int pjSerialPort_OpenPort( int port, int baud_rate, int parity, int data_bits,
                           int stop_bits ){
    TCHAR szPort[50];
    DCB dcb;
    COMMTIMEOUTS CommTimeOuts;
    unsigned char ucSet;
    DWORD dwError;

    if( pjSerialPort_isOpened ) return 1;

    wsprintf( szPort, _T("COM%d"), port );
    pjSerialPort_hIDComDev = CreateFile(szPort,
                            GENERIC_READ | GENERIC_WRITE,
                            0,
                            NULL,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,
                            NULL);
    if( !pjSerialPort_hIDComDev ) return 0;

    CommTimeOuts.ReadIntervalTimeout = TIMEOUT_READ_INTERVAL;
    CommTimeOuts.ReadTotalTimeoutMultiplier = TIMEOUT_READ_TOTAL_MULTIPLIER;
    CommTimeOuts.ReadTotalTimeoutConstant = TIMEOUT_READ_TOTAL_CONSTANT;
    CommTimeOuts.WriteTotalTimeoutMultiplier = TIMEOUT_WRITE_TOTAL_MULTIPLIER;
    CommTimeOuts.WriteTotalTimeoutConstant = TIMEOUT_WRITE_TOTAL_CONSTANT;
    SetCommTimeouts( pjSerialPort_hIDComDev, &CommTimeOuts );

    pjSerialPort_overlappedRead.hEvent = CreateEvent( NULL, 1, 0, NULL );
    pjSerialPort_overlappedWrite.hEvent = CreateEvent( NULL, 1, 0, NULL );

    dcb.DCBlength = sizeof(DCB);
    GetCommState( pjSerialPort_hIDComDev, &dcb );
    dcb.BaudRate = baud_rate;
    dcb.ByteSize = data_bits;
    dcb.StopBits = stop_bits;
    dcb.Parity = parity;

    ucSet = (unsigned char)( (FC_RTSCTS & FC_DTRDSR) != 0 );
    ucSet = (unsigned char)( (FC_RTSCTS & FC_RTSCTS) != 0 );
    ucSet = (unsigned char)( (FC_RTSCTS & FC_XONXOFF) != 0);

    if( !SetCommState(pjSerialPort_hIDComDev, &dcb) ||
       !SetupComm(pjSerialPort_hIDComDev,BUFFER_INPUT_RECOMMEND,BUFFER_OUTPUT_RECOMMEND) ||
       pjSerialPort_overlappedRead.hEvent == NULL ||
       pjSerialPort_overlappedWrite.hEvent == NULL){
        dwError = GetLastError();

        if( pjSerialPort_overlappedRead.hEvent != NULL )
            CloseHandle( pjSerialPort_overlappedRead.hEvent );

        if( pjSerialPort_overlappedWrite.hEvent != NULL )
            CloseHandle( pjSerialPort_overlappedWrite.hEvent );

        CloseHandle( pjSerialPort_hIDComDev );
        return 0;
    }

    pjSerialPort_isOpened = 1;
    return 1;
}
                                        /***************************************
                                        * pjSerialPort_ClosePort
                                        ***************************************/
int pjSerialPort_ClosePort(void){
    if( !pjSerialPort_isOpened || pjSerialPort_hIDComDev == NULL )
        return 1;

    if( pjSerialPort_overlappedRead.hEvent != NULL )
        CloseHandle( pjSerialPort_overlappedRead.hEvent );

    if( pjSerialPort_overlappedWrite.hEvent != NULL )
        CloseHandle( pjSerialPort_overlappedWrite.hEvent );

    CloseHandle( pjSerialPort_hIDComDev );

    pjSerialPort_hIDComDev = NULL;
    pjSerialPort_isOpened = 0;
    
    if( pjSerialPort_buffer != NULL ){
        free( pjSerialPort_buffer );
        pjSerialPort_buffer = NULL;   
    }

    return 1;
}
                                        /***************************************
                                        * pjSerialPort_IsOpened
                                        ***************************************/
int pjSerialPort_IsOpened(void){
    return pjSerialPort_isOpened;
}
                                        /***************************************
                                        * pjSerialPort_WriteChar
                                        ***************************************/
int pjSerialPort_WriteChar( char ch ){
    int bWriteStat;
    DWORD dwBytesWritten;

    bWriteStat = WriteFile( pjSerialPort_hIDComDev, (LPSTR)&ch, 1, 
                            &dwBytesWritten,
                            &pjSerialPort_overlappedWrite);

    if( !bWriteStat && (GetLastError() == ERROR_IO_PENDING) ){
        if( WaitForSingleObject( pjSerialPort_overlappedWrite.hEvent,
                                 TIMEOUT_WRITECOMM_EVENT) ){
            dwBytesWritten = 0;
        }else{
            GetOverlappedResult( pjSerialPort_hIDComDev,
                                 &pjSerialPort_overlappedWrite,
                                 &dwBytesWritten,
                                 0);
            pjSerialPort_overlappedWrite.Offset += dwBytesWritten;
        }
    }

    return 1;
}
                                        /***************************************
                                        * pjSerialPort_WriteData
                                        ***************************************/
int pjSerialPort_WriteData( const char* data ){
    DWORD dwBytesWritten=0;
    char* p = (char*)data;

    if( !pjSerialPort_isOpened || pjSerialPort_hIDComDev == NULL ) return 0;

    while( *p != '\0' ){
        pjSerialPort_WriteChar( *p );

        p++;
        dwBytesWritten++;
    }

    return dwBytesWritten;
}
                                        /***************************************
                                        * pjSerialPort_WriteLine
                                        ***************************************/
int pjSerialPort_WriteLine( const char* line ){
    DWORD dwBytesWritten=0;
    char* p = (char*)line;

    if( !pjSerialPort_isOpened || pjSerialPort_hIDComDev == NULL ) return 0;

    while( *p != '\0' ){
        pjSerialPort_WriteChar( *p );

        p++;
        dwBytesWritten++;
    }
    
    pjSerialPort_WriteChar( '\r' );
    pjSerialPort_WriteChar( '\n' );
    
    return dwBytesWritten;
}
                                        /***************************************
                                        * pjSerialPort_BytesToRead
                                        ***************************************/
int pjSerialPort_BytesToRead(void){
    DWORD dwErrorFlags;
    COMSTAT ComStat;

    if( !pjSerialPort_isOpened || pjSerialPort_hIDComDev == NULL ) return 0;

    ClearCommError( pjSerialPort_hIDComDev, &dwErrorFlags, &ComStat );

    return ComStat.cbInQue;
}
                                        /***************************************
                                        * pjSerialPort_ReadData
                                        ***************************************/
int pjSerialPort_ReadData( void* data, int length ){
    int bReadStatus;
    DWORD dwBytesRead,dwErrorFlags;
    COMSTAT ComStat;

    if( !pjSerialPort_isOpened || pjSerialPort_hIDComDev == NULL ) return 0;

    ClearCommError( pjSerialPort_hIDComDev, &dwErrorFlags, &ComStat );

    if( !ComStat.cbInQue ) return 0;

    dwBytesRead = (DWORD)ComStat.cbInQue;

    if( length < (int)dwBytesRead ) 
        dwBytesRead = (DWORD)length;

    bReadStatus = ReadFile( pjSerialPort_hIDComDev,
                            data,
                            dwBytesRead,
                            &dwBytesRead,
                            &pjSerialPort_overlappedRead);

    if( !bReadStatus ){
        if( GetLastError() == ERROR_IO_PENDING ){
            WaitForSingleObject( pjSerialPort_overlappedRead.hEvent,
                                 TIMEOUT_READCOMM_EVENT );
            return dwBytesRead;
        }

        return 0;
    }

    return dwBytesRead;
}
                                        /***************************************
                                        * pjSerialPort_ReadLineWithInterrupt
                                        ***************************************/
char* pjSerialPort_ReadLineWithInterrupt( int pressKeyExit ){
    if( !pjSerialPort_isOpened || pjSerialPort_hIDComDev == NULL ) 
        return 0;
        
    char* p = pjSerialPort_buffer;
    int num = 0;
    char ch = 0;
    while( ch != '\n' ){
        if( kbhit() && pressKeyExit )
            break;
            
        if( pjSerialPort_BytesToRead() > 0 ){
            pjSerialPort_ReadData( &ch, 1 );
            num++;
            if( num < MAX_BUFFER_LENGTH ){
                *p = ch;
                p++;
                if( ch == '\n' ){
                    *p = '\0';
                }
            }else{
                *p = '\0';
                break;   
            }
        }
        Sleep(1);
    }
    
    return pjSerialPort_buffer;
}
                                        /***************************************
                                        * pjSerialPort_ReadLine
                                        ***************************************/
char* pjSerialPort_ReadLine( void ){
    if( !pjSerialPort_isOpened || pjSerialPort_hIDComDev == NULL ) 
        return 0;
        
    char* p = pjSerialPort_buffer;
    int num = 0;
    char ch = 0;
    while( ch != '\n' ){
        if( pjSerialPort_BytesToRead() > 0 ){
            pjSerialPort_ReadData( &ch, 1 );
            num++;
            if( num < MAX_BUFFER_LENGTH ){
                *p = ch;
                p++;
                if( ch == '\n' ){
                    *p = '\0';
                }
            }else{
                *p = '\0';
                break;   
            }
        }
        Sleep(1);
    }
    
    return pjSerialPort_buffer;
}
                                        /***************************************
                                        * pjSerialPort_ReadLineWithCallbacks
                                        ***************************************/
char* pjSerialPort_ReadLineWithCallbacks( char* keys, pjSerialPort_Callback* callbacks ){
    if( !pjSerialPort_isOpened || pjSerialPort_hIDComDev == NULL ) 
        return 0;
        
    char* p = pjSerialPort_buffer;
    int num = 0;
    char ch = 0;
    char pressKey = 0;
    char* keyList = keys;
    pjSerialPort_Callback* callbackList = callbacks;
    while( ch != '\n' ){
        if( kbhit() ){
            pressKey = getch();
            keyList = keys;
            callbackList = callbacks;
            while( *keyList != '\0' ){
                if( pressKey == *keyList ){
                    (*callbackList)();
                }   
                keyList++;
                callbackList++;
            }
        }
        
        if( pjSerialPort_BytesToRead() > 0 ){
            pjSerialPort_ReadData( &ch, 1 );
            num++;
            if( num < MAX_BUFFER_LENGTH ){
                *p = ch;
                p++;
                if( ch == '\n' ){
                    *p = '\0';
                }
            }else{
                *p = '\0';
                break;   
            }
        }
        Sleep(1);
    }
    
    return pjSerialPort_buffer;
}
                                        /***************************************
                                        * pjSerialPort_ReadLineWithCallback
                                        ***************************************/
char* pjSerialPort_ReadLineWithCallback( char key, pjSerialPort_Callback callback ){
    if( !pjSerialPort_isOpened || pjSerialPort_hIDComDev == NULL ) 
        return 0;
        
    char* p = pjSerialPort_buffer;
    int num = 0;
    char ch = 0;
    char pressKey = 0;
    while( ch != '\n' ){
        if( kbhit() ){
            pressKey = getch();
            if( pressKey == key ){
                callback();   
            }
        }
        
        if( pjSerialPort_BytesToRead() > 0 ){
            pjSerialPort_ReadData( &ch, 1 );
            num++;
            if( num < MAX_BUFFER_LENGTH ){
                *p = ch;
                p++;
                if( ch == '\n' ){
                    *p = '\0';
                }
            }else{
                *p = '\0';
                break;   
            }
        }
        Sleep(1);
    }
    
    return pjSerialPort_buffer;
}
