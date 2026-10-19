/*
 * file:     field_player_grid.c
 * unit:     yes
 * function: FIELD_PLAYER_GRID_Create, FIELD_PLAYER_GRID_Delete, FIELD_PLAYER_GRID_Move, FIELD_PLAYER_GRID_BeginMove, FIELD_PLAYER_GRID_CanStartMove, FIELD_PLAYER_GRID_PlayTileSound, FIELD_PLAYER_GRID_PlayStepSound, FIELD_PLAYER_GRID_GetMoveResult, FIELD_PLAYER_GRID_GetDirChangeKind, FIELD_PLAYER_GRID_CheckCoreAction, FIELD_PLAYER_GRID_GetMoveResultOnFoot, FIELD_PLAYER_GRID_GetStandResultOnFoot, FIELD_PLAYER_GRID_GetWalkResultOnFoot, FIELD_PLAYER_GRID_GetTurnResultOnFoot, FIELD_PLAYER_GRID_GetBlockedResultOnFoot, FIELD_PLAYER_GRID_GetMoveResultOnFootHop, FIELD_PLAYER_GRID_GetStandResultOnFootHop, FIELD_PLAYER_GRID_GetWalkResultOnFootHop, FIELD_PLAYER_GRID_GetHoldResultOnFootHop, FIELD_PLAYER_GRID_GetHopAirResult, FIELD_PLAYER_GRID_GetHopFallResult, FIELD_PLAYER_GRID_GetMoveResultOnCycle, FIELD_PLAYER_GRID_GetStandResultOnCycle, FIELD_PLAYER_GRID_IsTileBlockingCycle, FIELD_PLAYER_GRID_GetWalkResultOnCycle, FIELD_PLAYER_GRID_GetTurnResultOnCycle, FIELD_PLAYER_GRID_GetBlockedResultOnCycle, FIELD_PLAYER_GRID_GetMoveResultOnSurf, FIELD_PLAYER_GRID_GetStandResultOnSurf, FIELD_PLAYER_GRID_GetWalkResultOnSurf, FIELD_PLAYER_GRID_GetTurnResultOnSurf, FIELD_PLAYER_GRID_GetBlockedResultOnSurf, FIELD_PLAYER_GRID_ApplyMoveResult, FIELD_PLAYER_GRID_ApplyMoveResultOnFoot, FIELD_PLAYER_GRID_ApplyNoneOnFoot, FIELD_PLAYER_GRID_StartStandOnFoot, FIELD_PLAYER_GRID_StartWalkOnFoot, FIELD_PLAYER_GRID_StartTurnOnFoot, FIELD_PLAYER_GRID_StartBlockedOnFoot, FIELD_PLAYER_GRID_StartLedgeJumpOnFoot, FIELD_PLAYER_GRID_StartHoldOnFoot, FIELD_PLAYER_GRID_StartHopOnFoot, FIELD_PLAYER_GRID_StartHopAirOnFoot, FIELD_PLAYER_GRID_StartHopFallOnFoot, FIELD_PLAYER_GRID_ApplyMoveResultOnCycle, FIELD_PLAYER_GRID_ApplyNoneOnCycle, FIELD_PLAYER_GRID_StartStandOnCycle, FIELD_PLAYER_GRID_StartWalkOnCycle, FIELD_PLAYER_GRID_StartTurnOnCycle, FIELD_PLAYER_GRID_StartBlockedOnCycle, FIELD_PLAYER_GRID_StartLedgeJumpOnCycle, FIELD_PLAYER_GRID_ApplyMoveResultOnSurf, FIELD_PLAYER_GRID_ApplyNoneOnSurf, FIELD_PLAYER_GRID_StartStandOnSurf, FIELD_PLAYER_GRID_StartWalkOnSurf, FIELD_PLAYER_GRID_StartTurnOnSurf, FIELD_PLAYER_GRID_StartBlockedOnSurf, FIELD_PLAYER_GRID_GetStepHitFlags, FIELD_PLAYER_GRID_SetFlag, FIELD_PLAYER_GRID_ClearFlag, FIELD_PLAYER_GRID_HasFlag, FIELD_PLAYER_GRID_SetForcedMoveFlag, FIELD_PLAYER_GRID_ClearForcedMoveFlag, FIELD_PLAYER_GRID_IsForcedMoveFlagSet, FIELD_PLAYER_GRID_SetNoForcedMoveFlag, FIELD_PLAYER_GRID_ClearNoForcedMoveFlag, FIELD_PLAYER_GRID_ClearStepPendingFlag, FIELD_PLAYER_GRID_SetHoldFlag, FIELD_PLAYER_GRID_IsHoldFlagSet, FIELD_PLAYER_GRID_SetHopFlag, FIELD_PLAYER_GRID_IsHopFlagSet, FIELD_PLAYER_GRID_ResetBlockedPose, FIELD_PLAYER_GRID_StopTurnOrBlocked, FIELD_PLAYER_GRID_CheckForcedMoveTile, FIELD_PLAYER_GRID_IsOnForcedMoveTile, FIELD_PLAYER_GRID_IsHopping, FIELD_PLAYER_GRID_FinishHop, FIELD_PLAYER_GRID_ReleaseForcedMove, FIELD_PLAYER_GRID_RunNoForcedMove, FIELD_PLAYER_GRID_StartForcedMove, FIELD_PLAYER_GRID_RunForcedMove, FIELD_PLAYER_GRID_IsHopTileKind, FIELD_PLAYER_GRID_IsHopStartTileKind, FIELD_PLAYER_GRID_IsOnHopStartTile, FIELD_PLAYER_GRID_FindHopDir, FIELD_PLAYER_GRID_GetHopStepHitFlags, FIELD_PLAYER_GRID_IsAtGroundHeight, FIELD_PLAYER_GRID_StartHold, FIELD_PLAYER_GRID_EndHold, FIELD_PLAYER_GRID_GetCore, FIELD_PLAYER_GRID_GetMmdl, FIELD_PLAYER_GRID_ResetHold, FIELD_PLAYER_GRID_StopForcedMove, FIELD_PLAYER_GRID_GetHopLanded, FIELD_PLAYER_GRID_SetHopLanded, FIELD_PLAYER_GRID_IsBlocked, FIELD_PLAYER_GRID_GetAttrAtDir, FIELD_PLAYER_GRID_GetHeightStep, FIELD_PLAYER_GRID_CheckMapConnectAhead
 * address:  0x021A4140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A41A0 (sFieldPlayerGridFile "field_player_grid.c"); 021A4140 is the grid constructor.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   sFieldPlayerGridFile     0x021DDECC  data  ov021  a4
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   gFieldPlayerGridAttrSounds     0x021D8A00  data  ov021  a4
 *   gFieldPlayerGridAttrSoundsAhead     0x021D8A0C  data  ov021  a4
 *   gFieldPlayerGridCallbackSounds     0x021D89F4  data  ov021  a4
 *   gFieldPlayerGridCallbackSoundsAhead     0x021D8A2C  data  a4
 *   COMM_PLAYER_SUPPORT_GetInfoCode  0x0202E83C  thumb
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   MAP_ATTR_IsLedgeNorth  0x021AB158  thumb  ov021
 *   MAP_ATTR_IsLedgeSouth  0x021AB164  thumb  ov021
 *   MAP_ATTR_IsLedgeWest  0x021AB170  thumb  ov021
 *   MAP_ATTR_IsLedgeEast  0x021AB17C  thumb  ov021
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_DRAW_SyncFrameGroup  0x0219F7CC  thumb  ov021
 *   MAP_ATTR_IsTallGrass  0x021AB140  thumb  ov021
 *   MAP_ATTR_IsDeepSand  0x021AB404  thumb  ov021
 *   MAP_ATTR_IsDeepSandB  0x021AB410  thumb  ov021
 *   MAP_ATTR_IsDeepSnow  0x021AB328  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   MAP_ATTR_IsNoDash  0x021AB44C  thumb  ov021
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetMoveBitShadowVanish  0x0216DCE8  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   MAP_ATTR_IsSand  0x021AB41C  thumb  ov021
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   FLDMMDL_MOVE_HitCheckMoveCurrent  0x02163994  thumb  ov010
 *   MAP_ATTR_IsHole  0x021AB2DC  thumb  ov021
 *   FLDMMDL_CheckMovedPosAtMapPos  0x0216E5B0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   MAP_ATTR_IsForcedSlide  0x021AB348  thumb  ov021
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   FLDMMDL_MOVE_UpdateMapAttr  0x021640B0  thumb  ov010
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   gFieldPlayerGridForcedMoveFuncs  0x021D89EC  data  a4
 *   gFieldPlayerGridNextHopDirs  0x021D8A24  data  a2
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_SearchConnectIdByGridPos  0x02162564  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_IsConnectExitDir  0x021626B8  thumb  ov010
 *   FIELD_PLAYER_CORE_GetPos  0x021A3898  thumb  ov021
 *   FIELD_PLAYER_CORE_GetDirDisp  0x021A3920  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFieldMap  0x021A395C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_CORE_ApplyFormCodeModel  0x021A3998  thumb  ov021
 *   FIELD_PLAYER_CORE_SetFormSlotModel  0x021A39AC  thumb  ov021
 *   FIELD_PLAYER_CORE_CheckFormModel  0x021A3A20  thumb  ov021
 *   FIELD_PLAYER_CORE_CheckAcmdPossible  0x021A3AA0  thumb  ov021
 *   FIELD_PLAYER_CORE_ChooseMoveDirFromKeys  0x021A3AB8  thumb  ov021
 *   FIELD_PLAYER_CORE_RememberKeyDirs  0x021A3AC4  thumb  ov021
 *   FIELD_PLAYER_CORE_StartFormChange  0x021A3CB0  thumb  ov021
 *   FIELD_PLAYER_CORE_StepFormChange  0x021A3CC0  thumb  ov021
 *   FIELD_PLAYER_CORE_FinishFormChange  0x021A3CE8  thumb  ov021
 */
#include "field_player_grid_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;

