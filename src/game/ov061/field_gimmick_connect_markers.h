#ifndef GAME_OV061_FIELD_GIMMICK_CONNECT_MARKERS_H
#define GAME_OV061_FIELD_GIMMICK_CONNECT_MARKERS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_connect_markers.c, prototypes copied from their definitions. */

#include "../ov061/field_gimmick_connect_markers_types.h"

void FIELD_GIMMICK_CONNECT_MARKERS_Init(void *fieldMap);
void FIELD_GIMMICK_CONNECT_MARKERS_Exit(void *fieldMap);
void FIELD_GIMMICK_CONNECT_MARKERS_Update(void *fieldMap);
int FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady(FieldGimmickConnectMarkersWork *unusedWork, void *player);
void FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers(FieldGimmickConnectMarkersWork *unusedWork, void *fieldMap);
/* END mkheaders: generated region */

#endif
