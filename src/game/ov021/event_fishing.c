/*
 * file:     event_fishing.c
 * unit:     yes
 * function: func_021C5C64, func_021C5D10, func_021C5DF4, func_021C5FA8, func_021C5FC0, func_021C5FEC, func_021C6018, func_021C602C, func_021C6054
 * address:  0x021C5C64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes the FISHING_ helpers 021C5FA8..021C6054 from the head of field_g3dobj.c (lane FXC2).
 * Split from fldeff_splash.c at 0x021C5C64 (lane FXC, CL129: the fishing event; the FISHING_ helpers 021C5FA8..021C6054 were at the head of field_g3dobj.c).
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020061E4 0x020061E4 thumb
 *   abs_id_C2      0x000000C2  data
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_0218DAEC  0x0218DAEC  thumb
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB2E8  0x021AB2E8  thumb  ov021
 *   func_021AB3B0  0x021AB3B0  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A34EC  0x021A34EC  thumb  ov021
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_021AA180  0x021AA180  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021C5FA8  0x021C5FA8  thumb  ov021
 *   func_021C602C  0x021C602C  thumb  ov021
 *   func_02005728  0x02005728  thumb
 *   func_021C5FC0  0x021C5FC0  thumb  ov021
 *   func_021C5FEC  0x021C5FEC  thumb  ov021
 *   func_021C6018  0x021C6018  thumb  ov021
 *   func_021C6054  0x021C6054  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_020130B4  0x020130B4  thumb
 *   func_0216E7C8  0x0216E7C8  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021AE01C  0x021AE01C  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021ADF94  0x021ADF94  thumb  ov021
 */
#include "event_fishing_types.h"
#include "../ov010/fldmmdl_types.h"

struct BbActDesc;
struct BbActRec;
struct Obj;
struct Desc;
struct Ctx;
struct Sub02008C20Obj;
struct Self;
struct S0201235C;

typedef signed short   s16_021C48A0;

typedef signed char    s8;

typedef signed short   s16_021C59A8;

typedef short s16_021C577C;

typedef struct FieldMap FieldMap;

/* Entry template for BILLBOARD_ACT_CreateEntries (0x24 bytes). */
typedef struct BbActDesc {
    u16 imageIdx;
    u16 scaleX;
    u16 scaleY;
    u8 alpha;
    u8 pad07;
    u32 visible;
    u32 animEnable;
    VecFx32 pos;
    void (*onEnd)(void);
    void *userData;
} BbActDesc;

/* Image record for BILLBOARD_ACT_CreateSlots. */
typedef struct BbActRec {
    void *resource;
    u8 type;
    u8 imageId;
    u8 cellWidth;
    u8 cellHeight;
    u32 count;
} BbActRec;

