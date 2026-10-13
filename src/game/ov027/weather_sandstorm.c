/*
 * file:     weather_sandstorm.c
 * unit:     yes
 * function: func_021EE740, func_021EE7A4, func_021EE814, func_021EE888, func_021EE8D4, func_021EE908, func_021EE970, func_021EE990, func_021EEA04, func_021EEAF4
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
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021A2254  0x021A2254  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_021A2248  0x021A2248  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   d_021EEB48     0x021EEB48  data  ov027  a4
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   d_021EEB68     0x021EEB68  data  a4
 *   func_021A244C  0x021A244C  thumb  ov021
 *   func_021A2564  0x021A2564  thumb  ov021
 *   func_021A2190  0x021A2190  thumb  ov021
 *   func_021A21A0  0x021A21A0  thumb  ov021
 */
#include "../ov021/weather_task_types.h"
#include "weather_sandstorm_types.h"

/* Weather task services (ov021). */
void *func_021A21B8(WeatherTaskSys *task);
void func_021A21F8(WeatherTaskSys *task, int count, int interval, int targetCount, int targetInterval, int intervalStep, int stepsPerCountChange, int countStep, WeatherSpawnFunc spawn);
void func_021A22E0(WeatherTaskSys *task, int slope, int offset, int phase);
void func_021A2424(WeatherTaskSys *task);
void func_021A25BC(WeatherTaskSys *task, u16 seId);
int func_021A223C(WeatherTaskSys *task, int heapId);
void func_021A232C(WeatherTaskSys *task, u8 slope, int offset, int frames, int mode);
int func_021A2108(WeatherTaskSys *task, int arcId, int memberId);
int func_021A23B0(WeatherTaskSys *task);
void func_021A2160(WeatherTaskSys *task, unsigned int value, int layer);
void func_021A2254(WeatherTaskSys *task, WeatherSpawnFunc spawn, int iterations, int growEvery, int growBy, int heapId);
int func_021A2114(WeatherTaskSys *task, int arcId, u32 memberId);
int func_021A2248(WeatherTaskSys *task, int heapId);
void func_021A2228(WeatherTaskSys *task, int targetCount, int targetInterval, int intervalStep, int countStep);
void func_021A25CC(WeatherTaskSys *task);
void func_021A2390(WeatherTaskSys *task, int endOffset, int frames, int mode);
int func_021A21BC(WeatherTaskSys *task);
void func_021A231C(WeatherTaskSys *task, int phase);
void func_021A2120(WeatherTaskSys *task, int phase);
u8 *func_021A2630(WeatherParticle *particle);
struct Actor *func_021A2638(WeatherParticle *particle);
void func_021A2640(WeatherParticle *particle, WeatherScreenPos *out);
void func_021A2654(WeatherParticle *particle, const WeatherScreenPos *pos);
void func_021A21E0(WeatherParticle *particle);
WeatherParticle *func_021A21C8(WeatherTaskSys *task, int reserved);
u16 func_02014A10(u32 weatherId);
extern u32 func_020056EC(u32 range);
/* Signed divide helper, called by name here (the result is the quotient). */
extern int func_0209C0A4(int dividend, int divisor);
extern void CLACT_SetActorAnimIndex(struct Actor *actor, u32 animIndex);
int func_021EE740(WeatherTaskSys *task, int variant);
int func_021EE7A4(WeatherTaskSys *task, int variant, int heapId);
int func_021EE814(WeatherTaskSys *task, int variant, int heapId);
int func_021EE888(WeatherTaskSys *task, int variant, int heapId);
int func_021EE8D4(WeatherTaskSys *task);
int func_021EE908(WeatherTaskSys *task, int variant, int heapId);
int func_021EE970(WeatherTaskSys *task, int variant);
void func_021EE990(WeatherParticle *particle);
void func_021EEA04(WeatherTaskSys *task, s32 count, u32 heapId);

/* Horizontal speed of the particles per gust step. */
extern const int d_021EEB48[];
/* Vertical speed per gust step. */
extern const int d_021EEB68[];
extern void func_021A244C(struct WeatherTaskSys *task, int *outX, int *outY);
extern void func_021A2564(struct WeatherTaskSys *task, int dx, int dy);
extern void func_021A2190(struct WeatherTaskSys *task, unsigned int value, int layer);
extern void func_021A21A0(struct WeatherTaskSys *task, unsigned int value, int layer);
/* Begin stage of the kind (staged start): spawner, fog and sound. */
int func_021EE740(WeatherTaskSys *task, int variant)
{
    WeatherSandstormWork *work = func_021A21B8(task);

    func_021A21F8(task, 1, 15, 1, 2, -2, 4, 1, func_021EEA04);
    func_021A22E0(task, 8, 0x7fdf, variant);
    work->startDelay = 1;
    work->gustCounter = 0;
    work->scrollPhase = 0;
    work->gustSpeed = 0;
    func_021A2424(task);
    func_021A25BC(task, 0x6e3);
    return 1;
}

/* Begin particles stage: start the fog and light change, wait for the fog and the spawner. */
int func_021EE7A4(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSandstormWork *work = func_021A21B8(task);
    int spawnerReady = func_021A223C(task, heapId);

    if (work->startDelay > 0) {
        work->startDelay = work->startDelay - 1;
        if (work->startDelay == 0) {
            func_021A232C(task, 8, 0x7f5e, 0x5a, variant);
            func_021A2108(task, 0x3e, func_02014A10(3));
        }
    } else if (func_021A23B0(task) != 0 && spawnerReady != 0) {
        func_021A2160(task, 1, 0);
        return 1;
    }
    func_021EEAF4(task, work);
    return 0;
}

