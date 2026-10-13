/*
 * file:     sp_poke_gimmick.c
 * unit:     yes
 * function: func_021F36C0, func_021F376C, func_021F3788, func_021F3794, func_021F3840, func_021F385C, func_021F3868, func_021F3980, func_021F39AC, func_021F39B8, func_021F3AA0, func_021F3B40, func_021F3B68, func_021F3B90, func_021F3C6C, func_021F3CB8, func_021F3CFC
 * address:  0x021F36C0
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3E94  0x021F3E94  data  a4
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   d_021F3E84     0x021F3E84  data  a4
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_021BE310  0x021BE310  thumb  ov021
 *   d_021F4080     0x021F4080  data  ov059  a1
 *   d_021F3E74     0x021F3E74  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021F3D9C  0x021F3D9C  thumb  ov059
 */
#include "../ov021/fld_exp_obj_types.h"
#include "sp_poke_gimmick_types.h"

extern u16 func_02188C84(struct FieldMap *fieldMap);
extern void *func_02189764(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void func_021897A0(struct FieldMap *fieldMap, int id);
extern void func_021BE760(FldExpObjCnt *expObj, const G3dUtilSetup *setup, int unitIndex);
extern void func_021BE310(FldExpObjCnt *expObj, const G3dUtilSetup *setup, int unitIndex);
extern void func_021BE418(FldExpObjCnt *expObj, u16 unitIndex);
extern void func_021BE4B4(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int hidden);
extern void func_021BE6B8(FldExpObjAnime *anime, int loop);
extern void func_021BE6B0(FldExpObjAnime *anime, int paused);
extern void func_021BE700(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex, int enable);
extern void func_021BE580(FldExpObjCnt *expObj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 func_020307B0(void *memory);
extern void func_020061E4(u32 seId);
extern VecFx32 *func_021BE480(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex);
extern void func_021BE6CC(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex, int frame);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent,
                                       GameEventFunc func, u32 workSize);

void func_021F36C0(struct FieldMap *fieldMap);
void func_021F376C(struct FieldMap *fieldMap);
void func_021F3788(struct FieldMap *fieldMap);
void func_021F3794(struct FieldMap *fieldMap);
void func_021F3840(struct FieldMap *fieldMap);
void func_021F385C(struct FieldMap *fieldMap);
void func_021F3868(struct FieldMap *fieldMap);
void func_021F3980(struct FieldMap *fieldMap);
void func_021F39AC(struct FieldMap *fieldMap);
struct GameEvent *func_021F39B8(struct GameSystem *gameSystem, int side, VecFx32 *from, const VecFx32 *to,
                                fx32 bump, int frames);
void func_021F3AA0(struct GameSystem *gameSystem, int side, VecFx32 *pos);
void func_021F3B40(struct GameSystem *gameSystem, int side);
void func_021F3B68(struct GameSystem *gameSystem, int side);
int func_021F3B90(struct GameEvent *event, int *seq, void *eventWork);
int func_021F3C6C(struct GameEvent *event, int *seq, void *eventWork);
int func_021F3CB8(struct GameEvent *event, int *seq, void *eventWork);
void func_021F3CFC(struct GameSystem *gameSystem, VecFx32 *pos, u16 removeObjectId, u16 addObjectId);

extern G3dUtilSetup d_021F3E94;
extern G3dUtilSetup d_021F3E84;
extern G3dUtilSetup d_021F3E74;
extern char d_021F4080[];

/* First two-model variant: add the unit, hide both models and stop all their animations. */
void func_021F36C0(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;
    FldExpObjAnime *anime;

    expObj = func_02188D2C(fieldMap);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), 0x28);
    func_021BE760(expObj, &d_021F3E94, 0);
    func_021BE4B4(expObj, 0, 1, 1);
    func_021BE4B4(expObj, 0, 0, 1);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        anime = func_021BE674(expObj, 0, 0, i);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, 0, i, 0);
        anime = func_021BE674(expObj, 0, 1, i);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, 1, i, 0);
    }
}

void func_021F376C(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;

    expObj = func_02188D2C(fieldMap);
    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}

void func_021F3788(struct FieldMap *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}

