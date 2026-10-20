#ifndef GAME_ARM9_OS_CACHE_H
#define GAME_ARM9_OS_CACHE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_cache.c, prototypes copied from their definitions. */

#include "../types.h"

void DC_FlushAll(void);
void DC_InvalidateRange(void *startAddr, u32 nBytes);
void DC_StoreRange(void *startAddr, u32 nBytes);
void DC_FlushRange(void *startAddr, unsigned long nBytes);
void DC_WaitWriteBufferEmpty(void);
void IC_InvalidateAll(void);
void IC_InvalidateRange(void *startAddr, u32 nBytes);
/* END mkheaders: generated region */

#endif
