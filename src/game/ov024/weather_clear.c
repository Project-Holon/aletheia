/*
 * file:     weather_clear.c
 * unit:     yes
 * function: WEATHER_CLEAR_Begin, func_021EE788, func_021EE7F0, func_021EE838, func_021EE83C, WEATHER_CLEAR_EndFade, func_021EE874
 * address:  0x021EE740
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Cleanup (lane WXT): unit_021EE860.c (formerly named DWC_IsValidFriendData, a false vendor match: it is stage slot 6 of the 7-pointer kind table, it calls the weather fade-done check) and the unplaced stage 021EE874 are merged in. Weather id 0, the clear weather: the zone fog only, no particles.
 *
 * symbols:
 *   WEATHER_TASK_IsZoneFogActive  0x021A23D4  thumb  ov021
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_CheckZoneFogA  0x021A23E8  thumb  ov021
 *   WEATHER_TASK_GetZoneFogC  0x021A2400  thumb  ov021
 *   WEATHER_TASK_GetZoneFogD  0x021A240C  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   WEATHER_TASK_CheckZoneFogB  0x021A23F4  thumb  ov021
 *   WEATHER_TASK_GetZoneFogE  0x021A2418  thumb  ov021
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_SetLight  0x021A2114  thumb  ov021
 *   WEATHER_TASK_ChangeFogOffset  0x021A2390  thumb  ov021
 *   WEATHER_TASK_DisableFog  0x021A231C  thumb  ov021
 *   WEATHER_TASK_ResetLight  0x021A2120  thumb  ov021
 */
#include "../ov021/weather_task_types.h"
#include "weather_clear_types.h"

/* Clear weather: no particles, only the zone fog is faded to white. */

/* Stage begin: waits for the zone fog to be idle, then starts the fog. */
int WEATHER_CLEAR_Begin(WeatherTaskSys *task, int variant, int heapId)
{
    if (WEATHER_TASK_IsZoneFogActive(task)) {
        return 0;
    }
    ((WeatherZoneFogWork *)WEATHER_TASK_GetWorkBuffer(task))->fadeStarted = 0;
    if (WEATHER_TASK_CheckZoneFogA(task)) {
        WEATHER_TASK_GetZoneFogC(task);
        WEATHER_TASK_InitFog(task, WEATHER_TASK_GetZoneFogD(task), 0x7FFF, variant);
    }
    return 1;
}

/* Stage fade in: fades fog and light in once, then waits until both are done. */
int func_021EE788(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherZoneFogWork *work = WEATHER_TASK_GetWorkBuffer(task);
    int endOffset;

    if (work->fadeStarted == 0) {
        if (WEATHER_TASK_CheckZoneFogA(task)) {
            endOffset = WEATHER_TASK_GetZoneFogC(task);
            WEATHER_TASK_ChangeFog(task, WEATHER_TASK_GetZoneFogD(task), endOffset, 0xA0, variant);
        }
        if (WEATHER_TASK_CheckZoneFogB(task)) {
            WEATHER_TASK_FadeLight(task, 0x52, WEATHER_TASK_GetZoneFogE(task));
        }
        work->fadeStarted = 1;
    }
    if (WEATHER_TASK_IsFogIdle(task)) {
        return 1;
    }
    return 0;
}

/* Stage begin without fade: sets fog and light at once. */
int func_021EE7F0(WeatherTaskSys *task, int variant, int heapId)
{
    int endOffset;

    if (WEATHER_TASK_CheckZoneFogA(task)) {
        endOffset = WEATHER_TASK_GetZoneFogC(task);
        WEATHER_TASK_InitFog(task, WEATHER_TASK_GetZoneFogD(task), endOffset, variant);
    }
    if (WEATHER_TASK_CheckZoneFogB(task)) {
        WEATHER_TASK_SetLight(task, 0x52, WEATHER_TASK_GetZoneFogE(task));
    }
    return 1;
}

/*
 * Unlabelled 4-byte Thumb leaf (`movs r0,#0; bx lr`), emitted as a data word
 * by disasm.py because it saves no lr. Sits alone between func_021EE7F0 and
 * func_021EE83C, extent 4.
 */
/* Stage run: nothing to do per frame. */
int func_021EE838(WeatherTaskSys *task, int variant, int heapId)
{
    return 0;
}

/* Stage end: fades the fog out. */
int func_021EE83C(WeatherTaskSys *task, int variant, int heapId)
{
    if (WEATHER_TASK_CheckZoneFogA(task)) {
        WEATHER_TASK_ChangeFogOffset(task, 0x7FFF, 0x50, variant);
    }
    return 1;
}

/* Stage end fade: waits until the fog fade is done. */
int WEATHER_CLEAR_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    if (WEATHER_TASK_IsFogIdle(task)) {
        return 1;
    }
    return 0;
}

/* Stage end finish: releases the fog and the light. */
int func_021EE874(WeatherTaskSys *task, int variant, int heapId)
{
    if (WEATHER_TASK_CheckZoneFogA(task)) {
        WEATHER_TASK_DisableFog(task, variant);
    }
    if (WEATHER_TASK_CheckZoneFogB(task)) {
        WEATHER_TASK_ResetLight(task, variant);
    }
    return 1;
}
