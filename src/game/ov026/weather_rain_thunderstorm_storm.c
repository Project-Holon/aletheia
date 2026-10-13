/*
 * file:     weather_rain_thunderstorm_storm.c
 * unit:     yes
 * function: func_021EE740, func_021EE790, func_021EE814, func_021EE888, func_021EE8B8, func_021EE8E4, func_021EE95C, func_021EE97C, func_021EEA18, func_021EEAEC, func_021EEB44, func_021EEC5C, func_021EECD8, func_021EED10, func_021EED44, func_021EEDB0, func_021EEDD8, func_021EEE38, func_021EEF0C, func_021EEF58, func_021EEFA8, func_021EF078, func_021EF104, func_021EF134, func_021EF180, func_021EF1D4, func_021EF1F4, func_021EF220, func_021EF2D8, func_021EF364, func_021EF3E0, func_021EF454, func_021EF4D0, func_021EF58C, func_021EF614, func_021EF664, func_021EF830, func_021EF920, func_021EF93C, func_021EF950, func_021EF9B0, func_021EF9CC, func_021EF9D8, func_021EFBA4, func_021EFBFC, func_021EFC3C, func_021EFCD4
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
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2424 0x021A2424 thumb ov021
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A232C 0x021A232C thumb ov021
 *   func_021A2108 0x021A2108 thumb ov021
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_021A2390 0x021A2390 thumb ov021
 *   func_021A21BC 0x021A21BC thumb ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A2640 0x021A2640 thumb ov021
 *   func_021A26C4 0x021A26C4 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   func_020056EC  0x020056EC  thumb
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A2154  0x021A2154  thumb  ov021
 *   func_021A2130  0x021A2130  thumb  ov021
 *   func_021A25DC  0x021A25DC  thumb  ov021
 *   func_021A213C  0x021A213C  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   d_021EFD08     0x021EFD08  data  ov026  a4
 *   func_021A2190 0x021A2190 thumb ov021
 *   func_021A21A0 0x021A21A0 thumb ov021
 *   d_021EFDCC 0x021EFDCC data ov026 a4
 *   d_021EFDC0     0x021EFDC0  data  a4
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B954  0x0204B954  arm
 *   func_021A2170  0x021A2170  thumb  ov021
 *   func_021A2180  0x021A2180  thumb  ov021
 *   d_021EFD74     0x021EFD74  data  ov026  a4
 *   d_021EFD78     0x021EFD78  data  ov026  a4
 *   d_021EFD3C     0x021EFD3C  data  ov026  a4
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_021A2604  0x021A2604  thumb  ov021
 *   func_02082BCC 0x02082BCC arm
 *   d_021EFCF9     0x021EFCF9  data  a1
 *   d_021EFD1C     0x021EFD1C  data  a1
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

int func_021EE740(WeatherTaskSys *task, int variant);
int func_021EE790(WeatherTaskSys *task, int variant, int heapId);
int func_021EE814(WeatherTaskSys *task, int variant, u16 heapId);
int func_021EE888(WeatherTaskSys *task, int variant, int heapId);
int func_021EE8B8(WeatherTaskSys *task);
int func_021EE8E4(WeatherTaskSys *task, int variant, int heapId);
int func_021EE95C(WeatherTaskSys *task, int variant);
void func_021EE97C(WeatherParticle *particle);
void func_021EEA18(WeatherTaskSys *task, s32 count, u32 heapId);
int func_021EEAEC(WeatherTaskSys *task, int variant);
int func_021EEB44(WeatherTaskSys *task, int variant, int heapId);
int func_021EEC5C(WeatherTaskSys *task, int variant, u16 heapId);
int func_021EECD8(WeatherTaskSys *task, int variant, int heapId);
int func_021EED10(WeatherTaskSys *task);
int func_021EED44(WeatherTaskSys *task, int variant, int heapId);
int func_021EEDB0(WeatherTaskSys *task, int variant);
void func_021EEDD8(WeatherParticle *particle);
void func_021EEE38(WeatherTaskSys *task, s32 count, u32 heapId);
void func_021EEF0C(WeatherTaskSys *task, WeatherThunderstormWork *work);
int func_021EEF58(WeatherTaskSys *task, int variant);
int func_021EEFA8(WeatherTaskSys *task, int variant, int heapId);
int func_021EF078(WeatherTaskSys *task, int variant, u16 heapId);
int func_021EF104(WeatherTaskSys *task, int variant, int heapId);
int func_021EF134(WeatherTaskSys *task, int variant);
int func_021EF180(WeatherTaskSys *task, int variant, int heapId);
int func_021EF1D4(WeatherTaskSys *task, int variant);
void func_021EF1F4(WeatherParticle *particle);
void func_021EF220(WeatherTaskSys *task, s32 count, u32 heapId);
void func_021EF2D8(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop);
void func_021EF364(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor);
void func_021EF3E0(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop);
void func_021EF454(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor);
void func_021EF4D0(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop);
void func_021EF58C(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor);
void func_021EF614(WeatherTaskSys *task, WeatherStormWork *work, int variant, int silent);
void func_021EF664(WeatherTaskSys *task, WeatherStormWork *work, int variant, int silent);
void func_021EF830(WeatherTaskSys *task, WeatherStormWork *work);
void func_021EF920(WeatherTaskSys *task, WeatherStormWork *work, int variant, int seId);
void func_021EF93C(WeatherStormWork *work);
void func_021EF950(WeatherTaskSys *task, WeatherStormWork *work, int variant);
extern int d_021EFD08[];
extern WeatherStormGustSample d_021EFD74[];
extern WeatherStormGustSample d_021EFD78[];
extern int d_021EFD3C[];
extern u8 d_021EFCF9[];
extern WeatherStormDropInitFunc d_021EFDC0[];
extern WeatherStormDropUpdateFunc d_021EFDCC[];
extern u8 d_021EFD1C[];
/* Rain: begin stage. Sets up the drop spawner, the fog fade-in and the first frame. */
int func_021EE740(WeatherTaskSys *task, int variant)
{
    WeatherRainWork *work;

    work = func_021A21B8(task);
    func_021A21F8(task, 1, 8, 2, 0, -4, 2, 1, func_021EEA18);
    func_021A22E0(task, 8, 0x7FDF, variant);
    work->fogDelay = 1;
    func_021A2424(task);
    return 1;
}

