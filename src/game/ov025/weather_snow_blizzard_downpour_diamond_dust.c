/*
 * file:     weather_snow_blizzard_downpour_diamond_dust.c
 * unit:     yes
 * function: WEATHER_SNOW_Begin, WEATHER_SNOW_BeginParticles, WEATHER_SNOW_BeginPlain, WEATHER_SNOW_Run, WEATHER_SNOW_EndParticles, WEATHER_SNOW_EndFade, WEATHER_SNOW_EndFinish, WEATHER_SNOW_UpdateParticle, WEATHER_SNOW_SpawnParticles, WEATHER_BLIZZARD_Begin, WEATHER_BLIZZARD_BeginParticles, WEATHER_BLIZZARD_BeginPlain, WEATHER_BLIZZARD_Run, WEATHER_BLIZZARD_EndParticles, WEATHER_BLIZZARD_EndFade, WEATHER_BLIZZARD_EndFinish, WEATHER_BLIZZARD_UpdateParticle, WEATHER_BLIZZARD_SpawnParticles, WEATHER_BLIZZARD_ScrollFogLayer, WEATHER_DOWNPOUR_Begin, WEATHER_DOWNPOUR_BeginParticles, WEATHER_DOWNPOUR_BeginPlain, WEATHER_DOWNPOUR_Run, WEATHER_DOWNPOUR_EndParticles, WEATHER_DOWNPOUR_EndFade, WEATHER_DOWNPOUR_EndFinish, WEATHER_DOWNPOUR_UpdateParticle, WEATHER_DOWNPOUR_SpawnParticles, WEATHER_DIAMOND_DUST_Begin, WEATHER_DIAMOND_DUST_BeginParticles, WEATHER_DIAMOND_DUST_BeginPlain, WEATHER_DIAMOND_DUST_Run, WEATHER_DIAMOND_DUST_EndParticles, WEATHER_DIAMOND_DUST_EndFade, WEATHER_DIAMOND_DUST_EndFinish, WEATHER_DIAMOND_DUST_UpdateParticle, WEATHER_DIAMOND_DUST_SpawnParticles
 * address:  0x021EE740
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Cleanup (lane WXT): the unplaced spawner 021EF634 is merged in. One file for the four kinds snow (weather id 1), blizzard (4), downpour (5) and diamond dust (8): the const tables of all four sit in one run sorted by size (blizzard 9, 11, 16, 16 bytes, then the 337 byte snow wobble table), which one object file gives and four do not.
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_SetupSpawner  0x021A21F8  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_SaveCameraPos  0x021A2424  thumb  ov021
 *   WEATHER_TASK_StepSpawner  0x021A223C  thumb  ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_GetCameraScroll  0x021A244C  thumb  ov021
 *   WEATHER_TASK_ShiftParticles  0x021A2564  thumb  ov021
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 *   WEATHER_TASK_PrewarmParticles  0x021A2254  thumb  ov021
 *   WEATHER_TASK_SetLight  0x021A2114  thumb  ov021
 *   WEATHER_TASK_StepSpawnTimer 0x021A2248 thumb ov021
 *   WEATHER_TASK_RetargetSpawner 0x021A2228 thumb ov021
 *   WEATHER_TASK_ChangeFogOffset  0x021A2390  thumb  ov021
 *   WEATHER_TASK_GetParticleCount  0x021A21BC  thumb  ov021
 *   WEATHER_TASK_DisableFog 0x021A231C thumb ov021
 *   WEATHER_TASK_ResetLight 0x021A2120 thumb ov021
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   WEATHER_TASK_GetParticlePos  0x021A2640  thumb  ov021
 *   WEATHER_TASK_SetParticlePosWrapped  0x021A2654  thumb  ov021
 *   WEATHER_TASK_RemoveParticle  0x021A21E0  thumb  ov021
 *   _u32_div_f  0x0209C2B0  arm
 *   gSnowWobbleOffsetX  0x021EF790  data  ov025  a1
 *   func_020056EC  0x020056EC  thumb
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   WEATHER_TASK_AddParticle  0x021A21C8  thumb  ov021
 *   WEATHER_TASK_PlaySe  0x021A25BC  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   gBlizzardWindSpeedX  0x021EF770  data  ov025  a4
 *   WEATHER_TASK_StopSe 0x021A25CC thumb ov021
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   gBlizzardWindSpeedY     0x021EF780  data   a4
 *   WEATHER_TASK_SetBillboardParam0C 0x021A2190 thumb ov021
 *   WEATHER_TASK_SetBillboardParam10 0x021A21A0 thumb ov021
 *   gBlizzardFogScrollStepX    0x021EF765 data a1
 *   gBlizzardFogScrollStepY    0x021EF75C data ov025 a1
 *   WEATHER_TASK_SetParticlePos  0x021A26C4  thumb  ov021
 *   CLACT_GetActorAnimSeqCount  0x0204B918  arm
 */
