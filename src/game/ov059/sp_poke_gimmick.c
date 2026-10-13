/*
 * file:     sp_poke_gimmick.c
 * unit:     yes
 * function: GIMMICK57_LoadModelScene, SP_POKE_GIMMICK_ExitPairA, SP_POKE_GIMMICK_UpdatePairA, SP_POKE_GIMMICK_InitPairB, SP_POKE_GIMMICK_ExitPairB, SP_POKE_GIMMICK_UpdatePairB, SP_POKE_GIMMICK_Init, SP_POKE_GIMMICK_Exit, SP_POKE_GIMMICK_Update, SP_POKE_GIMMICK_StartMove, SP_POKE_GIMMICK_ShowAndPlay, SP_POKE_GIMMICK_StartWaitAnimeProgress, SP_POKE_GIMMICK_StartWaitAnimeEnd, SP_POKE_GIMMICK_MoveEventMain, SP_POKE_GIMMICK_WaitAnimeProgressEventMain, SP_POKE_GIMMICK_WaitAnimeEndEventMain, SP_POKE_GIMMICK_StartSwapNpc
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
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   sSpPokeGimmickPairASetup  0x021F3E94  data  a4
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   sSpPokeGimmickPairBSetup     0x021F3E84  data  a4
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   FLD_EXP_OBJ_AddUnit  0x021BE310  thumb  ov021
 *   sSpPokeGimmickFileName     0x021F4080  data  ov059  a1
 *   sSpPokeGimmickSetup     0x021F3E74  data  a4
 *   func_020307B0  0x020307B0  arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   SP_POKE_GIMMICK_SwapNpcEventMain  0x021F3D9C  thumb  ov059
 */
#include "../ov021/fld_exp_obj_types.h"
#include "sp_poke_gimmick_types.h"

extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int id, int heapId, int size);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int id);
extern void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *expObj, const G3dUtilSetup *setup, int unitIndex);
extern void FLD_EXP_OBJ_AddUnit(FldExpObjCnt *expObj, const G3dUtilSetup *setup, int unitIndex);
extern void FLD_EXP_OBJ_RemoveUnit(FldExpObjCnt *expObj, u16 unitIndex);
extern void FLD_EXP_OBJ_SetModelHidden(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int hidden);
extern void FLD_EXP_OBJ_SetAnimeLoop(FldExpObjAnime *anime, int loop);
extern void FLD_EXP_OBJ_SetAnimePaused(FldExpObjAnime *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex, int enable);
extern void FLD_EXP_OBJ_UpdateAnimes(FldExpObjCnt *expObj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 func_020307B0(void *memory);
extern void func_020061E4(u32 seId);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex);
extern void FLD_EXP_OBJ_SetAnimeFrame(FldExpObjCnt *expObj, int unitIndex, u16 modelIndex, u16 animeIndex, int frame);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent,
                                       GameEventFunc func, u32 workSize);

void GIMMICK57_LoadModelScene(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_ExitPairA(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_UpdatePairA(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_InitPairB(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_ExitPairB(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_UpdatePairB(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_Init(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_Exit(struct FieldMap *fieldMap);
void SP_POKE_GIMMICK_Update(struct FieldMap *fieldMap);
struct GameEvent *SP_POKE_GIMMICK_StartMove(struct GameSystem *gameSystem, int side, VecFx32 *from, const VecFx32 *to,
                                fx32 bump, int frames);
void SP_POKE_GIMMICK_ShowAndPlay(struct GameSystem *gameSystem, int side, VecFx32 *pos);
void SP_POKE_GIMMICK_StartWaitAnimeProgress(struct GameSystem *gameSystem, int side);
void SP_POKE_GIMMICK_StartWaitAnimeEnd(struct GameSystem *gameSystem, int side);
int SP_POKE_GIMMICK_MoveEventMain(struct GameEvent *event, int *seq, void *eventWork);
int SP_POKE_GIMMICK_WaitAnimeProgressEventMain(struct GameEvent *event, int *seq, void *eventWork);
int SP_POKE_GIMMICK_WaitAnimeEndEventMain(struct GameEvent *event, int *seq, void *eventWork);
void SP_POKE_GIMMICK_StartSwapNpc(struct GameSystem *gameSystem, VecFx32 *pos, u16 removeObjectId, u16 addObjectId);

extern G3dUtilSetup sSpPokeGimmickPairASetup;
extern G3dUtilSetup sSpPokeGimmickPairBSetup;
extern G3dUtilSetup sSpPokeGimmickSetup;
extern char sSpPokeGimmickFileName[];

/* First two-model variant: add the unit, hide both models and stop all their animations. */
void GIMMICK57_LoadModelScene(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;
    FldExpObjAnime *anime;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), 0x28);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &sSpPokeGimmickPairASetup, 0);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 1, 1);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0, 1);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, i, 0);
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 1, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 1, i, 0);
    }
}

void SP_POKE_GIMMICK_ExitPairA(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void SP_POKE_GIMMICK_UpdatePairA(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Second two-model variant, same setup with its own unit. */
void SP_POKE_GIMMICK_InitPairB(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;
    FldExpObjAnime *anime;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), 0x28);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &sSpPokeGimmickPairBSetup, 0);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 1, 1);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0, 1);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, i, 0);
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 1, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 1, i, 0);
    }
}

