#ifndef B_PLIST_TYPES_H
#define B_PLIST_TYPES_H

/*
 * Owner header for the B_PLIST work objects of ov198 (the Pokemon list /
 * summary screen). Shared by b_plist_main.c, b_plist_draw.c and b_plist_anm.c.
 *
 * The three files all operate on one work object (B_PlistWork, 0x2544 bytes)
 * allocated by GFL_HEAP_Alloc. Its first field points at the shared app object
 * (B_PlistHost) and the tail holds a table of text windows. The old ObjNNNNN
 * views disagreed on the type at several offsets; the fields below use a union
 * wherever two views read the same offset with different but equal-size types.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef signed char s8;

struct B_PlistHost;

/* One text window handle: a created window and its visibility flag (8 bytes). */
struct B_PlistWin {
    void *handle;              /* 0x00 window created by BMP_WIN_Create */
    u8 visible;                /* 0x04 nonzero when the window is shown */
    u8 pad5[3];
};

#define B_PLIST_WIN_COUNT 23

/* The app object a B_PlistWork points at through its owner field. */
struct B_PlistHost {
    void *config;              /* 0x00 game config, first argument of WAZA_TOOL_IsHmMove */
    void *party;               /* 0x04 POKEPARTY shown in the first rows */
    void *partnerParty;        /* 0x08 POKEPARTY shown in rows 3..5 */
    u32   font;                /* 0x0C font handle for text measuring and printing */
    u16   heapId;              /* 0x10 heap id, ORed with 0x8000 */
    u16   pad12;               /* 0x12 */
    int   reserved14;             /* 0x14 */
    int   ownerKind;           /* 0x18 compared with 1 by B_PLIST_MAIN_GetOwnerFlag18 */
    u8    pad1C[3];
    u8    listType;             /* 0x1F list type, compared with 2, 3 and 5; role not known */
    u8    orderIndex;          /* 0x20 current order table index */
    u8    pad21;
    u8    partyCount;          /* 0x22 upper bound checked by B_PLIST_MAIN_IsIndexValid */
    u8    pad23;
    u16   itemId;              /* 0x24 item id read through FILE_UTIL_GetItemParam */
    u16   moveId;              /* 0x26 move id shown by the move info page */
    void *fadeContext;         /* 0x28 last argument of PALANM_RequestFade */
    int   reserved2C;             /* 0x2C */
    u32   cancelRequest;       /* 0x30 1 when the caller asked to cancel */
    int   exitRequest;         /* 0x34 1 when the caller asked to close the screen */
    int   reserved38;             /* 0x38 */
    int   reserved3C;             /* 0x3C */
    u32   seEnabled;           /* 0x40 1 when sound effects are played */
    void *syncFlagPtr;         /* 0x44 pointer to a flag byte shared with the caller */
    u8    pad48[3];
    u8    moveKind;            /* 0x4B compared with 4 by B_PLIST_MAIN_CheckMoveUsable */
};

/*
 * One row / slot record (0x4C bytes). Its base is p + 4 + index * 0x4C.
 * A few call sites index it as p + index * 0x4C; the base is left exactly
 * as the original wrote it so the codegen does not move.
 */
struct B_PlistSlot {
    union { void *ptr; u32 species; } u00;   /* 0x00 mon species id */
    u16   pad04;                              /* 0x04 */
    u16   attack;                             /* 0x06 */
    u16   active;                             /* 0x08 nonzero when the slot holds a mon */
    u16   speed;                              /* 0x0A */
    u16   spAttack;                           /* 0x0C */
    u16   spDefense;                          /* 0x0E */
    u16   hp;                                 /* 0x10 current HP */
    u16   maxHp;                              /* 0x12 */
    u16   hpRawBase;                          /* 0x14 current HP read through an unbiased base (record - 4) */
    struct { u8 level : 7; u8 flag : 1; } levelBits; /* 0x16 */
    u8    pad17;                              /* 0x17 */
    u16   abilityId;                          /* 0x18 */
    union {
        u16 heldItem;                         /* 0x1A */
        struct { u8 pad; struct { u8 low : 7; u8 high : 1; } flags; } bits;
    } u1A;
    u32   expCurrent;                         /* 0x1C */
    u32   expMin;                             /* 0x20 */
    u32   expMax;                             /* 0x24 */
    u8    pad28[8];                           /* 0x28 */
    struct { u16 value; u8 pad[6]; } extra[4]; /* 0x30 four halfwords, stride 8 */
    u8    pad38[0x14];                        /* 0x38 */
};

