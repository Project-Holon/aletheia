#ifndef OV025_WEATHER_SNOW_BLIZZARD_DOWNPOUR_DIAMOND_DUST_TYPES_H
#define OV025_WEATHER_SNOW_BLIZZARD_DOWNPOUR_DIAMOND_DUST_TYPES_H

#include "../ov021/weather_task_types.h"

/* Weather kinds loaded as overlay 25: snow, blizzard, downpour and diamond
 * dust. Each kind fills one WeatherKindDef (ov021 weather_task_types.h) with
 * seven stage callbacks, a particle update and a spawner callback. A kind
 * keeps its state in the task work buffer (task->workBuffer) and in the
 * 0x28 byte kind area of every particle (particle->kindWork).
 *
 * Needs from the including file: u8, u16, s16, u32, s32, WeatherTaskSys,
 * WeatherParticle, WeatherScreenPos, WeatherSpawnFunc (the main file includes
 * ../ov021/weather_task_types.h, a file at another depth declares them). */

typedef struct ClactActor Actor;

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

/* Arm9 services. */

/* Snow stages (begin, fade in, begin at once, run, stop spawning, fade out, finish). */
int WEATHER_SNOW_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_SNOW_EndFinish(WeatherTaskSys *task, int variant, int heapId);
void WEATHER_SNOW_UpdateParticle(WeatherParticle *particle);
void WEATHER_SNOW_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);

/* Blizzard stages. */
int WEATHER_BLIZZARD_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_Run(WeatherTaskSys *task, int variant, u16 heapId);
int WEATHER_BLIZZARD_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_BLIZZARD_EndFinish(WeatherTaskSys *task, int variant, int heapId);
void WEATHER_BLIZZARD_UpdateParticle(WeatherParticle *particle);
void WEATHER_BLIZZARD_SpawnParticles(WeatherTaskSys *task, s32 count, u16 heapId);
void WEATHER_BLIZZARD_ScrollFogLayer(WeatherTaskSys *task, WeatherBlizzardWork *work);

/* Downpour stages. */
int WEATHER_DOWNPOUR_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DOWNPOUR_EndFinish(WeatherTaskSys *task, int variant, int heapId);
void WEATHER_DOWNPOUR_UpdateParticle(WeatherParticle *particle);
void WEATHER_DOWNPOUR_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);

/* Diamond dust stages. */
int WEATHER_DIAMOND_DUST_Begin(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_BeginParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_BeginPlain(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_Run(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_EndParticles(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_EndFade(WeatherTaskSys *task, int variant, int heapId);
int WEATHER_DIAMOND_DUST_EndFinish(WeatherTaskSys *task, int variant, int heapId);
void WEATHER_DIAMOND_DUST_UpdateParticle(WeatherParticle *particle);
void WEATHER_DIAMOND_DUST_SpawnParticles(WeatherTaskSys *task, s32 count, u32 heapId);

#endif
