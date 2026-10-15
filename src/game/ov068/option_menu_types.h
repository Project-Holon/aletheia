#ifndef OPTION_MENU_TYPES_H
#define OPTION_MENU_TYPES_H

/*
 * Types of the options menu overlay (text speed, battle scene, battle style,
 * sound mode, button mode). Needs u8, u16, u32, s8, s16 from the includer.
 *
 * OptionMenuWork is the task work allocated by the proc init function. The
 * sub objects sit inside it at fixed offsets; every function that takes a
 * sub object pointer gets it as &work->member.
 */

#include "../ov067/touchbar_types.h"

/* Opaque types owned by other files. */
struct GfFont;
struct MsgBank;
struct PrintSys;
struct PrintStream;
struct BmpWindow;
struct Bitmap;
struct StringBuf;
struct TaskList;
struct Task;
struct TaskMenu;
struct TaskMenuRes;
struct ClUnit;
struct ClRes;
struct ClActor;
struct Config;
struct GameData;
struct GameSystem;
struct SaveData;
struct TaskMenuWin;
struct Proc;

/* Input command codes written by OPTION_MENU_ReadInput. */
enum {
    OPTION_INPUT_NONE = 0,
    OPTION_INPUT_DRAG = 1,
    OPTION_INPUT_TOUCH = 3,
    OPTION_INPUT_UP = 4,
    OPTION_INPUT_DOWN = 5,
    OPTION_INPUT_RIGHT = 6,
    OPTION_INPUT_LEFT = 7,
    OPTION_INPUT_CONFIRM = 8,
    OPTION_INPUT_CANCEL = 9,
    OPTION_INPUT_HOLD_UP = 10,
    OPTION_INPUT_HOLD_DOWN = 11,
    OPTION_INPUT_SHORTCUT_X = 12,
    OPTION_INPUT_SHORTCUT_Y = 13,
    OPTION_INPUT_KEY_ACTIVATE = 14
};

/* Indexes into OptionSettings.values and rows of the choice table. */
enum {
    OPTION_TEXT_SPEED = 0,
    OPTION_BATTLE_SCENE = 1,
    OPTION_BATTLE_STYLE = 2,
    OPTION_SOUND_MODE = 3,
    OPTION_BUTTON_MODE = 4,
    OPTION_COUNT = 5,
    OPTION_NO_CHANGE = 11
};

/* Cursor positions of OptionMenuList.cursor: five setting rows, then two buttons. */
enum {
    OPTION_CURSOR_CONFIRM = 5,
    OPTION_CURSOR_CANCEL = 6
};

/* Index of the window handles in OptionMenuGfx.windows. */
enum {
    OPTION_WINDOW_LABEL_COUNT = 16,
    OPTION_WINDOW_TITLE = 16,
    OPTION_WINDOW_DESCRIPTION = 17,
    OPTION_WINDOW_MESSAGE = 18,
    OPTION_WINDOW_COUNT = 19
};

/* Index of the actors in OptionMenuSprites.actors. */
enum {
    OPTION_ACTOR_CURSOR = 1,
    OPTION_ACTOR_CHOICE_FIRST = 2,
    OPTION_ACTOR_CHOICE_COUNT = 11,
    OPTION_ACTOR_COUNT = 14
};

/* OptionMenuButtons.choice values. */
enum {
    OPTION_BUTTON_CONFIRM = 0,
    OPTION_BUTTON_CANCEL = 1,
    OPTION_BUTTON_RETURN = 2,
    OPTION_BUTTON_NONE = 3
};

typedef struct OptionMenuArgs {
    u32 result;
    struct GameSystem *gameSystem;
} OptionMenuArgs;

/* One background layer setup row (table gOptionMenuBgLayers). */
typedef struct BgTemplate {
    u32 words[8];
} BgTemplate;

typedef struct OptionMenuBgLayer {
    u32 layerId;
    BgTemplate layout;
    u32 mapType;
} OptionMenuBgLayer;

typedef struct ScreenData {
    u8 header[0x14];
    u8 *charData;
} ScreenData;

typedef struct PaletteResource {
    u8 header[0xC];
    u8 *colors;
} PaletteResource;

/* Window label table (gOptionMenuLabels). */
typedef struct OptionMenuLabel {
    u32 messageId;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} OptionMenuLabel;

