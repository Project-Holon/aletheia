#ifndef GAME_OV026_WEATHER_RAIN_THUNDERSTORM_STORM_H
#define GAME_OV026_WEATHER_RAIN_THUNDERSTORM_STORM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of weather_rain_thunderstorm_storm.c, prototypes copied from their definitions. */

#include "../ov021/weather_task_types.h"
#include "../types.h"
#include "../ov026/weather_rain_thunderstorm_storm_types.h"
#include "../ov026/weather_lightning_types.h"

int WEATHER_RAIN_Begin(WeatherTaskSys *task, int variant);
int WEATHER_RAIN_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_RAIN_BeginPlain(WeatherTaskSys *task, int variant, u16 heapId);
int WEATHER_RAIN_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_RAIN_EndParticles(WeatherTaskSys *task);
int WEATHER_RAIN_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_RAIN_EndFinish(WeatherTaskSys *task, int variant);
void WEATHER_RAIN_UpdateParticle(WeatherParticle *particle);
void WEATHER_RAIN_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);
int WEATHER_THUNDERSTORM_Begin(WeatherTaskSys *task, int variant);
int WEATHER_THUNDERSTORM_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_THUNDERSTORM_BeginPlain(WeatherTaskSys *task, int variant, u16 heapId);
int WEATHER_THUNDERSTORM_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_THUNDERSTORM_EndParticles(WeatherTaskSys *task);
int WEATHER_THUNDERSTORM_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_THUNDERSTORM_EndFinish(WeatherTaskSys *task, int variant);
void WEATHER_THUNDERSTORM_UpdateParticle(WeatherParticle *particle);
void WEATHER_THUNDERSTORM_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);
void WEATHER_THUNDERSTORM_ScrollLayers(WeatherTaskSys *task, WeatherThunderstormWork *work);
int WEATHER_STORM_Begin(WeatherTaskSys *task, int variant);
int WEATHER_STORM_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_STORM_BeginPlain(WeatherTaskSys *task, int variant, u16 heapId);
int WEATHER_STORM_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_STORM_EndParticles(WeatherTaskSys *task, int variant);
int WEATHER_STORM_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_STORM_EndFinish(WeatherTaskSys *task, int variant);
void WEATHER_STORM_UpdateParticle(WeatherParticle *particle);
void WEATHER_STORM_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);
void WEATHER_STORM_UpdateSlowSideDrop(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop);
void WEATHER_STORM_InitSlowSideDrop(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor);
void WEATHER_STORM_UpdateFallingStreak(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop);
void WEATHER_STORM_InitFallingStreak(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor);
void WEATHER_STORM_UpdateFastSideStreak(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop);
void WEATHER_STORM_InitFastSideStreak(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor);
void WEATHER_STORM_StartCalm(WeatherTaskSys *task, WeatherStormWork *work, int variant, int silent);
void WEATHER_STORM_UpdateGust(WeatherTaskSys *task, WeatherStormWork *work, int variant, int silent);
void WEATHER_STORM_ScrollLayers(WeatherTaskSys *task, WeatherStormWork *work);
void WEATHER_STORM_PlayGustWarning(WeatherTaskSys *task, WeatherStormWork *work, int variant, int seId);
void WEATHER_STORM_ResetThunderTimer(WeatherStormWork *work);
void WEATHER_STORM_UpdateThunder(WeatherTaskSys *task, WeatherStormWork *work, int variant);
void WEATHER_LIGHTNING_Init(WeatherLightning *lightning, int mode);
void WEATHER_LIGHTNING_Clear(WeatherLightning *lightning);
void WEATHER_LIGHTNING_Update(WeatherLightning *lightning, WeatherTaskSys *task);
void WEATHER_LIGHTNING_PickShortFlashes(WeatherLightning *lightning);
void WEATHER_LIGHTNING_PickSingleFlash(WeatherLightning *lightning);
void WEATHER_LIGHTNING_PickLongSequence(WeatherLightning *lightning);
unsigned short WEATHER_LIGHTNING_GetFlashColor(WeatherLightning *lightning);
/* END mkheaders: generated region */

#endif
