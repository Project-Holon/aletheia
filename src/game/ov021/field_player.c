/*
 * file:     field_player.c
 * unit:     yes
 * function: FIELD_PLAYER_Create, FIELD_PLAYER_Delete, FIELD_PLAYER_SaveToPlayerWork, FIELD_PLAYER_TryPushBoulder, FIELD_PLAYER_StartFormChange, FIELD_PLAYER_StepFormChange, FIELD_PLAYER_FinishFormChange, FIELD_PLAYER_ResetMoveWork, FIELD_PLAYER_SetRideEffect, FIELD_PLAYER_GetRideEffect, FIELD_PLAYER_ChooseMoveDirFromKeys, FIELD_PLAYER_CheckMoveBusy, FIELD_PLAYER_ChangeToNormalForm, FIELD_PLAYER_UpdateStepPhase, FIELD_PLAYER_GetPos, FIELD_PLAYER_SetPos, FIELD_PLAYER_GetDirDisp, FIELD_PLAYER_SetDirDisp, FIELD_PLAYER_GetFieldMap, FIELD_PLAYER_GetMmdl, FIELD_PLAYER_GetStepKind, FIELD_PLAYER_GetStepPhase, FIELD_PLAYER_GetFormCode, FIELD_PLAYER_SetFormCode, FIELD_PLAYER_GetSex, FIELD_PLAYER_GetGameSystem, FIELD_PLAYER_GetNowAttribute, FIELD_PLAYER_GetFrontAttribute, FIELD_PLAYER_GetFormObjCode, FIELD_PLAYER_GetObjCodeOfFormCode, FIELD_PLAYER_GetFormSlotOfObjCode, FIELD_PLAYER_CheckNotWaterForm, FIELD_PLAYER_SetObjCode, FIELD_PLAYER_ClearRememberedObjCode, FIELD_PLAYER_CheckFormModel, FIELD_PLAYER_CheckAnimePaused, FIELD_PLAYER_SearchFrontMmdl, FIELD_PLAYER_SearchFrontMmdlHeight, FIELD_PLAYER_GetGridPosInDir, FIELD_PLAYER_GetPosInDir, FIELD_PLAYER_GetFrontGridPos, FIELD_PLAYER_GetMoveOffsetInDir, FIELD_PLAYER_GetFormSlot, FIELD_PLAYER_WaitModelReady, FIELD_PLAYER_CheckSurfStartAttr, FIELD_PLAYER_CheckWaterfallClimbAttr, FIELD_PLAYER_ResetGridHold, FIELD_PLAYER_StopGridForcedMove, FIELD_PLAYER_GetGridHopLanded, FIELD_PLAYER_SetGridHopLanded, FIELD_PLAYER_CheckMoveRestrictFlag, FIELD_PLAYER_CreateGrid, FIELD_PLAYER_MoveGrid, FIELD_PLAYER_GetNowGridPos, FIELD_PLAYER_IsGridHopping, FIELD_PLAYER_FinishGridHop, FIELD_PLAYER_CreateNogrid, FIELD_PLAYER_UpdateNogrid, FIELD_PLAYER_AttachNogridMmdl, FIELD_PLAYER_ResetNogrid, FIELD_PLAYER_IsNogridForcedMove, FIELD_PLAYER_GetNogridRailWork, FIELD_PLAYER_SetNogridRailLocation, FIELD_PLAYER_GetNogridNextRailLocation, FIELD_PLAYER_GetNogridLocationByDir, FIELD_PLAYER_GetNogridRailPos, FIELD_PLAYER_GetGrid
 * address:  0x021A2E50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A2E8C (gFieldPlayerFileName "field_player.c"); wrapper layer that forwards to core (+4), grid (+8) and nogrid (+C) objects.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gFieldPlayerFileName     0x021DDEA8  data  a4
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   GAME_DATA_SetPlayerPosition  0x02012A90  thumb
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   GAME_DATA_SetPlayerDirectionType  0x02012AD4  thumb
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb
 *   GAME_DATA_SetPlayerMoveForm  0x02012ABC  thumb
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb
 *   GAME_DATA_SetPlayerRail  0x02012AA4  thumb
 *   FIELD_PLAYER_GRID_EVENT_TryPushBoulder  0x021C0CA4  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   FIELD_NOGRID_MAPPER_GetAttribute  0x021BB3C4  thumb
 *   FLDMMDL_RAIL_GetLocationByDir  0x0219E664  thumb
 *   gFieldPlayerFormTable  0x021D890C  data
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FLDMMDL_RAIL_GetFrontLocation  0x0219E634  thumb
 *   FLDMMDL_RAIL_SearchMmdlByLocation  0x0219E570  thumb
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 *   FLDMMDL_RAIL_GetDrawOffsetByDir  0x0219E784  thumb  ov021
 *   FIELD_RAIL_GetUnitScale  0x021B7C38  thumb  ov021
 *   VEC_Normalize  0x0207CCA4  arm
 *   MAP_ATTR_IsHopTransition  0x021AB5AC  thumb  ov021
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsWaterfall  0x021AB310  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FIELD_PLAYER_CORE_Create  0x021A36E4  thumb  ov021
 *   FIELD_PLAYER_CORE_Delete  0x021A3810  thumb  ov021
 *   FIELD_PLAYER_CORE_UpdateStepPhase  0x021A3818  thumb  ov021
 *   FIELD_PLAYER_CORE_GetPos  0x021A3898  thumb  ov021
 *   FIELD_PLAYER_CORE_SetPos  0x021A38A4  thumb  ov021
 *   FIELD_PLAYER_CORE_GetDirDisp  0x021A3920  thumb  ov021
 *   FIELD_PLAYER_CORE_SetDirDisp  0x021A392C  thumb  ov021
 *   FIELD_PLAYER_CORE_SetObjCode  0x021A3938  thumb  ov021
 *   FIELD_PLAYER_CORE_ClearRememberedObjCode  0x021A394C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFieldMap  0x021A395C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_CORE_GetStepKind  0x021A3968  thumb  ov021
 *   FIELD_PLAYER_CORE_SetStepPhase  0x021A396C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetStepPhase  0x021A3970  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_CORE_SetFormCode  0x021A3980  thumb  ov021
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetGameSystem  0x021A3990  thumb  ov021
 *   FIELD_PLAYER_CORE_GetPlayerWork  0x021A3994  thumb  ov021
 *   FIELD_PLAYER_CORE_WaitModelReady  0x021A39E4  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFormSlot  0x021A3A10  thumb  ov021
 *   FIELD_PLAYER_CORE_CheckFormModel  0x021A3A20  thumb  ov021
 *   FIELD_PLAYER_CORE_CheckAnimePaused  0x021A3A3C  thumb  ov021
 *   FIELD_PLAYER_CORE_ChooseMoveDirFromKeys  0x021A3AB8  thumb  ov021
 *   FIELD_PLAYER_CORE_SetRideEffect  0x021A3AD0  thumb  ov021
 *   FIELD_PLAYER_CORE_GetRideEffect  0x021A3AD4  thumb  ov021
 *   FIELD_PLAYER_CORE_StartFormChange  0x021A3CB0  thumb  ov021
 *   FIELD_PLAYER_CORE_StepFormChange  0x021A3CC0  thumb  ov021
 *   FIELD_PLAYER_CORE_FinishFormChange  0x021A3CE8  thumb  ov021
 *   FIELD_PLAYER_GRID_Create  0x021A4140  thumb  ov021
 *   FIELD_PLAYER_GRID_Delete  0x021A41A8  thumb  ov021
 *   FIELD_PLAYER_GRID_Move  0x021A41B0  thumb  ov021
 *   FIELD_PLAYER_GRID_ResetBlockedPose  0x021A53D0  thumb  ov021
 *   FIELD_PLAYER_GRID_IsOnForcedMoveTile  0x021A548C  thumb  ov021
 *   FIELD_PLAYER_GRID_IsHopping  0x021A54A0  thumb  ov021
 *   FIELD_PLAYER_GRID_FinishHop  0x021A54B4  thumb  ov021
 *   FIELD_PLAYER_GRID_ResetHold  0x021A5738  thumb  ov021
 *   FIELD_PLAYER_GRID_StopForcedMove  0x021A575C  thumb  ov021
 *   FIELD_PLAYER_GRID_GetHopLanded  0x021A5764  thumb  ov021
 *   FIELD_PLAYER_GRID_SetHopLanded  0x021A5768  thumb  ov021
 *   FIELD_PLAYER_GRID_IsBlocked  0x021A5778  thumb  ov021
 *   FIELD_PLAYER_NOGRID_Create  0x021A5880  thumb  ov021
 *   FIELD_PLAYER_NOGRID_Delete  0x021A5920  thumb  ov021
 *   FIELD_PLAYER_NOGRID_AttachMmdl  0x021A5928  thumb  ov021
 *   FIELD_PLAYER_NOGRID_ClearRailWork  0x021A5964  thumb  ov021
 *   FIELD_PLAYER_NOGRID_Update  0x021A596C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_IsBlocked  0x021A59DC  thumb  ov021
 *   FIELD_PLAYER_NOGRID_IsForcedMove  0x021A59EC  thumb  ov021
 *   FIELD_PLAYER_NOGRID_SetRailLocation  0x021A5A00  thumb  ov021
 *   FIELD_PLAYER_NOGRID_GetNextRailLocation  0x021A5A0C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_GetRailLocationByDir  0x021A5A18  thumb  ov021
 *   FIELD_PLAYER_NOGRID_GetRailPos  0x021A5A24  thumb  ov021
 *   FIELD_PLAYER_NOGRID_GetRailWork  0x021A5A30  thumb  ov021
 *   FIELD_PLAYER_NOGRID_EndBlockedWalk  0x021A5A34  thumb  ov021
 */
