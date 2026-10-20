#ifndef STARTMENU_TYPES_H
#define STARTMENU_TYPES_H

/* Title screen and start menu. The including file defines u8, u16 and u32 first. */

/* ---- Title demo (work area allocated in STARTMENU_TitleDemoInit, 0x98 bytes) ---- */

/* Display capture blend setup and the vblank task that writes REG_DISP_CAPCNT. */
typedef struct TitleDemoCapture {
    u32 taskList; /* 0x00 */
    u32 vblankTask; /* 0x04 */
    u16 captureEva; /* 0x08 */
    u16 captureEvb; /* 0x0A */
} TitleDemoCapture;
typedef char TitleDemoCapture_SizeCheck[(sizeof(TitleDemoCapture) == 0xC) ? 1 : -1];

/* Logo text window on bg layer 5 and the bg scroll counter. */
typedef struct TitleDemoLogo {
    u32 textWindow; /* 0x00 */
    u32 textBitmap; /* 0x04 */
    u32 textWindowCopy; /* 0x08 */
    u8 windowDirty; /* 0x0C */
    u8 pad0D[3];
    u32 ready; /* 0x10 */
    u32 font; /* 0x14 */
    u32 printer; /* 0x18 */
    u8 pad1C[4];
    u32 msgBank; /* 0x20 */
    u32 titleText; /* 0x24 */
    int bgScroll; /* 0x28 */
} TitleDemoLogo;
typedef char TitleDemoLogo_SizeCheck[(sizeof(TitleDemoLogo) == 0x2C) ? 1 : -1];

/* 3D logo model: renderer, light set, ica animation and camera. */
typedef struct TitleDemo3d {
    u32 renderer; /* 0x00 */
    u16 modelId; /* 0x04 */
    u16 pad06;
    u32 lightSet; /* 0x08 */
    u32 anime; /* 0x0C */
    void *camera; /* 0x10 */
} TitleDemo3d;
typedef char TitleDemo3d_SizeCheck[(sizeof(TitleDemo3d) == 0x14) ? 1 : -1];

/* Cell actor unit with one actor and its three resources. */
typedef struct TitleDemoSprites {
    int unit; /* 0x00 */
    int actor; /* 0x04 */
    u8 pad08[0x24];
    int paletteRes; /* 0x2C */
    int charRes; /* 0x30 */
    int cellRes; /* 0x34 */
} TitleDemoSprites;
typedef char TitleDemoSprites_SizeCheck[(sizeof(TitleDemoSprites) == 0x38) ? 1 : -1];

typedef struct TitleDemoWork {
    u16 state; /* 0x00 */
    u16 heapId; /* 0x02 */
    u32 result; /* 0x04: 0 button pressed, 1 timed out, 2 and 3 key codes */
    TitleDemoCapture capture; /* 0x08 */
    TitleDemoLogo logo; /* 0x14 */
    TitleDemo3d demo3d; /* 0x40 */
    TitleDemoSprites sprites; /* 0x54 */
    u32 frameCount; /* 0x8C */
    void *fanfareHandle; /* 0x90 */
    u32 phase; /* 0x94 */
} TitleDemoWork;
typedef char TitleDemoWork_SizeCheck[(sizeof(TitleDemoWork) == 0x98) ? 1 : -1];

/* ---- Start menu (work area allocated in STARTMENU_MenuInit, 0x150 bytes) ---- */

/* A bitmap window and whether text was drawn into it and is still printing. */
typedef struct StartMenuWindow {
    void *window; /* 0x00 */
    u8 textPending; /* 0x04 */
} StartMenuWindow;

/* Arguments the start menu hands to the ov199 proc. */
typedef struct StartMenuOv199Args {
    u32 reserved0[2];
    u32 selection; /* 0x08 */
    u32 reserved1;
    u32 fromTitleMenu; /* 0x10 */
} StartMenuOv199Args;

/* Arguments the start menu hands to the ov107 proc. */
typedef struct StartMenuOv107Args {
    u8 fromTitleMenu; /* 0x00 */
} StartMenuOv107Args;

typedef struct StartMenuWork {
    void *saveData; /* 0x00 */
    void *playerData; /* 0x04 */
    void *unlockData; /* 0x08 */
    void *connectData; /* 0x0C */
    void *eventWork; /* 0x10 */
    int vblankTask; /* 0x14 */
    void *clactUnit; /* 0x18 */
    void *rowActors[6]; /* 0x1C */
    int actorCharRes[3]; /* 0x34 */
    int actorPaletteRes[3]; /* 0x40 */
    int actorCellRes[3]; /* 0x4C */
    u32 font; /* 0x58 */
    void *msgBank; /* 0x5C */
    void *wordSet; /* 0x60 */
    void *stringBuf; /* 0x64 */
    void *printSys; /* 0x68 */
    void *printJob; /* 0x6C */
    u32 taskList; /* 0x70 */
    void *msgBoxFrame; /* 0x74 */
    u32 printAdvanceLatched; /* 0x78 */
    void *yesNoMenu; /* 0x7C */
    StartMenuWindow windows[14]; /* 0x80 */
    void *descWindow; /* 0xF0 */
    u8 descWindowOpen; /* 0xF4 */
    u8 padF5[3];
    void *rowBuffers[8]; /* 0xF8 */
    void *frameManager; /* 0x118 */
    void *blinkPalAnm; /* 0x11C */
    u8 rowIds[8]; /* 0x120 */
    u8 cursorIndex; /* 0x128 */
    u8 selectedRow; /* 0x129 */
    u8 subState; /* 0x12A */
    u8 delay; /* 0x12B */
    u8 connectResult; /* 0x12C */
    u8 selectAnimPhase; /* 0x12D */
    u8 selectAnimTimer; /* 0x12E */
    s8 cursorTileY; /* 0x12F */
    int scrollPixels; /* 0x130 */
    int scrollStep; /* 0x134 */
    int scrollSpeed; /* 0x138 */
    int state; /* 0x13C */
    int nextStateAfterAnim; /* 0x140 */
    int nextStateAfterFade; /* 0x144 */
    u32 saveStatus; /* 0x148 */
    u32 noticeIndex; /* 0x14C */
} StartMenuWork;
typedef char StartMenuWork_SizeCheck[(sizeof(StartMenuWork) == 0x150) ? 1 : -1];

