#ifndef GAME_TWL_DSP_G711_H
#define GAME_TWL_DSP_G711_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dsp_g711.c, prototypes copied from their definitions. */

#include "../types.h"

void DSPi_OpenStaticComponentG711Core(u32 *file);
u32 DSPi_LoadG711Core(u32 file, u16 bankMaskA, u16 bankMaskB);
void DSPi_UnloadG711Core(void);
/* END mkheaders: generated region */

#endif
