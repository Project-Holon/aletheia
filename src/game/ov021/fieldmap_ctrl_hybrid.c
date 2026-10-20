/*
 * file:     fieldmap_ctrl_hybrid.c
 * unit:     yes
 * function: FIELDMAP_CTRL_HYBRID_GetMode, FIELDMAP_CTRL_HYBRID_ReplacePlayer, FIELDMAP_CTRL_HYBRID_Create, FIELDMAP_CTRL_HYBRID_Destroy, FIELDMAP_CTRL_HYBRID_Main, FIELDMAP_CTRL_HYBRID_GetTargetPos, FIELDMAP_CTRL_HYBRID_UpdateGrid, FIELDMAP_CTRL_HYBRID_UpdateNogrid, FIELDMAP_CTRL_HYBRID_SwitchToNogrid, FIELDMAP_CTRL_HYBRID_SwitchToGrid, FIELDMAP_CTRL_HYBRID_FindGridPos, FIELDMAP_CTRL_HYBRID_FindRailLocation, FIELDMAP_CTRL_HYBRID_SetMode
 * address:  0x021A6DC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A6F14 (gFieldMapCtrlHybridFileName "fieldmap_ctrl_hybrid.c"); 021A6DC0..021A6DC4 read the same holder (mode f0, core at +4) that 021A6F24 uses.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FIELDMAP_SetTargetPos  0x02188D40  thumb  ov021
 *   FIELDMAP_SetCtrlWork  0x02188CAC  thumb  ov021
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_ChangeHeader  0x0216E0AC  thumb  ov010
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerRail  0x02012AB8  thumb
 *   FIELD_NOGRID_MAPPER_BindCameraWork  0x021BB3AC  thumb  ov021
 *   GAME_DATA_GetPlayerMoveForm  0x02012AC0  thumb
 *   FLDMMDL_DRAW_GetBlactAnime  0x0219F058  thumb  ov021
 *   gFieldMapCtrlHybridFileName     0x021DDF64  data  a1
 *   gFieldMapCtrlHybridModeTable  0x021DDF38  data  a4
 *   RAIL_ATTR_IsJumpStart  0x021BB1A0  thumb  ov021
 *   FIELD_RAIL_FindSegmentLocation  0x021B7A84  thumb  ov021
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
 *   FIELD_RAIL_TryStepLocation  0x021B7CD8  thumb  ov021
 *   FLDMMDL_CheckMoveBitAcmd  0x0216DC4C  thumb  ov010
 *   FLDMMDL_InitGridPosition  0x0216E084  thumb  ov010
 *   FIELD_NOGRID_MAPPER_UnbindCameraWork  0x021BB3B8  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_ReloadSetting  0x0218E160  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FLDMMDL_SetDirMove  0x0216D600  thumb  ov010
 *   FLDMMDL_DRAW_SetBlactAnime  0x0219F0B0  thumb  ov021
 *   FIELD_PLAYER_ChooseMoveDirFromKeys  0x021A2FA4  thumb  ov021
 *   FIELD_PLAYER_CheckMoveBusy  0x021A2FB0  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FIELD_PLAYER_SetDirDisp  0x021A305C  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   FIELD_PLAYER_GetFrontAttribute  0x021A3128  thumb  ov021
 *   FIELD_PLAYER_CheckMoveRestrictFlag  0x021A35BC  thumb  ov021
 *   FIELD_PLAYER_CreateGrid  0x021A35E0  thumb  ov021
 *   FIELD_PLAYER_MoveGrid  0x021A35F0  thumb  ov021
 *   FIELD_PLAYER_CreateNogrid  0x021A3664  thumb  ov021
 *   FIELD_PLAYER_UpdateNogrid  0x021A3674  thumb  ov021
 *   FIELD_PLAYER_AttachNogridMmdl  0x021A3680  thumb  ov021
 *   FIELD_PLAYER_ResetNogrid  0x021A368C  thumb  ov021
 *   FIELD_PLAYER_IsNogridForcedMove  0x021A3698  thumb  ov021
 *   FIELD_PLAYER_GetNogridRailWork  0x021A36A4  thumb  ov021
 */
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"