/* Second two-model variant, same setup with its own unit. */
void func_021F3794(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;
    FldExpObjAnime *anime;

    expObj = func_02188D2C(fieldMap);
    func_02189764(fieldMap, 1, func_02188C84(fieldMap), 0x28);
    func_021BE760(expObj, &d_021F3E84, 0);
    func_021BE4B4(expObj, 0, 1, 1);
    func_021BE4B4(expObj, 0, 0, 1);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        anime = func_021BE674(expObj, 0, 0, i);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, 0, i, 0);
        anime = func_021BE674(expObj, 0, 1, i);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, 1, i, 0);
    }
}

void func_021F3840(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;

    expObj = func_02188D2C(fieldMap);
    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}

void func_021F385C(struct FieldMap *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}

/* Set up the gimmick: work, the three models, and the list of map objects to swap. */
void func_021F3868(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;
    FldExpObjAnime *anime;
    int heapId;
    SpPokeGimmickWork *work;

    expObj = func_02188D2C(fieldMap);
    heapId = (func_02188C84(fieldMap) & 0x7FFF) | 0x8000;
    func_02189764(fieldMap, 1, (u16)heapId, 0x28);
    work = func_021897BC(fieldMap, 1);
    work->swapObjectIds = func_02030734((u16)heapId, 4, 1, d_021F4080, 0x1D1);
    func_021BE310(expObj, &d_021F3E74, 0);
    func_021BE4B4(expObj, 0, 1, 1);
    func_021BE4B4(expObj, 0, 0, 1);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        anime = func_021BE674(expObj, 0, 0, i);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, 0, i, 0);
        anime = func_021BE674(expObj, 0, 1, i);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, 1, i, 0);
    }
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        anime = func_021BE674(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 1);
        func_021BE700(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i, 0);
    }
}

void func_021F3980(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    SpPokeGimmickWork *work;

    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    func_020307B0(work->swapObjectIds);
    func_021897A0(fieldMap, 1);
    func_021BE418(expObj, 0);
}

void func_021F39AC(struct FieldMap *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}

/*
 * Script command: put the model of one side at from, show it, stop its
 * animations and start the event that moves it to to over frames, along an
 * arc that rises by bump over the middle of the move. Side 0 plays a sound.
 */
struct GameEvent *func_021F39B8(struct GameSystem *gameSystem, int side, VecFx32 *from, const VecFx32 *to,
                                fx32 bump, int frames)
{
    int i;
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    struct GameEvent *event;
    SpPokeGimmickWork *work;
    int model;

    fieldMap = func_0201210C(gameSystem);
    model = 1;
    work = func_021897BC(fieldMap, 1);
    expObj = func_02188D2C(fieldMap);
    if (side == 0) {
        model = 0;
        func_020061E4(0x566);
    }
    *func_021BE480(expObj, 0, model) = *from;
    func_021BE4B4(expObj, 0, (u16)model, 0);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        func_021BE6B0(func_021BE674(expObj, 0, model, i), 1);
        func_021BE700(expObj, 0, model, i, 0);
        func_021BE6CC(expObj, 0, model, i, 0);
    }
    work->moveFrom = *from;
    work->moveTo = *to;
    work->moveFrames = frames;
    work->moveElapsed = 0;
    work->moveBump = bump;
    event = func_020122C0(gameSystem, 0, func_021F3B90, 0);
    work->side = side;
    return event;
}

/* Script command: put the model of one side at pos, show it and start its animations. */
void func_021F3AA0(struct GameSystem *gameSystem, int side, VecFx32 *pos)
{
    int i;
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    int model;

    fieldMap = func_0201210C(gameSystem);
    func_021897BC(fieldMap, 1);
    model = 1;
    expObj = func_02188D2C(fieldMap);
    if (side == 0) {
        model = 0;
        func_020061E4(0x567);
    } else {
        func_020061E4(0x793);
    }
    *func_021BE480(expObj, 0, model) = *pos;
    func_021BE4B4(expObj, 0, (u16)model, 0);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        func_021BE6B0(func_021BE674(expObj, 0, model, i), 0);
        func_021BE700(expObj, 0, model, i, 1);
        func_021BE6CC(expObj, 0, model, i, 0);
    }
}