/* Rain: begin-particles stage. Starts the fog change after a delay and ends when the spawner
 * and the fog are done. */
int func_021EE790(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherRainWork *work;
    int spawnerSettled;
    s32 scrollX;
    s32 scrollY;

    work = func_021A21B8(task);
    spawnerSettled = func_021A223C(task, heapId);
    if (work->fogDelay > 0) {
        work->fogDelay = work->fogDelay - 1;
        if (work->fogDelay == 0) {
            func_021A232C(task, 8, 0x7F5F, 0x5A, variant);
            func_021A2108(task, 0x3E, func_02014A10(2));
            func_021A25BC(task, 0x691);
        }
    } else if (func_021A23B0(task) != 0 && spawnerSettled != 0) {
        return 1;
    }
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Rain: begin-plain stage. Starts with the screen already full of drops. */
int func_021EE814(WeatherTaskSys *task, int variant, u16 heapId)
{
    func_021A21B8(task);
    func_021A21F8(task, 2, 0, 2, 0, -4, 2, 1, func_021EEA18);
    func_021A22E0(task, 8, 0x7F5F, variant);
    func_021A2254(task, func_021EEA18, 0x14, 0xA, 1, heapId);
    func_021A25BC(task, 0x691);
    func_021A2114(task, 0x3E, func_02014A10(2));
    return 1;
}

/* Rain: run stage. */
int func_021EE888(WeatherTaskSys *task, int variant, int heapId)
{
    s32 scrollX;
    s32 scrollY;

    func_021A21B8(task);
    func_021A2248(task, heapId);
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Rain: end-particles stage. Lets the spawner die out. */
int func_021EE8B8(WeatherTaskSys *task)
{
    WeatherRainWork *work;

    work = func_021A21B8(task);
    func_021A2228(task, 0, 8, 4, -1);
    work->fogDelay = 1;
    func_021A25CC(task);
    return 1;
}

/* Rain: end-fade stage. Fades the fog out and ends when every drop is gone. */
int func_021EE8E4(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherRainWork *work;
    int spawnerSettled;
    int fogDone;
    s32 scrollX;
    s32 scrollY;

    work = func_021A21B8(task);
    spawnerSettled = func_021A223C(task, heapId);
    if (work->fogDelay > 0) {
        work->fogDelay = work->fogDelay - 1;
        if (work->fogDelay == 0) {
            func_021A2390(task, 0x7FDF, 0x32, variant);
        }
    } else {
        if (variant != 0) {
            fogDone = func_021A23B0(task);
        } else {
            fogDone = 1;
        }
        if (fogDone != 0 && spawnerSettled != 0 && func_021A21BC(task) == 0) {
            return 1;
        }
    }
    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    return 0;
}

/* Rain: end-finish stage. */
int func_021EE95C(WeatherTaskSys *task, int variant)
{
    func_021A21B8(task);
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    return 1;
}

/* Rain: particle update. A drop falls, then either vanishes or splashes and vanishes. */
void func_021EE97C(WeatherParticle *particle)
{
    WeatherRainDrop *drop;
    int remaining;
    Actor *actor;
    WeatherScreenPos pos;

    drop = (WeatherRainDrop *)func_021A2630(particle);
    actor = func_021A2638(particle);
    func_021A2640(particle, &pos);
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
        func_021A26C4(particle, &pos);
        break;
    case WEATHER_RAIN_DROP_SPLASHING:
        remaining = drop->age;
        drop->age = remaining - 1;
        if (remaining <= 0) {
            drop->state = WEATHER_RAIN_DROP_REMOVE;
        }
        break;
    case WEATHER_RAIN_DROP_REMOVE:
        func_021A21E0(particle);
        break;
    }
}

/* Rain: spawner callback. Creates `count` drops of three sizes above the screen. */
void func_021EEA18(WeatherTaskSys *task, s32 count, u32 heapId)
{
    int i;
    WeatherParticle *particle;
    WeatherRainDrop *drop;
    Actor *actor;
    u32 rand;
    u32 size;
    int jitter;
    WeatherScreenPos pos;

    func_021A21B8(task);
    for (i = 0; i < count; i++) {
        particle = func_021A21C8(task, heapId);
        if (particle == 0) {
            return;
        }
        drop = (WeatherRainDrop *)func_021A2630(particle);
        actor = func_021A2638(particle);
        rand = func_020056EC(0);
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
        func_021A26C4(particle, &pos);
        drop->speedX = drop->speedX * 2;
        drop->speedY = drop->speedY * 2;
        drop->splashRoll = func_020056EC(10);
    }
}

/* Thunderstorm: begin stage. */
int func_021EEAEC(WeatherTaskSys *task, int variant)
{
    WeatherThunderstormWork *work;

    work = func_021A21B8(task);
    func_021EF9B0(&work->lightning, 2);
    func_021A21F8(task, 1, 0xF, 2, 0, -3, 1, 1, func_021EEE38);
    func_021A22E0(task, 9, 0x7FDF, variant);
    work->stepTimer = 0;
    work->step = 0;
    func_021A2424(task);
    return 1;
}

/* Thunderstorm: begin-particles stage. Runs the opening sequence: light archive, sky
 * pre-flash, first lightning flash, fog change, then waits for the spawner and the fog. */
int func_021EEB44(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherThunderstormWork *work;
    int spawnerSettled;
    int fogDone;

    work = func_021A21B8(task);
    switch (work->step) {
    case THUNDERSTORM_BEGIN_LOAD_LIGHT:
        func_021A2108(task, 0x3E, func_02014A10(6));
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
        func_021A2154(task, 0x28C6, 8);
        work->stepTimer = 0x10;
        work->step = work->step + 1;
        break;
    case THUNDERSTORM_BEGIN_FIRST_FLASH:
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer < 0) {
            func_021A2130(task, 0x23DE, 4, 0x3C);
            func_021A25DC(task, 0x692);
            work->step = work->step + 1;
        }
        break;
    case THUNDERSTORM_BEGIN_FOG:
        if (func_021A213C(task) == 0) {
            func_021A232C(task, 9, 0x7F80, 0x50, variant);
            work->step = work->step + 1;
            work->stepTimer = 0x30;
        }
        break;
    case THUNDERSTORM_BEGIN_SETTLE:
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer == 0) {
            func_021A25BC(task, 0x690);
            func_021A2160(task, 1, 0);
        }
        spawnerSettled = func_021A223C(task, heapId);
        fogDone = func_021A23B0(task);
        if (spawnerSettled != 0 && fogDone != 0) {
            return 1;
        }
        break;
    }
    func_021EEF0C(task, work);
    return 0;
}