#include "../types.h"

struct FieldPlayer;
struct FieldNogridMapper;
struct FieldG3dMapper;
struct FieldCamera;
struct RailManager;
struct Mmdl;

/* Which movement system the player uses right now. */
enum {
    FIELDMAP_CTRL_HYBRID_MODE_GRID,     /* walks on the tile grid */
    FIELDMAP_CTRL_HYBRID_MODE_NOGRID,   /* moves along the rails */
    FIELDMAP_CTRL_HYBRID_MODE_NONE      /* not placed yet (right after the allocation) */
};

/* The hybrid map control work (12 bytes), kept in FieldMap.ctrlWork. */
typedef struct FieldMapCtrlHybridWork {
    int mode;                       /* 0x00 FIELDMAP_CTRL_HYBRID_MODE_* */
    struct FieldPlayer *player;     /* 0x04 */
    u32 stepActive;                 /* 0x08: result of the last nogrid step start, 0 after a mode switch */
} FieldMapCtrlHybridWork;

/* Parameter block that FLDMMDL_ChangeHeader applies to a field model. */
typedef struct FieldMapCtrlHybridModelParam {
    u8 kind;            /* 0x00 */
    u8 flags;           /* 0x01 */
    u16 objCode;        /* 0x02: refreshed from the model on every switch to grid mode */
} FieldMapCtrlHybridModelParam;

/*
 * One static record: the per-mode update functions (indexed by the work's
 * mode), then the model parameter block.
 */
typedef struct FieldMapCtrlHybridModeTable {
    void (*update[2])(FieldMap *fieldMap, FieldMapCtrlHybridWork *work);    /* 0x00 */
    FieldMapCtrlHybridModelParam modelParam;                                /* 0x08 */
} FieldMapCtrlHybridModeTable;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/key.h"
#include "field_player.h"
#include "fieldmap.h"
struct FieldMap;
struct GameSystem;
struct GameData;
#include "../arm9/gamesystem.h"
struct PlayerWork;
#include "../arm9/game_data.h"
#include "../arm9/zonedata.h"
#include "../ov010/fldmmdl_move.h"
#include "../ov010/fldmmdl.h"
struct VecFx32;
struct MmdlHeader;
#include "field_camera.h"
#include "fldmmdl_draw.h"
#include "map_attr.h"
#include "field_rail.h"
#include "rail_attr.h"
struct RailWork;
#include "field_nogrid_mapper.h"
extern char gFieldMapCtrlHybridFileName;
extern FieldMapCtrlHybridModeTable gFieldMapCtrlHybridModeTable;

u32 FIELDMAP_CTRL_HYBRID_GetMode(FieldMapCtrlHybridWork *work);
void FIELDMAP_CTRL_HYBRID_ReplacePlayer(FieldMapCtrlHybridWork *work, FieldMap *fieldMap);
void FIELDMAP_CTRL_HYBRID_Create(FieldMap *fieldMap, VecFx32 *pos, u16 dir);
void FIELDMAP_CTRL_HYBRID_Destroy(FieldMap *fieldMap);
void FIELDMAP_CTRL_HYBRID_Main(FieldMap *fieldMap, VecFx32 *pos);
VecFx32 *FIELDMAP_CTRL_HYBRID_GetTargetPos(FieldMap *fieldMap);
void FIELDMAP_CTRL_HYBRID_UpdateGrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work);
void FIELDMAP_CTRL_HYBRID_UpdateNogrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work);
void FIELDMAP_CTRL_HYBRID_SwitchToNogrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, RailLocation *railLocation, u32 keyTrg, u32 keyCont);
void FIELDMAP_CTRL_HYBRID_SwitchToGrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, VecFx32 *gridPos, u32 keyTrg, u32 keyCont);
int FIELDMAP_CTRL_HYBRID_FindGridPos(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, VecFx32 *outPos, u32 dir);
int FIELDMAP_CTRL_HYBRID_FindRailLocation(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, RailLocation *outLocation, u32 dir);
void FIELDMAP_CTRL_HYBRID_SetMode(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, int mode, const void *place, u16 dir, u16 blactAnime, u16 blactFrame);

