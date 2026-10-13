#ifndef BTLV_SCU_TYPES_H
#define BTLV_SCU_TYPES_H

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

/* Opaque types owned by other files of the battle code. */
struct BtlvCore;
struct BtlContext;
struct BtlMonTable;
struct BtlPokeParam;
struct BmpWin;
struct CharBuf;
struct PrintSys;
struct MsgBuf;
struct Bmp;
struct PrintStream;

struct BtlvScu;

/* One state step of a battle view procedure: returns nonzero when done. */
typedef int (*BtlvScuProc)(int *state, struct BtlvScu *scu);
typedef int (*BtlvScuPhaseProc)(struct BtlvScu *scu, int *state);

/*
 * Fade of the message window (fields 0x154..0x16B of BtlvScu): the window is
 * blended in and out through the alpha blend registers. evA and evB are the
 * two blend coefficients in 20.12 fixed point, moved by the deltas once per
 * frame. State: 0 shown, 1 fading out, 2 hidden, 3 fading in, 4 fade-in
 * requested.
 */
typedef struct BtlvScuWinSlide {
    struct BmpWin *win;
    int evA;
    int evB;
    int evADelta;
    int evBDelta;
    u8 state;
    u8 stepsLeft;
} BtlvScuWinSlide;

/* Per-monster sprite slot, 12 bytes, 6 slots from offset 0x48. */
typedef struct BtlvScuMonSlot {
    struct BtlPokeParam *mon;       /* monster shown in the slot, 0 when none */
    struct BtlvScu *owner;
    u8 slotIdx;
    u8 viewPos;                     /* view position of the slot */
    u8 isShown;                     /* sprite is on screen */
    u8 isActive;                    /* slot is in use */
} BtlvScuMonSlot;

/* Name plate of one side, 0x24 bytes, 2 plates from offset 0x90. */
typedef struct BtlvScuNamePlate {
    struct BtlvScu *scu;
    struct Bmp *bmp;                /* 18 x 4 tiles, 4 bits per pixel */
    u16 speciesId;                  /* species the plate was drawn for */
    u8 sideIdx;                     /* 0 local side, 1 opposing side */
    u8 bgPlane;
    u8 pokeId;                      /* 0x1F when none */
    u8 phase;                       /* step of the plate procedures */
    u8 reserved0E[2];
    u8 *templatePixels;             /* background template for this side */
    int slideX;                     /* 20.12 fixed point scroll */
    int slideDx;
    u32 tile;
    u8 timer;
    u8 counter;
    u8 isShown : 1;
    u8 closeRequested : 1;
    u8 reserved23;
} BtlvScuNamePlate;

/* Loaded graphics file of the name plates: pixel data at 0x14. */
typedef struct BtlvScuNameGfx {
    u8 header[0x14];
    u8 *pixels;
} BtlvScuNameGfx;

/* Request handed to the move effect player (0x14 bytes). */
typedef struct BtlvScuWazaRequest {
    u16 wazaId;
    int attackerPos;                /* view positions */
    int defenderPos;
    u8 turnCount;
    u8 continueCount;
    int effectSeq;
} BtlvScuWazaRequest;

/* State of the battle entry scene, 16 bytes at offset 0xF0. */
typedef union BtlvScuIntroState {
    struct {
        struct BtlPokeParam *mon;
        u8 monIdx;
        u8 side;
        u8 monId;
        u8 trainerIdx;
        u8 opponentClient;
    } single;
    struct {
        struct BtlPokeParam *mon[2];
        u8 monId[2];
        u8 monIdx[2];
        u8 side[2];
        u8 reserved14;
        u8 localSide;
    } dbl;
    /* Trainer intro: view positions of the one or two trainer sprites. */
    struct {
        u8 side[2];
    } trainers;
    /* Send-out of two monsters (double battle). */
    struct {
        struct BtlPokeParam *mon[2];
        u8 monIdx[2];
        u8 side[2];
        u8 monId[2];
        u8 aliveCount;
        u8 clientId;
    } pair;
    /* Send-out of three monsters (triple battle). */
    struct {
        struct BtlPokeParam *mon[3];
        u8 monIdx[3];
        u8 side[3];
        u8 monId[3];
        u8 aliveCount;
        u8 clientId;
    } triple;
    /* Move effect request (the same bytes serve all scenes in turn). */
    BtlvScuWazaRequest waza;
} BtlvScuIntroState;

/* Battle view sub-unit: message windows, entry scenes and monster slots. */
typedef struct BtlvScu {
    struct BmpWin *msgWin;          /* 0x000 */
    struct CharBuf *msgWinChars;    /* 0x004 */
    struct BmpWin *nameWin;         /* 0x008 */
    struct CharBuf *nameWinChars;   /* 0x00C */
    u32 nameTile;                   /* 0x010 */
    u32 msgTile;                    /* 0x014 */
    struct PrintSys *printer;       /* 0x018 */
    struct BmpWin *msgWinCopy;      /* 0x01C */
    u8 lineIndex;                   /* 0x020 */
    u8 reserved21[3];
    void *fontMain;                 /* 0x024 */
    void *fontSub;                  /* 0x028 */
    void *taskSys;                  /* 0x02C */
    struct PrintStream *msgStream;  /* 0x030, running message stream */
    struct MsgBuf *textBuf;         /* 0x034 */
    struct MsgBuf *wordBuf0;        /* 0x038 */
    struct MsgBuf *wordBuf1;        /* 0x03C */
    u8 monTaskCount;                /* 0x040, running mon sprite and window fade tasks */
    u8 sendOutTaskCount;            /* 0x041 */
    u8 withdrawTaskCount;           /* 0x042 */
    u8 reserved43[5];
    BtlvScuMonSlot monSlots[6];     /* 0x048 */
    BtlvScuNamePlate namePlates[2]; /* 0x090 */
    void *nameGfxFile;              /* 0x0D8, memory block of the plate graphics */
    BtlvScuNameGfx *nameGfx;        /* 0x0DC */
    BtlvScuProc preProc;            /* 0x0E0 */
    BtlvScuProc mainProc;           /* 0x0E4 */
    struct BtlvScu *procScu;        /* 0x0E8 */
    int procState;                  /* 0x0EC */
    BtlvScuIntroState intro;        /* 0x0F0, 0x18 bytes */
    u8 reserved108[0x28];
    struct BtlvCore *core;          /* 0x130 */
    struct BtlContext *context;     /* 0x134 */
    struct BtlMonTable *monTable;   /* 0x138 */
    u16 heapId;                     /* 0x13C */
    u8 msgKeepText;                 /* 0x13E, text already printed */
    u8 msgStep;                     /* 0x13F, state of the message procedure */
    u8 clientIndex;                 /* 0x140 */
    u8 msgEnded;                    /* 0x141, stream finished, read once */
    u8 reserved142[2];
    int msgStreamState;             /* 0x144, 1 paused, 2 finished */
    u16 msgWait;                    /* 0x148, frames left to wait */
    u16 msgWaitReload;              /* 0x14A */
    u16 msgWaitEnd;                 /* 0x14C */
    u8 busyFlag;                    /* 0x14E */
    u8 phase;                       /* 0x14F */
    u8 quickMode;                   /* 0x150 */
    u8 reserved151[3];
    BtlvScuWinSlide slide;          /* 0x154 */
    u8 tail[0x14];                  /* 0x16C, end of the 0x180 allocation */
} BtlvScu;

#endif
