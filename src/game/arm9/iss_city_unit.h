#ifndef GAME_ARM9_ISS_CITY_UNIT_H
#define GAME_ARM9_ISS_CITY_UNIT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_city_unit.c, prototypes copied from their definitions. */

struct IssCityUnit;

#include "../types.h"

struct IssCityUnit *ISS_CITY_UNIT_Create(u32 heapId, u32 memberIndex);
void ISS_CITY_UNIT_Delete(struct IssCityUnit *unit);
u32 ISS_CITY_UNIT_GetZoneId(struct IssCityUnit *unit);
u8 ISS_CITY_UNIT_CalcVolume(const struct IssCityUnit *unit, const s32 *playerPos);
void ISS_CITY_UNIT_Copy(const struct IssCityUnit *src, struct IssCityUnit *dst);
u8 ISS_CITY_UNIT_CalcVolumeFromAxes(const struct IssCityUnit *unit, const s32 *playerPos);
u8 ISS_CITY_UNIT_CalcVolumeX(const struct IssCityUnit *unit, const s32 *playerPos);
u8 ISS_CITY_UNIT_CalcVolumeY(const struct IssCityUnit *unit, const s32 *playerPos);
u8 ISS_CITY_UNIT_CalcVolumeZ(const struct IssCityUnit *unit, const s32 *playerPos);
u32 ISS_CITY_UNIT_FindStepX(const struct IssCityUnit *unit, const s32 *playerPos);
u32 ISS_CITY_UNIT_FindStepY(const struct IssCityUnit *unit, const s32 *playerPos);
u32 ISS_CITY_UNIT_FindStepZ(const struct IssCityUnit *unit, const s32 *playerPos);
s32 ISS_CITY_UNIT_GetCenterX(const struct IssCityUnit *unit);
s32 ISS_CITY_UNIT_GetCenterY(const struct IssCityUnit *unit);
s32 ISS_CITY_UNIT_GetCenterZ(const struct IssCityUnit *unit);
s32 ISS_CITY_UNIT_Interpolate(s32 distA, s32 volumeA, s32 distB, s32 volumeB, s32 dist);
/* END mkheaders: generated region */

#endif