/* Current movement system of the work. */
u32 FIELDMAP_CTRL_HYBRID_GetMode(FieldMapCtrlHybridWork *work)
{
    return work->mode;
}

/*
 * Re-places the player in the movement system it stands in, from the
 * model's current direction (mode 0: grid to rail, else rail to grid).
 */
void FIELDMAP_CTRL_HYBRID_ReplacePlayer(FieldMapCtrlHybridWork *work, FieldMap *fieldMap)
{
    VecFx32 gridPos;
    RailLocation railLocation;
    u16 dir = FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(work->player));

    if (work->mode == 0) {
        if (FIELDMAP_CTRL_HYBRID_FindRailLocation(fieldMap, work, &railLocation, dir) != 0) {
            FIELDMAP_CTRL_HYBRID_SwitchToNogrid(fieldMap, work, dir, 0, &railLocation, 0, 0);
        }
    } else {
        if (FIELDMAP_CTRL_HYBRID_FindGridPos(fieldMap, work, &gridPos, dir) != 0) {
            FIELDMAP_CTRL_HYBRID_SwitchToGrid(fieldMap, work, dir, 0, &gridPos, 0, 0);
        }
    }
    work->stepActive = 0;
}

/*
 * Create slot: allocates the 12-byte work, creates the player in the
 * movement system the save data records (0: grid, else rail) and places it
 * through FIELDMAP_CTRL_HYBRID_SetMode (grid: at pos, rail: at the saved rail location).
 */
void FIELDMAP_CTRL_HYBRID_Create(FieldMap *fieldMap, VecFx32 *pos, u16 dir)
{
    void *saveRecord;
    u16 heapId;
    FieldMapCtrlHybridWork *work;
    int mode;
    struct Mmdl *mmdl;
    void *savedLocation;
    u16 blactAnime[2];

    saveRecord = GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    heapId = FIELDMAP_GetHeapId(fieldMap);
    work = GFL_HEAP_Alloc(heapId, sizeof(FieldMapCtrlHybridWork), 1, &gFieldMapCtrlHybridFileName, 0xbd);
    FIELDMAP_SetCtrlWork(fieldMap, work);
    work->player = FIELDMAP_GetFieldPlayer(fieldMap);
    mode = GAME_DATA_GetPlayerMoveForm(saveRecord);
    work->mode = FIELDMAP_CTRL_HYBRID_MODE_NONE;
    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    FLDMMDL_DRAW_GetBlactAnime(mmdl, &blactAnime[0], &blactAnime[1]);
    if (mode == 0) {
        FIELD_PLAYER_CreateGrid(work->player, heapId);
        FIELD_PLAYER_CreateNogrid(work->player, heapId);
        FIELD_PLAYER_SetDirDisp(work->player, dir);
        FIELDMAP_CTRL_HYBRID_SetMode(fieldMap, work, mode, pos, dir, blactAnime[0], blactAnime[1]);
    } else {
        savedLocation = GAME_DATA_GetPlayerRail(saveRecord);
        FIELD_PLAYER_CreateNogrid(work->player, heapId);
        FIELD_PLAYER_CreateGrid(work->player, heapId);
        FIELD_PLAYER_SetDirDisp(work->player, dir);
        FIELDMAP_CTRL_HYBRID_SetMode(fieldMap, work, mode, savedLocation, dir, blactAnime[0], blactAnime[1]);
    }
    FIELDMAP_SetTargetPos(fieldMap, FLDMMDL_GetPosPtr(mmdl));
    FIELD_PLAYER_GetPos(work->player, pos);
}

