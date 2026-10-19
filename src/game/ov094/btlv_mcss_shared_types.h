#ifndef BTLV_MCSS_SHARED_TYPES_H
#define BTLV_MCSS_SHARED_TYPES_H

#include "btlv_camera_shared_types.h"

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

/*
 * Battle Pokemon and trainer sprites (MCSS = multi-cell sprite system).
 * BtlvMcssWork is allocated by BTLV_MCSS_Create (0x5b4 bytes) and reached through
 * the effect system (BTLV_EFFECT_GetMcss returns it). Every other file that needs a
 * sprite function includes this header instead of keeping its own view.
 */

struct McssSystem; /* arm9 sprite system handle (MCSS_Init) */
struct McssSprite; /* arm9 sprite handle (MCSS_Add) */

#define BTLV_MCSS_SPRITE_MAX 14   /* positions 0..13: 8 Pokemon positions, 6 trainer positions */
#define BTLV_MCSS_POKE_POS_COUNT 8

/* Sprite positions. 0 and 1 are the single battle spots, 2..7 the double, triple and rotation spots;
 * even positions are the player side, odd positions the opponent side. */
typedef enum BtlvMcssPos {
    BTLV_MCSS_POS_AA = 0,
    BTLV_MCSS_POS_BB = 1,
    BTLV_MCSS_POS_A = 2,
    BTLV_MCSS_POS_B = 3,
    BTLV_MCSS_POS_C = 4,
    BTLV_MCSS_POS_D = 5,
    BTLV_MCSS_POS_E = 6,
    BTLV_MCSS_POS_F = 7,
    BTLV_MCSS_POS_TRAINER_FIRST = 8
} BtlvMcssPos;

/* Battle rule numbers (BTLV_MCSS_Create mode). */
#define BTLV_MCSS_RULE_SINGLE 0
#define BTLV_MCSS_RULE_DOUBLE 1
#define BTLV_MCSS_RULE_TRIPLE 2
#define BTLV_MCSS_RULE_ROTATION 3

/* Position change request kinds of the tween starters. */
#define BTLV_MCSS_TWEEN_SET 0         /* jump to the value */
#define BTLV_MCSS_TWEEN_ABSOLUTE 1    /* linear move to the value */
#define BTLV_MCSS_TWEEN_RELATIVE 2    /* the value is the total change */
#define BTLV_MCSS_TWEEN_RELATIVE_X2 3 /* as 2, wait doubled */
#define BTLV_MCSS_TWEEN_ABSOLUTE_B 4  /* as 1 */
#define BTLV_MCSS_TWEEN_SLOT_SET 6    /* value replaced by the slot position, then 0 */
#define BTLV_MCSS_TWEEN_SLOT_MOVE 5   /* value replaced by the slot position, then 1 */

/* Bits of attrFlags. */
#define BTLV_MCSS_ATTR_SWAPPED 0x1   /* resource set replaced by the substitute doll set */
#define BTLV_MCSS_ATTR_SHINY 0x2     /* POKE_TOOL_IsShiny reported 1 for the Pokemon */
#define BTLV_MCSS_ATTR_SUBSTITUTE 0x4 /* substitute doll is shown */

/* Same type as the camera and mover vector. */
typedef BtlvVec3 BtlvMcssVec;

/* MCSS_Add input: archive and the seven resource file ids of one sprite (36 bytes). */
typedef struct BtlvMcssAddWork {
    u32 archiveId;      /* 0x00 */
    u32 ncbrId;         /* 0x04 */
    u32 nclrId;         /* 0x08 */
    u32 ncerId;         /* 0x0c */
    u32 nanrId;         /* 0x10 */
    u32 nmcrId;         /* 0x14 */
    u32 nmarId;         /* 0x18 */
    u32 ncecId;         /* 0x1c */
    u32 terminator;     /* 0x20: 0 */
} BtlvMcssAddWork;

/* Bits of BtlvMcssSprite.flags. */
typedef struct BtlvMcssSpriteFlags {
    unsigned int blinkLocked : 1;       /* bit 0: eye blink forced on, further blink requests ignored */
    unsigned int statusTinting : 1;     /* bit 1: status condition tint pulses */
    unsigned int orthoBillboard : 1;    /* bit 2: sprite uses the orthographic scale */
    unsigned int idleCounter : 2;       /* bits 3-4: idle animation countdown */
    unsigned int vanishHeld : 1;        /* bit 5: sprite was already hidden when a timed hide began */
    unsigned int repositionHidden : 1;  /* bit 6: hidden because it is away from its slot position */
    unsigned int paletteFadeHold : 1;   /* bit 7: a palette fade holds back the status tint */
    unsigned int paletteFadeSet : 1;    /* bit 8: a palette fade was set while an effect ran */
    unsigned int refreshed : 1;         /* bit 9: party data was reloaded, read once by TakeSpriteRefreshFlag */
    unsigned int vanishSaved : 1;       /* bit 10: hidden state stored by SaveVanishStates */
    unsigned int restartAnim : 1;       /* bit 11: restart the animation on the next update */
    unsigned int reserved12 : 20;
} BtlvMcssSpriteFlags;

/* What the sprite shows (16 bytes), copied as a unit between sprites. */
typedef struct BtlvMcssIdentity {
    u32 species;                        /* 0x00 */
    u32 form;                           /* 0x04 */
    u32 personalRand;                   /* 0x08: seed of the Spinda spots */
    u16 weight;                /* 0x0c: POKE_TOOL_GetPersonalParam(species, form, 0x26) */
    u16 hpState;                        /* 0x0e: BGWINFRM_GetScaleRank(hp, maxHp) at load time, 1 lowers the cry pitch */
} BtlvMcssIdentity;

