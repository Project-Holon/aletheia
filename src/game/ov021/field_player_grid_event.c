/*
 * file:     field_player_grid_event.c
 * unit:     yes
 * function: FIELD_PLAYER_GRID_EVENT_TryPushBoulder, FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags, FIELD_PLAYER_GRID_EVENT_GetHoleCoverage, FIELD_PLAYER_GRID_EVENT_StartBoulderDrop, FIELD_PLAYER_GRID_EVENT_CreateBoulderDropEvent, FIELD_PLAYER_GRID_EVENT_BoulderDropEvent, FIELD_PLAYER_GRID_EVENT_CreateHopTask, FIELD_PLAYER_GRID_EVENT_IsHopDone, FIELD_PLAYER_GRID_EVENT_DeleteHopTask, FIELD_PLAYER_GRID_EVENT_HopTask, FIELD_PLAYER_GRID_EVENT_CreateJumpTask, FIELD_PLAYER_GRID_EVENT_IsJumpDone, FIELD_PLAYER_GRID_EVENT_DeleteJumpTask, FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset, FIELD_PLAYER_GRID_EVENT_JumpUpStart, FIELD_PLAYER_GRID_EVENT_JumpUpApproach, FIELD_PLAYER_GRID_EVENT_JumpUpRise, FIELD_PLAYER_GRID_EVENT_JumpUpArc, FIELD_PLAYER_GRID_EVENT_JumpUpLand, FIELD_PLAYER_GRID_EVENT_JumpUpWaitEffect, FIELD_PLAYER_GRID_EVENT_UpdateJumpDown, FIELD_PLAYER_GRID_EVENT_RunStateTable, FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr
 * address:  0x021C0CA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_player_grid_event.c, fld3d_ci.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_CheckEndAcmd 0x0216D454 thumb ov010
 *   FLDMMDL_EndAcmd 0x0216D480 thumb ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_PLAYER_GRID_GetCore  0x021A5728  thumb  ov021
 *   FIELD_PLAYER_GRID_GetMmdl  0x021A572C  thumb  ov021
 *   FIELD_PLAYER_CORE_ChooseMoveDirFromKeys  0x021A3AB8  thumb  ov021
 *   FIELD_PLAYER_GRID_CheckCoreAction  0x021A44BC  thumb  ov021
 *   FIELD_PLAYER_GRID_GetDirChangeKind  0x021A448C  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_GetSizeWidth  0x0216D91C  thumb  ov010
 *   FLDMMDL_GetSizeDepth  0x0216D924  thumb  ov010
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   MAP_ATTR_IsHole  0x021AB2DC  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr  0x021C19B4  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_IsMovedPosObjCode  0x0216E5FC  thumb  ov010
 *   FIELD_PLAYER_CORE_GetFieldMap  0x021A395C  thumb  ov021
 *   FLDMMDL_MOVE_HitCheckMoveDir  0x021639C0  thumb  ov010
 *   FIELD_PLAYER_CORE_GetGameSystem  0x021A3990  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_StopTurnOrBlocked  0x021A5408  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_SetDrawOffsetOutside  0x0216D8E0  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FLDMMDL_StoreMovedPos  0x0216E57C  thumb  ov010
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gFileFieldPlayerGridEvent     0x021DE3AC  data  ov021  a4
 *   FIELD_PLAYER_GetFieldMap  0x021A3068  thumb  ov021
 *   FIELD_PLAYER_GetGrid  0x021A36E0  thumb  ov021
 *   MAP_ATTR_IsLongHopEdge  0x021AB2E8  thumb  ov021
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   TCB_AddTask  0x02030DA8  arm
 *   TCBL_IsDeletePending  0x02030EE8  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FLDEFF_NAMIPOKE_Start  0x021ACB38  thumb  ov021
 *   FIELD_PLAYER_SetRideEffect  0x021A2F8C  thumb  ov021
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_IsSpotAt  0x021AA900  thumb  ov021
 *   EFFECT_ENCOUNT_SetEffectFlag  0x021AAB1C  thumb  ov021
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetFollowMode  0x021ACBB8  thumb  ov021
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 *   FIELD_PLAYER_SetGridHopLanded  0x021A35A0  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_RunStateTable  0x021C1988  thumb  ov021
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   FLDEFF_NAMIPOKE_SPLASH_StartOnEffect  0x021AD564  thumb  ov021
 *   FIELDMAP_TCB_CAMERA_ZOOM_Create  0x021C6B18  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDEFF_NAMIPOKE_SPLASH_IsFinished  0x021AD5CC  thumb  ov021
 *   FIELD_EFFECT_FreeResource  0x021ABE64  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_UpdateJumpDown  0x021C16AC  thumb  ov021
 *   d_021DA128     0x021DA128  data  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 */
#include "../ov010/fldmmdl_types.h"
#include "fld3d_ci_types.h"

#include "../types.h"

typedef struct FieldPlayer FieldPlayer;

typedef struct FieldPlayerCore FieldPlayerCore;

typedef struct FieldPlayerAnim FieldPlayerAnim;

typedef struct FieldMap FieldMap;