/* Destroy slot: frees the work. */
void FIELDMAP_CTRL_HYBRID_Destroy(FieldMap *fieldMap)
{
    GFL_HEAP_Free(FIELDMAP_GetCtrlWork(fieldMap));
}

/* Main slot: runs the update of the current mode, then reads back the player position. */
void FIELDMAP_CTRL_HYBRID_Main(FieldMap *fieldMap, VecFx32 *pos)
{
    FieldMapCtrlHybridWork *work = FIELDMAP_GetCtrlWork(fieldMap);

    gFieldMapCtrlHybridModeTable.update[work->mode](fieldMap, work);
    FIELD_PLAYER_GetPos(work->player, pos);
}

/* Position of the player's model, the point the camera follows. */
VecFx32 *FIELDMAP_CTRL_HYBRID_GetTargetPos(FieldMap *fieldMap)
{
    return FLDMMDL_GetPosPtr(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)));
}

/*
 * Update in grid mode: when the player stands on a rail entry tile and the
 * tile ahead allows it, switches to the rails, else walks with the keys.
 */
void FIELDMAP_CTRL_HYBRID_UpdateGrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work)
{
    RailLocation railLocation;
    u32 aheadAttr;
    u32 standAttr;
    struct Mmdl *mmdl;
    u32 keyTrg;
    u32 keyCont;
    u32 flags;
    u16 dir;

    keyTrg = KEY_GetTrg();
    keyCont = KEY_GetCont();
    flags = 0;
    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    dir = FIELD_PLAYER_ChooseMoveDirFromKeys(work->player, keyCont);
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1 || FIELD_PLAYER_CheckMoveBusy(work->player) == 1) {
        if (dir != 9) {
            standAttr = FIELD_PLAYER_GetNowAttribute(work->player);
            aheadAttr = FIELD_PLAYER_GetFrontAttribute(work->player, dir);
            if (RAIL_ATTR_IsJumpStart(MAP_ATTR_GetTerrainId(standAttr)) != 0) {
                if (MAP_ATTR_IsBlocked(aheadAttr) != 0) {
                    if (FIELDMAP_CTRL_HYBRID_FindRailLocation(fieldMap, work, &railLocation, dir) != 0) {
                        FIELDMAP_CTRL_HYBRID_SwitchToNogrid(fieldMap, work, dir, 1, &railLocation, keyTrg, keyCont);
                        return;
                    }
                }
            }
        }
    }
    if (FIELD_PLAYER_CheckMoveRestrictFlag(work->player) == 1)
        flags |= 1;
    FIELD_PLAYER_MoveGrid(work->player, keyTrg, keyCont, flags);
}

/*
 * Update in nogrid mode: when the player is on a rail tile and the tile
 * ahead allows it, switches back to the grid, else moves along the rails.
 */
void FIELDMAP_CTRL_HYBRID_UpdateNogrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work)
{
    VecFx32 gridPos;
    u32 aheadAttr;
    u32 standAttr;
    u32 keyTrg;
    struct Mmdl *mmdl;
    u32 keyCont;
    u32 useDir;
    u16 dir;

    keyTrg = KEY_GetTrg();
    keyCont = KEY_GetCont();
    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    if (work->stepActive == 0) {
        dir = FIELD_PLAYER_ChooseMoveDirFromKeys(work->player, keyCont);
        useDir = 1;
    } else {
        dir = FLDMMDL_GetDirMove(mmdl);
        useDir = 0;
    }
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1 || FIELD_PLAYER_CheckMoveBusy(work->player) == 1) {
        if (dir != 9) {
            standAttr = FIELD_PLAYER_GetNowAttribute(work->player);
            aheadAttr = FIELD_PLAYER_GetFrontAttribute(work->player, dir);
            if (RAIL_ATTR_IsJumpStart(MAP_ATTR_GetTerrainId(standAttr)) != 0) {
                if (MAP_ATTR_IsBlocked(aheadAttr) != 0) {
                    if (FIELDMAP_CTRL_HYBRID_FindGridPos(fieldMap, work, &gridPos, dir) != 0) {
                        FIELDMAP_CTRL_HYBRID_SwitchToGrid(fieldMap, work, dir, useDir, &gridPos, keyTrg, keyCont);
                        work->stepActive = 0;
                        return;
                    }
                }
            }
        }
    }
    work->stepActive = FIELD_PLAYER_IsNogridForcedMove(work->player);
    FIELD_PLAYER_UpdateNogrid(work->player, keyTrg, keyCont);
}

