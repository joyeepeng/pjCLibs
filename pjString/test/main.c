#include <stdio.h>
#include <stdlib.h>

#include "pjString.h"

int main(int argc, char *argv[])
{
    long int version = pjString_GetVersion();
	printf("pjString Version: %ld.%d.%d\n", version>>16&0xff, version>>8&0xff, version&0xff);
	printf("pjString Version: %d.%d.%d\n", pjString_GetVersionMajor(), pjString_GetVersionMinor(), pjString_GetVersionPatch() );
	
	/*
	char* testString = "abcd1389c";
	printf("Length: %d\n", pjString_Length2(testString) );
	printf("Find: %d\n", pjString_Find2(testString,'1'));
	
	char* testStr = (char*)malloc(sizeof(char)*strlen(testString));
	memset(testStr,'\0',sizeof(char)*strlen(testString));
	pjString_Copy2( testStr, testString );
	printf("Copy: %s\n", testStr);
	pjString_Replace2( testStr, 'c', 'e' );
	printf("Replace: %s\n", testStr );
	pjString_CopyLimited2( testStr, testString, pjString_Length2(testString)-3);
	printf("CopyLimited: %s\n", testStr);
	pjString_Append2( testStr, "peng" );
	printf("Append: %s\n", testStr );
	char* subStr = (char*)malloc(sizeof(char)*5);
	pjString_Substring2(testStr,2,5,subStr);
	printf("Substring: %s\n", subStr);
	int* find = (int*)malloc(sizeof(int)*5);
	int num = pjString_FindAll2( testString, 'c', find );
	int i = 0;
	for(i=0;i<num;i++)
		printf(" %d ", find[i]);
	free(find);
	free(subStr);
	free(testStr);
	
	char* splitString = (char*)malloc(sizeof(char) * 128);
	char* part1 = (char*)malloc(sizeof(char)* 3 );
	char* part2 = (char*)malloc(sizeof(char)* 3 );
	char* part3 = (char*)malloc(sizeof(char)* 3 );
	char* part4 = (char*)malloc(sizeof(char)* 3 );
	char** part = (char**)malloc(sizeof(char*)* 4);
	part[0] = part1;
	part[1] = part2;
	part[2] = part3;
	part[3] = part4;
	
	pjString_Copy2( splitString, "123,abc,def,345" );
	printf("\n%s\n", splitString );
	pjString_Split2( splitString, ',', part );
	
	printf("%s/%s/%s/%s\n", part1, part2, part3, part4 );
	
	free( splitString );
	free( part1 );
	free( part2 );
	free( part3 );
	free( part4 );
	free( part );
	*/
	
	pjString* str1 = pjString_New( 12 );
	pjString_Copy( str1, "abcdef" );
	printf("%s\n",pjString_ToString(str1));
	pjString_ToUpper( str1 );
	printf("%s\n",pjString_ToString(str1));
	pjString_ToLower( str1 );
	printf("%s\n", pjString_ToString(str1));
	printf("%d\n", pjString_Find( str1, 'c' ));
	pjString_Copy( str1, "12,34,56,78" );
	pjString* parts[4];
	int i = 0;
	for(i=0;i<4;i++) parts[i]=pjString_New(2);
	pjString_Split( str1, ',', parts );
	for(i=0;i<4;i++) printf("%s/",pjString_ToString(parts[i]));
	for(i=0;i<4;i++) pjString_Delete(parts[i]);
	pjString_Delete( str1 );
	
	system("pause");
	
    return 1;
}