typedef struct FieldG3dMapper G3dMapper;

typedef struct FieldEffectSys FieldEffectSys;

typedef struct EncountSys EncountSys;

typedef struct GameSystem GameSystem;

typedef struct GameEvent GameEvent;

typedef struct TcbSystem TcblSys;

struct TcbSystem;
struct TcbTask;
struct Mmdl;
struct FieldEncount;
struct FieldPlayerGrid;
struct FieldEffectObj;
struct MmdlSys;
struct TcbSystem;
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/tcb_list.h"
#include "field_player_core.h"
#include "fieldmap.h"
#include "../arm9/gfl_use.h"
extern GameEvent *GAME_EVENT_Create(GameSystem *gameSystem, GameEvent *parent, int (*func)(), u32 workSize);
extern void *GAME_EVENT_GetWork(GameEvent *event);
#include "../arm9/mi_memory.h"
#include "../ov010/fldmmdl_poslog.h"
#include "fldmmdl_acmd.h"
#include "effect_encount.h"
#include "map_attr.h"
#include "field_effect.h"
#include "fieldmap_tcb_camera_zoom.h"

/* Event work of the boulder drop (0x24 bytes). */
typedef struct BoulderDropWork {
    FieldPlayer *player;
    u16 dir;
    u16 fillsHole;       /* 1 when the boulder covers the whole hole */
    s16 frame;
    u8 pad0A[2];
    int targetY;         /* height the boulder sinks to */
    VecFx32 drawOffset;  /* wobble of the boulder while it sinks; y moves */
    Mmdl *boulder;
    Mmdl *playerMmdl;
} BoulderDropWork;

/* Task work of the hop (0x18 bytes). */
typedef struct HopWork {
    u16 state;
    s16 frame;
    u16 done;
    u16 startDir;
    u16 isLong;          /* 1: moves two tiles instead of one */
    u8 pad0A[2];
    FieldMap *fieldMap;
    FieldPlayer *player;
    GameSystem *gameSystem;
} HopWork;

/* Task work of the jump up and jump down (0x4C bytes). */
typedef struct JumpWork {
    u16 targetHigher;    /* 1 when the landing tile is higher */
    s16 state;
    u16 dir;
    u16 done;
    u16 frame;
    u8 pad0A[6];
    int gravity;
    u8 pad14[4];
    VecFx32 drawOffset;
    VecFx32 target;      /* landing position */
    int stepX;
    int velocityY;
    int stepZ;
    FieldPlayer *player;
    FieldMap *fieldMap;
    GameSystem *gameSystem;
    u32 effectHandle;
} JumpWork;







extern void *TCBL_IsDeletePending(struct TcbTask *task);



#ifdef __MWERKS__
#define FLDMMDL_SetAcmd FLDMMDL_SetAcmd_header
#include "../ov010/fldmmdl.h"
#include "../ov010/fldmmdl_move.h"
#undef FLDMMDL_SetAcmd
void FLDMMDL_SetAcmd(Mmdl *mmdl, u32 acmd); /* original prototype: the definition takes u16 */
#else
#include "../ov010/fldmmdl.h"
#include "../ov010/fldmmdl_move.h"
#endif



























extern void FIELD_PLAYER_StartFormChange(FieldPlayer *player, u32 value);

extern int FIELD_PLAYER_StepFormChange(FieldPlayer *player);

extern void FIELD_PLAYER_SetRideEffect(FieldPlayer *player, u32 value);

extern FieldPlayerAnim *FIELD_PLAYER_GetRideEffect(FieldPlayer *player);

extern FieldMap *FIELD_PLAYER_GetFieldMap(FieldPlayer *player);

extern Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *player);

extern void FIELD_PLAYER_SetGridHopLanded(FieldPlayer *player, int value);

extern struct FieldPlayerGrid *FIELD_PLAYER_GetGrid(FieldPlayer *player);





extern int FIELD_PLAYER_GRID_GetDirChangeKind(struct FieldPlayerGrid *grid, s32 dir);

extern int FIELD_PLAYER_GRID_CheckCoreAction(FieldPlayer *player, int dir);

extern int FIELD_PLAYER_GRID_StopTurnOrBlocked(struct FieldPlayerGrid *grid);

extern FieldPlayerCore *FIELD_PLAYER_GRID_GetCore(FieldPlayer *player);

extern void *FIELD_PLAYER_GRID_GetMmdl(FieldPlayer *player);











extern u32 FLDEFF_NAMIPOKE_Start(FieldEffectSys *effects, u32 dir, VecFx32 *pos, Mmdl *mmdl, int value);

extern void FLDEFF_NAMIPOKE_SetFollowMode(FieldPlayerAnim *anim, u8 value);

extern u32 FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FieldEffectSys *effects, u32 kind, FieldPlayerAnim *anim);

extern int FLDEFF_NAMIPOKE_SPLASH_IsFinished(struct FieldEffectObj *effect);

extern void FIELD_PLAYER_GRID_EVENT_RunStateTable(void *work, u16 *state);

extern u32 FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr(u8 *work, u32 dir);


extern u8 gFileFieldPlayerGridEvent;

