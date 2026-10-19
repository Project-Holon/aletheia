#ifndef ZKNSEARCH_TYPES_H
#define ZKNSEARCH_TYPES_H

/* Owner header for the zukan search (ZKNSEARCH) work objects of ov210.
 *
 * ZknSearchWork is the work block that ZKNSEARCH_SYS_Create allocates
 * (0x2D4 bytes) and every ZKNSEARCH_MAIN / ZKNSEARCH_SYS / ZKNSEARCH_MENU /
 * ZKNSEARCH_LIST / ZKNSEARCH_COND / ZKNSEARCH_RESULT function operates on.
 * It replaces the per-function ObjNNNNN matched-include views. */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

/* The zukan save record block the work points at (work->save). Only the
 * fields ov210 touches are named. */
typedef struct ZknSearchSave {
    void *gameData;      /* 0x00 handle for GAME_DATA_ContainsRecentId / SetSaveFlag */
    void *block;         /* 0x04 ZUKAN save block, ZUKAN_SAVE_GetViewMode / ZUKAN_InitQuery */
    u8   *record;        /* 0x08 entry record bytes (indexed by entry slot) */
    u32   mode;          /* 0x0C list mode, set to 0/1/2 when a row is confirmed */
    u8    pad10[4];      /* 0x10 never read by ov210 */
    u16   state;         /* 0x14 nonzero when a confirm dialog is pending */
} ZknSearchSave;

/* One BMP window slot: a descriptor handle plus a pending-transfer flag. */
typedef struct ZknSearchBmpWin {
    void *bmp;           /* 0x00 BMP window descriptor handle */
    u8    visible;       /* 0x04 nonzero while a char transfer is pending */
    u8    pad5[3];
} ZknSearchBmpWin;

typedef struct ZknSearchWork {
    ZknSearchSave *save;          /* 0x000 zukan save block */
    u32   vblank;                 /* 0x004 vblank callback handle */
    u32   hblank;                 /* 0x008 hblank callback handle */
    void *palAnm;                 /* 0x00C PALANM palette animation object */
    u32   state;                  /* 0x010 ZKNSEARCH_MAIN_RunState state index */
    u32   dialogState;            /* 0x014 confirm dialog step */
    u32   returnState;            /* 0x018 state to return to after a page */
    u32   returnState2;           /* 0x01C state to return to after a message */
    void *scrollWin;              /* 0x020 BGWINFRM scroll window manager */
    void *actorBank;              /* 0x024 CLACT unit bank for the actors */
    void *actors[57];             /* 0x028 CLACT actor handles */
    u32   charRes[6];             /* 0x10C CLACT character registrations */
    u32   palRes[6];              /* 0x124 CLACT palette registrations */
    u32   cellRes[4];             /* 0x13C CLACT cell anim registrations */
    ZknSearchBmpWin bmpWin[16];   /* 0x14C BMP window slots */
    u32   font;                   /* 0x1CC GF_FONT object handle */
    void *msgBank;                /* 0x1D0 MSG bank */
    void *wordSet;                /* 0x1D4 word set */
    void *strBuf;                 /* 0x1D8 STRBUF scratch buffer */
    u32   printSys;               /* 0x1DC PRINTSYS queue */
    void *frameList;              /* 0x1E0 FRAME_LIST object */
    void *entries[50];            /* 0x1E4 per-entry text buffers */
    u32   entryCount;             /* 0x2AC entry count for the current page */
    void *cursorMove;             /* 0x2B0 CURSOR_MOVE object */
    u32   blinkPal;               /* 0x2B4 BLINK_PALANM object */
    u8    fadeState;              /* 0x2B8 0 none, 1 show, 2 hide */
    u8    listPage;               /* 0x2B9 current list page 0..4, 0xFF before entry */
    u8    pageSubState;           /* 0x2BA page entry sub state */
    u8    searchProgress;         /* 0x2BB search engine progress 0..0x79 */
    void *resultGraphics;         /* 0x2BC result graphics buffer */
    u8    msgDialogActive;        /* 0x2C0 nonzero while a message dialog runs */
    u8    cursorIndex;            /* 0x2C1 actor index the cursor points at */
    u8    msgPhase;               /* 0x2C2 message dialog phase */
    u8    msgTimer;               /* 0x2C3 message dialog phase timer */
    u32   tickCounter;            /* 0x2C4 ZUKAN_TickCounter counter */
    u16   scrollRemaining;        /* 0x2C8 scroll move frames left */
    s16   scrollDelta;            /* 0x2CA scroll move step per frame */
    u32   searchEngineWork;       /* 0x2CC ZUKAN_SEARCH_ENGINE work handle */
    u32   filterResult;           /* 0x2D0 ZUKAN_SEARCH_ENGINE_Filter result */
} ZknSearchWork;

#endif