#include "field_player_types.h"

#include "../types.h"

/* A grid position or fixed point vector (three words). */
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} FieldPlayerLocationPos;

/* A rail location as a pair of words. */
typedef struct {
    s32 a;
    s32 b;
} FieldPlayerRailLocation;

struct GameData;
struct FieldG3dMapper;
struct FieldNogridMapper;

#include "../arm9/gfl_heap_wrap.h"
struct VecFx32;
struct Mmdl;
#include "../ov010/fldmmdl.h"
struct PlayerPosition;
struct PlayerWork;
#include "../arm9/game_data.h"
#include "fieldmap.h"
#include "fldmmdl_rail.h"
struct RailLocationWords;
struct FieldPlayer;
#include "field_player_grid_event.h"
#include "map_attr.h"
#include "field_nogrid_mapper.h"
#include "../ov010/fldmmdl_move.h"
struct RailManager;
#include "field_rail.h"
#include "../arm9/fx_vec.h"
#include "../arm9/gamesystem.h"
struct EventWork;
#include "../arm9/zonedata.h"

#include "field_player_core.h"

#include "field_player_grid.h"

#include "field_player_nogrid.h"
struct FieldPlayerNogrid;
struct RailWork;

void FIELD_PLAYER_GetPos(FieldPlayer *player, VecFx32 *out);
Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *player);
u32 FIELD_PLAYER_GetFormCode(FieldPlayer *player);
void FIELD_PLAYER_GetPosInDir(FieldPlayer *player, int dir, VecFx32 *out);
void FIELD_PLAYER_GetFrontGridPos(FieldPlayer *player, s16 *gridX, s16 *gridY, s16 *gridZ);

