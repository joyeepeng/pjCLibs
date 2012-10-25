/*******************************************************************************
* File Name: pjString.h
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-20 initial release version
*******************************************************************************/
#ifndef __PJSTRING_H__
#define __PJSTRING_H__

#define PJSTRING_VERSION_PATCH		1
#define PJSTRING_VERSION_MINOR		0
#define PJSTRING_VERSION_MAJOR		0

typedef struct tagPjString{
    char* string;
}pjString;

/*******************************************************************************
* Version Control
*******************************************************************************/
long int pjString_GetVersion( void );
int pjString_GetVersionPatch( void );
int pjString_GetVersionMinor( void );
int pjString_GetVersionMajor( void );
/*******************************************************************************
* Public Methods
*******************************************************************************/
                                        /***************************************
                                        * General Functions
                                        ***************************************/
int pjString_Find2( char* string, char findChar );
int pjString_FindAll2( char* string, char findChar, int* pos );
int pjString_Replace2( char* string, char oldChar, char newChar );
int pjString_Length2( char* string );
int pjString_Copy2( char* string, char* fromString );
int pjString_CopyLimited2( char* string, char* fromString, int length );
int pjString_Append2( char* string, char* append );
int pjString_Substring2( char* string, int start, int length, char* substring );
int pjString_Equals2( char* str1, char* str2 );
int pjString_ToUpper2( char* string );
int pjString_ToLower2( char* string );
int pjString_Split2( char* string, char splitChar, char** parts );
                                        /***************************************
                                        * Methods
                                        ***************************************/
pjString* pjString_New( int length );
void pjString_Delete( pjString* string );
int pjString_Copy( pjString* string, char* fromString );
int pjString_Find( pjString* string, char findChar );
int pjString_FindAll( pjString* string, char findChar, int* pos );
int pjString_Replace( pjString* string, char oldChar, char newChar );
int pjString_CopyLimited( pjString* string, char* fromString, int length );
int pjString_Append( pjString* string, char* append );
int pjString_Substring( pjString* string, int start, int length, char* substring );
int pjString_Equals( pjString* string1, pjString* string2 );
int pjString_ToUpper( pjString* string );
int pjString_ToLower( pjString* string );
int pjString_Split( pjString* string, char splitChar, pjString** parts );
char* pjString_ToString( pjString* string );
int pjString_ToInteger( pjString* string );

#endif