int FIELD_PLAYER_GRID_EVENT_TryPushBoulder(FieldPlayer *player, int unused, int keyDir, int flags);

int FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags(FieldPlayer *player, u16 dir, u32 flags);

int FIELD_PLAYER_GRID_EVENT_GetHoleCoverage(Mmdl *boulder, u32 dir, G3dMapper *map);

int FIELD_PLAYER_GRID_EVENT_StartBoulderDrop(FieldPlayer *player, u16 dir, int hitResult);

GameEvent *FIELD_PLAYER_GRID_EVENT_CreateBoulderDropEvent(FieldPlayer *player, u32 dir, Mmdl *boulder, u32 fillsHole);

int FIELD_PLAYER_GRID_EVENT_BoulderDropEvent(GameEvent *event, int *seq, BoulderDropWork *work);

void FIELD_PLAYER_GRID_EVENT_CreateHopTask(FieldPlayer *player, u16 dir, u32 attr, u32 heapId);

int FIELD_PLAYER_GRID_EVENT_IsHopDone(struct TcbTask *task);

void FIELD_PLAYER_GRID_EVENT_DeleteHopTask(struct TcbTask *task);

void FIELD_PLAYER_GRID_EVENT_HopTask(struct TcbTask *task, HopWork *work);

void FIELD_PLAYER_GRID_EVENT_CreateJumpTask(FieldPlayer *player, u16 dir, u32 attr, u32 heapId);

int FIELD_PLAYER_GRID_EVENT_IsJumpDone(struct TcbTask *task);

void FIELD_PLAYER_GRID_EVENT_DeleteJumpTask(struct TcbTask *task);

void FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(Mmdl *mmdl, const VecFx32 *offset);

int FIELD_PLAYER_GRID_EVENT_JumpUpStart(JumpWork *work);

int FIELD_PLAYER_GRID_EVENT_JumpUpApproach(JumpWork *work);

int FIELD_PLAYER_GRID_EVENT_JumpUpRise(JumpWork *work);

int FIELD_PLAYER_GRID_EVENT_JumpUpArc(JumpWork *work);

int FIELD_PLAYER_GRID_EVENT_JumpUpLand(JumpWork *work);

int FIELD_PLAYER_GRID_EVENT_JumpUpWaitEffect(JumpWork *work);

void FIELD_PLAYER_GRID_EVENT_UpdateJumpDown(JumpWork *work);

/*
 * Tries to start the boulder drop for the tile the player faces.
 */
int FIELD_PLAYER_GRID_EVENT_TryPushBoulder(FieldPlayer *player, int unused, int keyDir, int flags)
{
    FieldPlayerCore *core;
    u16 dir;
    int result;

    core = FIELD_PLAYER_GRID_GetCore(player);
    FIELD_PLAYER_GRID_GetMmdl(player);
    dir = FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(core, keyDir);
    if (FIELD_PLAYER_GRID_CheckCoreAction(player, dir) == 0)
        return 0;
    result = FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags(player, dir, flags);
    if (result == 0)
        return 0;
    return result;
}

/*
 * Runs the boulder drop check when bit 0 of the flags is set.
 */
int FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags(FieldPlayer *player, u16 dir, u32 flags)
{
    int result = 0;
    int hitResult = FIELD_PLAYER_GRID_GetDirChangeKind((struct FieldPlayerGrid *)player, dir);
    if (flags & 1)
        result = FIELD_PLAYER_GRID_EVENT_StartBoulderDrop(player, dir, hitResult);
    return result;
}

/*
 * Classifies the tiles under the boulder destination: 1 when a tile
 * blocks it, 0 when no tile is a hole, 3 when all tiles are holes and 2
 * when only some are.
 */
int FIELD_PLAYER_GRID_EVENT_GetHoleCoverage(Mmdl *boulder, u32 dir, G3dMapper *map)
{
    VecFx32 pos;
    VecFx32 cur;
    int hasOtherTile;
    int hasHoleTile;
    u8 row;
    u8 depth;
    u8 width;
    u8 col;
    u32 attr;
    u16 id;

    FLDMMDL_GetPos(boulder, &pos);
    FLDMMDL_MOVE_AddDirVector(dir, &pos, 0x10000);
    width = FLDMMDL_GetSizeWidth(boulder);
    depth = FLDMMDL_GetSizeDepth(boulder);
    hasOtherTile = 0;
    hasHoleTile = 0;
    for (row = 0; row < depth; row++, pos.z -= 0x10000) {
        cur = pos;
        for (col = 0; col < width; col++, cur.x += 0x10000) {
            attr = MAP_ATTR_GetAt(map, (const void *)&cur);
            id = MAP_ATTR_GetTerrainId(attr);
            if (MAP_ATTR_IsBlocked(attr)) {
                if (MAP_ATTR_IsHole(id) == 0)
                    return 1;
                hasHoleTile = 1;
            } else {
                hasOtherTile = 1;
            }
        }
    }
    if (hasHoleTile == 1) {
        if (hasOtherTile == 0)
            return 3;
        return 2;
    }
    return 0;
}

