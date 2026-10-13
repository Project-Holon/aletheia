#ifndef OV025_WEATHER_SNOW_BLIZZARD_DOWNPOUR_DIAMOND_DUST_TYPES_H
#define OV025_WEATHER_SNOW_BLIZZARD_DOWNPOUR_DIAMOND_DUST_TYPES_H

/* Weather kinds loaded as overlay 25: snow, blizzard, downpour and diamond
 * dust. Each kind fills one WeatherKindDef (ov021 weather_task_types.h) with
 * seven stage callbacks, a particle update and a spawner callback. A kind
 * keeps its state in the task work buffer (task->workBuffer) and in the
 * 0x28 byte kind area of every particle (particle->kindWork).
 *
 * Needs from the including file: u8, u16, s16, u32, s32, WeatherTaskSys,
 * WeatherParticle, WeatherScreenPos, WeatherSpawnFunc (the main file includes
 * ../ov021/weather_task_types.h, a file at another depth declares them). */

typedef struct Actor Actor;

/* Snow: work buffer. */
typedef struct WeatherSnowWork {
    int fadeDelay;       /* 0x00 frames before the fog and light fade starts */
    int staggerSpawn;    /* 0x04 set once a flake has left the screen: new flakes start staggered */
    int ending;          /* 0x08 set when the weather ends: flakes die after a random delay */
} WeatherSnowWork;

/* Snow: kind area of one flake. */
typedef struct WeatherSnowFlake {
    int *staggerSpawn;   /* 0x00 WeatherSnowWork.staggerSpawn */
    int pad04[2];        /* 0x04 */
    int fallThreshold;   /* 0x0C fallAccum above this moves the flake one pixel down */
    int fallAccum;       /* 0x10 */
    int wobbleIndex;     /* 0x14 index into the horizontal wobble table */
    int pad18;           /* 0x18 */
    int *ending;         /* 0x1C WeatherSnowWork.ending */
    int dying;           /* 0x20 set once the weather has ended */
    int dyingFrames;     /* 0x24 frames left until the flake is removed */
} WeatherSnowFlake;

/* Blizzard: work buffer. */
typedef struct WeatherBlizzardWork {
    int fadeDelay;       /* 0x00 */
    int windPhase;       /* 0x04 0 to 0x3FF, advanced by every spawn; /256 selects the wind table entry */
    int scrollX;         /* 0x08 scroll of the fog layer */
    int pad0C[5];        /* 0x0C */
    int scrollStep;      /* 0x20 step of the scroll jitter tables, 0 to 251 */
    int scrollY;         /* 0x24 */
} WeatherBlizzardWork;

/* Blizzard: kind area of one flake. */
typedef struct WeatherBlizzardFlake {
    int age;             /* 0x00 */
    int lifetime;        /* 0x04 */
    int speedY;          /* 0x08 */
    int state;           /* 0x0C 0: moving, 1: remove */
    int speedX;          /* 0x10 */
    int accelX;          /* 0x14 added to speedX every 4th frame */
} WeatherBlizzardFlake;

enum {
    WEATHER_BLIZZARD_FLAKE_MOVING = 0,
    WEATHER_BLIZZARD_FLAKE_REMOVE = 1
};

/* Downpour: work buffer. */
typedef struct WeatherDownpourWork {
    int fadeDelay;       /* 0x00 */
} WeatherDownpourWork;

/* Downpour: kind area of one drop. */
typedef struct WeatherDownpourDrop {
    int age;             /* 0x00 frames moved (falling) or frames left (splashing) */
    int fallFrames;      /* 0x04 frames the drop falls before it splashes */
    int speedY;          /* 0x08 */
    int state;           /* 0x0C */
    int speedX;          /* 0x10 */
    int pad14;           /* 0x14 */
    int splashSeed;      /* 0x18 random value that sets the splash length */
} WeatherDownpourDrop;

enum {
    WEATHER_DOWNPOUR_DROP_FALLING = 0,
    WEATHER_DOWNPOUR_DROP_SPLASHING = 1,
    WEATHER_DOWNPOUR_DROP_REMOVE = 2
};

/* Diamond dust: work buffer. */
typedef struct WeatherDiamondDustWork {
    int fadeState;       /* 0 until the fade is issued, then -1 (begin), or the end delay */
} WeatherDiamondDustWork;

/* Diamond dust: kind area of one sparkle. */
typedef struct WeatherDiamondDustSparkle {
    int age;             /* 0x00 */
    int lifetime;        /* 0x04 */
    int stepX;           /* 0x08 pixels moved every xInterval frames */
    int stepY;           /* 0x0C pixels moved every yInterval frames */
    int xInterval;       /* 0x10 */
    int yInterval;       /* 0x14 */
} WeatherDiamondDustSparkle;