void SP_POKE_GIMMICK_ExitPairB(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void SP_POKE_GIMMICK_UpdatePairB(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* Set up the gimmick: work, the three models, and the list of map objects to swap. */
void SP_POKE_GIMMICK_Init(struct FieldMap *fieldMap)
{
    int i;
    FldExpObjCnt *expObj;
    FldExpObjAnime *anime;
    int heapId;
    SpPokeGimmickWork *work;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    heapId = (FIELDMAP_GetHeapId(fieldMap) & 0x7FFF) | 0x8000;
    FIELDMAP_AllocCommonWork(fieldMap, 1, (u16)heapId, 0x28);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->swapObjectIds = func_02030734((u16)heapId, 4, 1, sSpPokeGimmickFileName, 0x1D1);
    FLD_EXP_OBJ_AddUnit(expObj, &sSpPokeGimmickSetup, 0);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 1, 1);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0, 1);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, i, 0);
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 1, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 1, i, 0);
    }
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i, 0);
    }
}

void SP_POKE_GIMMICK_Exit(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    SpPokeGimmickWork *work;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    func_020307B0(work->swapObjectIds);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void SP_POKE_GIMMICK_Update(struct FieldMap *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/*
 * Script command: put the model of one side at from, show it, stop its
 * animations and start the event that moves it to to over frames, along an
 * arc that rises by bump over the middle of the move. Side 0 plays a sound.
 */
struct GameEvent *SP_POKE_GIMMICK_StartMove(struct GameSystem *gameSystem, int side, VecFx32 *from, const VecFx32 *to,
                                fx32 bump, int frames)
{
    int i;
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    struct GameEvent *event;
    SpPokeGimmickWork *work;
    int model;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    model = 1;
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    if (side == 0) {
        model = 0;
        func_020061E4(0x566);
    }
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, model) = *from;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)model, 0);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, model, i), 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, model, i, 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, model, i, 0);
    }
    work->moveFrom = *from;
    work->moveTo = *to;
    work->moveFrames = frames;
    work->moveElapsed = 0;
    work->moveBump = bump;
    event = func_020122C0(gameSystem, 0, SP_POKE_GIMMICK_MoveEventMain, 0);
    work->side = side;
    return event;
}

/* Script command: put the model of one side at pos, show it and start its animations. */
void SP_POKE_GIMMICK_ShowAndPlay(struct GameSystem *gameSystem, int side, VecFx32 *pos)
{
    int i;
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    int model;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    model = 1;
    expObj = FIELDMAP_GetExpObj(fieldMap);
    if (side == 0) {
        model = 0;
        func_020061E4(0x567);
    } else {
        func_020061E4(0x793);
    }
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, model) = *pos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)model, 0);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, model, i), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, model, i, 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, model, i, 0);
    }
}

/* Script command: start the event that waits until the animation of one side is far enough. */
void SP_POKE_GIMMICK_StartWaitAnimeProgress(struct GameSystem *gameSystem, int side)
{
    SpPokeGimmickWork *work;

    work = FIELDMAP_GetCommonWork(GAMESYSTEM_GetFieldMap(gameSystem), 1);
    func_020122C0(gameSystem, 0, SP_POKE_GIMMICK_WaitAnimeProgressEventMain, 0);
    work->side = side;
}

/* Script command: start the event that waits until the animation of one side has ended. */
void SP_POKE_GIMMICK_StartWaitAnimeEnd(struct GameSystem *gameSystem, int side)
{
    SpPokeGimmickWork *work;

    work = FIELDMAP_GetCommonWork(GAMESYSTEM_GetFieldMap(gameSystem), 1);
    func_020122C0(gameSystem, 0, SP_POKE_GIMMICK_WaitAnimeEndEventMain, 0);
    work->side = side;
}

/*
 * Event the move command (SP_POKE_GIMMICK_StartMove) starts: steps moveElapsed towards
 * moveFrames and interpolates a position between moveFrom and moveTo with a
 * bump of moveBump on the middle axis. Each difference goes through the
 * named temporary delta (the original computes it into r1 and copies it to
 * r0 for muls; inline, it lands in r0 and the function is 6 bytes short).
 * The tail is one if with the return 1 inside it (the inverse early return
 * flips the blo).
 */
int SP_POKE_GIMMICK_MoveEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    SpPokeGimmickWork *work;
    int model;
    int elapsed;
    int frames;
    int delta;
    VecFx32 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    model = 1;
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
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
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, model) = pos;
    if (work->moveElapsed >= work->moveFrames) {
        if (work->side == 1)
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)model, 1);
        return 1;
    }
    return 0;
}

/* Event: ends when the animation of the side has played up to its wait frame. */
int SP_POKE_GIMMICK_WaitAnimeProgressEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    int waitFrame;
    int model;
    SpPokeGimmickWork *work;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    model = 1;
    if (work->side == 0) {
        waitFrame = SP_POKE_GIMMICK_SIDE0_WAIT_FRAME;
        model = 0;
    } else {
        waitFrame = SP_POKE_GIMMICK_SIDE1_WAIT_FRAME;
    }
    if (FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, (u16)model, 0) >= waitFrame) {
        return 1;
    }
    return 0;
}

/* Event: ends when the animation of the side has stopped. */
int SP_POKE_GIMMICK_WaitAnimeEndEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    int model;
    SpPokeGimmickWork *work;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    model = 1;
    if (work->side == 0) {
        model = 0;
    }
    if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)model, 0))) {
        return 1;
    }
    return 0;
}

/*
 * Script command: put the effect model at pos, start its animations and
 * start the event that removes the map object removeObjectId and adds
 * addObjectId when the effect reaches its swap frame.
 */
void SP_POKE_GIMMICK_StartSwapNpc(struct GameSystem *gameSystem, VecFx32 *pos, u16 removeObjectId, u16 addObjectId)
{
    int i;
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    SpPokeGimmickWork *work;
    u16 *objectIds;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    objectIds = work->swapObjectIds;
    objectIds[0] = removeObjectId;
    objectIds[1] = addObjectId;
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL) = *pos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, 0);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i, 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i, 0);
    }
    func_020122C0(gameSystem, 0, SP_POKE_GIMMICK_SwapNpcEventMain, 0);
}
