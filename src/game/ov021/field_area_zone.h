#ifndef GAME_OV021_FIELD_AREA_ZONE_H
#define GAME_OV021_FIELD_AREA_ZONE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_area_zone.c, prototypes copied from their definitions. */

struct FieldMap;

#include "../types.h"

u32 FIELD_GetAreaZoneId(u32 zoneId, int gridX, int gridZ);
int FIELD_GetPlayerAreaZoneId(struct FieldMap *fieldMap, u16 *zoneIdOut);
/* END mkheaders: generated region */

#endif