/* The shared B_PLIST work object (0x2544 bytes). */
struct B_PlistWork {
    struct B_PlistHost *owner;  /* 0x0000 app object */
    u8    pad04[0x0C];          /* 0x0004 */
    u16   monSpecies;           /* 0x0010 */
    u16   monSpeciesAlt;        /* 0x0012 */
    u8    pad14[3];             /* 0x0014 */
    struct { u8 low : 3; u8 kind : 4; u8 high : 1; } monFlags; /* 0x0017 */
    u8    pad18[0x10];          /* 0x0018 */
    void *task;                 /* 0x0028 task installed by TCB_AddTask */
    void *palAnmSlot;           /* 0x002C */
    u8    pad30[0x1A4];         /* 0x0030 */
    union { void *tcbl; u32 tcblWord; } u1D4; /* 0x01D4 tile-cache block */
    union { void *palAnm; u32 palAnmWord; } u1D8; /* 0x01D8 */
    u8    pad1DC[0x1C9C];       /* 0x01DC */
    u16   palette[16];          /* 0x1E78 palette data copied into a PALANM slot */
    u8    animStep;             /* 0x1E98 palette animation step */
    u8    animTimer;            /* 0x1E99 palette animation timer */
    u8    animKind;             /* 0x1E9A palette animation kind */
    struct { u8 low : 4; u8 mode : 3; u8 active : 1; } animFlags; /* 0x1E9B */
    union { void *fontSmall; u32 fontSmallWord; } u1E9C; /* 0x1E9C GF_FONT_Create_EC64 result */
    void *msgBank;              /* 0x1EA0 message bank */
    void *wordSet;              /* 0x1EA4 WORDSET used to format text */
    union { void *strBuf; u32 strBufWord; } u1EA8; /* 0x1EA8 string buffer the formatted text goes to */
    union { void *printQue; u32 printQueWord; } u1EAC; /* 0x1EAC print queue */
    union { void *printStream; int printStreamWord; } u1EB0; /* 0x1EB0 */
    int   printStreamFlags;     /* 0x1EB4 */
    union { u32 unitId; void *unitPtr; } u1EB8; /* 0x1EB8 actor unit */
    u8    pad1EBC[0x18];        /* 0x1EBC */
    void *resHandle;            /* 0x1ED4 */
    u8    pad1ED8[0x30];        /* 0x1ED8 */
    void *resHandle2;           /* 0x1F08 */
    u8    pad1F0C[0x54];        /* 0x1F0C */
    struct B_PlistWin win[B_PLIST_WIN_COUNT]; /* 0x1F60 text windows */
    u8    pad2018[0x158];       /* 0x2018 */
    union { u32 word; void *ptr; } u2170; /* 0x2170 */
    u8    winCount;             /* 0x2174 */
    union {                     /* 0x2175 */
        struct { u8 low : 5; u8 high : 3; } bc;      /* low 5 bits, top 3 bits */
        struct { u8 low : 6; u8 bit : 1; u8 high : 1; } f060; /* main Flag view */
        struct { u8 low : 7; u8 flip : 1; } e8b4;    /* low 7 bits, flip bit */
        struct { u8 low : 5; u8 flip : 1; u8 high : 2; } e9a0; /* low 5, flip bit, top 2 */
    } winFlags;
    u8    pad2176;              /* 0x2176 */
    struct { u8 step : 4; u8 flags : 4; } stateFlags; /* 0x2177 */
    int   state;                /* 0x2178 */
    u32   nextState;            /* 0x217C */
    u8    mode;                 /* 0x2180 */
    u8    pad2181[3];           /* 0x2181 */
    union { u32 word; void *ptr; } u2184; /* 0x2184 window/mode handle */
    union { u32 word; void *ptr; } u2188; /* 0x2188 B_APP_TOOL actor handle */
    union { u32 word; int ival; void *ptr; } u218C; /* 0x218C */
    u8    flag2190;             /* 0x2190 */
    u8    flag2191;             /* 0x2191 */
    u8    flag2192;             /* 0x2192 */
    u8    flag2193;             /* 0x2193 */
    void *bgWinFrame;           /* 0x2194 */
    u8    pad2198[0x300];       /* 0x2198 */
    u8    flag2498;             /* 0x2498 */
    u8    flag2499;             /* 0x2499 */
    u8    flag249A;             /* 0x249A */
    u8    pad249B;              /* 0x249B */
    u16   selPairFirst;         /* 0x249C first value of a stored selection pair, 0xFF when free */
    u16   selPairSecond;        /* 0x249E */
    u8    pad24A0[4];           /* 0x24A0 */
    int   charHandles;           /* 0x24A4 first of 26 character handles (to 0x250C) */
    u8    pad24A8[0x14];        /* 0x24A8 */
    int   iconSet1Char;            /* 0x24BC character handle of icon set 1 (role of the set not known) */
    int   iconSet3Char;            /* 0x24C0 character handle of icon set 3 (role of the set not known) */
    u8    pad24C4[0x38];        /* 0x24C4 */
    int   moveKindChar;         /* 0x24FC */
    int   moveKindCharAlt;      /* 0x2500 */
    int   toolChar;             /* 0x2504 */
    int   gearChar;             /* 0x2508 */
    u8    pad250C[4];           /* 0x250C */
    int   iconSet1Pal;            /* 0x2510 palette handle of icon set 1 (role of the set not known) */
    int   iconSet3Pal;            /* 0x2514 palette handle of icon set 3 (role of the set not known) */
    int   typeIconPal;          /* 0x2518 */
    int   toolPal;              /* 0x251C */
    int   gearPal;              /* 0x2520 */
    u8    pad2524[4];           /* 0x2524 */
    int   iconSet1Cell;            /* 0x2528 cell anim handle of icon set 1 (role of the set not known) */
    int   iconSet3Cell;            /* 0x252C cell anim handle of icon set 3 (role of the set not known) */
    int   typeIconCell;         /* 0x2530 */
    int   toolCell;             /* 0x2534 */
    int   gearCell;             /* 0x2538 */
    void *toolWinIds;           /* 0x253C window id table passed to B_APP_TOOL_ShowWindows */
    int   done;                 /* 0x2540 nonzero when the screen is finished */
};

#endif
