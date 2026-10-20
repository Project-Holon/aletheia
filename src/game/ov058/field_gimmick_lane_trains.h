#ifndef GAME_OV058_FIELD_GIMMICK_LANE_TRAINS_H
#define GAME_OV058_FIELD_GIMMICK_LANE_TRAINS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_lane_trains.c, prototypes copied from their definitions. */

struct FieldMap;

#include "../ov058/field_gimmick_lane_trains_types.h"

void FIELD_GIMMICK_LANE_TRAINS_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_LANE_TRAINS_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_LANE_TRAINS_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_LANE_TRAINS_PlaceTrains(FieldGimmickLaneTrainsWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(FieldGimmickLaneTrainsWork *work, struct FieldMap *fieldMap, int leadModel, int trailModel);
/* END mkheaders: generated region */

#endif