/* Thunderstorm: begin-plain stage. */
int func_021EEC5C(WeatherTaskSys *task, int variant, u16 heapId)
{
    func_021A21B8(task);
    func_021A21F8(task, 2, 0, 2, 0, -3, 1, 1, func_021EEE38);
    func_021A22E0(task, 9, 0x7F80, variant);
    func_021A2254(task, func_021EEE38, 0x14, 5, 1, heapId);
    func_021A25BC(task, 0x690);
    func_021A2114(task, 0x3E, func_02014A10(6));
    func_021A2160(task, 1, 0);
    return 1;
}

/* Thunderstorm: run stage. Cycles the drop speed scale and drives the lightning. */
int func_021EECD8(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherThunderstormWork *work;

    work = func_021A21B8(task);
    work->intensityTimer = (work->intensityTimer + 1) % 300;
    func_021A2248(task, heapId);
    func_021EF9D8(&work->lightning, task);
    func_021EEF0C(task, work);
    return 0;
}

/* Thunderstorm: end-particles stage. */
int func_021EED10(WeatherTaskSys *task)
{
    WeatherThunderstormWork *work;

    work = func_021A21B8(task);
    func_021A2228(task, 0, 15, 3, -1);
    work->stepTimer = 1;
    func_021A25CC(task);
    func_021A2160(task, 0, 0);
    return 1;
}

