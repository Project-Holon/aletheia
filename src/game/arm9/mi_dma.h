#ifndef GAME_ARM9_MI_DMA_H
#define GAME_ARM9_MI_DMA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mi_dma.c, prototypes copied from their definitions. */

#include "../types.h"

void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL dmaEnable);
void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
void MIi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
void MI_WaitDma(u32 dmaNo);
void MI_StopDma(u32 dmaNo);
void MI_StopAllDma(void);
void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType);
void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);
/* END mkheaders: generated region */

#endif