/* Script command: start the event that waits until the animation of one side is far enough. */
void func_021F3B40(struct GameSystem *gameSystem, int side)
{
    SpPokeGimmickWork *work;

    work = func_021897BC(func_0201210C(gameSystem), 1);
    func_020122C0(gameSystem, 0, func_021F3C6C, 0);
    work->side = side;
}

/* Script command: start the event that waits until the animation of one side has ended. */
void func_021F3B68(struct GameSystem *gameSystem, int side)
{
    SpPokeGimmickWork *work;

    work = func_021897BC(func_0201210C(gameSystem), 1);
    func_020122C0(gameSystem, 0, func_021F3CB8, 0);
    work->side = side;
}

/*
 * Event the move command (func_021F39B8) starts: steps moveElapsed towards
 * moveFrames and interpolates a position between moveFrom and moveTo with a
 * bump of moveBump on the middle axis. Each difference goes through the
 * named temporary delta (the original computes it into r1 and copies it to
 * r0 for muls; inline, it lands in r0 and the function is 6 bytes short).
 * The tail is one if with the return 1 inside it (the inverse early return
 * flips the blo).
 */
int func_021F3B90(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    SpPokeGimmickWork *work;
    int model;
    int elapsed;
    int frames;
    int delta;
    VecFx32 pos;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    model = 1;
    work = func_021897BC(fieldMap, 1);
    if (work->side == 0)
        model = 0;
    work->moveElapsed++;
    elapsed = work->moveElapsed;
    frames = work->moveFrames;
    delta = work->moveTo.x - work->moveFrom.x;
    pos.x = work->moveFrom.x + delta * elapsed / frames;
    delta = work->moveTo.y - work->moveFrom.y;
    pos.y = work->moveFrom.y + delta * elapsed / frames;
    delta = work->moveTo.z - work->moveFrom.z;
    pos.z = work->moveFrom.z + delta * elapsed / frames;
    if (elapsed >= (frames + 1) / 2)
        elapsed = frames - elapsed;
    pos.y += work->moveBump * elapsed / frames;
    *func_021BE480(expObj, 0, model) = pos;
    if (work->moveElapsed >= work->moveFrames) {
        if (work->side == 1)
            func_021BE4B4(expObj, 0, (u16)model, 1);
        return 1;
    }
    return 0;
}

/* Event: ends when the animation of the side has played up to its wait frame. */
int func_021F3C6C(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    int waitFrame;
    int model;
    SpPokeGimmickWork *work;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    model = 1;
    if (work->side == 0) {
        waitFrame = SP_POKE_GIMMICK_SIDE0_WAIT_FRAME;
        model = 0;
    } else {
        waitFrame = SP_POKE_GIMMICK_SIDE1_WAIT_FRAME;
    }
    if (func_021BE6E8(expObj, 0, (u16)model, 0) >= waitFrame) {
        return 1;
    }
    return 0;
}

/* Event: ends when the animation of the side has stopped. */
int func_021F3CB8(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    int model;
    SpPokeGimmickWork *work;

    fieldMap = func_0201210C(func_020124E4(event));
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    model = 1;
    if (work->side == 0) {
        model = 0;
    }
    if (func_021BE6BC(func_021BE674(expObj, 0, (u16)model, 0))) {
        return 1;
    }
    return 0;
}

/*
 * Script command: put the effect model at pos, start its animations and
 * start the event that removes the map object removeObjectId and adds
 * addObjectId when the effect reaches its swap frame.
 */
void func_021F3CFC(struct GameSystem *gameSystem, VecFx32 *pos, u16 removeObjectId, u16 addObjectId)
{
    int i;
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    SpPokeGimmickWork *work;
    u16 *objectIds;

    fieldMap = func_0201210C(gameSystem);
    work = func_021897BC(fieldMap, 1);
    expObj = func_02188D2C(fieldMap);
    objectIds = work->swapObjectIds;
    objectIds[0] = removeObjectId;
    objectIds[1] = addObjectId;
    *func_021BE480(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL) = *pos;
    func_021BE4B4(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, 0);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        func_021BE6B0(func_021BE674(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i), 0);
        func_021BE700(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i, 1);
        func_021BE6CC(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i, 0);
    }
    func_020122C0(gameSystem, 0, func_021F3D9C, 0);
}