#include "../ov021/weather_task_types.h"
#include "weather_snow_blizzard_downpour_diamond_dust_types.h"

extern const s8 gSnowWobbleOffsetX[];
extern const int gBlizzardWindSpeedX[];
extern const int gBlizzardWindSpeedY[];
extern const s8 gBlizzardFogScrollStepX[];
extern const s8 gBlizzardFogScrollStepY[];
/* ---- Snow ---- */

/* Snow, stage begin: slow spawner, fog and light fade parameters. */
int WEATHER_SNOW_Begin(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work = WEATHER_TASK_GetWorkBuffer(task);

    WEATHER_TASK_SetupSpawner(task, 1, 0x12, 1, 0x10, -3, 1, 0, WEATHER_SNOW_SpawnParticles);
    work->staggerSpawn = 0;
    work->ending = 0;
    WEATHER_TASK_InitFog(task, 8, 0x7FDF, variant);
    work->fadeDelay = 8;
    WEATHER_TASK_SaveCameraPos(task);
    return 1;
}

/* Snow, stage fade in: after a short delay fades fog and light, then waits for the spawner and the fade. */
int WEATHER_SNOW_BeginParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            WEATHER_TASK_ChangeFog(task, 8, 0x7F5F, 0x5A, variant);
            WEATHER_TASK_FadeLight(task, 0x3E, ZONEDATA_GetLightTableMember(1));
        }
    } else if (WEATHER_TASK_IsFogIdle(task) != 0 && spawnerReady != 0) {
        return 1;
    }
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Snow, stage begin at once: fills the screen with flakes and sets fog and light without a fade. */
int WEATHER_SNOW_BeginPlain(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work = WEATHER_TASK_GetWorkBuffer(task);

    WEATHER_TASK_SetupSpawner(task, 1, 0x10, 1, 0x10, -3, 1, 0, WEATHER_SNOW_SpawnParticles);
    work->staggerSpawn = 1;
    work->ending = 0;
    WEATHER_TASK_InitFog(task, 8, 0x7F5F, variant);
    WEATHER_TASK_PrewarmParticles(task, WEATHER_SNOW_SpawnParticles, 0x14, 1, 0x12, heapId);
    WEATHER_TASK_SetLight(task, 0x3E, ZONEDATA_GetLightTableMember(1));
    return 1;
}

/* Snow, stage run: spawner step and camera scroll. */
int WEATHER_SNOW_Run(WeatherTaskSys *task, int variant, int heapId)
{
    int scrollX;
    int scrollY;

    WEATHER_TASK_StepSpawnTimer(task, heapId);
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Snow, stage stop spawning. */
int WEATHER_SNOW_EndParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work;
    int scrollX;
    int scrollY;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_RetargetSpawner(task, 0, 18, 3, -1);
    work->fadeDelay = 16;
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 1;
}

/* Snow, stage fade out: after a delay fades fog and light out, then waits until the flakes are gone. */
int WEATHER_SNOW_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work;
    int spawnerReady;
    int fadeDone;
    int scrollX;
    int scrollY;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            WEATHER_TASK_ChangeFogOffset(task, 0x7FDF, 0x5A, variant);
        }
    } else {
        if (variant != 0) {
            fadeDone = WEATHER_TASK_IsFogIdle(task);
        } else {
            fadeDone = 1;
        }
        if (fadeDone != 0 && spawnerReady != 0) {
            work->ending = 1;
            if (WEATHER_TASK_GetParticleCount(task) == 0) {
                return 1;
            }
        }
    }
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/*
 * Snow, stage finish: releases fog and light.
 * extent: trailing two-byte zero alignment padding at 0x021EE97E.
 */