/* Animation command bases for FLDMMDL_ACMD_ConvertCodeByDir(dir, base). */
#define FIELD_PLAYER_GRID_ACMD_STAND            0x00
#define FIELD_PLAYER_GRID_ACMD_WALK             0x0C
#define FIELD_PLAYER_GRID_ACMD_RUN              0x10
#define FIELD_PLAYER_GRID_ACMD_DASH             0x14
#define FIELD_PLAYER_GRID_ACMD_BLOCKED          0x1C
#define FIELD_PLAYER_GRID_ACMD_TURN             0x24
#define FIELD_PLAYER_GRID_ACMD_HOP              0x34
#define FIELD_PLAYER_GRID_ACMD_LEDGE_JUMP       0x38
#define FIELD_PLAYER_GRID_ACMD_RUN_SLOPE_UP     0x4C
#define FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL      0x58
#define FIELD_PLAYER_GRID_ACMD_CYCLE_SPECIAL    0x9B
#define FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL_SLOPE_UP 0xA3
#define FIELD_PLAYER_GRID_ACMD_WALK_SLOPE_UP    0xA7

#define FIELD_PLAYER_GRID_SE_BLOCKED            0x55A
#define FIELD_PLAYER_GRID_SE_LEDGE_JUMP         0x55E

/* Status bits the forced move sets on the model: pause direction and bit 4. */
#define FIELD_PLAYER_GRID_MMDL_PAUSE_BITS       (MMDL_STABIT_PAUSE_DIR | 0x0010)
#define FIELD_PLAYER_GRID_MMDL_STEP_END_BITS    (MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_JUMP_END)

/* Step kind the core stores (FieldPlayerCore.stepKind). */
#define FIELD_PLAYER_GRID_STEP_KIND_NONE        0
#define FIELD_PLAYER_GRID_STEP_KIND_WALK        1
#define FIELD_PLAYER_GRID_STEP_KIND_RUN         2

/* Tile sound by attribute mask (gFieldPlayerGridAttrSounds, gFieldPlayerGridAttrSoundsAhead). */
typedef struct FieldPlayerGridAttrSound {
    u32 attrMask;
    int soundId;
    s16 repeatWalk;         /* frames between repeats, on foot */
    s16 repeatCycle;        /* the same while cycling */
} FieldPlayerGridAttrSound;

/* Tile sound by attribute predicate (gFieldPlayerGridCallbackSounds, gFieldPlayerGridCallbackSoundsAhead). */
typedef struct FieldPlayerGridCallbackSound {
    int (*isTile)(u16 attrKind);
    u16 soundId;
    s8 repeatWalk;
    s8 repeatCycle;
    u8 season;              /* 4 for every season */
} FieldPlayerGridCallbackSound;

typedef int (*FieldPlayerGridForcedMoveFunc)(FieldPlayerGrid *grid, int dir);

extern u32 GFL_HEAP_Free(void *memory);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void GFL_USE_PlaySeDefaultVolume(u32 soundId);
extern void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int dir);
extern void FLDMMDL_GetPos(Mmdl *mmdl, VecFx32 *out);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern u16 FLDMMDL_GetGridNowX(Mmdl *mmdl);
extern u16 FLDMMDL_GetGridNowY(Mmdl *mmdl);
extern u16 FLDMMDL_GetGridNowZ(Mmdl *mmdl);
extern int FLDMMDL_MOVE_GetDirAddGridX(int dir);
extern int FLDMMDL_MOVE_GetDirAddGridZ(int dir);
extern int MAP_ATTR_IsBlocked(u32 attr);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern void *GAMESYSTEM_GetGameData(void *gameSystem);
extern void *FIELDMAP_GetGameSystem(FieldMap *fieldMap);
extern void FLDMMDL_SetGridNowY(Mmdl *mmdl, int y);
extern void FLDMMDL_SetPos(Mmdl *mmdl, const VecFx32 *pos);
extern int FLDMMDL_CheckPossibleAcmd(Mmdl *mmdl);
extern MmdlSys *FLDMMDL_GetMmdlSys(Mmdl *mmdl);
extern u16 FLDMMDL_GetDirMove(Mmdl *mmdl);
extern void *FIELDMAP_GetEffect(FieldMap *fieldMap);
extern int FLDMMDL_MOVE_GetMapAttr(Mmdl *mmdl, VecFx32 *pos, int *outAttr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int COMM_PLAYER_SUPPORT_GetInfoCode(void *gameSystem);
extern void FLDMMDL_MOVE_AddDirVector(int dir, VecFx32 *pos, int amount);
extern int MAP_ATTR_IsLedgeNorth(u16 attrKind);
extern int MAP_ATTR_IsLedgeSouth(u16 attrKind);
extern int MAP_ATTR_IsLedgeWest(u16 attrKind);
extern int MAP_ATTR_IsLedgeEast(u16 attrKind);
extern void FLDMMDL_FreeAcmd(Mmdl *mmdl);
extern int FLDMMDL_DRAW_SyncFrameGroup(Mmdl *mmdl, u32 frame);
extern int MAP_ATTR_IsTallGrass(int attrKind);
extern int MAP_ATTR_IsDeepSand(int attrKind);
extern int MAP_ATTR_IsDeepSandB(int attrKind);
extern int MAP_ATTR_IsDeepSnow(int attrKind);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int dir, int acmdBase);
extern void FLDMMDL_SetAcmd(Mmdl *mmdl, int acmd);
extern int MAP_ATTR_IsNoDash(u16 attrKind);
extern int FLDMMDL_SetStatusBitHeightGetOff(Mmdl *mmdl, int flag);
extern int FLDMMDL_SetMoveBitShadowVanish(Mmdl *mmdl, int flag);
extern void FLDMMDL_SetMoveBit(Mmdl *mmdl, u32 bits);
extern int FLDMMDL_MOVE_GetMapHeight(Mmdl *mmdl, VecFx32 *pos, int *outHeight);
extern void FLDMMDL_ClearMoveBit(Mmdl *mmdl, u32 bits);
extern int MAP_ATTR_IsSand(u16 attrKind);
extern void FLDEFF_KEMURI_Start(Mmdl *mmdl, void *effectCtrl);
extern int FLDMMDL_MOVE_HitCheckMoveCurrent(Mmdl *mmdl, int gridX, int gridY, int gridZ, u32 dir);
extern int MAP_ATTR_IsHole(u16 attrKind);
extern int FLDMMDL_CheckMovedPosAtMapPos(MmdlSys *mmdlSys, const VecFx32 *pos);
extern void FLDMMDL_SetDrawStatus(Mmdl *mmdl, u16 drawStatus);
extern u32 FLDMMDL_GetNowAttr(Mmdl *mmdl);
extern int MAP_ATTR_IsForcedSlide(u32 attrKind);
extern int FLDMMDL_MOVE_UpdateHeight(Mmdl *mmdl);
extern int FLDMMDL_MOVE_UpdateMapAttr(Mmdl *mmdl);
extern int FLDMMDL_MOVE_UpdateOldGridPos(Mmdl *mmdl);
extern void FLDMMDL_ClearStatusBit(Mmdl *mmdl, u32 bits);
extern void FLDMMDL_SetStatusBit(Mmdl *mmdl, u32 bits);
extern void *GAME_DATA_GetEventData(void *gameData);
extern int EVENTDATA_SYSTEM_SearchConnectIdByGridPos(void *eventData, const VecFx32 *pos);
extern void *EVENTDATA_SYSTEM_GetConnectData(void *eventData, unsigned index);
extern int EVENTDATA_SYSTEM_IsConnectExitDir(void *connect, int dir);
extern void FIELD_PLAYER_CORE_GetPos(FieldPlayerCore *core, VecFx32 *out);
extern u16 FIELD_PLAYER_CORE_GetDirDisp(FieldPlayerCore *core);
extern FieldMap *FIELD_PLAYER_CORE_GetFieldMap(FieldPlayerCore *core);
extern Mmdl *FIELD_PLAYER_CORE_GetMmdl(FieldPlayerCore *core);
extern void FIELD_PLAYER_CORE_SetStepKind(FieldPlayerCore *core, u32 form);
extern u32 FIELD_PLAYER_CORE_GetFormCode(FieldPlayerCore *core);
extern void FIELD_PLAYER_CORE_ApplyFormCodeModel(FieldPlayerCore *core);
extern void FIELD_PLAYER_CORE_SetFormSlotModel(FieldPlayerCore *core, int a);
extern int FIELD_PLAYER_CORE_CheckFormModel(FieldPlayerCore *core);
extern int FIELD_PLAYER_CORE_CheckAcmdPossible(FieldPlayerCore *core);
extern u16 FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(FieldPlayerCore *core, u32 keys);
extern void FIELD_PLAYER_CORE_RememberKeyDirs(FieldPlayerCore *core, u32 keys);
extern int FIELD_PLAYER_CORE_StartFormChange(FieldPlayerCore *core, u32 mask);
extern int FIELD_PLAYER_CORE_StepFormChange(FieldPlayerCore *core);
extern void FIELD_PLAYER_CORE_FinishFormChange(FieldPlayerCore *core);

