/*
 * file:     field_tile_move.c
 * unit:     yes
 * function: func_021C8984, func_021C89A8, func_021C89BC, func_021C8A30, func_021C8A74, func_021C8A7C, func_021C8A8C, func_021C8A9C, func_021C8AAC, func_021C8AD0, func_021C8B14, func_021C8B48, func_021C8B5C, func_021C8B78, func_021C8B9C, func_021C8BC4, func_021C8BD8, func_021C8BFC, func_021C8C88, func_021C8CF0, func_021C8CF8, func_021C8D08, func_021C8D18, func_021C8D3C, func_021C8D74, func_021C8DC4, func_021C8DD4, func_021C8DE4, func_021C8DF4, func_021C8E14, func_021C8E30, func_021C8E5C
 * address:  0x021C8984
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C8984: floor tile tasks started from the attribute check in field_event_check.c (func_0218AD28) (file name guess, no anchor).
 *
 * symbols:
 *   d_021DAB24  0x021DAB24  data  ov021  a4
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_02006224  0x02006224  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021639C0  0x021639C0  thumb  ov010
 *   d_021DAB54  0x021DAB54  data  a4
 *   d_021DAB44  0x021DAB44  data  ov021  a4
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBC8  0x021ACBC8  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ABE8C  0x021ABE8C  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021AD598  0x021AD598  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_0200616C  0x0200616C  thumb
 */
#include "../ov010/fldmmdl_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct FieldMap FieldMap;
typedef struct FieldPlayer FieldPlayer;
typedef struct FieldEffectCtrl FieldEffectCtrl;

/* Update function of a game event: (event, state, work), returns 1 when finished. */
typedef int (*GameEventFunc)();

/* Spin tile table entry: the player keeps turning on tiles with this attribute. */
typedef struct TileSpinEntry {
    u16 attr;
    u16 stepAcmd;      /* animation command of one turn step */
    u16 stopDir;       /* direction the player faces when the spin ends */
    u16 interval;      /* frames between turns */
} TileSpinEntry;

/* Slide tile table entry: the player slides over tiles with this attribute. */
typedef struct TileSlideEntry {
    u16 attr;
    u16 stepAcmd;      /* animation command of one slide step */
    u16 reserved;      /* never read */
} TileSlideEntry;

/* Bump tile table entry: the slide ends against tiles with this attribute. */
typedef struct TileBumpEntry {
    u16 attr;
    u16 bumpAcmd;      /* animation command of the bump */
} TileBumpEntry;

/* Work of the spin task (0x1C). */
typedef struct TileSpinWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    FieldPlayer *player;        /* 0x08 */
    Mmdl *mmdl;                 /* 0x0C, the player's field model */
    TileSpinEntry *entry;       /* 0x10, entry of the tile the player stands on */
    u16 dir;                    /* 0x14, display direction while spinning */
    u16 reserved16;             /* 0x16 */
    u32 frameCount;             /* 0x18 */
} TileSpinWork;

/* Work of the slide task (0x28). */
typedef struct TileSlideWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    FieldPlayer *player;        /* 0x08 */
    Mmdl *mmdl;                 /* 0x0C, the player's field model */
    TileSlideEntry *slideEntry; /* 0x10, slide entry of the tile under the player */
    TileBumpEntry *bumpEntry;   /* 0x14, bump entry of the tile under the player */
    u32 bumpStarted;            /* 0x18, set once the bump animation runs */
    int bumpSeSlot;             /* 0x1C, SE slot of 0x55E (bump) */
    int bumpEffectSeSlot;       /* 0x20, SE slot of 0x6E2 (bump effect) */
    int slideSeSlot;            /* 0x24, SE slot of 0x769 (slide loop) */
} TileSlideWork;

