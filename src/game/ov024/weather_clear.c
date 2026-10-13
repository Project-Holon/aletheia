/*
 * file:     weather_clear.c
 * unit:     yes
 * function: func_021EE740, func_021EE788, func_021EE7F0, func_021EE838, func_021EE83C, WEATHER_CLEAR_EndFade, func_021EE874
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
 *   func_021A23D4  0x021A23D4  thumb  ov021
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A23E8  0x021A23E8  thumb  ov021
 *   func_021A2400  0x021A2400  thumb  ov021
 *   func_021A240C  0x021A240C  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A23F4  0x021A23F4  thumb  ov021
 *   func_021A2418  0x021A2418  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A231C  0x021A231C  thumb  ov021
 *   func_021A2120  0x021A2120  thumb  ov021
 */
#include "../ov021/weather_task_types.h"
#include "weather_clear_types.h"

/* Clear weather: no particles, only the zone fog is faded to white. */

/* Stage begin: waits for the zone fog to be idle, then starts the fog. */
int func_021EE740(WeatherTaskSys *task, int variant, int heapId)
{
    if (func_021A23D4(task)) {
        return 0;
    }
    ((WeatherZoneFogWork *)func_021A21B8(task))->fadeStarted = 0;
    if (func_021A23E8(task)) {
        func_021A2400(task);
        func_021A22E0(task, func_021A240C(task), 0x7FFF, variant);
    }
    return 1;
}

/* Stage fade in: fades fog and light in once, then waits until both are done. */
int func_021EE788(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherZoneFogWork *work = func_021A21B8(task);
    int endOffset;

    if (work->fadeStarted == 0) {
        if (func_021A23E8(task)) {
            endOffset = func_021A2400(task);
            func_021A232C(task, func_021A240C(task), endOffset, 0xA0, variant);
        }
        if (func_021A23F4(task)) {
            func_021A2108(task, 0x52, func_021A2418(task));
        }
        work->fadeStarted = 1;
    }
    if (func_021A23B0(task)) {
        return 1;
    }
    return 0;
}

/* Stage begin without fade: sets fog and light at once. */
int func_021EE7F0(WeatherTaskSys *task, int variant, int heapId)
{
    int endOffset;

    if (func_021A23E8(task)) {
        endOffset = func_021A2400(task);
        func_021A22E0(task, func_021A240C(task), endOffset, variant);
    }
    if (func_021A23F4(task)) {
        func_021A2114(task, 0x52, func_021A2418(task));
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
    if (func_021A23E8(task)) {
        func_021A2390(task, 0x7FFF, 0x50, variant);
    }
    return 1;
}

/* Stage end fade: waits until the fog fade is done. */
int WEATHER_CLEAR_EndFade(WeatherTaskSys *task, int variant, int heapId)
{
    if (func_021A23B0(task)) {
        return 1;
    }
    return 0;
}

/* Stage end finish: releases the fog and the light. */
int func_021EE874(WeatherTaskSys *task, int variant, int heapId)
{
    if (func_021A23E8(task)) {
        func_021A231C(task, variant);
    }
    if (func_021A23F4(task)) {
        func_021A2120(task, variant);
    }
    return 1;
}
