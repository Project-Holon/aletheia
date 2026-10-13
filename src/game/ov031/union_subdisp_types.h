/*
 * Types of the union room sub screen (ov031): the touch screen of the Union
 * Room. It shows the five appeal buttons, the chat mark and the last three
 * chat log lines. One work block of 0x80 bytes holds the graphics, the text
 * and the actors. The chat log lines are drawn by unit_021F0680.c, which uses
 * the same work. Needs u8, u16, u32 and s16 from the including file.
 */
#ifndef UNION_SUBDISP_TYPES_H
#define UNION_SUBDISP_TYPES_H

struct GameSystem;
struct GfFont;
struct MsgBank;
struct PrintSys;
struct PmsDraw;
struct BmpWin;
struct ClactUnit;
struct ClactActor;
struct ClactRes;

enum {
    UNION_SUBDISP_APPEAL_COUNT = 5,     /* actors 0..4 are the appeal buttons */
    UNION_SUBDISP_ACTOR_SCROLL_KNOB = 5,
    UNION_SUBDISP_ACTOR_COUNT = 6,
    UNION_SUBDISP_LINE_COUNT = 3        /* chat log lines on the screen */
};

/* How a chat line is drawn. */
enum {
    UNION_SUBDISP_LINE_PMS = 0,         /* easy chat sentence drawn by PMS_DRAW */
    UNION_SUBDISP_LINE_TEXT = 1         /* message printed into the line window */
};

/* Which chat log entry a line shows and how long its highlight runs. */
typedef struct UnionSubdispLineSlot {
    u16 timer;                  /* 0x00: 0 = the slot is free */
    u8 entryIndex;              /* 0x02: index in the chat log */
    u8 pad03;
} UnionSubdispLineSlot;

/* Window of a chat line and its pending transfer to VRAM. */
typedef struct UnionSubdispWinSlot {
    struct BmpWin *win;         /* 0x00: same window as lineWin[] */
    u8 transferPending;         /* 0x04: print not finished, transfer not done */
    u8 pad05[3];
} UnionSubdispWinSlot;

/* Geometry of one actor, as the clact add function reads it. */
typedef struct UnionSubdispActorParam {
    u16 x;
    u16 y;
    u16 anim;
    u16 bgPriority;
} UnionSubdispActorParam;

typedef struct UnionSubdispPos {
    s16 x;
    s16 y;
} UnionSubdispPos;

typedef struct UnionSubdispWork {
    struct GameSystem *gameSystem;                  /* 0x00 */
    u32 bgCharOffset;                               /* 0x04: char area of bg 5 */
    struct ClactRes *charRes;                       /* 0x08 */
    struct ClactRes *palRes;                        /* 0x0C */
    struct ClactRes *cellRes;                       /* 0x10 */
    struct ClactUnit *clactUnit;                    /* 0x14 */
    struct ClactActor *actor[UNION_SUBDISP_ACTOR_COUNT]; /* 0x18 */
    u8 appealNo;                                    /* 0x30: pressed appeal button, 0 = none */
    u8 inputResult;                                 /* 0x31: the chat log input handlers acted */
    u8 pad32[2];
    UnionSubdispLineSlot lineSlot[UNION_SUBDISP_LINE_COUNT]; /* 0x34 */
    struct PrintSys *printSys;                      /* 0x40 */
    struct GfFont *font;                            /* 0x44 */
    struct MsgBank *msgData;                        /* 0x48 */
    struct BmpWin *lineWin[UNION_SUBDISP_LINE_COUNT]; /* 0x4C */
    u32 lineKind[UNION_SUBDISP_LINE_COUNT];         /* 0x58: UNION_SUBDISP_LINE_* */
    UnionSubdispWinSlot winSlot[UNION_SUBDISP_LINE_COUNT]; /* 0x64 */
    struct PmsDraw *pmsDraw;                        /* 0x7C */
} UnionSubdispWork;

#endif