/* Switches from grid to rail mode at railLocation, then starts a rail step with the keys. */
void FIELDMAP_CTRL_HYBRID_SwitchToNogrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, RailLocation *railLocation, u32 keyTrg, u32 keyCont)
{
    u16 blactAnime[2];
    struct Mmdl *mmdl;

    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    FLDMMDL_DRAW_GetBlactAnime(mmdl, &blactAnime[0], &blactAnime[1]);
    FIELD_PLAYER_MoveGrid(work->player, 0, 0, 0);
    if (useDir == 0)
        dir = FLDMMDL_GetDirDisp(mmdl);
    FIELDMAP_CTRL_HYBRID_SetMode(fieldMap, work, 1, railLocation, dir, blactAnime[0], blactAnime[1]);
    FIELD_PLAYER_UpdateNogrid(work->player, keyTrg, keyCont);
}

/* Switches from rail to grid mode at gridPos, then starts a grid step with the keys. */
void FIELDMAP_CTRL_HYBRID_SwitchToGrid(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, VecFx32 *gridPos, u32 keyTrg, u32 keyCont)
{
    u16 blactAnime[2];
    struct Mmdl *mmdl;
    u32 flags;

    flags = 0;
    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    FLDMMDL_DRAW_GetBlactAnime(mmdl, &blactAnime[0], &blactAnime[1]);
    FIELD_PLAYER_UpdateNogrid(work->player, 0, 0);
    if (useDir == 0)
        dir = FLDMMDL_GetDirDisp(mmdl);
    FIELDMAP_CTRL_HYBRID_SetMode(fieldMap, work, 0, gridPos, dir, blactAnime[0], blactAnime[1]);
    if (FIELD_PLAYER_CheckMoveRestrictFlag(work->player) == 1)
        flags |= 1;
    FIELD_PLAYER_MoveGrid(work->player, keyTrg, keyCont, flags);
}

/*
 * Finds the grid position the player would step to one tile ahead in dir
 * and returns 1 when the map attribute there allows it.
 */
int FIELDMAP_CTRL_HYBRID_FindGridPos(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, VecFx32 *outPos, u32 dir)
{
    struct FieldG3dMapper *g3dMapper;
    VecFx32 aheadPos;

    g3dMapper = FIELDMAP_GetG3dMapper(fieldMap);
    FIELD_PLAYER_GetPos(work->player, outPos);
    aheadPos = *outPos;
    FLDMMDL_MOVE_AddDirVector(dir, &aheadPos, 0x10000);
    if (MAP_ATTR_IsBlocked(MAP_ATTR_GetAt(g3dMapper, &aheadPos)) == 0)
        return 1;
    return 0;
}

/*
 * Looks for the rail line under the player (a vertical segment around its
 * position) and returns its location in outLocation. The function has no
 * return statement: the callers test the r0 that FIELD_RAIL_FindSegmentLocation or
 * FIELD_RAIL_TryStepLocation left behind.
 */
