/*
 * Hall of Fame viewer (dendou_view.c): work struct and table records.
 *
 * The viewer shows one Hall of Fame entry at a time. The (up to) six
 * Pokemon of the entry stand on an ellipse and rotate; the front one is
 * described in a detail window. Two actor halves (6 actors each) hold the
 * Pokemon of the entry shown now and the one being swapped in.
 */
#ifndef DENDOU_VIEW_TYPES_H
#define DENDOU_VIEW_TYPES_H

#include "../types.h"
#include "../arm9/dendou_savedata.h"

struct Strbuf;
struct BmpWin;
struct Bmp;
struct GfFont;
struct MsgData;
struct WordSet;
struct PrintQue;
struct PaletteFade;
struct Unit;
struct ClactActor;
struct BmpOamSys;
struct BmpOam;

#define DENDOU_VIEW_ROW_MAX 15
#define DENDOU_VIEW_MEMBER_MAX 6
#define DENDOU_VIEW_ACTOR_MAX 16
#define DENDOU_VIEW_RESOURCE_MAX 13
#define DENDOU_VIEW_HEAP 0x8c
#define DENDOU_VIEW_BUTTON_FIRST 12

/* States of the main loop; the handler table has one entry per state. */
enum {
    DENDOU_VIEW_STATE_INIT = 0,
    DENDOU_VIEW_STATE_EXIT = 1,
    DENDOU_VIEW_STATE_WAIT_WIPE = 2,
    DENDOU_VIEW_STATE_WAIT_BUTTON = 3,
    DENDOU_VIEW_STATE_OVERVIEW = 4,
    DENDOU_VIEW_STATE_CHANGE_ROW = 5,
    DENDOU_VIEW_STATE_ENTER_DETAIL = 6,
    DENDOU_VIEW_STATE_DETAIL = 7,
    DENDOU_VIEW_STATE_LEAVE_DETAIL = 8,
    DENDOU_VIEW_STATE_ROTATE = 9,
    DENDOU_VIEW_STATE_START_EXIT = 10,
    DENDOU_VIEW_STATE_END = 11
};

/* Results of the input readers. */
enum {
    DENDOU_VIEW_INPUT_PREV = 0,
    DENDOU_VIEW_INPUT_NEXT = 1,
    DENDOU_VIEW_INPUT_SWITCH = 2,
    DENDOU_VIEW_INPUT_CANCEL = 3,
    DENDOU_VIEW_INPUT_CONFIRM = 4,
    DENDOU_VIEW_INPUT_MEMBER_0 = 5,
    DENDOU_VIEW_INPUT_MEMBER_1 = 6,
    DENDOU_VIEW_INPUT_MEMBER_2 = 7,
    DENDOU_VIEW_INPUT_MEMBER_3 = 8,
    DENDOU_VIEW_INPUT_MEMBER_4 = 9,
    DENDOU_VIEW_INPUT_MEMBER_5 = 10,
    DENDOU_VIEW_INPUT_NONE = 0xFF
};

/* Actor slots 0-11 are the two halves of Pokemon actors; 12-15 are buttons. */
enum {
    DENDOU_VIEW_ACTOR_BUTTON_PREV = 12,
    DENDOU_VIEW_ACTOR_BUTTON_NEXT = 13,
    DENDOU_VIEW_ACTOR_BUTTON_SWITCH = 14,
    DENDOU_VIEW_ACTOR_BUTTON_CANCEL = 15
};

/* Caller-owned parameters (the proc argument). */
typedef struct DendouViewParams {
    void *gameData;   /* +0 */
    u16 source;       /* +4 0: latest entry list of the save block, else extra save 8 */
    u16 result;       /* +6 written on exit: 1 after the X action, 0 after cancel */
} DendouViewParams;

/* One Pokemon of a Hall of Fame entry (0x1C bytes): the record the arm9 loader exports. */
typedef struct RecordTarget DendouViewMember;

/* One Hall of Fame entry (0xBC bytes). */
typedef struct DendouViewRow {
    DendouViewMember members[DENDOU_VIEW_MEMBER_MAX]; /* +0x00 */
    u32 year;           /* +0xA8 */
    u32 month;          /* +0xAC */
    u32 day;            /* +0xB0 */
    u32 dateReserved;   /* +0xB4 the arm9 date loader (DENDOU_SAVEDATA_GetRecordDate/ED14) writes 0; no reader in ov171 */
    u16 memberCount;    /* +0xB8 */
    u16 hallNumber;     /* +0xBA ordinal printed in the title */
} DendouViewRow;

/* A text window plus its pending-transfer flag (8 bytes). */
typedef struct DendouViewWindow {
    struct BmpWin *win;   /* +0 */
    u8 transferPending;   /* +4 */
    u8 pad_05[3];         /* alignment */
} DendouViewWindow;

