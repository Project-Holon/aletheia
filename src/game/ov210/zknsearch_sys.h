#ifndef GAME_OV210_ZKNSEARCH_SYS_H
#define GAME_OV210_ZKNSEARCH_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zknsearch_sys.c, prototypes copied from their definitions. */

#include "../types.h"

u32 ZKNSEARCH_SYS_Create(void *man, u32 unused, u32 arg);
u32 ZKNSEARCH_SYS_IsReady(u32 man, u32 unused, u32 args, u32 work);
u32 ZKNSEARCH_SYS_Delete(void *work);
void ZKNSEARCH_SYS_RegisterVBlank(u8 *work);
u32 ZKNSEARCH_SYS_UnregisterVBlank(u8 *work);
void ZKNSEARCH_SYS_VBlankHandler(void *unused,unsigned char *work);
void ZKNSEARCH_SYS_RegisterHBlank(u8 *work);
u32 ZKNSEARCH_SYS_UnregisterHBlank(u8 *work);
void ZKNSEARCH_SYS_HBlankHandler(void *ctx, unsigned char *work);
void ZKNSEARCH_SYS_SetVramBanks(void);
void *ZKNSEARCH_SYS_GetVramBanks(void);
/* END mkheaders: generated region */

#endif
