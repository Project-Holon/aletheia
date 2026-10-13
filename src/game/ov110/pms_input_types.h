#ifndef PMS_INPUT_TYPES_H
#define PMS_INPUT_TYPES_H

/* The easy chat (PMS) input screen, overlay 110. PmsInput is the work object
 * of the screen's process: pms_input.c creates it and drives the input
 * handlers, pmsiv_wordwin.c holds the cursor and word list logic that works on
 * it and its getters for the view code. */

#include "../arm9/pms_types.h"

struct PmsiParam;
struct PmsInputView;
struct PmsInputData;
struct PmsInputSearch;
struct TcbSystem;
struct PmsInput;

/* Touch hit box in screen pixels, the layout TOUCHPANEL_HitTrg reads. */
struct PmsTouchRect {
    unsigned char top;
    unsigned char bottom;
    unsigned char left;
    unsigned char right;
};

/* Hit table with one rectangle, ended by the table terminator. */
struct PmsTouchBox {
    struct PmsTouchRect rect;
    struct PmsTouchRect end;
};

/* Hit table with three rectangles. */
struct PmsTouchBox3 {
    struct PmsTouchRect rects[3];
    struct PmsTouchRect end;
};

/* Cursor over the sentence types and the sentences of one type. */
struct PmsSentenceCursor {
    short type;
    signed char index;
    signed char count;
};

/* Cursor of the word list: six visible rows of two columns. The selected
 * entry is (topRow + row) * 2 + column. */
struct PmsWordListCursor {
    unsigned short topRow;
    unsigned short maxTopRow;
    unsigned short itemCount;
    unsigned char column;
    unsigned char row;
    int scrollDelta;
    unsigned short barFocused;
    unsigned short touchedIndex;
};

/* Set when the screen is left: whether the player cancelled. */
struct PmsExitState {
    unsigned char cancelled;
    unsigned char requested;
};

typedef struct PmsInput PmsInput;

typedef int (*PmsInputHandler)(struct PmsInput *input, unsigned int *state);
typedef void (*PmsInputSubHandler)(struct PmsInput *input, unsigned int *state);
typedef int (*PmsInputUiSwitchFn)(struct PmsInput *input, unsigned int *state);

/* key bits of keyTrg, keyCont and keyRepeat */
#define PMS_KEY_A 0x0001
#define PMS_KEY_B 0x0002
#define PMS_KEY_SELECT 0x0004
#define PMS_KEY_START 0x0008
#define PMS_KEY_RIGHT 0x0010
#define PMS_KEY_LEFT 0x0020
#define PMS_KEY_UP 0x0040
#define PMS_KEY_DOWN 0x0080
#define PMS_KEY_R 0x0100
#define PMS_KEY_L 0x0200
#define PMS_KEY_DIRECTIONS (PMS_KEY_RIGHT|PMS_KEY_LEFT|PMS_KEY_UP|PMS_KEY_DOWN)

/* sound effect ids played by the input screen */
#define PMS_SE_MOVE 1352
#define PMS_SE_TAB 1355
#define PMS_SE_OK 1356
#define PMS_SE_CANCEL 1361
#define PMS_SE_SELECT_INITIAL 1363
#define PMS_SE_ERROR 1367
#define PMS_SE_PAGE 1636

/* cursorPos values besides the 12 category cells */
#define PMS_CURSOR_WORD_LIST 252
#define PMS_CURSOR_INITIAL_SEARCH 253
#define PMS_CURSOR_CANCEL 254
#define PMS_CURSOR_NONE 255

/* browseMode */
#define PMS_BROWSE_CATEGORY 0
#define PMS_BROWSE_INITIAL 1

/* inputMode: how many words the caller wants */
#define PMS_INPUT_MODE_SENTENCE 2

struct PmsInput {
    /* 0x00 */ struct PmsiParam *param;
    /* 0x04 */ unsigned int inputMode;
    /* 0x08 */ struct PmsData sentence;
    /* 0x10 */ unsigned short words[2];
    /* 0x14 */ struct PmsInputView *view;
    /* 0x18 */ struct PmsInputData *data;
    /* 0x1C */ struct PmsInputSearch *search;
    /* 0x20 */ unsigned int handlerState;
    /* 0x24 */ PmsInputHandler handler;
    /* 0x28 */ PmsInputHandler returnHandler;
    /* 0x2C */ unsigned int subState;
    /* 0x30 */ PmsInputSubHandler subHandler;
    /* 0x34 */ unsigned short keyTrg;
    /* 0x36 */ unsigned short keyCont;
    /* 0x38 */ unsigned short keyRepeat;
    /* 0x3A */ unsigned char pad3A[2];
    /* 0x3C */ int lastButton;
    /* 0x40 */ unsigned char pad40[4];
    /* 0x44 */ void *buttonMan;
    /* 0x48 */ unsigned short cancelSelected;
    /* 0x4A */ unsigned short wordSlot;
    /* 0x4C */ unsigned short cursorPos;
    /* 0x4E */ unsigned short prevCursorPos;
    /* 0x50 */ unsigned short savedCursorPos;
    /* 0x52 */ unsigned char pad52[2];
    /* 0x54 */ struct PmsWordListCursor wordList;
    /* 0x64 */ struct PmsSentenceCursor sentenceCursor;
    /* 0x68 */ unsigned char wordSlotCount;
    /* 0x69 */ unsigned char browseMode;
    /* 0x6A */ unsigned char scrollBarGrabbed;
    /* 0x6B */ struct PmsExitState exitState;
    /* 0x6D */ unsigned char pad6D[3];
    /* 0x70 */ unsigned int uiInputMode;
    /* 0x74 */ PmsInputUiSwitchFn uiSwitchFn;
    /* 0x78 */ void *taskBuf;
    /* 0x7C */ struct TcbSystem *tasks;
};

#endif