extern u32 func_02082BCC(void *p, int v, int n);
extern void func_020061E4(u32 se);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_02188C98(u8 *p);
extern void *func_02188CB4(void *fieldMap);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void func_021A3364(u32 *a, int b, int *out);
extern u32 func_02188CFC(u8 *p);
extern int func_0218DAEC(u32 a, int *b, u32 *out);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB2E8(int id);
extern int func_021AB3B0(u16 id);
extern void func_02164208(int dir, int *p, int amt);
extern u32 func_02188CE8(u8 *p);
extern void *func_02188C7C(u8 *q);
extern void func_021A3038(unsigned char *id, VecFx32 *out);
extern int func_021A34EC(u8 *p);
extern int func_021AA900(struct Self *self, short *pos);
/* Retain the mode used to store f59 for the helper's second argument. */
extern struct Obj *func_021AA180(struct Ctx *ctx, int mode);
extern void func_0216D9A0(void *o);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *p);
extern void func_0216D674(void *p, u16 v);
extern u32 func_02005728(u32 v);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern void func_021AA8EC(u8 *p);
extern int func_020130B4(int a0);
extern int func_0216E7C8(int a0, int a1, int a2, int a3, int a4);
extern void func_0201235C(struct S0201235C *o, u32 *out);
int func_021C5FA8(FishingWork *w, u32 limit);
int func_021C5FC0(FishingWork *w, u32 limit);
void func_021C5FEC(FishingWork *w);
void func_021C6018(FishingWork *w);
void func_021C602C(FishingWork *w);
void func_021C6054(FishingWork *w);
int func_021C5C64(u32 unused, void *fieldMap, VecFx32 *outPos);
void *func_021C5D10(struct FieldMap *fieldMap, void *gameSystem);
int func_021C5DF4(void *task, int *state, FishingWork *work);
extern unsigned char abs_id_C2[];
extern u32 func_020362DC(void);
extern void *func_02188CD0(void *fieldMap);
extern u32 func_021BB528(void *a, void *mmdl, u32 b, u32 c);
extern void func_021AE01C(u32 effect, u16 v);
extern void func_021AC154(u32 effect);
extern u32 func_021ADF94(void *a, void *b, u32 c, int d);
int func_021C5C64(u32 unused, void *fieldMap, VecFx32 *outPos)
{
    int facingPos[3];
    u32 tileInfo[4];
    void *player;
    u32 mapData;
    u8 playerDir;

    mapData = func_02188C98((u8 *)fieldMap);
    player = func_02188CB4(fieldMap);
    playerDir = func_0216D5F8(func_021A3074(player));
    func_021A3364(player, playerDir, facingPos);
    if (func_02188CFC((u8 *)fieldMap) == 1)
        return 0;
    if (func_0218DAEC(mapData, facingPos, tileInfo) == 0)
        return 0;
    if (func_021AB2E8(func_021AB0F0(tileInfo[2])) == 1) {
        func_02164208(playerDir, facingPos, 0x10000);
        if (func_0218DAEC(mapData, facingPos, tileInfo) == 0)
            return 0;
    }
    if (func_021AB3B0(func_021AB0F0(tileInfo[2])) == 0)
        return 0;
    if (outPos != 0) {
        outPos->x = facingPos[0];
        outPos->y = tileInfo[3];
        outPos->z = facingPos[2];
    }
    return 1;
}

/*
 * Creates the fishing event task for the player facing water.
 */
void *func_021C5D10(struct FieldMap *fieldMap, void *gameSystem)
{
    void *task;
    FishingWork *work;
    int hasEncounter;

    task = func_020122C0(gameSystem, 0, func_021C5DF4, sizeof(FishingWork));
    work = func_020124E8(task);
    func_02082BCC(work, 0, sizeof(FishingWork));
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->gameData = func_020120F4(gameSystem);
    work->encount = (void *)func_02188CE8((u8 *)work->fieldMap);
    work->trainerRecord = func_02012F2C(work->gameData);
    work->mmdlSys = func_02188C7C((u8 *)work->fieldMap);
    work->fieldPlayer = func_02188CB4(fieldMap);
    work->mmdl = func_021A3074(work->fieldPlayer);
    work->playerDir = func_0216D5F8(work->mmdl);
    func_021A3038(work->fieldPlayer, &work->playerPos);
    work->playerState = func_021A34EC(work->fieldPlayer);
    if (func_021C5C64((u32)work->gameData, work->fieldMap, &work->targetPos) == 0)
        work->noTarget = 1;
    work->targetGrid[0] = (work->targetPos.x >> 4) / 4096;
    work->targetGrid[1] = (work->targetPos.y >> 4) / 4096;
    work->targetGrid[2] = (work->targetPos.z >> 4) / 4096;
    if (func_021AA900(work->encount, work->targetGrid))
        work->hasEncounter = hasEncounter = 1;
    else
        work->hasEncounter = hasEncounter = 0;
    work->wildEncounter = func_021AA180(work->encount, hasEncounter);
    func_0216D9A0(work->mmdlSys);
    return task;
}

/*
 * Fishing event main. States: 0 start, 1 and 2 cast, 3 wait for a bite,
 * 4 bite (the player may pull), 5 no wild Pokemon (wait then give up),
 * 6 and 7 fish got away or nothing came, 8 and 9 give the player back,
 * 10 start the wild battle.
 */
