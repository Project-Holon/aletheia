#ifndef GAME_ARM9_FADE_H
#define GAME_ARM9_FADE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fade.c, prototypes copied from their definitions. */

#include "../types.h"

void FADE_Create(u32 heap);
void FADE_Update(void);
s32 FADE_GetSpeed(void);
void FADE_SetSpeed(s32 a);
void FADE_ResetSpeed(void);
void FADE_Start(u32 a, s32 b, s32 c, s32 d);
int FADE_IsActive(void);
void FADE_ApplyBrightness(void);
/* END mkheaders: generated region */

#endif
