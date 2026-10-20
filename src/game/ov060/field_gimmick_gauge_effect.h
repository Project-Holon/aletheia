#ifndef GAME_OV060_FIELD_GIMMICK_GAUGE_EFFECT_H
#define GAME_OV060_FIELD_GIMMICK_GAUGE_EFFECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_gauge_effect.c, prototypes copied from their definitions. */

struct GameData;
struct GameComm;

#include "../sdk_fx.h"
#include "../ov060/field_gimmick_gauge_effect_types.h"
#include "../ov011/intrude_comm_types.h"
#include "../types.h"

void FIELD_GIMMICK_GAUGE_EFFECT_Init(void *fieldMap);
void FIELD_GIMMICK_GAUGE_EFFECT_Exit(void *fieldMap);
void FIELD_GIMMICK_GAUGE_EFFECT_Update(void *fieldMap);
void FIELD_GIMMICK_GAUGE_EFFECT_StartEffectAt(void *fieldMap, VecFx32 *pos);
int FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive(void *fieldMap);
void FIELD_GIMMICK_GAUGE_EFFECT_PlaceModels(FieldGimmickGaugeEffectWork *work, void *fieldMap, struct GameData *gameData, IntrudeCommSys *commSys);
void FIELD_GIMMICK_GAUGE_EFFECT_HideGaugeModels(void *expObj);
int FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep(int count);
u8 FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges(struct GameData *gameData, void *expObj, IntrudeCommSys *unusedCommSys);
IntrudeCommSys *FIELD_GIMMICK_GAUGE_EFFECT_GetIntrudeCommSys(struct GameComm *gameComm);
void FIELD_GIMMICK_GAUGE_EFFECT_SetupEffect(void *unused, void *expObj);
void FIELD_GIMMICK_GAUGE_EFFECT_ShowEffect(FieldGimmickGaugeEffectWork *work, void *expObj, VecFx32 *pos);
void FIELD_GIMMICK_GAUGE_EFFECT_UpdateEffect(FieldGimmickGaugeEffectWork *work, void *expObj);
/* END mkheaders: generated region */

#endif
