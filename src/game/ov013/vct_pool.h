#ifndef GAME_OV013_VCT_POOL_H
#define GAME_OV013_VCT_POOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vct_pool.c, prototypes copied from their definitions. */

#include "../ov013/vct_types.h"
#include "../types.h"

int VCT_POOL_InitFrames(VctRxPacket *buffer, u32 size);
void VCT_POOL_Reset(void);
VctRxPacket *VCT_POOL_AllocFrame(void);
void VCT_POOL_FreeFrame(VctRxPacket *frame);
/* END mkheaders: generated region */

#endif
