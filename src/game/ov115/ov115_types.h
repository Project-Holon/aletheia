#ifndef ALETHEIA_OV115_TYPES_H
#define ALETHEIA_OV115_TYPES_H

/*
 * Types of the Wi-Fi login overlay (ov115). Three objects cooperate:
 *  - WifiloginState: the login session/config object handed in from outside;
 *  - WifiloginWork: the per-frame work object threaded through the login
 *    state machine (72 bytes);
 *  - WifiloginDisp: the background/actor display object (0x14BC bytes);
 * plus the message/dialog side of the same overlay, which uses
 * WifiloginMsg (132 bytes), its inline WifiloginMsgTask sub-object and its
 * own 32-byte WifiloginMsgWork context.
 */

#include "../types.h"

struct Obj;
struct Proc;
struct Proc;
struct Cfg;

/* Login session/config object, pointed to by WifiloginWork.state (0x40) and
 * by the message work object (0x10). */
struct WifiloginState {
    void *userdata;             /* 0x00: account/user data block */
    unsigned int mode;          /* 0x04: login mode (0 or 1); 1 enables touch cancel */
    unsigned int reconnect;     /* 0x08: non-zero restarts with the default timeout */
    unsigned int dialogId;      /* 0x0C: message/dialog id (10, 36 or 44) */
    unsigned int waiting;       /* 0x10: non-zero while waiting on the server */
    unsigned int netMode;       /* 0x14: current network mode (2 handled specially) */
    unsigned int cancelBgm;     /* 0x18: zero cancels the change and plays the BGM */
    unsigned int aidMismatch;   /* 0x1C: set when this console is not the current aid */
    void *stepCallback;         /* 0x20: optional per-frame step callback */
    unsigned int stepArg;       /* 0x24: argument handed to stepCallback */
};

/* Per-frame state-machine context threaded through the login steps. */
struct WifiloginWork {
    void (*stateHandler)(unsigned char *); /* 0x00: current step callback */
    unsigned char pad04[8];     /* 0x04 */
    unsigned short heapId;      /* 0x0C: child heap of the login */
    unsigned char pad0E[0x12];  /* 0x0E */
    unsigned int accountError;  /* 0x20: set when the profile or console check fails */
    unsigned int saveStarted;   /* 0x24: set once GAME_DATA_SaveStart has run */
    unsigned char pad28[4];     /* 0x28 */
    void *saveControl;          /* 0x2C: GAME_DATA save control block */
    void *task;                 /* 0x30: message task sub-object */
    void *disp;                 /* 0x34: WifiloginDisp display object */
    void *message;              /* 0x38: WifiloginMsg dialog object */
    void *profile;              /* 0x3C: GAME_DATA profile block */
    struct WifiloginState *state; /* 0x40: login session object */
    void *userdata;             /* 0x44: account/user data block */
};

/* Palette fade state of the mode 0 display (0x970 bytes at WifiloginDisp + 0x10, also the work of the
 * per-frame palette task). */
struct WifiloginPalTask {
    void *frameTask;            /* 0x000: per-frame task (GFL_USE_AddMainTask) */
    unsigned int ready;         /* 0x004: set once the palette is uploaded */
    unsigned short table[15][16]; /* 0x008: colour tables */
    unsigned short frames[60][16]; /* 0x1E8: blended frames (colours 4 to 10 are uploaded) */
    short index;                /* 0x968: frame index (0..59) */
    unsigned char pad96A;       /* 0x96A */
    unsigned char toggle;       /* 0x96B: toggles the palette upload */
    unsigned char layer;        /* 0x96C: BG layer scrolled with the upload */
    unsigned char pad96D[3];    /* 0x96D */
};