extern int gFieldPlayerFileName;
extern const FieldPlayerFormRow gFieldPlayerFormTable[];

/*
 * Addresses are Black-image addresses.
 */
FieldPlayer *FIELD_PLAYER_Create(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, u32 sex, u16 heapId)
{
    FieldPlayer *player = GFL_HEAP_Alloc(heapId, 0x10, 1, (const char *)&gFieldPlayerFileName, 0x4C);

    player->fieldMap = fieldMap;
    player->core = FIELD_PLAYER_CORE_Create(playerWork, fieldMap, pos, sex, heapId);
    return player;
}

int FIELD_PLAYER_Delete(FieldPlayer *player)
{
    if (player->grid != 0) {
        FIELD_PLAYER_GRID_Delete(player->grid);
    }
    if (player->nogrid != 0) {
        FIELD_PLAYER_NOGRID_Delete(player->nogrid);
    }
    FIELD_PLAYER_CORE_Delete(player->core);
    return GFL_HEAP_Free(player);
}

void FIELD_PLAYER_SaveToPlayerWork(FieldPlayer *player)
{
    u8 gridPos[12];
    u8 railLocation[8];
    struct PlayerWork *playerWork = FIELD_PLAYER_CORE_GetPlayerWork(player->core);
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(player->core);

    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)gridPos);
    GAME_DATA_SetPlayerPosition(playerWork, (struct PlayerPosition *)gridPos);
    GAME_DATA_SetPlayerDirectionType(playerWork, FLDMMDL_GetDirDisp(mmdl));
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        GAME_DATA_SetPlayerMoveForm( (struct PlayerWork *)playerWork, 0);
        return;
    }
    FLDMMDL_RAIL_GetNextLocation( (Mmdl *)mmdl, (RailLocation *)railLocation);
    GAME_DATA_SetPlayerRail( (struct PlayerWork *)playerWork, (const struct RailLocation *)((struct RailLocationWords *)railLocation));
    GAME_DATA_SetPlayerMoveForm(playerWork, 1);
}

