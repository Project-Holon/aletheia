#ifndef GAME_OV021_WEATHER_H
#define GAME_OV021_WEATHER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of weather.c, prototypes copied from their definitions. */

struct FieldCamera;
struct FieldLight;
struct FieldFog;
struct FieldZoneFog;
struct FieldSoundSystem;

#include "../ov021/weather_task_types.h"
#include "../types.h"

struct TcbTask;

WeatherSys *WEATHER_Create(struct FieldCamera *camera, struct FieldLight *light, struct FieldFog *fog, struct FieldZoneFog *zoneFog, struct FieldSoundSystem *soundSys, u16 zoneId, u16 heapId);
void WEATHER_Delete(WeatherSys *sys);
void WEATHER_Update(WeatherSys *sys, u16 frames);
void WEATHER_Draw(WeatherSys *sys);
int WEATHER_IsTaskActive(WeatherSys *sys);
void WEATHER_SetImmediate(WeatherSys *sys, int weatherId, int fadeParam);
void WEATHER_RequestChange(WeatherSys *sys, u16 weatherId);
int WEATHER_RequestChangeNoFade(WeatherSys *sys, u16 weatherId);
u16 WEATHER_GetWeatherId(WeatherSys *sys);
void WEATHER_LoadOverlay(WeatherSys *sys, u32 overlayId);
void WEATHER_UnloadOverlay(WeatherSys *sys);
void WEATHER_ReleaseBillboardVramTask(struct TcbTask *task, void *work);
int WEATHER_StartTransition(WeatherSys *sys, u16 weatherId);
void WEATHER_UpdateSequential(WeatherSys *sys, int frames);
void WEATHER_UpdateCrossfade(WeatherSys *sys, int frames);
int WEATHER_GetTransitionMode(u16 currentWeatherId, u16 nextWeatherId);
/* END mkheaders: generated region */

#endif
