/*
 * Object layouts of the monolith tool (ov071): the tool work object and the
 * blocks it passes to its sub-screens.
 */
#ifndef MONOLITH_TOOL_TYPES_H
#define MONOLITH_TOOL_TYPES_H

#include "../types.h"

struct PaletteFade;
struct PrintSys;
struct GfFont;
struct WordSet;
struct Bank;
struct Tcbl;
struct MsgBank;
struct MonolithToolWork;
struct Ctx;
struct Actor;
struct Bitmap;
struct BmpOamGrid;
struct BmpWin;
struct Strbuf;

/* Caller supplied setup block. Only the fields the tool reads are named. */
typedef struct MonolithToolSetup {
    struct Ctx *gameCtx;
    u8 slotIndex[6];
    u8 pad0A[0xB];
    u8 playerGender;
    u8 pad16[2];
    u16 playerName[10];
    int recordCount;
    long long playSeconds;
    u8 rankData[4];
    u8 areaId;
    u8 useSlotRecords;
} MonolithToolSetup;

/* One 24 byte record copied from the slot record archive. */
typedef struct MonolithToolSlotRecord {
    int word[6];
} MonolithToolSlotRecord;

/* Actor resource handles loaded for one of the two palette variants. */
typedef struct MonolithToolActorRes {
    u32 charPalAnm;
    u32 cellRes;
    u32 animRes;
    u32 simplePalAnm;
} MonolithToolActorRes;

/* Palette highlight of one button group: pulse while selected, flash when
   pressed. Eight bytes each. */
typedef struct MonolithToolHighlight {
    u16 level;
    u8 mode;
    u8 fadeDown;
    u8 timer;
    u8 flashCount;
    u8 pad6[2];
} MonolithToolHighlight;

/* Highest value of MonolithState.selected: no entry is selected. */
#define MONOLITH_ENTRY_NONE 0x30

/* Cursor value of MonolithListWork.cursor when no row is under the cursor. */
#define MONOLITH_CURSOR_NONE 0xFFFF

/* Number of sprite grids (visible rows) of the list. */
#define MONOLITH_ROW_GRIDS 7

/* Height of one row in pixels. */
#define MONOLITH_ROW_HEIGHT 32

/* Key bits (DS pad register layout). */
enum {
    MONOLITH_KEY_A = 0x01,
    MONOLITH_KEY_B = 0x02,
    MONOLITH_KEY_UP = 0x40,
    MONOLITH_KEY_DOWN = 0x80
};

/* Sound effect ids: cursor move and confirm. */
enum {
    MONOLITH_SE_MOVE = 0x548,
    MONOLITH_SE_CONFIRM = 0x54C
};

/* Value of MonolithListWork.inputMode: how the cursor was moved. */
enum {
    MONOLITH_INPUT_NONE = 0,
    MONOLITH_INPUT_KEY = 1,
    MONOLITH_INPUT_TOUCH = 2
};

/* One entry of the table at MonolithToolWork.entryTable. */
typedef struct MonolithEntry {
    u8 costA;
    u8 costB;
    u16 number;
    u16 nameMsgId;
    u16 descMsgId;
    u8 reserved[4];
} MonolithEntry;

/* Per-area record block: the state of the six slot icons and the two counters
   shown next to the cost of an entry. */
typedef struct MonolithCounts {
    u8 reserved0[6];
    u8 slotIconState[6];
    u16 current;
    u16 limit;
} MonolithCounts;

/* Selection state shared with the caller of the tool (MonolithToolProcArgs.param).
   The slot select screen writes slot; the list and information screens use the rest. */
typedef struct MonolithState {
    u8 slot;
    u8 selected;
    u8 mode;
    u8 activeDirty;
} MonolithState;

/* Block handed to every sub-screen as its parameter. It also carries the
   screen switch flags the sub-screens write back to the shell. */
typedef struct MonolithToolProcArgs {
    /* 0x00 */ MonolithToolSetup *setup;
    /* 0x04 */ struct MonolithToolWork *work;
    /* 0x08 */ MonolithState *param;
    /* 0x0C */ MonolithToolHighlight highlight[4];
    /* 0x2C */ u8 requestedScreen;
    /* 0x2D */ u8 topProcDone;
    /* 0x2E */ u8 abortRequested;
    /* 0x2F */ u8 reserved2F;
} MonolithToolProcArgs;

