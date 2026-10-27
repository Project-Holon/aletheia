#ifndef OV180_HALL_OF_FAME_TYPES_H
#define OV180_HALL_OF_FAME_TYPES_H
/*
 * Types of the Hall of Fame ceremony: the work area of the process and the
 * records its three source files share.
 */

#include "../types.h"

struct ClactActor;

#define HOF_HEAP_ID 141
#define HOF_ACTOR_COUNT 33
#define HOF_PARTY_MAX 6
#define HOF_CHAR_COUNT 6
#define HOF_PALETTE_COUNT 7
#define HOF_CELL_ANIM_COUNT 6
#define HOF_TEXT_PLATE_COUNT 4
#define HOF_JITTER_COUNT 8
#define HOF_PARTICLE_WORK_SIZE 0x4800

/* Slots of the actor table. */
enum {
    HOF_ACTOR_MON_TOP = 0,
    HOF_ACTOR_MON_BOTTOM = 1,
    HOF_ACTOR_PLATE_LEFT = 2,
    HOF_ACTOR_PLATE_RIGHT = 3,
    HOF_ACTOR_VOICE_MARK = 4,
    HOF_ACTOR_TRAINER_TOP = 5,
    HOF_ACTOR_TRAINER_BOTTOM = 6,
    HOF_ACTOR_RING_TOP = 7,
    HOF_ACTOR_RING_BOTTOM = 8,
    HOF_ACTOR_SPARKLE_FIRST = 9
};

/* States of the ceremony state machine (index into the handler table). */
enum {
    HOF_STATE_INIT = 0,
    HOF_STATE_DONE = 10
};

/* Parameter block the caller passes to the process. */
typedef struct HallOfFameArgs {
    void *party;                    /* 0x00 party of the player */
    void *myStatus;                 /* 0x04 trainer name and ID */
    void *playTime;                 /* 0x08 hours and minutes played */
} HallOfFameArgs;

/* Text plate: a window drawn as an object (8 bytes). */
typedef struct HallOfFameTextPlate {
    void *oam;                      /* 0x00 window object, 0 when free */
    void *bmp;                      /* 0x04 pixel buffer of the window */
} HallOfFameTextPlate;

/* Parameters of the window object creation. */
typedef struct HallOfFameOamParam {
    void *bmp;                      /* 0x00 */
    s16 x;                          /* 0x04 */
    s16 y;                          /* 0x06 */
    u32 palette;                    /* 0x08 palette handle */
    u32 reserved0C;                 /* 0x0C */
    u8 priority;                    /* 0x10 */
    u8 reserved11;                  /* 0x11 */
    u16 tag;                        /* 0x12 */
    u32 reserved14;                 /* 0x14 */
} HallOfFameOamParam;

/* Actor description: position, resource table indexes and layer (24 bytes). */
typedef struct HallOfFameActorTemplate {
    u16 x;                          /* 0x00 */
    u16 y;                          /* 0x02 */
    u32 depth;                      /* 0x04 */
    int charIndex;                  /* 0x08 index into charIds */
    int paletteIndex;               /* 0x0C index into paletteIds */
    int cellAnimIndex;              /* 0x10 index into cellAnimIds */
    u16 animSeq;                    /* 0x14 */
    u16 priority;                   /* 0x16 */
} HallOfFameActorTemplate;

/* Work area of the Hall of Fame process (0x919C bytes). */
typedef struct HallOfFameWork {
    HallOfFameArgs *args;           /* 0x0000 */
    void *vblankTask;               /* 0x0004 vblank task of the running scene */
    int renderMode;                 /* 0x0008 0 none, 1 mon scene, 2 trainer scene */
    void *waveArcSet;               /* 0x000C sound wave archive set */
    void *g3dUtil;                  /* 0x0010 */
    u8 reserved14[4];               /* 0x0014 */
    void *mcss;                     /* 0x0018 3D sprite system */
    void *monSprite;                /* 0x001C 3D sprite of the current Pokemon */
    void *camera;                   /* 0x0020 */
    int monAnimDone;                /* 0x0024 set when the Pokemon animation ended */
    void *monParticle;              /* 0x0028 effect system around the Pokemon */
    void *backdropParticle;         /* 0x002C effect system of the backdrop */
    u8 monParticleWork[HOF_PARTICLE_WORK_SIZE];       /* 0x0030 */
    u8 backdropParticleWork[HOF_PARTICLE_WORK_SIZE];  /* 0x4830 */
    void *fontMain;                 /* 0x9030 */
    void *fontSub;                  /* 0x9034 */
    void *msgData;                  /* 0x9038 */
    void *wordSet;                  /* 0x903C */
    void *strBuf;                   /* 0x9040 */
    void *clactUnit;                /* 0x9044 */
    struct ClactActor *actors[HOF_ACTOR_COUNT];              /* 0x9048 */
    int charIds[HOF_CHAR_COUNT];    /* 0x90CC */
    int paletteIds[HOF_PALETTE_COUNT];                /* 0x90E4 */
    int cellAnimIds[HOF_CELL_ANIM_COUNT];             /* 0x9100 */
    void *renderer;                 /* 0x9118 */
    void *oamSys;                   /* 0x911C window object system */
    HallOfFameTextPlate plates[HOF_TEXT_PLATE_COUNT]; /* 0x9120 */
    void *partyMons[HOF_PARTY_MAX]; /* 0x9140 members that are not eggs */
    u16 species;                    /* 0x9158 */
    u16 effectStyle;                /* 0x915A selects palette and effect archive */
    u8 form;                        /* 0x915C */
    u8 monIndex;                    /* 0x915D index into partyMons */
    u8 monCount;                    /* 0x915E number of entries in partyMons */
    u8 jitterIndex;                 /* 0x915F */
    s16 anchorX;                    /* 0x9160 */
    s16 anchorY;                    /* 0x9162 */
    s16 jitterX[HOF_JITTER_COUNT];  /* 0x9164 */
    s16 jitterY[HOF_JITTER_COUNT];  /* 0x9174 */
    u32 voiceHandle;                /* 0x9184 */
    int counter;                    /* 0x9188 frames left in the current step */
    int state;                      /* 0x918C */
    int step;                       /* 0x9190 sub-step of the running state */
    int nextState;                  /* 0x9194 state entered when the wait ends */
    int exiting;                    /* 0x9198 the player asked to leave */
} HallOfFameWork;

/* Compile-time size check: the allocation in the process init is 0x919C bytes. */
typedef char HallOfFameWorkSizeCheck[(sizeof(void *) != 4 || ((sizeof(HallOfFameWork) == 0x919C))) ? 1 : -1];

#endif