int WEATHER_SNOW_EndFinish(WeatherTaskSys *task, int variant, int heapId)
{
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    return 1;
}

/* Snow, particle update: sways with the wobble table and falls slowly; removed after the weather ended or at the screen edge. */
void WEATHER_SNOW_UpdateParticle(WeatherParticle *particle)
{
    WeatherSnowFlake *flake;
    int wasDying;
    int *ending;
    WeatherScreenPos pos;

    flake = (WeatherSnowFlake *)WEATHER_TASK_GetParticleWork(particle);
    WEATHER_TASK_GetParticleActor(particle);
    wasDying = flake->dying;
    ending = flake->ending;
    if (wasDying == 0) {
        if (*ending != 0) {
            flake->dying = wasDying + 1;
        }
    } else {
        flake->dyingFrames = flake->dyingFrames - 1;
        if (flake->dyingFrames < 0) {
            WEATHER_TASK_RemoveParticle(particle);
            return;
        }
    }
    WEATHER_TASK_GetParticlePos(particle, &pos);
    pos.x = pos.x + gSnowWobbleOffsetX[flake->wobbleIndex];
    if (flake->fallAccum > flake->fallThreshold) {
        pos.y = pos.y + 1;
        flake->fallAccum = flake->fallAccum % flake->fallThreshold;
    }
    WEATHER_TASK_SetParticlePosWrapped(particle, &pos);
    flake->fallAccum = flake->fallAccum + 8;
    flake->wobbleIndex = (unsigned)(flake->wobbleIndex + 1) % 337u;
    if ((pos.y < -284 && pos.y > -296) || (pos.y > 212 && pos.y < 232)) {
        *flake->staggerSpawn = 1;
        WEATHER_TASK_RemoveParticle(particle);
    }
}

/* Snow, spawner callback: creates flakes above the screen. */
void WEATHER_SNOW_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId)
{
    WeatherSnowWork *work;
    int i;
    WeatherParticle *particle;
    WeatherSnowFlake *flake;
    Actor *actor;
    WeatherScreenPos pos;

    work = WEATHER_TASK_GetWorkBuffer(task);
    for (i = 0; i < count; i++) {
        particle = WEATHER_TASK_AddParticle(task, heapId);
        if (particle == 0) {
            return;
        }
        flake = (WeatherSnowFlake *)WEATHER_TASK_GetParticleWork(particle);
        actor = WEATHER_TASK_GetParticleActor(particle);
        CLACT_SetActorAnimIndex(actor, (u16)func_020056EC(4));
        flake->fallAccum = 0;
        flake->wobbleIndex = 0;
        flake->dying = 0;
        flake->dyingFrames = (int)func_020056EC(0) % 30 + 2;
        flake->fallThreshold = func_020056EC(8) + 12;
        /* stand-in: the int round trip keeps the address arithmetic in the hoisting order of the original */
        flake->staggerSpawn = (int *)(int)&work->staggerSpawn;
        flake->ending = (int *)(int)&work->ending;
        pos.x = func_020056EC(0x19E) - 0x20;
        if (work->staggerSpawn == 1 && i >= count / 2) {
            pos.y = -8 - 0x20 - func_020056EC(0x14);
        } else {
            pos.y = -8 - func_020056EC(0x14);
        }
        WEATHER_TASK_SetParticlePosWrapped(particle, &pos);
    }
}

/* ---- Blizzard ---- */

/* Blizzard, stage begin: spawner, fog and light parameters, wind sound. */
int WEATHER_BLIZZARD_Begin(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work = WEATHER_TASK_GetWorkBuffer(task);

    WEATHER_TASK_SetupSpawner(task, 1, 6, 1, 2, -2, 2, 1, (WeatherSpawnFunc)WEATHER_BLIZZARD_SpawnParticles);
    WEATHER_TASK_InitFog(task, 4, 0x7FFF, variant);
    work->fadeDelay = 8;
    work->windPhase = 0;
    work->scrollX = 0;
    work->scrollY = 0;
    work->scrollStep = 0;
    WEATHER_TASK_SaveCameraPos(task);
    WEATHER_TASK_PlaySe(task, 0x6E3);
    return 1;
}