/* Actor button: actor, grid and bitmap handles plus an enable flag. */
typedef struct MonolithToolButton {
    void *actor;
    void *grid;
    void *bitmap;
    u8 on;
} MonolithToolButton;

/* Text label: bitmap and grid handles plus an enable flag. */
typedef struct MonolithToolLabel {
    void *bitmap;
    void *grid;
    u8 on;
} MonolithToolLabel;

/* Blinking cursor actor: handle, running flag, frame counter, anim phase. */
typedef struct MonolithToolBlink {
    struct ClactActor *actor;
    u8 active;
    u8 frame;
    u8 phase;
} MonolithToolBlink;

/* Work object of the tool shell, 0x13C bytes. */
typedef struct MonolithToolWork {
    /* 0x00 */ struct PaletteFade *palAnm;
    /* 0x04 */ u8 *actorTool;
    /* 0x08 */ struct PrintSys *printSys;
    /* 0x0C */ struct GfFont *font;
    /* 0x10 */ struct WordSet *wordSet;
    /* 0x14 */ struct Bank *unitBank;
    /* 0x18 */ struct Tcbl *taskList;
    /* 0x1C */ struct MsgBank *msgBank[4];
    /* 0x2C */ void *actorToolUnit;
    /* 0x30 */ void *archive;
    /* 0x34 */ MonolithEntry *entryTable;
    /* 0x38 */ u8 scratchList[8];
    /* 0x40 */ MonolithToolActorRes actorRes[2];
    /* 0x60 */ MonolithToolSlotRecord slotRecord[6];
    /* 0xF0 */ MonolithState selection;
    /* 0xF4 */ u8 reservedF4[4];
    /* 0xF8 */ MonolithToolProcArgs procArgs;
    /* 0x128 */ struct TcbTask *vblankTask;
    /* 0x12C */ struct ProcSys *topProcSys;
    /* 0x130 */ struct ProcSys *subProcSys;
    /* 0x134 */ u8 currentScreen;
    /* 0x135 */ u8 topProcStarted;
    /* 0x136 */ u8 subProcStarted;
    /* 0x137 */ u8 reserved137;
    /* 0x138 */ u32 subBgCharOffset;
} MonolithToolWork;

/* Slot select screen work object, 0x84 bytes. */
typedef struct MonolithToolSlotSelect {
    /* 0x00 */ void *msgWindow;
    /* 0x04 */ void *msgString;
    /* 0x08 */ void *msgPrinter;
    /* 0x0C */ void *slotIcon[6];
    /* 0x24 */ MonolithToolBlink cursorBlink;
    /* 0x2C */ MonolithToolButton button[2];
    /* 0x4C */ MonolithToolSlotRecord joinRecord;
    /* 0x64 */ u16 playerName[10];
    /* 0x78 */ u8 playerGender;
    /* 0x79 */ u8 pad79[3];
    /* 0x7C */ void *cursorActor;
    /* 0x80 */ u8 linkLost;
    /* 0x81 */ u8 joined;
    /* 0x82 */ u8 backMode;
    /* 0x83 */ u8 buttonHighlight;
} MonolithToolSlotSelect;

/* Title screen work object, 0x24 bytes. */
typedef struct MonolithToolTitle {
    /* 0x00 */ MonolithToolLabel nameLabel;
    /* 0x0C */ void *slotIcon[6];
} MonolithToolTitle;

/* Three way menu screen work object, 0x48 bytes. */
typedef struct MonolithToolMenu {
    /* 0x00 */ MonolithToolButton button[3];
    /* 0x30 */ signed char selected;
    /* 0x31 */ signed char result;
    /* 0x32 */ u8 kind;
    /* 0x33 */ u8 touchArmed;
    /* 0x34 */ MonolithToolBlink cursorBlink;
    /* 0x3C */ void *window;
    /* 0x40 */ void *messageBox;
    /* 0x44 */ void *messageText;
} MonolithToolMenu;

