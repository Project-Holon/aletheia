#ifndef GAME_TWL_MI_NDMA_GXCOMMAND_H
#define GAME_TWL_MI_NDMA_GXCOMMAND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mi_ndma_gxcommand.c, prototypes copied from their definitions. */

#include "../types.h"

void MI_SendNDmaGXCommandAsync(u32 ch, u32 src, u32 size, void (*cb)(void *), void *arg);
void MIi_NDMACallback(void);
void MI_SendNDmaGXCommandAsyncFast(u32 ch, u32 src, u32 size, void (*cb)(void *), void *arg);
void MIi_NDMAFastCallback(void);
/* END mkheaders: generated region */

#endif
