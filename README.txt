pjCLibs Library
---------------------------------------------------------------------------

1 pjPath Class
========================================================================
- pjPath_GetVersion( void )
- pjPath_GetVersionPatch( void )
- pjPath_GetVersionMinor( void )
- pjPath_GetVersionMajor( void )
- pjPath_GetFileExtension( char* path, char* fileExt )
- pjPath_GetDirectoryname( char* path, char* directoryName )
- pjPath_GetFileName( char* path, char* fileName )
- pjPath_GetFileNameWithoutExtension( char* path, char* fileName )
- pjPath_GetDriveName( char* path, char* drive )

2 pjString Class
========================================================================
- pjString_GetVersion( void )
- pjString_GetVersionPatch( void )
- pjString_GetVersionMinor( void )
- pjString_GetVersionMajor( void )
- pjString_Find( char* string, char findChar )
- pjString_FindAll( char* string, char findChar, int* pos )
- pjString_Replace( char* string, char oldChar, char newChar )
- pjString_Length( char* string )
- pjString_Copy( char* string, char* fromString )
- pjString_CopyLimited( char* string, char* fromString, int length )
- pjString_Append( char* string, char* append )
- pjString_Substring( char* string, int start, int length, char* substring )

3 pjTextReader Class
========================================================================
- pjTextReader_GetVersion( void )
- pjTextReader_GetVersionPatch( void )
- pjTextReader_GetVersionMinor( void )
- pjTextReader_GetVersionMajor( void )
- pjTextReader_OpenFile( pjTextReader* textReader, char* path )
- pjTextReader_GetLineNumber( pjTextReader* textReader )
- pjTextReader_GetMaxLineLength( pjTextReader* textReader )
- pjTextReader_ReadChars( pjTextReader* textReader, int length, char* line )
- pjTextReader_ReadLine( pjTextReader* textReader, char* line )
- pjTextReader_CloseFile( pjTextReader* textReader )

4 pjTextWriter Class
========================================================================
- pjTextWriter_GetVersion( void )
- pjTextWriter_GetVersionPatch( void )
- pjTextWriter_GetVersionMinor( void )
- pjTextWriter_GetVersionMajor( void )
- pjTextWriter_OpenFile( pjTextWriter* textWriter, char* path )
- pjTextWriter_WriteChars( pjTextWriter* textWriter, char* writeChars )
- pjTextWriter_WriteLine( pjTextWriter* textWriter, char* writeLine )
- pjTextWriter_CloseFile( pjTextWriter* textWriter )

5 pjJpegFile Class
========================================================================
- pjJpegFile_GetVersion( void )
- pjJpegFile_GetVersionPatch( void )
- pjJpegFile_GetVersionMinor( void )
- pjJpegFile_GetVersionMajor( void )