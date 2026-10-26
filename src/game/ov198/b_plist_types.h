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

#include "../types.h"

struct B_PlistHost;
struct GfFont;
struct PaletteFade;
struct BgWinFrmWork;

/* One text window handle: a created window and its visibility flag (8 bytes). */
struct B_PlistWin {
    void *handle;              /* 0x00 window created by BMP_WIN_Create */
    u8 visible;                /* 0x04 nonzero when the window is shown */
    u8 pad5[3];
};

#define B_PLIST_WIN_COUNT 23

/* The app object a B_PlistWork points at through its owner field. */
struct B_PlistHost {
    void *gameData;            /* 0x00 game data, first argument of WAZA_TOOL_IsHmMove */
    void *party;               /* 0x04 POKEPARTY shown in the first rows */
    void *partnerParty;        /* 0x08 POKEPARTY shown in rows 3..5 */
    struct GfFont *font;       /* 0x0C font handle for text measuring and printing */
    u16   heapId;              /* 0x10 heap id, ORed with 0x8000 */
    u16   pad12;               /* 0x12 */
    u32   rule;                /* 0x14 battle rule (0 outside battle) */
    int   hasPartner;          /* 0x18 compared with 1 by B_PLIST_MAIN_GetOwnerFlag18 */
    u8    isSecondTeam;        /* 0x1C */
    u8    selected[2];         /* 0x1D rows already picked for a swap */
    u8    listType;            /* 0x1F list type, compared with 2, 3 and 5; role not known */
    u8    orderIndex;          /* 0x20 current order table index */
    u8    pickIndex;           /* 0x21 index into order[] where the next pick goes */
    u8    partyCount;          /* 0x22 upper bound checked by B_PLIST_MAIN_IsIndexValid */
    u8    pad23;
    u16   itemId;              /* 0x24 item id read through FILE_UTIL_GetItemParam */
    u16   moveId;              /* 0x26 move id shown by the move info page */
    void *fadeContext;         /* 0x28 last argument of PALANM_RequestFade */
    struct PaletteFade *palAnm; /* 0x2C palette fade handle of the caller */
    u32   cancelRequest;       /* 0x30 1 when the caller asked to cancel */
    int   exitRequest;         /* 0x34 1 when the caller asked to close the screen */
    u8    slotFlags[8];        /* 0x38 per row flag, nonzero when the row cannot be picked */
    u32   seEnabled;           /* 0x40 1 when sound effects are played */
    void *syncFlagPtr;         /* 0x44 pointer to a flag byte shared with the caller */
    u8    order[4];            /* 0x48 picked rows; order[3] is the move kind (CheckMoveUsable) */
    u8    done;                /* 0x4C set to 1 when the screen closes */
    u8    pad4D[3];
};

/* One move entry of a slot (8 bytes). */
struct B_PlistMove {
    u16   id;                                 /* 0x00 move id */
    u8    pp;                                 /* 0x02 current PP */
    u8    maxPp;                              /* 0x03 */
    u8    type;                               /* 0x04 move type */
    u8    category;                           /* 0x05 */
    u8    accuracy;                           /* 0x06 */
    u8    power;                              /* 0x07 */
};

/*
 * One row / slot record (0x4C bytes), B_PlistWork.slot[index]. Some call sites reach it
 * through a base four bytes below the record; their field names were shifted by four.
 */
struct B_PlistSlot {
    void *mon;                                /* 0x00 mon (party member) the row shows */
    u16   species;                            /* 0x04 species id, 0 when the slot is empty */
    u16   attack;                             /* 0x06 */
    u16   active;                             /* 0x08 */
    u16   speed;                              /* 0x0A */
    u16   spAttack;                           /* 0x0C */
    u16   spDefense;                          /* 0x0E */
    u16   hp;                                 /* 0x10 current HP */
    u16   maxHp;                              /* 0x12 */
    u16   pad14;                              /* 0x14 */
    struct { u8 level : 7; u8 flag : 1; } levelBits; /* 0x16 */
    struct { u8 low : 3; u8 kind : 4; u8 high : 1; } statusFlags; /* 0x17 */
    u16   abilityId;                          /* 0x18 */
    union {
        u16 heldItem;                         /* 0x1A */
    } u1A;
    u32   expCurrent;                         /* 0x1C */
    u32   expMin;                             /* 0x20 */
    u32   expMax;                             /* 0x24 */
    u32   form;                               /* 0x28 form id passed to the icon palette lookup */
    struct B_PlistMove move[4];               /* 0x2C */
};

