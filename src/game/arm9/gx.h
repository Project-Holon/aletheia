#ifndef GAME_ARM9_GX_H
#define GAME_ARM9_GX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gx.c, prototypes copied from their definitions. */

#include "../types.h"

void GX_Init(void);
void GX_SetVCountEqVal(s32 val);
long GX_HBlankIntr(int enable);
long GX_VBlankIntr(int enable);
u16 GX_IsDispOn(void);
void GX_DispOff(void);
void GX_DispOn(void);
void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
void GXS_SetGraphicsMode(u32 mode);
void GXx_SetMasterBrightness_(vu16 *reg, int brightness);
int GXx_GetMasterBrightness_(vu16 *reg);
/* END mkheaders: generated region */

#endif
