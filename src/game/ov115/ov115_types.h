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

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

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
    unsigned int stateHandler;  /* 0x00: current step callback */
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

/* Background/actor display object (0x14BC bytes), owned by WifiloginWork.disp. */
struct WifiloginDisp {
    unsigned int charBank0;     /* 0x0000: obj char handle bank 0 */
    unsigned int charBank1;     /* 0x0004: obj char handle bank 1 */
    unsigned int mode;          /* 0x0008: display mode (0 or 1) */
    unsigned short heapId;      /* 0x000C: child heap of the display */
    unsigned char pad0E[2];     /* 0x000E */
    void *frameTask;            /* 0x0010: per-frame task (func_020056A0) */
    unsigned int paletteReady;  /* 0x0014: set once the palette is uploaded */
    unsigned char pad18[0x950]; /* 0x0018: palette blend buffers and colour tables */
    short palIndex;             /* 0x0968: palette index (0..59) */
    unsigned char pad96A;       /* 0x096A */
    unsigned char palToggle;    /* 0x096B: toggles the palette upload */
    unsigned char palLayer;     /* 0x096C: BG palette layer id */
    unsigned char pad96D[0xF];  /* 0x096D */
    unsigned char palDone;      /* 0x097C: palette upload finished flag */
    unsigned char pad97D[3];    /* 0x097D */
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
struct WifiloginMsgTask {
    unsigned int kind;          /* 0x00: 0 = task menu, 1 = yes/no dialog */
    void *strbufA;              /* 0x04: label buffer A */
    unsigned short colorA;      /* 0x08: colour of label A */
    unsigned char pad0A[6];     /* 0x0A */
    void *strbufB;              /* 0x10: label buffer B */
    unsigned short colorB;      /* 0x14: colour of label B */
    unsigned char pad16[6];     /* 0x16 */
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
    unsigned char pad3C[8];     /* 0x3C: print buffer used through raw offsets */
    void *tcbl;                 /* 0x44: text control block list */
    void *printsysQue;          /* 0x48: print queue */
    unsigned short heapId;      /* 0x4C: child heap of the dialog */
    unsigned char pad4E[2];     /* 0x4E */
    unsigned int mode;          /* 0x50: dialog mode */
    unsigned int taskKind;      /* 0x54: task sub-object kind */
    void *taskStrbufA;          /* 0x58: task label buffer A */
    unsigned short taskColorA;  /* 0x5C: task colour A */
    unsigned char pad5E[6];     /* 0x5E */
    void *taskStrbufB;          /* 0x64: task label buffer B */
    unsigned short taskColorB;  /* 0x68: task colour B */
    unsigned char pad6A[6];     /* 0x6A */
    void *taskMenuRes;          /* 0x70: task menu resources */
    void *taskMenu;             /* 0x74: open task menu */
    void *taskYesNo;            /* 0x78: yes/no dialog */
    int taskAnswer;             /* 0x7C: task cursor position / answer */
    void *timeIcon;             /* 0x80: time icon */
};

/* Message-side work object (32 bytes) used by the dialog task callbacks. */
struct WifiloginMsgWork {
    void *task;                 /* 0x00: WifiloginMsgTask to update */
    void *disp;                 /* 0x04: WifiloginDisp display object */
    void *message;              /* 0x08: WifiloginMsg dialog object */
    void *stateHandler;         /* 0x0C: current step callback */
    struct WifiloginState *state; /* 0x10: login session object */
    unsigned short heapId;      /* 0x14: child heap of the task */
    unsigned char pad16[2];     /* 0x16 */
    unsigned int flag18;        /* 0x18: exit flag */
    unsigned char pad1C[4];     /* 0x1C */
};

#endif