int FIELD_PLAYER_TryPushBoulder(FieldPlayer *player, int a, int b, int c)
{
    int pushed = 0;

    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0)
        pushed = FIELD_PLAYER_GRID_EVENT_TryPushBoulder((struct FieldPlayer *)player->grid, a, b, c);
    return pushed;
}

void FIELD_PLAYER_StartFormChange(FieldPlayer *player, u32 mask)
{
    FIELD_PLAYER_CORE_StartFormChange(player->core, mask);
}

int FIELD_PLAYER_StepFormChange(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_StepFormChange(player->core);
}

void FIELD_PLAYER_FinishFormChange(FieldPlayer *player)
{
    FIELD_PLAYER_CORE_FinishFormChange(player->core);
}

void FIELD_PLAYER_ResetMoveWork(FieldPlayer *player)
{
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0)
        FIELD_PLAYER_GRID_ResetBlockedPose(player->grid);
    else
        FIELD_PLAYER_NOGRID_EndBlockedWalk(player->nogrid);
}

void FIELD_PLAYER_SetRideEffect(FieldPlayer *player, struct FieldEffectObj *rideEffect)
{
    FIELD_PLAYER_CORE_SetRideEffect(player->core, rideEffect);
}

struct FieldEffectObj *FIELD_PLAYER_GetRideEffect(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetRideEffect(player->core);
}

u16 FIELD_PLAYER_ChooseMoveDirFromKeys(FieldPlayer *player, u32 keys)
{
    return FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(player->core, keys);
}

u32 FIELD_PLAYER_CheckMoveBusy(FieldPlayer *player)
{
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        return FIELD_PLAYER_GRID_IsBlocked(player->grid);
    }
    return FIELD_PLAYER_NOGRID_IsBlocked(player->nogrid);
}

void FIELD_PLAYER_ChangeToNormalForm(FieldPlayer *player)
{
    FIELD_PLAYER_CORE_StartFormChange(player->core, 1);
    FIELD_PLAYER_CORE_FinishFormChange(player->core);
}

void FIELD_PLAYER_UpdateStepPhase(FieldPlayer *player)
{
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        if (FIELD_PLAYER_GRID_IsOnForcedMoveTile(player->grid) == 1) {
            FIELD_PLAYER_CORE_SetStepPhase(player->core, 2);
            return;
        }
        if (FIELD_PLAYER_GRID_IsHopping(player->grid) == 1) {
            FIELD_PLAYER_CORE_SetStepPhase(player->core, 2);
            return;
        }
    } else {
        if (FIELD_PLAYER_NOGRID_IsForcedMove(player->nogrid) == 1) {
            FIELD_PLAYER_CORE_SetStepPhase(player->core, 2);
            return;
        }
    }
    FIELD_PLAYER_CORE_UpdateStepPhase(player->core);
}

void FIELD_PLAYER_GetPos(FieldPlayer *player, VecFx32 *out)
{
    FIELD_PLAYER_CORE_GetPos(player->core, out);
}

