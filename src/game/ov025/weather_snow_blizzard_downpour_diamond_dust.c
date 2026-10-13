/*
 * file:     weather_snow_blizzard_downpour_diamond_dust.c
 * unit:     yes
 * function: func_021EE740, func_021EE798, func_021EE810, func_021EE888, func_021EE8B0, func_021EE8EC, func_021EE968, func_021EE980, func_021EEA34, func_021EEB0C, func_021EEB74, func_021EEBE4, func_021EEC64, func_021EECB0, func_021EECEC, func_021EED58, func_021EED78, func_021EEE04, func_021EEEE0, func_021EEF94, func_021EEFF0, func_021EF068, func_021EF0D0, func_021EF100, func_021EF12C, func_021EF1A4, func_021EF1C4, func_021EF2D4, func_021EF3BC, func_021EF404, func_021EF47C, func_021EF4E4, func_021EF514, func_021EF538, func_021EF5B0, func_021EF5D0, func_021EF634
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
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A244C  0x021A244C  thumb  ov021
 *   func_021A2564  0x021A2564  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2254  0x021A2254  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 *   _u32_div_f  0x0209C2B0  arm
 *   d_021EF790  0x021EF790  data  ov025  a1
 *   func_020056EC  0x020056EC  thumb
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   d_021EF770  0x021EF770  data  ov025  a4
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   d_021EF780     0x021EF780  data   a4
 *   func_021A2190 0x021A2190 thumb ov021
 *   func_021A21A0 0x021A21A0 thumb ov021
 *   d_021EF765    0x021EF765 data a1
 *   d_021EF75C    0x021EF75C data ov025 a1
 *   func_021A26C4  0x021A26C4  thumb  ov021
 *   CLACT_GetActorAnimSeqCount  0x0204B918  arm
 */
#include "../ov021/weather_task_types.h"
#include "weather_snow_blizzard_downpour_diamond_dust_types.h"

extern const s8 d_021EF790[];
extern const int d_021EF770[];
extern const int d_021EF780[];
extern const s8 d_021EF765[];
extern const s8 d_021EF75C[];
/* ---- Snow ---- */

/* Snow, stage begin: slow spawner, fog and light fade parameters. */
int func_021EE740(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work = func_021A21B8(task);

    func_021A21F8(task, 1, 0x12, 1, 0x10, -3, 1, 0, func_021EEA34);
    work->staggerSpawn = 0;
    work->ending = 0;
    func_021A22E0(task, 8, 0x7FDF, variant);
    work->fadeDelay = 8;
    func_021A2424(task);
    return 1;
}

/* Snow, stage fade in: after a short delay fades fog and light, then waits for the spawner and the fade. */
int func_021EE798(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;

    work = func_021A21B8(task);
    spawnerReady = func_021A223C(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            func_021A232C(task, 8, 0x7F5F, 0x5A, variant);
            func_021A2108(task, 0x3E, func_02014A10(1));
        }
    } else if (func_021A23B0(task) != 0 && spawnerReady != 0) {
        return 1;
    }
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Snow, stage begin at once: fills the screen with flakes and sets fog and light without a fade. */
int func_021EE810(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work = func_021A21B8(task);

    func_021A21F8(task, 1, 0x10, 1, 0x10, -3, 1, 0, func_021EEA34);
    work->staggerSpawn = 1;
    work->ending = 0;
    func_021A22E0(task, 8, 0x7F5F, variant);
    func_021A2254(task, func_021EEA34, 0x14, 1, 0x12, heapId);
    func_021A2114(task, 0x3E, func_02014A10(1));
    return 1;
}

