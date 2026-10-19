/*
 * file:     weather_rain_thunderstorm_storm.c
 * unit:     yes
 * function: WEATHER_RAIN_Begin, WEATHER_RAIN_BeginParticles, WEATHER_RAIN_BeginPlain, WEATHER_RAIN_Run, WEATHER_RAIN_EndParticles, WEATHER_RAIN_EndFade, WEATHER_RAIN_EndFinish, WEATHER_RAIN_UpdateParticle, WEATHER_RAIN_SpawnParticles, WEATHER_THUNDERSTORM_Begin, WEATHER_THUNDERSTORM_BeginParticles, WEATHER_THUNDERSTORM_BeginPlain, WEATHER_THUNDERSTORM_Run, WEATHER_THUNDERSTORM_EndParticles, WEATHER_THUNDERSTORM_EndFade, WEATHER_THUNDERSTORM_EndFinish, WEATHER_THUNDERSTORM_UpdateParticle, WEATHER_THUNDERSTORM_SpawnParticles, WEATHER_THUNDERSTORM_ScrollLayers, WEATHER_STORM_Begin, WEATHER_STORM_BeginParticles, WEATHER_STORM_BeginPlain, WEATHER_STORM_Run, WEATHER_STORM_EndParticles, WEATHER_STORM_EndFade, WEATHER_STORM_EndFinish, WEATHER_STORM_UpdateParticle, WEATHER_STORM_SpawnParticles, WEATHER_STORM_UpdateSlowSideDrop, WEATHER_STORM_InitSlowSideDrop, WEATHER_STORM_UpdateFallingStreak, WEATHER_STORM_InitFallingStreak, WEATHER_STORM_UpdateFastSideStreak, WEATHER_STORM_InitFastSideStreak, WEATHER_STORM_StartCalm, WEATHER_STORM_UpdateGust, WEATHER_STORM_ScrollLayers, WEATHER_STORM_PlayGustWarning, WEATHER_STORM_ResetThunderTimer, WEATHER_STORM_UpdateThunder, WEATHER_LIGHTNING_Init, WEATHER_LIGHTNING_Clear, WEATHER_LIGHTNING_Update, WEATHER_LIGHTNING_PickShortFlashes, WEATHER_LIGHTNING_PickSingleFlash, WEATHER_LIGHTNING_PickLongSequence, WEATHER_LIGHTNING_GetFlashColor
 * address:  0x021EE740
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Cleanup (lane WXT): unit_021EFBA4.c and the unplaced leaf 021EFCD4 are merged in. One file for the kinds rain (weather id 2), thunderstorm (6) and storm (7) with the lightning sequencer 021EF9B0..021EFCD4: the const tables run 9, 15, 20, 32, 56, 76 bytes across all of them (lightning tables 15 and 32 bytes enclose the thunderstorm table of 20 bytes), which one object file gives and separate files do not.
 *
 * Boundary audit (wave 16): kept as one file. The const tables of rain, thunderstorm and storm and the lightning sequencer run 9, 15, 20, 32, 56, 76 bytes across all of them (0x021EFCF9.., lightning tables enclose the thunderstorm table), which one object file gives and separate files do not.
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_SetupSpawner 0x021A21F8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_TASK_SaveCameraPos 0x021A2424 thumb ov021
 *   WEATHER_TASK_StepSpawner 0x021A223C thumb ov021
 *   WEATHER_TASK_ChangeFog 0x021A232C thumb ov021
 *   WEATHER_TASK_FadeLight 0x021A2108 thumb ov021
 *   WEATHER_TASK_PlaySe 0x021A25BC thumb ov021
 *   WEATHER_TASK_IsFogIdle 0x021A23B0 thumb ov021
 *   WEATHER_TASK_GetCameraScroll 0x021A244C thumb ov021
 *   WEATHER_TASK_ShiftParticles 0x021A2564 thumb ov021
 *   ZONEDATA_GetLightTableMember 0x02014A10 thumb
 *   WEATHER_TASK_PrewarmParticles 0x021A2254 thumb ov021
 *   WEATHER_TASK_SetLight 0x021A2114 thumb ov021
 *   WEATHER_TASK_StepSpawnTimer 0x021A2248 thumb ov021
 *   WEATHER_TASK_RetargetSpawner 0x021A2228 thumb ov021
 *   WEATHER_TASK_StopSe 0x021A25CC thumb ov021
 *   WEATHER_TASK_ChangeFogOffset 0x021A2390 thumb ov021
 *   WEATHER_TASK_GetParticleCount 0x021A21BC thumb ov021
 *   WEATHER_TASK_DisableFog 0x021A231C thumb ov021
 *   WEATHER_TASK_ResetLight 0x021A2120 thumb ov021
 *   WEATHER_TASK_GetParticleWork 0x021A2630 thumb ov021
 *   WEATHER_TASK_GetParticleActor 0x021A2638 thumb ov021
 *   WEATHER_TASK_GetParticlePos 0x021A2640 thumb ov021
 *   WEATHER_TASK_SetParticlePos 0x021A26C4 thumb ov021
 *   WEATHER_TASK_RemoveParticle 0x021A21E0 thumb ov021
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   WEATHER_TASK_AddParticle  0x021A21C8  thumb  ov021
 *   WEATHER_TASK_SetLightColor  0x021A2154  thumb  ov021
 *   WEATHER_TASK_FlashLight  0x021A2130  thumb  ov021
 *   WEATHER_TASK_PlaySeDirect  0x021A25DC  thumb  ov021
 *   WEATHER_TASK_IsLightFlashing  0x021A213C  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   gWeatherThunderstormSpeedScale     0x021EFD08  data  ov026  a4
 *   WEATHER_TASK_SetBillboardTexOffsetX 0x021A2190 thumb ov021
 *   WEATHER_TASK_SetBillboardTexOffsetY 0x021A21A0 thumb ov021
 *   gWeatherStormDropUpdate 0x021EFDCC data ov026 a4
 *   gWeatherStormDropInit     0x021EFDC0  data  a4
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   WEATHER_TASK_SetBillboardScaleX  0x021A2170  thumb  ov021
 *   WEATHER_TASK_SetBillboardScaleY  0x021A2180  thumb  ov021
 *   gWeatherStormGustWindX     0x021EFD74  data  ov026  a4
 *   gWeatherStormGustWindY     0x021EFD78  data  ov026  a4
 *   gWeatherStormGustLayerScale     0x021EFD3C  data  ov026  a4
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   WEATHER_TASK_PlaySeWithVoice  0x021A2604  thumb  ov021
 *   MI_CpuFill8 0x02082BCC arm
 *   gWeatherLightningPatternChance     0x021EFCF9  data  a1
 *   gWeatherLightningReturnFrames     0x021EFD1C  data  a1
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "weather_rain_thunderstorm_storm_types.h"

/* Steps of the thunderstorm begin stage (WeatherThunderstormWork.step). */
enum {
    THUNDERSTORM_BEGIN_LOAD_LIGHT = 0,
    THUNDERSTORM_BEGIN_DELAY = 1,
    THUNDERSTORM_BEGIN_SKY_PREFLASH = 2,
    THUNDERSTORM_BEGIN_FIRST_FLASH = 3,
    THUNDERSTORM_BEGIN_FOG = 4,
    THUNDERSTORM_BEGIN_SETTLE = 5
};

