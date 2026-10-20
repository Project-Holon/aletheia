#ifndef GAME_OV021_FIELD_LIGHT_H
#define GAME_OV021_FIELD_LIGHT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_light.c, prototypes copied from their definitions. */

struct FieldLight;
struct LightSlot;
struct FieldLightKeyframe;
struct FieldLightColorLerp;
struct FieldLightDirLerp;
struct FieldLightBlend;
struct FieldLightFade;
typedef struct FieldLight FieldLight;
typedef struct FieldLightKeyframe FieldLightKeyframe;
typedef struct FieldLightColorLerp FieldLightColorLerp;
typedef struct FieldLightDirLerp FieldLightDirLerp;
typedef struct FieldLightBlend FieldLightBlend;
typedef struct FieldLightFade FieldLightFade;

#include "../types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

FieldLight *FIELD_LIGHT_Create(u32 tableId, u32 seconds, u32 season, void *fog, struct LightSlot *slots, u16 heapId);
void FIELD_LIGHT_Delete(FieldLight *light);
void FIELD_LIGHT_Main(FieldLight *light, s32 seconds);
void FIELD_LIGHT_Reflect(FieldLight *light, int force);
void FIELD_LIGHT_ChangeTable(FieldLight *light, u32 arcId, u32 memberId, u32 frames);
void FIELD_LIGHT_ReloadZoneTable(FieldLight *light);
void FIELD_LIGHT_StartColorFade(FieldLight *light, u32 color, u32 frames, u32 returnFrames);
void FIELD_LIGHT_StartColorFadeHold(FieldLight *light, u16 color, u32 frames);
int FIELD_LIGHT_IsColorFading(FieldLight *light);
void FIELD_LIGHT_Apply(const FieldLight *light, void *fog, struct LightSlot *slots);
void FIELD_LIGHT_LoadZoneTable(FieldLight *light, u32 tableId);
void FIELD_LIGHT_LoadTable(FieldLight *light, u32 arcId, u32 memberId);
void FIELD_LIGHT_Dummy(void);
u32 FIELD_LIGHT_FindKeyframe(FieldLight *light, int seconds);
int FIELD_LIGHT_GetKeyframeSeconds(u32 season, const FieldLightKeyframe *keyframe);
void FIELD_LIGHT_InitColorLerp(FieldLightColorLerp *lerp, s32 from, u32 to);
u16 FIELD_LIGHT_EvalColorLerp(FieldLightColorLerp *lerp, int step, int stepCount);
void FIELD_LIGHT_InitDirLerp(FieldLightDirLerp *lerp, const VecFx16 *from, const VecFx16 *to);
void FIELD_LIGHT_EvalDirLerp(FieldLightDirLerp *lerp, s32 step, s32 stepCount, s16 *out);
void FIELD_LIGHT_BeginBlendDefault(FieldLightBlend *blend, FieldLightKeyframe *from, FieldLightKeyframe *to);
void FIELD_LIGHT_BeginBlend(FieldLightBlend *blend, FieldLightKeyframe *from, FieldLightKeyframe *to, u32 frames);
void FIELD_LIGHT_BeginColorBlend(FieldLightBlend *blend, FieldLightKeyframe *from, u32 color, u32 frames);
void FIELD_LIGHT_StepBlend(FieldLightBlend *blend);
int FIELD_LIGHT_IsBlending(const FieldLightBlend *blend);
void FIELD_LIGHT_EvalBlend(const FieldLightBlend *blend, FieldLightKeyframe *out);
FieldLightFade *FIELD_LIGHT_FADE_Init(FieldLightFade *fade, u16 frames, u32 returnFrames, u32 color);
void FIELD_LIGHT_FADE_InitHold(FieldLightFade *fade, u16 frames, u16 color);
s32 FIELD_LIGHT_FADE_Update(FieldLightFade *fade, FieldLightBlend *blend, FieldLightKeyframe *current, FieldLightKeyframe *target);
int FIELD_LIGHT_FADE_IsActive(FieldLightFade *fade);
/* END mkheaders: generated region */

#endif
