/*
 * file:     weather_fog.c
 * unit:     yes
 * function: func_021EE740, func_021EE770, func_021EE7C0, func_021EE7EC, func_021EE7F0, func_021EE800, func_021EE84C, func_021EE864, func_021EE868, func_021EE8B0, func_021EE8F8, func_021EE940, func_021EE988, func_021EE9D8, func_021EEA04, func_021EEA08, func_021EEA18, func_021EEA64
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
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2148  0x021A2148  thumb  ov021
 *   d_021EEA80     0x021EEA80  data  ov028  a1
 *   d_021EEAA4     0x021EEAA4  data  ov028  a4
 */
#include "../ov021/weather_task_types.h"
#include "weather_fog_types.h"

/* Weather task services (ov021). */
void *func_021A21B8(WeatherTaskSys *task);
void func_021A22E0(WeatherTaskSys *task, int slope, int offset, int phase);
void func_021A232C(WeatherTaskSys *task, int slope, int offset, int frames, int mode);
int func_021A2108(WeatherTaskSys *task, int arcId, int memberId);
int func_021A23B0(WeatherTaskSys *task);
int func_021A2114(WeatherTaskSys *task, int arcId, u32 memberId);
void func_021A2390(WeatherTaskSys *task, int endOffset, int frames, int mode);
int func_021A21BC(WeatherTaskSys *task);
void func_021A231C(WeatherTaskSys *task, int phase);
void func_021A2120(WeatherTaskSys *task, int phase);
int func_021A2148(WeatherTaskSys *task);
u16 func_02014A10(u32 weatherId);

/* Weather id 9 (fixed fog). */
int func_021EE740(WeatherTaskSys *task, int variant);
int func_021EE770(WeatherTaskSys *task, int variant);
int func_021EE7C0(WeatherTaskSys *task, int variant);
int func_021EE7EC(void);
int func_021EE7F0(WeatherTaskSys *task);
int func_021EE800(WeatherTaskSys *task, int variant);
int func_021EE84C(WeatherTaskSys *task, int variant);
void func_021EE864(void);
/* Weather ids 10, 11, 13 and 14 (fog from the camera state). */
int func_021EE868(WeatherTaskSys *task, int variant);
int func_021EE8B0(WeatherTaskSys *task, int variant);
int func_021EE8F8(WeatherTaskSys *task, int variant);
int func_021EE940(WeatherTaskSys *task, int variant);
int func_021EE988(WeatherTaskSys *task, int variant);
int func_021EE9D8(WeatherTaskSys *task, int variant);
int func_021EEA04(void);
int func_021EEA08(WeatherTaskSys *task);
int func_021EEA18(WeatherTaskSys *task, int variant);

/* Fog slope per camera state. */
extern unsigned char d_021EEA80[];
/* Fog offset per camera state. */
extern int d_021EEAA4[];
/* Begin stage: set the fog up. */
int func_021EE740(WeatherTaskSys *task, int variant)
{
    FogFixedWork *work;
    work = func_021A21B8(task);
    func_021A22E0(task, 9, 0x7FDF, variant);
    work->fogChangeStarted = 0;
    work->fogSlope = 9;
    work->fogOffset = 0x7F78;
    return 1;
}

/* Begin particles stage: change the fog and the light once, then wait for the fog to settle. */
int func_021EE770(WeatherTaskSys *task, int variant)
{
    FogFixedWork *work = func_021A21B8(task);

    if (work->fogChangeStarted == 0) {
        func_021A232C(task, work->fogSlope, work->fogOffset, FOG_CHANGE_FRAMES, variant);
        func_021A2108(task, FOG_LIGHT_ARC_ID, func_02014A10(9));
        work->fogChangeStarted = work->fogChangeStarted - 1;
    } else if (func_021A23B0(task) != 0) {
        return 1;
    }
    return 0;
}

/* Begin plain stage: set the fog and the light at once. */
int func_021EE7C0(WeatherTaskSys *task, int variant)
{
    FogFixedWork *work;
    work = func_021A21B8(task);
    func_021A22E0(task, work->fogSlope, work->fogOffset, variant);
    func_021A2114(task, 62, func_02014A10(9));
    return 1;
}

/*
 * Unlabelled 4-byte Thumb leaf (`movs r0,#0; bx lr`), emitted as a data word
 * by disasm.py because it saves no lr. A standalone slot: it follows the
 * `pop {r3,r4,r5,pc}` end of func_021EE7E8 and precedes func_021EE7F0.
 */
/* Run stage: nothing to do. */
int func_021EE7EC(void)
{
    return 0;
}

/* End particles stage: allow the fog change to start again. */
int func_021EE7F0(WeatherTaskSys *task)
{
    FogFixedWork *work;
    work = func_021A21B8(task);
    work->fogChangeStarted = 0;
    return 1;
}

