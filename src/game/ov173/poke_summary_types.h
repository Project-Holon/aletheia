/*
 * file:     poke_summary_types.h
 * region:   ov173
 * purpose:  real record types for the Poke Summary overlay (poke_summary_main.c,
 *           poke_summary_actor.c, poke_summary_anim.c). Replaces the mechanical
 *           ObjNNNNN views: one struct per object, named fields.
 *
 * Two objects:
 *   PokeSummaryMon   the boxed-mon record handed to the work object at 0x0.
 *   PokeSummaryWork  the 0x228-byte task work object allocated by
 *                    POKE_SUMMARY_MAIN_Create (PROCSYS_AllocProcWork(obj,0x228,79)).
 *
 * Field offsets were read mechanically from the ObjNNNNN views each function
 * used (SW7j/objscan_ov173.txt) and cross-checked against the matched headers.
 * Where two views disagreed at one offset (a 4-byte slot read as both a pointer
 * and a word) the slot keeps the width both views load, so the bytes are
 * unchanged.
 */
#ifndef ALETHEIA_OV173_POKE_SUMMARY_TYPES_H
#define ALETHEIA_OV173_POKE_SUMMARY_TYPES_H

/* The boxed-mon record. Its pointer is stored at PokeSummaryWork.mon (0x0). */
struct PokeSummaryMon {
    void          *party;               /* 0x00  party/mon data pointer */
    unsigned int   myStatus;            /* 0x04  my-status word */
    unsigned int   field08;             /* 0x08  forwarded to the proc args */
    void          *field0C;             /* 0x0C  forwarded to ICA_ANIME_GetField1C */
    unsigned short *moveList;           /* 0x10  u16 move-id array */
    unsigned short selectedIndex;       /* 0x14  highlighted row */
    unsigned short scrollIndex;         /* 0x16  top visible row */
    unsigned char  pad_18[1];           /* 0x18  untouched */
    unsigned char  messageTableIndex;   /* 0x19  row of d_021B8350 */
    unsigned char  applyFlag;           /* 0x1A  cleared once a move is applied */
    unsigned char  variant;             /* 0x1B  party-slot / summary variant */
};

/* Decision dialog state at PokeSummaryWork 0x1D0. */
struct PokeSummaryDecide {
    unsigned char  pad_00[6];           /* 0x1D0  untouched */
    unsigned short windowIndex;         /* 0x1D6  actor / task-menu window index */
    unsigned short result;              /* 0x1D8  value handed back to the caller */
    unsigned short active;              /* 0x1DA  0 waits on an actor, 1 on a window */
};

/* One row of the four move list rows at PokeSummaryWork 0x1E4. */
struct PokeSummaryMoveEntry {
    void          *text;                /* +0x00  message buffer */
    unsigned short number;              /* +0x04  fixed label id */
    unsigned char  pad_06[2];           /* +0x06  untouched */
    unsigned int   value;               /* +0x08  value shown next to the label */
};

/* Registration handles at PokeSummaryWork 0x70. CLACT_RegisterCharacter fills
 * charHandles[0..7]; the remaining slots hold POKEGRA and cell-anim handles.
 * FlushPendingTransfers walks the whole area as eight consecutive words. */
union PokeSummaryReg {
    unsigned int flat[24];              /* 0x70  eight-word walk by the flusher */
    struct {
        unsigned int charHandles[8];        /* 0x70 */
        unsigned int cgrHandle;             /* 0x90 */
        unsigned int paletteHandles[5];     /* 0x94 */
        unsigned int reservedA[4];          /* 0xA8  untouched */
        unsigned int cellAnimHandles[5];    /* 0xB8 */
        unsigned int cellAnimHandle2;       /* 0xCC */
    } named;
};

