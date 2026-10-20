#ifndef GAME_OV021_FLDEFF_BUBBLE_H
#define GAME_OV021_FLDEFF_BUBBLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_bubble.c, prototypes copied from their definitions. */

struct BubbleRes;
struct BubbleWork;
struct BubbleParticle;
typedef struct BubbleRes BubbleRes;
typedef struct BubbleWork BubbleWork;
typedef struct BubbleParticle BubbleParticle;

#include "../ov010/fldmmdl_types.h"
#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../arm9/g3d_system_types.h"

void FLDEFF_BUBBLE_Start(Mmdl *mmdl, FieldEffectSys *fieldEffect);
BubbleRes *FLDEFF_BUBBLE_CreateRes(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_BUBBLE_DeleteRes(FieldEffectSys *fieldEffect, BubbleRes *res);
void FLDEFF_BUBBLE_LoadResources(BubbleRes *res);
void FLDEFF_BUBBLE_FreeResources(BubbleRes *res);
void FLDEFF_BUBBLE_Init(FieldEffectObj *effect, BubbleWork *work);
void FLDEFF_BUBBLE_Exit(void);
void FLDEFF_BUBBLE_Update(FieldEffectObj *effect, BubbleWork *work);
void FLDEFF_BUBBLE_Draw(FieldEffectObj *effect, BubbleWork *work);
BubbleParticle *FLDEFF_BUBBLE_FindFreeBubble(BubbleWork *work);
void FLDEFF_BUBBLE_SpawnBubble(BubbleParticle *bubble, Mmdl *mmdl);
void FLDEFF_BUBBLE_ClearBubble(BubbleParticle *bubble);
void FLDEFF_BUBBLE_UpdateBubble(BubbleParticle *bubble, int endFrame);
void FLDEFF_BUBBLE_DrawBubble(BubbleParticle *bubble, G3dObject *object);
int FLDEFF_BUBBLE_GetFacingVector(Mmdl *mmdl, s16 *dirVec);
/* END mkheaders: generated region */

#endif