/* Steps of the storm begin stage (WeatherStormWork.step). */
enum {
    STORM_BEGIN_LOAD_LIGHT = 0,
    STORM_BEGIN_DELAY = 1,
    STORM_BEGIN_SETTLE = 2
};

/* Drop types of the storm; they index the drop init and update tables. */
enum {
    STORM_DROP_SIDE_SLOW = 0,
    STORM_DROP_FALL = 1,
    STORM_DROP_SIDE_FAST = 2
};

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
extern int gWeatherThunderstormSpeedScale[];
extern WeatherStormGustSample gWeatherStormGustWindX[];
extern WeatherStormGustSample gWeatherStormGustWindY[];
extern int gWeatherStormGustLayerScale[];
extern u8 gWeatherLightningPatternChance[];
extern WeatherStormDropInitFunc gWeatherStormDropInit[];
extern WeatherStormDropUpdateFunc gWeatherStormDropUpdate[];
extern u8 gWeatherLightningReturnFrames[];
/* Rain: begin stage. Sets up the drop spawner, the fog fade-in and the first frame. */
int WEATHER_RAIN_Begin(WeatherTaskSys *task, int variant)
{
    WeatherRainWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 1, 8, 2, 0, -4, 2, 1, WEATHER_RAIN_SpawnParticles);
    WEATHER_TASK_InitFog(task, 8, 0x7FDF, variant);
    work->fogDelay = 1;
    WEATHER_TASK_SaveCameraPos(task);
    return 1;
}

/* Rain: begin-particles stage. Starts the fog change after a delay and ends when the spawner
 * and the fog are done. */
int WEATHER_RAIN_BeginParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherRainWork *work;
    int spawnerSettled;
    s32 scrollX;
    s32 scrollY;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerSettled = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fogDelay > 0) {
        work->fogDelay = work->fogDelay - 1;
        if (work->fogDelay == 0) {
            WEATHER_TASK_ChangeFog(task, 8, 0x7F5F, 0x5A, variant);
            WEATHER_TASK_FadeLight(task, 0x3E, ZONEDATA_GetLightTableMember(2));
            WEATHER_TASK_PlaySe(task, 0x691);
        }
    } else if (WEATHER_TASK_IsFogIdle(task) != 0 && spawnerSettled != 0) {
        return 1;
    }
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Rain: begin-plain stage. Starts with the screen already full of drops. */
int WEATHER_RAIN_BeginPlain(WeatherTaskSys *task, int variant, u16 heapId)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 2, 0, 2, 0, -4, 2, 1, WEATHER_RAIN_SpawnParticles);
    WEATHER_TASK_InitFog(task, 8, 0x7F5F, variant);
    WEATHER_TASK_PrewarmParticles(task, WEATHER_RAIN_SpawnParticles, 0x14, 0xA, 1, heapId);
    WEATHER_TASK_PlaySe(task, 0x691);
    WEATHER_TASK_SetLight(task, 0x3E, ZONEDATA_GetLightTableMember(2));
    return 1;
}

/* Rain: run stage. */
int WEATHER_RAIN_Run(WeatherTaskSys *task, int variant, int heapId)
{
    s32 scrollX;
    s32 scrollY;

    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_StepSpawnTimer(task, heapId);
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Rain: end-particles stage. Lets the spawner die out. */
int WEATHER_RAIN_EndParticles(WeatherTaskSys *task)
{
    WeatherRainWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_RetargetSpawner(task, 0, 8, 4, -1);
    work->fogDelay = 1;
    WEATHER_TASK_StopSe(task);
    return 1;
}

/* Rain: end-fade stage. Fades the fog out and ends when every drop is gone. */
int WEATHER_RAIN_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherRainWork *work;
    int spawnerSettled;
    int fogDone;
    s32 scrollX;
    s32 scrollY;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerSettled = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fogDelay > 0) {
        work->fogDelay = work->fogDelay - 1;
        if (work->fogDelay == 0) {
            WEATHER_TASK_ChangeFogOffset(task, 0x7FDF, 0x32, variant);
        }
    } else {
        if (variant != 0) {
            fogDone = WEATHER_TASK_IsFogIdle(task);
        } else {
            fogDone = 1;
        }
        if (fogDone != 0 && spawnerSettled != 0 && WEATHER_TASK_GetParticleCount(task) == 0) {
            return 1;
        }
    }
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Rain: end-finish stage. */
int WEATHER_RAIN_EndFinish(WeatherTaskSys *task, int variant)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    return 1;
}

/* Rain: particle update. A drop falls, then either vanishes or splashes and vanishes. */
void WEATHER_RAIN_UpdateParticle(WeatherParticle *particle)
{
    WeatherRainDrop *drop;
    int remaining;
    Actor *actor;
    WeatherScreenPos pos;

    drop = (WeatherRainDrop *)WEATHER_TASK_GetParticleWork(particle);
    actor = WEATHER_TASK_GetParticleActor(particle);
    WEATHER_TASK_GetParticlePos(particle, &pos);
    switch (drop->state) {
    case WEATHER_RAIN_DROP_FALLING:
        pos.x = pos.x + (s16)drop->speedX;
        pos.y = pos.y + (s16)drop->speedY;
        drop->age = drop->age + 2;
        if (drop->age > drop->lifetime) {
            if (drop->splashRoll < 7) {
                drop->state = WEATHER_RAIN_DROP_REMOVE;
            } else {
                drop->state = WEATHER_RAIN_DROP_SPLASHING;
                drop->age = 4;
                CLACT_SetActorAnimIndex(actor, 3);
            }
        }
        WEATHER_TASK_SetParticlePos(particle, &pos);
        break;
    case WEATHER_RAIN_DROP_SPLASHING:
        remaining = drop->age;
        drop->age = remaining - 1;
        if (remaining <= 0) {
            drop->state = WEATHER_RAIN_DROP_REMOVE;
        }
        break;
    case WEATHER_RAIN_DROP_REMOVE:
        WEATHER_TASK_RemoveParticle(particle);
        break;
    }
}