/* Text box: window handle plus a draw-pending flag. */
typedef struct MonolithToolTextBox {
    void *window;
    u8 on;
} MonolithToolTextBox;

/* Summary screen work object, 0x28 bytes. */
typedef struct MonolithToolSummary {
    /* 0x00 */ void *window[2];
    /* 0x08 */ MonolithToolTextBox text[2];
    /* 0x18 */ MonolithToolLabel nameLabel;
    /* 0x24 */ u8 shownSlot;
    /* 0x25 */ u8 pad25[3];
} MonolithToolSummary;

/* Slot record seen as a bitfield word pair. */
typedef struct MonolithToolSlotInfo {
    u32 id;
    u32 labelId : 4;
    u32 reserved4 : 14;
    u32 detailId : 11;
    u32 reserved29 : 3;
    u32 pad8[4];
} MonolithToolSlotInfo;

/* Statistics screen work object, 0x50 bytes. */
typedef struct MonolithToolStats {
    /* 0x00 */ void *window[6];
    /* 0x18 */ MonolithToolTextBox text[6];
    /* 0x48 */ MonolithToolBlink cursorBlink;
} MonolithToolStats;

/* Work object of the entry list screen, 0x314 bytes. It is a scrolling list of up
   to 50 rows, 32 pixels per row, moved by touch drag or by keys. Seven sprite grids
   show the rows that are visible at one time. */
typedef struct MonolithListWork {
    /* 0x000 */ struct TcbTask *task;
    /* 0x004 */ u32 bgCharOffset;
    /* 0x008 */ MonolithToolButton backButton;
    /* 0x018 */ struct Actor *scrollUpArrow;
    /* 0x01C */ struct Actor *scrollDownArrow;
    /* 0x020 */ struct MsgBank *entryNameBank;
    /* 0x024 */ struct Bitmap *entryBitmaps[50];
    /* 0x0EC */ u32 entryIds[50];
    /* 0x1B4 */ int entryDisabled[50];
    /* 0x27C */ u8 entryCount;
    /* 0x27D */ u8 loadedCount;
    /* 0x27E */ u8 reserved27E[2];
    /* 0x280 */ struct BmpWin *messageWindow;
    /* 0x284 */ struct BmpWin *titleWindow;
    /* 0x288 */ struct BmpWin *statusWindow;
    /* 0x28C */ u8 statusPending;
    /* 0x28D */ u8 reserved28D[3];
    /* 0x290 */ struct Strbuf *messageText;
    /* 0x294 */ void *messagePrinter;
    /* 0x298 */ MonolithToolBlink marker;
    /* 0x2A0 */ struct BmpOamGrid *rowGrids[MONOLITH_ROW_GRIDS];
    /* 0x2BC */ struct Bitmap *rowBitmaps[MONOLITH_ROW_GRIDS];
    /* 0x2D8 */ int scrollPos;
    /* 0x2DC */ int touchFrames;
    /* 0x2E0 */ int scrollVelocity;
    /* 0x2E4 */ int scrollRequest;
    /* 0x2E8 */ int touchY;
    /* 0x2EC */ int touchStartY;
    /* 0x2F0 */ int uploadPending;
    /* 0x2F4 */ int cursor;
    /* 0x2F8 */ int prevCursor;
    /* 0x2FC */ int lastCursor;
    /* 0x300 */ int chosenEntry;
    /* 0x304 */ int cursorChanged;
    /* 0x308 */ int inputMode;
    /* 0x30C */ void *taskMenuUnit;
    /* 0x310 */ void *yesNoMenu;
} MonolithListWork;

/* One text window of the information screen and its print-pending flag. */
typedef struct MonolithInfoSlot {
    struct BmpWin *window;
    u8 pending;
    u8 reserved05[3];
} MonolithInfoSlot;

/*
 * Work of the information screen. Slot 0 holds the fixed header text, slot 1
 * the name and description of the active entry, slot 2 the cost panel of the
 * selected entry. The window pointers appear twice (windows and slots), as in
 * the original.
 */
typedef struct MonolithInfoWork {
    struct BmpWin *windows[3];
    MonolithInfoSlot slots[3];
    u32 shownEntry;
} MonolithInfoWork;

#endif
