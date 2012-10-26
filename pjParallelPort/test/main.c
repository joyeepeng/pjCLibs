#include <stdio.h>
#include <stdlib.h>

#include "pjParallelPort.h"

int main(int argc, char *argv[])
{
    long int version = pjParallelPort_GetVersion();
    printf("pjParallelPort Version: %d.%d.%d\n", version>>16&0xff, version>>8&0xff, version&0xff);
    
    pjParallelPort_Output( 0x378, 0xFF );
    
    system("pause");
    
    pjParallelPort_SetPinValue( 0x378, PARALLELPORT_D4, PARALLELPORT_HIGH );
    system("pause");
    
    return 1;
}