FieldPlayerGrid *FIELD_PLAYER_GRID_Create(FieldPlayerCore *core, u32 heapId);
void FIELD_PLAYER_GRID_Delete(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_Move(FieldPlayerGrid *grid, u32 keyTrigger, u32 keyHeld, u32 dashAllowed);
void FIELD_PLAYER_GRID_BeginMove(FieldPlayerGrid *grid, int result, const FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_CanStartMove(FieldPlayerGrid *grid, u32 dir);
int FIELD_PLAYER_GRID_PlayTileSound(FieldPlayerGrid *grid, int unused, VecFx32 *pos, int lookAhead, int season);
void FIELD_PLAYER_GRID_PlayStepSound(FieldPlayerGrid *grid, int result, int dir);
int FIELD_PLAYER_GRID_GetMoveResult(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetDirChangeKind(FieldPlayerGrid *grid, int dir);
void FIELD_PLAYER_GRID_CheckCoreAction(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_GetMoveResultOnFoot(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetStandResultOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetWalkResultOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetTurnResultOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetBlockedResultOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetMoveResultOnFootHop(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetStandResultOnFootHop(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetWalkResultOnFootHop(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetHoldResultOnFootHop(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetHopAirResult(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetHopFallResult(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetMoveResultOnCycle(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetStandResultOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_IsTileBlockingCycle(int attrKind);
int FIELD_PLAYER_GRID_GetWalkResultOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetTurnResultOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetBlockedResultOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetMoveResultOnSurf(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetStandResultOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetWalkResultOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetTurnResultOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetBlockedResultOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_ApplyMoveResult(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_ApplyMoveResultOnFoot(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_ApplyNoneOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartStandOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartWalkOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartTurnOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartBlockedOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartLedgeJumpOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartHoldOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartHopOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartHopAirOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_StartHopFallOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_ApplyMoveResultOnCycle(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_ApplyNoneOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartStandOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartWalkOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartTurnOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartBlockedOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartLedgeJumpOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_ApplyMoveResultOnSurf(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_ApplyNoneOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartStandOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartWalkOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartTurnOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void FIELD_PLAYER_GRID_StartBlockedOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int FIELD_PLAYER_GRID_GetStepHitFlags(FieldPlayerGrid *grid, Mmdl *mmdl, u32 dir, int *outAttr);
void FIELD_PLAYER_GRID_SetFlag(FieldPlayerGrid *grid, u32 mask);
void FIELD_PLAYER_GRID_ClearFlag(FieldPlayerGrid *grid, u32 mask);
int FIELD_PLAYER_GRID_HasFlag(FieldPlayerGrid *grid, u32 mask);
void FIELD_PLAYER_GRID_SetForcedMoveFlag(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_ClearForcedMoveFlag(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_IsForcedMoveFlagSet(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_SetNoForcedMoveFlag(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_ClearNoForcedMoveFlag(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_ClearStepPendingFlag(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_SetHoldFlag(FieldPlayerGrid *grid, int on);
int FIELD_PLAYER_GRID_IsHoldFlagSet(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_SetHopFlag(FieldPlayerGrid *grid, int on);
int FIELD_PLAYER_GRID_IsHopFlagSet(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_ResetBlockedPose(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_StopTurnOrBlocked(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_CheckForcedMoveTile(FieldPlayerGrid *grid, int unused);
int FIELD_PLAYER_GRID_IsOnForcedMoveTile(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_IsHopping(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_FinishHop(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_ReleaseForcedMove(FieldPlayerGrid *grid);
u32 FIELD_PLAYER_GRID_RunNoForcedMove(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_StartForcedMove(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_RunForcedMove(FieldPlayerGrid *grid, u32 dir, int skip);
int FIELD_PLAYER_GRID_IsHopTileKind(int attrKind);
int FIELD_PLAYER_GRID_IsHopStartTileKind(int attrKind);
int FIELD_PLAYER_GRID_IsOnHopStartTile(FieldPlayerGrid *grid);
u32 FIELD_PLAYER_GRID_FindHopDir(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_GetHopStepHitFlags(FieldPlayerGrid *grid, Mmdl *mmdl, int dir, int *outAttr);
u32 FIELD_PLAYER_GRID_IsAtGroundHeight(FieldPlayerGrid *grid, u32 unused1, u32 unused2);
void FIELD_PLAYER_GRID_StartHold(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_EndHold(FieldPlayerGrid *grid);
FieldPlayerCore *FIELD_PLAYER_GRID_GetCore(FieldPlayerGrid *grid);
Mmdl *FIELD_PLAYER_GRID_GetMmdl(FieldPlayerGrid *grid);
void FIELD_PLAYER_GRID_ResetHold(FieldPlayerGrid *grid, int keepFrame);
void FIELD_PLAYER_GRID_StopForcedMove(FieldPlayerGrid *grid);
u32 FIELD_PLAYER_GRID_GetHopLanded(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_SetHopLanded(FieldPlayerGrid *grid, u32 landed);
int FIELD_PLAYER_GRID_IsBlocked(FieldPlayerGrid *grid);
int FIELD_PLAYER_GRID_GetAttrAtDir(FieldPlayerGrid *grid, int dir, int *outAttr);
int FIELD_PLAYER_GRID_GetHeightStep(FieldPlayerGrid *grid, int dir);
int FIELD_PLAYER_GRID_CheckMapConnectAhead(FieldPlayerGrid *grid, int dir);

extern u8 sFieldPlayerGridFile[];
extern FieldPlayerGridAttrSound gFieldPlayerGridAttrSounds[];
extern FieldPlayerGridAttrSound gFieldPlayerGridAttrSoundsAhead[];
extern FieldPlayerGridCallbackSound gFieldPlayerGridCallbackSounds[];
extern FieldPlayerGridCallbackSound gFieldPlayerGridCallbackSoundsAhead[];
extern FieldPlayerGridForcedMoveFunc const gFieldPlayerGridForcedMoveFuncs[];
extern const u16 gFieldPlayerGridNextHopDirs[4];

FieldPlayerGrid *FIELD_PLAYER_GRID_Create(FieldPlayerCore *core, u32 heapId)
{
    FieldPlayerGrid *grid;

    grid = GFL_HEAP_Alloc(heapId, 0x20, 1, (const char *)sFieldPlayerGridFile, 0x17D);
    grid->core = core;
    grid->fieldMap = FIELD_PLAYER_CORE_GetFieldMap(core);
    grid->soundId = FIELD_PLAYER_GRID_SOUND_NONE;
    FIELD_PLAYER_GRID_SetNoForcedMoveFlag(grid);
    switch (FIELD_PLAYER_CORE_GetFormCode(grid->core)) {
    case FIELD_PLAYER_AVATAR_FORM_SURF:
        FIELD_PLAYER_CORE_StartFormChange(grid->core, 4);
        FIELD_PLAYER_CORE_FinishFormChange(grid->core);
        break;
    case FIELD_PLAYER_AVATAR_FORM_DIVE:
        FIELD_PLAYER_CORE_StartFormChange(grid->core, 0x100);
        FIELD_PLAYER_CORE_FinishFormChange(grid->core);
        break;
    }
    return grid;
}


void FIELD_PLAYER_GRID_Delete(FieldPlayerGrid *grid)
{
    GFL_HEAP_Free(grid);
}


void FIELD_PLAYER_GRID_Move(FieldPlayerGrid *grid, u32 keyTrigger, u32 keyHeld, u32 dashAllowed)
{
    FieldPlayerGridMoveRequest request;
    u32 dir;
    int result;

    dir = FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(grid->core, keyHeld);
    if (FIELD_PLAYER_GRID_CanStartMove(grid, dir) == 1) {
        FIELD_PLAYER_CORE_StepFormChange(grid->core);
        if (FIELD_PLAYER_GRID_RunForcedMove(grid, dir, 0) == 0) {
            request.keyTrigger = keyTrigger;
            request.keyHeld = keyHeld;
            request.dir = dir;
            request.dashAllowed = dashAllowed;
            request.isDash = 0;
            result = FIELD_PLAYER_GRID_GetMoveResult(grid, &request);
            FIELD_PLAYER_GRID_BeginMove(grid, result, &request);
            FIELD_PLAYER_GRID_ApplyMoveResult(grid, result, &request);
            FIELD_PLAYER_GRID_PlayStepSound(grid, result, dir);
        }
    }
}


void FIELD_PLAYER_GRID_BeginMove(FieldPlayerGrid *grid, int result, const FieldPlayerGridMoveRequest *request)
{
    grid->lastResult = result;
    FIELD_PLAYER_CORE_RememberKeyDirs(grid->core, request->keyHeld);
    FIELD_PLAYER_GRID_ClearStepPendingFlag(grid);
    FIELD_PLAYER_GRID_ClearFlag(grid, FIELD_PLAYER_GRID_FLAG_SPECIAL_WALK);
    if (result == FIELD_PLAYER_GRID_RESULT_WALK)
        FIELD_PLAYER_GRID_ClearNoForcedMoveFlag(grid);
    grid->hopLanded = 0;
}


int FIELD_PLAYER_GRID_CanStartMove(FieldPlayerGrid *grid, u32 dir)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);

    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1)
        return 1;
    if (dir != FIELD_PLAYER_GRID_DIR_NONE && grid->state == FIELD_PLAYER_GRID_STATE_BLOCKED && dir != FLDMMDL_GetDirDisp(mmdl))
        return 1;
    return 0;
}


/*
 * Picks a tile sound from two 12-byte-record tables (attribute-mask table,
 * then predicate-callback table), 0x546 meaning none, and plays it with a
 * repeat counter. lookAhead selects the second table pair (the tile ahead).
 * gFieldPlayerGridCallbackSoundsAhead carries no ov021 token: with it the hint reads as contested.
 */
int FIELD_PLAYER_GRID_PlayTileSound(FieldPlayerGrid *grid, int unused, VecFx32 *pos, int lookAhead, int season)
{
    int repeatLimit;
    int soundId;
    int attr;
    int mode;
    FieldPlayerGridAttrSound *attrSound;
    FieldPlayerGridCallbackSound *callbackSound;
    u32 attrBits;

    soundId = FIELD_PLAYER_GRID_SOUND_NONE;
    repeatLimit = 0;
    mode = 0;
    if (FIELD_PLAYER_CORE_GetFormCode(grid->core) == FIELD_PLAYER_AVATAR_FORM_CYCLE) {
        mode = 2;
    } else if (FIELD_PLAYER_GRID_HasFlag(grid, FIELD_PLAYER_GRID_FLAG_SPECIAL_WALK) != 0) {
        mode = 1;
    }
    if (mode == 0) {
        grid->soundId = FIELD_PLAYER_GRID_SOUND_NONE;
        grid->soundRepeat = 0;
    }
    if (FLDMMDL_MOVE_GetMapAttr(FIELD_PLAYER_CORE_GetMmdl(grid->core), pos, &attr) == 1) {
        attrBits = MAP_ATTR_GetFlags(attr);
        if (lookAhead == 0) {
            attrSound = gFieldPlayerGridAttrSounds;
        } else {
            attrSound = gFieldPlayerGridAttrSoundsAhead;
        }
        for (; attrSound->attrMask != 0; attrSound++) {
            if (attrSound->attrMask & attrBits) {
                soundId = attrSound->soundId;
                if (mode == 1) {
                    repeatLimit = attrSound->repeatWalk;
                } else if (mode == 2) {
                    repeatLimit = attrSound->repeatCycle;
                }
                break;
            }
        }
        if (soundId == FIELD_PLAYER_GRID_SOUND_NONE) {
            callbackSound = gFieldPlayerGridCallbackSounds;
            if (lookAhead != 0) {
                callbackSound = gFieldPlayerGridCallbackSoundsAhead;
            }
            for (; callbackSound->isTile != 0; callbackSound++) {
                if (callbackSound->isTile((u16)attr) == 1 && (callbackSound->season == 4 || callbackSound->season == season)) {
                    soundId = callbackSound->soundId;
                    if (mode == 1) {
                        repeatLimit = callbackSound->repeatWalk;
                    } else if (mode == 2) {
                        repeatLimit = callbackSound->repeatCycle;
                    }
                    break;
                }
            }
        }
        if (soundId == FIELD_PLAYER_GRID_SOUND_NONE) {
            if (lookAhead == 1) {
                grid->soundRepeat = 0;
            }
        } else if (mode != 0) {
            if (grid->soundId != soundId) {
                grid->soundRepeat = 0;
            }
            if (grid->soundRepeat != 0 && grid->soundRepeat < repeatLimit) {
                soundId = FIELD_PLAYER_GRID_SOUND_NONE;
            }
            if (grid->soundRepeat >= repeatLimit) {
                grid->soundRepeat = 0;
            }
            grid->soundId = soundId;
            grid->soundRepeat = grid->soundRepeat + 1;
        }
        if (soundId != FIELD_PLAYER_GRID_SOUND_NONE) {
            GFL_USE_PlaySeDefaultVolume(soundId);
            return 1;
        }
    }
    return 0;
}


void FIELD_PLAYER_GRID_PlayStepSound(FieldPlayerGrid *grid, int result, int dir)
{
    VecFx32 pos;
    Mmdl *mmdl;
    u32 season;

    if (result != FIELD_PLAYER_GRID_RESULT_WALK) {
        grid->soundId = FIELD_PLAYER_GRID_SOUND_NONE;
        grid->soundRepeat = 0;
        return;
    }
    mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    season = COMM_PLAYER_SUPPORT_GetInfoCode(FIELDMAP_GetGameSystem(grid->fieldMap));
    FLDMMDL_GetPos(mmdl, &pos);
    if (FIELD_PLAYER_GRID_PlayTileSound(grid, result, &pos, 0, season) == 0) {
        FLDMMDL_MOVE_AddDirVector(dir, &pos, 0x10000);
        FIELD_PLAYER_GRID_PlayTileSound(grid, result, &pos, 1, season);
    }
}


int FIELD_PLAYER_GRID_GetMoveResult(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    int result;

    result = FIELD_PLAYER_GRID_RESULT_NONE;
    switch (FIELD_PLAYER_CORE_GetFormCode(grid->core)) {
    case FIELD_PLAYER_AVATAR_FORM_NORMAL:
        result = FIELD_PLAYER_GRID_GetMoveResultOnFoot(grid, request);
        break;
    case FIELD_PLAYER_AVATAR_FORM_CYCLE:
        result = FIELD_PLAYER_GRID_GetMoveResultOnCycle(grid, request);
        break;
    case FIELD_PLAYER_AVATAR_FORM_SURF:
    case FIELD_PLAYER_AVATAR_FORM_DIVE:
        result = FIELD_PLAYER_GRID_GetMoveResultOnSurf(grid, request);
        break;
    }
    return result;
}


int FIELD_PLAYER_GRID_GetDirChangeKind(FieldPlayerGrid *grid, int dir)
{
    int curDir = FLDMMDL_GetDirDisp(FIELD_PLAYER_CORE_GetMmdl(grid->core));

    if (dir == FIELD_PLAYER_GRID_DIR_NONE)
        return 0;
    if (dir != curDir && grid->state != FIELD_PLAYER_GRID_STATE_WALK && grid->state != FIELD_PLAYER_GRID_STATE_BLOCKED)
        return 2;
    return 1;
}


/* Tail-call thunk: the core's current action check. */
void FIELD_PLAYER_GRID_CheckCoreAction(FieldPlayerGrid *grid)
{
    FIELD_PLAYER_CORE_CheckAcmdPossible(grid->core);
}


int FIELD_PLAYER_GRID_GetMoveResultOnFoot(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl;
    int result;

    mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    result = FIELD_PLAYER_GRID_RESULT_NONE;
    if (FIELD_PLAYER_GRID_IsOnHopStartTile(grid) == 1 || FIELD_PLAYER_GRID_IsHopFlagSet(grid) == 1) {
        return FIELD_PLAYER_GRID_GetMoveResultOnFootHop(grid, request);
    }
    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        result = FIELD_PLAYER_GRID_GetStandResultOnFoot(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        result = FIELD_PLAYER_GRID_GetWalkResultOnFoot(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_TURN:
        result = FIELD_PLAYER_GRID_GetTurnResultOnFoot(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        result = FIELD_PLAYER_GRID_GetBlockedResultOnFoot(grid, mmdl, request);
        break;
    }
    return result;
}


int FIELD_PLAYER_GRID_GetStandResultOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
        if (request->dir != FIELD_PLAYER_GRID_DIR_NONE) {
            if (request->dir != FLDMMDL_GetDirDisp(mmdl) && request->isDash == 0) {
                if ((request->dashAllowed & 1) == 0) {
                    return FIELD_PLAYER_GRID_RESULT_TURN;
                }
                if ((2 & request->keyHeld) == 0) {
                    return FIELD_PLAYER_GRID_RESULT_TURN;
                }
            }
            return FIELD_PLAYER_GRID_GetWalkResultOnFoot(grid, mmdl, request);
        }
        return FIELD_PLAYER_GRID_RESULT_STAND;
    }
    return FIELD_PLAYER_GRID_RESULT_NONE;
}


/*
 * Twin of FIELD_PLAYER_GRID_GetWalkResultOnSurf with an extra tile-class check (ids
 * classed 0..3 by MAP_ATTR_IsLedgeNorth/164/170/17C) that returns 5.
 */
int FIELD_PLAYER_GRID_GetWalkResultOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 hitFlags;
    u16 attrKind;
    u32 attrBits;
    int ledgeDir;

    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return FIELD_PLAYER_GRID_GetStandResultOnFoot(grid, mmdl, request);
    }
    hitFlags = FIELD_PLAYER_GRID_GetStepHitFlags(grid, mmdl, request->dir, &attr);
    if (request->isDash == 1 && hitFlags != 0 && !(hitFlags & 0x10)) {
        hitFlags = 0;
    }
    if (attr != -1) {
        attrKind = MAP_ATTR_GetTerrainId(attr);
        attrBits = MAP_ATTR_GetFlags(attr);
        if (hitFlags & 2) {
            ledgeDir = FIELD_PLAYER_GRID_DIR_NONE;
            if (MAP_ATTR_IsLedgeNorth(attrKind)) {
                ledgeDir = 0;
            } else if (MAP_ATTR_IsLedgeSouth(attrKind)) {
                ledgeDir = 1;
            } else if (MAP_ATTR_IsLedgeWest(attrKind)) {
                ledgeDir = 2;
            } else if (MAP_ATTR_IsLedgeEast(attrKind)) {
                ledgeDir = 3;
            }
            if (ledgeDir != FIELD_PLAYER_GRID_DIR_NONE && ledgeDir == request->dir) {
                return FIELD_PLAYER_GRID_RESULT_LEDGE_JUMP;
            }
        }
        if (hitFlags == 0) {
            if (!(attrBits & 2)) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
            if (request->isDash == 1) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
        }
    }
    return FIELD_PLAYER_GRID_RESULT_BLOCKED;
}


int FIELD_PLAYER_GRID_GetTurnResultOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0)
        return FIELD_PLAYER_GRID_RESULT_NONE;
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE)
        return FIELD_PLAYER_GRID_GetStandResultOnFoot(grid, mmdl, request);
    return FIELD_PLAYER_GRID_GetWalkResultOnFoot(grid, mmdl, request);
}


int FIELD_PLAYER_GRID_GetBlockedResultOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    u32 curDir = FLDMMDL_GetDirDisp(mmdl);

    if (request->dir != FIELD_PLAYER_GRID_DIR_NONE && request->dir != curDir) {
        FLDMMDL_FreeAcmd(mmdl);
        return FIELD_PLAYER_GRID_GetWalkResultOnFoot(grid, mmdl, request);
    }
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return FIELD_PLAYER_GRID_GetStandResultOnFoot(grid, mmdl, request);
    }
    return FIELD_PLAYER_GRID_GetWalkResultOnFoot(grid, mmdl, request);
}


int FIELD_PLAYER_GRID_GetMoveResultOnFootHop(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    int result = FIELD_PLAYER_GRID_RESULT_NONE;

    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        result = FIELD_PLAYER_GRID_GetStandResultOnFootHop(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        result = FIELD_PLAYER_GRID_GetWalkResultOnFootHop(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_TURN:
        result = FIELD_PLAYER_GRID_GetTurnResultOnFoot(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        result = FIELD_PLAYER_GRID_GetBlockedResultOnFoot(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_HOLD:
        result = FIELD_PLAYER_GRID_GetHoldResultOnFootHop(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_HOP:
    case FIELD_PLAYER_GRID_STATE_HOP_AIR:
        result = FIELD_PLAYER_GRID_GetHopAirResult(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_HOP_FALL:
        result = FIELD_PLAYER_GRID_GetHopFallResult(grid, mmdl, request);
        break;
    }
    return result;
}


int FIELD_PLAYER_GRID_GetStandResultOnFootHop(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
        if (request->dir != FIELD_PLAYER_GRID_DIR_NONE) {
            u32 curDir = FLDMMDL_GetDirDisp(mmdl);
            if (request->dir != curDir && request->isDash == 0) {
                return FIELD_PLAYER_GRID_RESULT_TURN;
            }
            return FIELD_PLAYER_GRID_GetWalkResultOnFootHop(grid, mmdl, request);
        }
        return FIELD_PLAYER_GRID_GetHoldResultOnFootHop(grid, mmdl, request);
    }
    return FIELD_PLAYER_GRID_RESULT_NONE;
}


int FIELD_PLAYER_GRID_GetWalkResultOnFootHop(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 hitFlags;

    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return FIELD_PLAYER_GRID_GetStandResultOnFootHop(grid, mmdl, request);
    }
    hitFlags = FIELD_PLAYER_GRID_GetHopStepHitFlags(grid, mmdl, request->dir, &attr);
    if (attr != -1) {
        if (hitFlags & 0x100) {
            if (!(hitFlags & 0xFFFFFEFF)) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
        } else if (MAP_ATTR_IsBlocked(attr) == 0) {
            FIELD_PLAYER_GRID_SetHopFlag(grid, 1);
            return FIELD_PLAYER_GRID_RESULT_HOP;
        }
    }
    return FIELD_PLAYER_GRID_RESULT_BLOCKED;
}


int FIELD_PLAYER_GRID_GetHoldResultOnFootHop(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        if (FIELD_PLAYER_GRID_IsHoldFlagSet(grid) == 0) {
            FIELD_PLAYER_GRID_StartHold(grid);
        }
        if (grid->holdEffectPending == 1) {
            if (FLDMMDL_DRAW_SyncFrameGroup(mmdl, grid->holdFrames) != 0) {
                grid->holdEffectPending = 0;
            }
        }
        grid->holdFrames = grid->holdFrames + 1;
        if (grid->holdFrames == 60) {
            FIELD_PLAYER_GRID_EndHold(grid);
            FIELD_PLAYER_GRID_SetHopFlag(grid, 1);
            return FIELD_PLAYER_GRID_RESULT_HOP;
        }
    } else {
        FIELD_PLAYER_GRID_EndHold(grid);
        return FIELD_PLAYER_GRID_GetWalkResultOnFootHop(grid, mmdl, request);
    }
    return FIELD_PLAYER_GRID_RESULT_HOLD;
}


int FIELD_PLAYER_GRID_GetHopAirResult(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
        return FIELD_PLAYER_GRID_RESULT_HOP_FALL;
    }
    return FIELD_PLAYER_GRID_RESULT_HOP_AIR;
}


int FIELD_PLAYER_GRID_GetHopFallResult(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (FIELD_PLAYER_GRID_IsAtGroundHeight(grid, (u32)mmdl, (u32)request) == 1) {
        FIELD_PLAYER_GRID_FinishHop(grid);
        FIELD_PLAYER_GRID_SetHopFlag(grid, 0);
        return FIELD_PLAYER_GRID_RESULT_STAND;
    }
    return FIELD_PLAYER_GRID_RESULT_HOP_FALL;
}


int FIELD_PLAYER_GRID_GetMoveResultOnCycle(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    int result = FIELD_PLAYER_GRID_RESULT_NONE;

    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        result = FIELD_PLAYER_GRID_GetStandResultOnCycle(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        result = FIELD_PLAYER_GRID_GetWalkResultOnCycle(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_TURN:
        result = FIELD_PLAYER_GRID_GetTurnResultOnCycle(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        result = FIELD_PLAYER_GRID_GetBlockedResultOnCycle(grid, mmdl, request);
        break;
    }
    return result;
}


int FIELD_PLAYER_GRID_GetStandResultOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
        if (request->dir != FIELD_PLAYER_GRID_DIR_NONE) {
            u32 curDir = FLDMMDL_GetDirDisp(mmdl);
            if (request->dir != curDir && request->isDash == 0) {
                return FIELD_PLAYER_GRID_RESULT_TURN;
            }
            return FIELD_PLAYER_GRID_GetWalkResultOnCycle(grid, mmdl, request);
        }
        return FIELD_PLAYER_GRID_RESULT_STAND;
    }
    return FIELD_PLAYER_GRID_RESULT_NONE;
}


int FIELD_PLAYER_GRID_IsTileBlockingCycle(int attrKind)
{
    if (MAP_ATTR_IsTallGrass(attrKind) != 0 || MAP_ATTR_IsDeepSand(attrKind) != 0 || MAP_ATTR_IsDeepSandB(attrKind) != 0 || MAP_ATTR_IsDeepSnow(attrKind) != 0)
        return 1;
    return 0;
}


/*
 * Twin of FIELD_PLAYER_GRID_GetWalkResultOnFoot; the final attribute test also consults
 * FIELD_PLAYER_GRID_IsTileBlockingCycle on the tile id.
 */
int FIELD_PLAYER_GRID_GetWalkResultOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 hitFlags;
    u16 attrKind;
    u32 attrBits;
    int ledgeDir;

    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return FIELD_PLAYER_GRID_GetStandResultOnCycle(grid, mmdl, request);
    }
    hitFlags = FIELD_PLAYER_GRID_GetStepHitFlags(grid, mmdl, request->dir, &attr);
    if (request->isDash == 1 && hitFlags != 0 && !(hitFlags & 0x10)) {
        hitFlags = 0;
    }
    if (attr != -1) {
        attrKind = MAP_ATTR_GetTerrainId(attr);
        attrBits = MAP_ATTR_GetFlags(attr);
        if (hitFlags & 2) {
            ledgeDir = FIELD_PLAYER_GRID_DIR_NONE;
            if (MAP_ATTR_IsLedgeNorth(attrKind)) {
                ledgeDir = 0;
            } else if (MAP_ATTR_IsLedgeSouth(attrKind)) {
                ledgeDir = 1;
            } else if (MAP_ATTR_IsLedgeWest(attrKind)) {
                ledgeDir = 2;
            } else if (MAP_ATTR_IsLedgeEast(attrKind)) {
                ledgeDir = 3;
            }
            if (ledgeDir != FIELD_PLAYER_GRID_DIR_NONE && ledgeDir == request->dir) {
                return FIELD_PLAYER_GRID_RESULT_LEDGE_JUMP;
            }
        }
        if (hitFlags == 0) {
            if (!(attrBits & 2) && FIELD_PLAYER_GRID_IsTileBlockingCycle(attrKind) == 0) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
            if (request->isDash == 1) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
        }
    }
    return FIELD_PLAYER_GRID_RESULT_BLOCKED;
}


int FIELD_PLAYER_GRID_GetTurnResultOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0)
        return FIELD_PLAYER_GRID_RESULT_NONE;
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE)
        return FIELD_PLAYER_GRID_GetStandResultOnCycle(grid, mmdl, request);
    return FIELD_PLAYER_GRID_GetWalkResultOnCycle(grid, mmdl, request);
}


int FIELD_PLAYER_GRID_GetBlockedResultOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    u32 curDir = FLDMMDL_GetDirDisp(mmdl);

    if (request->dir != FIELD_PLAYER_GRID_DIR_NONE && request->dir != curDir) {
        FLDMMDL_FreeAcmd(mmdl);
        return FIELD_PLAYER_GRID_GetWalkResultOnCycle(grid, mmdl, request);
    }
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return FIELD_PLAYER_GRID_GetStandResultOnCycle(grid, mmdl, request);
    }
    return FIELD_PLAYER_GRID_GetWalkResultOnCycle(grid, mmdl, request);
}


int FIELD_PLAYER_GRID_GetMoveResultOnSurf(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    int result = FIELD_PLAYER_GRID_RESULT_NONE;

    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        result = FIELD_PLAYER_GRID_GetStandResultOnSurf(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        result = FIELD_PLAYER_GRID_GetWalkResultOnSurf(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_TURN:
        result = FIELD_PLAYER_GRID_GetTurnResultOnSurf(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        result = FIELD_PLAYER_GRID_GetBlockedResultOnSurf(grid, mmdl, request);
        break;
    }
    return result;
}


int FIELD_PLAYER_GRID_GetStandResultOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
        if (request->dir != FIELD_PLAYER_GRID_DIR_NONE) {
            u32 curDir = FLDMMDL_GetDirDisp(mmdl);
            if (request->dir != curDir && request->isDash == 0) {
                return FIELD_PLAYER_GRID_RESULT_TURN;
            }
            return FIELD_PLAYER_GRID_GetWalkResultOnSurf(grid, mmdl, request);
        }
        return FIELD_PLAYER_GRID_RESULT_STAND;
    }
    return FIELD_PLAYER_GRID_RESULT_NONE;
}


int FIELD_PLAYER_GRID_GetWalkResultOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 hitFlags;

    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return FIELD_PLAYER_GRID_GetStandResultOnSurf(grid, mmdl, request);
    }
    hitFlags = FIELD_PLAYER_GRID_GetStepHitFlags(grid, mmdl, request->dir, &attr);
    if (request->isDash == 1 && hitFlags != 0 && !(hitFlags & 0x10)) {
        hitFlags = 0;
    }
    if (attr != -1) {
        u32 attrBits;
        MAP_ATTR_GetTerrainId(attr);
        attrBits = MAP_ATTR_GetFlags(attr);
        if (hitFlags == 0) {
            if (attrBits & 2) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
            if (request->isDash == 1) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
        }
    }
    return FIELD_PLAYER_GRID_RESULT_BLOCKED;
}


int FIELD_PLAYER_GRID_GetTurnResultOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0)
        return FIELD_PLAYER_GRID_RESULT_NONE;
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE)
        return FIELD_PLAYER_GRID_GetStandResultOnSurf(grid, mmdl, request);
    return FIELD_PLAYER_GRID_GetWalkResultOnSurf(grid, mmdl, request);
}


int FIELD_PLAYER_GRID_GetBlockedResultOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    u32 curDir = FLDMMDL_GetDirDisp(mmdl);

    if (request->dir != FIELD_PLAYER_GRID_DIR_NONE && request->dir != curDir) {
        FLDMMDL_FreeAcmd(mmdl);
        return FIELD_PLAYER_GRID_GetWalkResultOnSurf(grid, mmdl, request);
    }
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return FIELD_PLAYER_GRID_GetStandResultOnSurf(grid, mmdl, request);
    }
    return FIELD_PLAYER_GRID_GetWalkResultOnSurf(grid, mmdl, request);
}


void FIELD_PLAYER_GRID_ApplyMoveResult(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request)
{
    switch (FIELD_PLAYER_CORE_GetFormCode(grid->core)) {
    case FIELD_PLAYER_AVATAR_FORM_NORMAL:
        FIELD_PLAYER_GRID_ApplyMoveResultOnFoot(grid, result, request);
        return;
    case FIELD_PLAYER_AVATAR_FORM_CYCLE:
        FIELD_PLAYER_GRID_ApplyMoveResultOnCycle(grid, result, request);
        return;
    case FIELD_PLAYER_AVATAR_FORM_SURF:
    case FIELD_PLAYER_AVATAR_FORM_DIVE:
        FIELD_PLAYER_GRID_ApplyMoveResultOnSurf(grid, result, request);
        break;
    }
}


void FIELD_PLAYER_GRID_ApplyMoveResultOnFoot(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);

    switch (result) {
    case FIELD_PLAYER_GRID_RESULT_NONE: FIELD_PLAYER_GRID_ApplyNoneOnFoot(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_STAND: FIELD_PLAYER_GRID_StartStandOnFoot(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_WALK: FIELD_PLAYER_GRID_StartWalkOnFoot(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_TURN: FIELD_PLAYER_GRID_StartTurnOnFoot(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_BLOCKED: FIELD_PLAYER_GRID_StartBlockedOnFoot(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_LEDGE_JUMP: FIELD_PLAYER_GRID_StartLedgeJumpOnFoot(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_HOLD: FIELD_PLAYER_GRID_StartHoldOnFoot(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_HOP: FIELD_PLAYER_GRID_StartHopOnFoot(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_HOP_AIR: FIELD_PLAYER_GRID_StartHopAirOnFoot(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_HOP_FALL: FIELD_PLAYER_GRID_StartHopFallOnFoot(grid, mmdl, request); break;
    }
}


/* Unlabelled leaf (no lr save), filed because it blocks the caller's MATCH. */
void FIELD_PLAYER_GRID_ApplyNoneOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
}


void FIELD_PLAYER_GRID_StartStandOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int dir = request->dir;

    if (dir == FIELD_PLAYER_GRID_DIR_NONE)
        dir = FLDMMDL_GetDirDisp(mmdl);
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, FIELD_PLAYER_GRID_ACMD_STAND));
    grid->state = FIELD_PLAYER_GRID_STATE_STAND;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
}


void FIELD_PLAYER_GRID_StartWalkOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    VecFx32 pos;
    int attr;
    u32 acmdBase;
    int checkSlope = 1;

    if (request->isDash == 1) {
        acmdBase = FIELD_PLAYER_GRID_ACMD_DASH;
        checkSlope = 0;
    } else if ((request->dashAllowed & 1) && (request->keyHeld & 2)) {
        if (FIELD_PLAYER_CORE_CheckFormModel(grid->core) == 0) {
            acmdBase = FIELD_PLAYER_GRID_ACMD_RUN;
        } else {
            acmdBase = FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL;
            FIELD_PLAYER_GRID_SetFlag(grid, FIELD_PLAYER_GRID_FLAG_SPECIAL_WALK);
            FIELD_PLAYER_CORE_GetPos(grid->core, &pos);
            if (FLDMMDL_MOVE_GetMapAttr(mmdl, &pos, &attr) != 0) {
                if (MAP_ATTR_IsNoDash(MAP_ATTR_GetTerrainId(attr)) != 0) {
                    acmdBase = FIELD_PLAYER_GRID_ACMD_WALK;
                    checkSlope = 0;
                    FIELD_PLAYER_GRID_ClearFlag(grid, FIELD_PLAYER_GRID_FLAG_SPECIAL_WALK);
                }
            }
        }
    } else {
        acmdBase = FIELD_PLAYER_GRID_ACMD_WALK;
    }
    if (checkSlope == 1) {
        if (FIELD_PLAYER_GRID_GetHeightStep(grid, request->dir) == 1) {
            switch (acmdBase) {
            case FIELD_PLAYER_GRID_ACMD_RUN: acmdBase = FIELD_PLAYER_GRID_ACMD_RUN_SLOPE_UP; break;
            case FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL: acmdBase = FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL_SLOPE_UP; break;
            case FIELD_PLAYER_GRID_ACMD_WALK: acmdBase = FIELD_PLAYER_GRID_ACMD_WALK_SLOPE_UP; break;
            }
        }
    }
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, acmdBase));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
}


void FIELD_PLAYER_GRID_StartTurnOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, FIELD_PLAYER_GRID_ACMD_TURN));
    grid->state = FIELD_PLAYER_GRID_STATE_TURN;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_RUN);
}


void FIELD_PLAYER_GRID_StartBlockedOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, FIELD_PLAYER_GRID_ACMD_BLOCKED));
    grid->state = FIELD_PLAYER_GRID_STATE_BLOCKED;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
    if (FIELD_PLAYER_GRID_CheckMapConnectAhead(grid, request->dir) == 0)
        GFL_USE_PlaySeDefaultVolume(FIELD_PLAYER_GRID_SE_BLOCKED);
}


void FIELD_PLAYER_GRID_StartLedgeJumpOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, FIELD_PLAYER_GRID_ACMD_LEDGE_JUMP));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
    GFL_USE_PlaySeDefaultVolume(FIELD_PLAYER_GRID_SE_LEDGE_JUMP);
}


void FIELD_PLAYER_GRID_StartHoldOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    grid->state = FIELD_PLAYER_GRID_STATE_HOLD;
}


void FIELD_PLAYER_GRID_StartHopOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    u32 dir = request->dir;

    if (dir == FIELD_PLAYER_GRID_DIR_NONE) {
        dir = FIELD_PLAYER_GRID_FindHopDir(grid);
    }
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, FIELD_PLAYER_GRID_ACMD_HOP));
    FLDMMDL_SetStatusBitHeightGetOff(mmdl, 1);
    FLDMMDL_SetMoveBitShadowVanish(mmdl, 1);
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_SHOAL_SET);
    grid->state = FIELD_PLAYER_GRID_STATE_HOP;
}


