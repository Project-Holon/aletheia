#ifndef GAME_ARM9_NCFG_BACKUP_H
#define GAME_ARM9_NCFG_BACKUP_H

#include "nvram.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ncfg_backup.c, prototypes copied from their definitions. */

#include "../types.h"

s32 NCFGi_InitBackupMemory(void);
unsigned char NCFG_GetFormatVersion(void);
s32 NCFG_ReadBackupMemory(void *buf, u32 size, s32 index);
s32 NCFG_WriteBackupMemory(s32 index, void *buf, u32 size);
int getSlotInfo(s32 index, u32 *address, u32 *size);
NVRAMResult ReadNVRAM(u32 address, u32 size, void *pData);
NVRAMResult WriteNVRAM(u32 address, u32 size, void *pData);
NVRAMResult VerifyNVRAM(u32 address, u32 size, void *pData);
/* END mkheaders: generated region */

#endif