void FIELD_PLAYER_SetPos(FieldPlayer *player, VecFx32 *pos)
{
    FIELD_PLAYER_CORE_SetPos(player->core, pos);
}

u16 FIELD_PLAYER_GetDirDisp(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetDirDisp(player->core);
}

void FIELD_PLAYER_SetDirDisp(FieldPlayer *player, int dir)
{
    FIELD_PLAYER_CORE_SetDirDisp(player->core, dir);
}

FieldMap *FIELD_PLAYER_GetFieldMap(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetFieldMap(player->core);
}

Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetMmdl(player->core);
}

u32 FIELD_PLAYER_GetStepKind(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetStepKind(player->core);
}

u32 FIELD_PLAYER_GetStepPhase(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetStepPhase(player->core);
}

u32 FIELD_PLAYER_GetFormCode(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetFormCode(player->core);
}

void FIELD_PLAYER_SetFormCode(FieldPlayer *player, u32 formCode)
{
    FIELD_PLAYER_CORE_SetFormCode(player->core, formCode);
}

u32 FIELD_PLAYER_GetSex(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetSex(player->core);
}

struct GameSystem *FIELD_PLAYER_GetGameSystem(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetGameSystem(player->core);
}

u32 FIELD_PLAYER_GetNowAttribute(FieldPlayer *player)
{
    u32 attr;

    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        FieldPlayerLocationPos pos;
        struct FieldG3dMapper *g3dMapper = FIELDMAP_GetG3dMapper(player->fieldMap);

        FIELD_PLAYER_GetPos(player, (VecFx32 *)&pos);
        attr = MAP_ATTR_GetAt(g3dMapper, (const struct VecFx32 *)&pos);
    } else if (FIELDMAP_GetMoveKind(player->fieldMap) == 1) {
        FieldPlayerRailLocation location;
        Mmdl *mmdl = FIELD_PLAYER_GetMmdl(player);
        struct FieldNogridMapper *mapper = FIELDMAP_GetNogridMapper(player->fieldMap);

        FLDMMDL_RAIL_GetNextLocation( (Mmdl *)mmdl, (RailLocation *)&location);
        attr = FIELD_NOGRID_MAPPER_GetAttribute( (FieldNogridMapper *)mapper, (const RailLocation *)&location);
    }
    return attr;
}

u32 FIELD_PLAYER_GetFrontAttribute(FieldPlayer *player, u32 dir)
{
    u32 attr;
    VecFx32 frontPos;
    u8 railLocation[8];

    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        struct FieldG3dMapper *g3dMapper = FIELDMAP_GetG3dMapper(player->fieldMap);

        FIELD_PLAYER_GetPosInDir(player, dir, &frontPos);
        attr = MAP_ATTR_GetAt(g3dMapper, &frontPos);
    } else if (FIELDMAP_GetMoveKind(player->fieldMap) == 1) {
        Mmdl *mmdl = FIELD_PLAYER_GetMmdl(player);
        struct FieldNogridMapper *mapper = FIELDMAP_GetNogridMapper(player->fieldMap);

        FLDMMDL_RAIL_GetLocationByDir( (Mmdl *)mmdl, dir, (RailLocation *)railLocation);
        attr = FIELD_NOGRID_MAPPER_GetAttribute( (FieldNogridMapper *)mapper, (const RailLocation *)railLocation);
    }
    return attr;
}

/* Model code of avatar form slot formSlot in the row for sex. */
u16 FIELD_PLAYER_GetFormObjCode(int sex, int formSlot)
{
    return gFieldPlayerFormTable[sex].entries[formSlot].objCode;
}

/* Model code of the entry of row sex whose form code is formCode, else the hero model. */
int FIELD_PLAYER_GetObjCodeOfFormCode(int sex, int formCode)
{
    const FieldPlayerFormEntry *entry;
    int slot;

    slot = 0;
    entry = gFieldPlayerFormTable[sex].entries;
    for (; slot < FIELD_PLAYER_AVATAR_FORM_COUNT; slot++, entry++) {
        if (entry->formCode == formCode)
            return entry->objCode;
    }
    return FIELD_PLAYER_OBJ_CODE_HERO;
}