void FIELD_PLAYER_GRID_StartHopAirOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    grid->state = FIELD_PLAYER_GRID_STATE_HOP_AIR;
}


/*
 * The function returns int: pos.y when the height is already at or under the
 * limit, 7 (the new state) otherwise. The only caller (FIELD_PLAYER_GRID_ApplyMoveResultOnFoot, case 9)
 * discards the value. Returning pos.y on the early path ties the cross-block
 * pos.y value to r0 (the return register), so the block-2 constant 0x8000 goes
 * to r1 and the subtract reads `subs r0, r0, r1`; the void form colours the
 * constant first into r0 and gives `subs r0, r1, r0` (three earlier rounds,
 * dozens of spellings). Leaving the final `return 7` out recolours the 7 to r1.
 * See docs/idioms/a-value-returned-on-the-early-path-precolours-its-register-to-r0.md.
 */
int FIELD_PLAYER_GRID_StartHopFallOnFoot(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    Mmdl *playerMmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    VecFx32 pos;
    int groundHeight;

    FLDMMDL_GetPos(playerMmdl, &pos);
    FLDMMDL_MOVE_GetMapHeight(playerMmdl, &pos, &groundHeight);
    if (pos.y > groundHeight) {
        pos.y -= 0x8000;
        if (pos.y < groundHeight) {
            pos.y = groundHeight;
            FLDMMDL_ClearMoveBit(playerMmdl, MMDL_MOVEBIT_SHOAL_SET);
            grid->hopLanded = 1;
        }
        FLDMMDL_SetPos(playerMmdl, &pos);
        grid->state = FIELD_PLAYER_GRID_STATE_HOP_FALL;
        return 7;
    }
    return pos.y;
}


