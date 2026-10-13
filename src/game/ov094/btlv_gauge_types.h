#ifndef BTLV_GAUGE_TYPES_H
#define BTLV_GAUGE_TYPES_H

#include "btlv_b_gauge_types.h"

/* Values of BTL_POKEPARAM read through func_021D59B4. */
#define BTLV_GAUGE_BPP_HP 13
#define BTLV_GAUGE_BPP_MAX_HP 14
#define BTLV_GAUGE_BPP_LEVEL 15
#define BTLV_GAUGE_BPP_FORM 19

/* Sound numbers. */
#define BTLV_GAUGE_SE_LEVEL_UP 0x56e
#define BTLV_GAUGE_BGM_LOW_HP 0x47a

#define BTLV_GAUGE_SLOT_COUNT 8
#define BTLV_GAUGE_BAR_TILES 6
#define BTLV_GAUGE_EXP_TILES 10

/* Base of the sub-engine-independent OBJ VRAM that actor images are copied to. */
typedef enum BtlvGaugeVramBase {
    BTLV_GAUGE_OBJ_VRAM = 0x06400000
} BtlvGaugeVramBase;

/* Loop index type of BTLV_B_GAUGE_SetSideVisible (an enum keeps the entry guard of the loop). */
typedef enum BtlvGaugeSlotIndex {
    BTLV_GAUGE_SLOT_FIRST = 0
} BtlvGaugeSlotIndex;

typedef struct BtlvGaugePointPair {
    BtlvGaugePoint p[2];
} BtlvGaugePointPair;

typedef struct BtlvGaugePointSix {
    BtlvGaugePoint p[6];
} BtlvGaugePointSix;

typedef struct BtlvGaugePointEight {
    BtlvGaugePoint p[8];
} BtlvGaugePointEight;

/* Image record filled by CLACT_GetActorImageProxy (36 bytes). */
typedef struct BtlvGaugeImageProxy {
    u32 attr;
    u32 vramOffset;     /* 0x04: offset of the actor character data inside OBJ VRAM */
    u32 reserved[7];
} BtlvGaugeImageProxy;

/* Per slot flag word (slot offset 0x70). */
typedef struct BtlvGaugeSlotFlags {
    u32 hpAnimating : 1;        /* bit 0 */
    u32 expAnimating : 1;       /* bit 1 */
    u32 levelUpPending : 1;     /* bit 2 */
    u32 occupied : 1;           /* bit 3: the slot shows a Pokemon */
    u32 levelUpPhase : 4;       /* bits 4-7 */
    u32 expStep : 8;            /* bits 8-15 */
    u32 slideCount : 4;         /* bits 16-19: frames left of the slide task */
    u32 selected : 1;           /* bit 20: raised as the chosen target */
    u32 hitFlashFrames : 5;     /* bits 21-25 */
    u32 hitFlashOn : 1;         /* bit 26 */
    u32 eventPending : 1;       /* bit 27: set by the battle view, cleared by TakeSlotEvent */
    u32 startPending : 1;       /* bit 28: an animation was requested */
    u32 visible : 1;            /* bit 29 */
    u32 hidden : 1;             /* bit 30 */
    u32 reserved31 : 1;         /* bit 31 */
} BtlvGaugeSlotFlags;

