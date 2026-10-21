#ifndef GAME_OV064_FIELD_GIMMICK_ARC_EFFECT_H
#define GAME_OV064_FIELD_GIMMICK_ARC_EFFECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_arc_effect.c, prototypes copied from their definitions. */

struct GameEvent;

#include "../sdk_fx.h"
#include "../sdk_fx.h"

void FIELD_GIMMICK_ARC_EFFECT_Init(void *fieldMap);
void FIELD_GIMMICK_ARC_EFFECT_Exit(void *fieldMap);
void FIELD_GIMMICK_ARC_EFFECT_Update(void *fieldMap);
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_StartPlayerEffect(void *gameSystem);
int FIELD_GIMMICK_ARC_EFFECT_PlayerEffectEvent(void *event, int *seq);
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_StartArcEffect(void *gameSystem, const VecFx32 *startPos, const VecFx32 *endPos, int arcHeight, int frameCount);
void FIELD_GIMMICK_ARC_EFFECT_ShowArcModelAt(void *gameSystem, VecFx32 *pos);
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent(void *gameSystem);
struct GameEvent *FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent(void *gameSystem);
int FIELD_GIMMICK_ARC_EFFECT_ArcEffectEvent(void *event, int *unusedSeq);
int FIELD_GIMMICK_ARC_EFFECT_IsArcPeakReached(void *event, int *unusedSeq);
int FIELD_GIMMICK_ARC_EFFECT_IsArcAnimeStopped(void *event, int *unusedSeq);
/* END mkheaders: generated region */

#endif