void FIELD_PLAYER_GRID_ApplyMoveResultOnCycle(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);

    switch (result) {
    case FIELD_PLAYER_GRID_RESULT_NONE: FIELD_PLAYER_GRID_ApplyNoneOnCycle(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_STAND: FIELD_PLAYER_GRID_StartStandOnCycle(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_WALK: FIELD_PLAYER_GRID_StartWalkOnCycle(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_TURN: FIELD_PLAYER_GRID_StartTurnOnCycle(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_BLOCKED: FIELD_PLAYER_GRID_StartBlockedOnCycle(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_LEDGE_JUMP: FIELD_PLAYER_GRID_StartLedgeJumpOnCycle(grid, mmdl, request); break;
    }
}


void FIELD_PLAYER_GRID_ApplyNoneOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
}


void FIELD_PLAYER_GRID_StartStandOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int dir = request->dir;

    if (dir == FIELD_PLAYER_GRID_DIR_NONE)
        dir = FLDMMDL_GetDirDisp(mmdl);
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, FIELD_PLAYER_GRID_ACMD_STAND));
    grid->state = FIELD_PLAYER_GRID_STATE_STAND;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
}


void FIELD_PLAYER_GRID_StartWalkOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 acmdBase;
    int checkSlope = 1;

    if (request->isDash == 1) {
        acmdBase = FIELD_PLAYER_GRID_ACMD_DASH;
        checkSlope = 0;
    } else {
        acmdBase = FIELD_PLAYER_GRID_ACMD_DASH;
        if (FIELD_PLAYER_GRID_GetAttrAtDir(grid, FIELD_PLAYER_GRID_DIR_NONE, &attr) == 1) {
            if (MAP_ATTR_IsSand(MAP_ATTR_GetTerrainId(attr)) == 1) {
                acmdBase = FIELD_PLAYER_GRID_ACMD_CYCLE_SPECIAL;
                FLDEFF_KEMURI_Start(mmdl, FIELDMAP_GetEffect(grid->fieldMap));
            }
        }
    }
    if (checkSlope == 1) {
        if (FIELD_PLAYER_GRID_GetHeightStep(grid, request->dir) == 1) {
            if (acmdBase == FIELD_PLAYER_GRID_ACMD_DASH) {
                acmdBase = FIELD_PLAYER_GRID_ACMD_RUN;
            }
        }
    }
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, acmdBase));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
}