/* Blizzard, stage fade in: after a short delay fades fog and light, then shows the fog layer. */
int WEATHER_BLIZZARD_BeginParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work;
    int spawnerReady;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            WEATHER_TASK_ChangeFog(task, 4, 0x7B18, 0x5A, variant);
            WEATHER_TASK_FadeLight(task, 0x3E, ZONEDATA_GetLightTableMember(4));
        }
    } else if (WEATHER_TASK_IsFogIdle(task) != 0 && spawnerReady != 0) {
        WEATHER_TASK_SetBillboardVisible(task, 1, 0);
        return 1;
    }
    WEATHER_BLIZZARD_ScrollFogLayer(task, work);
    return 0;
}

/* Blizzard, stage begin at once: fills the screen with flakes and shows the fog layer. */
int WEATHER_BLIZZARD_BeginPlain(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work = WEATHER_TASK_GetWorkBuffer(task);

    WEATHER_TASK_SetupSpawner(task, 1, 2, 1, 2, -2, 2, 1, (WeatherSpawnFunc)WEATHER_BLIZZARD_SpawnParticles);
    WEATHER_TASK_InitFog(task, 4, 0x7B18, variant);
    work->windPhase = 0;
    work->scrollX = 0;
    work->scrollY = 0;
    WEATHER_TASK_PrewarmParticles(task, (WeatherSpawnFunc)WEATHER_BLIZZARD_SpawnParticles, 0x14, 2, 2, heapId);
    WEATHER_TASK_SetBillboardVisible(task, 1, 0);
    WEATHER_TASK_SetLight(task, 0x3E, ZONEDATA_GetLightTableMember(4));
    return 1;
}

/* Blizzard, stage run: spawns an extra flake while the wind blows leftwards. */
int WEATHER_BLIZZARD_Run(WeatherTaskSys *task, int variant, u16 heapId)
{
    WeatherBlizzardWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    if (WEATHER_TASK_StepSpawnTimer(task, heapId) != 0) {
        if (gBlizzardWindSpeedX[work->windPhase / 256] <= -8) {
            WEATHER_BLIZZARD_SpawnParticles(task, 1, heapId);
        }
    }
    WEATHER_BLIZZARD_ScrollFogLayer(task, work);
    return 0;
}

/* Blizzard, stage stop spawning: hides the fog layer and stops the wind sound. */
int WEATHER_BLIZZARD_EndParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_RetargetSpawner(task, 0, 3, 1, -1);
    work->fadeDelay = 10;
    WEATHER_BLIZZARD_ScrollFogLayer(task, work);
    WEATHER_TASK_SetBillboardVisible(task, 0, 0);
    WEATHER_TASK_StopSe(task);
    return 1;
}

/* Blizzard, stage fade out. */
int WEATHER_BLIZZARD_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work;
    int spawnerReady;
    int fadeDone;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            WEATHER_TASK_ChangeFogOffset(task, 0x7FFF, 0x3C, variant);
        }
    } else {
        if (variant != 0) {
            fadeDone = WEATHER_TASK_IsFogIdle(task);
        } else {
            fadeDone = 1;
        }
        if (fadeDone != 0 && spawnerReady != 0) {
            work->scrollX = 1;
            if (WEATHER_TASK_GetParticleCount(task) == 0) {
                return 1;
            }
        }
    }
    WEATHER_BLIZZARD_ScrollFogLayer(task, work);
    return 0;
}

/*
 * Blizzard, stage finish: releases fog and light.
 * extent: trailing two-byte zero alignment padding at 0x021EED76.
 */
int WEATHER_BLIZZARD_EndFinish(WeatherTaskSys *task, int variant, int heapId)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    return 1;
}

/* Blizzard, particle update: flies with the wind, speeding up, and is removed after its lifetime. */
void WEATHER_BLIZZARD_UpdateParticle(WeatherParticle *particle)
{
    WeatherBlizzardFlake *flake;
    Actor *actor;
    WeatherScreenPos pos;

    flake = (WeatherBlizzardFlake *)WEATHER_TASK_GetParticleWork(particle);
    actor = WEATHER_TASK_GetParticleActor(particle);
    CLACT_GetActorSurfacePos(actor, &pos, 0);
    switch (flake->state) {
    case WEATHER_BLIZZARD_FLAKE_MOVING:
        pos.x = pos.x + (s16)flake->speedX;
        pos.y = pos.y + (s16)flake->speedY;
        if (flake->age++ > flake->lifetime) {
            flake->state = WEATHER_BLIZZARD_FLAKE_REMOVE;
        }
        if (flake->age % 4 == 0) {
            flake->speedX = flake->speedX + flake->accelX;
            if (flake->speedY > 1) {
                flake->speedY = flake->speedY - 1;
            }
        }
        CLACT_AddActorSurfacePos(actor, &pos, 0);
        break;
    case WEATHER_BLIZZARD_FLAKE_REMOVE:
        WEATHER_TASK_RemoveParticle(particle);
        break;
    }
}

