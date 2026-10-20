#ifndef GAME_ARM9_FS_PROC_ROM_H
#define GAME_ARM9_FS_PROC_ROM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fs_proc_rom.c, prototypes copied from their definitions. */

#include "../sdk_fs.h"
#include "../types.h"

int FSi_IsUnreadableRomOffset(FSArchive *arc, u32 offset);
FSResult FSi_RomArchiveProc(FSFile *file, FSCommandType cmd);
FSResult FSi_EmptyArchiveProc(FSFile *file, FSCommandType cmd);
FSResult FSi_ReadDummyCallback(FSArchive *p_arc, void *dst, u32 src, u32 len);
FSResult FSi_WriteDummyCallback(FSArchive *p_arc, const void *src, u32 pos, u32 len);
BOOL FSi_OverrideRomArchive(FSArchive *arc);
void FSi_InitRomArchive(u32 default_dma_no);
u32 FS_SetDefaultDMA(u32 dma_no);
u32 FS_TryLoadTable(void *p_mem, u32 size);
BOOL FS_CreateFileFromRom(FSFile *p_file, u32 offset, u32 size);
/* END mkheaders: generated region */

#endif