/* Rain: spawner callback. Creates `count` drops of three sizes above the screen. */
void WEATHER_RAIN_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId)
{
    int i;
    WeatherParticle *particle;
    WeatherRainDrop *drop;
    Actor *actor;
    u32 rand;
    u32 size;
    int jitter;
    WeatherScreenPos pos;

    WEATHER_TASK_GetWorkBuffer(task);
    for (i = 0; i < count; i++) {
        particle = WEATHER_TASK_AddParticle(task, heapId);
        if (particle == 0) {
            return;
        }
        drop = (WeatherRainDrop *)WEATHER_TASK_GetParticleWork(particle);
        actor = WEATHER_TASK_GetParticleActor(particle);
        rand = GFL_USE_GetRandom(0);
        drop->age = 0;
        size = rand % 3;
        CLACT_SetActorAnimIndex(actor, (u16)size);
        jitter = rand % 20;
        drop->speedY = jitter + (size + 1) * 16;
        if (size == 2) {
            drop->speedY += 16;
        }
        drop->speedX = jitter / 8 + (size + 1) * 8;
        if (size == 2) {
            drop->speedX += 8;
        }
        drop->state = WEATHER_RAIN_DROP_FALLING;
        drop->lifetime = (rand & 1) + 1;
        pos.x = (u8)rand + (size * 15 - 0x48);
        pos.y = -0x60;
        WEATHER_TASK_SetParticlePos(particle, &pos);
        drop->speedX = drop->speedX * 2;
        drop->speedY = drop->speedY * 2;
        drop->splashRoll = GFL_USE_GetRandom(10);
    }
}

/* Thunderstorm: begin stage. */
int WEATHER_THUNDERSTORM_Begin(WeatherTaskSys *task, int variant)
{
    WeatherThunderstormWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_LIGHTNING_Init(&work->lightning, 2);
    WEATHER_TASK_SetupSpawner(task, 1, 0xF, 2, 0, -3, 1, 1, WEATHER_THUNDERSTORM_SpawnParticles);
    WEATHER_TASK_InitFog(task, 9, 0x7FDF, variant);
    work->stepTimer = 0;
    work->step = 0;
    WEATHER_TASK_SaveCameraPos(task);
    return 1;
}

/* Thunderstorm: begin-particles stage. Runs the opening sequence: light archive, sky
 * pre-flash, first lightning flash, fog change, then waits for the spawner and the fog. */
int WEATHER_THUNDERSTORM_BeginParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherThunderstormWork *work;
    int spawnerSettled;
    int fogDone;

    work = WEATHER_TASK_GetWorkBuffer(task);
    switch (work->step) {
    case THUNDERSTORM_BEGIN_LOAD_LIGHT:
        WEATHER_TASK_FadeLight(task, 0x3E, ZONEDATA_GetLightTableMember(6));
        work->step = work->step + 1;
        work->stepTimer = 0x5A;
        break;
    case THUNDERSTORM_BEGIN_DELAY:
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer < 0) {
            work->step = work->step + 1;
        }
        break;
    case THUNDERSTORM_BEGIN_SKY_PREFLASH:
        WEATHER_TASK_SetLightColor(task, 0x28C6, 8);
        work->stepTimer = 0x10;
        work->step = work->step + 1;
        break;
    case THUNDERSTORM_BEGIN_FIRST_FLASH:
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer < 0) {
            WEATHER_TASK_FlashLight(task, 0x23DE, 4, 0x3C);
            WEATHER_TASK_PlaySeDirect(task, 0x692);
            work->step = work->step + 1;
        }
        break;
    case THUNDERSTORM_BEGIN_FOG:
        if (WEATHER_TASK_IsLightFlashing(task) == 0) {
            WEATHER_TASK_ChangeFog(task, 9, 0x7F80, 0x50, variant);
            work->step = work->step + 1;
            work->stepTimer = 0x30;
        }
        break;
    case THUNDERSTORM_BEGIN_SETTLE:
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer == 0) {
            WEATHER_TASK_PlaySe(task, 0x690);
            WEATHER_TASK_SetBillboardVisible(task, 1, 0);
        }
        spawnerSettled = WEATHER_TASK_StepSpawner(task, heapId);
        fogDone = WEATHER_TASK_IsFogIdle(task);
        if (spawnerSettled != 0 && fogDone != 0) {
            return 1;
        }
        break;
    }
    WEATHER_THUNDERSTORM_ScrollLayers(task, work);
    return 0;
}

/* Thunderstorm: begin-plain stage. */
int WEATHER_THUNDERSTORM_BeginPlain(WeatherTaskSys *task, int variant, u16 heapId)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 2, 0, 2, 0, -3, 1, 1, WEATHER_THUNDERSTORM_SpawnParticles);
    WEATHER_TASK_InitFog(task, 9, 0x7F80, variant);
    WEATHER_TASK_PrewarmParticles(task, WEATHER_THUNDERSTORM_SpawnParticles, 0x14, 5, 1, heapId);
    WEATHER_TASK_PlaySe(task, 0x690);
    WEATHER_TASK_SetLight(task, 0x3E, ZONEDATA_GetLightTableMember(6));
    WEATHER_TASK_SetBillboardVisible(task, 1, 0);
    return 1;
}

/* Thunderstorm: run stage. Cycles the drop speed scale and drives the lightning. */
int WEATHER_THUNDERSTORM_Run(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherThunderstormWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    work->intensityTimer = (work->intensityTimer + 1) % 300;
    WEATHER_TASK_StepSpawnTimer(task, heapId);
    WEATHER_LIGHTNING_Update(&work->lightning, task);
    WEATHER_THUNDERSTORM_ScrollLayers(task, work);
    return 0;
}

/* Thunderstorm: end-particles stage. */
int WEATHER_THUNDERSTORM_EndParticles(WeatherTaskSys *task)
{
    WeatherThunderstormWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_RetargetSpawner(task, 0, 15, 3, -1);
    work->stepTimer = 1;
    WEATHER_TASK_StopSe(task);
    WEATHER_TASK_SetBillboardVisible(task, 0, 0);
    return 1;
}

