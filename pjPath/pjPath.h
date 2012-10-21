/*******************************************************************************
* File Name: pjPath.h
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: 
* Blog: http://blog.csdn.net/pengqianhe
*******************************************************************************/

#ifndef __PJPATH_H__
#define __PJPATH_H__

#define PJPATH_VERSION_PATCH	1
#define PJPATH_VERSION_MINOR	0
#define PJPATH_VERSION_MAJOR	0

/*******************************************************************************
* Version Control
*******************************************************************************/
long int pjPath_GetVersion( void );
int pjPath_GetVersionPatch( void );
int pjPath_GetVersionMinor( void );
int pjPath_GetVersionMajor( void );

/*******************************************************************************
* Public Methods
*******************************************************************************/
int pjPath_GetFileExtension( char* path, char* fileExt );
int pjPath_GetDirectoryName( char* path, char* directoryName );
int pjPath_GetFileName( char* path, char* fileName );
int pjPath_GetDriveName( char* path, char* drive );

#endif
