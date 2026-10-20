/*
 * file:     weather_task.c
 * unit:     yes
 * function: WEATHER_TASK_Create, WEATHER_TASK_Delete, WEATHER_TASK_Update, WEATHER_TASK_Start, WEATHER_TASK_RequestEnd, WEATHER_TASK_ForceEnd, WEATHER_TASK_FadeLight, WEATHER_TASK_SetLight, WEATHER_TASK_ResetLight, WEATHER_TASK_FlashLight, WEATHER_TASK_IsLightFlashing, WEATHER_TASK_GetCameraSettingId, WEATHER_TASK_SetLightColor, WEATHER_TASK_SetBillboardVisible, WEATHER_TASK_SetBillboardScaleX, WEATHER_TASK_SetBillboardScaleY, WEATHER_TASK_SetBillboardTexOffsetX, WEATHER_TASK_SetBillboardTexOffsetY, WEATHER_TASK_GetPhase, WEATHER_TASK_GetWorkBuffer, WEATHER_TASK_GetParticleCount, WEATHER_TASK_AddParticle, WEATHER_TASK_RemoveParticle, WEATHER_TASK_SetupSpawner, WEATHER_TASK_RetargetSpawner, WEATHER_TASK_StepSpawner, WEATHER_TASK_StepSpawnTimer, WEATHER_TASK_PrewarmParticles, WEATHER_TASK_InitFog, WEATHER_TASK_DisableFog, WEATHER_TASK_ChangeFog, WEATHER_TASK_ChangeFogOffset, WEATHER_TASK_IsFogIdle, WEATHER_TASK_IsZoneFogActive, WEATHER_TASK_IsZoneFog, WEATHER_TASK_IsZoneFogLight, WEATHER_TASK_GetZoneFogOffset, WEATHER_TASK_GetZoneFogSlope, WEATHER_TASK_GetZoneFogLightId, WEATHER_TASK_SaveCameraPos, WEATHER_TASK_GetCameraScroll, WEATHER_TASK_ShiftParticles, WEATHER_TASK_PlaySe, WEATHER_TASK_StopSe, WEATHER_TASK_PlaySeDirect, WEATHER_TASK_PlaySeWithVoice, WEATHER_TASK_GetParticleWork, WEATHER_TASK_GetParticleActor, WEATHER_TASK_GetParticlePos, WEATHER_TASK_SetParticlePosWrapped, WEATHER_TASK_SetParticlePos, WEATHER_TASK_Reset, WEATHER_TASK_CallStageFunc, WEATHER_TASK_GetStagePhase, WEATHER_TASK_FindFreeParticle, WEATHER_TASK_LinkParticle, WEATHER_TASK_UnlinkParticle, WEATHER_TASK_UpdateParticles, WEATHER_TASK_LoadResources, WEATHER_TASK_UnloadResources, WEATHER_TASK_InitBillboards, WEATHER_TASK_FreeBillboards, WEATHER_TASK_AllocParticles, WEATHER_TASK_FreeParticles, WEATHER_TASK_MarkStarted, WEATHER_TASK_IsStarted, WEATHER_TASK_LoadArchive, WEATHER_TASK_FreeArchive, WEATHER_TASK_LoadSpriteResources, WEATHER_TASK_FreeSpriteResources, WEATHER_TASK_InitBillboard, WEATHER_TASK_FreeBillboard, WEATHER_TASK_InitSpawner, WEATHER_TASK_SetSpawnerTarget, WEATHER_TASK_TickSpawner, WEATHER_TASK_TickSpawnTimer, WEATHER_TASK_ClearParticle, WEATHER_TASK_IsParticleLinked, WEATHER_TASK_CreateParticleActor, WEATHER_TASK_DestroyParticleActor, WEATHER_TASK_GetParticleWorkPtr, WEATHER_TASK_GetParticleActorPtr, WEATHER_TASK_SetSoundUseSoundSys, WEATHER_TASK_PlaySound, WEATHER_TASK_StopSound, WEATHER_TASK_ResumeSound, WEATHER_TASK_QueueFogChange, WEATHER_TASK_ClearFogChange, WEATHER_TASK_HasFogChange, WEATHER_TASK_ApplyFogChange, WEATHER_TASK_GetViewScale
 * address:  0x021A1DB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchors 021A1DF4 and 021A2920 (gWeatherTaskFileName "weather_task.c"); constructor 021A1DB4 allocates the 0x784-byte task.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gWeatherTaskFileName     0x021DDE80  data  ov021  a4
 *   FIELD_FOG_FADE_IsFade  0x021A0244  thumb  ov021
 *   FIELD_LIGHT_ChangeTable  0x021A0590  thumb  ov021
 *   FIELD_LIGHT_ReloadZoneTable  0x021A05D8  thumb  ov021
 *   FIELD_LIGHT_StartColorFade  0x021A0618  thumb  ov021
 *   FIELD_LIGHT_IsColorFading 0x021A065C thumb ov021
 *   FIELD_CAMERA_GetSettingId 0x0218E188 thumb ov021
 *   FIELD_LIGHT_StartColorFadeHold 0x021A063C thumb ov021
 *   FIELD_3DBG_SetBillboardVisible 0x021A16D4 thumb ov021
 *   FIELD_3DBG_SetBillboardScaleX 0x021A16E4 thumb ov021
 *   FIELD_3DBG_SetBillboardScaleY 0x021A16E8 thumb ov021
 *   FIELD_3DBG_SetBillboardTexOffsetX 0x021A16DC thumb ov021
 *   FIELD_3DBG_SetBillboardTexOffsetY 0x021A16E0 thumb ov021
 *   FIELD_FOG_SetBlendMode  0x021A01AC  thumb  ov021
 *   FIELD_FOG_SetColorA  0x021A01CC  thumb  ov021
 *   FIELD_FOG_SetSlope  0x021A01B4  thumb  ov021
 *   FIELD_FOG_SetOffset  0x021A01BC  thumb  ov021
 *   FIELD_FOG_InitFogTable  0x021A01D8  thumb  ov021
 *   FIELD_FOG_SetFlag  0x021A01A4  thumb  ov021
 *   FIELD_FOG_FADE_Init  0x021A01FC  thumb  ov021
 *   FIELD_FOG_GetSlope  0x021A01D4  thumb  ov021
 *   FIELD_ZONEFOG_IsLoadRequest  0x021A0354  thumb  ov021
 *   FIELD_ZONEFOG_IsFog  0x021A0380  thumb  ov021
 *   FIELD_ZONEFOG_IsLight  0x021A0390  thumb  ov021
 *   FIELD_ZONEFOG_GetFogOffset  0x021A03A4  thumb  ov021
 *   FIELD_ZONEFOG_GetFogSlope  0x021A03B8  thumb  ov021
 *   FIELD_ZONEFOG_GetLightId  0x021A03CC  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   VEC_Distance  0x0207CF3C  arm
 *   FX_Div  0x0207C768  arm
 *   g_DefaultProjectionMtx  0x02148B54  data
 *   CLACT_GetActorPos  0x0204B53C  arm
 *   CLACT_SetActorPos  0x0204B528  arm
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot  0x02028A7C  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlotWithOwner  0x02028ACC  thumb
 *   GFL_USE_PlaySeWithVolume  0x020061F0  thumb
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   gWeatherStagePhase  0x021D88E8  data  a1
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   FIELD_3DBG_LoadBillboardTexture  0x021A1698  thumb  ov021
 *   FIELD_3DBG_SetBillboardPolygonId  0x021A16D8  thumb  ov021
 *   gWeatherBillboardTextureDesc     0x021EE710  data  a4
 *   d_021EE710b    0x021EE710  data  a4
 *   FIELD_3DBG_FreeBillboardTexture  0x021A1680  thumb  ov021
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorVisible  0x0204BA20  arm
 *   gWeatherParticlePosition  0x021D88E0  data  a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   FIELD_SOUND_SYSTEM_ReleaseSlot  0x02028B50  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   FIELD_FOG_FADE_InitEx  0x021A0224  thumb  ov021
 */