/* End fade stage: fade the fog out, then wait for the fog and the particles. */
int func_021EE800(WeatherTaskSys *task, int variant)
{
    FogFixedWork *work = func_021A21B8(task);
    int fogChangeStarted = work->fogChangeStarted;
    int fogIdle;

    if (fogChangeStarted == 0) {
        work->fogChangeStarted = fogChangeStarted - 1;
        func_021A2390(task, FOG_END_OFFSET, FOG_END_FRAMES, variant);
    } else {
        if (variant != 0)
            fogIdle = func_021A23B0(task);
        else
            fogIdle = 1;
        if (fogIdle != 0) {
            if (func_021A21BC(task) == 0)
                return 1;
        }
    }
    return 0;
}

/* End finish stage: switch the fog off and reset the light. */
int func_021EE84C(WeatherTaskSys *task, int variant)
{
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    return 1;
}

/* Particle update: this kind has no particles. */
void func_021EE864(void)
{
}

/* Begin stage of weather id 10: fog from the camera state. */
int func_021EE868(WeatherTaskSys *task, int variant)
{
    int cameraState = func_021A2148(task);
    FogCameraWork *work = func_021A21B8(task);

    work->fogChangeStarted = 0;
    work->weatherId = 10;
    work->fogSlope = d_021EEA80[cameraState];
    work->fogOffset = d_021EEAA4[cameraState];
    func_021A22E0(task, work->fogSlope, 0x7fdf, variant);
    return 1;
}

/* Begin stage of weather id 11. */
int func_021EE8B0(WeatherTaskSys *task, int variant)
{
    int cameraState = func_021A2148(task);
    FogCameraWork *work = func_021A21B8(task);

    work->fogChangeStarted = 0;
    work->weatherId = 11;
    work->fogSlope = d_021EEA80[cameraState];
    work->fogOffset = d_021EEAA4[cameraState];
    func_021A22E0(task, work->fogSlope, 0x7fdf, variant);
    return 1;
}

/* Begin stage of weather id 13. */
int func_021EE8F8(WeatherTaskSys *task, int variant)
{
    int cameraState = func_021A2148(task);
    FogCameraWork *work = func_021A21B8(task);

    work->fogChangeStarted = 0;
    work->weatherId = 13;
    work->fogSlope = d_021EEA80[cameraState];
    work->fogOffset = d_021EEAA4[cameraState];
    func_021A22E0(task, work->fogSlope, 0x7fdf, variant);
    return 1;
}

/* Begin stage of weather id 14. */
int func_021EE940(WeatherTaskSys *task, int variant)
{
    int cameraState = func_021A2148(task);
    FogCameraWork *work = func_021A21B8(task);

    work->fogChangeStarted = 0;
    work->weatherId = 14;
    work->fogSlope = d_021EEA80[cameraState];
    work->fogOffset = d_021EEAA4[cameraState];
    func_021A22E0(task, work->fogSlope, 0x7fdf, variant);
    return 1;
}

/* Begin particles stage: change the fog and the light of the weather once, then wait for the fog to settle. */
int func_021EE988(WeatherTaskSys *task, int variant)
{
    FogCameraWork *work = func_021A21B8(task);

    if (work->fogChangeStarted == 0) {
        func_021A232C(task, work->fogSlope, work->fogOffset, FOG_CHANGE_FRAMES, variant);
        func_021A2108(task, FOG_LIGHT_ARC_ID, func_02014A10(work->weatherId));
        work->fogChangeStarted = work->fogChangeStarted - 1;
    } else if (func_021A23B0(task) != 0) {
        return 1;
    }
    return 0;
}

/* Begin plain stage: set the fog and the light at once. */
int func_021EE9D8(WeatherTaskSys *task, int variant)
{
    FogCameraWork *work;
    work = func_021A21B8(task);
    func_021A22E0(task, work->fogSlope, work->fogOffset, variant);
    func_021A2114(task, 62, func_02014A10(work->weatherId));
    return 1;
}

/* Run stage: nothing to do. */
int func_021EEA04(void)
{
    return 0;
}

/* End particles stage: allow the fog change to start again. */
int func_021EEA08(WeatherTaskSys *task)
{
    FogCameraWork *work;
    work = func_021A21B8(task);
    work->fogChangeStarted = 0;
    return 1;
}

/* End fade stage: fade the fog out, then wait for the fog and the particles. */
int func_021EEA18(WeatherTaskSys *task, int variant)
{
    FogCameraWork *work = func_021A21B8(task);
    int fogIdle;

    if (work->fogChangeStarted == 0) {
        work->fogChangeStarted = work->fogChangeStarted - 1;
        func_021A2390(task, FOG_END_OFFSET, FOG_END_FRAMES, variant);
    } else {
        if (variant != 0) {
            fogIdle = func_021A23B0(task);
        } else {
            fogIdle = 1;
        }
        if (fogIdle != 0 && func_021A21BC(task) == 0) {
            return 1;
        }
    }
    return 0;
}

/* End finish stage: switch the fog off and reset the light. */
int func_021EEA64(struct WeatherTaskSys *task, int variant)
{
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    return 1;
}
