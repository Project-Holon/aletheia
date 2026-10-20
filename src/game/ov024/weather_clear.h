#ifndef GAME_OV024_WEATHER_CLEAR_H
#define GAME_OV024_WEATHER_CLEAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of weather_clear.c, prototypes copied from their definitions. */

#include "../ov021/weather_task_types.h"

int WEATHER_CLEAR_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_EndFinish(WeatherTaskSys *task, int variant, int heapId);
/* END mkheaders: generated region */

#endif
