/*******************************************************************************
* File Name: pjString.c
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-20 initial release version
*******************************************************************************/

#include "pjString.h"

/*******************************************************************************
* Version 
* version = major.minor.patch
            8-bits 8-bits 8-bits
*******************************************************************************/
										/***************************************
										* pjPath_GetVersionPatch
										***************************************/
int pjString_GetVersionPatch( void ){
	return PJSTRING_VERSION_PATCH;	
}
										/***************************************
										* pjPath_GetVersionMinor
										***************************************/
int pjString_GetVersionMinor( void ){
	return PJSTRING_VERSION_MINOR;	
}
										/***************************************
										* pjPath_GetVersionMajor
										***************************************/
int pjString_GetVersionMajor( void ){
	return PJSTRING_VERSION_MAJOR;	
}
										/***************************************
										* pjPath_GetVersion
										***************************************/
long int pjString_GetVersion( void ){
	return (PJSTRING_VERSION_MAJOR<<16) | (PJSTRING_VERSION_MINOR<<8) | PJSTRING_VERSION_PATCH;	
}
/*******************************************************************************
* Public Methods
*******************************************************************************/
										/***************************************
										* pjString_Find
										***************************************/
int pjString_Find( char* string, char findChar ){
	char* p = string;
	int pos = 0;
	while( *p != '\0' ){
		if( *p == findChar ) break;	
		p++;
		pos++;
	}
	
	return (*p == '\0') ? -1 : pos;
}
                                        /***************************************
                                        * pjString_FindAll
                                        ***************************************/
int pjString_FindAll( char* string, char findChar, int* pos ){
    char* p = string;
    int* q = pos;
    int isFind = 0;
    int charPos = 0;
    
    while( *p != '\0' ){
        if( *p == findChar ){
            isFind++;;
            *q = charPos;
            q++;
        }   
        p++;
        charPos++;
    }
    
    return isFind;
}
										/***************************************
										* pjString_Length
										***************************************/
int pjString_Length( char* string ){
	char* p = string;
	int length = 0;
	while( *p != '\0' ) {
		length++;
		p++;
	}
	return length;
}
                                        /***************************************
                                        * pjString_Replace
                                        ***************************************/
int pjString_Replace( char* string, char oldChar, char newChar ){
    char* p = string;
    int isFindChar = 0;
    while( *p != '\0' ){
        if( *p == oldChar ){
            *p = newChar;
            isFindChar = 1;
        }
        p++;   
    }
    
    return isFindChar;
}
                                        /***************************************
                                        * pjString_Copy
                                        ***************************************/
int pjString_Copy( char* string, char* fromString ){
    char* p = string;
    char* q = fromString;
    
    while( *q != '\0' ){
        *p = *q;
        q++;
        p++;   
    }
    *p = '\0';
    
    return 1;
}
                                        /***************************************
                                        * pjString_CopyLimited
                                        ***************************************/
int pjString_CopyLimited( char* string, char* fromString, int length ){
    char* p = string;
    char* q = fromString;
    int copyed = 0;
    
    while( copyed < length ){
        *p = *q;
        q++;
        p++;
        copyed++;   
    }
    *p = '\0';
    
    return 1;
}
                                        /***************************************
                                        * pjString_Append
                                        ***************************************/
int pjString_Append( char* string, char* append ){
    char* p = string + pjString_Length( string );
    char* q = append;
    
    while( *q != '\0' ){
        *p = *q;
        q++;
        p++;   
    }
    *p = '\0';
    
    return 1;
}
                                        /***************************************
                                        * pjString_Substring
                                        ***************************************/
int pjString_Substring( char* string, int start, int length, char* substring ){
    char* p = string;
    char* q = substring;
    int pos = 0;
    int len = 0;
    
    while( pos != start ){
        p++;
        pos++;   
    }
    
    while( len != length ){
        *q = *p;
        p++;
        q++;
        len++;   
    }
    *q = '\0';
    
    return 1;
}
