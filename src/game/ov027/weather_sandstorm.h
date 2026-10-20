#ifndef GAME_OV027_WEATHER_SANDSTORM_H
#define GAME_OV027_WEATHER_SANDSTORM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of weather_sandstorm.c, prototypes copied from their definitions. */

struct WeatherTaskSys;

#include "../ov021/weather_task_types.h"
#include "../types.h"
#include "../ov027/weather_sandstorm_types.h"

int WEATHER_SANDSTORM_Begin(WeatherTaskSys *task, int variant);
int WEATHER_SANDSTORM_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SANDSTORM_BeginPlain(WeatherTaskSys *task, int variant, u16 heapId);
int WEATHER_SANDSTORM_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SANDSTORM_EndParticles(WeatherTaskSys *task);
int WEATHER_SANDSTORM_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SANDSTORM_EndFinish(WeatherTaskSys *task, int variant);
void WEATHER_SANDSTORM_UpdateParticle(WeatherParticle *particle);
void WEATHER_SANDSTORM_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);
void WEATHER_SANDSTORM_ScrollBillboards(struct WeatherTaskSys *task, WeatherSandstormWork *work);
/* END mkheaders: generated region */

#endif