/* One HP/EXP gauge (0x80 bytes). */
typedef struct BtlvGaugeSlot {
    struct ClActor *frameActor;     /* 0x00: plate that carries nickname, gender, level and caught icon */
    struct ClActor *hpNumberActor;  /* 0x04: "current/max" numbers, player side only */
    struct ClActor *hpBarActor;     /* 0x08 */
    struct ClActor *hpLossActor;    /* 0x0c: marks the HP that was just lost */
    struct ClActor *expBarActor;    /* 0x10: player side only */
    struct ClActor *statusActor;    /* 0x14: status condition icon */
    int frameCharRes;               /* 0x18: resource ids of the actors above */
    int frameCellRes;               /* 0x1c */
    int numberCharRes;              /* 0x20 */
    int numberCellRes;              /* 0x24 */
    int barCharRes;                 /* 0x28 */
    int barCellRes;                 /* 0x2c */
    int lossCharRes;                /* 0x30 */
    int lossCellRes;                /* 0x34 */
    int expCharRes;                 /* 0x38: player side only */
    int expCellRes;                 /* 0x3c */
    int layout;                     /* 0x40: selects the position table (0..3, 4 = no gauge) */
    int side;                       /* 0x44: 0 = player, 1 = opponent */
    int hp;                         /* 0x48 */
    int maxHp;                      /* 0x4c */
    int hpAnimValue;                /* 0x50: bar fill accumulator, 0x80000000 = not started */
    int exp;                        /* 0x54: EXP inside the current level */
    int expMax;                     /* 0x58 */
    int expPerLevel;                /* 0x5c: EXP span of the current level */
    int expDelta;                   /* 0x60: negative while the bar grows */
    int expAnimValue;               /* 0x64 */
    int hpDelta;                    /* 0x68: HP lost by the last change (negative = healed) */
    u8 level;                       /* 0x6c */
    u8 gender;                      /* 0x6d: 0 male, 1 female, 2 none */
    u8 unused6e;                    /* 0x6e */
    u8 caught;                      /* 0x6f: shows the "already caught" icon */
    BtlvGaugeSlotFlags flags;       /* 0x70 */
    int hpAnimSpeed;                /* 0x74: 0 = jump to the target */
    int hpBarPixels;                /* 0x78: filled pixels of the HP bar */
    void *slideTask;                /* 0x7c */
} BtlvGaugeSlot;

/* Flag word of the gauge set (offset 0x440). */
typedef struct BtlvGaugeWorkFlags {
    u32 reserved0 : 1;              /* bit 0 */
    u32 bgmChangePending : 1;       /* bit 1: a BGM fade out is running */
    u32 lowHpBgmPlaying : 1;        /* bit 2 */
    u32 bgmReplaced : 1;            /* bit 3 */
    u32 altDisplay : 1;             /* bit 4: alternate actor shown on layouts 2 and 3 */
    u32 bobAngle : 16;              /* bits 5-20: phase of the bob of the selected slot */
    u32 lowHpBgmSuppressed : 1;     /* bit 21 */
    u32 stopRequested : 1;          /* bit 22 */
    u32 reserved23 : 9;             /* bits 23-31 */
} BtlvGaugeWorkFlags;

/* The battle HP/EXP gauge set: eight slots and the shared resources. */
typedef struct BtlvGaugeWork {
    struct ClUnit *unit;            /* 0x00: actor unit of all gauge actors */
    void *arcHandle;                /* 0x04: archive of the gauge graphics */
    void *font;                     /* 0x08 */
    void *flashTask;                /* 0x0c: palette flash task */
    void *screenData;               /* 0x10: loaded file that holds tileGfx */
    char *tileGfx;                  /* 0x14: gauge tile graphics copied into actor images */
    int palRes[6];                  /* 0x18: palette resources of the gauge plates */
    int statusCharRes;              /* 0x30 */
    int statusCellRes;              /* 0x34 */
    int statusPalRes[2];            /* 0x38: normal and alternate status icon palette */
    BtlvGaugeSlot slots[BTLV_GAUGE_SLOT_COUNT];     /* 0x40 */
    BtlvGaugeWorkFlags flags;       /* 0x440 */
    int savedBgmNo;                 /* 0x444: BGM to restore after the low HP music */
    u16 heapId;                     /* 0x448 */
} BtlvGaugeWork;

/* Loaded graphics file of the gauge: tile pixel data at 0x14. */
typedef struct BtlvGaugeTileFile {
    u8 header[0x14];
    char *pixels;
} BtlvGaugeTileFile;

typedef struct BtlvGaugeFlashTask {
    struct BtlvGaugeWork *work;     /* gauge set whose slots are flashed */
    int state;
    int mask;
    int count;
} BtlvGaugeFlashTask;

typedef struct BtlvGaugeMaskTable {
    int bits[8];
} BtlvGaugeMaskTable;

typedef struct BtlvGaugeStatusAnimTable {
    u32 anim[7];
} BtlvGaugeStatusAnimTable;

#endif
