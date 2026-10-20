#ifndef GAME_OV179_CDEMO_WIPE_H
#define GAME_OV179_CDEMO_WIPE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of cdemo_wipe.c, prototypes copied from their definitions. */

#include "../types.h"

void CDEMO_WIPE_StartFadeOut(char *p, u32 a, u32 b, u32 c);
void CDEMO_WIPE_StartFadeIn(char *p, u32 a, u32 b, u32 c);
void CDEMO_WIPE_StartFadeOutWhite(char *p, u32 a, u32 b, u32 c);
void CDEMO_WIPE_StartFadeInWhite(char *p, u32 a, u32 b, u32 c);
void CDEMO_WIPE_LoadPalette(void *obj, int a, int b);
int CDEMO_WIPE_RunScript(char *p);
/* END mkheaders: generated region */

#endif
