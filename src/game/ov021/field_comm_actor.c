/*
 * file:     field_comm_actor.c
 * unit:     yes
 * function: FIELD_COMM_ACTOR_CTRL_Create, FIELD_COMM_ACTOR_CTRL_Delete, FIELD_COMM_ACTOR_CTRL_AddActor, FIELD_COMM_ACTOR_CTRL_DeleteActor, FIELD_COMM_ACTOR_CTRL_SearchGridPos, FIELD_COMM_ACTOR_CTRL_GetMmdl, FIELD_COMM_ACTOR_DeleteActor, FIELD_COMM_ACTOR_AddMmdl, FIELD_COMM_ACTOR_MoveInit, FIELD_COMM_ACTOR_MoveDelete, FIELD_COMM_ACTOR_Move, FIELD_COMM_ACTOR_SetMoveWork, FIELD_COMM_ACTOR_ConvertDir, FIELD_COMM_ACTOR_CreateSubscreenChangeEvent, FIELD_COMM_ACTOR_SubscreenChangeMain
 * address:  0x02194284
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_wfbc.c at 0x02194284 (lane CL120, __FILE__ anchors).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm  arm9
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   sFieldCommActorFileName 0x021DDA70  data  a4
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_MOVE_IsGridInObjectRect  0x02163C04  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   sCommActorMmdlHeader 0x021D3F68  data  ov021  a4
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetStatusBitAttrGetOff  0x0216DC98  thumb  ov010
 *   FLDMMDL_SetStatusBitZoneDeleteOff  0x0216DB80  thumb  ov010
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 *   FLDMMDL_SetMoveBitSysPauseOff  0x0216DC64  thumb  ov010
 *   FLDMMDL_SetMoveBitAttrEffectOff  0x0216DCCC  thumb  ov010
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   GAME_DATA_SetFieldMenuCursor  0x020129D0  thumb
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 */
#include "../ov010/fldmmdl_types.h"

struct GameEvent;
struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldSubscreen;

#include "../types.h"

/* One actor of a connected player (0xC bytes). */
typedef struct FieldCommActor {
    u32 id;
    u16 isMmdlDeleted;   /* set by the move remove procedure */
    u16 useRunAnime;
    Mmdl *mmdl;
} FieldCommActor;

/* Actor control of the connected players (0xC bytes). */
typedef struct FieldCommActorCtrl {
    u16 actorMax;
    u16 useRunAnime;
    MmdlSys *mmdlSys;
    FieldCommActor *actors;
} FieldCommActorCtrl;

/* Move procedure work of an actor model (0x10 bytes): pointers into the comm player entry. */
typedef struct FieldCommActorMoveWork {
    const u16 *dir;
    const VecFx32 *pos;
    const int *vanish;
    FieldCommActor *actor;
} FieldCommActorMoveWork;

/* Work of the subscreen change event (0x14 bytes). */
typedef struct SubscreenChangeEventWork {
    struct GameEvent *event;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u32 mode;
    u8 seq;
} SubscreenChangeEventWork;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define FLDMMDL_SetDrawStatus FLDMMDL_SetDrawStatus_header
#endif
#include "../ov010/fldmmdl.h"
#ifdef __MWERKS__
#undef FLDMMDL_SetDrawStatus
extern void FLDMMDL_SetDrawStatus(Mmdl *, int);
#endif
#include "../ov010/fldmmdl_move.h"
struct Mmdl;
#include "fieldmap.h"
#include "../arm9/game_event.h"
#include "field_subscreen.h"
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
FieldCommActorCtrl *FIELD_COMM_ACTOR_CTRL_Create(int actorMax, MmdlSys *mmdlSys, int heapId, int useRunAnime);
void FIELD_COMM_ACTOR_CTRL_Delete(FieldCommActorCtrl *ctrl);
void FIELD_COMM_ACTOR_CTRL_AddActor(FieldCommActorCtrl *ctrl, int id, int objCode, const u16 *dir, const VecFx32 *pos, const int *vanish);
void FIELD_COMM_ACTOR_CTRL_DeleteActor(FieldCommActorCtrl *ctrl, u32 id);
int FIELD_COMM_ACTOR_CTRL_SearchGridPos(FieldCommActorCtrl *ctrl, s16 gridX, int gridY, s16 gridZ, int *outId, unsigned *index);
Mmdl *FIELD_COMM_ACTOR_CTRL_GetMmdl(FieldCommActorCtrl *ctrl, u32 id);
void FIELD_COMM_ACTOR_DeleteActor(FieldCommActor *actor);
Mmdl *FIELD_COMM_ACTOR_AddMmdl(FieldCommActorCtrl *ctrl, int objCode, const u16 *dir, const VecFx32 *pos, const int *vanish, FieldCommActor *actor);
void FIELD_COMM_ACTOR_MoveInit(Mmdl *mmdl);
void FIELD_COMM_ACTOR_MoveDelete(Mmdl *mmdl);
void FIELD_COMM_ACTOR_Move(Mmdl *mmdl);
void FIELD_COMM_ACTOR_SetMoveWork(Mmdl *mmdl, const u16 *dir, const VecFx32 *pos, const int *vanish, FieldCommActor *actor);
int FIELD_COMM_ACTOR_ConvertDir(int dir);
struct GameEvent *FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 mode);
int FIELD_COMM_ACTOR_SubscreenChangeMain(struct GameEvent *event, int *seq, void *work);
extern char sFieldCommActorFileName[];
extern MmdlHeader sCommActorMmdlHeader;

