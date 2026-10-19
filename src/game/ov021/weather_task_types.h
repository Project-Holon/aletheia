#ifndef WEATHER_TASK_TYPES_H
#define WEATHER_TASK_TYPES_H

#include "../ov021/field_3dbg_types.h"

#include "../sdk_fx.h"

typedef struct {
    s16 x;
    s16 y;
} WeatherScreenPos;

/* Objects the weather task drives. Their layouts belong to the files that own them. */
struct Actor;
struct FieldCamera;
struct FieldFog;
struct FieldLight;
struct FieldSoundSystem;
struct FieldZoneFog;
struct Field3dbgBillboard;
struct WeatherTaskSys;
struct WeatherParticle;

#define WEATHER_BILLBOARD_COUNT 2
#define WEATHER_PARTICLE_MAX 0x20

/* The weather system (weather.c): two billboard layers, a texture bank
 * and two weather tasks used alternately. */
struct Bank;
struct TextureList;

typedef struct WeatherSys {
    struct Field3dbgBillboard *billboards[WEATHER_BILLBOARD_COUNT];
    u16 mode;             /* index into the transition handler table */
    u16 phase;            /* 0 idle, otherwise the step of the running transition */
    u16 weatherId;        /* current weather, 0xFFFF before the first one */
    u16 nextWeatherId;    /* weather being switched to, 0xFFFF when none */
    u32 useFade;          /* passed to the task as its fade-in flag */
    u16 queuedWeatherId;  /* request that arrived during a transition, 0xFFFF when none */
    u16 pad16;
    struct Bank *textureBank;
    struct TextureList *textureList;
    struct WeatherTaskSys *tasks[2];
    int loadedOverlayId;  /* overlay of the current weather, -1 when none */
    int updateTaskId;     /* per-frame task that releases the billboard VRAM copies */
} WeatherSys;

/* Stages of the task state machine (WeatherTaskSys.stage). */
enum {
    WEATHER_STAGE_IDLE = 0,
    WEATHER_STAGE_LOAD_ALL = 1,          /* load everything in one frame */
    WEATHER_STAGE_LOAD_RESOURCES = 2,    /* staged load, step 1 */
    WEATHER_STAGE_LOAD_BILLBOARDS = 3,   /* staged load, step 2 */
    WEATHER_STAGE_LOAD_PARTICLES = 4,    /* staged load, step 3 */
    WEATHER_STAGE_BEGIN = 5,
    WEATHER_STAGE_BEGIN_PARTICLES = 6,
    WEATHER_STAGE_BEGIN_PLAIN = 7,
    WEATHER_STAGE_RUN = 8,
    WEATHER_STAGE_END_PARTICLES = 9,
    WEATHER_STAGE_END_FADE = 10,
    WEATHER_STAGE_END_FINISH = 11,
    WEATHER_STAGE_RELEASE = 12
};

/* Callback of one stage of a weather kind: task, variant, heap id. Returns 1 when the stage is done. */
typedef int (*WeatherKindStageFunc)(struct WeatherTaskSys *task, int variant, int heapId);

/* Called for every linked particle once per frame. */
typedef void (*WeatherParticleUpdateFunc)(struct WeatherParticle *particle);

/* Texture description of one billboard layer (copied to a scratch buffer
 * before the layer is created). */
typedef struct WeatherBillboardInit {
    u8 textureDesc[12];
} WeatherBillboardInit;

/* Static description of one weather kind, referenced by the task. */
typedef struct WeatherKindDef {
    u16 archiveId;                              /* 0x00 archive loaded when hasSprites is set */
    u16 hasSprites;                             /* 0x02 non-zero: sprite resources and particles are used */
    u16 billboardCount;                         /* 0x04 */
    u16 charArg;                                /* 0x06 */
    u16 paletteArg;                             /* 0x08 */
    u16 cellArg;                                /* 0x0A */
    u16 cellAnimArg;                            /* 0x0C */
    WeatherBillboardInit billboards[WEATHER_BILLBOARD_COUNT]; /* 0x0E */
    u16 gap26;                                  /* 0x26 */
    u32 workBufferSize;                         /* 0x28 */
    WeatherKindStageFunc begin;                 /* 0x2C */
    WeatherKindStageFunc beginParticles;        /* 0x30 */
    WeatherKindStageFunc beginPlain;            /* 0x34 */
    WeatherKindStageFunc run;                   /* 0x38 */
    WeatherKindStageFunc endParticles;          /* 0x3C */
    WeatherKindStageFunc endFade;               /* 0x40 */
    WeatherKindStageFunc endFinish;             /* 0x44 */
    WeatherParticleUpdateFunc updateParticle;   /* 0x48 */
} WeatherKindDef;