/* Thunderstorm: end-fade stage. */
int WEATHER_THUNDERSTORM_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherThunderstormWork *work;
    int spawnerSettled;
    int fogDone;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerSettled = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->stepTimer > 0) {
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer == 0) {
            WEATHER_TASK_ChangeFogOffset(task, 0x7FDF, 0x32, variant);
        }
    } else {
        if (variant != 0) {
            fogDone = WEATHER_TASK_IsFogIdle(task);
        } else {
            fogDone = 1;
        }
        if (fogDone != 0 && spawnerSettled != 0 && WEATHER_TASK_GetParticleCount(task) == 0) {
            return 1;
        }
    }
    WEATHER_THUNDERSTORM_ScrollLayers(task, work);
    return 0;
}

/* Thunderstorm: end-finish stage. */
int WEATHER_THUNDERSTORM_EndFinish(WeatherTaskSys *task, int variant)
{
    WeatherThunderstormWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    WEATHER_LIGHTNING_Clear(&work->lightning);
    return 1;
}

/* Thunderstorm: particle update. A drop falls until it leaves the screen. */
void WEATHER_THUNDERSTORM_UpdateParticle(WeatherParticle *particle)
{
    WeatherThunderstormDrop *drop;
    WeatherScreenPos pos;

    drop = (WeatherThunderstormDrop *)WEATHER_TASK_GetParticleWork(particle);
    WEATHER_TASK_GetParticleActor(particle);
    WEATHER_TASK_GetParticlePos(particle, &pos);
    switch (drop->state) {
    case 0:
        pos.x = pos.x + (s16)drop->speedX;
        pos.y = pos.y + (s16)drop->speedY;
        if (pos.y >= 0xC0) {
            drop->state = 1;
        }
        WEATHER_TASK_SetParticlePos(particle, &pos);
        break;
    case 1:
        WEATHER_TASK_RemoveParticle(particle);
        break;
    }
}

/* Thunderstorm: spawner callback. Drop speed follows the intensity table. */
void WEATHER_THUNDERSTORM_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId)
{
    int i;
    WeatherThunderstormWork *work;
    WeatherParticle *particle;
    WeatherThunderstormDrop *drop;
    Actor *actor;
    u32 rand;
    u32 size;
    WeatherScreenPos pos;

    work = WEATHER_TASK_GetWorkBuffer(task);
    for (i = 0; i < count; i++) {
        particle = WEATHER_TASK_AddParticle(task, heapId);
        if (particle == 0) {
            return;
        }
        drop = (WeatherThunderstormDrop *)WEATHER_TASK_GetParticleWork(particle);
        actor = WEATHER_TASK_GetParticleActor(particle);
        rand = GFL_USE_GetRandom(0);
        size = rand % 3;
        CLACT_SetActorAnimIndex(actor, (u16)size);
        drop->speedY = drop->speedX = (rand & 15) + (size + 1) * 14;
        drop->speedX = gWeatherThunderstormSpeedScale[work->intensityTimer / 60] * drop->speedX / 10;
        drop->speedY = gWeatherThunderstormSpeedScale[work->intensityTimer / 60] * drop->speedY / 10;
        drop->state = 0;
        pos.x = rand % 0x180 - 0x80;
        pos.y = rand % 0x28 - 0x50;
        WEATHER_TASK_SetParticlePos(particle, &pos);
    }
}

/* Thunderstorm: scrolls the two drop layers with the camera and advances their phase. */
void WEATHER_THUNDERSTORM_ScrollLayers(WeatherTaskSys *task, WeatherThunderstormWork *work)
{
    s32 scrollX;
    s32 scrollY;

    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    work->scrollPhase = (work->scrollPhase + 9) % 256;
    WEATHER_TASK_SetBillboardTexOffsetX(task, -(work->scrollPhase + scrollX), 0);
    WEATHER_TASK_SetBillboardTexOffsetY(task, scrollY - work->scrollPhase, 0);
}

/* Storm: begin stage. */
int WEATHER_STORM_Begin(WeatherTaskSys *task, int variant)
{
    WeatherStormWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 1, 4, 1, 1, -4, 1, 1, WEATHER_STORM_SpawnParticles);
    WEATHER_TASK_InitFog(task, 9, 0x7FDF, variant);
    WEATHER_TASK_SaveCameraPos(task);
    WEATHER_STORM_ResetThunderTimer(work);
    return 1;
}

/* Storm: begin-particles stage. Loads the light archive, then starts the first calm phase
 * and the fog change, and ends when the spawner and the fog are done. */
int WEATHER_STORM_BeginParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherStormWork *work;
    int spawnerSettled;
    int fogDone;

    work = WEATHER_TASK_GetWorkBuffer(task);
    switch (work->step) {
    case STORM_BEGIN_LOAD_LIGHT:
        WEATHER_TASK_FadeLight(task, 0x3E, ZONEDATA_GetLightTableMember(7));
        work->stepTimer = 0x5A;
        work->step = work->step + 1;
        break;
    case STORM_BEGIN_DELAY:
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer <= 0) {
            WEATHER_STORM_StartCalm(task, work, variant, 1);
            work->gustDuration = 0x78;
            work->stepTimer = 8;
            work->step = work->step + 1;
        }
        break;
    case STORM_BEGIN_SETTLE:
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer == 0) {
            WEATHER_TASK_PlaySe(task, 0x690);
            WEATHER_TASK_SetBillboardVisible(task, 1, 0);
            WEATHER_TASK_ChangeFog(task, 9, 0x7F80, 10, variant);
        }
        spawnerSettled = WEATHER_TASK_StepSpawner(task, heapId);
        fogDone = WEATHER_TASK_IsFogIdle(task);
        if (spawnerSettled == 1 && fogDone == 1 && work->stepTimer <= 0) {
            return 1;
        }
        break;
    }
    WEATHER_STORM_UpdateGust(task, work, variant, 0);
    WEATHER_STORM_ScrollLayers(task, work);
    return 0;
}

/* Storm: begin-plain stage. */
int WEATHER_STORM_BeginPlain(WeatherTaskSys *task, int variant, u16 heapId)
{
    WeatherStormWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 1, 1, 1, 1, -4, 1, 1, WEATHER_STORM_SpawnParticles);
    WEATHER_TASK_InitFog(task, 9, 0x7F80, variant);
    WEATHER_TASK_PrewarmParticles(task, WEATHER_STORM_SpawnParticles, 0x14, 5, 1, heapId);
    WEATHER_TASK_PlaySe(task, 0x690);
    WEATHER_STORM_StartCalm(task, work, variant, 0);
    WEATHER_TASK_SetBillboardVisible(task, 1, 0);
    WEATHER_TASK_SetLight(task, 0x3E, ZONEDATA_GetLightTableMember(7));
    return 1;
}