/* Background/actor display object (0x14BC bytes), owned by WifiloginWork.disp. */
struct WifiloginDisp {
    unsigned int charBank0;     /* 0x0000: obj char handle bank 0 */
    unsigned int charBank1;     /* 0x0004: obj char handle bank 1 */
    unsigned int mode;          /* 0x0008: display mode (0 or 1) */
    unsigned short heapId;      /* 0x000C: child heap of the display */
    unsigned char pad0E[2];     /* 0x000E */
    struct WifiloginPalTask pal; /* 0x0010 */
    void *unit;                 /* 0x0980: CLACT unit */
    void *vblankTask;           /* 0x0984: CLACT vblank task */
    void *hblankTask;           /* 0x0988: hblank task */
    unsigned int paletteHandle; /* 0x098C: CLACT palette handle */
    unsigned int charHandle;    /* 0x0990: CLACT character handle */
    unsigned int cellAnimHandle;/* 0x0994: CLACT cell anim handle */
    unsigned char pad998[4];    /* 0x0998 */
    void *actors[5];            /* 0x099C: actor slots */
    unsigned char pad9B0[0x14]; /* 0x09B0 */
    unsigned int palFlag;       /* 0x09C4: palette fade-in flag */
    short scanline;             /* 0x09C8: sine scanline counter */
    short sineTable[192];       /* 0x09CA: sine wave table */
    short frameTimer;           /* 0x0B4A: fade/frame counter */
    unsigned char padB4C[0x970];/* 0x0B4C: trailing space of the allocation */
};

/* Task sub-object at WifiloginMsg + 0x54, returned by the dialog creator and
 * kept in WifiloginWork.task. Its 0x1C slot aliases WifiloginMsg.taskMenuRes. */
/* One task menu entry (12 bytes on the DS). */
struct WifiloginMsgItem {
    void *strbuf;               /* 0x00: label buffer */
    unsigned short color;       /* 0x04: label colour */
    unsigned char pad06[6];     /* 0x06 */
};

struct WifiloginMsgTask {
    unsigned int kind;          /* 0x00: 0 = task menu, 1 = yes/no dialog */
    struct WifiloginMsgItem items[2]; /* 0x04: the two task menu entries (label buffer and colour) */
    void *taskMenuRes;          /* 0x1C: task menu resources (aliases WifiloginMsg.taskMenuRes) */
    void *taskMenu;             /* 0x20: open task menu */
    void *yesNo;                /* 0x24: yes/no dialog */
    int answer;                 /* 0x28: cursor position / answer (-1 while open) */
};

struct WifiloginMsg {
    unsigned int frameGfx0;     /* 0x00: packed frame graphic descriptor 0 */
    unsigned int frameGfx1;     /* 0x04: packed frame graphic descriptor 1 */
    unsigned char pad08[0x14];  /* 0x08 */
    void *msgBank;              /* 0x1C: message bank */
    void *wordSet;              /* 0x20: word set */
    void *gfFont;               /* 0x24: font */
    void *strbuf;               /* 0x28: shared string buffer */
    void *window;               /* 0x2C: main window */
    void *window2;              /* 0x30: secondary window */
    void *window3;              /* 0x34: message window */
    void *printStream;          /* 0x38: print stream */
    unsigned char printCtrl[8]; /* 0x3C: PRINTSYS_CTRL block */
    void *tcbl;                 /* 0x44: text control block list */
    void *printsysQue;          /* 0x48: print queue */
    unsigned short heapId;      /* 0x4C: child heap of the dialog */
    unsigned char pad4E[2];     /* 0x4E */
    unsigned int mode;          /* 0x50: dialog mode */
    struct WifiloginMsgTask task; /* 0x54: task sub-object (kind, entries, menu, yes/no, answer) */
    void *timeIcon;             /* 0x80: time icon */
};

/* Message-side work object (32 bytes) used by the dialog task callbacks. */
struct WifiloginMsgWork {
    void *task;                 /* 0x00: WifiloginMsgTask to update */
    void *disp;                 /* 0x04: WifiloginDisp display object */
    void *message;              /* 0x08: WifiloginMsg dialog object */
    void (*stateHandler)(unsigned char *); /* 0x0C: current step callback */
    struct WifiloginState *state; /* 0x10: login session object */
    unsigned short heapId;      /* 0x14: child heap of the task */
    unsigned char pad16[2];     /* 0x16 */
    unsigned int flag18;        /* 0x18: exit flag */
    unsigned char pad1C[4];     /* 0x1C */
};

#endif
