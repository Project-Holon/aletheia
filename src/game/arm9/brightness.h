#ifndef GAME_ARM9_BRIGHTNESS_H
#define GAME_ARM9_BRIGHTNESS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of brightness.c, prototypes copied from their definitions. */

struct BrightnessChange;

#include "../types.h"

void BRIGHTNESS_ChangeStep(struct BrightnessChange *p);
void BRIGHTNESS_ChangeInit(struct BrightnessChange *p, u16 steps, s16 from, s16 to, u32 plane, u32 screenMask);
void BRIGHTNESS_ChangeRequest(u16 steps, s16 from, s16 to, u32 plane, u32 mask);
void BRIGHTNESS_Set(u32 brightness, u32 plane, u32 mask);
void BRIGHTNESS_ChangeReset(u32 mask);
void BRIGHTNESS_ChangeMain(void);
int BRIGHTNESS_IsFinished(int a);
/* END mkheaders: generated region */

#endif