/* Storm: run stage. */
int WEATHER_STORM_Run(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherStormWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_StepSpawnTimer(task, heapId);
    WEATHER_STORM_UpdateGust(task, work, variant, 0);
    WEATHER_STORM_ScrollLayers(task, work);
    return 0;
}

/* Storm: end-particles stage. */
int WEATHER_STORM_EndParticles(WeatherTaskSys *task, int variant)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_RetargetSpawner(task, 0, 4, 4, -1);
    WEATHER_TASK_StopSe(task);
    WEATHER_TASK_ChangeFogOffset(task, 0x7FDF, 0x32, variant);
    WEATHER_TASK_SetBillboardVisible(task, 0, 0);
    WEATHER_TASK_SetBillboardVisible(task, 0, 1);
    return 1;
}

/* Storm: end-fade stage. */
int WEATHER_STORM_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherStormWork *work;
    int spawnerSettled;
    int fogDone;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerSettled = WEATHER_TASK_StepSpawner(task, heapId);
    fogDone = (variant != 0) ? WEATHER_TASK_IsFogIdle(task) : 1;
    if (fogDone != 0 && spawnerSettled != 0 && WEATHER_TASK_GetParticleCount(task) == 0) {
        return 1;
    }
    WEATHER_STORM_UpdateGust(task, work, variant, 1);
    WEATHER_STORM_ScrollLayers(task, work);
    return 0;
}

/* Storm: end-finish stage. */
int WEATHER_STORM_EndFinish(WeatherTaskSys *task, int variant)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    return 1;
}

/* Storm: particle update. Calls the update function of the drop type. */
void WEATHER_STORM_UpdateParticle(WeatherParticle *particle)
{
    WeatherStormParticle *kind;
    Actor *actor;

    kind = (WeatherStormParticle *)WEATHER_TASK_GetParticleWork(particle);
    actor = WEATHER_TASK_GetParticleActor(particle);
    gWeatherStormDropUpdate[kind->dropType](particle, kind->work, &kind->drop, actor);
}

/* Storm: spawner callback. The gust phase decides how many drops appear and of which type. */
void WEATHER_STORM_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId)
{
    u32 rand;
    u32 percent;
    WeatherStormWork *work;
    int i;
    WeatherParticle *particle;
    WeatherStormParticle *kind;
    Actor *actor;

    rand = GFL_USE_GetRandom(0);
    work = WEATHER_TASK_GetWorkBuffer(task);
    if (work->gustPhase == WEATHER_STORM_GUST_NONE) {
        return;
    }
    if (work->gustPhase == WEATHER_STORM_GUST && (rand & 1)) {
        return;
    }
    i = 0;
    if (count <= 0) {
        return;
    }
    percent = rand % 100;
    do {
        particle = WEATHER_TASK_AddParticle(task, heapId);
        if (particle == 0) {
            return;
        }
        kind = (WeatherStormParticle *)WEATHER_TASK_GetParticleWork(particle);
        actor = WEATHER_TASK_GetParticleActor(particle);
        kind->work = work;
        switch (work->gustPhase) {
        case WEATHER_STORM_GUST_NONE:
            break;
        case WEATHER_STORM_CALM:
            kind->dropType = STORM_DROP_FALL;
            break;
        case WEATHER_STORM_GUST:
            if (percent <= 0x32) {
                kind->dropType = STORM_DROP_SIDE_FAST;
            } else {
                kind->dropType = STORM_DROP_SIDE_SLOW;
            }
            break;
        case WEATHER_STORM_GUST_RISE:
        case WEATHER_STORM_GUST_FADE:
            if (percent <= 0x50) {
                kind->dropType = STORM_DROP_FALL;
            } else {
                kind->dropType = STORM_DROP_SIDE_FAST;
            }
            break;
        }
        gWeatherStormDropInit[kind->dropType](particle, kind->work, &kind->drop, actor);
        i++;
    } while (i < count);
}

/* Storm: update of a slow sideways drop. */
void WEATHER_STORM_UpdateSlowSideDrop(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop)
{
    WeatherScreenPos pos;
    int windX;
    int windY;

    windX = work->windX;
    if (windX == 0) {
        windX = drop->lastWindX;
        windY = drop->lastWindY;
    } else {
        windY = work->windY;
        drop->lastWindX = windX;
        drop->lastWindY = windY;
    }
    WEATHER_TASK_GetParticlePos(particle, &pos);
    drop->posX = drop->posX + (s16)(drop->speedX + windX);
    drop->posY = drop->posY + (s16)(drop->speedY + windY);
    pos.x = drop->posX / 8;
    pos.y = drop->posY / 8;
    if (pos.x >= 256 || pos.y >= 192) {
        WEATHER_TASK_RemoveParticle(particle);
        return;
    }
    WEATHER_TASK_SetParticlePos(particle, &pos);
}

/* Storm: init of a slow sideways drop. */
void WEATHER_STORM_InitSlowSideDrop(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor)
{
    u32 rand;
    WeatherScreenPos pos;
    int autoAnimSpeed;
    int windX;

    rand = GFL_USE_GetRandom(0);
    drop->speedX = rand % 24 + 0x10;
    windX = work->windX;
    drop->speedY = rand % 24 + 8;
    drop->lastWindX = windX;
    drop->lastWindY = work->windY;
    pos.x = (rand & 7) - 8;
    pos.y = rand % 160 - 16;
    WEATHER_TASK_SetParticlePos(particle, &pos);
    drop->posX = pos.x << 3;
    drop->posY = pos.y << 3;
    CLACT_SetActorAnimSeq(actor, 0);
    autoAnimSpeed = 1;
    CLACT_SetActorAutoAnim(actor, 1);
    CLACT_SetActorAutoAnimSpeed(actor, autoAnimSpeed << 13);
}

/* Storm: update of a falling streak. */
void WEATHER_STORM_UpdateFallingStreak(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop)
{
    WeatherScreenPos pos;

    WEATHER_TASK_GetParticlePos(particle, &pos);
    drop->posX = drop->posX + (s16)(drop->speedX + work->windX);
    drop->posY = drop->posY + (s16)(drop->speedY + work->windY);
    pos.x = drop->posX / 8;
    pos.y = drop->posY / 8;
    if (pos.x >= 256 || pos.y >= 160) {
        WEATHER_TASK_RemoveParticle(particle);
        return;
    }
    WEATHER_TASK_SetParticlePos(particle, &pos);
}