void FIELD_PLAYER_GRID_StartTurnOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, FIELD_PLAYER_GRID_ACMD_TURN));
    grid->state = FIELD_PLAYER_GRID_STATE_TURN;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_RUN);
}


void FIELD_PLAYER_GRID_StartBlockedOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, FIELD_PLAYER_GRID_ACMD_BLOCKED));
    grid->state = FIELD_PLAYER_GRID_STATE_BLOCKED;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
    if (FIELD_PLAYER_GRID_CheckMapConnectAhead(grid, request->dir) == 0)
        GFL_USE_PlaySeDefaultVolume(FIELD_PLAYER_GRID_SE_BLOCKED);
}


void FIELD_PLAYER_GRID_StartLedgeJumpOnCycle(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, FIELD_PLAYER_GRID_ACMD_LEDGE_JUMP));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
    GFL_USE_PlaySeDefaultVolume(FIELD_PLAYER_GRID_SE_LEDGE_JUMP);
}


void FIELD_PLAYER_GRID_ApplyMoveResultOnSurf(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);

    switch (result) {
    case FIELD_PLAYER_GRID_RESULT_NONE: FIELD_PLAYER_GRID_ApplyNoneOnSurf(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_STAND: FIELD_PLAYER_GRID_StartStandOnSurf(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_WALK: FIELD_PLAYER_GRID_StartWalkOnSurf(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_TURN: FIELD_PLAYER_GRID_StartTurnOnSurf(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_BLOCKED: FIELD_PLAYER_GRID_StartBlockedOnSurf(grid, mmdl, request); break;
    }
}


void FIELD_PLAYER_GRID_ApplyNoneOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
}


void FIELD_PLAYER_GRID_StartStandOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int dir = request->dir;

    if (dir == FIELD_PLAYER_GRID_DIR_NONE)
        dir = FLDMMDL_GetDirDisp(mmdl);
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, FIELD_PLAYER_GRID_ACMD_STAND));
    grid->state = FIELD_PLAYER_GRID_STATE_STAND;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
}


