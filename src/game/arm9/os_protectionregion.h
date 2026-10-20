#ifndef GAME_ARM9_OS_PROTECTIONREGION_H
#define GAME_ARM9_OS_PROTECTIONREGION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_protectionregion.c, prototypes copied from their definitions. */

#include "../types.h"

void OS_SetProtectionRegionParam(int regionNo, u32 param);
void OSi_WriteProtectionRegion0(u32 param);
void OSi_WriteProtectionRegion1(u32 param);
void OSi_WriteProtectionRegion2(u32 param);
void OSi_WriteProtectionRegion3(u32 param);
void OSi_WriteProtectionRegion4(u32 param);
void OSi_WriteProtectionRegion5(u32 param);
void OSi_WriteProtectionRegion6(u32 param);
void OSi_WriteProtectionRegion7(u32 param);
u32 OSi_ReadProtectionRegion0(void);
u32 OSi_ReadProtectionRegion1(void);
u32 OSi_ReadProtectionRegion2(void);
u32 OSi_ReadProtectionRegion3(void);
u32 OSi_ReadProtectionRegion4(void);
u32 OSi_ReadProtectionRegion5(void);
u32 OSi_ReadProtectionRegion6(void);
u32 OSi_ReadProtectionRegion7(void);
void OS_SetProtectionRegionEx(int regionNo, u32 address, u32 sizeDef);
/* END mkheaders: generated region */

#endif