/* Snow, stage run: spawner step and camera scroll. */
int func_021EE888(WeatherTaskSys *task, int variant, int heapId)
{
    int scrollX;
    int scrollY;

    func_021A2248(task, heapId);
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Snow, stage stop spawning. */
int func_021EE8B0(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work;
    int scrollX;
    int scrollY;

    work = func_021A21B8(task);
    func_021A2228(task, 0, 18, 3, -1);
    work->fadeDelay = 16;
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 1;
}

/* Snow, stage fade out: after a delay fades fog and light out, then waits until the flakes are gone. */
int func_021EE8EC(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSnowWork *work;
    int spawnerReady;
    int fadeDone;
    int scrollX;
    int scrollY;

    work = func_021A21B8(task);
    spawnerReady = func_021A223C(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            func_021A2390(task, 0x7FDF, 0x5A, variant);
        }
    } else {
        if (variant != 0) {
            fadeDone = func_021A23B0(task);
        } else {
            fadeDone = 1;
        }
        if (fadeDone != 0 && spawnerReady != 0) {
            work->ending = 1;
            if (func_021A21BC(task) == 0) {
                return 1;
            }
        }
    }
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/*
 * Snow, stage finish: releases fog and light.
 * extent: trailing two-byte zero alignment padding at 0x021EE97E.
 */
int func_021EE968(WeatherTaskSys *task, int variant, int heapId)
{
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    return 1;
}

/* Snow, particle update: sways with the wobble table and falls slowly; removed after the weather ended or at the screen edge. */
void func_021EE980(WeatherParticle *particle)
{
    WeatherSnowFlake *flake;
    int wasDying;
    int *ending;
    WeatherScreenPos pos;

    flake = (WeatherSnowFlake *)func_021A2630(particle);
    func_021A2638(particle);
    wasDying = flake->dying;
    ending = flake->ending;
    if (wasDying == 0) {
        if (*ending != 0) {
            flake->dying = wasDying + 1;
        }
    } else {
        flake->dyingFrames = flake->dyingFrames - 1;
        if (flake->dyingFrames < 0) {
            func_021A21E0(particle);
            return;
        }
    }
    func_021A2640(particle, &pos);
    pos.x = pos.x + d_021EF790[flake->wobbleIndex];
    if (flake->fallAccum > flake->fallThreshold) {
        pos.y = pos.y + 1;
        flake->fallAccum = flake->fallAccum % flake->fallThreshold;
    }
    func_021A2654(particle, &pos);
    flake->fallAccum = flake->fallAccum + 8;
    flake->wobbleIndex = (unsigned)(flake->wobbleIndex + 1) % 337u;
    if ((pos.y < -284 && pos.y > -296) || (pos.y > 212 && pos.y < 232)) {
        *flake->staggerSpawn = 1;
        func_021A21E0(particle);
    }
}

/* Snow, spawner callback: creates flakes above the screen. */
void func_021EEA34(WeatherTaskSys *task, s32 count, u32 heapId)
{
    WeatherSnowWork *work;
    int i;
    WeatherParticle *particle;
    WeatherSnowFlake *flake;
    Actor *actor;
    WeatherScreenPos pos;

    work = func_021A21B8(task);
    for (i = 0; i < count; i++) {
        particle = func_021A21C8(task, heapId);
        if (particle == 0) {
            return;
        }
        flake = (WeatherSnowFlake *)func_021A2630(particle);
        actor = func_021A2638(particle);
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
        func_021A2654(particle, &pos);
    }
}

/* ---- Blizzard ---- */

/* Blizzard, stage begin: spawner, fog and light parameters, wind sound. */
int func_021EEB0C(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work = func_021A21B8(task);

    func_021A21F8(task, 1, 6, 1, 2, -2, 2, 1, (WeatherSpawnFunc)func_021EEE04);
    func_021A22E0(task, 4, 0x7FFF, variant);
    work->fadeDelay = 8;
    work->windPhase = 0;
    work->scrollX = 0;
    work->scrollY = 0;
    work->scrollStep = 0;
    func_021A2424(task);
    func_021A25BC(task, 0x6E3);
    return 1;
}

/* Blizzard, stage fade in: after a short delay fades fog and light, then shows the fog layer. */
int func_021EEB74(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work;
    int spawnerReady;

    work = func_021A21B8(task);
    spawnerReady = func_021A223C(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            func_021A232C(task, 4, 0x7B18, 0x5A, variant);
            func_021A2108(task, 0x3E, func_02014A10(4));
        }
    } else if (func_021A23B0(task) != 0 && spawnerReady != 0) {
        func_021A2160(task, 1, 0);
        return 1;
    }
    func_021EEEE0(task, work);
    return 0;
}

/* Blizzard, stage begin at once: fills the screen with flakes and shows the fog layer. */
int func_021EEBE4(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work = func_021A21B8(task);

    func_021A21F8(task, 1, 2, 1, 2, -2, 2, 1, (WeatherSpawnFunc)func_021EEE04);
    func_021A22E0(task, 4, 0x7B18, variant);
    work->windPhase = 0;
    work->scrollX = 0;
    work->scrollY = 0;
    func_021A2254(task, (WeatherSpawnFunc)func_021EEE04, 0x14, 2, 2, heapId);
    func_021A2160(task, 1, 0);
    func_021A2114(task, 0x3E, func_02014A10(4));
    return 1;
}

