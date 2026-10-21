#ifndef PMS_SELECT_GRAPHIC_TYPES_H
#define PMS_SELECT_GRAPHIC_TYPES_H




#include "../ov067/touchbar_types.h"
#include "../ov067/ui_scene_types.h"
#include "../types.h"
/* The graphic selection screen of the easy chat (PMS) system, overlay 110:
 * a list of the saved sentences with a scroll bar on the touch screen. The
 * player picks one, edits it in the input screen or discards it.
 * The includer defines u8, u16 and u32 first and includes the overlay 67
 * headers ui_scene_types.h and touchbar_types.h before this one. */

#define PMS_SELECT_GRAPHIC_VISIBLE_ROWS 4
#define PMS_SELECT_GRAPHIC_MAX_ENTRIES 20

/* Argument block of the process, owned by the caller. */
struct PmsSelectGraphicArgs {
    void *pmsSystem;
    int cancelled;
    const void *selected;
};

/* Background of the list: its screen data, the blinking colours of the
 * selected row and the window of the title text (0x2C bytes). */
struct PmsSelectGraphicBg {
    u32 tileRange;
    void *screenMem;
    u16 *screen;
    u16 colorPhase;
    u16 blinkColors[3];
    u16 palette[4];
    int decided;
    u8 decideFrames;
    u8 pad21[3];
    void *titleWindow;
    int titlePending;
};

/* Display state of the screen (0x10 bytes). */
struct PmsSelectGraphicScene {
    u32 bgState;
    void *actorUnit;
    u32 pad08;
    void *drawTask;
};

/* Work object of the process (0xB0 bytes). */
struct PmsSelectGraphic {
    /* 0x00 */ struct PmsSelectGraphicArgs *args;
    /* 0x04 */ u16 heapId;
    /* 0x06 */ u16 pad06;
    /* 0x08 */ void *scrollThumb;
    /* 0x0C */ ActorGfxSet actorGfx;
    /* 0x1C */ void *pmsSystem;
    /* 0x20 */ void *saveData;
    /* 0x24 */ struct PmsSelectGraphicBg bg;
    /* 0x50 */ struct PmsSelectGraphicScene *scene;
    /* 0x54 */ TouchBar *touchBar;
    /* 0x58 */ void *font;
    /* 0x5C */ void *printQueue;
    /* 0x60 */ void *msgBank;
    /* 0x64 */ void *taskMenuRes;
    /* 0x68 */ void *taskMenu;
    /* 0x6C */ void *rowWindows[PMS_SELECT_GRAPHIC_VISIBLE_ROWS];
    /* 0x7C */ int rowPending[PMS_SELECT_GRAPHIC_VISIBLE_ROWS];
    /* 0x8C */ void *pmsDraw;
    /* 0x90 */ void *editParam;
    /* 0x94 */ u8 prevSelected;
    /* 0x95 */ u8 selected;
    /* 0x96 */ u8 topRow;
    /* 0x97 */ u8 filledCount;
    /* 0x98 */ u8 rowCount;
    /* 0x99 */ u8 touchScrolling:1;
    /* 0x99 */ u8 flagsRest:7;
    /* 0x9A */ u8 pad9A[2];
    /* 0x9C */ int subState;
    /* 0xA0 */ int nextState;
    /* 0xA4 */ int touchBarActive;
    /* 0xA8 */ int isTouch;
    /* 0xAC */ void *procList;
};

/* One row of the background colour table: the palette slot, its low and
 * high colour and the screen position the colour is written to. */
struct PmsSelectGraphicColorRec {
    u16 x;
    u16 y;
    u16 c;
    u16 d;
};

/* Layout of the task menu structs of app_taskmenu.c that this screen fills. */
struct PmsSelectGraphicMenuItem {
    void *text;
    u16 color;
    u16 pad06;
    u32 type;
};

struct PmsSelectGraphicMenuInit {
    u32 heapId;
    u8 itemCount;
    u8 pad05[3];
    void *items;
    u32 positionType;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
};

/* One background layer row: id, template, palette index and screen mode. */
struct PmsSelectGraphicBgRow {
    u32 id;
    u32 bg[8];
    u32 pal;
    u32 value;
};

#endif