/* One sprite slot (0x5c bytes). A slot is free while mcss is NULL. */
typedef struct BtlvMcssSprite {
    struct McssSprite *mcss;            /* 0x00 */
    BtlvMcssAddWork addWork;            /* 0x04 */
    void *animWatchTask;                /* 0x28: idle animation watcher task */
    BtlvMcssIdentity identity;          /* 0x2c */
    u32 colorCode;                      /* 0x3c: Pokemon value 0x98, used as a color/type code by effect scripts */
    u32 attrFlags;                      /* 0x40: BTLV_MCSS_ATTR_* */
    int animPending;                    /* 0x44: set when an animation index was chosen, cleared by its callback */
    int pos;                            /* 0x48: BtlvMcssPos, 0xff = none */
    BtlvMcssSpriteFlags flags;          /* 0x4c */
    int tintLevel;                      /* 0x50: status tint intensity step 0..12 */
    int tintStep;                       /* 0x54: +1 / -1 */
    int tintTimer;                      /* 0x58 */
} BtlvMcssSprite;

/* Bits of BtlvMcssWork.flags. */
typedef struct BtlvMcssWorkFlags {
    unsigned int triple : 1;            /* bit 0: triple battle layout */
    unsigned int rotation : 1;          /* bit 1: rotation battle layout */
    unsigned int rotating : 1;          /* bit 2: a rotation animation runs, idle animation and status tint stop */
    unsigned int reserved3 : 29;
} BtlvMcssWorkFlags;

/* The sprite system of the battle view. */
typedef struct BtlvMcssWork {
    void *taskOwner;                    /* 0x000: owner of the tween tasks */
    struct McssSystem *mcss;            /* 0x004 */
    BtlvMcssSprite sprites[BTLV_MCSS_SPRITE_MAX]; /* 0x008 */
    BtlvMcssWorkFlags flags;            /* 0x510 */
    u32 positionTweenMask;              /* 0x514: bit per position with a running position, shake or bounce task */
    u32 shadowScaleTweenMask;           /* 0x518 */
    u32 rotateTweenMask;                /* 0x51c */
    u32 scaleTweenMask;                 /* 0x520 */
    u32 drawScaleTweenMask;             /* 0x524 */
    u32 blinkTaskMask;                  /* 0x528 */
    u32 alphaTweenMask;                 /* 0x52c */
    u32 mosaicTweenMask;                /* 0x530 */
    int orthoActive;                    /* 0x534 */
    int scaleEven;                      /* 0x538: fx32 scale factor of the player side */
    int scaleOdd;                       /* 0x53c: fx32 scale factor of the opponent side */
    u16 heapId;                         /* 0x540 */
    /* Per position task serial numbers: a task ends when its serial no longer matches. */
    u8 positionSerial[BTLV_MCSS_SPRITE_MAX];     /* 0x542: also used by shake and bounce */
    u8 shadowScaleSerial[BTLV_MCSS_SPRITE_MAX];  /* 0x550 */
    u8 scaleSerial[BTLV_MCSS_SPRITE_MAX];        /* 0x55e */
    u8 drawScaleSerial[BTLV_MCSS_SPRITE_MAX];    /* 0x56c */
    u8 rotateSerial[BTLV_MCSS_SPRITE_MAX];       /* 0x57a */
    u8 blinkSerial[BTLV_MCSS_SPRITE_MAX];        /* 0x588 */
    u8 alphaSerial[BTLV_MCSS_SPRITE_MAX];        /* 0x596 */
    u8 mosaicSerial[BTLV_MCSS_SPRITE_MAX];       /* 0x5a4 */
    u8 sizePad[2];                      /* 0x5b2: rounds the 0x5b2 bytes up to the 0x5b4 allocation */
} BtlvMcssWork;

/* Parameters of BTLV_MCSS_StartShakeTask (filled by the effect script command; the task state follows). */
typedef struct BtlvMcssShakeParams {
    BtlvMcssWork *work;                 /* 0x00: set by the starter */
    int pos;                            /* 0x04 */
    int mode;                           /* 0x08: bit 0 runs the wave backwards, bits 1-2 plane (0 yz, 1 xz, 2 xy) */
    int waveStart;                      /* 0x0c: 0..3, the quarter of the wave that starts the motion */
    int amplitudeX;                     /* 0x10 */
    int amplitudeY;                     /* 0x14 */
    int stepsPerCycle;                  /* 0x18 */
    int stepInterval;                   /* 0x1c: frames per step */
    int cycles;                         /* 0x20 */
    int cyclePause;                     /* 0x24: frames between cycles */
    int phase;                          /* 0x28: 16.16 fraction of a turn */
    int phaseStep;                      /* 0x2c */
    int intervalCounter;                /* 0x30 */
    int pauseCounter;                   /* 0x34 */
    int serial;                         /* 0x38 */
} BtlvMcssShakeParams;

/* Parameters of BTLV_MCSS_StartBounceTask. */
typedef struct BtlvMcssBounceParams {
    BtlvMcssWork *work;                 /* 0x00: set by the starter */
    int pos;                            /* 0x04 */
    BtlvMcssVec startPosition;          /* 0x08: sprite position when the task began, never read again */
    int axisY;                          /* 0x14: nonzero moves along y, zero along x */
    int phase;                          /* 0x18: angle accumulator */
    int phaseStep;                      /* 0x1c */
    int amplitude;                      /* 0x20 */
    int frames;                         /* 0x24: frames left */
    int serial;                         /* 0x28 */
} BtlvMcssBounceParams;

/* Old name used by btlv_input.c until that file is moved to BtlvMcssWork. */

#endif
