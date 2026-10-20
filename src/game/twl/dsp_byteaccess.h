#ifndef GAME_TWL_DSP_BYTEACCESS_H
#define GAME_TWL_DSP_BYTEACCESS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dsp_byteaccess.c, prototypes copied from their definitions. */

#include "../types.h"

void DSP_LoadData(u32 addr, u8 *dst, u32 len);
void DSP_Store8(u32 addr, u32 val);
void DSP_StoreData(u32 addr, u8 *src, u32 len);
/* END mkheaders: generated region */

#endif
