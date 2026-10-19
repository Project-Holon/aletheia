/*
 * file:     weather_sandstorm.c
 * unit:     yes
 * function: WEATHER_SANDSTORM_Begin, WEATHER_SANDSTORM_BeginParticles, WEATHER_SANDSTORM_BeginPlain, WEATHER_SANDSTORM_Run, WEATHER_SANDSTORM_EndParticles, WEATHER_SANDSTORM_EndFade, WEATHER_SANDSTORM_EndFinish, WEATHER_SANDSTORM_UpdateParticle, WEATHER_SANDSTORM_SpawnParticles, WEATHER_SANDSTORM_ScrollBillboards
 * address:  0x021EE740
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Cleanup (lane WXT): the unplaced billboard scroll leaf 021EEAF4 is merged in. Weather ids 3 and 12 (two WeatherKindDef with the same stages, ids differ in the first layer word).
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_SetupSpawner  0x021A21F8  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_SaveCameraPos  0x021A2424  thumb  ov021
 *   WEATHER_TASK_PlaySe  0x021A25BC  thumb  ov021
 *   WEATHER_TASK_StepSpawner  0x021A223C  thumb  ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   WEATHER_TASK_PrewarmParticles  0x021A2254  thumb  ov021
 *   WEATHER_TASK_SetLight  0x021A2114  thumb  ov021
 *   WEATHER_TASK_StepSpawnTimer  0x021A2248  thumb  ov021
 *   gSandstormGustSpeedX     0x021EEB48  data  ov027  a4
 *   WEATHER_TASK_RetargetSpawner 0x021A2228 thumb ov021
 *   WEATHER_TASK_StopSe 0x021A25CC thumb ov021
 *   WEATHER_TASK_ChangeFogOffset  0x021A2390  thumb  ov021
 *   WEATHER_TASK_GetParticleCount  0x021A21BC  thumb  ov021
 *   WEATHER_TASK_DisableFog 0x021A231C thumb ov021
 *   WEATHER_TASK_ResetLight 0x021A2120 thumb ov021
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   WEATHER_TASK_GetParticlePos  0x021A2640  thumb  ov021
 *   WEATHER_TASK_SetParticlePosWrapped  0x021A2654  thumb  ov021
 *   WEATHER_TASK_RemoveParticle  0x021A21E0  thumb  ov021
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   WEATHER_TASK_AddParticle  0x021A21C8  thumb  ov021
 *   gSandstormGustSpeedY     0x021EEB68  data  a4
 *   WEATHER_TASK_GetCameraScroll  0x021A244C  thumb  ov021
 *   WEATHER_TASK_ShiftParticles  0x021A2564  thumb  ov021
 *   WEATHER_TASK_SetBillboardParam0C  0x021A2190  thumb  ov021
 *   WEATHER_TASK_SetBillboardParam10  0x021A21A0  thumb  ov021
 */
#include "../ov021/weather_task_types.h"
#include "weather_sandstorm_types.h"

