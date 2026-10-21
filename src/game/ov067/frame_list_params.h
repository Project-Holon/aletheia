#ifndef GAME_OV067_FRAME_LIST_PARAMS_H
#define GAME_OV067_FRAME_LIST_PARAMS_H

#include "../types.h"
/*
 * FrameListParams and the records a caller fills in to build a frame list.
 * Split from frame_list_types.h so a file with its own base typedefs (ov209
 * zukan_list.c) can include it: this header redeclares no base types, the
 * includer must define u8, u16 and u32 first, as elsewhere in this tree.
 */

struct FrameListWindow;

/* Row drawing, cursor and scroll callbacks of a frame list. */
struct FrameListOps {
    void (*drawRow)(void *userData, int item, struct FrameListWindow *window, short y, int topSet);
    void (*onCursor)(void *userData, int item, int play);
    void (*onScroll)(void *userData, int speed);
};

/* Touch region of the list; the table ends with left == 0xFF. */
struct FrameListHitEntry {
    u8 left;
    u8 top;
    u8 right;
    u8 bottom;
    u32 kind;
};

/* Layout of the list as the caller gives it. */
typedef struct FrameListParams {
    u8 bgLayer;
    u8 bgLayerB;
    u8 tileX;
    signed char firstRow;
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

#endif
