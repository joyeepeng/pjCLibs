#include <stdio.h>
#include <stdlib.h>

#include "pjSerialPort.h"
#include "pjTextReader.h"
#include "pjString.h"

#define SERIALPORT_CALLBACKS   3

int g_port = 1;
int g_baud_rate = 115200;
int g_data_bits = 8;
int g_stop_bits = 0;  /* 1 Bit */
int g_parity = 0;     /* None */
pjSerialPort_Callback* g_callbacks;

/* send a string with a carriage return and new line char in the end */
void SendDataWithLineEnd( void ){
    char send[25];
    printf("Send String: ");  
    scanf("%s", send);
    pjSerialPort_WriteLine( send );
}

/* send a string without a '\r' and '\n' char in the end */
void SendDataWithoutLineEnd( void ){
    char send[25];
    printf("Send String: ");  
    scanf("%s", send);
    pjSerialPort_WriteData( send ); 
}

/* exit the program */
void Exit( void ){
    if( pjSerialPort_IsOpened() )
        pjSerialPort_ClosePort();
        
    if( g_callbacks != NULL ){
        free( g_callbacks );
        g_callbacks = NULL;
    }
    
    exit(0);   
}

void read_settings(){
    pjTextReader* textReader = pjTextReader_New();
    pjString* line = pjString_New( 128 );
    pjString* parts[5];
    int i = 0;
    
    for(i=0;i<5;i++) parts[i] = pjString_New( 7 );
    if( pjTextReader_IsExist( "Settings.txt" ) ){
        pjTextReader_OpenFile( textReader, "Settings.txt" );
        pjTextReader_ReadLine( textReader, pjString_ToString(line) );
        pjTextReader_CloseFile( textReader );
            
        pjString_Split( line, ',', parts );
        
        g_port = pjString_ToInteger( parts[0] );
        g_baud_rate = pjString_ToInteger( parts[1] );
        g_data_bits = pjString_ToInteger( parts[2] );
        g_stop_bits = pjString_ToInteger( parts[3] );
        g_parity = pjString_ToInteger( parts[4] );
    }

    for(i=0;i<5;i++) pjString_Delete(parts[i]);
    pjString_Delete(line);
    pjTextReader_Delete( textReader );
}

int main(int argc, char *argv[])
{
    /* if exist the setting.ini, then read it */
    read_settings();
    
    pjSerialPort_Initialize();
    pjSerialPort_OpenPort( g_port, g_baud_rate, g_parity, g_data_bits, g_stop_bits );
    
    g_callbacks = (pjSerialPort_Callback*)malloc( sizeof(pjSerialPort_Callback)  * SERIALPORT_CALLBACKS );
    g_callbacks[0] = SendDataWithLineEnd;
    g_callbacks[1] = SendDataWithoutLineEnd;
    g_callbacks[2] = Exit;
    while( 1 ){
        if( pjSerialPort_IsOpened() ){
            printf("open port passed.\n");
            while( !kbhit() ){
                printf( "%s", pjSerialPort_ReadLineWithCallbacks( "sge", g_callbacks ) );   
            }
        }else{
            printf("open port failed.\n");
            break;
        }
    }
    
    system( "pause" );
    return 1;
}
