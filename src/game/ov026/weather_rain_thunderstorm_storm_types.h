#ifndef OV026_WEATHER_RAIN_THUNDERSTORM_STORM_TYPES_H
#define OV026_WEATHER_RAIN_THUNDERSTORM_STORM_TYPES_H

#include "../ov021/weather_task_types.h"
#include "weather_lightning_types.h"

/* Weather kinds loaded as overlay 26: a light rain, a thunderstorm and a
 * windy storm. Each kind fills one WeatherKindDef with eight stage
 * callbacks and a particle update. The kind keeps its own state in the task
 * work buffer (task->workBuffer) and in the 0x28 byte kind area of every
 * particle (particle->kindWork). */

typedef struct Actor Actor;

/* Rain: the work buffer is one counter. */
typedef struct WeatherRainWork {
    int fogDelay;          /* 0x00 frames before the fog change starts */
} WeatherRainWork;

/* Rain: one falling drop. */
typedef struct WeatherRainDrop {
    int age;               /* 0x00 */
    int lifetime;          /* 0x04 */
    int speedY;            /* 0x08 */
    int state;             /* 0x0C 0: falling, 1: splashing, 2: remove */
    int speedX;            /* 0x10 */
    int splashRoll;        /* 0x14 splashes when 7 or more */
} WeatherRainDrop;

enum {
    WEATHER_RAIN_DROP_FALLING = 0,
    WEATHER_RAIN_DROP_SPLASHING = 1,
    WEATHER_RAIN_DROP_REMOVE = 2
};

/* Thunderstorm: work buffer. */
typedef struct WeatherThunderstormWork {
    s16 step;                       /* 0x00 begin step */
    s16 stepTimer;                  /* 0x02 */
    int scrollPhase;                /* 0x04 */
    int intensityTimer;             /* 0x08 0 to 299, selects the drop speed scale */
    WeatherLightning lightning;     /* 0x0C */
} WeatherThunderstormWork;

/* Thunderstorm: one fast drop. */
typedef struct WeatherThunderstormDrop {
    int reserved[2];       /* 0x00 */
    int speedY;            /* 0x08 */
    int state;             /* 0x0C 0: falling, 1: remove */
    int speedX;            /* 0x10 */
} WeatherThunderstormDrop;

/* Storm: gust phases (WeatherStormWork.gustPhase). */
enum {
    WEATHER_STORM_GUST_NONE = 0,
    WEATHER_STORM_CALM = 1,
    WEATHER_STORM_GUST = 2,
    WEATHER_STORM_GUST_RISE = 3,
    WEATHER_STORM_GUST_FADE = 4
};

/* Storm: work buffer. */
typedef struct WeatherStormWork {
    s16 step;               /* 0x00 begin step */
    s16 stepTimer;          /* 0x02 */
    s16 scrollX0;           /* 0x04 layer 0 scroll */
    s16 scrollY0;           /* 0x06 */
    s16 scrollX1;           /* 0x08 layer 1 scroll */
    s16 scrollY1;           /* 0x0A */
    s16 gustTimer;          /* 0x0C */
    s16 gustDuration;       /* 0x0E */
    s16 gustPhase;          /* 0x10 */
    s16 thunderTimer;       /* 0x12 */
    s16 thunderInterval;    /* 0x14 */
    s16 windX;              /* 0x16 added to every drop each frame */
    s16 windY;              /* 0x18 */
    s16 pad1A;              /* 0x1A */
    int layerScale;         /* 0x1C scale of both layers */
} WeatherStormWork;

/* Storm: one drop in 1/8 pixel units. */
typedef struct WeatherStormDrop {
    s16 posX;               /* 0x00 */
    s16 posY;               /* 0x02 */
    s16 speedX;             /* 0x04 */
    s16 speedY;             /* 0x06 */
    s16 lastWindX;          /* 0x08 */
    s16 lastWindY;          /* 0x0A */
} WeatherStormDrop;

/* Storm: kind area of one particle. */
typedef struct WeatherStormParticle {
    int dropType;                /* 0x00 index into the init and update tables */
    WeatherStormWork *work;      /* 0x04 */
    WeatherStormDrop drop;       /* 0x08 */
} WeatherStormParticle;

typedef void (*WeatherStormDropInitFunc)(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor);
typedef void (*WeatherStormDropUpdateFunc)(WeatherParticle *particle, const WeatherStormWork *work, WeatherStormDrop *drop, Actor *actor);

/* Table of three samples per step: the wind of the gust at the given step and one
 * unused word. The code reads it through two symbols, one for each column. */
typedef struct WeatherStormGustSample {
    int value;
    int skip1;
    int skip2;
} WeatherStormGustSample;