/* Weather task services (ov021 weather_task.c). */
extern void *func_021A21B8(WeatherTaskSys *task);
extern void func_021A21F8(WeatherTaskSys *task, int count, int interval, int targetCount, int targetInterval, int intervalStep, int stepsPerCountChange, int countStep, WeatherSpawnFunc spawn);
extern void func_021A22E0(WeatherTaskSys *task, int slope, int offset, int phase);
extern void func_021A2424(WeatherTaskSys *task);
extern int func_021A223C(WeatherTaskSys *task, int arg);
extern void func_021A232C(WeatherTaskSys *task, int slope, int offset, int frames, int mode);
extern int func_021A2108(WeatherTaskSys *task, int arcId, int memberId);
extern void func_021A25BC(WeatherTaskSys *task, u16 seId);
extern int func_021A23B0(WeatherTaskSys *task);
extern void func_021A244C(WeatherTaskSys *task, s32 *outX, s32 *outY);
extern void func_021A2564(WeatherTaskSys *task, int dx, int dy);
extern void func_021A2254(WeatherTaskSys *task, WeatherSpawnFunc spawn, int iterations, int growEvery, int growBy, int heapId);
extern int func_021A2114(WeatherTaskSys *task, int arcId, u32 memberId);
extern int func_021A2248(WeatherTaskSys *task, int arg);
extern void func_021A2228(WeatherTaskSys *task, int targetCount, int targetInterval, int intervalStep, int countStep);
extern void func_021A25CC(WeatherTaskSys *task);
extern void func_021A2390(WeatherTaskSys *task, int endOffset, int frames, int mode);
extern int func_021A21BC(WeatherTaskSys *task);
extern void func_021A231C(WeatherTaskSys *task, int phase);
extern void func_021A2120(WeatherTaskSys *task, int phase);
extern u8 *func_021A2630(WeatherParticle *particle);
extern Actor *func_021A2638(WeatherParticle *particle);
extern void func_021A2640(WeatherParticle *particle, WeatherScreenPos *out);
extern void func_021A2654(WeatherParticle *particle, const WeatherScreenPos *pos);
extern int func_021A26C4(WeatherParticle *particle, const WeatherScreenPos *pos);
extern void func_021A21E0(WeatherParticle *particle);
extern WeatherParticle *func_021A21C8(WeatherTaskSys *task, int reserved);
extern void func_021A2160(WeatherTaskSys *task, unsigned int value, int layer);
extern void func_021A2190(WeatherTaskSys *task, unsigned int value, int layer);
extern void func_021A21A0(WeatherTaskSys *task, unsigned int value, int layer);

/* Arm9 services. */
extern u16 func_02014A10(u32 i);
extern u32 func_020056EC(u32 range);
extern void CLACT_SetActorAnimIndex(Actor *actor, int index);
extern u16 CLACT_GetActorAnimSeqCount(Actor *actor);
extern void func_0204B454(Actor *actor, WeatherScreenPos *out, u32 space);
extern void func_0204B404(Actor *actor, const WeatherScreenPos *pos, u32 space);

/* Snow stages (begin, fade in, begin at once, run, stop spawning, fade out, finish). */
int func_021EE740(WeatherTaskSys *task, int variant, int heapId);
int func_021EE798(WeatherTaskSys *task, int variant, int heapId);
int func_021EE810(WeatherTaskSys *task, int variant, int heapId);
int func_021EE888(WeatherTaskSys *task, int variant, int heapId);
int func_021EE8B0(WeatherTaskSys *task, int variant, int heapId);
int func_021EE8EC(WeatherTaskSys *task, int variant, int heapId);
int func_021EE968(WeatherTaskSys *task, int variant, int heapId);
void func_021EE980(WeatherParticle *particle);
void func_021EEA34(WeatherTaskSys *task, s32 count, u32 heapId);

/* Blizzard stages. */
int func_021EEB0C(WeatherTaskSys *task, int variant, int heapId);
int func_021EEB74(WeatherTaskSys *task, int variant, int heapId);
int func_021EEBE4(WeatherTaskSys *task, int variant, int heapId);
int func_021EEC64(WeatherTaskSys *task, int variant, u16 heapId);
int func_021EECB0(WeatherTaskSys *task, int variant, int heapId);
int func_021EECEC(WeatherTaskSys *task, int variant, int heapId);
int func_021EED58(WeatherTaskSys *task, int variant, int heapId);
void func_021EED78(WeatherParticle *particle);
void func_021EEE04(WeatherTaskSys *task, s32 count, u16 heapId);
void func_021EEEE0(WeatherTaskSys *task, WeatherBlizzardWork *work);

/* Downpour stages. */
int func_021EEF94(WeatherTaskSys *task, int variant, int heapId);
int func_021EEFF0(WeatherTaskSys *task, int variant, int heapId);
int func_021EF068(WeatherTaskSys *task, int variant, int heapId);
int func_021EF0D0(WeatherTaskSys *task, int variant, int heapId);
int func_021EF100(WeatherTaskSys *task, int variant, int heapId);
int func_021EF12C(WeatherTaskSys *task, int variant, int heapId);
int func_021EF1A4(WeatherTaskSys *task, int variant, int heapId);
void func_021EF1C4(WeatherParticle *particle);
void func_021EF2D4(WeatherTaskSys *task, s32 count, u32 heapId);

/* Diamond dust stages. */
int func_021EF3BC(WeatherTaskSys *task, int variant, int heapId);
int func_021EF404(WeatherTaskSys *task, int variant, int heapId);
int func_021EF47C(WeatherTaskSys *task, int variant, int heapId);
int func_021EF4E4(WeatherTaskSys *task, int variant, int heapId);
int func_021EF514(WeatherTaskSys *task, int variant, int heapId);
int func_021EF538(WeatherTaskSys *task, int variant, int heapId);
int func_021EF5B0(WeatherTaskSys *task, int variant, int heapId);
void func_021EF5D0(WeatherParticle *particle);
void func_021EF634(WeatherTaskSys *task, s32 count, u32 heapId);

#endif