/* Begin plain stage (everything at once): fog, filled screen, light, first billboard layer. */
int func_021EE814(WeatherTaskSys *task, int variant, int heapId)
{
    func_021A21B8(task);
    func_021A21F8(task, 1, 2, 1, 2, -2, 4, 1, func_021EEA04);
    func_021A22E0(task, 8, 0x7f5e, variant);
    func_021A2254(task, func_021EEA04, 24, 2, 2, heapId);
    func_021A2160(task, 1, 0);
    func_021A2114(task, 0x3e, func_02014A10(3));
    return 1;
}

/* Run stage: pick the gust speed of the current step and scroll the billboards. */
int func_021EE888(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSandstormWork *work = func_021A21B8(task);

    if (func_021A2248(task, heapId) != 0) {
        int gustSpeed = d_021EEB48[func_0209C0A4(work->gustCounter, GUST_STEP_FRAMES)];
        work->gustSpeed = gustSpeed;
        if (gustSpeed <= -6)
            func_021EEA04(task, 1, heapId);
    }
    func_021EEAF4(task, work);
    return 0;
}

/* End particles stage: let the spawner run out, hide the first billboard layer, stop the sound. */
int func_021EE8D4(WeatherTaskSys *task)
{
    WeatherSandstormWork *work;
    work = func_021A21B8(task);
    func_021A2228(task, 0, 15, 2, -1);
    work->startDelay = 31;
    func_021A2160(task, 0, 0);
    func_021A25CC(task);
    return 1;
}

/* End fade stage: after the delay fade the fog out, then wait for the fog and the particles. */
int func_021EE908(WeatherTaskSys *task, int variant, int heapId)
{
    WeatherSandstormWork *work = func_021A21B8(task);
    int spawnerReady = func_021A223C(task, heapId);
    int fogIdle;

    if (work->startDelay > 0) {
        work->startDelay = work->startDelay - 1;
        if (work->startDelay == 0)
            func_021A2390(task, 0x7fdf, 0x5a, variant);
    } else {
        if (variant != 0)
            fogIdle = func_021A23B0(task);
        else
            fogIdle = 1;
        if (fogIdle != 0 && spawnerReady != 0) {
            if (func_021A21BC(task) == 0)
                return 1;
        }
    }
    func_021EEAF4(task, work);
    return 0;
}

/* End finish stage: switch the fog off and reset the light. */
int func_021EE970(WeatherTaskSys *task, int variant)
{
    func_021A21B8(task);
    func_021A231C(task, variant);
    func_021A2120(task, variant);
    return 1;
}

/*
 * The 2 trailing bytes (0x021EEA02) are alignment padding before
 * func_021EEA04, which is why the verdict is EXACT*.
 */
/* Moves one particle: gusts accelerate it to the right until it expires. */
void func_021EE990(WeatherParticle *particle)
{
    WeatherSandstormGrain *work = (WeatherSandstormGrain *)func_021A2630(particle);
    WeatherScreenPos pos;

    func_021A2638(particle);
    func_021A2640(particle, &pos);
    if (work->expired == 0) {
        pos.x = pos.x + (s16)work->speedX;
        pos.y = pos.y + (s16)work->speedY;
        if (work->age % 5 == 0)
            work->speedX = work->speedX + work->speedXStep;
        if (work->age++ > work->lifetime)
            work->expired = 1;
        func_021A2654(particle, &pos);
    } else {
        func_021A21E0(particle);
    }
}

/* Spawn callback: creates count grains at the left edge. A shorter lifetime gives a larger sprite and more speed. */
void func_021EEA04(WeatherTaskSys *task, s32 count, u32 heapId)
{
    WeatherSandstormWork *work;
    int gustStep;
    int i;
    int spriteSize;
    WeatherParticle *particle;
    WeatherSandstormGrain *particleWork;
    struct Actor *actor;
    WeatherScreenPos pos;

    work = func_021A21B8(task);
    work->gustCounter = (work->gustCounter + 1) % GUST_CYCLE_FRAMES;
    gustStep = work->gustCounter / GUST_STEP_FRAMES;
    for (i = 0; i < count; i++) {
        particle = func_021A21C8(task, heapId);
        if (particle == 0) {
            return;
        }
        particleWork = (WeatherSandstormGrain *)func_021A2630(particle);
        actor = func_021A2638(particle);
        particleWork->age = 0;
        particleWork->lifetime = func_020056EC(20) + 15;
        spriteSize = 3 - (particleWork->lifetime - 15) / 6;
        particleWork->speedY = (spriteSize + 1) * d_021EEB68[gustStep];
        particleWork->speedX = (spriteSize + 1) * d_021EEB48[gustStep];
        particleWork->expired = 0;
        particleWork->speedXStep = d_021EEB48[gustStep];
        if (func_020056EC(1000) == 777) {
            spriteSize = 4;
            particleWork->speedY = particleWork->speedY + particleWork->speedY / 2;
        }
        CLACT_SetActorAnimIndex(actor, (u16)spriteSize);
        pos.x = -6 - func_020056EC(24);
        pos.y = func_020056EC(192) - 64;
        func_021A2654(particle, &pos);
    }
}

/* Scrolls the billboards with the camera and with the gust phase, and shifts the particles. */
void func_021EEAF4(struct WeatherTaskSys *task, WeatherSandstormWork *work)
{
    int scrollX;
    int scrollY;

    func_021A244C(task, &scrollX, &scrollY);
    func_021A2564(task, scrollX, scrollY);
    work->scrollPhase = (work->scrollPhase + GUST_SCROLL_STEP) % GUST_SCROLL_PERIOD;
    func_021A2190(task, -work->scrollPhase * 2 - scrollX, 0);
    func_021A21A0(task, scrollY + -work->scrollPhase * 2, 0);
}