/* Weather task services (overlay 21, weather_task.c). */
extern void *WEATHER_TASK_GetWorkBuffer(WeatherTaskSys *task);
extern void WEATHER_TASK_SetupSpawner(WeatherTaskSys *task, int count, int interval, int targetCount, int targetInterval, int intervalStep, int stepsPerCountChange, int countStep, WeatherSpawnFunc spawn);
extern void WEATHER_TASK_InitFog(WeatherTaskSys *task, int slope, int offset, int phase);
extern void WEATHER_TASK_SaveCameraPos(WeatherTaskSys *task);
extern int WEATHER_TASK_StepSpawner(WeatherTaskSys *task, int arg);
extern void WEATHER_TASK_ChangeFog(WeatherTaskSys *task, u8 slope, int offset, int frames, int mode);
extern int WEATHER_TASK_FadeLight(WeatherTaskSys *task, int arcId, int memberId);
extern void WEATHER_TASK_PlaySe(WeatherTaskSys *task, u16 seId);
extern int WEATHER_TASK_IsFogIdle(WeatherTaskSys *task);
extern void WEATHER_TASK_GetCameraScroll(WeatherTaskSys *task, s32 *outX, s32 *outY);
extern void WEATHER_TASK_ShiftParticles(WeatherTaskSys *task, int dx, int dy);
extern void WEATHER_TASK_PrewarmParticles(WeatherTaskSys *task, WeatherSpawnFunc spawn, int iterations, int growEvery, int growBy, u16 heapId);
extern int WEATHER_TASK_SetLight(WeatherTaskSys *task, int arcId, u32 memberId);
extern int WEATHER_TASK_StepSpawnTimer(WeatherTaskSys *task, int arg);
extern void WEATHER_TASK_RetargetSpawner(WeatherTaskSys *task, int targetCount, int targetInterval, int intervalStep, int countStep);
extern void WEATHER_TASK_StopSe(WeatherTaskSys *task);
extern void WEATHER_TASK_ChangeFogOffset(WeatherTaskSys *task, int endOffset, int frames, int mode);
extern int WEATHER_TASK_GetParticleCount(WeatherTaskSys *task);
extern void WEATHER_TASK_DisableFog(WeatherTaskSys *task, int phase);
extern void WEATHER_TASK_ResetLight(WeatherTaskSys *task, int phase);
extern u8 *WEATHER_TASK_GetParticleWork(WeatherParticle *particle);
extern Actor *WEATHER_TASK_GetParticleActor(WeatherParticle *particle);
extern void WEATHER_TASK_GetParticlePos(WeatherParticle *particle, WeatherScreenPos *out);
extern int WEATHER_TASK_SetParticlePos(WeatherParticle *particle, const WeatherScreenPos *pos);
extern void WEATHER_TASK_RemoveParticle(WeatherParticle *particle);
extern WeatherParticle *WEATHER_TASK_AddParticle(WeatherTaskSys *task, int reserved);
extern void WEATHER_TASK_SetLightColor(WeatherTaskSys *task, unsigned int color, unsigned int frames);
extern void WEATHER_TASK_FlashLight(WeatherTaskSys *task, unsigned int color, unsigned int frames, unsigned int returnFrames);
extern void WEATHER_TASK_PlaySeDirect(WeatherTaskSys *task, int seId);
extern void WEATHER_TASK_PlaySeWithVoice(WeatherTaskSys *task, int seId, int who);
extern int WEATHER_TASK_IsLightFlashing(WeatherTaskSys *task);
extern void WEATHER_TASK_SetBillboardVisible(WeatherTaskSys *task, unsigned int value, int layer);
extern void WEATHER_TASK_SetBillboardParam14(WeatherTaskSys *task, unsigned int value, int layer);
extern void WEATHER_TASK_SetBillboardParam18(WeatherTaskSys *task, unsigned int value, int layer);
extern void WEATHER_TASK_SetBillboardParam0C(WeatherTaskSys *task, unsigned int value, int layer);
extern void WEATHER_TASK_SetBillboardParam10(WeatherTaskSys *task, unsigned int value, int layer);

/* Arm9 services. */
extern u16 func_02014A10(u32 i);
extern u32 func_020056EC(u32 range);
extern void CLACT_SetActorAnimIndex(Actor *actor, int index);
extern void CLACT_SetActorAnimSeq(Actor *actor, u16 value);
extern void func_0204B92C(Actor *actor, unsigned int enabled);
extern void CLACT_SetActorAutoAnimSpeed(Actor *actor, u32 speed);
extern int GFL_USE_GetSeSlot(u32 seId);
extern int GFL_USE_IsSeSlotBusy(u32 handle);
extern void func_02082BCC(void *dst, int value, u32 size);

#endif
