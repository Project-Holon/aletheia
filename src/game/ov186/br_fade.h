#ifndef GAME_OV186_BR_FADE_H
#define GAME_OV186_BR_FADE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_fade.c, prototypes copied from their definitions. */

struct BrFade;

#include "../types.h"

struct BrFade *BR_FADE_Create(u16 heapId);
void BR_FADE_Delete(struct BrFade *fade);
void BR_FADE_Update(struct BrFade *fade);
void BR_FADE_Start(void *fade, int stepIndex, int planeMask, int direction);
void BR_FADE_StartTimed(struct BrFade *fade,u32 stepIndex,u32 planeMask,u32 direction,u32 durationParam);
int BR_FADE_GetResult(struct BrFade *fade);
void BR_FADE_CaptureHwPalettes(struct BrFade *fade);
void BR_FADE_SetBlendColor(struct BrFade *fade,u16 blendColor);
void BR_FADE_BlendFull(struct BrFade *fade, int planeMask);
void BR_FADE_SetBlendLevel(int unused, int planeMask, int level);
void BR_FADE_LoadPalette(struct BrFade *fade,void *archive,u32 fileId,u32 slot,u32 offset,u32 count,u16 heapId);
int BR_FADE_StepFadeBgA(struct BrFade *fade, int *state);
int BR_FADE_StepFadeBgB(struct BrFade *fade, int *state);
int BR_FADE_StepBlend(struct BrFade *fade,int *state);
int BR_FADE_StepPalette(struct BrFade *fade,int *state);
int BR_FADE_StepSubPlane3(struct BrFade *fade,int *state);
void *BR_FADE_GetStepFunc(unsigned stepIndex);
/* END mkheaders: generated region */

#endif
