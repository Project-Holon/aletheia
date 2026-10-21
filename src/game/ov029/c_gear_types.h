#ifndef C_GEAR_TYPES_H
#define C_GEAR_TYPES_H

#include "../types.h"

/*
 * Work of the C-Gear panel (ov029, c_gear.c and its tail unit_021F2C10.c).
 * The panel draws a hex tile board of 9 columns by 4 rows; odd columns have
 * one row fewer (see C_GEAR_IsColumnRowValid). Allocated with size 0x468.
 * Needs u8, u16, u32 and s16 from the including file.
 */

struct ClactActor;
struct Unit;
struct ActorResources;
struct ButtonTask;
struct FadeCtx;
struct GameSystem;
struct HexMap;
struct PaletteFade;
struct VBlankTask;

struct CGearWork;
typedef void (*CGearStepFunc)(struct CGearWork *work);

/* Sprite slot: one animated actor per lit tile, at most 20 at once. */
typedef struct CGearActorSlot {
    struct ClactActor *actor;
    int col;
    int row;
} CGearActorSlot;

/* File descriptor filled by the archive loader. */
typedef struct CGearFileInfo {
    u8 gap00[8];
    u32 size;
    u8 *data;
} CGearFileInfo;

/* Base tile number of each tile kind in the tile map. */
typedef struct CGearTileBases {
    int base[6];
} CGearTileBases;

/* Intro flash table entry: the tile at (col, row) starts flashing at tick startTick. */
typedef struct CGearFlashStep {
    u8 startTick;
    u8 col;
    u8 row;
    u8 stepPeriod;
} CGearFlashStep;

/* One value per column parity: even columns, odd columns. */
typedef struct CGearParityPair {
    int value[2];
} CGearParityPair;

/* Tile flash animation: a 5 step palette ramp played forwards then back. */
typedef struct CGearTile {
    u16 active : 1;
    u16 tick : 15;
    u16 stepPeriod;     /* ticks per animation step */
    u8 palRow;          /* row of the tile palette table (tile kind) */
    u8 stopStep;        /* step at which the backwards pass stops */
    u8 col;
    u8 row;
} CGearTile;

/* Palette tab timer: three counters that count up to `limit`. */
typedef struct CGearTabTimer {
    u16 count[3];
    u16 limit;
    u8 resetOnFire;
    u8 running;
} CGearTabTimer;

/*
 * Palette flash of one sprite: while `active` is set, the step function
 * requests a palette fade each frame until the sprite animation ends.
 */
typedef struct CGearFadeFx {
    int active;
    int palette;            /* palette offset handed to PALANM_RequestFade */
    struct ClactActor *actor;
    struct PaletteFade *palAnm;
    struct FadeCtx *fadeCtx;
} CGearFadeFx;

typedef struct CGearWork {
    CGearStepFunc stepFunc;         /* 0x000 */
    u8 unused004[8];
    u16 heapId;                     /* 0x00C */
    u8 unused00E[2];
    struct ButtonTask *buttonTask;  /* 0x010 */
    u32 bgCharBlock;                /* 0x014, low half: base, high half: size */
    int parentWork;                 /* 0x018 */
    struct GameSystem *gameSystem;  /* 0x01C */
    struct HexMap *hexMap;          /* 0x020 */
    void *archive;                  /* 0x024 */
    int spritePlttRes;              /* 0x028 */
    int spriteCharRes;              /* 0x02C */
    int spriteAnimRes;              /* 0x030 */
    struct Unit *spriteSystem;       /* 0x034 */
    struct ActorResources *spriteResList;   /* 0x038 */
    CGearActorSlot actorSlots[20];  /* 0x03C */
    struct ClactActor *hudActors[11];    /* 0x12C, clock digits, battery, icons */
    struct ClactActor *tileMarkerActors[3];      /* 0x158 */
    struct ClactActor *barActors[3];     /* 0x164 */
    struct ClactActor *splashActors[18]; /* 0x170 */
    u32 beaconColors[17];           /* 0x1B8, [16]: no beacon */
    void (*endCallback)(int);       /* 0x1FC */
    int endCallbackArg;             /* 0x200 */
    struct FadeCtx *fadeCtx;        /* 0x204 */
    struct VBlankTask *palTransferTask;     /* 0x208 */
    void *fadeMem;                  /* 0x20C */
    struct PaletteFade *palAnm;          /* 0x210 */
    int command;                    /* 0x214 */
    int lastCommand;                /* 0x218 */
    CGearFadeFx fadeFx;             /* 0x21C */
    u16 basePalette[3][5];          /* 0x230 */
    u16 blendPalette[3][5];         /* 0x24E */
    u16 targetPalIndex[3];          /* 0x26C */
    u16 targetPalette[9][5];        /* 0x272 */
    u16 touchX;                     /* 0x2CC */
    u16 touchY;                     /* 0x2CE */
    CGearTile tiles[9][4];          /* 0x2D0 */
    u8 grid[9][4];                  /* 0x3F0 */
    u8 rippleKind;                  /* 0x414 */
    u8 rippleStep;                  /* 0x415 */
    u8 activeIcon;                  /* 0x416, index into hudActors */
    u8 pad417;
    CGearTabTimer tabTimers[5];     /* 0x418 */
    u8 tabState[3];                 /* 0x44A */
    u8 keyCycle;                    /* 0x44D */
    u8 pad44E[2];
    u8 beaconPending;               /* 0x450 */
    u8 commEvent;                   /* 0x451 */
    u8 selectedCol;                 /* 0x452 */
    u8 selectedRow;                 /* 0x453 */
    u8 powerOn;                     /* 0x454 */
    u8 phase;                       /* 0x455 */
    u8 phaseTimer;                  /* 0x456 */
    u8 paintMode;                   /* 0x457 */
    u8 skinIndex;                   /* 0x458 */
    u8 colorTheme;                  /* 0x459 */
    u8 commEnabled;                 /* 0x45A */
    u8 agbSlotPresent;              /* 0x45B */
    u8 offIndicator;                /* 0x45C */
    u8 commIndicator;               /* 0x45D */
    u8 indicatorDirty;              /* 0x45E */
    u8 indicatorTimer;              /* 0x45F */
    u8 refreshFlag;                 /* 0x460 */
    u8 tabMode;                     /* 0x461 */
    u8 ringtoneActive;              /* 0x462 */
    u8 callTabShown;                /* 0x463 */
    u8 tabVariant;                  /* 0x464 */
    u8 tabActive;                   /* 0x465 */
    u8 tabFrame;                    /* 0x466 */
    u8 pad467;
} CGearWork;

/* Request that a panel button hands to the event system. */
typedef struct CGearEventWork {
    CGearWork *work;
    int kind;
} CGearEventWork;

/* Argument block of the sub-process that event kind 12 launches. */
typedef struct CGearSubprocArgs {
    u8 *playerData;
    struct GameSystem *gameSystem;
} CGearSubprocArgs;

#endif
