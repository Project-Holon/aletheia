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
#include "../types.h"
#include "../arm9/tp.h"

#define HW_BUTTON_XY_BUF    0x02FFFFA8

/* ui.c: UI frame rate values (UiCtx.frameRate) */
#define UI_FRAMERATE_30     30

/* One entry of a touch hit table: a rectangle, or a circle when the first
 * byte is TOUCHPANEL_HIT_CIRCLE.  TOUCHPANEL_HIT_END ends the table. */
typedef union {
    struct {
        u8 top;
        u8 bottom;
        u8 left;
        u8 right;
    } rect;
    struct {
        u8 code;
        u8 x;
        u8 y;
        u8 r;
    } circle;
} TouchHitTable;


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
typedef void (*UiCb)(void *);

typedef int  (*UiPred)(void *);

typedef void (*UiIntrFunc)(u32);

/* The UI context pointed at by gUiState.ctx (0x021469BC).  touchpanel.c and the
 * areaman tick UI_Main are all views of this one object; the fields
 * follow the names those files use (keyWork/tpWork/onWake..resumeArmed). */
typedef struct UiCtx {
    KeyWork *keyWork;        /* 0x00 KEY_Create result */
    TouchPanelWork *tpWork;         /* 0x04 TOUCHPANEL_Create result */
    UiIntrFunc intrData;      /* 0x08 per-frame interrupt callback */
    u32     intrArg;          /* 0x0C its argument */
    UiCb    onWake;           /* 0x10 */
    UiCb    onSleep;          /* 0x14 */
    UiCb    onResume;         /* 0x18 */
    UiCb    onSuspend;        /* 0x1C */
    UiCb    onWakePowered;    /* 0x20 */
    UiPred  keepAwakePred;    /* 0x24 */
    void   *sleepWakeArg;     /* 0x28 */
    void   *suspendResumeArg; /* 0x2C */
    void   *wakePoweredArg;   /* 0x30 */
    void   *keepAwakeArg;     /* 0x34 */
    u8      keepAwakeFlags;   /* 0x38 */
    u8      softResetInhibit;          /* 0x39 */
    u8      reserved3A;       /* 0x3A */
    u8      backlightState;   /* 0x3B */
    u8      inputMode;        /* 0x3C */
    u8      frameRate;        /* 0x3D */
    u8      frameCounter;     /* 0x3E */
    u8      powerState;       /* 0x3F */
    u8      mode;             /* 0x40 */
    u8      resumeArmed;      /* 0x41 */
    u8      reserved42;       /* 0x42 */
    u8      suspended;        /* 0x43 */
} UiCtx;

#endif
