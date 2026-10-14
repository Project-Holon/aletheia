#ifndef CTVT_TYPES_H
#define CTVT_TYPES_H

/*
 * Owner header of the C-Gear video chat overlay (ov172): the screen work
 * record CtvtWork and the records its sub-systems keep behind pointers.
 */

#include "ctvt_camera_types.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef signed short   s16;

/* Opaque library objects. */
struct ClActor;
struct BmpWin;
struct PrintQue;
struct MsgData;
struct StrBuf;
struct TaskMenu;
struct TimeIcon;
struct ArcHandle;
struct ClActUnit;
struct GameData;

/* Sub-system records behind the CtvtWork pointers. */
struct CtvtComm;
struct CtvtTalk;
struct CtvtCall;
struct CtvtSprites;

/* Screen numbers of the CtvtWork state machine. */
#define CTVT_SCREEN_TALK       1
#define CTVT_SCREEN_CALL       2
#define CTVT_SCREEN_DRAW       3
#define CTVT_SCREEN_CAM_SETUP  4
#define CTVT_SCREEN_CAM_WIPE   5

/* Launch parameters handed to the overlay (16 bytes). */
typedef struct CtvtLaunchParams {
    struct GameData *gameData;
    u32 mode;               /* 0 and 1: start from the menu, 2: invited, 3: call from the field */
    u8 peerParam[8];        /* copied into the comm record when mode is 2 */
} CtvtLaunchParams;

/* Work record of the video chat overlay, allocated by the process init.
 * Size 0x1FC. */
typedef struct CtvtWork {
    u16 heapId;
    u8 pad2[2];                 /* alignment before the task pointer */
    void *vblankTask;           /* per-frame task, runs the palette fade */
    s32 screen;                 /* CTVT_SCREEN_* now running */
    s32 nextScreen;             /* CTVT_SCREEN_* requested by the running screen */
    s32 returnedFromChild;      /* 1: wipe differs when a child screen returns */
    s32 netErrorPending;        /* 1: the network error screen was requested */
    u8 memberCount;
    u8 selfSlot;
    u8 pad1A[2];                /* alignment before the next word */
    s32 halfRes;                /* 1: camera frames are half resolution */
    s32 messageActive;          /* 1: a message panel is on the lower screen */
    s32 viewSwapped;            /* toggled by Select/Start: swaps the camera layout */
    s32 inputLocked;            /* 1: touch input is ignored */
    s32 endRequested;           /* 1: the player asked to leave the chat */
    s32 hostBusy;               /* set at init when the wireless stack reports a busy state */
    s32 cameraBusy;             /* 1 while a camera frame is being copied */
    u16 fadePhase;              /* angle of the palette fade sine, +0x200 per frame */
    u16 fadeIndex;              /* palette row currently loaded, 0..9 */
    u8 fadePalette[10][32];     /* palette rows of the fade */
    struct ArcHandle *arc;      /* graphics archive */
    u32 resId[11];              /* cell actor resource ids: 3 groups of char, palette, cell, anim */
    struct ClActUnit *clactUnit;
    struct ClActor *marker;     /* slot marker sprite */
    signed char slotFlagA;
    signed char slotFlagB;
    u8 pad1B6[2];               /* alignment before the window array */
    struct BmpWin *bmpWin[4];   /* one name window per member slot */
    u32 font;
    struct MsgData *msgData;
    struct PrintQue *printQue;
    struct TaskMenu *taskMenu;
    void *timeIconSrc;          /* source handed to TIME_ICON_CreateNode */
    struct TimeIcon *timeIcon;
    CtvtCamView *camView;
    struct CtvtComm *comm;
    struct CtvtTalk *talk;
    struct CtvtDrawScene *draw;
    struct CtvtCall *call;
    struct CtvtSprites *sprites;
    CtvtLaunchParams *launch;
} CtvtWork;

typedef char CtvtWorkSizeCheck[(sizeof(CtvtWork) == 0x1FC) ? 1 : -1];

/* Drawing board screen ("Draw"): record of the pen tool screen. Size 0x98. */
typedef struct CtvtDrawScene {
    s32 state;
    u8 panelTarget;             /* tool panel slide target, 0x18 = hidden */
    u8 panelPos;                /* tool panel slide position */
    u8 pad6[2];                 /* alignment before the next word */
    s32 uiHandled;              /* 1: a button took the touch this frame */
    s32 penDown;                /* 1: the pen is dragging */
    s32 sizePickerOpen;         /* pen size picker is open */
    s32 stampPickerOpen;        /* stamp picker is open */
    s32 touchEnabled;           /* 1 after the wipe in */
    s32 exitKind;               /* 0: leave with 1, else leave with 4 */
    s32 cameraHidden;           /* 1: the camera view was hidden for a message */
    s32 drawTool;               /* 0: pen, 1: stamp, remembered across the color pick */
    s32 toolMode;               /* 0: pen, 1: color pick, 2: eraser, 3: stamp */
    u32 lastX;                  /* previous touch point, 0xFFFF = none */
    u32 lastY;
    u16 penColor;               /* 15 bit color, bit 15 set = valid */
    u8 penSize;                 /* index into the size table */
    u8 stampKind;               /* index into the stamp table */
    s32 helpPending;            /* help window needs its transfer */
    s32 helpPage;               /* 1: second page of the help text */
    s32 titlePending;           /* title window needs its transfer */
    s32 messagePending;         /* message window needs its transfer */
    struct BmpWin *helpWin;
    struct BmpWin *titleWin;
    struct BmpWin *messageWin;
    u16 messageTimer;           /* frames since the message appeared */
    u8 pad56[2];                /* alignment before the actor array */
    struct ClActor *button[6];  /* pen, pick, eraser, stamp, grid, panel arrow */
    struct ClActor *helpIcon[5];
    struct ClActor *penPicker;
    struct ClActor *stampPicker;
    struct ClActor *pickMarker;
    struct ClActor *cursor;
    u16 fadeColor;              /* backdrop color written to the palette */
    u16 fadePhase;
} CtvtDrawScene;

