#ifndef OV024_WEATHER_CLEAR_TYPES_H
#define OV024_WEATHER_CLEAR_TYPES_H

#include "../ov021/weather_task_types.h"

/* Clear weather kind (overlay 24, weather id 0): only the zone fog, no particles (WeatherKindDef of the weather task, ov021 weather_task.c).
 * Needs WeatherTaskSys from the including file: the main file includes
 * ../ov021/weather_task_types.h, a file at another depth declares the typedef. */

/* Work buffer of the clear weather kind (the task's workBuffer). */
typedef struct WeatherZoneFogWork {
    int fadeStarted;  /* 0 until the fade-in has been issued */
} WeatherZoneFogWork;

/* Weather task services (ov021 weather_task.c) used by the clear weather kind. */

/* Stages of the clear weather kind (WeatherKindDef callbacks: task, variant, heap id). */
int WEATHER_CLEAR_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_CLEAR_EndFinish(WeatherTaskSys *task, int variant, int heapId);

#endif
