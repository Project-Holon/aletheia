#ifndef GAME_OV052_FIELD_GIMMICK_BSUBWAY_H
#define GAME_OV052_FIELD_GIMMICK_BSUBWAY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_bsubway.c, prototypes copied from their definitions. */

struct FieldMap;
struct FieldEffectObj;

#include "../types.h"
#include "../sdk_fx.h"
#include "../ov052/field_gimmick_bsubway_types.h"

void FIELD_GIMMICK_BSUBWAY_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_StartTrain(struct FieldMap *fieldMap, u32 modelIndex, const VecFx32 *pos);
struct FieldEffectObj *FIELD_GIMMICK_BSUBWAY_GetTrainEffect(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_InitTrain(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_ExitTrain(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_HaltTrainSway(struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_InitTrainSway(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_ExitTrainSway(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_UpdateTrainSway(BsubwayZoneGimmick *zone, struct FieldMap *fieldMap);
void FIELD_GIMMICK_BSUBWAY_FindZoneEntry(int zoneId, int *slotId, int *handlerIndex);
/* END mkheaders: generated region */

#endif
