/*
 * file:     sp_poke_gimmick.c
 * unit:     yes
 * function: SP_POKE_GIMMICK_LoadModelScene, SP_POKE_GIMMICK_ExitPairA, SP_POKE_GIMMICK_UpdatePairA, SP_POKE_GIMMICK_InitPairB, SP_POKE_GIMMICK_ExitPairB, SP_POKE_GIMMICK_UpdatePairB, SP_POKE_GIMMICK_Init, SP_POKE_GIMMICK_Exit, SP_POKE_GIMMICK_Update, SP_POKE_GIMMICK_StartMove, SP_POKE_GIMMICK_ShowAndPlay, SP_POKE_GIMMICK_StartWaitAnimeProgress, SP_POKE_GIMMICK_StartWaitAnimeEnd, SP_POKE_GIMMICK_MoveEventMain, SP_POKE_GIMMICK_WaitAnimeProgressEventMain, SP_POKE_GIMMICK_WaitAnimeEndEventMain, SP_POKE_GIMMICK_StartSwapNpc, SP_POKE_GIMMICK_SwapNpcEventMain
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
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FLD_EXP_OBJ_AddUnit  0x021BE310  thumb  ov021
 *   sSpPokeGimmickFileName     0x021F4080  data  ov059  a1
 *   sSpPokeGimmickSetup     0x021F3E74  data  a4
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   SP_POKE_GIMMICK_SwapNpcEventMain  0x021F3D9C  thumb  ov059
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   FLDMMDL_AddMmdlHeaderById  0x0216CEE4  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 */
/* Original prototypes (docs/ORIGINAL_BUGS.tsv): the DS file declares these differently from the ARM9 headers. */
#include "../ov021/fld_exp_obj_types.h"
#include "sp_poke_gimmick_types.h"
#include "../ov021/fld_exp_obj.h"

struct G3dUtilSetup;
struct FldExpObjCnt;
#include "../ov021/fld_exp_obj.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gfl_use.h"
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);

void SP_POKE_GIMMICK_LoadModelScene(struct FieldMap *fieldMap);
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
struct GameEvent *SP_POKE_GIMMICK_StartWaitAnimeProgress(struct GameSystem *gameSystem, int side);
struct GameEvent *SP_POKE_GIMMICK_StartWaitAnimeEnd(struct GameSystem *gameSystem, int side);
int SP_POKE_GIMMICK_MoveEventMain(struct GameEvent *event, int *seq, void *eventWork);
int SP_POKE_GIMMICK_WaitAnimeProgressEventMain(struct GameEvent *event, int *seq, void *eventWork);
int SP_POKE_GIMMICK_WaitAnimeEndEventMain(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *SP_POKE_GIMMICK_StartSwapNpc(struct GameSystem *gameSystem, VecFx32 *pos, u16 removeObjectId, u16 addObjectId);

extern G3dUtilSetup sSpPokeGimmickPairASetup;
extern G3dUtilSetup sSpPokeGimmickPairBSetup;
extern G3dUtilSetup sSpPokeGimmickSetup;
extern char sSpPokeGimmickFileName[];
struct MmdlSys;
struct EventData;
struct Mmdl;
struct NpcHeader;
struct PlayerWork;
#include "../ov010/fldmmdl.h"
#include "../arm9/game_data.h"
struct EventDataSystem;
#include "../ov010/eventdata_system.h"
#include "../arm9/game_event.h"
#include "../arm9/gamesystem.h"
#include "../ov021/fieldmap.h"
struct MmdlHeader;

/* First two-model variant: add the unit, hide both models and stop all their animations. */
void SP_POKE_GIMMICK_LoadModelScene(struct FieldMap *fieldMap)
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
    work->swapObjectIds = GFL_HEAP_Alloc((u16)heapId, 4, 1, sSpPokeGimmickFileName, 0x1D1);
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
    GFL_HEAP_Free(work->swapObjectIds);
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
        GFL_USE_PlaySeDefaultVolume(0x566);
    }
    *((VecFx32 *)FLD_EXP_OBJ_GetModelStatus(expObj, 0, model)) = *from;
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
    event = GAME_EVENT_Create(gameSystem, 0, SP_POKE_GIMMICK_MoveEventMain, 0);
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
        GFL_USE_PlaySeDefaultVolume(0x567);
    } else {
        GFL_USE_PlaySeDefaultVolume(0x793);
    }
    *((VecFx32 *)FLD_EXP_OBJ_GetModelStatus(expObj, 0, model)) = *pos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)model, 0);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, model, i), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, model, i, 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, model, i, 0);
    }
}

