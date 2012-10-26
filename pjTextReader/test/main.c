#include <stdio.h>
#include <stdlib.h>

#include "pjTextReader.h"

int main(int argc, char *argv[])
{
    long int version = pjTextReader_GetVersion();
    printf("pjTextReader Version: %ld.%d.%d\n", version>>16&0xff, version>>8&0xff, version&0xff);
    printf("pjTextReader Version: %d.%d.%d\n", pjTextReader_GetVersionMajor(),pjTextReader_GetVersionMinor(),pjTextReader_GetVersionPatch());
    
    pjTextReader* textReader = pjTextReader_New();
    char line[19];
    pjTextReader_OpenFile( textReader, "Settings.txt" );
    printf("GetLineNumber: %d\n", pjTextReader_GetLineNumber( textReader ) );
    printf("MaxLineLength: %d\n", pjTextReader_GetMaxLineLength( textReader ) );

    pjTextReader_ReadLine( textReader, line );
    printf("ReadLine: %s\n", line );
    pjTextReader_ReadLine( textReader, line );
    printf("ReadLine: %s\n", line );
    pjTextReader_ReadLine( textReader, line );
    printf("ReadLine: %s\n", line );
    pjTextReader_ReadChars( textReader, 6, line);
    printf("ReadChars: %s\n", line);
    pjTextReader_CloseFile( textReader );
    pjTextReader_Delete( textReader );
    
    system("pause");
    return 1;
}
