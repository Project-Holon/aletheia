#ifndef GAME_ARM9_FS_FILE_H
#define GAME_ARM9_FS_FILE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fs_file.c, prototypes copied from their definitions. */

struct FSFile;

#include "../sdk_fs.h"
#include "../types.h"

int FSi_DecrementSjisPosition(const char *str, int pos);
int FSi_IncrementSjisPositionToSlash(const char *str, int pos);
int FSi_DecrementSjisPositionToSlash(const char *str, int pos);
int FSi_TrimSjisTrailingSlash(char *str);
void FS_InitFile(FSFile *file);
BOOL FS_ConvertPathToFileID(FSFileID *p_fileid, const char *path);
BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);
BOOL FS_OpenFileFast(FSFile *file, FSFileID id);
BOOL FS_OpenFileEx(FSFile *file, const char *path, u32 mode);
BOOL FS_CloseFile(FSFile *file);
u32 FS_GetFileLength(FSFile *file);
u32 FS_GetFilePosition(FSFile *file);
int FS_SeekFile(FSFile *file, long offset, FSSeekFileMode origin);
s32 FS_ReadFile(FSFile *file, void *buffer, s32 length);
s32 FS_WriteFile(FSFile *file, void *buffer, s32 length);
BOOL FS_OpenFile(FSFile *file, const char *path);
u32 FS_GetLength(struct FSFile *file);
int FS_ChangeDir(const char *path);
/* END mkheaders: generated region */

#endif