/* Proc-argument block at PokeSummaryWork 0x180, passed to GAMESYSTEM_CallProc. */
struct PokeSummaryProcArgs {
    unsigned int   party;               /* 0x180  mon->party */
    unsigned int   field04;             /* 0x184  mon->field08 */
    void          *anime;               /* 0x188  ICA_ANIME handle */
    unsigned char  field0C;             /* 0x18C */
    unsigned char  field0D;             /* 0x18D */
    unsigned char  field0E;             /* 0x18E */
    unsigned char  field0F;             /* 0x18F */
    unsigned char  field10;             /* 0x190 */
    unsigned char  netFlagA;            /* 0x191  net-restart flag */
    unsigned char  netFlagB;            /* 0x192  net-restart flag */
    unsigned char  pad_13[1];           /* 0x193  untouched */
    unsigned short record;              /* 0x194  current move id */
    unsigned char  pad_16[2];           /* 0x196  untouched */
    unsigned int   field18;             /* 0x198 */
};

/* One pending character transfer at PokeSummaryWork 0x140 (stride 8). */
struct PokeSummaryTransfer {
    unsigned int   param;               /* +0x00  APP_ICON_GetTypeCellFileId argument */
    unsigned int   flag;                /* +0x04  nonzero while pending */
};

/* The 0x228-byte task work object. */
struct PokeSummaryWork {
    struct PokeSummaryMon *mon;         /* 0x000 */
    void          *bmpWindows[16];      /* 0x004  BMP_WIN handles, index 0..15 */
    void          *msgBank;             /* 0x044  MSGDATA bank */
    void          *wordSet;             /* 0x048  WORDSET */
    void          *strBufA;             /* 0x04C */
    void          *strBufB;             /* 0x050 */
    void          *strBufC;             /* 0x054 */
    void          *menuWork;            /* 0x058  BMP_MENUWORK */
    unsigned char  pad_05C[4];          /* 0x05C  untouched */
    void          *font;                /* 0x060  GF_FONT */
    void          *tcbl;                /* 0x064  TCBL */
    void          *vblankTask;          /* 0x068  vblank task node */
    void          *printStream;         /* 0x06C  PRINTSYS stream */
    union PokeSummaryReg reg;           /* 0x070  registration handles */
    unsigned char  pad_0D0[48];         /* 0x0D0  untouched */
    void          *unit;                /* 0x100  CLACT unit */
    void          *actors[14];          /* 0x104  CLACT actors */
    void          *resourceHandle;      /* 0x13C  ARC handle */
    struct PokeSummaryTransfer transfers[8]; /* 0x140 */
    struct PokeSummaryProcArgs procArgs;/* 0x180 */
    unsigned char  pad_19C[20];         /* 0x19C  untouched */
    unsigned int   state;               /* 0x1B0  task state */
    unsigned char  pad_1B4[4];          /* 0x1B4  untouched */
    unsigned char  moveCount;           /* 0x1B8  moves in the list */
    unsigned char  pad_1B9[1];          /* 0x1B9  untouched */
    unsigned char  textKind;            /* 0x1BA  current text kind */
    unsigned char  field1BB;            /* 0x1BB */
    unsigned char  field1BC;            /* 0x1BC */
    unsigned char  pad_1BD[3];          /* 0x1BD  untouched */
    void          *msgWindow;           /* 0x1C0  message window */
    void          *tmpHandle;           /* 0x1C4  ARC_UTIL_LoadPaletteDataFromHandle out-slot */
    void          *sound;               /* 0x1C8  CURSOR_MOVE handle */
    unsigned short cursorIndex;         /* 0x1CC  CURSOR_MOVE_GetCurrent */
    unsigned short cursorSkipFlag;      /* 0x1CE  skip bit state */
    struct PokeSummaryDecide decide;    /* 0x1D0 */
    void          *taskMenuRes;         /* 0x1DC  APP_TASKMENU_RES */
    void          *taskMenu;            /* 0x1E0  APP_TASKMENU */
    struct PokeSummaryMoveEntry moveEntries[4]; /* 0x1E4 */
    unsigned char  pad_214[4];          /* 0x214  untouched */
    void          *printQueue;          /* 0x218  PRINTSYS_QUE */
    void          *keyCursor;           /* 0x21C  APP_KEYCURSOR */
    void          *taskMenuWindows[2];  /* 0x220 */
};

typedef char PokeSummaryWork_size_check[
    (sizeof(struct PokeSummaryWork) == 0x228) ? 1 : -1];
typedef char PokeSummaryMon_size_check[
    (sizeof(struct PokeSummaryMon) == 0x1C) ? 1 : -1];

#endif
