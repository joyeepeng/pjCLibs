#include <stdio.h>
#include <stdlib.h>

#include "pjTextWriter.h"

int main(int argc, char *argv[])
{
    long int version = pjTextWriter_GetVersion();
    printf("pjTextWriter Version: %d.%d.%d\n", version>>16&0xff, version>>8&0xff, version&0xff);
    printf("pjTextWriter Version: %d.%d.%d\n", pjTextWriter_GetVersionMajor(), pjTextWriter_GetVersionMinor(), pjTextWriter_GetVersionPatch());
    
    pjTextWriter* textWriter = pjTextWriter_New();
    char buffer[8] = "dded";
    
    pjTextWriter_OpenFile( textWriter, "a.txt" );
    pjTextWriter_WriteLine( textWriter, "abcd" );
    pjTextWriter_WriteChars( textWriter, buffer );
    pjTextWriter_WriteLine( textWriter, "123");
    pjTextWriter_CloseFile( textWriter );
    
    pjTextWriter_Delete( textWriter );
    
    system("pause");
    return 1;
}
