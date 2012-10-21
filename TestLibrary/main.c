#include <stdio.h>
#include <stdlib.h>

//#define __DEBUG_PJPATH__
#define __DEBUG_PJSTRING__

#ifdef __DEBUG_PJPATH__
#include "pjPath.h"
#endif

#ifdef __DEBUG_PJSTRING__
#include "pjString.h"
#endif

int main(int argc, char *argv[])
{
#ifdef __DEBUG_PJPATH__
	long int version = pjPath_GetVersion();
	printf("pjPath Version: %ld.%d.%d\n", version>>16&0xff, version>>8&0xff, version&0xff);
	printf("pjPath Version: %d.%d.%d\n", pjPath_GetVersionMajor(), pjPath_GetVersionMinor(), pjPath_GetVersionPatch() );
	
	char fileExt[6];
	pjPath_GetFileExtension("C:\\a.txt",fileExt);
	printf("GetFileExtension: %s\n", fileExt);
	
	char dirName[128];
	pjPath_GetDirectoryName("C:\\pengjun\\abc\\d.pdf",dirName);
	printf("GetDirectoryName: %s\n", dirName);
	
	char fileName[12];
	pjPath_GetFileName("C:\\pengjun\\a\\b\\c\\defs.sdf",fileName);
	printf("FileName: %s\n", fileName);
	
	pjPath_GetDriveName("C:\\pengjun\\abc\\dedfs.dff",fileName);
	printf("DriveName: %s\n", fileName);
#endif

#ifdef __DEBUG_PJSTRING__
	char* testString = "abcd1389";
	printf("Length: %d\n", pjString_Length(testString) );
	printf("Find: %d\n", pjString_Find(testString,'a'));
#endif
	
	system("pause");
	return 0;
}