/* Blizzard, stage run: spawns an extra flake while the wind blows leftwards. */
int func_021EEC64(WeatherTaskSys *task, int variant, u16 heapId)
{
    WeatherBlizzardWork *work;

    work = func_021A21B8(task);
    if (func_021A2248(task, heapId) != 0) {
        if (d_021EF770[work->windPhase / 256] <= -8) {
            func_021EEE04(task, 1, heapId);
        }
    }
    func_021EEEE0(task, work);
    return 0;
}

/* Blizzard, stage stop spawning: hides the fog layer and stops the wind sound. */
int func_021EECB0(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work;

    work = func_021A21B8(task);
    func_021A2228(task, 0, 3, 1, -1);
    work->fadeDelay = 10;
    func_021EEEE0(task, work);
    func_021A2160(task, 0, 0);
    func_021A25CC(task);
    return 1;
}

/* Blizzard, stage fade out. */
int func_021EECEC(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherBlizzardWork *work;
    int spawnerReady;
    int fadeDone;

    work = func_021A21B8(task);
    spawnerReady = func_021A223C(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            func_021A2390(task, 0x7FFF, 0x3C, variant);
        }
    } else {
        if (variant != 0) {
            fadeDone = func_021A23B0(task);
        } else {
            fadeDone = 1;
        }
        if (fadeDone != 0 && spawnerReady != 0) {
            work->scrollX = 1;
            if (func_021A21BC(task) == 0) {
                return 1;
            }
        }
    }
    func_021EEEE0(task, work);
    return 0;
}

/*
 * Blizzard, stage finish: releases fog and light.
 * extent: trailing two-byte zero alignment padding at 0x021EED76.
 */
int func_021EED58(WeatherTaskSys *task, int variant, int heapId)
{
    func_021A21B8(task);
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    return 1;
}

/* Blizzard, particle update: flies with the wind, speeding up, and is removed after its lifetime. */
void func_021EED78(WeatherParticle *particle)
{
    WeatherBlizzardFlake *flake;
    Actor *actor;
    WeatherScreenPos pos;

    flake = (WeatherBlizzardFlake *)func_021A2630(particle);
    actor = func_021A2638(particle);
    func_0204B454(actor, &pos, 0);
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
        func_0204B404(actor, &pos, 0);
        break;
    case WEATHER_BLIZZARD_FLAKE_REMOVE:
        func_021A21E0(particle);
        break;
    }
}

/*
 * Blizzard, spawner callback: creates flakes at the left edge, moving with the current wind.
 * note:     heapId is narrow (u16/s16/u8 all give EXACT; int puts its home store
 *           third instead of first): func_021A21C8 only forwards it, so no
 *           callee fixes the exact width. const on the two tables lets the
 *           indexed loads hoist out of the loop past the stores through flake.
 */