int FIELD_PLAYER_GRID_EVENT_StartBoulderDrop(FieldPlayer *player, u16 dir, int hitResult)
{
    Mmdl *boulder;
    u32 coverage;
    u32 moveHit;

    if (hitResult == 1) {
        boulder = (Mmdl *)FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr((u8 *)player, dir);
        if (boulder != 0) {
            if (FLDMMDL_IsMovedPosObjCode(FLDMMDL_GetObjCode(boulder)) == 1) {
                coverage = FIELD_PLAYER_GRID_EVENT_GetHoleCoverage(boulder, dir, FIELDMAP_GetG3dMapper(FIELD_PLAYER_CORE_GetFieldMap(FIELD_PLAYER_GRID_GetCore(player))));
                moveHit = FLDMMDL_MOVE_HitCheckMoveDir(boulder, dir);
                moveHit &= ~1;
                if ((moveHit & 2) && coverage - 2 <= 1)
                    moveHit &= ~2;
                if (moveHit == 0) {
                    int fillsHole = 0;
                    if (coverage == 3)
                        fillsHole = 1;
                    return (sptr)FIELD_PLAYER_GRID_EVENT_CreateBoulderDropEvent(player, dir, boulder, fillsHole);
                }
            }
        }
    }
    return 0;
}

GameEvent *FIELD_PLAYER_GRID_EVENT_CreateBoulderDropEvent(FieldPlayer *player, u32 dir, Mmdl *boulder, u32 fillsHole)
{
    FieldPlayerCore *core;
    GameEvent *event;
    BoulderDropWork *work;

    core = FIELD_PLAYER_GRID_GetCore(player);
    event = GAME_EVENT_Create(FIELD_PLAYER_CORE_GetGameSystem(core), 0, FIELD_PLAYER_GRID_EVENT_BoulderDropEvent, sizeof(BoulderDropWork));
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(BoulderDropWork));
    work->player = player;
    work->dir = dir;
    work->fillsHole = fillsHole;
    work->boulder = boulder;
    work->playerMmdl = FIELD_PLAYER_CORE_GetMmdl(core);
    return event;
}

int FIELD_PLAYER_GRID_EVENT_BoulderDropEvent(GameEvent *event, int *seq, BoulderDropWork *work)
{
    VecFx32 boulderPos;
    VecFx32 sinkPos;
    VecFx32 settlePos;

    switch (*seq) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(work->boulder) == 0)
            break;
        if (FLDMMDL_CheckPossibleAcmd(work->playerMmdl) == 0 && FIELD_PLAYER_GRID_StopTurnOrBlocked((struct FieldPlayerGrid *)work->player) == 0)
            break;
        FLDMMDL_SetAcmd(work->boulder, FLDMMDL_ACMD_ConvertCodeByDir(work->dir, 8));
        FLDMMDL_SetAcmd(work->playerMmdl, FLDMMDL_ACMD_ConvertCodeByDir(work->dir, 0x20));
        GFL_USE_PlaySeDefaultVolume(0x674);
        (*seq)++;
        break;
    case 1:
        if (FLDMMDL_CheckEndAcmd(work->boulder) == 0)
            break;
        if (FLDMMDL_CheckEndAcmd(work->playerMmdl) == 0)
            break;
        if (work->fillsHole == 0) {
            *seq = 4;
            break;
        }
        FLDMMDL_GetPos(work->boulder, &boulderPos);
        FLDMMDL_MOVE_GetMapHeight(work->boulder, &boulderPos, &work->targetY);
        if (FLDMMDL_GetObjCode(work->boulder) == 0x6d)
            work->targetY -= 14 << 12;
        else
            work->targetY -= 26 << 12;
        FLDMMDL_SetStatusBitHeightGetOff(work->boulder, 1);
        FLDMMDL_SetStatusBitFellowHit(work->boulder, 0);
        GFL_USE_PlaySeDefaultVolume(0x675);
        (*seq)++;
        break;
    case 2:
        FLDMMDL_GetPos(work->boulder, &sinkPos);
        if (work->targetY < sinkPos.y) {
            sinkPos.y -= 0x4000;
            if (work->targetY > sinkPos.y)
                sinkPos.y = work->targetY;
        } else if (work->targetY > sinkPos.y) {
            sinkPos.y += 0x4000;
            if (work->targetY < sinkPos.y)
                sinkPos.y = work->targetY;
        }
        FLDMMDL_SetPos(work->boulder, &sinkPos);
        if (work->targetY == sinkPos.y) {
            work->drawOffset.y = 0x2000;
            (*seq)++;
        }
        break;
    case 3:
        FLDMMDL_SetDrawOffsetOutside(work->boulder, &work->drawOffset);
        work->drawOffset.y = -work->drawOffset.y;
        work->frame = work->frame + 1;
        if (work->frame & 4) {
            if (work->drawOffset.y < 0)
                work->drawOffset.y += 0x1000;
            else if (work->drawOffset.y > 0)
                work->drawOffset.y -= 0x1000;
        }
        if (work->drawOffset.y == 0) {
            FLDMMDL_GetPos(work->boulder, &settlePos);
            FLDMMDL_InitPosition(work->boulder, &settlePos, work->dir);
            FLDMMDL_SetDrawOffsetOutside(work->boulder, &work->drawOffset);
            FLDMMDL_StoreMovedPos(work->boulder);
            (*seq)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}