/* Thunderstorm: end-fade stage. */
int func_021EED44(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherThunderstormWork *work;
    int spawnerSettled;
    int fogDone;

    work = func_021A21B8(task);
    spawnerSettled = func_021A223C(task, heapId);
    if (work->stepTimer > 0) {
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer == 0) {
            func_021A2390(task, 0x7FDF, 0x32, variant);
        }
    } else {
        if (variant != 0) {
            fogDone = func_021A23B0(task);
        } else {
            fogDone = 1;
        }
        if (fogDone != 0 && spawnerSettled != 0 && func_021A21BC(task) == 0) {
            return 1;
        }
    }
    func_021EEF0C(task, work);
    return 0;
}

/* Thunderstorm: end-finish stage. */
int func_021EEDB0(WeatherTaskSys *task, int variant)
{
    WeatherThunderstormWork *work;

    work = func_021A21B8(task);
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    func_021EF9CC(&work->lightning);
    return 1;
}

/* Thunderstorm: particle update. A drop falls until it leaves the screen. */
void func_021EEDD8(WeatherParticle *particle)
{
    WeatherThunderstormDrop *drop;
    WeatherScreenPos pos;

    drop = (WeatherThunderstormDrop *)func_021A2630(particle);
    func_021A2638(particle);
    func_021A2640(particle, &pos);
    switch (drop->state) {
    case 0:
        pos.x = pos.x + (s16)drop->speedX;
        pos.y = pos.y + (s16)drop->speedY;
        if (pos.y >= 0xC0) {
            drop->state = 1;
        }
        func_021A26C4(particle, &pos);
        break;
    case 1:
        func_021A21E0(particle);
        break;
    }
}

/* Thunderstorm: spawner callback. Drop speed follows the intensity table. */
void func_021EEE38(WeatherTaskSys *task, s32 count, u32 heapId)
{
    int i;
    WeatherThunderstormWork *work;
    WeatherParticle *particle;
    WeatherThunderstormDrop *drop;
    Actor *actor;
    u32 rand;
    u32 size;
    WeatherScreenPos pos;

    work = func_021A21B8(task);
    for (i = 0; i < count; i++) {
        particle = func_021A21C8(task, heapId);
        if (particle == 0) {
            return;
        }
        drop = (WeatherThunderstormDrop *)func_021A2630(particle);
        actor = func_021A2638(particle);
        rand = func_020056EC(0);
        size = rand % 3;
        CLACT_SetActorAnimIndex(actor, (u16)size);
        drop->speedY = drop->speedX = (rand & 15) + (size + 1) * 14;
        drop->speedX = d_021EFD08[work->intensityTimer / 60] * drop->speedX / 10;
        drop->speedY = d_021EFD08[work->intensityTimer / 60] * drop->speedY / 10;
        drop->state = 0;
        pos.x = rand % 0x180 - 0x80;
        pos.y = rand % 0x28 - 0x50;
        func_021A26C4(particle, &pos);
    }
}

/* Thunderstorm: scrolls the two drop layers with the camera and advances their phase. */
void func_021EEF0C(WeatherTaskSys *task, WeatherThunderstormWork *work)
{
    s32 scrollX;
    s32 scrollY;

    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    work->scrollPhase = (work->scrollPhase + 9) % 256;
    func_021A2190(task, -(work->scrollPhase + scrollX), 0);
    func_021A21A0(task, scrollY - work->scrollPhase, 0);
}

/* Storm: begin stage. */
int func_021EEF58(WeatherTaskSys *task, int variant)
{
    WeatherStormWork *work;

    work = func_021A21B8(task);
    func_021A21F8(task, 1, 4, 1, 1, -4, 1, 1, func_021EF220);
    func_021A22E0(task, 9, 0x7FDF, variant);
    func_021A2424(task);
    func_021EF93C(work);
    return 1;
}

/* Storm: begin-particles stage. Loads the light archive, then starts the first calm phase
 * and the fog change, and ends when the spawner and the fog are done. */