int func_021C5DF4(void *task, int *state, FishingWork *work)
{
    int result;

    switch (*state) {
    case 0:
        if (work->noTarget != 0) {
            *state = 8;
            break;
        }
        func_021A2F48((u8 *)work->fieldPlayer, 0x200);
        (*state)++;
    case 1:
        if (func_021A2F54((u8 *)work->fieldPlayer) != 1)
            break;
        func_0216D674(work->mmdl, 0);
        func_020061E4(0x684);
        (*state)++;
        break;
    case 2:
        if (func_021C5FA8(work, 15) == 0)
            break;
        func_021C602C(work);
        if (work->wildEncounter == 0) {
            *state = 5;
            break;
        }
        work->biteDelay = func_02005728(0x5a) + 0x1e;
        (*state)++;
        break;
    case 3:
        result = func_021C5FC0(work, work->biteDelay);
        if (result == 1) {
            *state = 6;
            break;
        }
        if (result != 2)
            break;
        func_021C5FEC(work);
        (*state)++;
        break;
    case 4:
        result = func_021C5FC0(work, 0x1e);
        if (result == 0)
            break;
        func_021C6018(work);
        if (result == 1) {
            func_021C6054(work);
            func_0216D674(work->mmdl, 3);
            func_02158780(task, (u16)0x2796, (u32)0, (u32)0, (u32)0x15);
            *state = 10;
            break;
        }
        if (result != 2)
            break;
        func_02008DF0((struct Sub02008C20Obj *)work->trainerRecord, 0x50);
        *state = 7;
        break;
    case 5:
        result = func_021C5FC0(work, 0x78);
        if (result != 2) {
            if (result == 1)
                *state = 6;
            break;
        }
    case 6:
    case 7:
        func_021C6054(work);
        if (work->wildEncounter != 0) {
            if (work->hasEncounter == 1)
                func_021AA8EC(work->encount);
            func_020130B4((int)work->wildEncounter);
        }
        func_0216D674(work->mmdl, 1);
        func_02158780(task, (u16)(*state + 0x2792), (u32)0, (u32)0, (u32)0x15);
        *state = 8;
        break;
    case 8:
        func_021A2F48((u8 *)work->fieldPlayer, 8);
        *state = 9;
    case 9:
        if (func_021A2F54((u8 *)work->fieldPlayer) == 1)
            return 1;
        break;
    case 10:
        func_02008DF0((struct Sub02008C20Obj *)work->trainerRecord, 8);
        func_0201235C(task, (u32 *)func_0216E7C8((int)work->gameSystem, (int)work->fieldMap, (int)work->wildEncounter, 0, (u8)(work->hasEncounter == 1 ? 1 : 4)));
        return 0;
    }
    return 0;
}

int func_021C5FA8(FishingWork *w, u32 limit)
{
    if (w->counter++ < limit)
        return 0;
    w->counter = 0;
    return 1;
}

/*
 * Wait step: 1 on a key press, 2 on timeout, otherwise 0.
 */
int func_021C5FC0(FishingWork *w, u32 limit)
{
    u32 n = w->counter;

    w->counter = n + 1;
    if (n < limit) {
        if (func_020362DC() & 1) {
            w->counter = 0;
            return 1;
        }
    } else {
        w->counter = 0;
        return 2;
    }
    return 0;
}

/*
 * Switches the player model to mode 2 and shows the exclamation mark and rod effects.
 */
void func_021C5FEC(FishingWork *w)
{
    void *effectSys = func_02188CD0(w->fieldMap);

    func_0216D674(w->mmdl, 2);
    w->exclamEffect = func_021BB528(effectSys, w->mmdl, 0, 1);
    func_021AE01C(w->rodEffect, 1);
}

void func_021C6018(FishingWork *w)
{
    if (w->exclamEffect != 0) {
        func_021AC154(w->exclamEffect);
        w->exclamEffect = 0;
    }
}

void func_021C602C(FishingWork *w)
{
    w->rodEffect = func_021ADF94(func_02188CD0(w->fieldMap), &w->targetPos, w->playerDir, w->targetPos.y == w->playerPos.y);
}

void func_021C6054(FishingWork *w)
{
    if (w->rodEffect != 0) {
        func_021AC154(w->rodEffect);
        w->rodEffect = 0;
    }
}