void FIELD_PLAYER_GRID_EVENT_CreateHopTask(FieldPlayer *player, u16 dir, u32 attr, u32 heapId)
{
    HopWork *work;

    work = GFL_HEAP_Alloc((u16)(0x8000 | (heapId & 0x7fff)), sizeof(HopWork), 1, (const char *)&gFileFieldPlayerGridEvent, 0x1e6);
    work->fieldMap = FIELD_PLAYER_GetFieldMap(player);
    work->startDir = dir;
    work->player = player;
    work->gameSystem = (struct GameSystem *)FIELD_PLAYER_GetGrid(player);
    if (MAP_ATTR_IsLongHopEdge(MAP_ATTR_GetTerrainId(attr)) == 1)
        work->isLong = 1;
    TCB_AddTask((struct TcbSystem *)(FIELDMAP_GetTcblSys(work->fieldMap)), (TcbFunc)FIELD_PLAYER_GRID_EVENT_HopTask, work, 0);
}

int FIELD_PLAYER_GRID_EVENT_IsHopDone(struct TcbTask *task)
{
    return ((HopWork *)TCBL_IsDeletePending(task))->done;
}

void FIELD_PLAYER_GRID_EVENT_DeleteHopTask(struct TcbTask *task)
{
    GFL_HEAP_Free(TCBL_IsDeletePending(task));
    TCB_DeleteTask(task);
}

void FIELD_PLAYER_GRID_EVENT_HopTask(struct TcbTask *task, HopWork *work)
{
    Mmdl *mmdl;
    u16 dir;
    u32 acmd;
    int gridX;
    int gridZ;
    VecFx32 pos;
    int mapHeight;
    short tile[3];
    EncountSys *encount;
    int stepDist;

    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    switch (work->state) {
    case 0:
        dir = FLDMMDL_GetDirDisp(mmdl);
        gridX = FLDMMDL_GetGridNowX(mmdl);
        gridZ = FLDMMDL_GetGridNowZ(mmdl);
        FLDMMDL_GetPos(mmdl, &pos);
        FLDMMDL_MOVE_GridToVectorPos(gridX, gridZ, &pos);
        stepDist = 0x10000;
        if (work->isLong == 1)
            stepDist = 0x20000;
        FLDMMDL_MOVE_AddDirVector(dir, &pos, stepDist);
        mapHeight = 0;
        FLDMMDL_MOVE_GetMapHeight(mmdl, &pos, &mapHeight);
        pos.y = mapHeight;
        FIELD_PLAYER_SetRideEffect(work->player, FLDEFF_NAMIPOKE_Start(FIELDMAP_GetEffect(work->fieldMap), dir, &pos, mmdl, 0));
        encount = (struct EncountSys *)FIELDMAP_GetEncount(work->fieldMap);
        tile[0] = (pos.x >> 4) / 0x1000;
        tile[1] = (pos.y >> 4) / 0x1000;
        tile[2] = (pos.z >> 4) / 0x1000;
        if (EFFECT_ENCOUNT_IsSpotAt((struct FieldEncount *)encount, tile))
            EFFECT_ENCOUNT_SetEffectFlag((struct FieldEncount *)encount, 1);
        work->state++;
        break;
    case 1:
        work->frame++;
        if (work->frame > 15)
            work->state++;
        break;
    case 2:
        dir = FLDMMDL_GetDirDisp(mmdl);
        acmd = FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x34);
        if (work->isLong == 1)
            acmd = FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x38);
        FLDMMDL_SetAcmd(mmdl, acmd);
        work->state++;
        break;
    case 3:
        if (FLDMMDL_CheckEndAcmd(mmdl) == 0)
            break;
        FLDMMDL_EndAcmd(mmdl);
        FLDEFF_NAMIPOKE_SetFollowMode(FIELD_PLAYER_GetRideEffect(work->player), 1);
        FIELD_PLAYER_StartFormChange(work->player, 4);
        work->state++;
    case 4:
        if (FIELD_PLAYER_StepFormChange(work->player) == 1) {
            FIELD_PLAYER_SetGridHopLanded(work->player, 1);
            work->done = 1;
            work->state++;
        }
        break;
    case 5:
        break;
    }
}