int func_021EEFA8(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherStormWork *work;
    int spawnerSettled;
    int fogDone;

    work = func_021A21B8(task);
    switch (work->step) {
    case STORM_BEGIN_LOAD_LIGHT:
        func_021A2108(task, 0x3E, func_02014A10(7));
        work->stepTimer = 0x5A;
        work->step = work->step + 1;
        break;
    case STORM_BEGIN_DELAY:
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer <= 0) {
            func_021EF614(task, work, variant, 1);
            work->gustDuration = 0x78;
            work->stepTimer = 8;
            work->step = work->step + 1;
        }
        break;
    case STORM_BEGIN_SETTLE:
        work->stepTimer = work->stepTimer - 1;
        if (work->stepTimer == 0) {
            func_021A25BC(task, 0x690);
            func_021A2160(task, 1, 0);
            func_021A232C(task, 9, 0x7F80, 10, variant);
        }
        spawnerSettled = func_021A223C(task, heapId);
        fogDone = func_021A23B0(task);
        if (spawnerSettled == 1 && fogDone == 1 && work->stepTimer <= 0) {
            return 1;
        }
        break;
    }
    func_021EF664(task, work, variant, 0);
    func_021EF830(task, work);
    return 0;
}

/* Storm: begin-plain stage. */
int func_021EF078(WeatherTaskSys *task, int variant, u16 heapId)
{
    WeatherStormWork *work;

    work = func_021A21B8(task);
    func_021A21F8(task, 1, 1, 1, 1, -4, 1, 1, func_021EF220);
    func_021A22E0(task, 9, 0x7F80, variant);
    func_021A2254(task, func_021EF220, 0x14, 5, 1, heapId);
    func_021A25BC(task, 0x690);
    func_021EF614(task, work, variant, 0);
    func_021A2160(task, 1, 0);
    func_021A2114(task, 0x3E, func_02014A10(7));
    return 1;
}

/* Storm: run stage. */
int func_021EF104(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherStormWork *work;

    work = func_021A21B8(task);
    func_021A2248(task, heapId);
    func_021EF664(task, work, variant, 0);
    func_021EF830(task, work);
    return 0;
}

/* Storm: end-particles stage. */
int func_021EF134(WeatherTaskSys *task, int variant)
{
    func_021A21B8(task);
    func_021A2228(task, 0, 4, 4, -1);
    func_021A25CC(task);
    func_021A2390(task, 0x7FDF, 0x32, variant);
    func_021A2160(task, 0, 0);
    func_021A2160(task, 0, 1);
    return 1;
}

/* Storm: end-fade stage. */
int func_021EF180(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherStormWork *work;
    int spawnerSettled;
    int fogDone;

    work = func_021A21B8(task);
    spawnerSettled = func_021A223C(task, heapId);
    fogDone = (variant != 0) ? func_021A23B0(task) : 1;
    if (fogDone != 0 && spawnerSettled != 0 && func_021A21BC(task) == 0) {
        return 1;
    }
    func_021EF664(task, work, variant, 1);
    func_021EF830(task, work);
    return 0;
}

/* Storm: end-finish stage. */
int func_021EF1D4(WeatherTaskSys *task, int variant)
{
    func_021A21B8(task);
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    return 1;
}

/* Storm: particle update. Calls the update function of the drop type. */
void func_021EF1F4(WeatherParticle *particle)
{
    WeatherStormParticle *kind;
    Actor *actor;

    kind = (WeatherStormParticle *)func_021A2630(particle);
    actor = func_021A2638(particle);
    d_021EFDCC[kind->dropType](particle, kind->work, &kind->drop, actor);
}

/* Storm: spawner callback. The gust phase decides how many drops appear and of which type. */
void func_021EF220(WeatherTaskSys *task, s32 count, u32 heapId)
{
    u32 rand;
    u32 percent;
    WeatherStormWork *work;
    int i;
    WeatherParticle *particle;
    WeatherStormParticle *kind;
    Actor *actor;

    rand = func_020056EC(0);
    work = func_021A21B8(task);
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
        particle = func_021A21C8(task, heapId);
        if (particle == 0) {
            return;
        }
        kind = (WeatherStormParticle *)func_021A2630(particle);
        actor = func_021A2638(particle);
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
        d_021EFDC0[kind->dropType](particle, kind->work, &kind->drop, actor);
        i++;
    } while (i < count);
}

/* Storm: update of a slow sideways drop. */
void func_021EF2D8(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop)
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
    func_021A2640(particle, &pos);
    drop->posX = drop->posX + (s16)(drop->speedX + windX);
    drop->posY = drop->posY + (s16)(drop->speedY + windY);
    pos.x = drop->posX / 8;
    pos.y = drop->posY / 8;
    if (pos.x >= 256 || pos.y >= 192) {
        func_021A21E0(particle);
        return;
    }
    func_021A26C4(particle, &pos);
}