/*
 * Blizzard, spawner callback: creates flakes at the left edge, moving with the current wind.
 * note:     heapId is narrow (u16/s16/u8 all give EXACT; int puts its home store
 *           third instead of first): WEATHER_TASK_AddParticle only forwards it, so no
 *           callee fixes the exact width. const on the two tables lets the
 *           indexed loads hoist out of the loop past the stores through flake.
 */
void WEATHER_BLIZZARD_SpawnParticles(WeatherTaskSys *task, s32 count, u16 heapId)
{
    WeatherBlizzardWork *work;
    int windIndex;
    int i;
    WeatherParticle *particle;
    WeatherBlizzardFlake *flake;
    Actor *actor;
    int size;
    WeatherScreenPos pos;

    work = WEATHER_TASK_GetWorkBuffer(task);
    if (++work->windPhase >= 0x400) {
        work->windPhase = 0;
    }
    windIndex = work->windPhase / 256;
    for (i = 0; i < count; i++) {
        particle = WEATHER_TASK_AddParticle(task, heapId);
        if (particle == 0) {
            return;
        }
        flake = (WeatherBlizzardFlake *)WEATHER_TASK_GetParticleWork(particle);
        actor = WEATHER_TASK_GetParticleActor(particle);
        flake->age = 0;
        flake->lifetime = func_020056EC(3) + 9;
        size = func_020056EC(4);
        CLACT_SetActorAnimIndex(actor, (u16)size);
        flake->speedX = (size + 1) * gBlizzardWindSpeedX[windIndex];
        flake->speedY = gBlizzardWindSpeedY[windIndex] * (size + 1);
        flake->state = WEATHER_BLIZZARD_FLAKE_MOVING;
        if (size == 3) {
            flake->speedX = flake->speedX + gBlizzardWindSpeedX[windIndex];
            flake->speedY = flake->speedY + gBlizzardWindSpeedY[windIndex];
        }
        flake->accelX = gBlizzardWindSpeedX[windIndex];
        pos.x = -func_020056EC(0x18);
        pos.y = func_020056EC(0xA8) - 0x20;
        CLACT_AddActorSurfacePos(actor, &pos, 0);
    }
}

/*
 * Blizzard, camera scroll and fog layer jitter: moves the flakes with the camera
 * and scrolls the fog layer by a small stepped offset.
 * The remainder goes back into step before the store (step = (step + 1) % 252u;
 * work->scrollStep = step;): storing the expression directly lets the compiler sink
 * index = step / 28 below the _u32_div_f call. const on the two s8 tables
 * schedules the second table pool load above the scrollX store.
 */
void WEATHER_BLIZZARD_ScrollFogLayer(WeatherTaskSys *task, WeatherBlizzardWork *work)
{
    int cameraDx;
    int cameraDy;
    int index;
    int step;

    WEATHER_TASK_GetCameraScroll(task, &cameraDx, &cameraDy);
    WEATHER_TASK_ShiftParticles(task, cameraDx, cameraDy);
    step = work->scrollStep;
    index = step / 28;
    step = (unsigned)(step + 1) % 252u;
    work->scrollStep = step;
    work->scrollX = work->scrollX + gBlizzardFogScrollStepX[index] - cameraDx / 2;
    work->scrollY = work->scrollY + gBlizzardFogScrollStepY[index] - cameraDy / 2;
    if (work->scrollX < 0) {
        work->scrollX = work->scrollX + 256;
    }
    if (work->scrollY < 0) {
        work->scrollY = work->scrollY + 256;
    }
    work->scrollX = work->scrollX % 256;
    work->scrollY = work->scrollY % 256;
    WEATHER_TASK_SetBillboardParam0C(task, -work->scrollX, 0);
    WEATHER_TASK_SetBillboardParam10(task, -work->scrollY, 0);
}

