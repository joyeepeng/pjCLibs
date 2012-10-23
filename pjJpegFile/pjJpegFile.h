/*******************************************************************************
* File Name: pjJpegFile.h
* Author: Joyee Peng
* Email: joyee.peng@gmail.com
* Github: https://github.com/joyeepeng
* Blog: http://blog.csdn.net/pengqianhe
* History:
	2012-10-23 initial release version
*******************************************************************************/

#ifndef __PJJPEGFILE_H__
#define __PJJPEGFILE_H__

#define PJJPEGFILE_VERSION_PATCH	1
#define PJJPEGFILE_VERSION_MINOR	0
#define PJJPEGFILE_VERSION_MAJOR	0

/*******************************************************************************
* Version Control
*******************************************************************************/
long int pjJpegFile_GetVersion( void );
int pjJpegFile_GetVersionPatch( void );
int pjJpegFile_GetVersionMinor( void );
int pjJpegFile_GetVersionMajor( void );

/*******************************************************************************
* Public Methods
*******************************************************************************/

#endif