/* Weather task services (ov021). */
void *WEATHER_TASK_GetWorkBuffer(WeatherTaskSys *task);
void WEATHER_TASK_SetupSpawner(WeatherTaskSys *task, int count, int interval, int targetCount, int targetInterval, int intervalStep, int stepsPerCountChange, int countStep, WeatherSpawnFunc spawn);
void WEATHER_TASK_InitFog(WeatherTaskSys *task, int slope, int offset, int phase);
void WEATHER_TASK_SaveCameraPos(WeatherTaskSys *task);
void WEATHER_TASK_PlaySe(WeatherTaskSys *task, u16 seId);
int WEATHER_TASK_StepSpawner(WeatherTaskSys *task, int heapId);
void WEATHER_TASK_ChangeFog(WeatherTaskSys *task, u8 slope, int offset, int frames, int mode);
int WEATHER_TASK_FadeLight(WeatherTaskSys *task, int arcId, int memberId);
int WEATHER_TASK_IsFogIdle(WeatherTaskSys *task);
void WEATHER_TASK_SetBillboardVisible(WeatherTaskSys *task, unsigned int value, int layer);
void WEATHER_TASK_PrewarmParticles(WeatherTaskSys *task, WeatherSpawnFunc spawn, int iterations, int growEvery, int growBy, int heapId);
int WEATHER_TASK_SetLight(WeatherTaskSys *task, int arcId, u32 memberId);
int WEATHER_TASK_StepSpawnTimer(WeatherTaskSys *task, int heapId);
void WEATHER_TASK_RetargetSpawner(WeatherTaskSys *task, int targetCount, int targetInterval, int intervalStep, int countStep);
void WEATHER_TASK_StopSe(WeatherTaskSys *task);
void WEATHER_TASK_ChangeFogOffset(WeatherTaskSys *task, int endOffset, int frames, int mode);
int WEATHER_TASK_GetParticleCount(WeatherTaskSys *task);
void WEATHER_TASK_DisableFog(WeatherTaskSys *task, int phase);
void WEATHER_TASK_ResetLight(WeatherTaskSys *task, int phase);
u8 *WEATHER_TASK_GetParticleWork(WeatherParticle *particle);
struct Actor *WEATHER_TASK_GetParticleActor(WeatherParticle *particle);
void WEATHER_TASK_GetParticlePos(WeatherParticle *particle, WeatherScreenPos *out);
void WEATHER_TASK_SetParticlePosWrapped(WeatherParticle *particle, const WeatherScreenPos *pos);
void WEATHER_TASK_RemoveParticle(WeatherParticle *particle);
WeatherParticle *WEATHER_TASK_AddParticle(WeatherTaskSys *task, int reserved);
u16 ZONEDATA_GetLightTableMember(u32 weatherId);
extern u32 GFL_USE_GetRandom(u32 range);
/* Signed divide helper, called by name here (the result is the quotient). */
extern void CLACT_SetActorAnimIndex(struct Actor *actor, u32 animIndex);
int WEATHER_SANDSTORM_Begin(WeatherTaskSys *task, int variant);
int WEATHER_SANDSTORM_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SANDSTORM_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SANDSTORM_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SANDSTORM_EndParticles(WeatherTaskSys *task);
int WEATHER_SANDSTORM_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SANDSTORM_EndFinish(WeatherTaskSys *task, int variant);
void WEATHER_SANDSTORM_UpdateParticle(WeatherParticle *particle);
void WEATHER_SANDSTORM_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);

/* Horizontal speed of the particles per gust step. */
extern const int gSandstormGustSpeedX[];
/* Vertical speed per gust step. */
extern const int gSandstormGustSpeedY[];
extern void WEATHER_TASK_GetCameraScroll(struct WeatherTaskSys *task, int *outX, int *outY);
extern void WEATHER_TASK_ShiftParticles(struct WeatherTaskSys *task, int dx, int dy);
extern void WEATHER_TASK_SetBillboardParam0C(struct WeatherTaskSys *task, unsigned int value, int layer);
extern void WEATHER_TASK_SetBillboardParam10(struct WeatherTaskSys *task, unsigned int value, int layer);
/* Begin stage of the kind (staged start): spawner, fog and sound. */
int WEATHER_SANDSTORM_Begin(WeatherTaskSys *task, int variant)
{
    WeatherSandstormWork *work = WEATHER_TASK_GetWorkBuffer(task);

    WEATHER_TASK_SetupSpawner(task, 1, 15, 1, 2, -2, 4, 1, WEATHER_SANDSTORM_SpawnParticles);
    WEATHER_TASK_InitFog(task, 8, 0x7fdf, variant);
    work->startDelay = 1;
    work->gustCounter = 0;
    work->scrollPhase = 0;
    work->gustSpeed = 0;
    WEATHER_TASK_SaveCameraPos(task);
    WEATHER_TASK_PlaySe(task, 0x6e3);
    return 1;
}