/* ---- Downpour ---- */

/* Downpour, stage begin: spawner, fog and light parameters, rain sound. */
int WEATHER_DOWNPOUR_Begin(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDownpourWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 0, 8, 1, 1, -4, 2, 1, WEATHER_DOWNPOUR_SpawnParticles);
    WEATHER_TASK_InitFog(task, 9, 0x7FDF, variant);
    work->fadeDelay = 1;
    WEATHER_TASK_SaveCameraPos(task);
    WEATHER_TASK_PlaySe(task, 0x6E4);
    return 1;
}

/* Downpour, stage fade in. */
int WEATHER_DOWNPOUR_BeginParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDownpourWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            WEATHER_TASK_ChangeFog(task, 9, 0x7F80, 0x3C, variant);
            WEATHER_TASK_FadeLight(task, 0x3E, ZONEDATA_GetLightTableMember(5));
        }
    } else if (WEATHER_TASK_IsFogIdle(task) != 0 && spawnerReady != 0) {
        return 1;
    }
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Downpour, stage begin at once. */
int WEATHER_DOWNPOUR_BeginPlain(WeatherTaskSys *task, int variant, int heapId)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 1, 1, 1, 1, -4, 2, 1, WEATHER_DOWNPOUR_SpawnParticles);
    WEATHER_TASK_InitFog(task, 9, 0x7F80, variant);
    WEATHER_TASK_PrewarmParticles(task, WEATHER_DOWNPOUR_SpawnParticles, 0x14, 10, 1, heapId);
    WEATHER_TASK_SetLight(task, 0x3E, ZONEDATA_GetLightTableMember(5));
    return 1;
}

/* Downpour, stage run. */
int WEATHER_DOWNPOUR_Run(WeatherTaskSys *task, int variant, int heapId)
{
    int scrollX;
    int scrollY;

    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_StepSpawnTimer(task, heapId);
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Downpour, stage stop spawning: stops the rain sound. */
int WEATHER_DOWNPOUR_EndParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDownpourWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_RetargetSpawner(task, 0, 8, 4, -1);
    work->fadeDelay = 1;
    WEATHER_TASK_StopSe(task);
    return 1;
}

/* Downpour, stage fade out. */
int WEATHER_DOWNPOUR_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDownpourWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;
    int fadeDone;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            WEATHER_TASK_ChangeFogOffset(task, 0x7FDF, 0x3C, variant);
        }
    } else {
        fadeDone = (variant != 0) ? WEATHER_TASK_IsFogIdle(task) : 1;
        if (fadeDone != 0 && spawnerReady != 0 && WEATHER_TASK_GetParticleCount(task) == 0) {
            return 1;
        }
    }
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Downpour, stage finish: releases fog and light. */
int WEATHER_DOWNPOUR_EndFinish(WeatherTaskSys *task, int variant, int heapId)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    return 1;
}

/* Downpour, particle update: a drop falls fast for a few frames, then splashes and fades. */
void WEATHER_DOWNPOUR_UpdateParticle(WeatherParticle *particle)
{
    WeatherDownpourDrop *drop;
    Actor *actor;
    WeatherScreenPos pos;

    drop = (WeatherDownpourDrop *)WEATHER_TASK_GetParticleWork(particle);
    actor = WEATHER_TASK_GetParticleActor(particle);
    WEATHER_TASK_GetParticlePos(particle, &pos);
    switch (drop->state) {
    case WEATHER_DOWNPOUR_DROP_FALLING:
        if (++drop->age > drop->fallFrames) {
            drop->state = WEATHER_DOWNPOUR_DROP_SPLASHING;
            drop->age = (drop->splashSeed % 4) * 2 + 8;
            drop->speedX = 2;
            drop->speedY = 2;
            CLACT_SetActorAnimIndex(actor, (u16)(CLACT_GetActorAnimSeqCount(actor) + 3));
            return;
        }
        pos.x = pos.x + (s16)drop->speedX;
        pos.y = pos.y + (s16)drop->speedY;
        WEATHER_TASK_SetParticlePosWrapped(particle, &pos);
        break;
    case WEATHER_DOWNPOUR_DROP_SPLASHING:
        pos.x = pos.x + (s16)drop->speedX;
        if (drop->age % 2 == 0) {
            pos.y = pos.y + (s16)drop->speedY;
        } else {
            pos.y = pos.y - (s16)drop->speedY;
        }
        if (drop->age % 4 == 0) {
            if (drop->speedY - 1 >= 0) {
                drop->speedY = drop->speedY - 1;
            }
            if (drop->speedX - 1 >= 0) {
                drop->speedX = drop->speedX - 1;
            }
        }
        WEATHER_TASK_SetParticlePos(particle, &pos);
        if (drop->age-- <= 0) {
            drop->state = WEATHER_DOWNPOUR_DROP_REMOVE;
        }
        break;
    case WEATHER_DOWNPOUR_DROP_REMOVE:
        WEATHER_TASK_RemoveParticle(particle);
        break;
    }
}