FieldCommActorCtrl *FIELD_COMM_ACTOR_CTRL_Create(int actorMax, MmdlSys *mmdlSys, int heapId, int useRunAnime)
{
    int size = sizeof(FieldCommActor);
    FieldCommActorCtrl *ctrl = GFL_HEAP_Alloc(heapId, size, 1, sFieldCommActorFileName, 0x5d);
    ctrl->actorMax = actorMax;
    ctrl->useRunAnime = useRunAnime;
    ctrl->mmdlSys = mmdlSys;
    ctrl->actors = GFL_HEAP_Alloc(heapId, size * actorMax, 1, sFieldCommActorFileName, 0x63);
    return ctrl;
}

void FIELD_COMM_ACTOR_CTRL_Delete(FieldCommActorCtrl *ctrl)
{
    u16 i;
    FieldCommActor *actor;
    i = 0;
    actor = ctrl->actors;
    if (i < ctrl->actorMax) {
        for (; i < ctrl->actorMax; i++) {
            if (actor->mmdl != 0) {
                FIELD_COMM_ACTOR_DeleteActor(actor);
            }
            actor++;
        }
    }
    GFL_HEAP_Free(ctrl->actors);
    GFL_HEAP_Free(ctrl);
}

void FIELD_COMM_ACTOR_CTRL_AddActor(FieldCommActorCtrl *ctrl, int id, int objCode, const u16 *dir, const VecFx32 *pos, const int *vanish)
{
    u16 i;
    FieldCommActor *actor = ctrl->actors;
    FIELD_COMM_ACTOR_ConvertDir(*dir);
    for (i = 0; i < ctrl->actorMax; i++) {
        if (actor->mmdl == 0) {
            actor->mmdl = FIELD_COMM_ACTOR_AddMmdl(ctrl, objCode, dir, pos, vanish, actor);
            actor->id = id;
            actor->useRunAnime = ctrl->useRunAnime;
            return;
        }
        actor++;
    }
}

void FIELD_COMM_ACTOR_CTRL_DeleteActor(FieldCommActorCtrl *ctrl, u32 id)
{
    FieldCommActor *actor;
    u16 i;
    actor = ctrl->actors;
    for (i = 0; i < ctrl->actorMax; i++) {
        if (actor->mmdl != 0 && actor->id == id) {
            FIELD_COMM_ACTOR_DeleteActor(actor);
            return;
        }
        actor++;
    }
}

/*
 * The actor pointer only advances past actors that have a model; the
 * search resumes from *index on the next call.
 */
int FIELD_COMM_ACTOR_CTRL_SearchGridPos(FieldCommActorCtrl *ctrl, s16 gridX, int gridY, s16 gridZ, int *outId, unsigned *index)
{
    unsigned actorMax = ctrl->actorMax;
    FieldCommActor *actor;
    short diff;
    if (*index < actorMax) {
        actor = ctrl->actors + *index;
        do {
            (*index)++;
            if (actor->mmdl != 0) {
                diff = FLDMMDL_GetGridNowY(actor->mmdl) - gridY;
                if (diff < 0)
                    diff = -diff;
                if (diff < 1) {
                    if (FLDMMDL_MOVE_IsGridInObjectRect(actor->mmdl, gridX, gridZ, 1)) {
                        *outId = actor->id;
                        return 1;
                    }
                }
                actor++;
            }
        } while (*index < actorMax);
    }
    return 0;
}

Mmdl *FIELD_COMM_ACTOR_CTRL_GetMmdl(FieldCommActorCtrl *ctrl, u32 id)
{
    u16 i;
    FieldCommActor *actor;
    u16 actorMax;
    actorMax = ctrl->actorMax;
    i = 0;
    actor = ctrl->actors;
    for (; i < actorMax; i++, actor++) {
        if (actor->mmdl != 0 && actor->id == id)
            return actor->mmdl;
    }
    return 0;
}

void FIELD_COMM_ACTOR_DeleteActor(FieldCommActor *actor)
{
    if (actor->isMmdlDeleted == 0) {
        FLDMMDL_DeleteMmdl(actor->mmdl);
    }
    MI_CpuFill8(actor, 0, sizeof(FieldCommActor));
}