#include "weather_task_types.h"

typedef struct FieldCamera FieldCamera;
typedef struct FieldFog FieldFog;
typedef struct FieldLight FieldLight;
typedef struct FieldSoundSystem FieldSoundSystem;
typedef struct FieldZoneFog FieldZoneFog;
typedef struct ClactActor Actor;

#include "../arm9/gfl_heap_wrap.h"
#include "field_fog.h"
#include "field_zonefog.h"
extern u32 FIELD_LIGHT_ChangeTable(FieldLight *light, u32 arcId, u32 memberId, u32 frames);
void FIELD_LIGHT_ReloadZoneTable(FieldLight *light);
extern void FIELD_LIGHT_StartColorFade(FieldLight *light, u32 color, u32 frames, u32 returnFrames);
extern int FIELD_LIGHT_IsColorFading(FieldLight *light);
#include "field_camera.h"
extern void FIELD_LIGHT_StartColorFadeHold(FieldLight *light, u32 color, u32 frames);
#include "field_3dbg.h"
struct Field3dbgBillboard;
struct G3dCamera;
#include "../arm9/g3d_camera.h"
#include "../arm9/fx_vec.h"
#include "../arm9/fx_cp.h"
struct Pt16;
#include "../arm9/clact.h"
#include "../arm9/gfl_use.h"
#include "../arm9/field_sound_system.h"
#include "../arm9/mi_memory.h"
#include "../arm9/arc_tool.h"
struct Field3dbgTextureDesc;


WeatherTaskSys *WEATHER_TASK_Create(void *textureBank, FieldCamera *camera, FieldLight *light, FieldFog *fog, FieldZoneFog *zoneFog, WeatherSys *sys, FieldSoundSystem *soundSys, u16 zoneId, u16 heapId);
void WEATHER_TASK_Delete(WeatherTaskSys *task);
void WEATHER_TASK_Update(WeatherTaskSys *task, u16 heapId);
void WEATHER_TASK_Start(WeatherTaskSys *task, const WeatherKindDef *kind, u8 startMode, u32 updatesParticles, u32 variant, u32 useSoundSys, u32 reserved);
void WEATHER_TASK_RequestEnd(WeatherTaskSys *task, u32 updatesParticles, u32 variant);
void WEATHER_TASK_ForceEnd(WeatherTaskSys *task);
int WEATHER_TASK_FadeLight(WeatherTaskSys *task, int arcId, int memberId);
int WEATHER_TASK_SetLight(WeatherTaskSys *task, int arcId, u32 memberId);
void WEATHER_TASK_ResetLight(WeatherTaskSys *task, int phase);
void WEATHER_TASK_FlashLight(WeatherTaskSys *task, u32 color, u32 frames, u32 returnFrames);
int WEATHER_TASK_IsLightFlashing(WeatherTaskSys *task);
int WEATHER_TASK_GetCameraSettingId(WeatherTaskSys *task);
void WEATHER_TASK_SetLightColor(WeatherTaskSys *task, u32 color, u32 frames);
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
extern u8 gWeatherTaskFileName[];
extern WeatherViewScale g_DefaultProjectionMtx;
extern const u8 gWeatherStagePhase[];
extern unsigned char gWeatherBillboardTextureDesc[12];
extern unsigned char d_021EE710b[12];
extern const struct ActorInitParam gWeatherParticlePosition;


/* Constructor: allocates the task and stores the objects it drives. */
WeatherTaskSys *WEATHER_TASK_Create(void *textureBank, FieldCamera *camera, FieldLight *light, FieldFog *fog, FieldZoneFog *zoneFog, WeatherSys *sys, FieldSoundSystem *soundSys, u16 zoneId, u16 heapId)
{
    WeatherTaskSys *task;

    task = GFL_HEAP_Alloc(heapId, sizeof(WeatherTaskSys), 1, (const char *)gWeatherTaskFileName, 0x17E);
    task->textureBank = textureBank;
    task->camera = camera;
    task->fog = fog;
    task->light = light;
    task->zoneFog = zoneFog;
    task->sys = sys;
    task->soundSys = soundSys;
    task->zoneId = zoneId;
    return task;
}


void WEATHER_TASK_Delete(WeatherTaskSys *task)
{
    WEATHER_TASK_ForceEnd(task);
    GFL_HEAP_Free(task);
}


