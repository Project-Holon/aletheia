#ifndef GAME_OV210_ZKNSEARCH_SYS_H
#define GAME_OV210_ZKNSEARCH_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zknsearch_sys.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov210/zknsearch_types.h"

struct TcbTask;

u32 ZKNSEARCH_SYS_Create(void *man, u32 unused, void *arg);
u32 ZKNSEARCH_SYS_IsReady(u32 man, u32 unused, u32 args, ZknSearchWork *work);
u32 ZKNSEARCH_SYS_Delete(void *work);
void ZKNSEARCH_SYS_RegisterVBlank(ZknSearchWork *work);
u32 ZKNSEARCH_SYS_UnregisterVBlank(ZknSearchWork *work);
void ZKNSEARCH_SYS_VBlankHandler(struct TcbTask *unused, void *workArg);
void ZKNSEARCH_SYS_RegisterHBlank(ZknSearchWork *work);
u32 ZKNSEARCH_SYS_UnregisterHBlank(ZknSearchWork *work);
void ZKNSEARCH_SYS_HBlankHandler(struct TcbTask *ctx, void *workArg);
void ZKNSEARCH_SYS_SetVramBanks(void);
void *ZKNSEARCH_SYS_GetVramBanks(void);
/* END mkheaders: generated region */

#endif