/* Sprite resources of the current kind. */
typedef struct WeatherResourceSet {
    u16 loaded;                  /* 0x00 */
    u16 charResId;               /* 0x02 */
    u16 paletteResId;            /* 0x04 */
    u16 cellResId;               /* 0x06 */
    int billboardReady[WEATHER_BILLBOARD_COUNT]; /* 0x08 */
    void *archive;               /* 0x10 */
} WeatherResourceSet;

/* Sound effect started by the task. State 2 means "start once the sound system is free". */
typedef struct WeatherSoundState {
    u16 state;                   /* 0 stopped, 1 playing, 2 waiting */
    u16 seId;                    /* 0x02 */
    u32 reserved;                /* 0x04 */
    u32 useSoundSys;             /* 0x08 non-zero: play through the field sound system */
} WeatherSoundState;

typedef void (*WeatherSpawnFunc)(struct WeatherTaskSys *task, s32 count, u32 arg);

/* Particle spawner: calls spawn every `interval` ticks and moves count and
 * interval towards their targets in steps. */
typedef struct WeatherSpawner {
    struct WeatherTaskSys *owner;  /* 0x00 */
    s16 count;                     /* 0x04 */
    s16 timer;                     /* 0x06 */
    s16 interval;                  /* 0x08 */
    s16 stepCounter;               /* 0x0A */
    s16 targetCount;               /* 0x0C */
    s16 targetInterval;            /* 0x0E */
    s16 intervalStep;              /* 0x10 */
    s16 stepsPerCountChange;       /* 0x12 */
    s32 countStep;                 /* 0x14 */
    WeatherSpawnFunc spawn;        /* 0x18 */
} WeatherSpawner;

/* One particle: an actor plus the kind's own data, linked into a ring. */
typedef struct WeatherParticle {
    struct WeatherTaskSys *owner;  /* 0x00 */
    struct Actor *actor;           /* 0x04 */
    u8 kindWork[0x28];             /* 0x08 */
    struct WeatherParticle *prev;  /* 0x30 */
    struct WeatherParticle *next;  /* 0x34 */
} WeatherParticle;

/* Task object of one weather kind (0x784 bytes, allocated by the constructor). */
typedef struct WeatherTaskSys {
    void *textureBank;                      /* 0x00 */
    struct FieldFog *fog;                   /* 0x04 */
    struct FieldLight *light;               /* 0x08 */
    struct FieldSoundSystem *soundSys;      /* 0x0C */
    struct FieldZoneFog *zoneFog;           /* 0x10 */
    struct FieldCamera *camera;             /* 0x14 */
    WeatherSys *sys;                        /* 0x18 */
    u16 zoneId;                             /* 0x1C */
    u16 pad1E;                              /* 0x1E */
    const WeatherKindDef *kind;             /* 0x20 */
    u8 variant : 4;                         /* 0x24 passed to the stage callbacks */
    u8 updatesParticles : 4;
    u8 startMode;                           /* 0x25 0: load in one frame, 1: staged */
    u8 stage;                               /* 0x26 */
    u8 started;                             /* 0x27 */
    WeatherResourceSet resources;           /* 0x28 */
    void *workBuffer;                       /* 0x3C */
    WeatherSoundState sound;                /* 0x40 */
    WeatherSpawner spawner;                 /* 0x4C */
    VecFx32 lastCameraPos;                  /* 0x68 */
    WeatherParticle particles[WEATHER_PARTICLE_MAX]; /* 0x74 */
    WeatherParticle *particleHead;          /* 0x774 */
    int particleCount;                      /* 0x778 */
    u8 fogChangePending;                    /* 0x77C */
    u8 fogSlope;                            /* 0x77D */
    u8 fogFrames;                           /* 0x77E */
    u8 pad77F;                              /* 0x77F */
    u32 fogOffset;                          /* 0x780 */
} WeatherTaskSys;

/* Scale factors of the view, used to turn camera movement into scroll. */
typedef struct WeatherViewScale {
    fx32 widthRef;                          /* 0x00 */
    int otherParams[4];                     /* 0x04 */
    fx32 heightRef;                         /* 0x14 */
} WeatherViewScale;

#endif