void FIELD_PLAYER_GRID_EVENT_CreateJumpTask(FieldPlayer *player, u16 dir, u32 attr, u32 heapId)
{
    JumpWork *work;
    Mmdl *mmdl;
    VecFx32 start;
    VecFx32 ahead;
    int aheadHeight;

    work = GFL_HEAP_Alloc((u16)(0x8000 | (heapId & 0x7fff)), sizeof(JumpWork), 1, (const char *)&gFileFieldPlayerGridEvent, 0x2b3);
    work->dir = dir;
    work->player = player;
    work->fieldMap = FIELD_PLAYER_GetFieldMap(player);
    mmdl = FIELD_PLAYER_GetMmdl(player);
    FLDMMDL_GetPos(mmdl, &start);
    ahead = start;
    FLDMMDL_MOVE_AddDirVector(work->dir, &ahead, 0x20000);
    FLDMMDL_MOVE_GetMapHeight(mmdl, &ahead, &aheadHeight);
    if (aheadHeight > start.y)
        work->targetHigher = 1;
    work->gameSystem = (struct GameSystem *)FIELD_PLAYER_GetGrid(work->player);
    TCB_AddTask((struct TcbSystem *)(FIELDMAP_GetTcblSys(work->fieldMap)), (TcbFunc)FIELD_PLAYER_GRID_EVENT_RunStateTable, work, 0);
}

int FIELD_PLAYER_GRID_EVENT_IsJumpDone(struct TcbTask *task)
{
    return ((JumpWork *)TCBL_IsDeletePending(task))->done;
}

void FIELD_PLAYER_GRID_EVENT_DeleteJumpTask(struct TcbTask *task)
{
    GFL_HEAP_Free(TCBL_IsDeletePending(task));
    TCB_DeleteTask(task);
}

/*
 * Offsets a draw offset by (0, 1.0, 5.0) fx32 and applies it.
 */
void FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(Mmdl *mmdl, const VecFx32 *offset)
{
    VecFx32 shifted = *offset;
    shifted.y += 0x1000;
    shifted.z += 0x5000;
    FLDMMDL_SetDrawOffsetOutside(mmdl, &shifted);
}

int FIELD_PLAYER_GRID_EVENT_JumpUpStart(JumpWork *work)
{
    u32 effectKind;
    Mmdl *mmdl;
    FieldPlayerAnim *playerAnim;
    FieldEffectSys *effects;
    VecFx32 pos;
    VecFx32 nearPos;
    VecFx32 farPos;
    VecFx32 origin;
    int effectId;

    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    effectKind = 1;
    FLDMMDL_SetStatusBitHeightGetOff(mmdl, 1);
    FLDMMDL_GetPos(mmdl, &pos);
    origin = pos;
    nearPos = origin;
    farPos = origin;
    FLDMMDL_MOVE_AddDirVector(work->dir, &nearPos, 0x10000);
    FLDMMDL_MOVE_AddDirVector(work->dir, &farPos, 0x20000);
    FLDMMDL_MOVE_GridToVectorPos((s16)((nearPos.x >> 4) / 0x1000), (s16)((nearPos.z >> 4) / 0x1000), &nearPos);
    FLDMMDL_MOVE_GridToVectorPos((s16)((farPos.x >> 4) / 0x1000), (s16)((farPos.z >> 4) / 0x1000), &work->target);
    work->target = farPos;
    FLDMMDL_MOVE_GetMapHeight(mmdl, &farPos, &work->target.y);
    work->stepX = (nearPos.x - pos.x) / 2 / 16;
    work->stepZ = (nearPos.z - pos.z) / 2 / 16;
    work->velocityY = 0x6000;
    work->drawOffset.y = 0x1000;
    playerAnim = FIELD_PLAYER_GetRideEffect(work->player);
    FLDEFF_NAMIPOKE_SetFollowMode(playerAnim, 2);
    if ((u16)(work->dir + 0xfffe) <= 1)
        effectKind = 3;
    effects = FIELDMAP_GetEffect(work->fieldMap);
    effectId = 9;
    FIELD_EFFECT_LoadResources(effects, &effectId, 1);
    work->effectHandle = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(effects, effectKind, playerAnim);
    FIELDMAP_TCB_CAMERA_ZOOM_Create(work->fieldMap, 0x10, 0x20000);
    GFL_USE_PlaySeDefaultVolume(0x6e0);
    work->state = work->state + 1;
    return 1;
}

int FIELD_PLAYER_GRID_EVENT_JumpUpApproach(JumpWork *work)
{
    VecFx32 pos;
    Mmdl *mmdl;
    FieldPlayerAnim *playerAnim;

    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    FLDMMDL_GetPos(mmdl, &pos);
    pos.x += work->stepX;
    pos.z += work->stepZ;
    FLDMMDL_SetPos(mmdl, &pos);
    work->drawOffset.y = -work->drawOffset.y;
    work->frame += 1;
    if (work->frame >= 0x10) {
        work->frame = 0;
        work->drawOffset.y = 0;
        work->state = work->state + 1;
        FIELD_EFFECT_DeleteObject((struct FieldEffectObj *)work->effectHandle);
        playerAnim = FIELD_PLAYER_GetRideEffect(work->player);
        {
            /* both branches give 2 */
            u32 effectKind = 2;
            if ((u16)(work->dir + 0xfffe) <= 1)
                effectKind = 2;
            work->effectHandle = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FIELDMAP_GetEffect(work->fieldMap), effectKind, playerAnim);
        }
    }
    FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(mmdl, &work->drawOffset);
    return 0;
}