extern int func_0216D454(Mmdl *mmdl);
extern int func_02006148(u32 seId);
extern void func_020061F8(int seSlot);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, GameEventFunc func, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern Mmdl *func_021A3074(FieldPlayer *player);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern void func_021A3038(FieldPlayer *player, VecFx32 *outPos);
extern void *func_02188C98(FieldMap *fieldMap);
extern int func_021AB0D4(void *mapAttr, VecFx32 *pos);
extern u16 func_021AB0F0(u32 attr);
extern void func_0216D550(Mmdl *mmdl, u32 bit);
extern void func_0216D5E0(Mmdl *mmdl, int dir);
extern void func_0216D548(Mmdl *mmdl, u32 bit);
extern void func_0216D410(Mmdl *mmdl, u16 acmd);
extern int func_02006224(int seSlot);
extern void func_020061E4(u32 seId);
extern u32 func_021639C0(Mmdl *mmdl, u16 dir);
extern u32 func_021A2F98(FieldPlayer *player);
extern u32 func_021ACBC8(u32 namipoke, int visible);
extern FieldEffectCtrl *func_02188CD0(FieldMap *fieldMap);
extern int func_021ABE8C(FieldEffectCtrl *ctrl, int effectId);
extern void func_021ABE30(FieldEffectCtrl *ctrl, int *effectIds, int count);
extern void func_021AD598(FieldEffectCtrl *ctrl, u32 kind, VecFx32 *pos);
extern int func_02005C64(void);
extern void func_0200616C(u32 seId, int seSlot);

TileSpinEntry *func_021C8984(u16 attr);
int func_021C89A8(u16 attr);
int func_021C89BC(GameEvent *event, int *state, TileSpinWork *work);
GameEvent *func_021C8A30(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int func_021C8A74(u16 attr);
u16 func_021C8A7C(TileSpinWork *work);
u16 func_021C8A8C(TileSpinWork *work);
int func_021C8A9C(TileSpinWork *work);
u16 func_021C8AAC(TileSpinWork *work);
void func_021C8AD0(TileSpinWork *work);
void func_021C8B14(TileSpinWork *work);
void func_021C8B48(TileSpinWork *work);
int func_021C8B5C(TileSpinWork *work);
void func_021C8B78(TileSpinWork *work);
const TileSlideEntry *func_021C8B9C(u16 attr);
int func_021C8BC4(u16 attr);
TileBumpEntry *func_021C8BD8(u16 attr);
int func_021C8BFC(GameEvent *event, int *state, TileSlideWork *work);
GameEvent *func_021C8C88(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int func_021C8CF0(u16 attr);
u16 func_021C8CF8(TileSlideWork *work);
u16 func_021C8D08(TileSlideWork *work);
u16 func_021C8D18(TileSlideWork *work);
void func_021C8D3C(TileSlideWork *work);
void func_021C8D74(TileSlideWork *work);
void func_021C8DC4(TileSlideWork *work);
void func_021C8DD4(TileSlideWork *work);
int func_021C8DE4(TileSlideWork *work);
void func_021C8DF4(TileSlideWork *work);
void func_021C8E14(TileSlideWork *work);
void func_021C8E30(TileSlideWork *work);
void func_021C8E5C(TileSlideWork *work);
extern TileSpinEntry d_021DAB24[4];
extern const TileSlideEntry d_021DAB54[4];
extern TileBumpEntry d_021DAB44[4];

/* Finds the spin table entry for a tile attribute. */
TileSpinEntry *func_021C8984(u16 attr)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (attr == d_021DAB24[i].attr)
            return &d_021DAB24[i];
    }
    return 0;
}

int func_021C89A8(u16 attr)
{
    if (func_021C8984(attr) != 0) {
        return 1;
    }
    return 0;
}

/* Spin task: 0 checks the tile, 1 turns the player every interval until blocked, 2 ends. */
int func_021C89BC(GameEvent *event, int *state, TileSpinWork *work)
{
    switch (*state) {
    case 0:
        if (func_021C89A8(func_021C8AAC(work)) == 0) {
            *state = 2;
        } else {
            *state = 1;
        }
        break;
    case 1:
        func_021C8AD0(work);
        if (func_0216D454(work->mmdl)) {
            func_021C8B48(work);
            if (func_021C8B5C(work)) {
                func_020061F8(func_02006148(0x694));
                *state = 2;
            } else {
                func_021C8B14(work);
            }
        }
        break;
    case 2:
        func_021C8B78(work);
        return 1;
    }
    return 0;
}

/* Creates the spin task with a 0x1C byte work area and fills it from the field map. */
GameEvent *func_021C8A30(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, parent, func_021C89BC, 0x1C);
    TileSpinWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->player = func_02188CB4(fieldMap);
    work->mmdl = func_021A3074(work->player);
    work->entry = 0;
    work->dir = func_0216D5F8(work->mmdl);
    work->frameCount = 0;
    return event;
}

