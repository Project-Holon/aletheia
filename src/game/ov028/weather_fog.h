#ifndef GAME_OV028_WEATHER_FOG_H
#define GAME_OV028_WEATHER_FOG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of weather_fog.c, prototypes copied from their definitions. */

struct WeatherTaskSys;

#include "../ov021/weather_task_types.h"

int WEATHER_FOG_BeginFixed(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginParticlesFixed(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginPlainFixed(WeatherTaskSys *task, int variant);
int WEATHER_FOG_RunFixed(void);
int WEATHER_FOG_EndParticlesFixed(WeatherTaskSys *task);
int WEATHER_FOG_EndFadeFixed(WeatherTaskSys *task, int variant);
int WEATHER_FOG_EndFinishFixed(WeatherTaskSys *task, int variant);
void WEATHER_FOG_UpdateParticleFixed(void);
int WEATHER_FOG_BeginKind10(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginKind11(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginKind13(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginKind14(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginParticles(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginPlain(WeatherTaskSys *task, int variant);
int WEATHER_FOG_Run(void);
int WEATHER_FOG_EndParticles(WeatherTaskSys *task);
int WEATHER_FOG_EndFade(WeatherTaskSys *task, int variant);
int WEATHER_FOG_EndFinish(struct WeatherTaskSys *task, int variant);
/* END mkheaders: generated region */

#endif