/* Downpour, spawner callback: creates drops of three sizes along the top of the screen. */
void WEATHER_DOWNPOUR_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId)
{
    int i;
    WeatherParticle *particle;
    WeatherDownpourDrop *drop;
    Actor *actor;
    u32 random;
    u32 roll;
    int sizeClass;
    int jitter;
    WeatherScreenPos pos;

    WEATHER_TASK_GetWorkBuffer(task);
    for (i = 0; i < count; i++) {
        particle = WEATHER_TASK_AddParticle(task, heapId);
        if (particle == 0) {
            return;
        }
        drop = (WeatherDownpourDrop *)WEATHER_TASK_GetParticleWork(particle);
        actor = WEATHER_TASK_GetParticleActor(particle);
        random = func_020056EC(0);
        drop->age = 0;
        roll = random % 100;
        if (roll < 30) {
            sizeClass = 0;
        } else if (roll < 95) {
            sizeClass = 1;
        } else if (roll < 100) {
            sizeClass = 2;
        }
        CLACT_SetActorAnimIndex(actor, (u16)(2 - sizeClass));
        jitter = random % 23;
        drop->speedY = jitter + (sizeClass + 1) * 10;
        if (sizeClass == 2) {
            drop->speedY += 3;
        }
        drop->speedX = jitter / 4 + (sizeClass + 1) * 4;
        if (sizeClass == 2) {
            drop->speedX -= 2;
        }
        drop->state = WEATHER_DOWNPOUR_DROP_FALLING;
        drop->fallFrames = (random & 3) + 1;
        pos.x = random % 270 + (sizeClass * 15 - 0x40);
        pos.y = (random & 0xF) - 8;
        WEATHER_TASK_SetParticlePosWrapped(particle, &pos);
        drop->splashSeed = random;
    }
}

/* ---- Diamond dust ---- */

/* Diamond dust, stage begin. */
int WEATHER_DIAMOND_DUST_Begin(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDiamondDustWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 2, 0x10, 0x14, 2, -2, 4, 2, WEATHER_DIAMOND_DUST_SpawnParticles);
    WEATHER_TASK_InitFog(task, 8, 0x7FFF, variant);
    work->fadeState = 0;
    return 1;
}

/* Diamond dust, stage fade in: issues the fog and light fade once, then waits for it. */
int WEATHER_DIAMOND_DUST_BeginParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDiamondDustWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fadeState == 0) {
        work->fadeState = work->fadeState - 1;
        WEATHER_TASK_ChangeFog(task, 8, 0x7F57, 0x5A, variant);
        WEATHER_TASK_FadeLight(task, 0x3E, ZONEDATA_GetLightTableMember(8));
    } else if (WEATHER_TASK_IsFogIdle(task) != 0 && spawnerReady != 0) {
        return 1;
    }
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Diamond dust, stage begin at once. */
int WEATHER_DIAMOND_DUST_BeginPlain(WeatherTaskSys *task, int variant, int heapId)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 0x14, 2, 0x14, 2, -2, 4, 2, WEATHER_DIAMOND_DUST_SpawnParticles);
    WEATHER_TASK_InitFog(task, 8, 0x7F57, variant);
    WEATHER_TASK_PrewarmParticles(task, WEATHER_DIAMOND_DUST_SpawnParticles, 0x14, 10, 1, heapId);
    WEATHER_TASK_SetLight(task, 0x3E, ZONEDATA_GetLightTableMember(8));
    return 1;
}