/* Script command: start the event that waits until the animation of one side is far enough. */
struct GameEvent *SP_POKE_GIMMICK_StartWaitAnimeProgress(struct GameSystem *gameSystem, int side)
{
    SpPokeGimmickWork *work;
    struct GameEvent *event;

    work = FIELDMAP_GetCommonWork(GAMESYSTEM_GetFieldMap(gameSystem), 1);
    event = GAME_EVENT_Create(gameSystem, 0, SP_POKE_GIMMICK_WaitAnimeProgressEventMain, 0);
    work->side = side;
    return event;
}

/* Script command: start the event that waits until the animation of one side has ended. */
struct GameEvent *SP_POKE_GIMMICK_StartWaitAnimeEnd(struct GameSystem *gameSystem, int side)
{
    SpPokeGimmickWork *work;
    struct GameEvent *event;

    work = FIELDMAP_GetCommonWork(GAMESYSTEM_GetFieldMap(gameSystem), 1);
    event = GAME_EVENT_Create(gameSystem, 0, SP_POKE_GIMMICK_WaitAnimeEndEventMain, 0);
    work->side = side;
    return event;
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

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
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
    *((VecFx32 *)FLD_EXP_OBJ_GetModelStatus(expObj, 0, model)) = pos;
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

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
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

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
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
struct GameEvent *SP_POKE_GIMMICK_StartSwapNpc(struct GameSystem *gameSystem, VecFx32 *pos, u16 removeObjectId, u16 addObjectId)
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
    *((VecFx32 *)FLD_EXP_OBJ_GetModelStatus(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL)) = *pos;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, 0);
    for (i = 0; i < SP_POKE_GIMMICK_ANIME_COUNT; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i, 1);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, i, 0);
    }
    return GAME_EVENT_Create(gameSystem, 0, SP_POKE_GIMMICK_SwapNpcEventMain, 0);
}

/*
 * Event: when the effect model reaches its swap frame, remove the map object
 * with the first stored id and add the one with the second id from the NPC
 * headers of the zone. Ends when the effect animation has stopped.
 */
int SP_POKE_GIMMICK_SwapNpcEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    SpPokeGimmickWork *work;
    u16 removeObjectId;
    u16 addObjectId;
    struct MmdlSys *mmdlSys;
    struct GameData *gameData;
    struct EventData *eventData;
    u16 npcCount;
    u32 zoneId;
    void *eventFlagWork;
    struct Mmdl *mmdl;
    int result;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    if (FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, 0) == SP_POKE_GIMMICK_SWAP_FRAME) {
        removeObjectId = work->swapObjectIds[0];
        addObjectId = work->swapObjectIds[1];
        mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
        FLDMMDL_DeleteMmdl(FLDMMDL_SysSearchObjId(mmdlSys, removeObjectId));
        gameData = GAMESYSTEM_GetGameData(gameSystem);
        eventData = GAME_DATA_GetEventData(gameData);
        npcCount = EVENTDATA_SYSTEM_GetNpcCount((struct EventDataSystem *)eventData);
        zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
        if (npcCount != 0) {
            eventFlagWork = GAME_DATA_GetEventWork(gameData);
            mmdl = FLDMMDL_AddMmdlHeaderById(mmdlSys, (struct MmdlHeader *)(void *)EVENTDATA_SYSTEM_GetNpcHeaders((struct EventDataSystem *)eventData), zoneId, npcCount, (void *)eventFlagWork, addObjectId);
            if (mmdl != 0)
                FLDMMDL_OnMoveBitMovePause(mmdl);
        }
    }
    result = 0;
    if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, 0)) != 0)
        result = 1;
    return result;
}
