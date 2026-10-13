#ifndef GAME_OV067_FRAME_LIST_TYPES_H
#define GAME_OV067_FRAME_LIST_TYPES_H

/*
 * Types of the scrolling frame list (frame_list.c): a vertical list of rows
 * drawn into a background layer that scrolls by touch, d-pad, scroll bar and
 * flick. One FrameList object is built from a FrameListParams.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct BlinkPalAnm;
struct PrintSys;
struct BgWinFrm;
struct BmpWin;

struct FrameListWindow {
    struct BmpWin *window;
    u8 busy;
    u8 pad[3];
};

struct FrameListOps {
    void (*drawRow)(void *userData, int item, struct FrameListWindow *window, short y, int topSet);
    void (*onCursor)(void *userData, int item, int play);
    void (*onScroll)(void *userData, int speed);
};

struct FrameListItem {
    u32 mapIndex;
    u32 value;
};

/* What a touch region does (FrameListHitEntry.kind). */
enum FrameListHitKind {
    FRAME_LIST_HIT_ROW = 0,        /* row: select it and allow a drag */
    FRAME_LIST_HIT_SCROLL_BAR = 1,
    FRAME_LIST_HIT_ARROW_UP = 2,
    FRAME_LIST_HIT_ARROW_DOWN = 3,
    FRAME_LIST_HIT_PAGE_UP = 4,
    FRAME_LIST_HIT_PAGE_DOWN = 5,
    FRAME_LIST_HIT_JUMP_TOP = 6,
    FRAME_LIST_HIT_JUMP_BOTTOM = 7,
    FRAME_LIST_HIT_ROW_CONFIRM = 8 /* row: select it and confirm at once */
};

/* Input events found by the touch and key readers, handled by HandleInput. */
enum FrameListEvent {
    FRAME_LIST_EVENT_KEY_MODE = 0,
    FRAME_LIST_EVENT_CURSOR_STEP = 1,
    FRAME_LIST_EVENT_ARROW_UP = 2,
    FRAME_LIST_EVENT_ARROW_DOWN = 3,
    FRAME_LIST_EVENT_PAGE_UP = 4,
    FRAME_LIST_EVENT_PAGE_DOWN = 5,
    FRAME_LIST_EVENT_CURSOR_TOP = 6,
    FRAME_LIST_EVENT_CURSOR_BOTTOM = 7,
    FRAME_LIST_EVENT_JUMP_TOP = 8,
    FRAME_LIST_EVENT_JUMP_BOTTOM = 9,
    FRAME_LIST_EVENT_SCROLL_BAR = 10,
    FRAME_LIST_EVENT_ROW_TOUCH = 11,
    FRAME_LIST_EVENT_CONFIRM = 12,
    FRAME_LIST_EVENT_IGNORED = 13,
    FRAME_LIST_EVENT_NONE = 14
};

/* Touch region of the list; the table ends with left == 0xFF. */
struct FrameListHitEntry {
    u8 left;
    u8 top;
    u8 right;
    u8 bottom;
    u32 kind;
};

struct FrameListHitRect {
    u8 left;
    u8 top;
    u8 right;
    u8 bottom;
};

/* Layout of the list as the caller gives it. */
typedef struct FrameListParams {
    u8 bgLayer;
    u8 bgLayerB;
    u8 tileX;
    s8 firstRow;
    u8 tileWidth;
    u8 rowHeight;
    u8 winX;
    u8 winY;
    u8 winW;
    u8 winH;
    u8 winPltt;
    u8 stepTable[6];
    u8 cursorPltt;
    u8 scrollBarPad;
    u8 pad13;
    u16 itemCount;
    u16 mapCount;
    u8 initialCursor;
    u8 visibleRows;
    u16 initialScroll;
    const struct FrameListHitEntry *hitEntries;
    const struct FrameListOps *ops;
    void *userData;
} FrameListParams;

typedef struct FrameList {
    FrameListParams params;
    struct FrameListItem *items;
    struct FrameListHitRect *hitRects;
    struct BlinkPalAnm *cursorAnim;
    struct PrintSys *printer;
    struct FrameListWindow *windows;
    struct BgWinFrm *frameMgr;
    u16 **maps;
    u8 windowCount;
    u8 windowCountHalf;
    s8 ringA;
    s8 ringB;
    u8 ringSizeA;
    u8 ringSizeB;
    s8 rowRemainder;
    u8 pad4B;
    u16 totalItems;
    u16 state;
    u16 returnState;
    u16 reserved52;
    u32 touchY;
    int prevTouchY;
    s16 cursor;
    u16 visibleCount;
    s16 prevCursor;
    s16 scrollPos;
    u16 scrollMax;
    s8 pixelOffset;
    s8 scrollSpeed;
    u8 stepsLeft;
    u8 stepFramesLeft;
    u16 reserved6A;
    u32 playScrollSe;
    u32 flicking;
    u8 scrollBarRect[5];
    u8 pad79[3];
    u8 tappedRow;
    u8 scrollBarX;
    u8 scrollBarY;
    u8 scrollBarDrag;
    u32 scrollBarTouchY;
    u8 dragPhase;
    s8 dragDelta;
    u8 dragFrames : 5;
    u8 ready : 1;
    u8 drag : 1;
    u8 trigger : 1;
    u8 dragAnchorRow;
    u8 dragRow;
    u8 speedIndex;
    u16 reserved8A;
    u32 dragStartY;
    u32 dragLastY;
    /* stand-in: volatile only because FRAME_LIST_UpdateHoldStage reloads the counter after the store */
    volatile u8 holdFrames;
    u8 holdStage;
    u8 repeatDelay;
    u8 pad97;
    u16 heapId;
    u8 pad9A[2];
} FrameList;

#endif