/* Form slot whose model code is objCode in either row, else FIELD_PLAYER_AVATAR_FORM_COUNT. */
int FIELD_PLAYER_GetFormSlotOfObjCode(u16 objCode)
{
    int sex;
    int slot;
    const FieldPlayerFormEntry *entry;

    for (sex = 0; sex < 2; sex++) {
        entry = gFieldPlayerFormTable[sex].entries;
        for (slot = 0; slot < FIELD_PLAYER_AVATAR_FORM_COUNT; slot++) {
            if (entry->objCode == objCode)
                return slot;
            entry++;
        }
    }
    return FIELD_PLAYER_AVATAR_FORM_COUNT;
}

/* 0 while the form code is 2 or 3 (surf, dive), else 1. */
int FIELD_PLAYER_CheckNotWaterForm(FieldPlayer *player)
{
    switch (FIELD_PLAYER_GetFormCode(player)) {
    case 2:
    case 3:
        return 0;
    }
    return 1;
}

void FIELD_PLAYER_SetObjCode(FieldPlayer *player, u32 objCode)
{
    FIELD_PLAYER_CORE_SetObjCode(player->core, objCode);
}

void FIELD_PLAYER_ClearRememberedObjCode(FieldPlayer *player)
{
    FIELD_PLAYER_CORE_ClearRememberedObjCode(player->core);
}

int FIELD_PLAYER_CheckFormModel(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_CheckFormModel(player->core);
}

int FIELD_PLAYER_CheckAnimePaused(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_CheckAnimePaused(player->core);
}

/*
 * FLDMMDL_SysSearchGridPos forwards r0-r3 to FLDMMDL_SysSearchGridPosList, so it takes four
 * arguments; the fourth is the literal 0 whose register the compiler also
 * uses as the v[0] index.
 */
struct Mmdl *FIELD_PLAYER_SearchFrontMmdl(FieldPlayer *player)
{
    s16 v[8];
    struct MmdlSys *mmdlSys = FIELDMAP_GetMmdlSys(player->fieldMap);

    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        FIELD_PLAYER_GetFrontGridPos(player, &v[2], &v[1], &v[0]);
        return FLDMMDL_SysSearchGridPos(mmdlSys, v[2], v[0], 0);
    }
    FLDMMDL_RAIL_GetFrontLocation( (Mmdl *)(FIELD_PLAYER_CORE_GetMmdl( (FieldPlayerCore *)player->core)), (RailLocation *)&v[3]);
    return FLDMMDL_RAIL_SearchMmdlByLocation( (MmdlSys *)mmdlSys, (RailLocation *)&v[3], 0);
}

void FIELD_PLAYER_SearchFrontMmdlHeight(FieldPlayer *player, u32 limit)
{
    s16 v[8];
    struct MmdlSys *mmdlSys = FIELDMAP_GetMmdlSys(player->fieldMap);

    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        FIELD_PLAYER_GetFrontGridPos(player, &v[2], &v[1], &v[0]);
        FLDMMDL_SysSearchGridPosHeight(mmdlSys, v[2], v[0], v[1] << 16, limit, 0);
        return;
    }
    FLDMMDL_RAIL_GetFrontLocation( (Mmdl *)(FIELD_PLAYER_CORE_GetMmdl( (FieldPlayerCore *)player->core)), (RailLocation *)&v[3]);
    FLDMMDL_RAIL_SearchMmdlByLocation( (MmdlSys *)mmdlSys, (RailLocation *)&v[3], 0);
}

void FIELD_PLAYER_GetGridPosInDir(FieldPlayer *player, u32 dir, s16 *gridX, s16 *gridY, s16 *gridZ)
{
    Mmdl *mmdl = FIELD_PLAYER_GetMmdl(player);

    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        *gridX = FLDMMDL_GetGridNowX(mmdl);
        *gridY = FLDMMDL_GetGridNowY(mmdl);
        *gridZ = FLDMMDL_GetGridNowZ(mmdl);
        *gridX = *gridX + FLDMMDL_MOVE_GetDirAddGridX(dir);
        *gridZ = *gridZ + FLDMMDL_MOVE_GetDirAddGridZ(dir);
    }
}

