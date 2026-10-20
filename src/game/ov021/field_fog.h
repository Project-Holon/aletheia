#ifndef GAME_OV021_FIELD_FOG_H
#define GAME_OV021_FIELD_FOG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_fog.c, prototypes copied from their definitions. */

struct FieldFog;
struct FieldFogFade;
typedef struct FieldFog FieldFog;
typedef struct FieldFogFade FieldFogFade;

#include "../types.h"

FieldFog *FIELD_FOG_Create(u16 heapId);
void FIELD_FOG_Delete(FieldFog *fog);
void FIELD_FOG_Main(FieldFog *fog);
void FIELD_FOG_Reflect(FieldFog *fog);
void FIELD_FOG_SetFlag(FieldFog *fog, u32 flag);
void FIELD_FOG_SetBlendMode(FieldFog *fog, u32 blendMode);
void FIELD_FOG_SetSlope(FieldFog *fog, u32 slope);
void FIELD_FOG_SetOffset(FieldFog *fog, u32 offset);
void FIELD_FOG_SetColorRgb(FieldFog *fog, u32 colorRgb);
void FIELD_FOG_SetColorA(FieldFog *fog, u32 alpha);
u32 FIELD_FOG_GetSlope(FieldFog *fog);
void FIELD_FOG_InitFogTable(FieldFog *fog);
void FIELD_FOG_FADE_Init(FieldFog *fog, u32 endOffset, u32 endSlope, u32 frames);
void FIELD_FOG_FADE_InitEx(FieldFog *fog, u32 startOffset, u32 endOffset, u32 startSlope, u32 endSlope, u16 frames);
int FIELD_FOG_FADE_IsFade(FieldFog *fog);
int FIELD_FOG_FadeIsRunning(FieldFogFade *fade);
void FIELD_FOG_FadeStart(FieldFogFade *fade, u32 startOffset, u32 endOffset, u16 startSlope, u16 endSlope, u16 frames);
void FIELD_FOG_FadeStep(FieldFogFade *fade);
u32 FIELD_FOG_FadeGetOffset(FieldFogFade *fade);
u16 FIELD_FOG_FadeGetSlope(FieldFogFade *fade);
/* END mkheaders: generated region */

#endif
