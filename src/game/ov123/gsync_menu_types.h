/* Work area of the Game Sync menu proc (gsync_menu.c): Yes/No buttons, message window, sprites. */
#ifndef GSYNC_MENU_TYPES_H
#define GSYNC_MENU_TYPES_H

#include "gsync_common_types.h"

/* Key bits of the pad word read in the main loop (DS pad register layout). */
#define GSYNC_KEY_UP    0x40
#define GSYNC_KEY_DOWN  0x80
#define GSYNC_KEY_R     0x100
#define GSYNC_KEY_L     0x200

/* Values of GsyncMenuWork.exitMode. */
#define GSYNC_MENU_EXIT_NONE     0
#define GSYNC_MENU_EXIT_BUTTON_0 2
#define GSYNC_MENU_EXIT_BUTTON_1 3

/* Template passed to APP_TASKMENU_OpenMenu (same record as TaskMenuTmpl in the item menu). */
typedef struct TaskMenuTmpl {
    int heapId;
    u8 itemNum;
    u8 pad[3];
    void *items;
    int posType;
    u8 charPosX;
    u8 charPosY;
    u8 width;
    u8 height;
} TaskMenuTmpl;

/* One entry of the template item array. */
typedef struct TaskMenuItem {
    void *text;             /* STRBUF */
    u16 color;
    u32 value;              /* never written by ov123 */
} TaskMenuItem;

/* Arguments the caller hands to the menu proc; also receives the result. */
typedef struct GsyncProcParam {
    void *gameSystem;       /* 0x000 */
    void *gameData;         /* 0x004 */
    u8 unknown_08[0x1C0];   /* 0x008, not accessed by the menu code */
    int result;             /* 0x1C8, written on exit: the exit mode of the menu */
    u8 unknown_1CC[0xFC];   /* 0x1CC, not accessed by the menu code */
    int fadeFromWhite;      /* 0x2C8, nonzero: wipe in from white, cleared after use */
} GsyncProcParam;

struct GsyncMenuWork;
typedef void (*GsyncMenuStateFunc)(struct GsyncMenuWork *work);

/* Animation end callback record given to the actor animation system. */
typedef struct GsyncActorAnimCallback {
    u16 frame;
    struct GsyncMenuWork *work;
    void (*callback)(struct GsyncMenuWork *work);
} GsyncActorAnimCallback;

/* Palette data record of the graphics archive loader (only rawData is read). */
typedef struct GsyncPaletteData {
    u8 unknown_00[12];
    void *rawData;          /* 0x0C */
} GsyncPaletteData;

/* 0x2B4 bytes, one instance per proc. */
typedef struct GsyncMenuWork {
    GsyncMenuStateFunc stateFunc;                       /* 0x000 */
    int (*buttonCallback)(int button, struct GsyncMenuWork *work);  /* 0x004, set while the buttons are active */
    int exitMode;                                       /* 0x008 */
    u16 heapId;                                         /* 0x00C */
    void *buttonWins[4];                                /* 0x010 */
    void *buttonMan;                                    /* 0x020 */
    void *msgBank;                                      /* 0x024, UI texts */
    void *msgBankSub;                                   /* 0x028 */
    u8 unknown_2C[4];                                   /* 0x02C */
    void *font;                                         /* 0x030 */
    u8 unknown_34[4];                                   /* 0x034 */
    void *msgBuf;                                       /* 0x038, STRBUF, 300 chars */
    u32 bgFrame;                                        /* 0x03C, frame allocation of BG 5, packed halves */
    u32 charBase;                                       /* 0x040 */
    u16 palette[7 * 16];                                /* 0x044 */
    u16 paletteDim[7 * 16];                             /* 0x124, palette brightened by AddPaletteEntries */
    u8 unknown_204[0x20];                               /* 0x204 */
    void *msgWin;                                       /* 0x224, BG 5 message window */
    void *printStream;                                  /* 0x228 */
    u32 keyCursor;                                      /* 0x22C */
    void *tcbl;                                         /* 0x230 */
    void *printQue;                                     /* 0x234 */
    void *taskMenu;                                     /* 0x238 */
    TaskMenuItem menuItems[2];                          /* 0x23C, Yes and No */
    void *taskMenuRes;                                  /* 0x254 */
    GsyncProcParam *param;                              /* 0x258 */
    int buttonCount;                                    /* 0x25C, number of button windows in use */
    void *gameData;                                     /* 0x260 */
    void *gameSystem;                                   /* 0x264 */
    int bgScrollY;                                      /* 0x268, counts down once per frame */
    u8 unknown_26C[4];                                  /* 0x26C */
    int pressedButton;                                  /* 0x270 */
    u8 unknown_274[4];                                  /* 0x274 */
    u32 keyNow;                                         /* 0x278 */
    u32 keyPrev;                                        /* 0x27C */
    void *palBufMain;                                   /* 0x280, 0x200 byte copy of the main palette RAM */
    void *palBufSub;                                    /* 0x284, 0x200 byte copy of the sub palette RAM */
    u8 *timeIcon;                                       /* 0x288 */
    int exiting;                                        /* 0x28C, set when the fade out starts */
    s32 palHandle;                                      /* 0x290, sprite palette */
    s32 charHandle;                                     /* 0x294, sprite character data */
    s32 cellHandle;                                     /* 0x298, sprite cell animation */
    u8 unknown_29C[4];                                  /* 0x29C */
    void *actors[3];                                    /* 0x2A0, cursor sprites */
    void *clactUnit;                                    /* 0x2AC */
    void *vblankTcb;                                    /* 0x2B0 */
} GsyncMenuWork;

#endif