int FIELD_PLAYER_GRID_EVENT_JumpUpRise(JumpWork *work)
{
    VecFx32 pos;
    Mmdl *mmdl;

    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    FLDMMDL_GetPos(mmdl, &pos);
    pos.y += work->velocityY;
    if (pos.y >= work->target.y) {
        pos.y = work->target.y;
        work->state = work->state + 1;
        work->stepX = (work->target.x - pos.x) / 16;
        work->stepZ = (work->target.z - pos.z) / 16;
        work->gravity = -0x8000;
        work->velocityY = 0x6000;
        work->gravity = work->gravity / 0xb;
        FIELDMAP_TCB_CAMERA_ZOOM_Create(work->fieldMap, 0x10, (u32)-0x8000 << 2);
        FIELD_EFFECT_DeleteObject((struct FieldEffectObj *)work->effectHandle);
    }
    FLDMMDL_SetPos(mmdl, &pos);
    return 0;
}

int FIELD_PLAYER_GRID_EVENT_JumpUpArc(JumpWork *work)
{
    VecFx32 pos;
    Mmdl *mmdl;

    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    FLDMMDL_GetPos(mmdl, &pos);
    if (pos.x < work->target.x) {
        pos.x += work->stepX;
        if (pos.x > work->target.x)
            pos.x = work->target.x;
    } else {
        pos.x += work->stepX;
        if (pos.x < work->target.x)
            pos.x = work->target.x;
    }
    if (pos.z < work->target.z) {
        pos.z += work->stepZ;
        if (pos.z > work->target.z)
            pos.z = work->target.z;
    } else {
        pos.z += work->stepZ;
        if (pos.z < work->target.z)
            pos.z = work->target.z;
    }
    pos.y += work->velocityY;
    work->velocityY += work->gravity;
    work->frame += 1;
    if (work->frame >= 0x10) {
        pos = work->target;
        work->drawOffset.x = 0;
        work->drawOffset.y = 0;
        work->drawOffset.z = 0;
        work->state = work->state + 1;
    }
    FLDMMDL_SetPos(mmdl, &pos);
    FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(mmdl, &work->drawOffset);
    return 0;
}

int FIELD_PLAYER_GRID_EVENT_JumpUpLand(JumpWork *work)
{
    Mmdl *mmdl;
    FieldPlayerAnim *playerAnim;

    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    FLDMMDL_SetStatusBitHeightGetOff(mmdl, 0);
    FLDMMDL_InitPosition(mmdl, &work->target, work->dir);
    playerAnim = FIELD_PLAYER_GetRideEffect(work->player);
    FLDEFF_NAMIPOKE_SetFollowMode(playerAnim, 1);
    work->effectHandle = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FIELDMAP_GetEffect(work->fieldMap), 0, playerAnim);
    GFL_USE_PlaySeDefaultVolume(0x6e2);
    work->state = work->state + 1;
    return 0;
}

int FIELD_PLAYER_GRID_EVENT_JumpUpWaitEffect(JumpWork *work)
{
    FieldEffectSys *effects;

    if (work->effectHandle != 0 && FLDEFF_NAMIPOKE_SPLASH_IsFinished((struct FieldEffectObj *)work->effectHandle) == 1) {
        effects = FIELDMAP_GetEffect(work->fieldMap);
        FIELD_EFFECT_DeleteObject((struct FieldEffectObj *)work->effectHandle);
        FIELD_EFFECT_FreeResource(effects, 9);
        FIELD_PLAYER_SetGridHopLanded(work->player, 1);
        work->effectHandle = 0;
        work->done = 1;
    }
    return 0;
}