/* Storm: init of a slow sideways drop. */
void func_021EF364(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor)
{
    u32 rand;
    WeatherScreenPos pos;
    int autoAnimSpeed;
    int windX;

    rand = func_020056EC(0);
    drop->speedX = rand % 24 + 0x10;
    windX = work->windX;
    drop->speedY = rand % 24 + 8;
    drop->lastWindX = windX;
    drop->lastWindY = work->windY;
    pos.x = (rand & 7) - 8;
    pos.y = rand % 160 - 16;
    func_021A26C4(particle, &pos);
    drop->posX = pos.x << 3;
    drop->posY = pos.y << 3;
    func_0204B878(actor, 0);
    autoAnimSpeed = 1;
    func_0204B92C(actor, 1);
    func_0204B954(actor, autoAnimSpeed << 13);
}

/* Storm: update of a falling streak. */
void func_021EF3E0(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop)
{
    WeatherScreenPos pos;

    func_021A2640(particle, &pos);
    drop->posX = drop->posX + (s16)(drop->speedX + work->windX);
    drop->posY = drop->posY + (s16)(drop->speedY + work->windY);
    pos.x = drop->posX / 8;
    pos.y = drop->posY / 8;
    if (pos.x >= 256 || pos.y >= 160) {
        func_021A21E0(particle);
        return;
    }
    func_021A26C4(particle, &pos);
}

/* Storm: init of a falling streak. */
void func_021EF454(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor)
{
    u32 rand;
    WeatherScreenPos pos;
    int autoAnimSpeed;

    rand = func_020056EC(0);
    drop->speedX = rand % 43 + 0x56;
    drop->speedY = (rand % 43) * 2 + 0x102;
    pos.x = rand % 336 - 0x50;
    pos.y = rand % 40 - 0x50;
    func_021A26C4(particle, &pos);
    drop->posX = pos.x << 3;
    drop->posY = pos.y << 3;
    func_0204B878(actor, 1);
    autoAnimSpeed = 1;
    func_0204B92C(actor, 1);
    func_0204B954(actor, autoAnimSpeed << 13);
}

/*
 * note: 2026-10-05 (wD8 lane04): closed. work is a const pointer (the struct is for readability; a
 *   const char * with casts gives the same bytes, a non-const one does not): the drop->posY store then does
 *   not kill the CSE of drop->speedY + work->windY, so lastWindY reuses the kept sum. Both sums are written inline
 *   (drop->posX + (s16)(drop->speedX + windX)) and repeated for lastWindX/lastWindY.
 *   EXACT* = 186 bytes compiled vs a 188-byte listing extent (2 bytes of padding).
 */
/* Storm: update of a fast sideways streak. */
void func_021EF4D0(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop)
{
    WeatherScreenPos pos;
    s16 windX;

    func_021A2640(particle, &pos);
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
        func_021A21E0(particle);
    } else {
        func_021A26C4(particle, &pos);
    }
}

/* Storm: init of a fast sideways streak. */
void func_021EF58C(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor)
{
    u32 rand;
    WeatherScreenPos pos;
    int autoAnimSpeed;

    rand = func_020056EC(0);
    drop->speedX = rand % 24 + 0x50;
    drop->speedY = rand % 24 + 0xE;
    drop->lastWindX = drop->speedX + work->windX;
    drop->lastWindY = drop->speedY + work->windY;
    pos.x = (rand & 7) - 8;
    pos.y = rand % 160 - 16;
    func_021A26C4(particle, &pos);
    drop->posX = pos.x << 3;
    drop->posY = pos.y << 3;
    func_0204B878(actor, 2);
    autoAnimSpeed = 1;
    func_0204B92C(actor, 1);
    func_0204B954(actor, autoAnimSpeed << 13);
}

/* Storm: starts a calm phase of random length. With silent set the caller does the fog,
 * light and sound changes itself. */
void func_021EF614(WeatherTaskSys *task, WeatherStormWork *work, int variant, int silent)
{
    u32 rand = func_020056EC(0);

    work->gustPhase = WEATHER_STORM_CALM;
    work->gustDuration = rand % 400 + 0x3C;
    work->gustTimer = 0;
    if (silent == 0) {
        func_021A232C(task, 9, 0x7F80, 10, variant);
        func_021A2160(task, 0, 1);
        func_021A25BC(task, 0x690);
    }
}

/* Storm: advances the gust cycle calm, rise, gust, fade, calm and sets the wind and the
 * layer scale of the current phase. */
