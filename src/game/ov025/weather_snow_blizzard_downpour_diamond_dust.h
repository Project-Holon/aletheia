#ifndef GAME_OV025_WEATHER_SNOW_BLIZZARD_DOWNPOUR_DIAMOND_DUST_H
#define GAME_OV025_WEATHER_SNOW_BLIZZARD_DOWNPOUR_DIAMOND_DUST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of weather_snow_blizzard_downpour_diamond_dust.c, prototypes copied from their definitions. */

#include "../ov021/weather_task_types.h"
#include "../types.h"
#include "../ov025/weather_snow_blizzard_downpour_diamond_dust_types.h"

int WEATHER_SNOW_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_EndFinish(WeatherTaskSys *task, int variant, int heapId);
void WEATHER_SNOW_UpdateParticle(WeatherParticle *particle);
void WEATHER_SNOW_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);
int WEATHER_BLIZZARD_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_Run(WeatherTaskSys *task, int variant, u16 heapId);
int WEATHER_BLIZZARD_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_EndFinish(WeatherTaskSys *task, int variant, int heapId);
void WEATHER_BLIZZARD_UpdateParticle(WeatherParticle *particle);
void WEATHER_BLIZZARD_SpawnParticles(WeatherTaskSys *task, s32 count, u16 heapId);
void WEATHER_BLIZZARD_ScrollFogLayer(WeatherTaskSys *task, WeatherBlizzardWork *work);
int WEATHER_DOWNPOUR_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_EndFinish(WeatherTaskSys *task, int variant, int heapId);
void WEATHER_DOWNPOUR_UpdateParticle(WeatherParticle *particle);
void WEATHER_DOWNPOUR_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);
int WEATHER_DIAMOND_DUST_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_EndFinish(WeatherTaskSys *task, int variant, int heapId);
void WEATHER_DIAMOND_DUST_UpdateParticle(WeatherParticle *particle);
void WEATHER_DIAMOND_DUST_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);
/* END mkheaders: generated region */

#endif
