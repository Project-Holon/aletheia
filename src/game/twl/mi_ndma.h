#ifndef GAME_TWL_MI_NDMA_H
#define GAME_TWL_MI_NDMA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mi_ndma.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../twl/mi_ndma_types.h"

u32 MIi_GetControlData(u32 type);
void MIi_NDma_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, NdmaConfig *cfg, int words, u32 flags);
void MIi_NDmaAsync_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, void (*cb)(), void *arg, NdmaConfig *cfg, int words, u32 flags);
void MI_InitNDma(void);
void MI_NDmaFill(int ch, int dst, int data, int size);
void MI_NDmaCopy(int ch, int src, int dst, int size);
void MI_NDmaFillAsync(int ch, u32 dst, u32 data, u32 size, void (*cb)(), void *arg);
void MI_NDmaCopyAsync(int ch, u32 src, u32 dst, u32 size, void (*cb)(), void *arg);
u32 MI_IsNDmaBusy(int ch);
void MI_WaitNDma(int ch);
void MI_StopNDma(int ch);
void MI_StopAllNDma(void);
void MI_SetNDmaArbitrament(u32 arbitrament, u32 roundRobin);
void MI_InitNDmaConfig(void);
void MI_GetNDmaConfig(int ch, const void *src);
void MIi_CardNDmaRecv32(int ch, const void *src, void *dst);
void MI_Card_NDmaCopy(int ch, const void *src, void *dst);
void MI_Camera_NDmaRecvAsync(u32 ch, u32 dst, u32 blockWordCount, u32 size, int mode, void (*callback)(), void *arg);
/* END mkheaders: generated region */

#endif