void FIELD_PLAYER_GRID_StartWalkOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int acmdBase = (request->isDash == 1) ? FIELD_PLAYER_GRID_ACMD_DASH : FIELD_PLAYER_GRID_ACMD_RUN;

    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, acmdBase));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
}


void FIELD_PLAYER_GRID_StartTurnOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, FIELD_PLAYER_GRID_ACMD_TURN));
    grid->state = FIELD_PLAYER_GRID_STATE_TURN;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_RUN);
}


void FIELD_PLAYER_GRID_StartBlockedOnSurf(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(request->dir, FIELD_PLAYER_GRID_ACMD_BLOCKED));
    grid->state = FIELD_PLAYER_GRID_STATE_BLOCKED;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
    if (FIELD_PLAYER_GRID_CheckMapConnectAhead(grid, request->dir) == 0)
        GFL_USE_PlaySeDefaultVolume(FIELD_PLAYER_GRID_SE_BLOCKED);
}


int FIELD_PLAYER_GRID_GetStepHitFlags(FieldPlayerGrid *grid, Mmdl *mmdl, u32 dir, int *outAttr)
{
    VecFx32 pos;
    int gridZ;
    int gridY;
    int hitFlags;
    int stepX;
    stepX = FLDMMDL_GetGridNowX(mmdl);
    gridY = FLDMMDL_GetGridNowY(mmdl);
    gridZ = FLDMMDL_GetGridNowZ(mmdl);
    stepX = (short)(stepX + FLDMMDL_MOVE_GetDirAddGridX(dir));
    hitFlags = (short)(gridZ + FLDMMDL_MOVE_GetDirAddGridZ(dir));
    stepX = FLDMMDL_MOVE_HitCheckMoveCurrent(mmdl, stepX, gridY, hitFlags, dir);
    FLDMMDL_GetPos(mmdl, &pos);
    FLDMMDL_MOVE_AddDirVector(dir, &pos, 0x10000);
    if (FLDMMDL_MOVE_GetMapAttr(mmdl, &pos, outAttr) == 0) {
        *outAttr = -1;
    }
    if (stepX & 2) {
        if (MAP_ATTR_IsHole(MAP_ATTR_GetTerrainId(*outAttr)) == 1) {
            if (FLDMMDL_CheckMovedPosAtMapPos(FLDMMDL_GetMmdlSys(mmdl), &pos) == 1) {
                stepX &= ~2;
            }
        }
    }
    return stepX;
}


void FIELD_PLAYER_GRID_SetFlag(FieldPlayerGrid *grid, u32 mask)
{
    grid->flags = (mask | grid->flags);
}


void FIELD_PLAYER_GRID_ClearFlag(FieldPlayerGrid *grid, u32 mask)
{
    grid->flags = ((~mask) & grid->flags);
}


int FIELD_PLAYER_GRID_HasFlag(FieldPlayerGrid *grid, u32 mask)
{
    if (grid->flags & mask)
        return 1;
    return 0;
}


void FIELD_PLAYER_GRID_SetForcedMoveFlag(FieldPlayerGrid *grid)
{
    FIELD_PLAYER_GRID_SetFlag(grid, FIELD_PLAYER_GRID_FLAG_FORCED_MOVE);
}


void FIELD_PLAYER_GRID_ClearForcedMoveFlag(FieldPlayerGrid *grid)
{
    FIELD_PLAYER_GRID_ClearFlag(grid, FIELD_PLAYER_GRID_FLAG_FORCED_MOVE);
}


int FIELD_PLAYER_GRID_IsForcedMoveFlagSet(FieldPlayerGrid *grid)
{
    int isForced = 1;

    if (FIELD_PLAYER_GRID_HasFlag(grid, FIELD_PLAYER_GRID_FLAG_FORCED_MOVE) == 0)
        isForced = 0;
    return isForced;
}


void FIELD_PLAYER_GRID_SetNoForcedMoveFlag(FieldPlayerGrid *grid)
{
    FIELD_PLAYER_GRID_SetFlag(grid, FIELD_PLAYER_GRID_FLAG_NO_FORCED_MOVE);
}


void FIELD_PLAYER_GRID_ClearNoForcedMoveFlag(FieldPlayerGrid *grid)
{
    FIELD_PLAYER_GRID_ClearFlag(grid, FIELD_PLAYER_GRID_FLAG_NO_FORCED_MOVE);
}


void FIELD_PLAYER_GRID_ClearStepPendingFlag(FieldPlayerGrid *grid)
{
    FIELD_PLAYER_GRID_ClearFlag(grid, FIELD_PLAYER_GRID_FLAG_STEP_PENDING);
}


void FIELD_PLAYER_GRID_SetHoldFlag(FieldPlayerGrid *grid, int on)
{
    if (on == 1)
        FIELD_PLAYER_GRID_SetFlag(grid, FIELD_PLAYER_GRID_FLAG_HOLD);
    else
        FIELD_PLAYER_GRID_ClearFlag(grid, FIELD_PLAYER_GRID_FLAG_HOLD);
}


int FIELD_PLAYER_GRID_IsHoldFlagSet(FieldPlayerGrid *grid)
{
    if (FIELD_PLAYER_GRID_HasFlag(grid, FIELD_PLAYER_GRID_FLAG_HOLD) != 0) {
        return 1;
    }
    return 0;
}


void FIELD_PLAYER_GRID_SetHopFlag(FieldPlayerGrid *grid, int on)
{
    if (on == 1)
        FIELD_PLAYER_GRID_SetFlag(grid, FIELD_PLAYER_GRID_FLAG_HOP);
    else
        FIELD_PLAYER_GRID_ClearFlag(grid, FIELD_PLAYER_GRID_FLAG_HOP);
}


int FIELD_PLAYER_GRID_IsHopFlagSet(FieldPlayerGrid *grid)
{
    if (FIELD_PLAYER_GRID_HasFlag(grid, FIELD_PLAYER_GRID_FLAG_HOP) != 0) {
        return 1;
    }
    return 0;
}


void FIELD_PLAYER_GRID_ResetBlockedPose(FieldPlayerGrid *grid)
{
    Mmdl *mmdl;
    int dir;

    if (grid->state == FIELD_PLAYER_GRID_STATE_BLOCKED) {
        mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
        dir = FLDMMDL_GetDirDisp(mmdl);
        FLDMMDL_FreeAcmd(mmdl);
        FLDMMDL_SetDirDispCheckPause(mmdl, dir);
        FLDMMDL_SetDrawStatus(mmdl, 0);
        FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
    }
}


int FIELD_PLAYER_GRID_StopTurnOrBlocked(FieldPlayerGrid *grid)
{
    Mmdl *mmdl;
    u32 dir;

    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        return 0;
    case FIELD_PLAYER_GRID_STATE_TURN:
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        mmdl = FIELD_PLAYER_GRID_GetMmdl(grid);
        dir = FLDMMDL_GetDirDisp(mmdl);
        FLDMMDL_FreeAcmd(mmdl);
        FLDMMDL_SetDirDispCheckPause(mmdl, dir);
        FLDMMDL_SetDrawStatus(mmdl, 0);
        FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
        break;
    }
    return 1;
}


int FIELD_PLAYER_GRID_CheckForcedMoveTile(FieldPlayerGrid *grid, int unused)
{
    int attrKind = FLDMMDL_GetNowAttr(FIELD_PLAYER_CORE_GetMmdl(grid->core));

    if (FIELD_PLAYER_GRID_HasFlag(grid, FIELD_PLAYER_GRID_FLAG_NO_FORCED_MOVE) == 0 && MAP_ATTR_IsForcedSlide(MAP_ATTR_GetTerrainId(attrKind)) == 1)
        return 1;
    return 0;
}


int FIELD_PLAYER_GRID_IsOnForcedMoveTile(FieldPlayerGrid *grid)
{
    if (FIELD_PLAYER_GRID_CheckForcedMoveTile(grid, FIELD_PLAYER_GRID_DIR_NONE) != 0) {
        return 1;
    }
    return 0;
}


int FIELD_PLAYER_GRID_IsHopping(FieldPlayerGrid *grid)
{
    if (FIELD_PLAYER_GRID_IsHopFlagSet(grid) == 1) {
        return 1;
    }
    return 0;
}


