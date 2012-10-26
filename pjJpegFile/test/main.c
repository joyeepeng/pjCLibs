#include <stdio.h>
#include <stdlib.h>

#include "pjJpegFile.h"

int main(int argc, char *argv[])
{
    long int version = pjJpegFile_GetVersion();
    printf("pjJpegFile Version: %d.%d.%d\n", version>>16&0xff, version>>8&0xff, version&0xff);
    printf("pjJpegFile Version: %d.%d.%d\n", pjJpegFile_GetVersionMajor(), pjJpegFile_GetVersionMinor(), pjJpegFile_GetVersionPatch());
    
    pjJpegFile* jpegFile = pjJpegFile_New();

    pjJpegFile_ReadFile( "flower.jpg", jpegFile );
    int c = 0, r = 0;
    printf("GetPixel Pos: ");
    scanf("%d,%d",&r,&c);
    pjJpegColor clr = pjJpegFile_GetPixel( jpegFile, r, c );
    printf("%d,%d,%d\n", clr.R, clr.G, clr.B );
    clr.R = 255;
    clr.G = 0;
    clr.B = 255;
    pjJpegFile_SetRegionColor( jpegFile, c+5, r+5, 100,100, clr);
    clr.R = 0;
    clr.G = 0;
    clr.B = 0;
    pjJpegFile_SetPixel( jpegFile, 20, 20, clr );
    pjJpegFile_WriteFile( jpegFile, "flower2.jpg", 75 );
    
    pjJpegFile_Delete( jpegFile );
    free(jpegFile);
    
    system("pause");
        
    return 1;
}
