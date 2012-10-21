/*******************************************************************************
* File Name: pjPath.c
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-20 initial release version
*******************************************************************************/

#include "pjPath.h"

/*******************************************************************************
* Version 
* version = major.minor.patch
            8-bits 8-bits 8-bits
*******************************************************************************/
										/***************************************
										* pjPath_GetVersionPatch
										***************************************/
int pjPath_GetVersionPatch( void ){
	return PJPATH_VERSION_PATCH;	
}
										/***************************************
										* pjPath_GetVersionMinor
										***************************************/
int pjPath_GetVersionMinor( void ){
	return PJPATH_VERSION_MINOR;	
}
										/***************************************
										* pjPath_GetVersionMajor
										***************************************/
int pjPath_GetVersionMajor( void ){
	return PJPATH_VERSION_MAJOR;	
}
										/***************************************
										* pjPath_GetVersion
										***************************************/
long int pjPath_GetVersion( void ){
	return (PJPATH_VERSION_MAJOR<<16) | (PJPATH_VERSION_MINOR<<8) | PJPATH_VERSION_PATCH;	
}

/*******************************************************************************
* Public Methods
*******************************************************************************/
										/***************************************
										* pjPath_GetDriveName
										***************************************/
int pjPath_GetDriveName( char* path, char* drive ){
	char* ps = path;
	char* pe = path + strlen(path);
	char* d = drive;
	
	while( *ps != ':' && ps < pe ){
		*drive = *ps;
		ps++;
		drive++;	
	}
	
	if( ps == pe )
		return 0;
		
	*drive = '\0';
	
	return 1;
}
										/***************************************
										* pjPath_GetFileName
										***************************************/
int pjPath_GetFileName( char* path, char* fileName ){
	char* p = path;
	char* fn = fileName;
	
	p += strlen( path );
	while( *p != '\\' && (p > path) ){
		p--;
	}
	
	if( p == path )
		return 0;
	
	p++;
	while( *p != '\0' ){
		*fn = *p;
		p++;
		fn++;
	}
	*fn = '\0';
	
	return 1;
}
										/***************************************
										* pjPath_GetDirectoryName
										***************************************/
int pjPath_GetDirectoryName( char* path, char* directoryName ){
	char* ps = (char*)path;
	char* pe = ps + strlen( path );
	char* dn = directoryName;
	
	while( *pe != '\\' && (pe > ps) ){
		pe--;	
	}
	
	if( pe == ps )
		return 0;
		
	while( ps < pe ){
		*dn = *ps;
		ps++;
		dn++;	
	}
	*dn = '\0';
	
	return 1;
}
										/***************************************
										* pjPath_GetFileExtension
										***************************************/
int pjPath_GetFileExtension( char* path, char* fileExt ){
	char* p = (char*)path;
	char* fe = fileExt;
	
	p += strlen( path );
	while( *p != '.' && (p > path) ){
		p--;
	}
	
	if( p == path )
		return 0;
		
	while( *p != '\0' ){
		*fe = *p;
		fe++;
		p++;	
	}
	*fe = '\0';
	
	return 1;
}
