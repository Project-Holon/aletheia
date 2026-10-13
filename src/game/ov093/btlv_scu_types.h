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

struct BtlvScu;

/* One state step of a battle view procedure: returns nonzero when done. */
typedef int (*BtlvScuProc)(int *state, struct BtlvScu *scu);
typedef int (*BtlvScuPhaseProc)(struct BtlvScu *scu, int *state);

/* Slide animation of the message window (fields 0x154..0x16B of BtlvScu). */
typedef struct BtlvScuWinSlide {
    struct BmpWin *win;
    int x;
    int y;
    int dx;
    int dy;
    u8 state;
    u8 timer;
} BtlvScuWinSlide;

/* Per-monster sprite slot, 12 bytes, 12 slots from offset 0x48. */
typedef struct BtlvScuMonSlot {
    void *sprite;
    struct BtlvScu *owner;
    u8 monIdx;
    u8 state;
    u8 flagA;
    u8 flagB;
} BtlvScuMonSlot;

/* State of the battle entry scene, 16 bytes at offset 0xF0. */
typedef union BtlvScuIntroState {
    struct {
        struct BtlPokeParam *mon;
        u8 monIdx;
        u8 side;
        u8 monId;
        u8 trainerIdx;
    } single;
    struct {
        struct BtlPokeParam *mon[2];
        u8 monId[2];
        u8 monIdx[2];
        u8 side[2];
        u8 reserved14;
        u8 localSide;
    } dbl;
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
    u32 taskHandle;                 /* 0x030 */
    struct MsgBuf *textBuf;         /* 0x034 */
    struct MsgBuf *wordBuf0;        /* 0x038 */
    struct MsgBuf *wordBuf1;        /* 0x03C */
    u8 reserved40[8];
    BtlvScuMonSlot monSlots[12];    /* 0x048 */
    u32 cmdResult;                  /* 0x0D8 */
    u32 reservedDC;
    BtlvScuProc preProc;            /* 0x0E0 */
    BtlvScuProc mainProc;           /* 0x0E4 */
    struct BtlvScu *procScu;        /* 0x0E8 */
    int procState;                  /* 0x0EC */
    BtlvScuIntroState intro;        /* 0x0F0 */
    u8 reserved100[0x30];
    struct BtlvCore *core;          /* 0x130 */
    struct BtlContext *context;     /* 0x134 */
    struct BtlMonTable *monTable;   /* 0x138 */
    u16 heapId;                     /* 0x13C */
    u8 reserved13E[2];
    u8 clientIndex;                 /* 0x140 */
    u8 reserved141[13];
    u8 busyFlag;                    /* 0x14E */
    u8 phase;                       /* 0x14F */
    u8 quickMode;                   /* 0x150 */
    u8 reserved151[3];
    BtlvScuWinSlide slide;          /* 0x154 */
    u8 tail[0x14];                  /* 0x16C, end of the 0x180 allocation */
} BtlvScu;

#endif