int FIELDMAP_CTRL_HYBRID_FindRailLocation(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, RailLocation *outLocation, u32 dir)
{
    VecFx32 hitPos;
    VecFx32 segBottom;
    VecFx32 segTop;
    u16 locations[8];   /* [0..3]: stepped location (unused), [4..7]: hit location */
    struct RailManager *railManager;
    u16 *outWords = (u16 *)outLocation;
    int ret;

    railManager = FIELD_NOGRID_MAPPER_GetRailMan(FIELDMAP_GetNogridMapper(fieldMap));
    FIELD_PLAYER_GetPos(work->player, &segBottom);
    segTop.x = segBottom.x;
    segTop.y = segBottom.y + 0x4000;
    segTop.z = segBottom.z;
    segBottom.y = segBottom.y - 0x4000;
    ret = FIELD_RAIL_FindSegmentLocation(railManager, &segBottom, &segTop, (RailLocation *)&locations[4], &hitPos);
    if (ret != 0)
        ret = FIELD_RAIL_TryStepLocation(railManager, (RailLocation *)&locations[4], ZONEDATA_DirToRailKey(dir), (RailLocation *)locations);
    outWords[0] = locations[4];
    outWords[1] = locations[5];
    outWords[2] = locations[6];
    outWords[3] = locations[7];
    return ret;
}

/*
 * Moves the player model between the two movement systems. mode 0: grid
 * (place points at a VecFx32, copied in; the model gets a tile position and
 * the camera follows again); else rail (place points at a RailLocation).
 * Does nothing when the work is already in that mode. gFieldMapCtrlHybridModeTable is one
 * static record: the per-mode updates, then the parameter block that
 * FLDMMDL_ChangeHeader takes, whose objCode is refreshed here (docs/idioms/
 * pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 */
void FIELDMAP_CTRL_HYBRID_SetMode(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, int mode, const void *place, u16 dir, u16 blactAnime, u16 blactFrame)
{
    struct FieldNogridMapper *nogridMapper;
    struct FieldCamera *camera;
    struct Mmdl *mmdl;
    VecFx32 pos;

    nogridMapper = FIELDMAP_GetNogridMapper(fieldMap);
    camera = FIELDMAP_GetCamera(fieldMap);
    if (work->mode == mode) {
        return;
    }
    mmdl = FIELD_PLAYER_GetMmdl(work->player);
    if (FLDMMDL_CheckMoveBitAcmd(mmdl) != 0) {
        FLDMMDL_FreeAcmd(mmdl);
    }
    if (mode == 0) {
        pos = *(const VecFx32 *)place;
        gFieldMapCtrlHybridModeTable.modelParam.objCode = FLDMMDL_GetObjCode(mmdl);
        FIELD_PLAYER_ResetNogrid(work->player);
        FLDMMDL_ChangeHeader(mmdl, (struct MmdlHeader *)(&gFieldMapCtrlHybridModeTable.modelParam));
        FLDMMDL_InitGridPosition(mmdl, (s16)((pos.x >> 12) / 16), (s16)((pos.y >> 12) / 16), (s16)((pos.z >> 12) / 16), dir);
        FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&pos));
        FIELD_PLAYER_SetPos(work->player, &pos);
        FIELD_NOGRID_MAPPER_UnbindCameraWork(nogridMapper);
        FIELD_CAMERA_SetMode(camera, 0);
        FIELD_CAMERA_ResumeTargetTrace(camera);
        FIELD_CAMERA_ReloadSetting(camera);
    } else {
        FIELD_PLAYER_AttachNogridMmdl(work->player, (sptr)place);
        FIELD_NOGRID_MAPPER_BindCameraWork(nogridMapper, (struct RailWork *)(FIELD_PLAYER_GetNogridRailWork(work->player)));
        FIELD_CAMERA_RestartDelay(camera);
    }
    FLDMMDL_SetDirDispCheckPause(mmdl, dir);
    FLDMMDL_SetDirMove(mmdl, dir);
    FLDMMDL_DRAW_SetBlactAnime(mmdl, blactAnime, blactFrame);
    work->mode = mode;
}
