#ifndef GAME_ARM9_ZONE_LIGHT_H
#define GAME_ARM9_ZONE_LIGHT_H

/* Public functions of zone_light.c, prototypes copied from their definitions. */

#include "../types.h"

void ZONEDATA_GetTimeLightColors(u32 zoneId, u32 hour, u32 minute, u32 lightTableId, u32 season, u16 *outColors, u16 heapId);
u16 ZONEDATA_GetLightTableMember(u32 i);
void *ZONEDATA_LoadLightTable(u32 archive, u32 member, u32 *countOut, u32 heap);
void ZONEDATA_FindLightEntryColors(u8 *table, u32 count, s32 time, u32 season, u16 *out);

#endif
