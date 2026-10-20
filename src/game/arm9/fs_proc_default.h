#ifndef GAME_ARM9_FS_PROC_DEFAULT_H
#define GAME_ARM9_FS_PROC_DEFAULT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fs_proc_default.c, prototypes copied from their definitions. */

#include "../sdk_fs.h"
#include "../types.h"

FSResult FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len);
void FSi_SeekDirDirect(FSFile *file, u32 id);
FSResult FSi_SeekDirDefault(FSFile *file);
FSResult FSi_ReadDirDefault(FSFile *file);
FSResult FSi_GetPathDefault(FSFile *file);
FSResult FSi_OpenFileFastDefault(FSFile *p_file);
FSResult FSi_OpenFileDirectDefault(FSFile *p_file);
FSResult FSi_ReadFileDefault(FSFile *file);
FSResult FSi_WriteFileDefault(FSFile *file);
FSResult FSi_NoOpCommandDefault(FSFile *file);
FSResult FSi_TranslateCommand(FSFile *file, FSCommandType command, BOOL block);
FSResult FSi_ROMFAT_ReadFile(FSArchive *arc, FSFile *file, void *buffer, u32 *length);
FSResult FSi_ROMFAT_WriteFile(FSArchive *arc, FSFile *file, const void *buffer, u32 *length);
FSResult FSi_ROMFAT_SeekDirectory(FSArchive *arc, FSFile *file, u32 id, u32 position);
FSResult FSi_ROMFAT_ReadDirectory(FSArchive *arc, FSFile *file, FSDirectoryEntryInfo *info);
FSResult FSi_ROMFAT_FindPath(FSArchive *arc, u32 base_dir_id, const char *path, u32 *target_id, BOOL target_is_directory);
FSResult FSi_ROMFAT_GetPath(FSArchive *arc, FSFile *file, BOOL is_directory, char *buffer, u32 *length);
FSResult FSi_ROMFAT_OpenFileFast(FSArchive *arc, FSFile *file, u32 id, u32 mode);
FSResult FSi_ROMFAT_OpenFileDirect(FSArchive *arc, FSFile *file, u32 top, u32 bottom, u32 *id);
FSResult FSi_ROMFAT_CloseFile(FSArchive *arc, FSFile *file);
void FSi_ROMFAT_Activate(FSArchive *arc);
void FSi_ROMFAT_Idle(FSArchive *arc);
void FSi_ROMFAT_Suspend(FSArchive *arc);
void FSi_ROMFAT_Resume(FSArchive *arc);
FSResult FSi_ROMFAT_OpenFile(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode);
FSResult FSi_ROMFAT_SeekFile(FSArchive *arc, FSFile *file, int *offset, FSSeekFileMode from);
int FSi_ROMFAT_GetFileLength(void *arc, void *file, u32 *length);
int FSi_ROMFAT_GetFilePosition(void *arc, void *file, u32 *position);
void FSi_ROMFAT_Unmount(FSArchive *arc);
int FSi_ROMFAT_GetArchiveCaps(void *arc, u32 *caps);
FSResult FSi_ROMFAT_OpenDirectory(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode);
int FSi_ROMFAT_CloseDirectory(void *arc, void *file);
FSResult FSi_ROMFAT_GetPathInfo(FSArchive *arc, u32 baseid, const char *path, FSPathInfo *info);
FSResult FSi_ROMFAT_GetArchiveResource(FSArchive *arc, FSArchiveResource *resource);
FSResult FSi_ReadMemCallback(FSArchive *p_arc, void *dst, u32 pos, u32 size);
FSResult FSi_WriteMemCallback(FSArchive *p_arc, const void *src, u32 pos, u32 size);
BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size, FS_ARCHIVE_READ_FUNC read_func, FS_ARCHIVE_WRITE_FUNC write_func);
BOOL FS_UnloadArchive(FSArchive *arc);
BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length);
BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position);
void FS_SetArchiveProc(void *arc, u32 proc, u32 flags);
u32 FS_LoadArchiveTables(FSArchive *p_arc, void *p_mem, u32 max_size);
void *FS_UnloadArchiveTables(FSArchive *arc);
void *FS_GetArchiveBase(void *arc);
u32 FS_GetArchiveOffset(void *arc, u32 pos);
int FS_IsArchiveTableLoaded(void *arc);
/* END mkheaders: generated region */

#endif