/* Runs the stage state machine of the task once per frame. */
void WEATHER_TASK_Update(WeatherTaskSys *task, u16 heapId)
{
    if (WEATHER_TASK_HasFogChange(task) != 0 && FIELD_FOG_FADE_IsFade(task->fog) == 0) {
        WEATHER_TASK_ApplyFogChange(task);
        WEATHER_TASK_ClearFogChange(task);
    }
    switch (task->stage) {
    case WEATHER_STAGE_IDLE:
        break;
    case WEATHER_STAGE_LOAD_ALL:
        WEATHER_TASK_LoadResources(task, heapId);
        WEATHER_TASK_InitBillboards(task, heapId);
        WEATHER_TASK_AllocParticles(task, heapId);
        WEATHER_TASK_MarkStarted(task);
        task->stage = WEATHER_STAGE_BEGIN;
        break;
    case WEATHER_STAGE_LOAD_RESOURCES:
        WEATHER_TASK_LoadResources(task, heapId);
        task->stage = WEATHER_STAGE_LOAD_BILLBOARDS;
        break;
    case WEATHER_STAGE_LOAD_BILLBOARDS:
        WEATHER_TASK_InitBillboards(task, heapId);
        task->stage = WEATHER_STAGE_LOAD_PARTICLES;
        break;
    case WEATHER_STAGE_LOAD_PARTICLES:
        WEATHER_TASK_AllocParticles(task, heapId);
        task->stage = WEATHER_STAGE_BEGIN;
        break;
    case WEATHER_STAGE_BEGIN:
        if (WEATHER_TASK_CallStageFunc(task, task->kind->begin, heapId) != 0) {
            task->stage = task->updatesParticles != 0 ? WEATHER_STAGE_BEGIN_PARTICLES : WEATHER_STAGE_BEGIN_PLAIN;
        }
        WEATHER_TASK_ResumeSound(&task->sound, task->soundSys);
        WEATHER_TASK_MarkStarted(task);
        break;
    case WEATHER_STAGE_BEGIN_PARTICLES:
        if (WEATHER_TASK_CallStageFunc(task, task->kind->beginParticles, heapId) != 0) {
            task->stage = WEATHER_STAGE_RUN;
        }
        WEATHER_TASK_UpdateParticles(task);
        WEATHER_TASK_ResumeSound(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_BEGIN_PLAIN:
        if (WEATHER_TASK_CallStageFunc(task, task->kind->beginPlain, heapId) != 0) {
            task->stage = WEATHER_STAGE_RUN;
        }
        WEATHER_TASK_ResumeSound(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_RUN:
        WEATHER_TASK_CallStageFunc(task, task->kind->run, heapId);
        WEATHER_TASK_UpdateParticles(task);
        WEATHER_TASK_ResumeSound(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_END_PARTICLES:
        if (WEATHER_TASK_CallStageFunc(task, task->kind->endParticles, heapId) != 0) {
            task->stage = WEATHER_STAGE_END_FADE;
        }
        WEATHER_TASK_UpdateParticles(task);
        WEATHER_TASK_ResumeSound(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_END_FADE:
        if (WEATHER_TASK_CallStageFunc(task, task->kind->endFade, heapId) != 0) {
            task->stage = WEATHER_STAGE_END_FINISH;
        }
        WEATHER_TASK_UpdateParticles(task);
        WEATHER_TASK_ResumeSound(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_END_FINISH:
        if (WEATHER_TASK_IsStarted(task) != 0) {
            WEATHER_TASK_CallStageFunc(task, task->kind->endFinish, heapId);
        }
        task->stage = WEATHER_STAGE_RELEASE;
        break;
    case WEATHER_STAGE_RELEASE:
        WEATHER_TASK_FreeParticles(task);
        WEATHER_TASK_FreeBillboards(task);
        WEATHER_TASK_UnloadResources(task);
        WEATHER_TASK_Reset(task);
        task->stage = WEATHER_STAGE_IDLE;
        break;
    }
}


/* Starts a weather kind: stores the kind and picks the first load stage. */
void WEATHER_TASK_Start(WeatherTaskSys *task, const WeatherKindDef *kind, u8 startMode, u32 updatesParticles, u32 variant, u32 useSoundSys, u32 reserved)
{
    task->kind = kind;
    task->variant = (u8)variant;
    task->updatesParticles = (u8)updatesParticles;
    task->startMode = startMode;
    if (task->startMode == 0) {
        task->stage = WEATHER_STAGE_LOAD_ALL;
    } else if (task->startMode == 1) {
        task->stage = WEATHER_STAGE_LOAD_RESOURCES;
    }
    WEATHER_TASK_SetSoundUseSoundSys(&task->sound, useSoundSys);
}


/* Asks the running kind to end, either with its fade (particles) or at once. */
void WEATHER_TASK_RequestEnd(WeatherTaskSys *task, u32 updatesParticles, u32 variant)
{
    u32 phase;
    u32 stage;

    phase = WEATHER_TASK_GetStagePhase(task);
    stage = task->stage;
    if (stage == 0) {
        return;
    }
    if (phase - 4 <= 1) {
        return;
    }
    task->updatesParticles = (u8)updatesParticles;
    task->variant = (u8)variant;
    if (stage <= WEATHER_STAGE_BEGIN) {
        task->stage = WEATHER_STAGE_END_FINISH;
        return;
    }
    if (task->updatesParticles != 0) {
        task->stage = WEATHER_STAGE_END_PARTICLES;
        return;
    }
    task->stage = WEATHER_STAGE_END_FINISH;
}


/* Ends the kind at once and releases everything it loaded. */
void WEATHER_TASK_ForceEnd(WeatherTaskSys *task)
{
    if (task->stage == 0) {
        return;
    }
    if (task->stage <= WEATHER_STAGE_END_FINISH) {
        WEATHER_TASK_CallStageFunc(task, task->kind->endFinish, 0);
    }
    if (task->stage <= WEATHER_STAGE_RELEASE) {
        WEATHER_TASK_FreeParticles(task);
        WEATHER_TASK_FreeBillboards(task);
        WEATHER_TASK_UnloadResources(task);
    }
    WEATHER_TASK_Reset(task);
}


/* Starts a light change that takes 60 frames. */
int WEATHER_TASK_FadeLight(WeatherTaskSys *task, int arcId, int memberId)
{
    return FIELD_LIGHT_ChangeTable(task->light, arcId, memberId, 60);
}


/* Sets a light in one frame. */
int WEATHER_TASK_SetLight(WeatherTaskSys *task, int arcId, u32 memberId)
{
    return FIELD_LIGHT_ChangeTable(task->light, arcId, memberId, 1);
}


void WEATHER_TASK_ResetLight(WeatherTaskSys *task, int phase)
{
    if (phase == 1)
        FIELD_LIGHT_ReloadZoneTable(task->light);
}


void WEATHER_TASK_FlashLight(WeatherTaskSys *task, u32 color, u32 frames, u32 returnFrames)
{
    FIELD_LIGHT_StartColorFade(task->light, color, frames, returnFrames);
}


int WEATHER_TASK_IsLightFlashing(WeatherTaskSys *task)
{
    return FIELD_LIGHT_IsColorFading(task->light);
}


int WEATHER_TASK_GetCameraSettingId(WeatherTaskSys *task)
{
    return FIELD_CAMERA_GetSettingId(task->camera);
}


void WEATHER_TASK_SetLightColor(WeatherTaskSys *task, u32 color, u32 frames)
{
    FIELD_LIGHT_StartColorFadeHold(task->light, color, frames);
}


void WEATHER_TASK_SetBillboardVisible(WeatherTaskSys *task, unsigned int value, int layer)
{
    FIELD_3DBG_SetBillboardVisible(task->sys->billboards[layer], value);
}


void WEATHER_TASK_SetBillboardScaleX(WeatherTaskSys *task, unsigned int value, int layer)
{
    FIELD_3DBG_SetBillboardScaleX(task->sys->billboards[layer], value);
}


void WEATHER_TASK_SetBillboardScaleY(WeatherTaskSys *task, unsigned int value, int layer)
{
    FIELD_3DBG_SetBillboardScaleY(task->sys->billboards[layer], value);
}


void WEATHER_TASK_SetBillboardTexOffsetX(WeatherTaskSys *task, unsigned int value, int layer)
{
    FIELD_3DBG_SetBillboardTexOffsetX(task->sys->billboards[layer], value);
}


void WEATHER_TASK_SetBillboardTexOffsetY(WeatherTaskSys *task, unsigned int value, int layer)
{
    FIELD_3DBG_SetBillboardTexOffsetY(task->sys->billboards[layer], value);
}


int WEATHER_TASK_GetPhase(WeatherTaskSys *task)
{
    return WEATHER_TASK_GetStagePhase(task);
}


void *WEATHER_TASK_GetWorkBuffer(WeatherTaskSys *task)
{
    return task->workBuffer;
}


int WEATHER_TASK_GetParticleCount(WeatherTaskSys *task)
{
    return task->particleCount;
}


/* Takes a free particle slot and links it into the ring. */
WeatherParticle *WEATHER_TASK_AddParticle(WeatherTaskSys *task, int reserved)
{
    WeatherParticle *particle = WEATHER_TASK_FindFreeParticle(task);

    if (particle != 0)
        WEATHER_TASK_LinkParticle(task, particle);
    return particle;
}


void WEATHER_TASK_RemoveParticle(WeatherParticle *particle)
{
    if (WEATHER_TASK_IsParticleLinked(particle) != 0)
        WEATHER_TASK_UnlinkParticle(particle->owner, particle);
}


void WEATHER_TASK_SetupSpawner(WeatherTaskSys *task, int count, int interval, int targetCount, int targetInterval, int intervalStep, int stepsPerCountChange, int countStep, WeatherSpawnFunc spawn)
{
    WEATHER_TASK_InitSpawner(&task->spawner, task, interval, count, targetCount, targetInterval, intervalStep, stepsPerCountChange, countStep, spawn);
}


void WEATHER_TASK_RetargetSpawner(WeatherTaskSys *task, int targetCount, int targetInterval, int intervalStep, int countStep)
{
    WEATHER_TASK_SetSpawnerTarget(&task->spawner, targetCount, targetInterval, intervalStep, countStep);
}


int WEATHER_TASK_StepSpawner(WeatherTaskSys *task, int arg)
{
    return WEATHER_TASK_TickSpawner(&task->spawner, arg);
}


int WEATHER_TASK_StepSpawnTimer(WeatherTaskSys *task, int arg)
{
    return WEATHER_TASK_TickSpawnTimer(&task->spawner, arg);
}


/* Spawns the particles of a kind and runs them ahead so the screen starts filled. */
void WEATHER_TASK_PrewarmParticles(WeatherTaskSys *task, WeatherSpawnFunc spawn, int iterations, int growEvery, int growBy, u16 heapId)
{
    int j;
    WeatherParticle *cur;
    int steps;
    int i;
    WeatherParticle *next;

    spawn(task, iterations, heapId);
    steps = 0;
    cur = task->particleHead;
    if (cur == 0) {
        return;
    }
    next = cur->next;
    i = 0;
    if (iterations <= 0) {
        return;
    }
    do {
        j = 0;
        if (steps > 0) {
            do {
                task->kind->updateParticle(cur);
                if (WEATHER_TASK_IsParticleLinked(cur) == 0) {
                    break;
                }
                j++;
            } while (j < steps);
        }
        cur = next;
        next = cur->next;
        if (i >= growEvery) {
            if (i % growEvery == 0) {
                steps += growBy;
            }
        }
        if (cur == task->particleHead) {
            break;
        }
        i++;
    } while (i < iterations);
}


void WEATHER_TASK_InitFog(WeatherTaskSys *task, int slope, int offset, int phase)
{
    if (phase == 1) {
        FIELD_FOG_SetBlendMode(task->fog, 0);
        FIELD_FOG_SetColorA(task->fog, 0x1F);
        FIELD_FOG_SetSlope(task->fog, slope);
        FIELD_FOG_SetOffset(task->fog, offset);
        FIELD_FOG_InitFogTable(task->fog);
        FIELD_FOG_SetFlag(task->fog, 1);
    }
}


void WEATHER_TASK_DisableFog(WeatherTaskSys *task, int phase)
{
    if (phase == 1)
        FIELD_FOG_SetFlag(task->fog, 0);
}


/* Changes the fog. Mode 2 first fades the fog out and queues the change for the end of that fade. */
void WEATHER_TASK_ChangeFog(WeatherTaskSys *task, u8 slope, int offset, int frames, int mode)
{
    int half;

    if (mode == 1) {
        FIELD_FOG_FADE_Init(task->fog, offset, slope, frames);
        return;
    }
    if (mode == 2) {
        if (slope == FIELD_FOG_GetSlope(task->fog)) {
            FIELD_FOG_FADE_Init(task->fog, offset, slope, frames);
            return;
        }
        half = frames / 2;
        FIELD_FOG_FADE_Init(task->fog, 0x7FDF, FIELD_FOG_GetSlope(task->fog), half);
        WEATHER_TASK_QueueFogChange(task, slope, offset, half);
    }
}


void WEATHER_TASK_ChangeFogOffset(WeatherTaskSys *task, int endOffset, int frames, int mode)
{
    if (mode == 1)
        FIELD_FOG_FADE_Init(task->fog, endOffset, FIELD_FOG_GetSlope(task->fog), frames);
}


/* 1 when the fog is not changing and no change is queued. */
int WEATHER_TASK_IsFogIdle(WeatherTaskSys *task)
{
    if (FIELD_FOG_FADE_IsFade(task->fog) != 0) {
        return 0;
    }
    if (WEATHER_TASK_HasFogChange(task) == 0) {
        return 1;
    }
    return 0;
}


int WEATHER_TASK_IsZoneFogActive(WeatherTaskSys *task)
{
    if (FIELD_ZONEFOG_IsLoadRequest(task->zoneFog) == 1) {
        return 1;
    }
    return 0;
}


int WEATHER_TASK_IsZoneFog(WeatherTaskSys *task)
{
    return FIELD_ZONEFOG_IsFog(task->zoneFog);
}


int WEATHER_TASK_IsZoneFogLight(WeatherTaskSys *task)
{
    return FIELD_ZONEFOG_IsLight(task->zoneFog);
}


int WEATHER_TASK_GetZoneFogOffset(WeatherTaskSys *task)
{
    return FIELD_ZONEFOG_GetFogOffset(task->zoneFog);
}


int WEATHER_TASK_GetZoneFogSlope(WeatherTaskSys *task)
{
    return FIELD_ZONEFOG_GetFogSlope(task->zoneFog);
}


int WEATHER_TASK_GetZoneFogLightId(WeatherTaskSys *task)
{
    return FIELD_ZONEFOG_GetLightId(task->zoneFog);
}


/* Remembers the camera position for the scroll computation. */
void WEATHER_TASK_SaveCameraPos(WeatherTaskSys *task)
{
    VecFx32 pos;

    if (task->camera != 0) {
        G3D_CAMERA_GetCamTarget(FIELD_CAMERA_GetG3dCamera(task->camera), &pos);
        task->lastCameraPos = pos;
    }
}


/*
 * Turns the camera movement since the last call into a scroll in whole
 * pixels. A jump beyond the limits is treated as a warp: no scroll.
 * FX_Div is FX_Div, VEC_Distance VEC_Distance.
 */
void WEATHER_TASK_GetCameraScroll(WeatherTaskSys *task, s32 *outX, s32 *outY)
{
    VecFx32 pos;
    VecFx32 target;
    fx32 width;
    fx32 height;
    fx32 dx;
    fx32 dz;
    fx32 signX;
    fx32 signZ;
    void *camera;

    if (task->camera == 0) {
        *outX = 0;
        *outY = 0;
        return;
    }
    camera = FIELD_CAMERA_GetG3dCamera(task->camera);
    G3D_CAMERA_GetCamTarget(camera, &pos);
    G3D_CAMERA_GetEye(camera, &target);
    dx = pos.x - task->lastCameraPos.x;
    dz = pos.z - task->lastCameraPos.z;
    if ((dx < 0 ? -dx : dx) > 0x3E8000 || (dz < 0 ? -dz : dz) > 0x64000) {
        task->lastCameraPos = pos;
        *outX = 0;
        *outY = 0;
        return;
    }
    WEATHER_TASK_GetViewScale(&g_DefaultProjectionMtx, VEC_Distance(&pos, &target), &width, &height);
    width = FX_Div(width, 0x100000);
    height = FX_Div(height, 0xC0000);
    signX = 0x1000;
    if (dx < 0) {
        signX = -0x1000;
        dx = -dx;
    }
    dx = FX_Div(dx, width);
    if (signX < 0) {
        dx = 0 - dx;
        dx += 0x1000;
    }
    signZ = 0x1000;
    if (dz < 0) {
        signZ = -0x1000;
        dz = -dz;
    }
    dz = FX_Div(dz, height);
    if (signZ < 0) {
        dz = 0 - dz;
        dz += 0x1000;
    }
    if (dx + dz != 0) {
        task->lastCameraPos = pos;
    }
    *outX = dx >> 12;
    *outY = dz >> 12;
}


/* Moves every particle by (-dx, -dy) on screen. */
void WEATHER_TASK_ShiftParticles(WeatherTaskSys *task, int dx, int dy)
{
    WeatherParticle *particle = task->particleHead;
    Actor *actor;
    int y;
    int x;
    WeatherScreenPos pos;

    if (particle != 0) {
        x = (short)dx;
        y = (short)dy;
        do {
            actor = WEATHER_TASK_GetParticleActorPtr(particle);
            CLACT_GetActorPos(actor, (struct Pt16 *)(&pos));
            pos.x = pos.x - x;
            pos.y = pos.y - y;
            CLACT_SetActorPos(actor, (struct Pt16 *)(&pos));
            particle = particle->next;
        } while (particle != task->particleHead);
    }
}


void WEATHER_TASK_PlaySe(WeatherTaskSys *task, u16 seId)
{
    WEATHER_TASK_PlaySound(&task->sound, task->soundSys, seId);
}


void WEATHER_TASK_StopSe(WeatherTaskSys *task)
{
    WEATHER_TASK_StopSound(&task->sound, task->soundSys);
}


void WEATHER_TASK_PlaySeDirect(WeatherTaskSys *task, int seId)
{
    if (GFL_USE_IsLoaderBusy() == 0) {
        if (task->sound.useSoundSys != 0)
            FIELD_SOUND_SYSTEM_ClaimSlot(task->soundSys, seId);
        else
            GFL_USE_PlaySeDefaultVolume(seId);
    }
}


void WEATHER_TASK_PlaySeWithVoice(WeatherTaskSys *task, int seId, int who)
{
    if (GFL_USE_IsLoaderBusy() == 0) {
        if (task->sound.useSoundSys != 0)
            FIELD_SOUND_SYSTEM_ClaimSlotWithOwner(task->soundSys, seId, who);
        else
            GFL_USE_PlaySeWithVolume(seId, who);
    }
}


u8 *WEATHER_TASK_GetParticleWork(WeatherParticle *particle)
{
    return WEATHER_TASK_GetParticleWorkPtr(particle);
}


Actor *WEATHER_TASK_GetParticleActor(WeatherParticle *particle)
{
    return WEATHER_TASK_GetParticleActorPtr(particle);
}


void WEATHER_TASK_GetParticlePos(WeatherParticle *particle, WeatherScreenPos *out)
{
    CLACT_GetActorSurfacePos(WEATHER_TASK_GetParticleActorPtr(particle), out, 0);
}


/* Sets the particle position, wrapping it into the screen plus a margin. */
void WEATHER_TASK_SetParticlePosWrapped(WeatherParticle *particle, u16 *src)
{
    s16 pos[2];

    pos[0] = src[0];
    pos[1] = src[1];
    if (pos[0] > 320) {
        pos[0] = pos[0] % 320;
    } else if (pos[0] < -64) {
        pos[0] = pos[0] + 320;
    }
    if (pos[1] > 256) {
        s16 *posY;
        posY = &pos[1];
        *posY = *posY % 256;
    } else if (pos[1] < -64) {
        pos[1] = pos[1] + 256;
    }
    CLACT_AddActorSurfacePos(WEATHER_TASK_GetParticleActorPtr(particle), (const struct ClactVec2 *)pos, 0);
}


void WEATHER_TASK_SetParticlePos(WeatherParticle *particle, const WeatherScreenPos *pos)
{
    CLACT_AddActorSurfacePos(WEATHER_TASK_GetParticleActorPtr(particle), pos, 0);
}


/* Clears the task but keeps the objects it was created with. */
void WEATHER_TASK_Reset(WeatherTaskSys *task)
{
    void *textureBank;
    FieldFog *fog;
    FieldZoneFog *zoneFog;
    FieldLight *light;
    WeatherSys *sys;
    FieldCamera *camera;
    FieldSoundSystem *soundSys;
    unsigned short zoneId;

    textureBank = task->textureBank;
    fog = task->fog;
    camera = task->camera;
    zoneFog = task->zoneFog;
    soundSys = task->soundSys;
    light = task->light;
    zoneId = task->zoneId;
    sys = task->sys;
    MI_CpuFill8(task, 0, sizeof(WeatherTaskSys));
    task->camera = camera;
    task->textureBank = textureBank;
    task->soundSys = soundSys;
    task->fog = fog;
    task->zoneId = zoneId;
    task->light = light;
    task->sys = sys;
    task->zoneFog = zoneFog;
}


/* Calls a stage function of the kind; a kind without one is done at once. */
int WEATHER_TASK_CallStageFunc(WeatherTaskSys *task, WeatherKindStageFunc stageFunc, int heapId)
{
    if (stageFunc != 0)
        return stageFunc(task, task->variant, heapId);
    return 1;
}


u8 WEATHER_TASK_GetStagePhase(WeatherTaskSys *task)
{
    return gWeatherStagePhase[task->stage];
}


WeatherParticle *WEATHER_TASK_FindFreeParticle(WeatherTaskSys *task)
{
    int i;

    for (i = 0; i < WEATHER_PARTICLE_MAX; i++) {
        if (WEATHER_TASK_IsParticleLinked(&task->particles[i]) == 0) {
            /* stand-in: the original reuses the task pointer as the base of the particle array; the plain &task->particles[i] changes the register use */
            task = (WeatherTaskSys *)task->particles;
            return (WeatherParticle *)task + i;
        }
    }
    return 0;
}


void WEATHER_TASK_LinkParticle(WeatherTaskSys *task, WeatherParticle *particle)
{
    WeatherParticle *tail;

    task->particleCount++;
    if (task->particleHead == 0) {
        task->particleHead = particle;
        particle->next = particle;
        task->particleHead->prev = particle;
        return;
    }
    tail = task->particleHead->prev;
    particle->prev = tail;
    particle->next = tail->next;
    tail->next->prev = particle;
    tail->next = particle;
    CLACT_SetActorDrawEnable(particle->actor, 1);
}


void WEATHER_TASK_UnlinkParticle(WeatherTaskSys *task, WeatherParticle *particle)
{
    task->particleCount--;
    if (task->particleHead == particle) {
        if (particle->next == particle)
            task->particleHead = 0;
        else
            task->particleHead = particle->next;
    }
    particle->next->prev = particle->prev;
    particle->prev->next = particle->next;
    particle->next = 0;
    particle->prev = 0;
    CLACT_SetActorDrawEnable(particle->actor, 0);
}


void WEATHER_TASK_UpdateParticles(WeatherTaskSys *task)
{
    WeatherParticle *cur = task->particleHead;
    WeatherParticle *next;

    if (cur != 0 && task->kind->updateParticle != 0) {
        next = cur->next;
        do {
            task->kind->updateParticle(cur);
            cur = next;
            next = next->next;
        } while (cur != task->particleHead && task->particleHead != 0);
    }
}


void WEATHER_TASK_LoadResources(WeatherTaskSys *task, u16 heapId)
{
    WEATHER_TASK_LoadArchive(&task->resources, task->kind, heapId);
    WEATHER_TASK_LoadSpriteResources(&task->resources, task->kind, heapId);
}


void WEATHER_TASK_UnloadResources(WeatherTaskSys *task)
{
    WEATHER_TASK_FreeSpriteResources(&task->resources);
    WEATHER_TASK_FreeArchive(&task->resources);
}


void WEATHER_TASK_InitBillboards(WeatherTaskSys *task, u16 heapId)
{
    int i;

    for (i = 0; i < task->kind->billboardCount; i++) {
        WEATHER_TASK_InitBillboard(&task->resources, i, task->sys->billboards[i], &task->kind->billboards[i], heapId);
    }
}


void WEATHER_TASK_FreeBillboards(WeatherTaskSys *task)
{
    int i;

    for (i = 0; i < task->kind->billboardCount; i++)
        WEATHER_TASK_FreeBillboard(&task->resources, i, task->sys->billboards[i]);
}


/* Allocates the work buffer of the kind and one actor per particle slot. */
void WEATHER_TASK_AllocParticles(WeatherTaskSys *task, u16 heapId)
{
    int i;

    task->workBuffer = GFL_HEAP_Alloc(heapId, task->kind->workBufferSize, 1, (const char *)&gWeatherTaskFileName, 0x874);
    if (task->kind->hasSprites != 0) {
        for (i = 0; i < WEATHER_PARTICLE_MAX; i++) {
            WEATHER_TASK_CreateParticleActor(&task->particles[i], task, &task->resources, task->textureBank, heapId);
        }
    }
}


void WEATHER_TASK_FreeParticles(WeatherTaskSys *task)
{
    int i;

    if (task->workBuffer != 0) {
        GFL_HEAP_Free(task->workBuffer);
        task->workBuffer = 0;
    }
    if (task->kind->hasSprites != 0) {
        for (i = 0; i < WEATHER_PARTICLE_MAX; i++) {
            WEATHER_TASK_DestroyParticleActor(&task->particles[i]);
            WEATHER_TASK_ClearParticle(&task->particles[i]);
        }
    }
    WEATHER_TASK_StopSe(task);
}


void WEATHER_TASK_MarkStarted(WeatherTaskSys *task)
{
    task->started = 1;
}


u8 WEATHER_TASK_IsStarted(WeatherTaskSys *task)
{
    return task->started;
}


void WEATHER_TASK_LoadArchive(WeatherResourceSet *resources, const WeatherKindDef *kind, u32 heapId)
{
    if (kind->hasSprites != 0 || kind->billboardCount != 0)
        resources->archive = ARC_TOOL_CreateHandle(kind->archiveId, heapId);
}


void WEATHER_TASK_FreeArchive(WeatherResourceSet *resources)
{
    void *archive = resources->archive;
    if (archive != 0) {
        ARC_TOOL_DeleteHandle(archive);
        resources->archive = 0;
    }
}


void WEATHER_TASK_LoadSpriteResources(WeatherResourceSet *resources, const WeatherKindDef *kind, u16 heapId)
{
    if (kind->hasSprites != 0) {
        resources->charResId = CLACT_RegisterCharacter(resources->archive, kind->charArg, 0, 0, heapId);
        resources->paletteResId = CLACT_RegisterPaletteEx(resources->archive, kind->paletteArg, 0, 0, 0, 1, heapId);
        resources->cellResId = CLACT_RegisterCellAnim(resources->archive, kind->cellArg, kind->cellAnimArg, heapId);
        resources->loaded = 1;
    }
}


void WEATHER_TASK_FreeSpriteResources(WeatherResourceSet *resources)
{
    if (resources->loaded != 0) {
        CLACT_ReleaseCharacter(resources->charResId);
        CLACT_ReleasePalette(resources->paletteResId);
        CLACT_ReleaseCellAnim(resources->cellResId);
        resources->loaded = 0;
    }
}


/*
 * Note: the original loads the pool word for 0x021EE710 twice (once for the
 * memcpy dst and the 3rd argument, once for the byte-8 test); the second
 * name is an alias at the same address that stops the compiler CSEing them.
 */
void WEATHER_TASK_InitBillboard(WeatherResourceSet *resources, int index, Field3dbgBillboard *billboard, const WeatherBillboardInit *init, unsigned short heapId)
{
    MI_CpuCopy8(init, gWeatherBillboardTextureDesc, 12);
    if (d_021EE710b[8] != 0x1f) {
        d_021EE710b[8] = 0x1f;
    }
    FIELD_3DBG_LoadBillboardTexture(billboard, resources->archive, (struct Field3dbgTextureDesc *)gWeatherBillboardTextureDesc, heapId);
    FIELD_3DBG_SetBillboardVisible(billboard, 0);
    FIELD_3DBG_SetBillboardPolygonId(billboard, 0x20);
    resources->billboardReady[index] = 1;
}


void WEATHER_TASK_FreeBillboard(WeatherResourceSet *resources, int index, Field3dbgBillboard *billboard)
{
    if (resources->billboardReady[index] != 0) {
        FIELD_3DBG_FreeBillboardTexture(billboard);
        resources->billboardReady[index] = 0;
    }
}


WeatherSpawner *WEATHER_TASK_InitSpawner(WeatherSpawner *spawner, WeatherTaskSys *owner, u32 interval, u32 count, u32 targetCount, u32 targetInterval, u32 intervalStep, u32 stepsPerCountChange, u32 countStep, WeatherSpawnFunc spawn)
{
    spawner->owner = owner;
    spawner->timer = 0;
    spawner->stepCounter = 0;
    spawner->count = count;
    spawner->targetCount = targetCount;
    spawner->interval = interval;
    spawner->targetInterval = targetInterval;
    spawner->intervalStep = intervalStep;
    spawner->stepsPerCountChange = stepsPerCountChange;
    spawner->countStep = countStep;
    spawner->spawn = spawn;
    return spawner;
}


void WEATHER_TASK_SetSpawnerTarget(WeatherSpawner *spawner, int targetCount, int targetInterval, int intervalStep, int countStep)
{
    spawner->targetCount = targetCount;
    spawner->targetInterval = targetInterval;
    spawner->intervalStep = intervalStep;
    spawner->countStep = countStep;
}


/* One tick of the spawner. Returns 1 when the interval has reached its target. */
s32 WEATHER_TASK_TickSpawner(WeatherSpawner *spawner, u32 arg)
{
    u32 reached;
    s32 negative;

    reached = 0;
    if (spawner->intervalStep == 0) {
        reached |= 1;
    } else {
        negative = spawner->intervalStep > 0 ? 0 : 1;
        if ((spawner->interval >= spawner->targetInterval && negative == 0) || (spawner->interval <= spawner->targetInterval && negative == 1)) {
            reached |= 1;
            spawner->interval = spawner->targetInterval;
        }
    }
    if (spawner->countStep == 0) {
        reached |= 2;
    } else {
        negative = spawner->countStep > 0 ? 0 : 1;
        if ((spawner->count >= spawner->targetCount && negative == 0) || (spawner->count <= spawner->targetCount && negative == 1)) {
            reached |= 2;
            spawner->count = spawner->targetCount;
        }
    }
    spawner->timer--;
    if (spawner->timer <= 0) {
        spawner->spawn(spawner->owner, spawner->count, arg);
        spawner->timer = spawner->interval;
        if (!(reached & 1)) {
            spawner->interval += spawner->intervalStep;
        }
        if (!(reached & 2)) {
            spawner->stepCounter++;
            if (spawner->stepCounter >= spawner->stepsPerCountChange) {
                spawner->stepCounter = 0;
                spawner->count += (s16)spawner->countStep;
            }
        }
    }
    return (reached & 1) ? 1 : 0;
}


/* One tick of the plain timer use of the spawner. Returns 1 when it fired. */
int WEATHER_TASK_TickSpawnTimer(WeatherSpawner *spawner, int arg)
{
    spawner->timer--;
    if (spawner->timer <= 0) {
        spawner->spawn(spawner->owner, spawner->count, arg);
        spawner->timer = spawner->interval;
        return 1;
    }
    return 0;
}


void WEATHER_TASK_ClearParticle(WeatherParticle *particle)
{
    MI_CpuFill8(particle, 0, sizeof(WeatherParticle));
}


/* A particle is in use while it is linked into the ring. */
int WEATHER_TASK_IsParticleLinked(WeatherParticle *particle)
{
    if (particle->prev != 0) {
        return 1;
    }
    return 0;
}


void WEATHER_TASK_CreateParticleActor(WeatherParticle *particle, WeatherTaskSys *owner, const WeatherResourceSet *resources, void *textureBank, u16 heapId)
{
    particle->owner = owner;
    particle->actor = CLACT_CreateActor(textureBank, resources->charResId, resources->paletteResId, resources->cellResId, &gWeatherParticlePosition, 0, heapId);
    CLACT_SetActorDrawEnable(particle->actor, 0);
    CLACT_SetActorVisible(particle->actor, 0);
}


void WEATHER_TASK_DestroyParticleActor(WeatherParticle *particle)
{
    Actor *actor = particle->actor;
    if (actor != 0) {
        CLACT_DeleteActor(actor);
        particle->actor = 0;
    }
}


u8 *WEATHER_TASK_GetParticleWorkPtr(WeatherParticle *particle)
{
    return particle->kindWork;
}


Actor *WEATHER_TASK_GetParticleActorPtr(WeatherParticle *particle)
{
    return particle->actor;
}


void WEATHER_TASK_SetSoundUseSoundSys(WeatherSoundState *sound, u32 useSoundSys)
{
    sound->useSoundSys = useSoundSys;
}


void WEATHER_TASK_PlaySound(WeatherSoundState *sound, FieldSoundSystem *soundSys, u16 seId)
{
    WEATHER_TASK_StopSound(sound, soundSys);
    if (GFL_USE_IsLoaderBusy() == 0) {
        sound->state = 1;
        sound->seId = seId;
        if (sound->useSoundSys != 0)
            FIELD_SOUND_SYSTEM_ClaimSlot(soundSys, sound->seId);
        else
            GFL_USE_PlaySeDefaultVolume(sound->seId);
    } else {
        sound->state = 2;
        sound->seId = seId;
    }
}


void WEATHER_TASK_StopSound(WeatherSoundState *sound, FieldSoundSystem *soundSys)
{
    if (sound->state == 1) {
        sound->state = 0;
        if (sound->useSoundSys != 0)
            FIELD_SOUND_SYSTEM_ReleaseSlot(soundSys, sound->seId);
        else
            GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(sound->seId));
    }
}


/* Starts a sound that was waiting for the sound system to be free. */
void WEATHER_TASK_ResumeSound(WeatherSoundState *sound, FieldSoundSystem *soundSys)
{
    if (sound->state == 2 && GFL_USE_IsLoaderBusy() == 0) {
        sound->state = 1;
        if (sound->useSoundSys != 0)
            FIELD_SOUND_SYSTEM_ClaimSlot(soundSys, sound->seId);
        else
            GFL_USE_PlaySeDefaultVolume(sound->seId);
    }
}


/* Queues a fog change that starts once the current fog change is over. */
void WEATHER_TASK_QueueFogChange(WeatherTaskSys *task, u8 slope, u32 offset, int firstStepFrames)
{
    task->fogChangePending = 1;
    task->fogSlope = slope;
    task->fogOffset = offset;
    task->fogFrames = firstStepFrames / 2;
}


void WEATHER_TASK_ClearFogChange(WeatherTaskSys *task)
{
    task->fogChangePending = 0;
}


u8 WEATHER_TASK_HasFogChange(WeatherTaskSys *task)
{
    return task->fogChangePending;
}


void WEATHER_TASK_ApplyFogChange(WeatherTaskSys *task)
{
    FIELD_FOG_FADE_InitEx(task->fog, 0x7FDF, task->fogOffset, task->fogSlope, task->fogSlope, task->fogFrames);
}


void WEATHER_TASK_GetViewScale(WeatherViewScale *scale, int distance, int *outWidth, int *outHeight)
{
    *outHeight = (int)(((long long)(int)FX_Div(distance, scale->heightRef) * 0x2000 + 0x800) >> 12);
    *outWidth = (int)(((long long)(int)FX_Div(distance, scale->widthRef) * 0x2000 + 0x800) >> 12);
}