Mmdl *FIELD_COMM_ACTOR_AddMmdl(FieldCommActorCtrl *ctrl, int objCode, const u16 *dir, const VecFx32 *pos, const int *vanish, FieldCommActor *actor)
{
    MmdlSys *mmdlSys = ctrl->mmdlSys;
    MmdlHeader header = sCommActorMmdlHeader;
    Mmdl *mmdl;
    header.objCode = objCode;
    mmdl = FLDMMDL_AddMmdl(mmdlSys, &header, 0);
    FIELD_COMM_ACTOR_SetMoveWork(mmdl, dir, pos, vanish, actor);
    FLDMMDL_InitPosition(mmdl, pos, FIELD_COMM_ACTOR_ConvertDir(*dir));
    FLDMMDL_SetStatusBitHeightGetOff(mmdl, 1);
    FLDMMDL_SetStatusBitAttrGetOff(mmdl, 1);
    FLDMMDL_SetStatusBitZoneDeleteOff(mmdl, 1);
    FLDMMDL_SetStatusBitFellowHit(mmdl, 0);
    FLDMMDL_SetMoveBitSysPauseOff(mmdl, 1);
    FLDMMDL_SetMoveBitAttrEffectOff(mmdl, 1);
    return mmdl;
}

void FIELD_COMM_ACTOR_MoveInit(Mmdl *mmdl)
{
    FLDMMDL_InitMoveProcWork(mmdl, sizeof(FieldCommActorMoveWork));
}

void FIELD_COMM_ACTOR_MoveDelete(Mmdl *mmdl)
{
    ((FieldCommActorMoveWork *)FLDMMDL_GetMoveProcWork(mmdl))->actor->isMmdlDeleted = 1;
}

void FIELD_COMM_ACTOR_Move(Mmdl *mmdl)
{
    VecFx32 nowPos;
    FieldCommActorMoveWork *work;
    int drawStatus;
    const VecFx32 *pos;
    int objCode;
    int diff;
    work = FLDMMDL_GetMoveProcWork(mmdl);
    FLDMMDL_SetDirDispCheckPause(mmdl, FIELD_COMM_ACTOR_ConvertDir(*work->dir));
    drawStatus = 0;
    FLDMMDL_GetPos(mmdl, &nowPos);
    pos = work->pos;
    if (nowPos.x != pos->x || nowPos.y != pos->y || nowPos.z != pos->z) {
        FLDMMDL_InitPosition(mmdl, work->pos, FLDMMDL_GetDirDisp(mmdl));
        drawStatus = 3;
        if (work->actor->useRunAnime != 0) {
            objCode = FLDMMDL_GetObjCode(mmdl);
            if (objCode == 1 || objCode == 4) {
                int distance = 0;
                pos = work->pos;
                diff = nowPos.x - pos->x;
                if (diff < 0)
                    diff = -diff;
                distance += diff;
                diff = nowPos.z - pos->z;
                if (diff < 0)
                    diff = -diff;
                distance += diff;
                if (distance >= 0x4000)
                    drawStatus = 10;
            }
        }
    }
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    if (work->vanish != 0)
    {
        int vanish = 0;
        if (*work->vanish == 1)
            vanish = 1;
        FLDMMDL_SetStatusBitVanish(mmdl, vanish);
    }
}

void FIELD_COMM_ACTOR_SetMoveWork(Mmdl *mmdl, const u16 *dir, const VecFx32 *pos, const int *vanish, FieldCommActor *actor)
{
    FieldCommActorMoveWork *work;
    work = FLDMMDL_GetMoveProcWork(mmdl);
    work->dir = dir;
    work->pos = pos;
    work->vanish = vanish;
    work->actor = actor;
}

/* Returns the direction unchanged (a conversion that does nothing in this version). */
int FIELD_COMM_ACTOR_ConvertDir(int dir)
{
    return dir;
}

struct GameEvent *FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 mode)
{
    struct GameEvent *event;
    SubscreenChangeEventWork *work;
    FIELDMAP_GetSubscreen(fieldMap);
    event = GAME_EVENT_Create(gameSystem, 0, FIELD_COMM_ACTOR_SubscreenChangeMain, sizeof(SubscreenChangeEventWork));
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(SubscreenChangeEventWork));
    work->gameSystem = gameSystem;
    work->event = event;
    work->fieldMap = fieldMap;
    work->mode = mode;
    return event;
}

int FIELD_COMM_ACTOR_SubscreenChangeMain(struct GameEvent *event, int *seq, void *work)
{
    SubscreenChangeEventWork *evWork = work;
    MmdlSys *mmdlSys;
    struct GameData *gameData;
    switch (evWork->seq) {
    case 0:
        if (FIELD_SUBSCREEN_IsIdle(FIELDMAP_GetSubscreen(evWork->fieldMap)) == 1) {
            mmdlSys = FIELDMAP_GetMmdlSys(evWork->fieldMap);
            gameData = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(event));
            FLDMMDL_SysPauseMove(mmdlSys);
            GAME_DATA_SetFieldMenuCursor(gameData, 1);
            FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(evWork->fieldMap), evWork->mode);
            evWork->seq++;
        }
        break;
    case 1:
        if (FIELD_SUBSCREEN_IsIdle(FIELDMAP_GetSubscreen(evWork->fieldMap)) == 1) {
            GAME_DATA_SetSubscreenType(GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(event)), evWork->mode & 0xff);
            evWork->seq++;
        }
        break;
    case 2:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(evWork->fieldMap));
        return 1;
    }
    return 0;
}
