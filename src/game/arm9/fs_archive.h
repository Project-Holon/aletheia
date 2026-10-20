#ifndef GAME_ARM9_FS_ARCHIVE_H
#define GAME_ARM9_FS_ARCHIVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fs_archive.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_fs.h"

BOOL FSi_IsEventCommand(FSCommandType command);
void FSi_EndCommand(FSFile *file, FSResult ret);
FSResult FSi_WaitForArchiveCompletion(FSFile *file, FSResult result);
FSResult FSi_InvokeCommand(FSFile *file, FSCommandType command);
FSFile *FSi_NextCommand(FSArchive *arc, BOOL owner);
void FSi_ExecuteAsyncCommand(FSFile *file);
void FSi_ExecuteSyncCommand(FSFile *file);
BOOL FSi_SendCommand(FSFile *file, u32 command, BOOL blocking);
FSArchive *FS_FindArchive(const char *name, int name_len);
BOOL FS_SetCurrentDirectory(const char *path);
int FSi_CopySafeString(char *dst, int dstlen, const char *src, int srclen, BOOL *stickyFailure);
FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath);
void FS_InitArchive(FSArchive *p_arc);
BOOL FS_RegisterArchiveName(FSArchive *p_arc, const char *name, u32 name_len);
void FS_ReleaseArchiveName(FSArchive *p_arc);
char *FS_GetArchiveName(FSArchive *arc);
BOOL FS_MountArchive(FSArchive *arc, void *userdata, const FSArchiveInterface *vtbl);
BOOL FS_UnmountArchive(FSArchive *arc);
BOOL FS_SuspendArchive(FSArchive *p_arc);
BOOL FS_ResumeArchive(FSArchive *arc);
void FS_NotifyArchiveAsyncEnd(FSArchive *arc, int ret);
/* END mkheaders: generated region */

#endif
