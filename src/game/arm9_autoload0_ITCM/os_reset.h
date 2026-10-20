#ifndef GAME_ARM9_AUTOLOAD0_ITCM_OS_RESET_H
#define GAME_ARM9_AUTOLOAD0_ITCM_OS_RESET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_reset.c, prototypes copied from their definitions. */

#include "../types.h"

BOOL OSi_VerifyStaticSegmentHash(const u8 *src, u32 len, const void *digest);
void OSi_VerifyStaticSegments(void);
void OSi_DoResetSystem(void);
void OSi_DoBoot(void);
void OSi_CpuClear32(u32 data, void *destp, u32 size);
void OSi_ReloadRomData(BOOL ontwl);
void OSi_ReadCardRom32(u32 src, void *dst, int len);
/* END mkheaders: generated region */

#endif