/* Tail-call thunk: forwards to func_021C89A8 with no argument change. */
int func_021C8A74(u16 attr)
{
    return func_021C89A8(attr);
}

u16 func_021C8A7C(TileSpinWork *work)
{
    if (work->entry != 0) {
        return work->entry->stepAcmd;
    }
    return 0;
}

u16 func_021C8A8C(TileSpinWork *work)
{
    if (work->entry != 0) {
        return work->entry->stopDir;
    }
    return 0;
}

int func_021C8A9C(TileSpinWork *work)
{
    if (work->entry != 0) {
        return work->entry->interval;
    }
    return 0;
}

/* Attribute of the tile under the player. */
u16 func_021C8AAC(TileSpinWork *work)
{
    VecFx32 pos;
    func_021A3038(work->player, &pos);
    return func_021AB0F0(func_021AB0D4(func_02188C98(work->fieldMap), &pos));
}

/* Counts frames; every interval turns the player's display direction a quarter. */
void func_021C8AD0(TileSpinWork *work)
{
    int interval = func_021C8A9C(work);

    work->frameCount = work->frameCount + 1;
    if (work->frameCount % interval == 0) {
        work->dir = (work->dir + 1) % 4;
        func_0216D550(work->mmdl, MMDL_STABIT_PAUSE_DIR);
        func_0216D5E0(work->mmdl, work->dir);
        func_0216D548(work->mmdl, MMDL_STABIT_PAUSE_DIR);
    }
}

/* Starts one spin step: animation command, direction pause, looping SE. */
void func_021C8B14(TileSpinWork *work)
{
    func_0216D410(work->mmdl, func_021C8A7C(work));
    func_0216D548(work->mmdl, MMDL_STABIT_PAUSE_DIR);
    if (func_02006224(func_02006148(0x694)) == 0)
        func_020061E4(0x694);
}

void func_021C8B48(TileSpinWork *work)
{
    TileSpinEntry *entry = func_021C8984(func_021C8AAC(work));
    if (entry != 0)
        work->entry = entry;
}

/* Nonzero when the tile in the stop direction blocks the player. */
int func_021C8B5C(TileSpinWork *work)
{
    if (func_021639C0(work->mmdl, func_021C8A8C(work)) != 0) {
        return 1;
    }
    return 0;
}

void func_021C8B78(TileSpinWork *work)
{
    func_0216D550(work->mmdl, MMDL_STABIT_PAUSE_DIR);
    if (work->entry != 0)
        func_0216D5E0(work->mmdl, func_021C8A8C(work));
}

/*
 * 2026-10-02: the base/offset register swap of the earlier DIFF closed by
 * declaring the table const (the const element type recolours the hoisted
 * table base into r3).
 */
const TileSlideEntry *func_021C8B9C(u16 attr)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (d_021DAB54[i].attr == attr)
            return &d_021DAB54[i];
    }
    return 0;
}

int func_021C8BC4(u16 attr)
{
    if (func_021C8B9C(attr) != 0) {
        return 1;
    }
    return 0;
}

TileBumpEntry *func_021C8BD8(u16 attr)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (attr == d_021DAB44[i].attr)
            return &d_021DAB44[i];
    }
    return 0;
}

/* Slide task: 0 checks the tile, 1 slides step by step until no slide or bump tile is left, 2 ends. */
int func_021C8BFC(GameEvent *event, int *state, TileSlideWork *work)
{
    switch (*state) {
    case 0:
        if (func_021C8BC4(func_021C8D18(work)) == 0) {
            *state = 2;
        } else {
            func_021ACBC8(func_021A2F98(work->player), 0);
            func_021C8E30(work);
            *state = 1;
        }
        break;
    case 1:
        func_021C8E30(work);
        if (func_0216D454(work->mmdl)) {
            func_021C8D74(work);
            func_021C8DC4(work);
            func_021C8DD4(work);
            if (work->slideEntry == 0 && work->bumpEntry == 0) {
                func_021C8E5C(work);
                *state = 2;
            } else {
                func_021C8D3C(work);
            }
        }
        break;
    case 2:
        func_021C8DE4(work);
        return 1;
    }
    return 0;
}