/* Diamond dust, stage run. */
int WEATHER_DIAMOND_DUST_Run(WeatherTaskSys *task, int variant, int heapId)
{
    int scrollX;
    int scrollY;

    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_StepSpawnTimer(task, heapId);
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Diamond dust, stage stop spawning. */
int WEATHER_DIAMOND_DUST_EndParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDiamondDustWork *work;

    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_RetargetSpawner(task, 0, 16, 2, -2);
    work->fadeState = 100;
    return 1;
}

/* Diamond dust, stage fade out: waits 100 frames, then fades fog and light out. */
int WEATHER_DIAMOND_DUST_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDiamondDustWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;
    int fadeDone;

    work = WEATHER_TASK_GetWorkBuffer(task);
    spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);
    if (work->fadeState > 0) {
        work->fadeState = work->fadeState - 1;
        if (work->fadeState == 0) {
            WEATHER_TASK_ChangeFogOffset(task, 0x7FFF, 0x78, variant);
        }
    } else {
        fadeDone = (variant != 0) ? WEATHER_TASK_IsFogIdle(task) : 1;
        if (fadeDone != 0 && spawnerReady != 0 && WEATHER_TASK_GetParticleCount(task) == 0) {
            return 1;
        }
    }
    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    return 0;
}

/* Diamond dust, stage finish: releases fog and light. */
int WEATHER_DIAMOND_DUST_EndFinish(WeatherTaskSys *task, int variant, int heapId)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    return 1;
}

/* Diamond dust, particle update: drifts one pixel at a time, removed after its lifetime. */
void WEATHER_DIAMOND_DUST_UpdateParticle(WeatherParticle *particle)
{
    WeatherDiamondDustSparkle *sparkle;
    WeatherScreenPos pos;

    sparkle = (WeatherDiamondDustSparkle *)WEATHER_TASK_GetParticleWork(particle);
    WEATHER_TASK_GetParticleActor(particle);
    WEATHER_TASK_GetParticlePos(particle, &pos);
    sparkle->age = sparkle->age + 1;
    if (sparkle->age % sparkle->xInterval == 0) {
        pos.x = pos.x + (s16)sparkle->stepX;
    }
    if (sparkle->age % sparkle->yInterval == 0) {
        pos.y = pos.y + (s16)sparkle->stepY;
    }
    if (sparkle->age >= sparkle->lifetime) {
        WEATHER_TASK_RemoveParticle(particle);
    }
}

/*
 * Diamond dust, spawner callback: creates sparkles at random places; those
 * inside a diagonal strip live twice as long.
 */
void WEATHER_DIAMOND_DUST_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId)
{
    int i;
    WeatherParticle *particle;
    int random;
    WeatherDiamondDustSparkle *sparkle;
    Actor *actor;
    int random2;
    int animIndex;
    int stripTop;
    int stripSpan;
    int stripBottom;
    WeatherScreenPos pos;

    WEATHER_TASK_GetWorkBuffer(task);
    for (i = 0; i < count; i++) {
        particle = WEATHER_TASK_AddParticle(task, heapId);
        if (particle == 0) {
            return;
        }
        sparkle = (WeatherDiamondDustSparkle *)WEATHER_TASK_GetParticleWork(particle);
        actor = WEATHER_TASK_GetParticleActor(particle);
        random = func_020056EC(0);
        random2 = func_020056EC(0);
        sparkle->age = 0;
        sparkle->lifetime = random % 5 + 7;
        if (random % 2 == 0) {
            sparkle->stepX = 1;
        } else {
            sparkle->stepX = -1;
        }
        sparkle->stepY = 1;
        sparkle->xInterval = random % 6 + 3;
        sparkle->yInterval = random2 % 5 + 4;
        animIndex = random % 20;
        pos.x = random % 384 - 64;
        pos.y = random2 % 256 - 8;
        WEATHER_TASK_SetParticlePosWrapped(particle, &pos);
        stripTop = 50 - pos.x / 3;
        stripSpan = 206 - pos.x / 3;
        if (stripSpan < 0) {
            stripBottom = stripTop - random2 % -stripSpan;
        } else {
            stripBottom = stripTop + random2 % stripSpan;
        }
        if (stripTop <= pos.y && stripBottom >= pos.y) {
            sparkle->lifetime *= 2;
        } else {
            animIndex = random % 4;
        }
        CLACT_SetActorAnimIndex(actor, (u16)animIndex);
    }
}