/* Storm: init of a falling streak. */
void WEATHER_STORM_InitFallingStreak(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor)
{
    u32 rand;
    WeatherScreenPos pos;
    int autoAnimSpeed;

    rand = GFL_USE_GetRandom(0);
    drop->speedX = rand % 43 + 0x56;
    drop->speedY = (rand % 43) * 2 + 0x102;
    pos.x = rand % 336 - 0x50;
    pos.y = rand % 40 - 0x50;
    WEATHER_TASK_SetParticlePos(particle, &pos);
    drop->posX = pos.x << 3;
    drop->posY = pos.y << 3;
    CLACT_SetActorAnimSeq(actor, 1);
    autoAnimSpeed = 1;
    CLACT_SetActorAutoAnim(actor, 1);
    CLACT_SetActorAutoAnimSpeed(actor, autoAnimSpeed << 13);
}

/*
 * note: 2026-10-05 (wD8 lane04): closed. work is a const pointer (the struct is for readability; a
 *   const char * with casts gives the same bytes, a non-const one does not): the drop->posY store then does
 *   not kill the CSE of drop->speedY + work->windY, so lastWindY reuses the kept sum. Both sums are written inline
 *   (drop->posX + (s16)(drop->speedX + windX)) and repeated for lastWindX/lastWindY.
 *   EXACT* = 186 bytes compiled vs a 188-byte listing extent (2 bytes of padding).
 */
/* Storm: update of a fast sideways streak. */
void WEATHER_STORM_UpdateFastSideStreak(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop)
{
    WeatherScreenPos pos;
    s16 windX;

    WEATHER_TASK_GetParticlePos(particle, &pos);
    windX = work->windX;
    if (windX != 0) {
        drop->posX = drop->posX + (s16)(drop->speedX + windX);
        drop->posY = drop->posY + (s16)(drop->speedY + work->windY);
        pos.x = drop->posX / 8;
        pos.y = drop->posY / 8;
        drop->lastWindX = drop->speedX + windX;
        drop->lastWindY = drop->speedY + work->windY;
    } else {
        drop->posX = drop->posX + drop->lastWindX;
        drop->posY = drop->posY + drop->lastWindY;
        pos.x = drop->posX / 8;
        pos.y = drop->posY / 8;
    }
    if (pos.x >= 0x100 || pos.y >= 0xc0) {
        WEATHER_TASK_RemoveParticle(particle);
    } else {
        WEATHER_TASK_SetParticlePos(particle, &pos);
    }
}

/* Storm: init of a fast sideways streak. */
void WEATHER_STORM_InitFastSideStreak(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor)
{
    u32 rand;
    WeatherScreenPos pos;
    int autoAnimSpeed;

    rand = GFL_USE_GetRandom(0);
    drop->speedX = rand % 24 + 0x50;
    drop->speedY = rand % 24 + 0xE;
    drop->lastWindX = drop->speedX + work->windX;
    drop->lastWindY = drop->speedY + work->windY;
    pos.x = (rand & 7) - 8;
    pos.y = rand % 160 - 16;
    WEATHER_TASK_SetParticlePos(particle, &pos);
    drop->posX = pos.x << 3;
    drop->posY = pos.y << 3;
    CLACT_SetActorAnimSeq(actor, 2);
    autoAnimSpeed = 1;
    CLACT_SetActorAutoAnim(actor, 1);
    CLACT_SetActorAutoAnimSpeed(actor, autoAnimSpeed << 13);
}

/* Storm: starts a calm phase of random length. With silent set the caller does the fog,
 * light and sound changes itself. */
void WEATHER_STORM_StartCalm(WeatherTaskSys *task, WeatherStormWork *work, int variant, int silent)
{
    u32 rand = GFL_USE_GetRandom(0);

    work->gustPhase = WEATHER_STORM_CALM;
    work->gustDuration = rand % 400 + 0x3C;
    work->gustTimer = 0;
    if (silent == 0) {
        WEATHER_TASK_ChangeFog(task, 9, 0x7F80, 10, variant);
        WEATHER_TASK_SetBillboardVisible(task, 0, 1);
        WEATHER_TASK_PlaySe(task, 0x690);
    }
}

/* Storm: advances the gust cycle calm, rise, gust, fade, calm and sets the wind and the
 * layer scale of the current phase. */
void WEATHER_STORM_UpdateGust(WeatherTaskSys *task, WeatherStormWork *work, int variant, int silent)
{
    u32 rand;
    int i;

    switch (work->gustPhase) {
    case WEATHER_STORM_GUST_NONE:
        break;
    case WEATHER_STORM_CALM:
        work->gustTimer = work->gustTimer + 1;
        WEATHER_STORM_PlayGustWarning(task, work, variant, 0x71F);
        if (work->gustTimer >= work->gustDuration) {
            work->gustPhase = WEATHER_STORM_GUST_RISE;
            work->gustDuration = 0x10;
            work->gustTimer = 0;
            if (silent == 0) {
                WEATHER_TASK_ChangeFog(task, 9, 0x7F70, 10, variant);
                WEATHER_TASK_PlaySe(task, 0x720);
            }
        }
        break;
    case WEATHER_STORM_GUST:
        work->gustTimer = work->gustTimer + 1;
        WEATHER_STORM_PlayGustWarning(task, work, variant, 0x71F);
        WEATHER_STORM_UpdateThunder(task, work, variant);
        if (work->gustTimer >= work->gustDuration) {
            work->gustPhase = WEATHER_STORM_GUST_FADE;
            work->gustDuration = 0x10;
            work->gustTimer = 0;
            if (silent == 0) {
                WEATHER_TASK_SetBillboardVisible(task, 0, 1);
                WEATHER_TASK_SetBillboardScaleX(task, 0x1000, 0);
                WEATHER_TASK_SetBillboardScaleY(task, 0x1000, 0);
            }
        }
        break;
    case WEATHER_STORM_GUST_RISE:
        work->gustTimer = work->gustTimer + 1;
        if (work->gustTimer >= work->gustDuration) {
            rand = GFL_USE_GetRandom(0);
            work->gustPhase = WEATHER_STORM_GUST;
            work->gustDuration = rand % 400 + 0x3C;
            work->gustTimer = 0;
            if (silent == 0) {
                WEATHER_TASK_SetBillboardVisible(task, 1, 1);
                WEATHER_TASK_SetBillboardScaleX(task, 0x800, 0);
                WEATHER_TASK_SetBillboardScaleY(task, 0x1800, 0);
            }
        }
        break;
    case WEATHER_STORM_GUST_FADE:
        work->gustTimer = work->gustTimer + 1;
        if (work->gustTimer >= work->gustDuration) {
            WEATHER_STORM_StartCalm(task, work, variant, silent);
        }
        break;
    }
    switch (work->gustPhase) {
    case WEATHER_STORM_GUST_NONE:
        break;
    case WEATHER_STORM_CALM:
        if (work->gustDuration - work->gustTimer >= 9) {
            work->windX = 0;
            work->windY = 0;
        } else {
            work->windX = 0xA0;
            work->windY = 0x10;
        }
        break;
    case WEATHER_STORM_GUST:
        i = work->gustTimer % 0x48 * 6 / 0x48;
        work->windX = gWeatherStormGustWindX[i].value;
        work->windY = gWeatherStormGustWindY[i].value;
        work->layerScale = gWeatherStormGustLayerScale[(work->gustTimer % 0xE0u) * 14 / 0xE0u];
        break;
    case WEATHER_STORM_GUST_RISE:
    case WEATHER_STORM_GUST_FADE:
        work->windX = 0xA0;
        work->windY = 0x10;
        work->layerScale = 0x800;
        break;
    }
}

