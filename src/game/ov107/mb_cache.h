#ifndef GAME_OV107_MB_CACHE_H
#define GAME_OV107_MB_CACHE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mb_cache.c, prototypes copied from their definitions. */

#include "../sdk_mb.h"
#include "../types.h"

void MBi_InitCache(void *pl);
void MBi_AttachCacheBuffer(MBiCacheList *pl, u32 src, u32 len, void *ptr, u32 state);
int MBi_ReadFromCache(MBiCacheList *pl, u32 src, void *dst, u32 len);
/* END mkheaders: generated region */

#endif
