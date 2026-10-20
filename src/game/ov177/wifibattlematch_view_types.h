#ifndef GAME_OV177_WIFIBATTLEMATCH_VIEW_TYPES_H
#define GAME_OV177_WIFIBATTLEMATCH_VIEW_TYPES_H

#include "../types.h"
#include "../ov177/wifibattlematch_view_shared_types.h"

typedef struct WifiBattleMatchViewRoot { int a, b, c, d, e, f; } WifiBattleMatchViewRoot;

typedef struct WifiBattleMatchViewAnimState { char pad[0x18]; unsigned short out[16], original[16], target[16], phase; } WifiBattleMatchViewAnimState;

typedef struct WifiBattleMatchViewMainInfo {
    u32 kind;            /* 0x00, REC[1] box kind */
    u16 count, pad6;     /* 0x04, BSUBWAY stat count */
    u32 name;            /* 0x08, avatar id (MYSTATUS_GetTrainerView), poke-actor index */
    void *total;         /* 0x0C, score (a + b), first GetEntryValue argument */
    u16 a, b;            /* 0x10 win count, 0x12 loss count */
} WifiBattleMatchViewMainInfo;

typedef struct WifibattlematchViewWork {
    unsigned count;      /* 0x000 */
    void *wins[30];      /* 0x004 */
    WifibattlematchViewSlot slots[30];      /* 0x07c */
    void *objs[22];      /* 0x16c */
    void *chr[6];        /* 0x1c4 */
    char pad1dc[4];
    void *cell;          /* 0x1e0 */
    void *pal;           /* 0x1e4 */
    u32 actorPal;        /* 0x1e8 */
    u32 actorChr;        /* 0x1ec */
    u32 actorCell;       /* 0x1f0 */
    void *pal2;          /* 0x1f4 */
    void *chr2;          /* 0x1f8 */
    void *cell2;         /* 0x1fc */
    unsigned objCount;   /* 0x200 */
    short baseX[22];     /* 0x204 */
    u8 bg;               /* 0x230 */
    u8 palette;          /* 0x231 */
    u8 palSlot;          /* 0x232 */
    u8 spritePalSlot;
    u32 layer;           /* 0x234 */
    void *record;        /* 0x238 */
    u16 heap;            /* 0x23c */
    u16 pad23e;
    void *owner;         /* 0x240 */
} WifibattlematchViewWork;

typedef struct WifiBattleMatchViewRecordWork {
    u32 owner;           /* 0x00 */
    void *win[8];        /* 0x04 */
    WifibattlematchViewSlot ent[7];        /* 0x24 */
    char pad5c[0x64 - 0x5c];
    void *recordActor;          /* 0x64 */
    void *obj[5];        /* 0x68 */
    void *menu;          /* 0x7c */
    u16 recPal;          /* 0x80 */
    u16 recChr;          /* 0x82 */
    u16 recCell;         /* 0x84 */
    char pad86[0x88 - 0x86];
    unsigned count;      /* 0x88 */
    unsigned short base; /* 0x8c */
    unsigned short objBase[5]; /* 0x8e */
    u32 mode;            /* 0x98 */
} WifiBattleMatchViewRecordWork;

typedef struct WifiBattleMatchViewRecord {
    char pad0[0x28];
    unsigned score;      /* 0x28 */
    u32 losses;          /* 0x2c */
    void *total;           /* 0x30 */
    unsigned count;      /* 0x34 */
    char name[1];        /* 0x38 */
} WifiBattleMatchViewRecord;

typedef struct WifiBattleMatchViewPartyWork {
    void *pal;
    void *chr[7];
    void *cell;
    void *palB;
    void *chrB;
    void *cellB;
    void *spr[14];
    void *win[6];
    WifibattlematchViewSlot ent[6];
    unsigned count;
    short base[14];
} WifiBattleMatchViewPartyWork;

#endif
