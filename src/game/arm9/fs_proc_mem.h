#ifndef GAME_ARM9_FS_PROC_MEM_H
#define GAME_ARM9_FS_PROC_MEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fs_proc_mem.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_fs.h"

u32 FS_GetFileImageTop(FSFile *file);
int FSi_MemArchiveProc(FSFile *p_file, u32 cmd);
void FSi_InitMemArchive(void);
BOOL FS_CreateFileFromMemory(FSFile *p_file, void *buf, u32 size);
/* END mkheaders: generated region */

#endif