void FIELD_PLAYER_GetPosInDir(FieldPlayer *player, int dir, VecFx32 *out)
{
    int railPos[3];
    s16 drawOffset[3];
    s16 location[4];
    s16 gridX;
    s16 gridY;
    s16 gridZ;
    Mmdl *mmdl;
    void *railMan;
    int unitScale;

    mmdl = FIELD_PLAYER_CORE_GetMmdl( (FieldPlayerCore *)player->core);
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        FIELD_PLAYER_GetGridPosInDir(player, dir, &gridX, &gridY, &gridZ);
        FLDMMDL_MOVE_GridToVectorPos(gridX, gridZ, out);
        out->y = gridY << 16;
        return;
    }
    railMan = FIELD_NOGRID_MAPPER_GetRailMan( (FieldNogridMapper *)(FIELDMAP_GetNogridMapper(player->fieldMap)));
    FLDMMDL_RAIL_GetNextLocation( (Mmdl *)mmdl, (RailLocation *)location);
    FIELD_RAIL_GetLocationPos( (RailManager *)railMan, (RailLocation *)location, (VecFx32 *)railPos);
    FLDMMDL_RAIL_GetDrawOffsetByDir(mmdl, dir, drawOffset);
    unitScale = FIELD_RAIL_GetUnitScale(railMan);
    out->x = railPos[0] + (int)(((long long)drawOffset[0] * unitScale + 0x800) >> 12);
    out->y = railPos[1] + (int)(((long long)drawOffset[1] * unitScale + 0x800) >> 12);
    out->z = railPos[2] + (int)(((long long)drawOffset[2] * unitScale + 0x800) >> 12);
}

void FIELD_PLAYER_GetFrontGridPos(FieldPlayer *player, s16 *gridX, s16 *gridY, s16 *gridZ)
{
    FIELD_PLAYER_GetGridPosInDir(player, FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(player)), gridX, gridY, gridZ);
}

void FIELD_PLAYER_GetMoveOffsetInDir(FieldPlayer *player, int dir, s32 *out)
{
    s16 offset[4];
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(player->core);

    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        s32 dz;

        out[1] = 0;
        out[0] = FLDMMDL_MOVE_GetDirAddGridX(dir);
        dz = FLDMMDL_MOVE_GetDirAddGridZ(dir);
        out[0] = out[0] << 16;
        out[2] = dz << 16;
        VEC_Normalize( (const VecFx32 *)out, (VecFx32 *)out);
        return;
    }
    FLDMMDL_RAIL_GetDrawOffsetByDir(mmdl, dir, offset);
    offsetZ = offset[2];
    offsetY = offset[1];
    offsetX = offset[0];
    out[0] = offsetX;
    out[1] = offsetY;
    out[2] = offsetZ;
}

int FIELD_PLAYER_GetFormSlot(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_GetFormSlot(player->core);
}

int FIELD_PLAYER_WaitModelReady(FieldPlayer *player)
{
    return FIELD_PLAYER_CORE_WaitModelReady(player->core);
}

int FIELD_PLAYER_CheckSurfStartAttr(FieldPlayer *player, int a, int b)
{
    int formCode = FIELD_PLAYER_GetFormCode(player);

    if (formCode == 2 || formCode == 3)
        return 0;
    return MAP_ATTR_IsHopTransition(a, b);
}

int FIELD_PLAYER_CheckWaterfallClimbAttr(FieldPlayer *player, int attrA, int attrB)
{
    int formCode = FIELD_PLAYER_GetFormCode(player);

    if (MAP_ATTR_IsBlocked(attrA) != 0 || formCode != 2)
        return 0;
    return MAP_ATTR_IsWaterfall(MAP_ATTR_GetTerrainId(attrB));
}

void FIELD_PLAYER_ResetGridHold(FieldPlayer *player, int a)
{
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0)
        FIELD_PLAYER_GRID_ResetHold(player->grid, a);
}

void FIELD_PLAYER_StopGridForcedMove(FieldPlayer *player)
{
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0)
        FIELD_PLAYER_GRID_StopForcedMove(player->grid);
}

