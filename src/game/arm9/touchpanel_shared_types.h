#ifndef TOUCHPANEL_SHARED_TYPES_H
#define TOUCHPANEL_SHARED_TYPES_H

/*
 * This file holds five original source files, in image order (cut points
 * from their __FILE__ words):
 *   touchpanel.c     0x02035750..0x02035EE8  touch panel sampling, hit tests
 *   key.c            0x02035EE8..0x0203640C  pad reading, key repeat
 *   net_ring_buff.c  0x0203640C..0x02036670  byte ring buffer of the net code
 *   net_queue.c      0x02036670..0x02036BD4  send queue of the net code
 *   wm_icon.c        0x02036BD4..0x02037224  wireless signal icon
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

#define HW_BUTTON_XY_BUF    0x02FFFFA8

/* ui.c: UI frame rate values (UiCtx.frameRate) */
#define UI_FRAMERATE_30     30

/* SDK touch panel sample */
typedef struct {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;

/* touchpanel.c work, 0x7c bytes (held by UiCtx.tpWork and _pTouchPanelWork) */
typedef struct {
    u8     pad00[0x0C];          /* nothing reads it */
    TPData autoSampleBuf[9];     /* 0x0C: auto sampling buffer */
    u8     pad54[4];             /* nothing reads it */
    u16    autoSampleMode;       /* 0x58: auto sampling is used */
    u16    autoSampleStopped;    /* 0x5A: auto sampling is stopped for now */
    u16    x;                    /* 0x5C */
    u16    y;                    /* 0x5E */
    u16    trg;                  /* 0x60 */
    u16    cont;                 /* 0x62 */
    u16    x30;                  /* 0x64: values for a 30 fps frame */
    u16    y30;
    u16    trg30;
    u16    cont30;
    u16    pendX;                /* 0x6C: collected over the frame pair */
    u16    pendY;
    u16    pendTrg;
    u16    pendCont;
    u8     autoSampleActive;     /* 0x74: read the auto sampling result */
    u8     autoSampleFreq;       /* 0x75 */
    u8     autoSampleIndex;      /* 0x76 */
    u8     pad77[5];             /* nothing reads it */
} TouchPanelWork;

/* key.c: one entry of a control mode table (key conversion) */
typedef struct {
    u32 srcKey;
    u32 dstKey;
    u8  kind;                    /* KEY_CONV_* */
    u8  pad09[3];
} KeyConvEntry;

/* key.c work, 0x4c bytes (held by UiCtx.keyWork) */
typedef struct {
    const KeyConvEntry *controlModeTable;  /* 0x00 */
    u32 controlModeCount;        /* 0x04 */
    u32 controlMode;             /* 0x08: entry index into the table */
    u32 rawCont;                 /* 0x0C: pad state before conversion */
    u32 rawTrg;
    u32 rawRepeat;
    u32 cont;                    /* 0x18: after conversion */
    u32 trg;
    u32 repeat;
    u32 cont30;                  /* 0x24: values for a 30 fps frame */
    u32 trg30;
    u32 repeat30;
    u32 pendCont;                /* 0x30: collected over the frame pair */
    u32 pendTrg;
    u32 pendRepeat;
    s32 repeatCounter;           /* 0x3C */
    s32 repeatSpeed;             /* 0x40 */
    s32 repeatWait;              /* 0x44 */
    u32 pad48;                   /* nothing reads it */
} KeyWork;

/* ui.c system object; only the members this file uses */
typedef struct UiCtx {
    KeyWork        *keyWork;     /* 0x00 */
    TouchPanelWork *tpWork;      /* 0x04 */
    u8              uiState[0x35]; /* 0x08: callbacks and flags of ui.c */
    u8              frameRate;   /* 0x3D: 60 or UI_FRAMERATE_30 */
    u8              frameCounter; /* 0x3E */
} UiCtx;

#endif
