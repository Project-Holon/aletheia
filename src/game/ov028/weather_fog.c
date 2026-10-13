/*
 * file:     weather_fog.c
 * unit:     yes
 * function: func_021EE740, WEATHER_FOG_BeginParticlesFixed, WEATHER_FOG_BeginPlainFixed, WEATHER_FOG_RunFixed, WEATHER_FOG_EndParticlesFixed, WEATHER_FOG_EndFadeFixed, WEATHER_FOG_EndFinishFixed, WEATHER_FOG_UpdateParticleFixed, WEATHER_FOG_BeginKind10, WEATHER_FOG_BeginKind11, WEATHER_FOG_BeginKind13, WEATHER_FOG_BeginKind14, WEATHER_FOG_BeginParticles, WEATHER_FOG_BeginPlain, func_021EEA04, WEATHER_FOG_EndParticles, WEATHER_FOG_EndFade, WEATHER_FOG_EndFinish
 * address:  0x021EE740
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Cleanup (lane WXT): the unplaced end finish stage 021EEA64 is merged in. One file for weather ids 9, 10, 11, 13 and 14: the five WeatherKindDef are interleaved in data (order ids 14, 10, 9, 11, 13), so the fixed fog stages 021EE740..021EE867 are not a separate file.
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_SetLight 0x021A2114 thumb ov021
 *   WEATHER_TASK_ChangeFogOffset  0x021A2390  thumb  ov021
 *   WEATHER_TASK_GetParticleCount  0x021A21BC  thumb  ov021
 *   WEATHER_TASK_DisableFog 0x021A231C thumb ov021
 *   WEATHER_TASK_ResetLight 0x021A2120 thumb ov021
 *   WEATHER_TASK_GetCameraState  0x021A2148  thumb  ov021
 *   gFogSlopeByCameraState     0x021EEA80  data  ov028  a1
 *   gFogOffsetByCameraState     0x021EEAA4  data  ov028  a4
 */
#include "../ov021/weather_task_types.h"
#include "weather_fog_types.h"

/* Weather task services (ov021). */
void *WEATHER_TASK_GetWorkBuffer(WeatherTaskSys *task);
void WEATHER_TASK_InitFog(WeatherTaskSys *task, int slope, int offset, int phase);
void WEATHER_TASK_ChangeFog(WeatherTaskSys *task, int slope, int offset, int frames, int mode);
int WEATHER_TASK_FadeLight(WeatherTaskSys *task, int arcId, int memberId);
int WEATHER_TASK_IsFogIdle(WeatherTaskSys *task);
int WEATHER_TASK_SetLight(WeatherTaskSys *task, int arcId, u32 memberId);
void WEATHER_TASK_ChangeFogOffset(WeatherTaskSys *task, int endOffset, int frames, int mode);
int WEATHER_TASK_GetParticleCount(WeatherTaskSys *task);
void WEATHER_TASK_DisableFog(WeatherTaskSys *task, int phase);
void WEATHER_TASK_ResetLight(WeatherTaskSys *task, int phase);
int WEATHER_TASK_GetCameraState(WeatherTaskSys *task);
u16 func_02014A10(u32 weatherId);