/* ---- New game intro (work area allocated in STARTMENU_NewGameIntroInit, 0x5C bytes) ---- */

struct SaveControlIntr;
struct Proc;
struct ProcSys;
struct ProcData;
struct Config;
struct MyStatus;
struct WaveArcSet;
struct Strbuf;

/* Arguments of the first block of the new game proc work. */
typedef struct NewGameStartArg {
    u32 startMode;              /* always 0 here */
    struct Config *config;
    struct MyStatus *myStatus;
} NewGameStartArg;

/* Procwork of the intro overlay (ov204), 0x18 bytes at offset 0x10 of the work. */
typedef struct NewGameIntroParam {
    struct MyStatus *myStatus;
    struct Config *config;
    u32 phase;                  /* 1 for the first intro part, 7 for the part after the name entry */
    struct SaveControlIntr *saveIntr;
    u32 voiceHandle;
    u32 retryNameEntry;         /* written by the intro: nonzero asks for the name entry again */
} NewGameIntroParam;

/* Name input argument block, owned by ../ov010/namein_args.h. */
#include "../ov010/namein_args.h"

/* Work of the new game intro proc, 0x5C bytes. */
typedef struct NewGameIntroWork {
    NewGameStartArg startArg;           /* 0x00 */
    void *saveOptions;                  /* 0x0C */
    NewGameIntroParam introParam;       /* 0x10 */
    NameInArgs *nameInArgs;             /* 0x28 */
    struct SaveControlIntr *saveIntr;   /* 0x2C */
    struct ProcSys *procSys;            /* 0x30: runs the intro and name entry procs */
    struct WaveArcSet *waveArcSet;      /* 0x34 */
    u8 padding38[0x18];
    u32 voiceHandle;                    /* 0x50 */
    struct MyStatus *myStatus;          /* 0x54 */
    struct Config *config;              /* 0x58 */
} NewGameIntroWork;

/* ---- Config prompt (work area allocated in STARTMENU_ConfigPromptInit, 0x1C bytes) ---- */

typedef struct ConfigPromptWork {
    u8 selectedChoice; /* 0x00 */
    u8 pad01[3];
    u32 question; /* 0x04 */
    void *font; /* 0x08 */
    void *questionWin; /* 0x0C */
    void *choiceWin[2]; /* 0x10 */
    u16 pulsePhase; /* 0x18 */
    u16 pulseColor; /* 0x1A */
} ConfigPromptWork;
typedef char ConfigPromptWork_SizeCheck[(sizeof(ConfigPromptWork) == 0x1C) ? 1 : -1];

/* ---- Logo screen (work area allocated in STARTMENU_LogoScreenInit, 8 bytes) ---- */

typedef struct LogoScreenWork {
    u16 state; /* 0x00 */
    u16 pad02;
    int timer; /* 0x04: frames waited in the current step */
} LogoScreenWork;
typedef char LogoScreenWork_SizeCheck[(sizeof(LogoScreenWork) == 8) ? 1 : -1];

/* ---- Save data erase screen (work area allocated in STARTMENU_SaveEraseInit, 0x2C bytes) ---- */

typedef struct SaveEraseWork {
    void *vblankTask; /* 0x00 */
    void *font; /* 0x04 */
    void *msgBank; /* 0x08 */
    u8 savedAppliedFlag; /* 0x0C: restored when the screen closes */
    u8 pad0D[3];
    void *stringBuf; /* 0x10 */
    void *printJob; /* 0x14 */
    void *taskList; /* 0x18 */
    void *window; /* 0x1C */
    void *yesNoMenu; /* 0x20 */
    void *msgBoxFrame; /* 0x24 */
    int printAdvanceLatched; /* 0x28 */
} SaveEraseWork;
typedef char SaveEraseWork_SizeCheck[(sizeof(SaveEraseWork) == 0x2C) ? 1 : -1];

/* One touch screen hit box in pixels. */
typedef struct StartmenuTouchRect {
    u8 top, bottom, left, right;
} StartmenuTouchRect;

/* Hit boxes of the Yes and No buttons, ended by a zero entry. */
typedef struct StartmenuTouchHitTable {
    StartmenuTouchRect rects[3];
} StartmenuTouchHitTable;

#endif