/* Storm: scrolls the two drop layers with the camera and applies the layer scale. */
void WEATHER_STORM_ScrollLayers(WeatherTaskSys *task, WeatherStormWork *work)
{
    s32 scrollX;
    s32 scrollY;

    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    if (work->windX != 0) {
        work->scrollX0 = (work->scrollX0 + 9) % 256;
        work->scrollY0 = (work->scrollY0 + 3) % 256;
        work->scrollX1 = (work->scrollX1 + 9) % 256;
        work->scrollY1 = (work->scrollY1 + 2) % 256;
    } else {
        work->scrollX0 = (work->scrollX0 + 3) % 256;
        work->scrollY0 = (work->scrollY0 + 8) % 256;
    }
    WEATHER_TASK_SetBillboardTexOffsetX(task, -(work->scrollX0 + scrollX), 0);
    WEATHER_TASK_SetBillboardTexOffsetY(task, scrollY - work->scrollY0, 0);
    WEATHER_TASK_SetBillboardTexOffsetX(task, -(work->scrollX1 + scrollX), 1);
    WEATHER_TASK_SetBillboardTexOffsetY(task, scrollY - work->scrollY1, 1);
    WEATHER_TASK_SetBillboardScaleX(task, work->layerScale, 1);
    WEATHER_TASK_SetBillboardScaleY(task, work->layerScale, 1);
}

/* Storm: plays the warning sound 24 frames before the calm phase ends. */
void WEATHER_STORM_PlayGustWarning(WeatherTaskSys *task, WeatherStormWork *work, int variant, int seId)
{
    if (variant != 0 && work->gustTimer == work->gustDuration - 24)
        WEATHER_TASK_PlaySeDirect(task, seId);
}

/* Storm: restarts the thunder timer with a random interval. */
void WEATHER_STORM_ResetThunderTimer(WeatherStormWork *work)
{
    work->thunderTimer = 0;
    work->thunderInterval = GFL_USE_GetRandom(16) + 50;
}

/* Storm: plays thunder at random intervals during a gust, unless the warning sound is still playing. */
void WEATHER_STORM_UpdateThunder(WeatherTaskSys *task, WeatherStormWork *work, int variant)
{
    if (variant == 0) {
        return;
    }
    if (work->gustTimer > work->gustDuration - 0x4A) {
        return;
    }
    work->thunderTimer++;
    if (work->thunderTimer < work->thunderInterval) {
        return;
    }
    if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x71F)) == 0) {
        int pan = GFL_USE_GetRandom(0x1B) + 0x64;
        WEATHER_TASK_PlaySeWithVoice(task, 0x71E, pan);
        WEATHER_STORM_ResetThunderTimer(work);
        return;
    }
    work->thunderTimer = work->thunderInterval - 10;
}

/* Lightning: clears the sequencer and picks the first wait. */
void WEATHER_LIGHTNING_Init(WeatherLightning *lightning, int mode)
{
    MI_CpuFill8(lightning, 0, 64);
    lightning->timer = GFL_USE_GetRandom(3);
    lightning->mode = mode;
}

/* Lightning: clears the sequencer. */
void WEATHER_LIGHTNING_Clear(WeatherLightning *lightning)
{
    MI_CpuFill8(lightning, 0, 0x40);
}

/*
 * State 6 re-reads flashIndex into a local after the flash's decrement
 * (`flashes[flashIndex].holdFrames--; i = flashIndex; if (flashes[i].holdFrames <= 0) { if (flashCount >
 * i + 1)`): spelled with `flashIndex` throughout, every form tried (either
 * compare order, `flashIndex++`, a temporary for flashIndex + 1) colours flashCount and
 * flashIndex + 1 into r0/r1 swapped, 7 bytes out.
 * State 4 indexes the flash directly (`flashes[i].soundDelay`); a `WeatherLightningFlash *`
 * cursor gives 100+ bytes out.
 */
/* Lightning: runs one frame of the sequencer. Picks a flash pattern, flashes the screen
 * light flash by flash and starts the thunder after its delay. */
