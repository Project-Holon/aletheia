#ifndef GAME_ARM9_TIMEZONE_H
#define GAME_ARM9_TIMEZONE_H

/* Public functions of timezone.c, prototypes copied from their definitions. */

#include "../types.h"

u32 TIMEZONE_GetNowTimeZone(u32 season);
int TIMEZONE_GetTimeZoneOfHour(int season, int hour);
u8 TIMEZONE_GetLight(int season, int timeZone);
u32 TIMEZONE_IsNight(u32 season);

#endif