void func_021EF664(WeatherTaskSys *task, WeatherStormWork *work, int variant, int silent)
{
    u32 rand;
    int i;

    switch (work->gustPhase) {
    case WEATHER_STORM_GUST_NONE:
        break;
    case WEATHER_STORM_CALM:
        work->gustTimer = work->gustTimer + 1;
        func_021EF920(task, work, variant, 0x71F);
        if (work->gustTimer >= work->gustDuration) {
            work->gustPhase = WEATHER_STORM_GUST_RISE;
            work->gustDuration = 0x10;
            work->gustTimer = 0;
            if (silent == 0) {
                func_021A232C(task, 9, 0x7F70, 10, variant);
                func_021A25BC(task, 0x720);
            }
        }
        break;
    case WEATHER_STORM_GUST:
        work->gustTimer = work->gustTimer + 1;
        func_021EF920(task, work, variant, 0x71F);
        func_021EF950(task, work, variant);
        if (work->gustTimer >= work->gustDuration) {
            work->gustPhase = WEATHER_STORM_GUST_FADE;
            work->gustDuration = 0x10;
            work->gustTimer = 0;
            if (silent == 0) {
                func_021A2160(task, 0, 1);
                func_021A2170(task, 0x1000, 0);
                func_021A2180(task, 0x1000, 0);
            }
        }
        break;
    case WEATHER_STORM_GUST_RISE:
        work->gustTimer = work->gustTimer + 1;
        if (work->gustTimer >= work->gustDuration) {
            rand = func_020056EC(0);
            work->gustPhase = WEATHER_STORM_GUST;
            work->gustDuration = rand % 400 + 0x3C;
            work->gustTimer = 0;
            if (silent == 0) {
                func_021A2160(task, 1, 1);
                func_021A2170(task, 0x800, 0);
                func_021A2180(task, 0x1800, 0);
            }
        }
        break;
    case WEATHER_STORM_GUST_FADE:
        work->gustTimer = work->gustTimer + 1;
        if (work->gustTimer >= work->gustDuration) {
            func_021EF614(task, work, variant, silent);
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
        work->windX = d_021EFD74[i].value;
        work->windY = d_021EFD78[i].value;
        work->layerScale = d_021EFD3C[(work->gustTimer % 0xE0u) * 14 / 0xE0u];
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
void func_021EF830(WeatherTaskSys *task, WeatherStormWork *work)
{
    s32 scrollX;
    s32 scrollY;

    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    if (work->windX != 0) {
        work->scrollX0 = (work->scrollX0 + 9) % 256;
        work->scrollY0 = (work->scrollY0 + 3) % 256;
        work->scrollX1 = (work->scrollX1 + 9) % 256;
        work->scrollY1 = (work->scrollY1 + 2) % 256;
    } else {
        work->scrollX0 = (work->scrollX0 + 3) % 256;
        work->scrollY0 = (work->scrollY0 + 8) % 256;
    }
    func_021A2190(task, -(work->scrollX0 + scrollX), 0);
    func_021A21A0(task, scrollY - work->scrollY0, 0);
    func_021A2190(task, -(work->scrollX1 + scrollX), 1);
    func_021A21A0(task, scrollY - work->scrollY1, 1);
    func_021A2170(task, work->layerScale, 1);
    func_021A2180(task, work->layerScale, 1);
}

/* Storm: plays the warning sound 24 frames before the calm phase ends. */
void func_021EF920(WeatherTaskSys *task, WeatherStormWork *work, int variant, int seId)
{
    if (variant != 0 && work->gustTimer == work->gustDuration - 24)
        func_021A25DC(task, seId);
}

/* Storm: restarts the thunder timer with a random interval. */
void func_021EF93C(WeatherStormWork *work)
{
    work->thunderTimer = 0;
    work->thunderInterval = func_020056EC(16) + 50;
}

/* Storm: plays thunder at random intervals during a gust, unless the warning sound is still playing. */
void func_021EF950(WeatherTaskSys *task, WeatherStormWork *work, int variant)
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
    if (func_02006224(func_02006148(0x71F)) == 0) {
        int pan = func_020056EC(0x1B) + 0x64;
        func_021A2604(task, 0x71E, pan);
        func_021EF93C(work);
        return;
    }
    work->thunderTimer = work->thunderInterval - 10;
}

/* Lightning: clears the sequencer and picks the first wait. */
void func_021EF9B0(WeatherLightning *lightning, int mode)
{
    func_02082BCC(lightning, 0, 64);
    lightning->timer = func_020056EC(3);
    lightning->mode = mode;
}

/* Lightning: clears the sequencer. */
void func_021EF9CC(WeatherLightning *lightning)
{
    func_02082BCC(lightning, 0, 0x40);
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
void func_021EF9D8(WeatherLightning *lightning, WeatherTaskSys *task)
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
        rand = func_020056EC(100);
        for (i = 0; i < 3; i++) {
            if (d_021EFCF9[i] >= rand) {
                break;
            }
        }
        if (lightning->mode == 0) {
            func_021EFBA4(lightning);
        } else {
            switch (i) {
            case 0:
                if (lightning->mode == 1) {
                    func_021EFBA4(lightning);
                } else {
                    func_021EFBFC(lightning);
                }
                break;
            case 1:
                func_021EFBFC(lightning);
                break;
            case 2:
                func_021EFC3C(lightning);
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
        func_021A2154(task, 0x3129, 4);
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
            func_021A2130(task, func_021EFCD4(lightning), lightning->flashes[lightning->flashIndex].fadeInFrames, lightning->flashes[lightning->flashIndex].returnFrames);
        }
        if (lightning->pattern == 2) {
            lightning->timer = lightning->flashes[lightning->flashIndex].fadeInFrames / 2 + func_020056EC(lightning->flashes[lightning->flashIndex].returnFrames);
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
                func_021A25DC(task, lightning->pendingSoundId);
            }
        }
        if (func_021A213C(task) == 0) {
            lightning->state = WEATHER_LIGHTNING_FLASH_HOLD;
        }
        break;
    case WEATHER_LIGHTNING_FLASH_HOLD:
        if (lightning->pendingSoundDelay > 0) {
            lightning->pendingSoundDelay--;
            if (lightning->pendingSoundDelay == 0) {
                func_021A25DC(task, lightning->pendingSoundId);
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
void func_021EFBA4(WeatherLightning *lightning)
{
    int i;

    i = 0;
    lightning->pattern = 0;
    lightning->flashCount = func_020056EC(2) + 1;
    for (; i < lightning->flashCount; i++) {
        lightning->flashes[i].brightness = func_020056EC(3) + 0x12;
        lightning->flashes[i].fadeInFrames = 4;
        lightning->flashes[i].returnFrames = d_021EFD1C[lightning->flashes[i].brightness];
        lightning->flashes[i].holdFrames = func_020056EC(0xF0) + 0x78;
        lightning->flashes[i].soundDelay = 0x1C;
        lightning->flashes[i].soundId = 0x693;
    }
}

/* Lightning: picks a single flash. */
void func_021EFBFC(WeatherLightning *lightning)
{
    lightning->pattern = 1;
    lightning->flashCount = 1;
    lightning->flashes[0].brightness = func_020056EC(3) + 0x18;
    lightning->flashes[0].fadeInFrames = 4;
    lightning->flashes[0].returnFrames = d_021EFD1C[lightning->flashes[0].brightness];
    lightning->flashes[0].holdFrames = func_020056EC(0x12C) + 0xF0;
    lightning->flashes[0].soundDelay = 0xD;
    lightning->flashes[0].soundId = 0x692;
}

/*
 * The handed 644-byte extent is 152 bytes of code; the unlabelled leaf
 * func_021EFCD4 and ov026 data follow. The tail flash must be spelled
 * flashes[i].field (a cursor pointer, as the plain loop of the twin
 * func_021EFBA4 might suggest, gives 62 bytes out: the image indexes +0xC from a
 * separate base and re-adds lightning + i*12 per store).
 */
/* Lightning: picks a long sequence of short flashes and a last bright one. */
void func_021EFC3C(WeatherLightning *lightning)
{
    int i;

    lightning->pattern = 2;
    lightning->flashCount = func_020056EC(2) + 1;
    i = 0;
    lightning->flashCount = lightning->flashCount + 1;
    for (; i < lightning->flashCount - 1; i++) {
        lightning->flashes[i].brightness = func_020056EC(3) + 0x12;
        lightning->flashes[i].fadeInFrames = 4;
        lightning->flashes[i].returnFrames = 8;
        lightning->flashes[i].holdFrames = func_020056EC(4);
        lightning->flashes[i].soundDelay = 10;
        lightning->flashes[i].soundId = 0x693;
    }
    lightning->flashes[i].brightness = func_020056EC(1) + 0x1E;
    lightning->flashes[i].fadeInFrames = 4;
    lightning->flashes[i].returnFrames = d_021EFD1C[lightning->flashes[i].brightness];
    lightning->flashes[i].holdFrames = func_020056EC(300) + 0xF0;
    lightning->flashes[i].soundDelay = 10;
    lightning->flashes[i].soundId = 0x692;
}

/* Lightning: the flash colour of the current flash (grey ramp with a blue bias). */
unsigned short func_021EFCD4(WeatherLightning *lightning)
{
    unsigned short brightness;

    brightness = lightning->flashes[lightning->flashIndex].brightness;
    return brightness | (brightness << 5) | 0x2000;
}
