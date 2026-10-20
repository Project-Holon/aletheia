#ifndef GAME_ARM9_ZONE_WEATHER_H
#define GAME_ARM9_ZONE_WEATHER_H

/* Public functions of zone_weather.c, prototypes copied from their definitions. */

struct Ctx;

#include "../types.h"

u32 WEATHER_GetZoneWeatherId(void *fieldSys, u32 zoneId);
int WEATHER_IsSeasonSynced(int gameData);
void WEATHER_StoreZoneWeatherId(struct Ctx *fieldSys, u32 zoneId);
void WEATHER_RefreshStoredWeatherId(u8 *gameData, int zoneId);
s32 WEATHER_GetAreaOwnerWeather(void *fieldSys, u32 gameData, u32 zoneId);
s32 WEATHER_GetSpecialPowerWeather(void *fieldSys, u32 gameData, u32 zoneId);
u32 WEATHER_GetBirthdayWeather(void *fieldSys, void *gameData, u32 zoneId);

#endif