/* Begin particles stage: start the fog and light change, wait for the fog and the spawner. */
int WEATHER_SANDSTORM_BeginParticles(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSandstormWork *work = WEATHER_TASK_GetWorkBuffer(task);
    int spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);

    if (work->startDelay > 0) {
        work->startDelay = work->startDelay - 1;
        if (work->startDelay == 0) {
            WEATHER_TASK_ChangeFog(task, 8, 0x7f5e, 0x5a, variant);
            WEATHER_TASK_FadeLight(task, 0x3e, ZONEDATA_GetLightTableMember(3));
        }
    } else if (WEATHER_TASK_IsFogIdle(task) != 0 && spawnerReady != 0) {
        WEATHER_TASK_SetBillboardVisible(task, 1, 0);
        return 1;
    }
    WEATHER_SANDSTORM_ScrollBillboards(task, work);
    return 0;
}

/* Begin plain stage (everything at once): fog, filled screen, light, first billboard layer. */
int WEATHER_SANDSTORM_BeginPlain(WeatherTaskSys *task, int variant, int heapId)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_SetupSpawner(task, 1, 2, 1, 2, -2, 4, 1, WEATHER_SANDSTORM_SpawnParticles);
    WEATHER_TASK_InitFog(task, 8, 0x7f5e, variant);
    WEATHER_TASK_PrewarmParticles(task, WEATHER_SANDSTORM_SpawnParticles, 24, 2, 2, heapId);
    WEATHER_TASK_SetBillboardVisible(task, 1, 0);
    WEATHER_TASK_SetLight(task, 0x3e, ZONEDATA_GetLightTableMember(3));
    return 1;
}

/* Run stage: pick the gust speed of the current step and scroll the billboards. */
int WEATHER_SANDSTORM_Run(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSandstormWork *work = WEATHER_TASK_GetWorkBuffer(task);

    if (WEATHER_TASK_StepSpawnTimer(task, heapId) != 0) {
        int gustSpeed = gSandstormGustSpeedX[work->gustCounter / GUST_STEP_FRAMES];
        work->gustSpeed = gustSpeed;
        if (gustSpeed <= -6)
            WEATHER_SANDSTORM_SpawnParticles(task, 1, heapId);
    }
    WEATHER_SANDSTORM_ScrollBillboards(task, work);
    return 0;
}

/* End particles stage: let the spawner run out, hide the first billboard layer, stop the sound. */
int WEATHER_SANDSTORM_EndParticles(WeatherTaskSys *task)
{
    WeatherSandstormWork *work;
    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_RetargetSpawner(task, 0, 15, 2, -1);
    work->startDelay = 31;
    WEATHER_TASK_SetBillboardVisible(task, 0, 0);
    WEATHER_TASK_StopSe(task);
    return 1;
}

/* End fade stage: after the delay fade the fog out, then wait for the fog and the particles. */
int WEATHER_SANDSTORM_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSandstormWork *work = WEATHER_TASK_GetWorkBuffer(task);
    int spawnerReady = WEATHER_TASK_StepSpawner(task, heapId);
    int fogIdle;

    if (work->startDelay > 0) {
        work->startDelay = work->startDelay - 1;
        if (work->startDelay == 0)
            WEATHER_TASK_ChangeFogOffset(task, 0x7fdf, 0x5a, variant);
    } else {
        if (variant != 0)
            fogIdle = WEATHER_TASK_IsFogIdle(task);
        else
            fogIdle = 1;
        if (fogIdle != 0 && spawnerReady != 0) {
            if (WEATHER_TASK_GetParticleCount(task) == 0)
                return 1;
        }
    }
    WEATHER_SANDSTORM_ScrollBillboards(task, work);
    return 0;
}

/* End finish stage: switch the fog off and reset the light. */
int WEATHER_SANDSTORM_EndFinish(WeatherTaskSys *task, int variant)
{
    WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    return 1;
}