/* Weather id 9 (fixed fog). */
int func_021EE740(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginParticlesFixed(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginPlainFixed(WeatherTaskSys *task, int variant);
int WEATHER_FOG_RunFixed(void);
int WEATHER_FOG_EndParticlesFixed(WeatherTaskSys *task);
int WEATHER_FOG_EndFadeFixed(WeatherTaskSys *task, int variant);
int WEATHER_FOG_EndFinishFixed(WeatherTaskSys *task, int variant);
void WEATHER_FOG_UpdateParticleFixed(void);
/* Weather ids 10, 11, 13 and 14 (fog from the camera state). */
int WEATHER_FOG_BeginKind10(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginKind11(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginKind13(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginKind14(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginParticles(WeatherTaskSys *task, int variant);
int WEATHER_FOG_BeginPlain(WeatherTaskSys *task, int variant);
int func_021EEA04(void);
int WEATHER_FOG_EndParticles(WeatherTaskSys *task);
int WEATHER_FOG_EndFade(WeatherTaskSys *task, int variant);

/* Fog slope per camera state. */
extern unsigned char gFogSlopeByCameraState[];
/* Fog offset per camera state. */
extern int gFogOffsetByCameraState[];
/* Begin stage: set the fog up. */
int func_021EE740(WeatherTaskSys *task, int variant)
{
    FogFixedWork *work;
    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_InitFog(task, 9, 0x7FDF, variant);
    work->fogChangeStarted = 0;
    work->fogSlope = 9;
    work->fogOffset = 0x7F78;
    return 1;
}

/* Begin particles stage: change the fog and the light once, then wait for the fog to settle. */
int WEATHER_FOG_BeginParticlesFixed(WeatherTaskSys *task, int variant)
{
    FogFixedWork *work = WEATHER_TASK_GetWorkBuffer(task);

    if (work->fogChangeStarted == 0) {
        WEATHER_TASK_ChangeFog(task, work->fogSlope, work->fogOffset, FOG_CHANGE_FRAMES, variant);
        WEATHER_TASK_FadeLight(task, FOG_LIGHT_ARC_ID, func_02014A10(9));
        work->fogChangeStarted = work->fogChangeStarted - 1;
    } else if (WEATHER_TASK_IsFogIdle(task) != 0) {
        return 1;
    }
    return 0;
}

/* Begin plain stage: set the fog and the light at once. */
int WEATHER_FOG_BeginPlainFixed(WeatherTaskSys *task, int variant)
{
    FogFixedWork *work;
    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_InitFog(task, work->fogSlope, work->fogOffset, variant);
    WEATHER_TASK_SetLight(task, 62, func_02014A10(9));
    return 1;
}

/*
 * Unlabelled 4-byte Thumb leaf (`movs r0,#0; bx lr`), emitted as a data word
 * by disasm.py because it saves no lr. A standalone slot: it follows the
 * `pop {r3,r4,r5,pc}` end of func_021EE7E8 and precedes WEATHER_FOG_EndParticlesFixed.
 */
/* Run stage: nothing to do. */
int WEATHER_FOG_RunFixed(void)
{
    return 0;
}

/* End particles stage: allow the fog change to start again. */
int WEATHER_FOG_EndParticlesFixed(WeatherTaskSys *task)
{
    FogFixedWork *work;
    work = WEATHER_TASK_GetWorkBuffer(task);
    work->fogChangeStarted = 0;
    return 1;
}

/* End fade stage: fade the fog out, then wait for the fog and the particles. */
int WEATHER_FOG_EndFadeFixed(WeatherTaskSys *task, int variant)
{
    FogFixedWork *work = WEATHER_TASK_GetWorkBuffer(task);
    int fogChangeStarted = work->fogChangeStarted;
    int fogIdle;

    if (fogChangeStarted == 0) {
        work->fogChangeStarted = fogChangeStarted - 1;
        WEATHER_TASK_ChangeFogOffset(task, FOG_END_OFFSET, FOG_END_FRAMES, variant);
    } else {
        if (variant != 0)
            fogIdle = WEATHER_TASK_IsFogIdle(task);
        else
            fogIdle = 1;
        if (fogIdle != 0) {
            if (WEATHER_TASK_GetParticleCount(task) == 0)
                return 1;
        }
    }
    return 0;
}

/* End finish stage: switch the fog off and reset the light. */
int WEATHER_FOG_EndFinishFixed(WeatherTaskSys *task, int variant)
{
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    return 1;
}

/* Particle update: this kind has no particles. */
void WEATHER_FOG_UpdateParticleFixed(void)
{
}

/* Begin stage of weather id 10: fog from the camera state. */
int WEATHER_FOG_BeginKind10(WeatherTaskSys *task, int variant)
{
    int cameraState = WEATHER_TASK_GetCameraState(task);
    FogCameraWork *work = WEATHER_TASK_GetWorkBuffer(task);

    work->fogChangeStarted = 0;
    work->weatherId = 10;
    work->fogSlope = gFogSlopeByCameraState[cameraState];
    work->fogOffset = gFogOffsetByCameraState[cameraState];
    WEATHER_TASK_InitFog(task, work->fogSlope, 0x7fdf, variant);
    return 1;
}

/* Begin stage of weather id 11. */
int WEATHER_FOG_BeginKind11(WeatherTaskSys *task, int variant)
{
    int cameraState = WEATHER_TASK_GetCameraState(task);
    FogCameraWork *work = WEATHER_TASK_GetWorkBuffer(task);

    work->fogChangeStarted = 0;
    work->weatherId = 11;
    work->fogSlope = gFogSlopeByCameraState[cameraState];
    work->fogOffset = gFogOffsetByCameraState[cameraState];
    WEATHER_TASK_InitFog(task, work->fogSlope, 0x7fdf, variant);
    return 1;
}

/* Begin stage of weather id 13. */
int WEATHER_FOG_BeginKind13(WeatherTaskSys *task, int variant)
{
    int cameraState = WEATHER_TASK_GetCameraState(task);
    FogCameraWork *work = WEATHER_TASK_GetWorkBuffer(task);

    work->fogChangeStarted = 0;
    work->weatherId = 13;
    work->fogSlope = gFogSlopeByCameraState[cameraState];
    work->fogOffset = gFogOffsetByCameraState[cameraState];
    WEATHER_TASK_InitFog(task, work->fogSlope, 0x7fdf, variant);
    return 1;
}

/* Begin stage of weather id 14. */
int WEATHER_FOG_BeginKind14(WeatherTaskSys *task, int variant)
{
    int cameraState = WEATHER_TASK_GetCameraState(task);
    FogCameraWork *work = WEATHER_TASK_GetWorkBuffer(task);

    work->fogChangeStarted = 0;
    work->weatherId = 14;
    work->fogSlope = gFogSlopeByCameraState[cameraState];
    work->fogOffset = gFogOffsetByCameraState[cameraState];
    WEATHER_TASK_InitFog(task, work->fogSlope, 0x7fdf, variant);
    return 1;
}

/* Begin particles stage: change the fog and the light of the weather once, then wait for the fog to settle. */
int WEATHER_FOG_BeginParticles(WeatherTaskSys *task, int variant)
{
    FogCameraWork *work = WEATHER_TASK_GetWorkBuffer(task);

    if (work->fogChangeStarted == 0) {
        WEATHER_TASK_ChangeFog(task, work->fogSlope, work->fogOffset, FOG_CHANGE_FRAMES, variant);
        WEATHER_TASK_FadeLight(task, FOG_LIGHT_ARC_ID, func_02014A10(work->weatherId));
        work->fogChangeStarted = work->fogChangeStarted - 1;
    } else if (WEATHER_TASK_IsFogIdle(task) != 0) {
        return 1;
    }
    return 0;
}

/* Begin plain stage: set the fog and the light at once. */
int WEATHER_FOG_BeginPlain(WeatherTaskSys *task, int variant)
{
    FogCameraWork *work;
    work = WEATHER_TASK_GetWorkBuffer(task);
    WEATHER_TASK_InitFog(task, work->fogSlope, work->fogOffset, variant);
    WEATHER_TASK_SetLight(task, 62, func_02014A10(work->weatherId));
    return 1;
}

/* Run stage: nothing to do. */
int func_021EEA04(void)
{
    return 0;
}

/* End particles stage: allow the fog change to start again. */
int WEATHER_FOG_EndParticles(WeatherTaskSys *task)
{
    FogCameraWork *work;
    work = WEATHER_TASK_GetWorkBuffer(task);
    work->fogChangeStarted = 0;
    return 1;
}

/* End fade stage: fade the fog out, then wait for the fog and the particles. */
int WEATHER_FOG_EndFade(WeatherTaskSys *task, int variant)
{
    FogCameraWork *work = WEATHER_TASK_GetWorkBuffer(task);
    int fogIdle;

    if (work->fogChangeStarted == 0) {
        work->fogChangeStarted = work->fogChangeStarted - 1;
        WEATHER_TASK_ChangeFogOffset(task, FOG_END_OFFSET, FOG_END_FRAMES, variant);
    } else {
        if (variant != 0) {
            fogIdle = WEATHER_TASK_IsFogIdle(task);
        } else {
            fogIdle = 1;
        }
        if (fogIdle != 0 && WEATHER_TASK_GetParticleCount(task) == 0) {
            return 1;
        }
    }
    return 0;
}

/* End finish stage: switch the fog off and reset the light. */
int WEATHER_FOG_EndFinish(struct WeatherTaskSys *task, int variant)
{
    WEATHER_TASK_DisableFog(task, variant);
    WEATHER_TASK_ResetLight(task, variant);
    return 1;
}
