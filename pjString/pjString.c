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
										* pjString_GetVersionPatch
										***************************************/
int pjString_GetVersionPatch( void ){
	return PJSTRING_VERSION_PATCH;	
}
										/***************************************
										* pjString_GetVersionMinor
										***************************************/
int pjString_GetVersionMinor( void ){
	return PJSTRING_VERSION_MINOR;	
}
										/***************************************
										* pjString_GetVersionMajor
										***************************************/
int pjString_GetVersionMajor( void ){
	return PJSTRING_VERSION_MAJOR;	
}
										/***************************************
										* pjString_GetVersion
										***************************************/
long int pjString_GetVersion( void ){
	return (PJSTRING_VERSION_MAJOR<<16) | (PJSTRING_VERSION_MINOR<<8) | PJSTRING_VERSION_PATCH;	
}
/*******************************************************************************
* Public Methods
*******************************************************************************/
										/***************************************
										* pjString_Find2
										***************************************/
int pjString_Find2( char* string, char findChar ){
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
                                        * pjString_FindAll2
                                        ***************************************/
int pjString_FindAll2( char* string, char findChar, int* pos ){
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
										* pjString_Length2
										***************************************/
int pjString_Length2( char* string ){
	char* p = string;
	int length = 0;
	while( *p != '\0' ) {
		length++;
		p++;
	}
	return length;
}
                                        /***************************************
                                        * pjString_Replace2
                                        ***************************************/
int pjString_Replace2( char* string, char oldChar, char newChar ){
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
                                        * pjString_Copy2
                                        ***************************************/
int pjString_Copy2( char* string, char* fromString ){
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
                                        * pjString_CopyLimited2
                                        ***************************************/
int pjString_CopyLimited2( char* string, char* fromString, int length ){
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
                                        * pjString_Append2
                                        ***************************************/
int pjString_Append2( char* string, char* append ){
    char* p = string + pjString_Length2( string );
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
                                        * pjString_Substring2
                                        ***************************************/
int pjString_Substring2( char* string, int start, int length, char* substring ){
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
                                        /***************************************
                                        * pjString_Equals2
                                        ***************************************/
int pjString_Equals2( char* str1, char* str2 ){
    char* p = str1;
    char* q = str2;
    char* tmp = 0;
    
    int str1Len = pjString_Length2( str1 );
    int str2Len = pjString_Length2( str2 );
    
    if( str1Len > str2Len ){
        tmp = q;
    }else{
        tmp = p;   
    }
    
    while( *tmp != '\0' ){
        if( *p != *q ){
            return 0;
        }
        p++;
        q++;
        tmp++;
    }
    
    return 1;
}
                                        /***************************************
                                        * pjString_ToUpper2
                                        ***************************************/
int pjString_ToUpper2( char* string ){
    char* p = string;
    
    while( *p != '\0' ){
        if( *p >= 'a' && *p <= 'z' ){
            *p -= 32;   
        }   
        p++;
    }
    
    return 1;
}
                                        /***************************************
                                        * pjString_ToLower2
                                        ***************************************/
int pjString_ToLower2( char* string ){
    char* p = string;
    
    while( *p != '\0' ){
        if( *p >= 'A' && *p <= 'Z' ){
            *p += 32;   
        }
        p++;
    }
    
    return 1;
}
                                        /***************************************
                                        * pjString_Split2
                                        ***************************************/
int pjString_Split2( char* string, char splitChar, char** parts ){
    char* str = string;
    char** part = parts;
    char* p = *(part);
    
    while( *str != '\0' ){
        if( *str != splitChar ){
            *p = *str;
            str++;   
            p++;
        }else{
            *p = '\0';
            p =  *(++part);
            str++;
        }
    }
    
    *p = '\0';
    
    return 1;
}
                                        /***************************************
                                        * pjString_New
                                        ***************************************/
pjString* pjString_New( int length ){
    pjString* string = (pjString*)malloc( sizeof(pjString) );
    string->string = (char*)malloc( sizeof(char) * (length + 1) );
    return string;
}
                                        /***************************************
                                        * pjString_Delete
                                        ***************************************/
void pjString_Delete( pjString* string ){
    if( string != 0 ){
        if( string->string != 0 ){
            free( string->string );
            string->string = 0;    
        }
        
        free( string );
        string = 0;   
    }   
}
                                        /***************************************
                                        * pjString_Copy
                                        ***************************************/
int pjString_Copy( pjString* string, char* fromString ){
    if( string == 0 ) return;
    
    return pjString_Copy2( string->string, fromString );
}
                                        /***************************************
                                        * pjString_ToString
                                        ***************************************/
char* pjString_ToString( pjString* string ){
    return string->string;   
}

                                        /***************************************
                                        * pjString_Find
                                        ***************************************/
int pjString_Find( pjString* string, char findChar ){
    if( string == 0 ) return -1;
    
    return pjString_Find2( string->string, findChar );   
}
                                        /***************************************
                                        * pjString_FindAll
                                        ***************************************/
int pjString_FindAll( pjString* string, char findChar, int* pos ){
    if( string == 0 ) return -1;
    
    return pjString_FindAll2( string->string, findChar, pos );
}
                                        /***************************************
                                        * pjString_Replace
                                        ***************************************/
int pjString_Replace( pjString* string, char oldChar, char newChar ){
    if( string == 0 ) return -1;
    
    return pjString_Replace2( string->string, oldChar, newChar );
}
                                        /***************************************
                                        * pjString_CopyLimited
                                        ***************************************/   
int pjString_CopyLimited( pjString* string, char* fromString, int length ){
    if( string == 0 ) return -1;
    
    return pjString_CopyLimited2( string->string, fromString, length );
}
                                        /***************************************
                                        * pjString_Append
                                        ***************************************/
int pjString_Append( pjString* string, char* append ){
    if( string == 0 ) return -1;
    
    return pjString_Append2( string->string, append );
}
                                        /***************************************
                                        * pjString_Substring
                                        ***************************************/
int pjString_Substring( pjString* string, int start, int length, char* substring ){
    if( string == 0 ) return -1;
    
    return pjString_Substring2( string->string, start, length, substring );
}
                                        /***************************************
                                        * pjString_Equals
                                        ***************************************/
int pjString_Equals( pjString* string1, pjString* string2 ){
    if( string1 == 0 || string2 == 0 ) return -1;
    
    return pjString_Equals2( string1->string, string2->string );
}
                                        /***************************************
                                        * pjString_ToUpper
                                        ***************************************/
int pjString_ToUpper( pjString* string ){
    if( string == 0 ) return -1;
    
    return pjString_ToUpper2( string->string );
}
                                        /***************************************
                                        * pjString_ToLower
                                        ***************************************/
int pjString_ToLower( pjString* string ){
    if( string == 0 ) return -1;
    
    return pjString_ToLower2( string->string );
}
                                        /***************************************
                                        * pjString_Split
                                        ***************************************/
int pjString_Split( pjString* string, char splitChar, pjString** parts ){
    char* str = string->string;
    pjString** part = parts;
    char* p = (*(part))->string;
    
    while( *str != '\0' ){
        if( *str != splitChar ){
            *p = *str;
            str++;   
            p++;
        }else{
            *p = '\0';
            p =  (*(++part))->string;
            str++;
        }
    }
    
    *p = '\0';
    
    return 1;
}
                                        /***************************************
                                        * pjString_ToInteger
                                        ***************************************/
int pjString_ToInteger( pjString* string ){
    return atoi( string->string );
}
