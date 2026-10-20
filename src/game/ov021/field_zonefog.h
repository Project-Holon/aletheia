#ifndef GAME_OV021_FIELD_ZONEFOG_H
#define GAME_OV021_FIELD_ZONEFOG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_zonefog.c, prototypes copied from their definitions. */

struct FieldZoneFog;
typedef struct FieldZoneFog FieldZoneFog;

#include "../types.h"

FieldZoneFog *FIELD_ZONEFOG_Create(u16 heapId);
int FIELD_ZONEFOG_Delete(FieldZoneFog *zoneFog);
void FIELD_ZONEFOG_Main(FieldZoneFog *zoneFog, u16 heapId);
void FIELD_ZONEFOG_SetUp(FieldZoneFog *zoneFog, u32 fogId, u32 lightId, u8 loadWait);
u8 FIELD_ZONEFOG_IsLoadRequest(FieldZoneFog *zoneFog);
void FIELD_ZONEFOG_Clear(FieldZoneFog *zoneFog);
int FIELD_ZONEFOG_IsFog(FieldZoneFog *zoneFog);
int FIELD_ZONEFOG_IsLight(FieldZoneFog *zoneFog);
int FIELD_ZONEFOG_GetFogOffset(FieldZoneFog *zoneFog);
int FIELD_ZONEFOG_GetFogSlope(FieldZoneFog *zoneFog);
int FIELD_ZONEFOG_GetLightId(FieldZoneFog *zoneFog);
/* END mkheaders: generated region */

#endif