int FIELD_PLAYER_GetGridHopLanded(FieldPlayer *player)
{
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        return FIELD_PLAYER_GRID_GetHopLanded(player->grid);
    }
    return 0;
}

void FIELD_PLAYER_SetGridHopLanded(FieldPlayer *player, int a)
{
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0)
        FIELD_PLAYER_GRID_SetHopLanded(player->grid, a);
}

int FIELD_PLAYER_CheckMoveRestrictFlag(FieldPlayer *player)
{
    if (ZONEDATA_CheckEventFlag(GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(FIELD_PLAYER_GetGameSystem(player))), 0x963) != 0)
        return 1;
    return 0;
}

void FIELD_PLAYER_CreateGrid(FieldPlayer *player, u32 heapId)
{
    player->grid = FIELD_PLAYER_GRID_Create(player->core, heapId);
}

void FIELD_PLAYER_MoveGrid(FieldPlayer *player, u32 a, u32 b, u32 c)
{
    FIELD_PLAYER_GRID_Move(player->grid, a, b, c);
}

void FIELD_PLAYER_GetNowGridPos(FieldPlayer *player, u16 *gridX, u16 *gridY, u16 *gridZ)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(player->core);

    *gridX = FLDMMDL_GetGridNowX(mmdl);
    *gridY = FLDMMDL_GetGridNowY(mmdl);
    *gridZ = FLDMMDL_GetGridNowZ(mmdl);
}

int FIELD_PLAYER_IsGridHopping(FieldPlayer *player)
{
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0) {
        if (FIELD_PLAYER_GRID_IsHopping(player->grid) == 1) {
            return 1;
        }
    }
    return 0;
}

void FIELD_PLAYER_FinishGridHop(FieldPlayer *player)
{
    if (FIELDMAP_GetMoveKind(player->fieldMap) == 0 && FIELD_PLAYER_GRID_IsHopping(player->grid) == 1)
        FIELD_PLAYER_GRID_FinishHop(player->grid);
}

void FIELD_PLAYER_CreateNogrid(FieldPlayer *player, u32 heapId)
{
    player->nogrid = FIELD_PLAYER_NOGRID_Create(player->core, heapId);
}

void FIELD_PLAYER_UpdateNogrid(FieldPlayer *player, u32 a, u32 b)
{
    FIELD_PLAYER_NOGRID_Update(player->nogrid, a, b);
}

void FIELD_PLAYER_AttachNogridMmdl(FieldPlayer *player, int a)
{
    FIELD_PLAYER_NOGRID_AttachMmdl( (FieldPlayerNogrid *)player->nogrid, (RailLocation *)a);
}

void FIELD_PLAYER_ResetNogrid(FieldPlayer *player)
{
    FIELD_PLAYER_NOGRID_ClearRailWork(player->nogrid);
}

u32 FIELD_PLAYER_IsNogridForcedMove(FieldPlayer *player)
{
    return FIELD_PLAYER_NOGRID_IsForcedMove(player->nogrid);
}

u32 FIELD_PLAYER_GetNogridRailWork(FieldPlayer *player)
{
    return (uptr)FIELD_PLAYER_NOGRID_GetRailWork(player->nogrid);
}

void FIELD_PLAYER_SetNogridRailLocation(FieldPlayer *player, void *a)
{
    FIELD_PLAYER_NOGRID_SetRailLocation(player->nogrid, a);
}

void FIELD_PLAYER_GetNogridNextRailLocation(FieldPlayer *player, void *a)
{
    FIELD_PLAYER_NOGRID_GetNextRailLocation(player->nogrid, a);
}

int FIELD_PLAYER_GetNogridLocationByDir(FieldPlayer *player, u32 a, void *b)
{
    return FIELD_PLAYER_NOGRID_GetRailLocationByDir(player->nogrid, a, b);
}

void FIELD_PLAYER_GetNogridRailPos(FieldPlayer *player, void *outPos)
{
    FIELD_PLAYER_NOGRID_GetRailPos(player->nogrid, outPos);
}

FieldPlayerGrid *FIELD_PLAYER_GetGrid(FieldPlayer *player)
{
    return player->grid;
}
