#ifndef GAME_OV021_WEATHER_TASK_H
#define GAME_OV021_WEATHER_TASK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of weather_task.c, prototypes copied from their definitions. */

struct FieldLight;
struct FieldFog;
struct FieldZoneFog;
struct FieldSoundSystem;
struct ClactActor;
typedef struct FieldLight FieldLight;
typedef struct FieldFog FieldFog;
typedef struct FieldZoneFog FieldZoneFog;
typedef struct FieldSoundSystem FieldSoundSystem;
typedef struct ClactActor Actor;

#include "../ov021/weather_task_types.h"
#include "../ov021/field_camera_types.h"
#include "../ov021/weather_task_types.h"
#include "../types.h"
#include "../ov021/field_3dbg_types.h"

WeatherTaskSys *WEATHER_TASK_Create(void *textureBank, FieldCamera *camera, FieldLight *light, FieldFog *fog, FieldZoneFog *zoneFog, WeatherSys *sys, FieldSoundSystem *soundSys, u16 zoneId, u16 heapId);
void WEATHER_TASK_Delete(WeatherTaskSys *task);
void WEATHER_TASK_Update(WeatherTaskSys *task, u16 heapId);
void WEATHER_TASK_Start(WeatherTaskSys *task, const WeatherKindDef *kind, u8 startMode, u32 updatesParticles, u32 variant, u32 useSoundSys, u32 reserved);
void WEATHER_TASK_RequestEnd(WeatherTaskSys *task, u32 updatesParticles, u32 variant);
void WEATHER_TASK_ForceEnd(WeatherTaskSys *task);
void WEATHER_TASK_FadeLight(WeatherTaskSys *task, int arcId, int memberId);
void WEATHER_TASK_SetLight(WeatherTaskSys *task, int arcId, u32 memberId);
void WEATHER_TASK_ResetLight(WeatherTaskSys *task, int phase);
void WEATHER_TASK_FlashLight(WeatherTaskSys *task, u32 color, u32 frames, u32 returnFrames);
int WEATHER_TASK_IsLightFlashing(WeatherTaskSys *task);
int WEATHER_TASK_GetCameraSettingId(WeatherTaskSys *task);
void WEATHER_TASK_SetLightColor(WeatherTaskSys *task, u16 color, u32 frames);
void WEATHER_TASK_SetBillboardVisible(WeatherTaskSys *task, unsigned int value, int layer);
void WEATHER_TASK_SetBillboardScaleX(WeatherTaskSys *task, unsigned int value, int layer);
void WEATHER_TASK_SetBillboardScaleY(WeatherTaskSys *task, unsigned int value, int layer);
void WEATHER_TASK_SetBillboardTexOffsetX(WeatherTaskSys *task, unsigned int value, int layer);
void WEATHER_TASK_SetBillboardTexOffsetY(WeatherTaskSys *task, unsigned int value, int layer);
int WEATHER_TASK_GetPhase(WeatherTaskSys *task);
void *WEATHER_TASK_GetWorkBuffer(WeatherTaskSys *task);
int WEATHER_TASK_GetParticleCount(WeatherTaskSys *task);
WeatherParticle *WEATHER_TASK_AddParticle(WeatherTaskSys *task, int reserved);
void WEATHER_TASK_RemoveParticle(WeatherParticle *particle);
void WEATHER_TASK_SetupSpawner(WeatherTaskSys *task, int count, int interval, int targetCount, int targetInterval, int intervalStep, int stepsPerCountChange, int countStep, WeatherSpawnFunc spawn);
void WEATHER_TASK_RetargetSpawner(WeatherTaskSys *task, int targetCount, int targetInterval, int intervalStep, int countStep);
int WEATHER_TASK_StepSpawner(WeatherTaskSys *task, int arg);
int WEATHER_TASK_StepSpawnTimer(WeatherTaskSys *task, int arg);
void WEATHER_TASK_PrewarmParticles(WeatherTaskSys *task, WeatherSpawnFunc spawn, int iterations, int growEvery, int growBy, u16 heapId);
void WEATHER_TASK_InitFog(WeatherTaskSys *task, int slope, int offset, int phase);
void WEATHER_TASK_DisableFog(WeatherTaskSys *task, int phase);
void WEATHER_TASK_ChangeFog(WeatherTaskSys *task, u8 slope, int offset, int frames, int mode);
void WEATHER_TASK_ChangeFogOffset(WeatherTaskSys *task, int endOffset, int frames, int mode);
int WEATHER_TASK_IsFogIdle(WeatherTaskSys *task);
int WEATHER_TASK_IsZoneFogActive(WeatherTaskSys *task);
int WEATHER_TASK_IsZoneFog(WeatherTaskSys *task);
int WEATHER_TASK_IsZoneFogLight(WeatherTaskSys *task);
int WEATHER_TASK_GetZoneFogOffset(WeatherTaskSys *task);
int WEATHER_TASK_GetZoneFogSlope(WeatherTaskSys *task);
int WEATHER_TASK_GetZoneFogLightId(WeatherTaskSys *task);
void WEATHER_TASK_SaveCameraPos(WeatherTaskSys *task);
void WEATHER_TASK_GetCameraScroll(WeatherTaskSys *task, s32 *outX, s32 *outY);
void WEATHER_TASK_ShiftParticles(WeatherTaskSys *task, int dx, int dy);
void WEATHER_TASK_PlaySe(WeatherTaskSys *task, u16 seId);
void WEATHER_TASK_StopSe(WeatherTaskSys *task);
void WEATHER_TASK_PlaySeDirect(WeatherTaskSys *task, int seId);
void WEATHER_TASK_PlaySeWithVoice(WeatherTaskSys *task, int seId, int who);
u8 *WEATHER_TASK_GetParticleWork(WeatherParticle *particle);
Actor *WEATHER_TASK_GetParticleActor(WeatherParticle *particle);
void WEATHER_TASK_GetParticlePos(WeatherParticle *particle, WeatherScreenPos *out);
void WEATHER_TASK_SetParticlePosWrapped(WeatherParticle *particle, u16 *src);
void WEATHER_TASK_SetParticlePos(WeatherParticle *particle, const WeatherScreenPos *pos);
void WEATHER_TASK_Reset(WeatherTaskSys *task);
int WEATHER_TASK_CallStageFunc(WeatherTaskSys *task, WeatherKindStageFunc stageFunc, int heapId);
u8 WEATHER_TASK_GetStagePhase(WeatherTaskSys *task);
WeatherParticle *WEATHER_TASK_FindFreeParticle(WeatherTaskSys *task);
void WEATHER_TASK_LinkParticle(WeatherTaskSys *task, WeatherParticle *particle);
void WEATHER_TASK_UnlinkParticle(WeatherTaskSys *task, WeatherParticle *particle);
void WEATHER_TASK_UpdateParticles(WeatherTaskSys *task);
void WEATHER_TASK_LoadResources(WeatherTaskSys *task, u16 heapId);
void WEATHER_TASK_UnloadResources(WeatherTaskSys *task);
void WEATHER_TASK_InitBillboards(WeatherTaskSys *task, u16 heapId);
void WEATHER_TASK_FreeBillboards(WeatherTaskSys *task);
void WEATHER_TASK_AllocParticles(WeatherTaskSys *task, u16 heapId);
void WEATHER_TASK_FreeParticles(WeatherTaskSys *task);
void WEATHER_TASK_MarkStarted(WeatherTaskSys *task);
u8 WEATHER_TASK_IsStarted(WeatherTaskSys *task);
void WEATHER_TASK_LoadArchive(WeatherResourceSet *resources, const WeatherKindDef *kind, u32 heapId);
void WEATHER_TASK_FreeArchive(WeatherResourceSet *resources);
void WEATHER_TASK_LoadSpriteResources(WeatherResourceSet *resources, const WeatherKindDef *kind, u16 heapId);
void WEATHER_TASK_FreeSpriteResources(WeatherResourceSet *resources);
void WEATHER_TASK_InitBillboard(WeatherResourceSet *resources, int index, Field3dbgBillboard *billboard, const WeatherBillboardInit *init, unsigned short heapId);
void WEATHER_TASK_FreeBillboard(WeatherResourceSet *resources, int index, Field3dbgBillboard *billboard);
WeatherSpawner *WEATHER_TASK_InitSpawner(WeatherSpawner *spawner, WeatherTaskSys *owner, u32 interval, u32 count, u32 targetCount, u32 targetInterval, u32 intervalStep, u32 stepsPerCountChange, u32 countStep, WeatherSpawnFunc spawn);
void WEATHER_TASK_SetSpawnerTarget(WeatherSpawner *spawner, int targetCount, int targetInterval, int intervalStep, int countStep);
s32 WEATHER_TASK_TickSpawner(WeatherSpawner *spawner, u32 arg);
int WEATHER_TASK_TickSpawnTimer(WeatherSpawner *spawner, int arg);
void WEATHER_TASK_ClearParticle(WeatherParticle *particle);
int WEATHER_TASK_IsParticleLinked(WeatherParticle *particle);
void WEATHER_TASK_CreateParticleActor(WeatherParticle *particle, WeatherTaskSys *owner, const WeatherResourceSet *resources, void *textureBank, u16 heapId);
void WEATHER_TASK_DestroyParticleActor(WeatherParticle *particle);
u8 *WEATHER_TASK_GetParticleWorkPtr(WeatherParticle *particle);
Actor *WEATHER_TASK_GetParticleActorPtr(WeatherParticle *particle);
void WEATHER_TASK_SetSoundUseSoundSys(WeatherSoundState *sound, u32 useSoundSys);
void WEATHER_TASK_PlaySound(WeatherSoundState *sound, FieldSoundSystem *soundSys, u16 seId);
void WEATHER_TASK_StopSound(WeatherSoundState *sound, FieldSoundSystem *soundSys);
void WEATHER_TASK_ResumeSound(WeatherSoundState *sound, FieldSoundSystem *soundSys);
void WEATHER_TASK_QueueFogChange(WeatherTaskSys *task, u8 slope, u32 offset, int firstStepFrames);
void WEATHER_TASK_ClearFogChange(WeatherTaskSys *task);
u8 WEATHER_TASK_HasFogChange(WeatherTaskSys *task);
void WEATHER_TASK_ApplyFogChange(WeatherTaskSys *task);
void WEATHER_TASK_GetViewScale(WeatherViewScale *scale, int distance, int *outWidth, int *outHeight);
/* END mkheaders: generated region */

#endif