void WEATHER_LIGHTNING_Update(WeatherLightning *lightning, WeatherTaskSys *task)
{
    u32 rand;
    int i;

    switch (lightning->state) {
    case WEATHER_LIGHTNING_WAIT:
        if (--lightning->timer < 0) {
            lightning->state = WEATHER_LIGHTNING_PICK_SEQUENCE;
        }
        break;
    case WEATHER_LIGHTNING_PICK_SEQUENCE:
        rand = GFL_USE_GetRandom(100);
        for (i = 0; i < 3; i++) {
            if (gWeatherLightningPatternChance[i] >= rand) {
                break;
            }
        }
        if (lightning->mode == 0) {
            WEATHER_LIGHTNING_PickShortFlashes(lightning);
        } else {
            switch (i) {
            case 0:
                if (lightning->mode == 1) {
                    WEATHER_LIGHTNING_PickShortFlashes(lightning);
                } else {
                    WEATHER_LIGHTNING_PickSingleFlash(lightning);
                }
                break;
            case 1:
                WEATHER_LIGHTNING_PickSingleFlash(lightning);
                break;
            case 2:
                WEATHER_LIGHTNING_PickLongSequence(lightning);
                break;
            }
        }
        lightning->flashIndex = 0;
        lightning->state = WEATHER_LIGHTNING_SKY_FLASH;
        break;
    case WEATHER_LIGHTNING_SKY_FLASH:
        if (lightning->mode != 2) {
            lightning->state = WEATHER_LIGHTNING_START_FLASH;
            break;
        }
        WEATHER_TASK_SetLightColor(task, 0x3129, 4);
        lightning->timer = 10;
        lightning->state = WEATHER_LIGHTNING_SKY_FLASH_WAIT;
        break;
    case WEATHER_LIGHTNING_SKY_FLASH_WAIT:
        if (--lightning->timer <= 0) {
            lightning->state = WEATHER_LIGHTNING_START_FLASH;
        }
        break;
    case WEATHER_LIGHTNING_START_FLASH:
        if (lightning->mode != 0) {
            WEATHER_TASK_FlashLight(task, WEATHER_LIGHTNING_GetFlashColor(lightning), lightning->flashes[lightning->flashIndex].fadeInFrames, lightning->flashes[lightning->flashIndex].returnFrames);
        }
        if (lightning->pattern == 2) {
            lightning->timer = lightning->flashes[lightning->flashIndex].fadeInFrames / 2 + GFL_USE_GetRandom(lightning->flashes[lightning->flashIndex].returnFrames);
        }
        i = lightning->flashIndex;
        lightning->pendingSoundDelay = lightning->flashes[i].soundDelay;
        lightning->pendingSoundId = lightning->flashes[i].soundId;
        if (lightning->mode == 2) {
            if (i + 1 == lightning->flashCount) {
                lightning->flashes[i].holdFrames = lightning->flashes[i].holdFrames / 3;
            }
        } else if (lightning->mode == 0) {
            lightning->flashes[i].holdFrames = lightning->flashes[i].holdFrames * 2;
        }
        lightning->state = WEATHER_LIGHTNING_FLASH_FADE;
        break;
    case WEATHER_LIGHTNING_FLASH_FADE:
        if (lightning->pendingSoundDelay > 0) {
            lightning->pendingSoundDelay--;
            if (lightning->pendingSoundDelay == 0) {
                WEATHER_TASK_PlaySeDirect(task, lightning->pendingSoundId);
            }
        }
        if (WEATHER_TASK_IsLightFlashing(task) == 0) {
            lightning->state = WEATHER_LIGHTNING_FLASH_HOLD;
        }
        break;
    case WEATHER_LIGHTNING_FLASH_HOLD:
        if (lightning->pendingSoundDelay > 0) {
            lightning->pendingSoundDelay--;
            if (lightning->pendingSoundDelay == 0) {
                WEATHER_TASK_PlaySeDirect(task, lightning->pendingSoundId);
            }
        }
        lightning->flashes[lightning->flashIndex].holdFrames--;
        i = lightning->flashIndex;
        if (lightning->flashes[i].holdFrames <= 0) {
            if (lightning->flashCount > i + 1) {
                lightning->flashIndex = i + 1;
                lightning->state = WEATHER_LIGHTNING_START_FLASH;
            } else {
                lightning->state = WEATHER_LIGHTNING_PICK_SEQUENCE;
            }
        }
        break;
    }
}

/* Lightning: picks one or two short flashes with a long wait between them. */
void WEATHER_LIGHTNING_PickShortFlashes(WeatherLightning *lightning)
{
    int i;

    i = 0;
    lightning->pattern = 0;
    lightning->flashCount = GFL_USE_GetRandom(2) + 1;
    for (; i < lightning->flashCount; i++) {
        lightning->flashes[i].brightness = GFL_USE_GetRandom(3) + 0x12;
        lightning->flashes[i].fadeInFrames = 4;
        lightning->flashes[i].returnFrames = gWeatherLightningReturnFrames[lightning->flashes[i].brightness];
        lightning->flashes[i].holdFrames = GFL_USE_GetRandom(0xF0) + 0x78;
        lightning->flashes[i].soundDelay = 0x1C;
        lightning->flashes[i].soundId = 0x693;
    }
}

/* Lightning: picks a single flash. */
void WEATHER_LIGHTNING_PickSingleFlash(WeatherLightning *lightning)
{
    lightning->pattern = 1;
    lightning->flashCount = 1;
    lightning->flashes[0].brightness = GFL_USE_GetRandom(3) + 0x18;
    lightning->flashes[0].fadeInFrames = 4;
    lightning->flashes[0].returnFrames = gWeatherLightningReturnFrames[lightning->flashes[0].brightness];
    lightning->flashes[0].holdFrames = GFL_USE_GetRandom(0x12C) + 0xF0;
    lightning->flashes[0].soundDelay = 0xD;
    lightning->flashes[0].soundId = 0x692;
}

/*
 * The handed 644-byte extent is 152 bytes of code; the unlabelled leaf
 * WEATHER_LIGHTNING_GetFlashColor and ov026 data follow. The tail flash must be spelled
 * flashes[i].field (a cursor pointer, as the plain loop of the twin
 * WEATHER_LIGHTNING_PickShortFlashes might suggest, gives 62 bytes out: the image indexes +0xC from a
 * separate base and re-adds lightning + i*12 per store).
 */
/* Lightning: picks a long sequence of short flashes and a last bright one. */
void WEATHER_LIGHTNING_PickLongSequence(WeatherLightning *lightning)
{
    int i;

    lightning->pattern = 2;
    lightning->flashCount = GFL_USE_GetRandom(2) + 1;
    i = 0;
    lightning->flashCount = lightning->flashCount + 1;
    for (; i < lightning->flashCount - 1; i++) {
        lightning->flashes[i].brightness = GFL_USE_GetRandom(3) + 0x12;
        lightning->flashes[i].fadeInFrames = 4;
        lightning->flashes[i].returnFrames = 8;
        lightning->flashes[i].holdFrames = GFL_USE_GetRandom(4);
        lightning->flashes[i].soundDelay = 10;
        lightning->flashes[i].soundId = 0x693;
    }
    lightning->flashes[i].brightness = GFL_USE_GetRandom(1) + 0x1E;
    lightning->flashes[i].fadeInFrames = 4;
    lightning->flashes[i].returnFrames = gWeatherLightningReturnFrames[lightning->flashes[i].brightness];
    lightning->flashes[i].holdFrames = GFL_USE_GetRandom(300) + 0xF0;
    lightning->flashes[i].soundDelay = 10;
    lightning->flashes[i].soundId = 0x692;
}

/* Lightning: the flash colour of the current flash (grey ramp with a blue bias). */
unsigned short WEATHER_LIGHTNING_GetFlashColor(WeatherLightning *lightning)
{
    unsigned short brightness;

    brightness = lightning->flashes[lightning->flashIndex].brightness;
    return brightness | (brightness << 5) | 0x2000;
}