/* Creates the slide task with a 0x28 byte work area; loads the three SE slots (0x55E, 0x6E2, 0x769). */
GameEvent *func_021C8C88(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap)
{
    FieldPlayer *player = func_02188CB4(fieldMap);
    GameEvent *event = func_020122C0(gameSystem, parent, func_021C8BFC, 0x28);
    TileSlideWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->player = player;
    work->mmdl = func_021A3074(work->player);
    work->slideEntry = 0;
    work->bumpEntry = 0;
    work->bumpStarted = 0;
    work->bumpSeSlot = func_02006148(0x55E);
    work->bumpEffectSeSlot = func_02006148(0x6E2);
    work->slideSeSlot = func_02006148(0x769);
    return event;
}

/* Tail-call thunk: forwards to func_021C8BC4 with no argument change. */
int func_021C8CF0(u16 attr)
{
    return func_021C8BC4(attr);
}

u16 func_021C8CF8(TileSlideWork *work)
{
    if (work->slideEntry != 0) {
        return work->slideEntry->stepAcmd;
    }
    return 0;
}

u16 func_021C8D08(TileSlideWork *work)
{
    if (work->bumpEntry != 0) {
        return work->bumpEntry->bumpAcmd;
    }
    return 0;
}

/* Attribute of the tile under the player. */
u16 func_021C8D18(TileSlideWork *work)
{
    VecFx32 pos;
    func_021A3038(work->player, &pos);
    return func_021AB0F0(func_021AB0D4(func_02188C98(work->fieldMap), &pos));
}

/* Starts the next step: the bump animation if the tile bumps, else the slide step. */
void func_021C8D3C(TileSlideWork *work)
{
    if (work->bumpEntry != 0) {
        func_0216D410(work->mmdl, func_021C8D08(work));
        func_021C8DF4(work);
        work->bumpStarted = 1;
        return;
    }
    if (work->slideEntry != 0)
        func_0216D410(work->mmdl, func_021C8CF8(work));
}

/* After a bump step: registers effect 9, spawns it at the player and clears the bump state. */
void func_021C8D74(TileSlideWork *work)
{
    VecFx32 pos;
    int effectId;
    FieldEffectCtrl *effectCtrl;

    if (work->bumpEntry != 0) {
        effectCtrl = func_02188CD0(work->fieldMap);
        effectId = 9;
        if (func_021ABE8C(effectCtrl, effectId) == 0) {
            func_021ABE30(effectCtrl, &effectId, 1);
        }
        func_021A3038(work->player, &pos);
        func_021AD598(effectCtrl, 0, &pos);
        func_021C8E14(work);
        work->bumpEntry = 0;
        work->bumpStarted = 0;
    }
}

void func_021C8DC4(TileSlideWork *work)
{
    work->slideEntry = (TileSlideEntry *)func_021C8B9C(func_021C8D18(work));
}

void func_021C8DD4(TileSlideWork *work)
{
    work->bumpEntry = func_021C8BD8(func_021C8D18(work));
}

/* Shows the player's surf Pokemon again. */
int func_021C8DE4(TileSlideWork *work)
{
    return func_021ACBC8(func_021A2F98(work->player), 1);
}

/* Stops the slide loop SE and plays the bump SE. */
void func_021C8DF4(TileSlideWork *work)
{
    if (func_02005C64() == 0) {
        func_020061F8(work->slideSeSlot);
        func_0200616C(0x55E, work->bumpSeSlot);
    }
}

void func_021C8E14(TileSlideWork *work)
{
    if (func_02005C64() == 0)
        func_0200616C(0x6E2, work->bumpEffectSeSlot);
}

/* Keeps the slide loop SE (0x769) playing until a bump starts. */
void func_021C8E30(TileSlideWork *work)
{
    if (func_02005C64() == 0 && work->bumpStarted == 0 && func_02006224(work->slideSeSlot) == 0)
        func_0200616C(0x769, work->slideSeSlot);
}

/* Tail-call thunk: stops the slide loop SE. */
void func_021C8E5C(TileSlideWork *work)
{
    func_020061F8(work->slideSeSlot);
}