typedef char CtvtDrawSceneSizeCheck[(sizeof(CtvtDrawScene) == 0x98) ? 1 : -1];

/* One stroke segment of the drawing board, in a list of 8 byte records. */
typedef struct CtvtStroke {
    u8 x0;
    u8 y0;
    u8 x1;
    u8 y1;
    u16 color;              /* 15 bit color, 0 = eraser */
    u8 kind;                /* pen size or stamp index, 2 = eraser */
    u8 pad7;                /* never read or written by the code seen so far */
} CtvtStroke;

/* Accessors of CtvtWork fields and helpers (comm_tvt_sys.c). */
extern CtvtCamView *COMM_TVT_SYS_GetCamView(CtvtWork *work);
extern struct CtvtComm *COMM_TVT_SYS_GetComm(CtvtWork *work);
extern int COMM_TVT_SYS_GetTalkStatus(CtvtWork *work);
extern struct CtvtSprites *COMM_TVT_SYS_GetSprites(CtvtWork *work);
extern CtvtLaunchParams *COMM_TVT_SYS_GetLaunchParams(CtvtWork *work);
extern u16 COMM_TVT_SYS_GetHeapId(CtvtWork *work);
extern struct ArcHandle *COMM_TVT_SYS_GetArc(CtvtWork *work);
extern u32 COMM_TVT_SYS_GetResId(CtvtWork *work, int index);
extern struct ClActUnit *COMM_TVT_SYS_GetClactUnit(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetReturnedFromChild(CtvtWork *work);
extern void COMM_TVT_SYS_SetReturnedFromChild(CtvtWork *work, s32 value);
extern u32 COMM_TVT_SYS_GetFont(CtvtWork *work);
extern struct MsgData *COMM_TVT_SYS_GetMsgData(CtvtWork *work);
extern struct PrintQue *COMM_TVT_SYS_GetPrintQue(CtvtWork *work);
extern struct TaskMenu *COMM_TVT_SYS_GetTaskMenu(CtvtWork *work);
extern u8 COMM_TVT_SYS_GetMemberCount(CtvtWork *work);
extern void COMM_TVT_SYS_SetMemberCount(CtvtWork *work, u32 count);
extern int COMM_TVT_SYS_GetLayoutMode(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetHalfRes(CtvtWork *work);
extern void COMM_TVT_SYS_ApplyHalfRes(CtvtWork *work, s32 halfRes);
extern void COMM_TVT_SYS_ToggleHalfRes(CtvtWork *work);
extern void COMM_TVT_SYS_SetHalfRes(CtvtWork *work, s32 halfRes);
extern u8 COMM_TVT_SYS_GetSelfSlot(CtvtWork *work);
extern void COMM_TVT_SYS_SetSelfSlot(CtvtWork *work, u32 slot);
extern s32 COMM_TVT_SYS_GetMessageActive(CtvtWork *work);
extern void COMM_TVT_SYS_SetMessageActive(CtvtWork *work, s32 value);
extern s32 COMM_TVT_SYS_GetViewSwapped(CtvtWork *work);
extern void COMM_TVT_SYS_ToggleViewSwapped(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetInputLocked(CtvtWork *work);
extern void COMM_TVT_SYS_SetInputLocked(CtvtWork *work, s32 value);
extern s32 COMM_TVT_SYS_GetEndRequested(CtvtWork *work);
extern void COMM_TVT_SYS_SetEndRequested(CtvtWork *work, s32 value);
extern int COMM_TVT_SYS_IsLaunchModeCall(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetHostBusy(CtvtWork *work);
extern void COMM_TVT_SYS_ClearHostBusy(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetCameraBusy(CtvtWork *work);
extern void COMM_TVT_SYS_SetCameraBusy(CtvtWork *work, s32 value);
extern int COMM_TVT_SYS_IsNetIdle(void);
extern struct TaskMenu *COMM_TVT_SYS_OpenConfirmMenu(CtvtWork *work);
extern void COMM_TVT_SYS_ClearNameWindows(CtvtWork *work);
extern void COMM_TVT_SYS_ClearAndTransferNameWindows(CtvtWork *work);
extern void COMM_TVT_SYS_PlaceSlotMarker(CtvtWork *work, u8 slot);
extern void COMM_TVT_SYS_HideSlotMarker(CtvtWork *work);
extern void COMM_TVT_SYS_CreateTimeIcon(CtvtWork *work, void *arg);
extern void COMM_TVT_SYS_DeleteTimeIcon(CtvtWork *work);

#endif