void func_021EEE04(WeatherTaskSys *task, s32 count, u16 heapId)
{
    WeatherBlizzardWork *work;
    int windIndex;
    int i;
    WeatherParticle *particle;
    WeatherBlizzardFlake *flake;
    Actor *actor;
    int size;
    WeatherScreenPos pos;

    work = func_021A21B8(task);
    if (++work->windPhase >= 0x400) {
        work->windPhase = 0;
    }
    windIndex = work->windPhase / 256;
    for (i = 0; i < count; i++) {
        particle = func_021A21C8(task, heapId);
        if (particle == 0) {
            return;
        }
        flake = (WeatherBlizzardFlake *)func_021A2630(particle);
        actor = func_021A2638(particle);
        flake->age = 0;
        flake->lifetime = func_020056EC(3) + 9;
        size = func_020056EC(4);
        CLACT_SetActorAnimIndex(actor, (u16)size);
        flake->speedX = (size + 1) * d_021EF770[windIndex];
        flake->speedY = d_021EF780[windIndex] * (size + 1);
        flake->state = WEATHER_BLIZZARD_FLAKE_MOVING;
        if (size == 3) {
            flake->speedX = flake->speedX + d_021EF770[windIndex];
            flake->speedY = flake->speedY + d_021EF780[windIndex];
        }
        flake->accelX = d_021EF770[windIndex];
        pos.x = -func_020056EC(0x18);
        pos.y = func_020056EC(0xA8) - 0x20;
        func_0204B404(actor, &pos, 0);
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
void func_021EEEE0(WeatherTaskSys *task, WeatherBlizzardWork *work)
{
    int cameraDx;
    int cameraDy;
    int index;
    int step;

    func_021A244C(task, &cameraDx, &cameraDy);
    func_021A2564(task, cameraDx, cameraDy);
    step = work->scrollStep;
    index = step / 28;
    step = (unsigned)(step + 1) % 252u;
    work->scrollStep = step;
    work->scrollX = work->scrollX + d_021EF765[index] - cameraDx / 2;
    work->scrollY = work->scrollY + d_021EF75C[index] - cameraDy / 2;
    if (work->scrollX < 0) {
        work->scrollX = work->scrollX + 256;
    }
    if (work->scrollY < 0) {
        work->scrollY = work->scrollY + 256;
    }
    work->scrollX = work->scrollX % 256;
    work->scrollY = work->scrollY % 256;
    func_021A2190(task, -work->scrollX, 0);
    func_021A21A0(task, -work->scrollY, 0);
}

/* ---- Downpour ---- */

/* Downpour, stage begin: spawner, fog and light parameters, rain sound. */
int func_021EEF94(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDownpourWork *work;

    work = func_021A21B8(task);
    func_021A21F8(task, 0, 8, 1, 1, -4, 2, 1, func_021EF2D4);
    func_021A22E0(task, 9, 0x7FDF, variant);
    work->fadeDelay = 1;
    func_021A2424(task);
    func_021A25BC(task, 0x6E4);
    return 1;
}

/* Downpour, stage fade in. */
int func_021EEFF0(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDownpourWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;

    work = func_021A21B8(task);
    spawnerReady = func_021A223C(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            func_021A232C(task, 9, 0x7F80, 0x3C, variant);
            func_021A2108(task, 0x3E, func_02014A10(5));
        }
    } else if (func_021A23B0(task) != 0 && spawnerReady != 0) {
        return 1;
    }
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Downpour, stage begin at once. */
int func_021EF068(WeatherTaskSys *task, int variant, int heapId)
{
    func_021A21B8(task);
    func_021A21F8(task, 1, 1, 1, 1, -4, 2, 1, func_021EF2D4);
    func_021A22E0(task, 9, 0x7F80, variant);
    func_021A2254(task, func_021EF2D4, 0x14, 10, 1, heapId);
    func_021A2114(task, 0x3E, func_02014A10(5));
    return 1;
}

/* Downpour, stage run. */
int func_021EF0D0(WeatherTaskSys *task, int variant, int heapId)
{
    int scrollX;
    int scrollY;

    func_021A21B8(task);
    func_021A2248(task, heapId);
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Downpour, stage stop spawning: stops the rain sound. */
int func_021EF100(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDownpourWork *work;

    work = func_021A21B8(task);
    func_021A2228(task, 0, 8, 4, -1);
    work->fadeDelay = 1;
    func_021A25CC(task);
    return 1;
}

/* Downpour, stage fade out. */
int func_021EF12C(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDownpourWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;
    int fadeDone;

    work = func_021A21B8(task);
    spawnerReady = func_021A223C(task, heapId);
    if (work->fadeDelay > 0) {
        work->fadeDelay = work->fadeDelay - 1;
        if (work->fadeDelay == 0) {
            func_021A2390(task, 0x7FDF, 0x3C, variant);
        }
    } else {
        fadeDone = (variant != 0) ? func_021A23B0(task) : 1;
        if (fadeDone != 0 && spawnerReady != 0 && func_021A21BC(task) == 0) {
            return 1;
        }
    }
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Downpour, stage finish: releases fog and light. */
int func_021EF1A4(WeatherTaskSys *task, int variant, int heapId)
{
    func_021A21B8(task);
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    return 1;
}

/* Downpour, particle update: a drop falls fast for a few frames, then splashes and fades. */
void func_021EF1C4(WeatherParticle *particle)
{
    WeatherDownpourDrop *drop;
    Actor *actor;
    WeatherScreenPos pos;

    drop = (WeatherDownpourDrop *)func_021A2630(particle);
    actor = func_021A2638(particle);
    func_021A2640(particle, &pos);
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
        func_021A2654(particle, &pos);
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
        func_021A26C4(particle, &pos);
        if (drop->age-- <= 0) {
            drop->state = WEATHER_DOWNPOUR_DROP_REMOVE;
        }
        break;
    case WEATHER_DOWNPOUR_DROP_REMOVE:
        func_021A21E0(particle);
        break;
    }
}

/* Downpour, spawner callback: creates drops of three sizes along the top of the screen. */
void func_021EF2D4(WeatherTaskSys *task, s32 count, u32 heapId)
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

    func_021A21B8(task);
    for (i = 0; i < count; i++) {
        particle = func_021A21C8(task, heapId);
        if (particle == 0) {
            return;
        }
        drop = (WeatherDownpourDrop *)func_021A2630(particle);
        actor = func_021A2638(particle);
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
        func_021A2654(particle, &pos);
        drop->splashSeed = random;
    }
}

/* ---- Diamond dust ---- */

/* Diamond dust, stage begin. */
int func_021EF3BC(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDiamondDustWork *work;

    work = func_021A21B8(task);
    func_021A21F8(task, 2, 0x10, 0x14, 2, -2, 4, 2, func_021EF634);
    func_021A22E0(task, 8, 0x7FFF, variant);
    work->fadeState = 0;
    return 1;
}

/* Diamond dust, stage fade in: issues the fog and light fade once, then waits for it. */
int func_021EF404(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDiamondDustWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;

    work = func_021A21B8(task);
    spawnerReady = func_021A223C(task, heapId);
    if (work->fadeState == 0) {
        work->fadeState = work->fadeState - 1;
        func_021A232C(task, 8, 0x7F57, 0x5A, variant);
        func_021A2108(task, 0x3E, func_02014A10(8));
    } else if (func_021A23B0(task) != 0 && spawnerReady != 0) {
        return 1;
    }
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Diamond dust, stage begin at once. */
int func_021EF47C(WeatherTaskSys *task, int variant, int heapId)
{
    func_021A21B8(task);
    func_021A21F8(task, 0x14, 2, 0x14, 2, -2, 4, 2, func_021EF634);
    func_021A22E0(task, 8, 0x7F57, variant);
    func_021A2254(task, func_021EF634, 0x14, 10, 1, heapId);
    func_021A2114(task, 0x3E, func_02014A10(8));
    return 1;
}

/* Diamond dust, stage run. */
int func_021EF4E4(WeatherTaskSys *task, int variant, int heapId)
{
    int scrollX;
    int scrollY;

    func_021A21B8(task);
    func_021A2248(task, heapId);
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Diamond dust, stage stop spawning. */
int func_021EF514(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDiamondDustWork *work;

    work = func_021A21B8(task);
    func_021A2228(task, 0, 16, 2, -2);
    work->fadeState = 100;
    return 1;
}

/* Diamond dust, stage fade out: waits 100 frames, then fades fog and light out. */
int func_021EF538(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherDiamondDustWork *work;
    int spawnerReady;
    int scrollX;
    int scrollY;
    int fadeDone;

    work = func_021A21B8(task);
    spawnerReady = func_021A223C(task, heapId);
    if (work->fadeState > 0) {
        work->fadeState = work->fadeState - 1;
        if (work->fadeState == 0) {
            func_021A2390(task, 0x7FFF, 0x78, variant);
        }
    } else {
        fadeDone = (variant != 0) ? func_021A23B0(task) : 1;
        if (fadeDone != 0 && spawnerReady != 0 && func_021A21BC(task) == 0) {
            return 1;
        }
    }
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Diamond dust, stage finish: releases fog and light. */
int func_021EF5B0(WeatherTaskSys *task, int variant, int heapId)
{
    func_021A21B8(task);
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    return 1;
}

/* Diamond dust, particle update: drifts one pixel at a time, removed after its lifetime. */
void func_021EF5D0(WeatherParticle *particle)
{
    WeatherDiamondDustSparkle *sparkle;
    WeatherScreenPos pos;

    sparkle = (WeatherDiamondDustSparkle *)func_021A2630(particle);
    func_021A2638(particle);
    func_021A2640(particle, &pos);
    sparkle->age = sparkle->age + 1;
    if (sparkle->age % sparkle->xInterval == 0) {
        pos.x = pos.x + (s16)sparkle->stepX;
    }
    if (sparkle->age % sparkle->yInterval == 0) {
        pos.y = pos.y + (s16)sparkle->stepY;
    }
    if (sparkle->age >= sparkle->lifetime) {
        func_021A21E0(particle);
    }
}

/*
 * Diamond dust, spawner callback: creates sparkles at random places; those
 * inside a diagonal strip live twice as long.
 */
void func_021EF634(WeatherTaskSys *task, s32 count, u32 heapId)
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

    func_021A21B8(task);
    for (i = 0; i < count; i++) {
        particle = func_021A21C8(task, heapId);
        if (particle == 0) {
            return;
        }
        sparkle = (WeatherDiamondDustSparkle *)func_021A2630(particle);
        actor = func_021A2638(particle);
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
        func_021A2654(particle, &pos);
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
