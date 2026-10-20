#ifndef GAME_ARM9_ISS_CITY_SYS_H
#define GAME_ARM9_ISS_CITY_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_city_sys.c, prototypes copied from their definitions. */

struct IssCitySys;
struct PlayerWork;
struct IssCityUnit;

#include "../types.h"

struct IssCitySys *ISS_CITY_SYS_Create(struct PlayerWork *player, u32 heapId);
void ISS_CITY_SYS_Delete(struct IssCitySys *sys);
void ISS_CITY_SYS_Update(struct IssCitySys *sys);
void ISS_CITY_SYS_Start(struct IssCitySys *sys);
void ISS_CITY_SYS_Stop(struct IssCitySys *sys);
void ISS_CITY_SYS_NotifyZoneChange(struct IssCitySys *sys, u32 zoneId);
void ISS_CITY_SYS_InitState(struct IssCitySys *sys, u32 heapIdUnused, struct PlayerWork *player);
void ISS_CITY_SYS_InitUnits(struct IssCitySys *sys, u32 heapId);
void ISS_CITY_SYS_ReleaseUnits(struct IssCitySys *sys);
void ISS_CITY_SYS_LoadUnits(struct IssCitySys *sys, u32 heapId);
void ISS_CITY_SYS_FreeUnits(struct IssCitySys *sys);
u32 ISS_CITY_SYS_GetMode(struct IssCitySys *sys);
void ISS_CITY_SYS_SetMode(struct IssCitySys *sys, u32 mode);
void ISS_CITY_SYS_Enable(struct IssCitySys *sys);
int ISS_CITY_SYS_Disable(struct IssCitySys *sys);
void ISS_CITY_SYS_HandleZoneChange(struct IssCitySys *sys, u32 zoneId);
u32 ISS_CITY_SYS_GetPlayerZoneId(struct IssCitySys *sys);
u32 ISS_CITY_SYS_IsEnabled(struct IssCitySys *sys);
void ISS_CITY_SYS_UpdateByMode(struct IssCitySys *sys);
void ISS_CITY_SYS_UpdateSteady(struct IssCitySys *sys);
void ISS_CITY_SYS_UpdateFadeIn(struct IssCitySys *sys);
void ISS_CITY_SYS_UpdateFadeOut(struct IssCitySys *sys);
struct IssCityUnit *ISS_CITY_SYS_GetCurrentUnit(struct IssCitySys *sys);
u32 ISS_CITY_SYS_GetCurrentUnitIndex(struct IssCitySys *sys);
int ISS_CITY_SYS_HasCurrentUnit(struct IssCitySys *sys);
int ISS_CITY_SYS_HasUnitForZone(struct IssCitySys *sys, u32 zoneId);
int ISS_CITY_SYS_SelectUnitForZone(struct IssCitySys *sys, u32 zoneId);
u8 ISS_CITY_SYS_FindUnitIndex(struct IssCitySys *sys, u32 zoneId);
u32 ISS_CITY_SYS_GetFadeLevel(struct IssCitySys *sys);
int ISS_CITY_SYS_StepFadeIn(struct IssCitySys *sys);
int ISS_CITY_SYS_StepFadeOut(struct IssCitySys *sys);
void ISS_CITY_SYS_SetFadeLevel(struct IssCitySys *sys, u32 fadeLevel);
u32 ISS_CITY_SYS_GetVolume(struct IssCitySys *sys);
int ISS_CITY_SYS_RefreshVolume(struct IssCitySys *sys);
int ISS_CITY_SYS_CalcUnitVolume(struct IssCitySys *sys);
void ISS_CITY_SYS_SetVolume(struct IssCitySys *sys, u32 volume);
void ISS_CITY_SYS_ApplyVolume(struct IssCitySys *sys);
int ISS_CITY_SYS_CalcOutputVolume(struct IssCitySys *sys);
/* END mkheaders: generated region */

#endif