void FIELD_PLAYER_GRID_EVENT_UpdateJumpDown(JumpWork *work)
{
    Mmdl *mmdl;
    u32 effectKind;
    FieldPlayerAnim *playerAnim;
    FieldEffectSys *effects;
    VecFx32 nowPos;
    VecFx32 pos;
    VecFx32 nearPos;
    VecFx32 farPos;
    VecFx32 origin;
    int effectId;

    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    switch (work->state) {
    case 0:
        effectKind = 1;
        FLDMMDL_SetStatusBitHeightGetOff(mmdl, 1);
        FLDMMDL_GetPos(mmdl, &pos);
        origin = pos;
        nearPos = origin;
        farPos = origin;
        FLDMMDL_MOVE_AddDirVector(work->dir, &nearPos, 0x10000);
        FLDMMDL_MOVE_AddDirVector(work->dir, &farPos, 0x20000);
        FLDMMDL_MOVE_GridToVectorPos((s16)((nearPos.x >> 4) / 0x1000), (s16)((nearPos.z >> 4) / 0x1000), &nearPos);
        FLDMMDL_MOVE_AddDirVector(work->dir, &nearPos, 0x4000);
        FLDMMDL_MOVE_GridToVectorPos((s16)((farPos.x >> 4) / 0x1000), (s16)((farPos.z >> 4) / 0x1000), &farPos);
        work->target = farPos;
        FLDMMDL_MOVE_GetMapHeight(mmdl, &farPos, &work->target.y);
        work->stepX = (nearPos.x - pos.x) / 16;
        work->stepZ = (nearPos.z - pos.z) / 16;
        work->velocityY = -0x6000;
        work->drawOffset.y = 0x1000;
        playerAnim = FIELD_PLAYER_GetRideEffect(work->player);
        FLDEFF_NAMIPOKE_SetFollowMode(playerAnim, 2);
        if ((u16)(work->dir + 0xfffe) <= 1)
            effectKind = 3;
        effects = FIELDMAP_GetEffect(work->fieldMap);
        effectId = 9;
        FIELD_EFFECT_LoadResources(effects, &effectId, 1);
        work->effectHandle = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(effects, effectKind, playerAnim);
        FIELDMAP_TCB_CAMERA_ZOOM_Create(work->fieldMap, 0x10, 0x20000);
        GFL_USE_PlaySeDefaultVolume(0x6e1);
        work->state = work->state + 1;
    case 1:
        FLDMMDL_GetPos(mmdl, &nowPos);
        nowPos.x += work->stepX;
        nowPos.z += work->stepZ;
        FLDMMDL_SetPos(mmdl, &nowPos);
        work->drawOffset.y = -work->drawOffset.y;
        work->frame += 1;
        if (work->frame >= 0x10) {
            work->frame = 0;
            work->drawOffset.y = 0;
            work->state = work->state + 1;
            FIELD_EFFECT_DeleteObject((struct FieldEffectObj *)work->effectHandle);
            playerAnim = FIELD_PLAYER_GetRideEffect(work->player);
            {
                /* both branches give 2 */
                u32 landKind = 2;
                if ((u16)(work->dir + 0xfffe) <= 1)
                    landKind = 2;
                work->effectHandle = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FIELDMAP_GetEffect(work->fieldMap), landKind, playerAnim);
            }
        }
        FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(mmdl, &work->drawOffset);
        break;
    case 2:
        FLDMMDL_GetPos(mmdl, &nowPos);
        nowPos.y += work->velocityY;
        if (nowPos.y <= work->target.y) {
            nowPos.y = work->target.y;
            work->state = work->state + 1;
            work->stepX = (work->target.x - nowPos.x) / 16;
            work->stepZ = (work->target.z - nowPos.z) / 16;
            FIELDMAP_TCB_CAMERA_ZOOM_Create(work->fieldMap, 0x10, -0x20000);
            FIELD_EFFECT_DeleteObject((struct FieldEffectObj *)work->effectHandle);
            playerAnim = FIELD_PLAYER_GetRideEffect(work->player);
            FLDEFF_NAMIPOKE_SetFollowMode(playerAnim, 1);
            work->effectHandle = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FIELDMAP_GetEffect(work->fieldMap), 0, playerAnim);
        }
        FLDMMDL_SetPos(mmdl, &nowPos);
        break;
    case 3:
        FLDMMDL_GetPos(mmdl, &nowPos);
        nowPos.x += work->stepX;
        nowPos.z += work->stepZ;
        FLDMMDL_SetPos(mmdl, &nowPos);
        work->frame += 1;
        if (work->frame >= 0x10) {
            effects = FIELDMAP_GetEffect(work->fieldMap);
            FLDMMDL_SetStatusBitHeightGetOff(mmdl, 0);
            FLDMMDL_InitPosition(mmdl, &work->target, work->dir);
            FIELD_EFFECT_DeleteObject((struct FieldEffectObj *)work->effectHandle);
            FIELD_EFFECT_FreeResource(effects, 9);
            FIELD_PLAYER_SetGridHopLanded(work->player, 1);
            work->effectHandle = 0;
            work->done = 1;
            GFL_USE_PlaySeDefaultVolume(0x6e2);
            work->state = work->state + 1;
        }
        break;
    }
}

typedef int (*Fld3dCiStateFunc)(u16 *state);






extern Fld3dCiStateFunc d_021DA128[];

/*
 * Runs the state table until a state returns other than 1.
 * Belongs to the grid event file (see cuts).
 */
void FIELD_PLAYER_GRID_EVENT_RunStateTable(void *work, u16 *state)
{
    if (state[0] != 0) {
        while (d_021DA128[(s16)state[1]](state) == 1)
            ;
    } else {
        FIELD_PLAYER_GRID_EVENT_UpdateJumpDown((JumpWork *)state);
    }
}

/* Belongs to the grid event file (see cuts). */
u32 FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr(u8 *work, u32 direction)
{
    uptr mmdl;
    uptr mapHandle;
    int gridX;
    int gridZ;

    mmdl = (uptr)FIELD_PLAYER_GRID_GetMmdl((FieldPlayer *)work);
    mapHandle = (uptr)FLDMMDL_GetMmdlSys((void *)mmdl);
    gridX = FLDMMDL_GetGridNowX((Mmdl *)mmdl);
    gridX += FLDMMDL_MOVE_GetDirAddGridX(direction);
    gridZ = FLDMMDL_GetGridNowZ((Mmdl *)mmdl);
    gridZ += FLDMMDL_MOVE_GetDirAddGridZ(direction);
    return (uptr)FLDMMDL_SysSearchGridPosHeight((struct MmdlSys *)mapHandle, (s16)gridX, (s16)gridZ, (u32)FLDMMDL_GetPosY((void *)mmdl), (u32)1, 0);
}