/* Template for CLACT_CreateActor; the first fields are read by the library. */
typedef struct DendouViewActorTemplate {
    s16 x;            /* +0x00 */
    s16 y;            /* +0x02 */
    u16 animSeq;      /* +0x04 */
    u16 layer;        /* +0x06 */
    s32 cgrSlot;      /* +0x08 index into DendouViewWork.cgrIds */
    s32 palSlot;      /* +0x0C index into DendouViewWork.palIds */
    s32 cellSlot;     /* +0x10 index into DendouViewWork.cellIds */
    u16 reserved;     /* +0x14 */
    u16 argLast;      /* +0x16 last argument of CLACT_CreateActor before the heap */
} DendouViewActorTemplate;

/* Start angle and fade level of one Pokemon on the ellipse, read from
   sMemberSlotsByCount (d_021DEC94) indexed by memberCount-1 and slot. */
typedef struct DendouViewSlot {
    u16 angle;
    u16 fadeLevel;
} DendouViewSlot;

/* Bmp OAM creation parameter. */
typedef struct DendouViewBmpOamParam {
    struct Bmp *bmp;   /* +0x00 */
    u16 x, y;          /* +0x04 */
    s32 paletteId;     /* +0x08 */
    u32 mode;          /* +0x0C */
    u8 a, b;           /* +0x10 */
    u16 id;            /* +0x12 */
    u32 extra;         /* +0x14 */
} DendouViewBmpOamParam;

/* Work struct, 0xC78 bytes. */
typedef struct DendouViewWork {
    DendouViewParams *params;                       /* +0x000 */
    u8 pad_004[8];                                  /* +0x004 */
    DendouViewRow rows[DENDOU_VIEW_ROW_MAX];        /* +0x00C */
    s16 angle[DENDOU_VIEW_MEMBER_MAX];              /* +0xB10 current angle per actor */
    s16 targetAngle[DENDOU_VIEW_MEMBER_MAX];        /* +0xB1C */
    struct TcbTask *vblankTaskId;                         /* +0xB28 */
    u8 pad_B2C[4];                                  /* +0xB2C */
    struct PaletteFade *palAnm;                          /* +0xB30 */
    u8 fadeSettled[DENDOU_VIEW_MEMBER_MAX];         /* +0xB34 */
    u8 fadeLevel[DENDOU_VIEW_MEMBER_MAX];           /* +0xB3A */
    u8 fadeTarget[DENDOU_VIEW_MEMBER_MAX];          /* +0xB40 */
    u8 pad_B46[2];                                  /* +0xB46 alignment before windows[] at +0xB48 */
    DendouViewWindow windows[2];                    /* +0xB48 title, detail */
    struct GfFont *fontBody;                        /* +0xB58 */
    struct GfFont *fontLevelLabel;                  /* +0xB5C */
    struct MsgData *msgData;                        /* +0xB60 */
    struct WordSet *wordSet;                        /* +0xB64 */
    struct Strbuf *textBuf;                         /* +0xB68 */
    struct PrintQue *printQueue;                    /* +0xB6C */
    struct Unit *clactUnit;                    /* +0xB70 */
    struct ClactActor *actors[DENDOU_VIEW_ACTOR_MAX]; /* +0xB74 */
    s32 cgrIds[DENDOU_VIEW_RESOURCE_MAX];           /* +0xBB4 */
    s32 palIds[DENDOU_VIEW_RESOURCE_MAX];           /* +0xBE8 */
    s32 cellIds[DENDOU_VIEW_RESOURCE_MAX];          /* +0xC1C */
    struct BmpOamSys *bmpOamSys;                    /* +0xC50 */
    struct BmpOam *pageBmpOam;                      /* +0xC54 */
    struct Bmp *pageBmp;                            /* +0xC58 */
    s8 cursor;                                      /* +0xC5C member in front */
    s8 selected;                                    /* +0xC5D member chosen */
    s8 rowIndex;                                    /* +0xC5E */
    u8 rowCount;                                    /* +0xC5F */
    u8 activeHalf;                                  /* +0xC60 1: actors 0-5 shown, 0: actors 6-11 */
    s8 rotationStep;                                /* +0xC61 degrees per frame */
    u8 rotationFramesLeft;                          /* +0xC62 */
    u8 pad_C63;                                     /* +0xC63 alignment before buttonActor at +0xC64 */
    s32 buttonActor;                                /* +0xC64 */
    s32 stateAfterButton;                           /* +0xC68 */
    s32 state;                                      /* +0xC6C */
    s32 substate;                                   /* +0xC70 */
    s32 wipeNextState;                              /* +0xC74 */
} DendouViewWork;

#endif
