#ifndef GAME_TWL_AES_CORE_H
#define GAME_TWL_AES_CORE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of aes_core.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_os.h"
#include "../sdk_os.h"

void PxiCallback(int tag, u32 data, BOOL err);
u32 WaitResult(void);
void AESi_Init(void);
u32 AESi_SeedRand(u32 *seed);
u32 AESi_RandUnit(u8 *buf, ...);
u32 AESi_CalcMac(void *src, u32 data, u32 length, void *mac, void (*callback)(u32, OSEvent *), OSEvent *arg);
/* END mkheaders: generated region */

#endif
