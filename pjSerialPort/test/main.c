#include <stdio.h>
#include <stdlib.h>

#include "pjSerialPort.h"

void SendDataWithLineEnd( void ){
    char send[25];
    printf("Send String: ");  
    scanf("%s", send);
    pjSerialPort_WriteLine( send );
}

void SendData( void ){
    char send[25];
    printf("Send String: ");  
    scanf("%s", send);
    pjSerialPort_WriteData( send ); 
}

void Exit( void ){
    pjSerialPort_ClosePort();
    exit(0);   
}

int main(int argc, char *argv[])
{
    long int version = pjSerialPort_GetVersion();
    printf("pjSerialPort Ver: %d.%d.%d\n", version>>16&0xff, version>>8&0xff, version&0xff);
    printf("pjSerialPort Ver: %d.%d.%d\n", pjSerialPort_GetVersionMajor(), pjSerialPort_GetVersionMinor(), pjSerialPort_GetVersionPatch());
    
    pjSerialPort_Initialize();
    pjSerialPort_OpenPort( 4, 115200, 0, 8, 0 );
    pjSerialPort_Callback* callbacks = (pjSerialPort_Callback*)malloc(sizeof(pjSerialPort_Callback)*3);
    callbacks[0] = SendDataWithLineEnd;
    callbacks[1] = SendData;
    callbacks[2] = Exit;
    if( pjSerialPort_IsOpened() ){
        printf("open port passed.\n");
        while( !kbhit() ){
            printf("%s", pjSerialPort_ReadLineWithCallbacks( "sge", callbacks ) );   
        }
        pjSerialPort_ClosePort();
    }else{
        printf("open port failed.\n");
    }
    free( callbacks );
    
    return 1;
}