/* One clickable choice (gOptionMenuChoices). */
typedef struct OptionMenuChoice {
    u32 settingIndex;
    u32 value;
    u32 actorX;
    u32 actorY;
    s16 rectX;
    s16 rectY;
    s16 rectWidth;
    s16 rectHeight;
} OptionMenuChoice;

/* Choices of one setting row (gOptionMenuSettingRows / gOptionMenuSettingRowChoiceCount / gOptionMenuSettingRowChoices). */
typedef struct OptionMenuSettingRow {
    u16 descriptionId;
    u16 choiceCount;
    u8 choices[4];
} OptionMenuSettingRow;

typedef struct OptionMenuRect {
    int left;
    int top;
    int right;
    int bottom;
} OptionMenuRect;

typedef struct OptionMenuPoint {
    int x;
    int y;
} OptionMenuPoint;

/* Actor creation parameters. */
typedef struct ClActorParam {
    u16 x;
    u16 y;
    u16 z;
    u8 priority;
    u8 bgPriority;
} ClActorParam;

typedef struct ClPos {
    u16 x;
    u16 y;
} ClPos;

/* Background display and window resources (first 0x7C bytes of the screen). */
typedef struct OptionMenuGfx {
    struct BmpWindow *windows[OPTION_WINDOW_COUNT]; /* 0x00 */
    u16 blinkAngle;                                  /* 0x4C */
    u16 pad4E;                                       /* 0x4E reserved: twin of arm9 BlinkPalAnm.reserved12, never accessed here */
    u16 blinkColor;                                  /* 0x50 */
    u16 pad52;                                       /* 0x52 alignment before the pointer */
    void *screenBuffer;                              /* 0x54 */
    ScreenData *screenData;                          /* 0x58 */
    u16 palette[16];                                 /* 0x5C */
} OptionMenuGfx;

/* Sprite resources and actors. */
typedef struct OptionMenuSprites {
    struct ClUnit *unit;            /* 0x00 */
    struct ClRes *plttRes;          /* 0x04 */
    struct ClRes *mainCharRes;      /* 0x08 */
    struct ClRes *mainCellRes;      /* 0x0C */
    struct ClRes *subCharRes;       /* 0x10 */
    struct ClRes *subCellRes;       /* 0x14 */
    struct ClActor *actors[OPTION_ACTOR_COUNT]; /* 0x18 */
    u16 animFrame;                  /* 0x50 */
    u16 pad52;                      /* 0x52 alignment, struct size 0x54 */
} OptionMenuSprites;

typedef struct OptionMenuScreen {
    OptionMenuGfx gfx;              /* 0x00 */
    OptionMenuSprites sprites;      /* 0x7C */
    struct Task *task;              /* 0xD0 */
} OptionMenuScreen;

struct OptionMenuRunner;
struct OptionMenuWork;

typedef void (*OptionMenuStateFn)(struct OptionMenuRunner *runner, u32 *state, struct OptionMenuWork *work);

/* State machine: runs one callback per frame until it is told to finish. */
typedef struct OptionMenuRunner {
    OptionMenuStateFn callback;     /* 0x00 */
    int finished;                   /* 0x04 */
    u32 state;                      /* 0x08 */
    struct OptionMenuWork *work;    /* 0x0C */
} OptionMenuRunner;

/* Touch and key input of the current frame. */
typedef struct OptionMenuInput {
    int command;                    /* 0x00 */
    int startX;                     /* 0x04 */
    int startY;                     /* 0x08 */
    int dragX;                      /* 0x0C */
    int dragY;                      /* 0x10 */
    int lastX;                      /* 0x14 */
    int lastY;                      /* 0x18 */
    int touching;                   /* 0x1C */
} OptionMenuInput;

/* The five settings as bytes, a change marker and the config they come from. */
typedef struct OptionSettings {
    u8 values[OPTION_COUNT];        /* 0x00 */
    u8 lastChanged;                 /* 0x05 */
    u16 pad6;                       /* 0x06 alignment before the pointer */
    struct Config *config;          /* 0x08 */
} OptionSettings;

typedef struct TaskMenuItem {
    struct StringBuf *label;        /* 0x00 */
    u16 color;                      /* 0x04 */
    u32 value;                      /* 0x08 */
} TaskMenuItem;

typedef struct TaskMenuTemplate {
    u32 heapId;                     /* 0x00 */
    u8 itemCount;                   /* 0x04 */
    TaskMenuItem *items;            /* 0x08 */
    u32 cursorType;                 /* 0x0C */
    u8 tileOffset;                  /* 0x10 */
    u8 cursorPalette;               /* 0x11 */
    u8 windowPalette;               /* 0x12 */
    u8 textColor;                   /* 0x13 */
} TaskMenuTemplate;