void FIELD_PLAYER_GRID_FinishHop(FieldPlayerGrid *grid)
{
    VecFx32 pos;
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);

    FLDMMDL_SetStatusBitHeightGetOff(mmdl, 0);
    FLDMMDL_SetMoveBitShadowVanish(mmdl, 0);
    FLDMMDL_SetMoveBit(mmdl, FIELD_PLAYER_GRID_MMDL_STEP_END_BITS);
    FLDMMDL_MOVE_UpdateHeight(mmdl);
    FLDMMDL_GetPos(mmdl, &pos);
    FLDMMDL_SetGridNowY(mmdl, (s16)((pos.y >> 4) / 4096));
    FLDMMDL_MOVE_UpdateMapAttr(mmdl);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
}


void FIELD_PLAYER_GRID_ReleaseForcedMove(FieldPlayerGrid *grid)
{
    if (FIELD_PLAYER_GRID_IsForcedMoveFlagSet(grid) == 1) {
        FLDMMDL_ClearStatusBit(FIELD_PLAYER_CORE_GetMmdl(grid->core), FIELD_PLAYER_GRID_MMDL_PAUSE_BITS);
        FIELD_PLAYER_GRID_ClearForcedMoveFlag(grid);
    }
}


u32 FIELD_PLAYER_GRID_RunNoForcedMove(FieldPlayerGrid *grid)
{
    FIELD_PLAYER_GRID_ReleaseForcedMove(grid);

    return 0x0;
}


int FIELD_PLAYER_GRID_StartForcedMove(FieldPlayerGrid *grid)
{
    int attr;
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    u32 dir = FLDMMDL_GetDirMove(mmdl);

    if (FIELD_PLAYER_GRID_GetStepHitFlags(grid, mmdl, dir, &attr) != 0) {
        FIELD_PLAYER_GRID_ReleaseForcedMove(grid);
        FIELD_PLAYER_GRID_SetNoForcedMoveFlag(grid);
        FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
        return 0;
    }
    FIELD_PLAYER_GRID_SetForcedMoveFlag(grid);
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, FIELD_PLAYER_GRID_ACMD_RUN));
    FLDMMDL_SetStatusBit(mmdl, FIELD_PLAYER_GRID_MMDL_PAUSE_BITS);
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
    return 1;
}


int FIELD_PLAYER_GRID_RunForcedMove(FieldPlayerGrid *grid, u32 dir, int skip)
{
    if (skip == 0) {
        if (gFieldPlayerGridForcedMoveFuncs[FIELD_PLAYER_GRID_CheckForcedMoveTile(grid, dir)](grid, dir) == 1)
            return 1;
    }
    FIELD_PLAYER_GRID_ClearForcedMoveFlag(grid);
    return 0;
}


int FIELD_PLAYER_GRID_IsHopTileKind(int attrKind)
{
    if (MAP_ATTR_IsDeepSand(attrKind) == 1 || MAP_ATTR_IsDeepSandB(attrKind) == 1)
        return 1;
    return 0;
}


int FIELD_PLAYER_GRID_IsHopStartTileKind(int attrKind)
{
    if (MAP_ATTR_IsDeepSand(attrKind) == 1) {
        return 1;
    }
    return 0;
}


int FIELD_PLAYER_GRID_IsOnHopStartTile(FieldPlayerGrid *grid)
{
    int attr;

    FIELD_PLAYER_GRID_GetAttrAtDir(grid, FIELD_PLAYER_GRID_DIR_NONE, &attr);
    if (FIELD_PLAYER_GRID_IsHopStartTileKind(MAP_ATTR_GetTerrainId(attr)) == 1)
        return 1;
    return 0;
}


u32 FIELD_PLAYER_GRID_FindHopDir(FieldPlayerGrid *grid)
{
    int attr;
    u16 dirTable[4];
    u16 tries;
    u32 dir;
    u16 *nextDir = dirTable;

    dirTable[0] = gFieldPlayerGridNextHopDirs[0];
    dirTable[1] = gFieldPlayerGridNextHopDirs[1];
    dirTable[2] = gFieldPlayerGridNextHopDirs[2];
    dirTable[3] = gFieldPlayerGridNextHopDirs[3];
    dir = FIELD_PLAYER_CORE_GetDirDisp(grid->core);
    tries = 0;
    do {
        if (FIELD_PLAYER_GRID_GetAttrAtDir(grid, dir, &attr) == 1) {
            if (FIELD_PLAYER_GRID_IsHopTileKind(MAP_ATTR_GetTerrainId(attr)) == 0) {
                if (MAP_ATTR_IsBlocked(attr) == 0) {
                    return dir;
                }
            }
        }
        tries = tries + 1;
        dir = nextDir[dir];
    } while (tries < 4);
    return FIELD_PLAYER_GRID_DIR_NONE;
}


int FIELD_PLAYER_GRID_GetHopStepHitFlags(FieldPlayerGrid *grid, Mmdl *mmdl, int dir, int *outAttr)
{
    int hitFlags = FIELD_PLAYER_GRID_GetStepHitFlags(grid, mmdl, dir, outAttr);

    if (FIELD_PLAYER_GRID_IsHopTileKind(MAP_ATTR_GetTerrainId(*outAttr)) == 1)
        hitFlags |= 0x100;
    return hitFlags;
}


u32 FIELD_PLAYER_GRID_IsAtGroundHeight(FieldPlayerGrid *grid, u32 unused1, u32 unused2)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    VecFx32 pos;
    int groundHeight;

    FLDMMDL_GetPos(mmdl, &pos);
    FLDMMDL_MOVE_GetMapHeight(mmdl, &pos, &groundHeight);
    if (pos.y <= groundHeight)
        return 1;
    return 0;
}


void FIELD_PLAYER_GRID_StartHold(FieldPlayerGrid *grid)
{
    FIELD_PLAYER_GRID_SetHoldFlag(grid, 1);
    FIELD_PLAYER_CORE_SetFormSlotModel(grid->core, 7);
}


void FIELD_PLAYER_GRID_EndHold(FieldPlayerGrid *grid)
{
    grid->holdFrames = 0;
    grid->holdEffectPending = 0;
    FIELD_PLAYER_GRID_SetHopFlag(grid, 0);
    FIELD_PLAYER_GRID_SetHoldFlag(grid, 0);
    FIELD_PLAYER_CORE_ApplyFormCodeModel(grid->core);
}


FieldPlayerCore *FIELD_PLAYER_GRID_GetCore(FieldPlayerGrid *grid)
{
    return grid->core;
}


/* Tail-call thunk: the model of the core. */
Mmdl *FIELD_PLAYER_GRID_GetMmdl(FieldPlayerGrid *grid)
{
    return FIELD_PLAYER_CORE_GetMmdl(grid->core);
}


void FIELD_PLAYER_GRID_ResetHold(FieldPlayerGrid *grid, int keepFrame)
{
    u16 savedFrames;

    if (FIELD_PLAYER_GRID_IsHoldFlagSet(grid) == 1) {
        savedFrames = grid->holdFrames;
        FIELD_PLAYER_GRID_EndHold(grid);
        if (keepFrame == 1) {
            grid->holdFrames = savedFrames;
            grid->holdEffectPending = 1;
        }
    }
}


/* Tail-call thunk: forwards to FIELD_PLAYER_GRID_ReleaseForcedMove with no argument change. */
void FIELD_PLAYER_GRID_StopForcedMove(FieldPlayerGrid *grid)
{
    FIELD_PLAYER_GRID_ReleaseForcedMove(grid);
}


u32 FIELD_PLAYER_GRID_GetHopLanded(FieldPlayerGrid *grid)
{
    return grid->hopLanded;
}


int FIELD_PLAYER_GRID_SetHopLanded(FieldPlayerGrid *grid, u32 landed)
{
    if (landed == 1) {
        grid->hopLanded = 1;
        return (int)grid;
    }
    grid->hopLanded = 0;
    return (int)grid;
}


int FIELD_PLAYER_GRID_IsBlocked(FieldPlayerGrid *grid)
{
    if (grid->state == FIELD_PLAYER_GRID_STATE_BLOCKED) {
        return 1;
    }
    return 0;
}


int FIELD_PLAYER_GRID_GetAttrAtDir(FieldPlayerGrid *grid, int dir, int *outAttr)
{
    VecFx32 pos;

    FIELD_PLAYER_CORE_GetPos(grid->core, &pos);
    if (dir != FIELD_PLAYER_GRID_DIR_NONE)
        FLDMMDL_MOVE_AddDirVector(dir, &pos, 0x10000);
    return FLDMMDL_MOVE_GetMapAttr(FIELD_PLAYER_CORE_GetMmdl(grid->core), &pos, outAttr);
}


int FIELD_PLAYER_GRID_GetHeightStep(FieldPlayerGrid *grid, int dir)
{
    Mmdl *mmdl;
    int curHeight;
    VecFx32 pos;
    int destHeight;

    mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    FLDMMDL_GetPos(mmdl, &pos);
    curHeight = pos.y;
    FLDMMDL_MOVE_AddDirVector(dir, &pos, 0x10000);
    if (FLDMMDL_MOVE_GetMapHeight(mmdl, &pos, &destHeight) == 1) {
        if (curHeight < destHeight) {
            return 1;
        }
        if (curHeight > destHeight) {
            return 2;
        }
    }
    return 0;
}


int FIELD_PLAYER_GRID_CheckMapConnectAhead(FieldPlayerGrid *grid, int dir)
{
    Mmdl *mmdl;
    void *eventData;
    int connectIndex;
    VecFx32 pos;

    mmdl = FIELD_PLAYER_CORE_GetMmdl(grid->core);
    eventData = GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(grid->fieldMap)));
    FLDMMDL_GetPos(mmdl, &pos);
    FLDMMDL_MOVE_AddDirVector(dir, &pos, 0x10000);
    connectIndex = EVENTDATA_SYSTEM_SearchConnectIdByGridPos(eventData, &pos);
    if (connectIndex == 0xffff) {
        return 0;
    }
    if (EVENTDATA_SYSTEM_IsConnectExitDir(EVENTDATA_SYSTEM_GetConnectData(eventData, (u16)connectIndex), dir)) {
        return 1;
    }
    return 0;
}