/* The shared B_PLIST work object (0x2544 bytes). */
struct B_PlistWork {
    struct B_PlistHost *owner;  /* 0x0000 app object */
    struct B_PlistSlot slot[6]; /* 0x0004 one record per party row, 0x4C bytes each */
    u8    order[8];             /* 0x01CC row order table */
    void *tcbl;                 /* 0x01D4 tile-cache block */
    void *palAnm;               /* 0x01D8 */
    u16   tileSet0to5[2][4][0x60];  /* 0x01DC tile buffers of tile kinds 0 to 5: [which][index] */
    u16   tileSet8to11[4][0x41];    /* 0x07DC tile kinds 8 to 11 */
    u16   tileSet12[4][25];         /* 0x09E4 tile kind 12 */
    u16   tileSet13[4][25];         /* 0x0AAC tile kind 13 */
    u16   tileSet6[4][25];          /* 0x0B74 tile kind 6 */
    u16   tileSet7[3][0x1FE];       /* 0x0C3C tile kind 7 */
    u16   tileSet14to26[4][0x60];   /* 0x1830 tile kinds 14 to 26 */
    u16   tileSet27[3][0x82];       /* 0x1B30 tile kind 27 */
    u16   tileSet28to31[3][10];     /* 0x1E3C tile kinds 28 to 31 */
    u16   palette[16];          /* 0x1E78 palette data copied into a PALANM slot */
    u8    animStep;             /* 0x1E98 palette animation step */
    u8    animTimer;            /* 0x1E99 palette animation timer */
    u8    animKind;             /* 0x1E9A palette animation kind */
    struct { u8 low : 4; u8 mode : 3; u8 active : 1; } animFlags; /* 0x1E9B */
    void *fontSmall; /* 0x1E9C GF_FONT_Create_EC64 result */
    void *msgBank;              /* 0x1EA0 message bank */
    void *wordSet;              /* 0x1EA4 WORDSET used to format text */
    void *strBuf; /* 0x1EA8 string buffer the formatted text goes to */
    void *printQue; /* 0x1EAC print queue */
    void *printStream; /* 0x1EB0 */
    int   printStreamFlags;     /* 0x1EB4 */
    void *unit; /* 0x1EB8 actor unit */
    void *actor[41];            /* 0x1EBC screen actors; sub-ranges start at 6, 7, 13 and 19 */
    struct B_PlistWin win[B_PLIST_WIN_COUNT]; /* 0x1F60 text windows */
    u8    pad2018[0x158];       /* 0x2018 */
    void *bmpWin; /* 0x2170 */
    u8    winCount;             /* 0x2174 */
    struct {                    /* 0x2175 */
        u8 low : 5;             /* bit 0 toggled by the first window creation */
        u8 flipA : 1;           /* bit 5 */
        u8 flipB : 1;           /* bit 6 */
        u8 flipC : 1;           /* bit 7 */
    } winFlags;
    u8    orderIndex;           /* 0x2176 copy of the host order index */
    struct { u8 step : 4; u8 flags : 4; } stateFlags; /* 0x2177 */
    int   state;                /* 0x2178 */
    u32   nextState;            /* 0x217C */
    u8    mode;                 /* 0x2180 */
    u8    pad2181[3];           /* 0x2181 */
    void *cursorMove; /* 0x2184 window/mode handle */
    void *appTool; /* 0x2188 B_APP_TOOL actor handle */
    int   syncRequested; /* 0x218C */
    u8    flag2190;             /* 0x2190 */
    u8    flag2191;             /* 0x2191 */
    u8    flag2192;             /* 0x2192 */
    u8    flag2193;             /* 0x2193 */
    struct BgWinFrmWork *bgWinFrame; /* 0x2194 */
    u8    pad2198[0x300];       /* 0x2198 */
    u8    flag2498;             /* 0x2498 */
    u8    flag2499;             /* 0x2499 */
    u8    flag249A;             /* 0x249A */
    u8    pad249B;              /* 0x249B */
    struct { u16 first; u16 second; } selPair[2]; /* 0x249C stored selection pairs (first is 0xFF when free) */
    int   charId[26];           /* 0x24A4 character resource ids of the screen sprites (-1 when free) */
    int   palId[6];             /* 0x250C palette resource ids */
    int   cellId[6];            /* 0x2524 cell animation resource ids */
    void *toolWinIds;           /* 0x253C window id table passed to B_APP_TOOL_ShowWindows */
    int   done;                 /* 0x2540 nonzero when the screen is finished */
};

#endif
