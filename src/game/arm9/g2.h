#ifndef GAME_ARM9_G2_H
#define GAME_ARM9_G2_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of g2.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_fx.h"

void G2x_SetBGyAffine_(u32 addr, const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1);
void G2x_SetBlendAlpha_(unsigned int *reg, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
void G2x_SetBlendBrightnessExt_(u32 addr, int plane1, int plane2, int ev1, int ev2, int brightness);
void DWCi_WindowG2x_ChangeBlendBrightness_(u32 addr, int brightness);
/* END mkheaders: generated region */

#endif