/*
 * The 2 trailing bytes (0x021EEA02) are alignment padding before
 * WEATHER_SANDSTORM_SpawnParticles, which is why the verdict is EXACT*.
 */
/* Moves one particle: gusts accelerate it to the right until it expires. */
void WEATHER_SANDSTORM_UpdateParticle(WeatherParticle *particle)
{
    WeatherSandstormGrain *work = (WeatherSandstormGrain *)WEATHER_TASK_GetParticleWork(particle);
    WeatherScreenPos pos;

    WEATHER_TASK_GetParticleActor(particle);
    WEATHER_TASK_GetParticlePos(particle, &pos);
    if (work->expired == 0) {
        pos.x = pos.x + (s16)work->speedX;
        pos.y = pos.y + (s16)work->speedY;
        if (work->age % 5 == 0)
            work->speedX = work->speedX + work->speedXStep;
        if (work->age++ > work->lifetime)
            work->expired = 1;
        WEATHER_TASK_SetParticlePosWrapped(particle, &pos);
    } else {
        WEATHER_TASK_RemoveParticle(particle);
    }
}

/* Spawn callback: creates count grains at the left edge. A shorter lifetime gives a larger sprite and more speed. */
void WEATHER_SANDSTORM_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId)
{
    WeatherSandstormWork *work;
    int gustStep;
    int i;
    int spriteSize;
    WeatherParticle *particle;
    WeatherSandstormGrain *particleWork;
    struct Actor *actor;
    WeatherScreenPos pos;

    work = WEATHER_TASK_GetWorkBuffer(task);
    work->gustCounter = (work->gustCounter + 1) % GUST_CYCLE_FRAMES;
    gustStep = work->gustCounter / GUST_STEP_FRAMES;
    for (i = 0; i < count; i++) {
        particle = WEATHER_TASK_AddParticle(task, heapId);
        if (particle == 0) {
            return;
        }
        particleWork = (WeatherSandstormGrain *)WEATHER_TASK_GetParticleWork(particle);
        actor = WEATHER_TASK_GetParticleActor(particle);
        particleWork->age = 0;
        particleWork->lifetime = GFL_USE_GetRandom(20) + 15;
        spriteSize = 3 - (particleWork->lifetime - 15) / 6;
        particleWork->speedY = (spriteSize + 1) * gSandstormGustSpeedY[gustStep];
        particleWork->speedX = (spriteSize + 1) * gSandstormGustSpeedX[gustStep];
        particleWork->expired = 0;
        particleWork->speedXStep = gSandstormGustSpeedX[gustStep];
        if (GFL_USE_GetRandom(1000) == 777) {
            spriteSize = 4;
            particleWork->speedY = particleWork->speedY + particleWork->speedY / 2;
        }
        CLACT_SetActorAnimIndex(actor, (u16)spriteSize);
        pos.x = -6 - GFL_USE_GetRandom(24);
        pos.y = GFL_USE_GetRandom(192) - 64;
        WEATHER_TASK_SetParticlePosWrapped(particle, &pos);
    }
}

/* Scrolls the billboards with the camera and with the gust phase, and shifts the particles. */
void WEATHER_SANDSTORM_ScrollBillboards(struct WeatherTaskSys *task, WeatherSandstormWork *work)
{
    int scrollX;
    int scrollY;

    WEATHER_TASK_GetCameraScroll(task, &scrollX, &scrollY);
    WEATHER_TASK_ShiftParticles(task, scrollX, scrollY);
    work->scrollPhase = (work->scrollPhase + GUST_SCROLL_STEP) % GUST_SCROLL_PERIOD;
    WEATHER_TASK_SetBillboardParam0C(task, -work->scrollPhase * 2 - scrollX, 0);
    WEATHER_TASK_SetBillboardParam10(task, scrollY + -work->scrollPhase * 2, 0);
}