/* The two touch bar buttons (return and toggle), copied to the stack when the bar is created (gOptionMenuReturnButtonCells). */
typedef struct ReturnButtonCells {
    TouchBarButtonDef def[2];
} ReturnButtonCells;

/* Confirm, cancel and return buttons at the bottom of the screen. */
typedef struct OptionMenuButtons {
    struct GfFont *font;            /* 0x00 */
    struct PrintSys *printSys;      /* 0x04 */
    TouchBar *returnButton;         /* 0x08 */
    int choice;                     /* 0x0C */
    int decided;                    /* 0x10 */
    struct TaskMenuRes *menuRes;    /* 0x14 */
    struct MsgBank *msgBank;        /* 0x18 */
    TaskMenuItem items[2];          /* 0x1C */
    struct TaskMenuWin *buttons[2]; /* 0x34 */
    struct GameData *gameData;      /* 0x3C */
    int focusChanged;               /* 0x40 */
} OptionMenuButtons;

/* The list of settings with its cursor and the edited copy of the settings. */
typedef struct OptionMenuList {
    u16 mainLayer;                  /* 0x00 */
    u16 subLayer;                   /* 0x02 */
    int cursor;                     /* 0x04 */
    struct ClActor *choiceActors[OPTION_ACTOR_CHOICE_COUNT]; /* 0x08 */
    int scrollY;                    /* 0x34 */
    u32 repeatCounter;              /* 0x38 */
    u32 inputTrail;                 /* 0x3C */
    u32 pad40;                      /* 0x40 reserved: gap between inputTrail and settings, never accessed */
    OptionSettings settings;        /* 0x44 */
    int redraw;                     /* 0x50 */
    int highlight;                  /* 0x54 */
} OptionMenuList;

typedef struct PrintWaitState {
    u32 words[3];
} PrintWaitState;

/* Message printing into one window. */
typedef struct OptionMenuTextBox {
    struct MsgBank *msgBank;        /* 0x00 */
    struct GfFont *font;            /* 0x04 */
    struct PrintStream *stream;     /* 0x08 */
    struct TaskList *taskList;      /* 0x0C */
    struct BmpWindow *window;       /* 0x10 */
    struct StringBuf *buffer;       /* 0x14 */
    u16 fillColor;                  /* 0x18 */
    u16 heapId;                     /* 0x1A */
    struct BmpWindow *printWindow;  /* 0x1C */
    u8 printing;                    /* 0x20 */
    u8 pad21[3];                    /* 0x21 alignment before the pointer */
    struct PrintSys *printSys;      /* 0x24 */
    u32 mode;                       /* 0x28 */
    PrintWaitState waitState;       /* 0x2C */
} OptionMenuTextBox;

/* Text box that can also ask a two choice question. */
typedef struct OptionMenuMessageBox {
    OptionMenuTextBox text;         /* 0x00 */
    struct TaskMenu *menu;          /* 0x38 */
    TaskMenuItem items[2];          /* 0x3C */
    u16 answer;                     /* 0x54 */
    u16 phase;                      /* 0x56 */
    TaskMenuTemplate menuTemplate;  /* 0x58 */
    struct TaskMenuRes *menuRes;    /* 0x6C */
} OptionMenuMessageBox;

typedef struct OptionMenuWork {
    OptionMenuScreen screen;            /* 0x000 */
    OptionMenuRunner runner;            /* 0x0D4 */
    OptionMenuInput input;              /* 0x0E4 */
    OptionMenuButtons buttons;          /* 0x104 */
    OptionMenuList list;                /* 0x148 */
    OptionMenuTextBox helpText;         /* 0x1A0 */
    OptionMenuMessageBox messageBox;    /* 0x1D8 */
    OptionSettings savedSettings;       /* 0x248 */
    struct GfFont *font;                /* 0x254 */
    struct PrintSys *printSys;          /* 0x258 */
    struct MsgBank *msgBank;            /* 0x25C */
    struct TaskMenuRes *buttonMenuRes;  /* 0x260 */
    struct TaskMenuRes *messageMenuRes; /* 0x264 */
    struct TaskList *taskList;          /* 0x268 */
    OptionMenuArgs *args;               /* 0x26C */
} OptionMenuWork;

#endif
