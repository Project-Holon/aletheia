# unit_02079304.c (arm9)

Translation unit 02079304..0207A7BC, 42 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02079304.c` is blocked by:

- FSi_ReadTable.c..fs_isarchivetableloaded.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_SeekDirDefault.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_SeekDirDefau
- FSi_ReadTable.c..FSi_ROMFAT_Activate.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_SeekDirDefault.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_SeekDirDefau
- FSi_ReadTable.c..FSi_TranslateCommand.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_SeekDirDefault.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_SeekDirDefau
- FSi_ReadTable.c..FSi_FindPathDefault.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_SeekDirDefault.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_SeekDirDefau
- FSi_SeekDirDefault.c..FSi_FindPathDefault.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_ReadDirDefault.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_ReadDirDefau
- FSi_GetPathDefault.c..FSi_TranslateCommand.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_ReadFileDefault.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_ReadFileDef
- FSi_GetPathDefault.c..FSi_OpenFileFastDefault.c: prototype of FSi_TranslateCommand differs between members (src/matched/arm9_sdk/FSi_OpenFileFastDefault.c)
- FSi_ReadFileDefault.c..FSi_TranslateCommand.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_WriteFileDefault.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_WriteFileD
- FSi_WriteFileDefault.c..FSi_TranslateCommand.c: c99=CCERR: line 235: struct/union/enum/class tag 'FSROMFATArchiveContext' redefined | line 239: identifier 'FSROMFATArchiveContext' redeclared | line 239: was declared as: 'struct FSROMFATArchiveConte
- FSi_ROMFAT_ReadFile.c..FSi_ROMFAT_Activate.c: c99=CCERR: line 890: object 'FS_SetFileHandle(struct FSFile *, struct FSArchive *, void *)' redefined | line 899: object 'FS_SetDirectoryHandle(struct FSFile *, struct FSArchive *, void *)' redefined 
- FSi_ROMFAT_GetPath.c..FSi_ROMFAT_Activate.c: c99=CCERR: line 459: object 'FS_SetFileHandle(struct FSFile *, struct FSArchive *, void *)' redefined | line 468: object 'FS_SetDirectoryHandle(struct FSFile *, struct FSArchive *, void *)' redefined 
- FSi_ROMFAT_OpenFileDirect.c..FSi_ROMFAT_Activate.c: c99=CCERR: line 372: object 'FS_SetFileHandle(struct FSFile *, struct FSArchive *, void *)' redefined | line 381: object 'FS_SetDirectoryHandle(struct FSFile *, struct FSArchive *, void *)' redefined 
- FSi_ROMFAT_Idle.c..fs_isarchivetableloaded.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT_Suspend.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT_Suspe
- FSi_ROMFAT_Idle.c..FSi_ROMFAT_GetArchiveResource.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT_Suspend.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT_Suspe
- FSi_ROMFAT_Idle.c..fsi_romfat_getfilelength.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT_Suspend.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT_Suspe
- FSi_ROMFAT_Resume.c..fsi_romfat_getfilelength.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT_OpenFile.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT_Open
- FSi_ROMFAT_OpenFile.c..fsi_romfat_getfilelength.c: c99=DIFF nolang=DIFF
- fsi_romfat_getfileposition.c..FSi_ROMFAT_GetArchiveResource.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT_OpenDirectory.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_ROMFAT
- FSi_ROMFAT_OpenDirectory.c..FSi_ROMFAT_GetArchiveResource.c: c99=DIFF nolang=DIFF
- FSi_ReadMemCallback.c..fs_isarchivetableloaded.c: type typedef FS_ARCHIVE_READ_FUNC differs between members (src/matched/arm9_sdk/FSi_WriteMemCallback.c); type typedef FS_ARCHIVE_WRITE_FUNC differs between members (src/matched/arm9_sdk/FSi_WriteMemCa
- FSi_ReadMemCallback.c..FSi_GetFilePositionIfProc.c: c99=DIFF nolang=DIFF
- FS_LoadArchive.c..FSi_GetFilePositionIfProc.c: c99=DIFF nolang=DIFF
- no verified entry for 0207A51C

Status after the merge-lane pass (same-settings runs merged greedily; the blocker list above may include entries already resolved):

Parts: unit_02079304_p01.c, unit_02079304_p02.c, unit_02079304_p03.c, unit_02079304_p04.c, unit_02079304_p05.c, unit_02079304_p06.c, unit_02079304_p07.c

Members still separate:

- `FSi_GetPathDefault.c`
- `FSi_OpenFileFastDefault.c`
- `FSi_ROMFAT_OpenDirectory.c`
- `FSi_SeekDirDefault.c`
- `FSi_TranslateCommand.c`

- `FSi_OpenFileDirectDefault.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `FSi_ROMFAT_SeekFile.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `fsi_romfat_getarchivecaps.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `fsi_romfat_closedirectory.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
