/*
 * file:     field_player_nogrid.c
 * unit:     yes
 * function: FIELD_PLAYER_NOGRID_Create, FIELD_PLAYER_NOGRID_Delete, FIELD_PLAYER_NOGRID_AttachMmdl, FIELD_PLAYER_NOGRID_ClearRailWork, FIELD_PLAYER_NOGRID_Update, FIELD_PLAYER_NOGRID_IsBlocked, FIELD_PLAYER_NOGRID_IsForcedMove, FIELD_PLAYER_NOGRID_SetRailLocation, FIELD_PLAYER_NOGRID_GetNextRailLocation, FIELD_PLAYER_NOGRID_GetRailLocationByDir, FIELD_PLAYER_NOGRID_GetRailPos, FIELD_PLAYER_NOGRID_GetRailWork, FIELD_PLAYER_NOGRID_EndBlockedWalk, FIELD_PLAYER_NOGRID_CheckAction, FIELD_PLAYER_NOGRID_StartAction, FIELD_PLAYER_NOGRID_UpdateFlagsAfterCheck, FIELD_PLAYER_NOGRID_GetHitBits, FIELD_PLAYER_NOGRID_UpdateSpin, FIELD_PLAYER_NOGRID_StartActionWalk, FIELD_PLAYER_NOGRID_CheckActionWalk, FIELD_PLAYER_NOGRID_CheckWalkFromStand, FIELD_PLAYER_NOGRID_CheckWalkStep, FIELD_PLAYER_NOGRID_CheckWalkFromTurn, FIELD_PLAYER_NOGRID_CheckWalkFromBlocked, FIELD_PLAYER_NOGRID_StartWalkNone, FIELD_PLAYER_NOGRID_StartWalkStand, FIELD_PLAYER_NOGRID_StartWalkStep, FIELD_PLAYER_NOGRID_StartWalkTurn, FIELD_PLAYER_NOGRID_StartWalkBlocked, FIELD_PLAYER_NOGRID_StartWalkLedgeJump, FIELD_PLAYER_NOGRID_StartActionSlow, FIELD_PLAYER_NOGRID_CheckActionSlow, FIELD_PLAYER_NOGRID_CheckSlowFromStand, FIELD_PLAYER_NOGRID_CheckSlowStep, FIELD_PLAYER_NOGRID_CheckSlowFromTurn, FIELD_PLAYER_NOGRID_CheckSlowFromBlocked, FIELD_PLAYER_NOGRID_StartSlowNone, FIELD_PLAYER_NOGRID_StartSlowStand, FIELD_PLAYER_NOGRID_StartSlowStep, FIELD_PLAYER_NOGRID_StartSlowTurn, FIELD_PLAYER_NOGRID_StartSlowBlocked, FIELD_PLAYER_NOGRID_StartSlowLedgeJump, FIELD_PLAYER_NOGRID_StartActionRail, FIELD_PLAYER_NOGRID_StartRailNone, FIELD_PLAYER_NOGRID_StartRailStand, FIELD_PLAYER_NOGRID_StartRailStep, FIELD_PLAYER_NOGRID_StartRailTurn, FIELD_PLAYER_NOGRID_StartRailBlocked, FIELD_PLAYER_NOGRID_CheckActionRail, FIELD_PLAYER_NOGRID_CheckRailFromStand, FIELD_PLAYER_NOGRID_CheckRailStep, FIELD_PLAYER_NOGRID_CheckRailFromTurn, FIELD_PLAYER_NOGRID_CheckRailFromBlocked, FIELD_PLAYER_NOGRID_SetFlags, FIELD_PLAYER_NOGRID_ClearFlags, FIELD_PLAYER_NOGRID_HasFlags, FIELD_PLAYER_NOGRID_SetForcedMove, FIELD_PLAYER_NOGRID_ClearForcedMove, FIELD_PLAYER_NOGRID_SetForcedMoveEnded, FIELD_PLAYER_NOGRID_ClearForcedMoveEnded, FIELD_PLAYER_NOGRID_ClearPending, FIELD_PLAYER_NOGRID_SetSpinA, FIELD_PLAYER_NOGRID_ClearSpinA, FIELD_PLAYER_NOGRID_SetSpinB, FIELD_PLAYER_NOGRID_ClearSpinB, FIELD_PLAYER_NOGRID_SetFaceRight, FIELD_PLAYER_NOGRID_ClearFaceRight, FIELD_PLAYER_NOGRID_SetInputHold, FIELD_PLAYER_NOGRID_ClearInputHold, FIELD_PLAYER_NOGRID_GetForcedMoveKind, FIELD_PLAYER_NOGRID_RunForcedMove, FIELD_PLAYER_NOGRID_EndForcedMove, FIELD_PLAYER_NOGRID_ForcedSlide, FIELD_PLAYER_NOGRID_ForcedSlideSpinA, FIELD_PLAYER_NOGRID_ForcedSlideSpinB, FIELD_PLAYER_NOGRID_ForcedSlideWarnDir2, FIELD_PLAYER_NOGRID_ForcedSlideWarnDir3, FIELD_PLAYER_NOGRID_ForcedSlideFaceRight, FIELD_PLAYER_NOGRID_ForcedInputHold, FIELD_PLAYER_NOGRID_StartSpin, FIELD_PLAYER_NOGRID_StopSpin, FIELD_PLAYER_NOGRID_AdvanceSpin, FIELD_PLAYER_NOGRID_InitInputHold, FIELD_PLAYER_NOGRID_EnableInputHold, FIELD_PLAYER_NOGRID_ResetInputHold, FIELD_PLAYER_NOGRID_UpdateInputHold, FIELD_PLAYER_NOGRID_EndInputHoldFrame, FIELD_PLAYER_NOGRID_GetInputHoldDir, FIELD_PLAYER_NOGRID_IsInputHoldKept, FIELD_PLAYER_NOGRID_HasConnectionAhead
 * address:  0x021A5880
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A5914 (d_021DDF04 "field_player_nogrid.c"); 021A5880 is the nogrid constructor.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb
 *   FLDMMDL_RAIL_GetLocationByDir  0x0219E664  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   MAP_ATTR_IsLedgeNorth  0x021AB158  thumb  ov021
 *   MAP_ATTR_IsLedgeSouth  0x021AB164  thumb  ov021
 *   MAP_ATTR_IsLedgeWest  0x021AB170  thumb  ov021
 *   MAP_ATTR_IsLedgeEast  0x021AB17C  thumb  ov021
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   MAP_ATTR_IsForcedSlide  0x021AB348  thumb  ov021
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   GAME_DATA_GetField158  0x02012844  thumb
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_ChangeHeader  0x0216E0AC  thumb  ov010
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb  ov021
 *   d_021DDF04     0x021DDF04  data  a4
 *   gFieldPlayerNogridMmdlHeader     0x021DDEE0  data  a4
 *   d_021DDEE0b    0x021DDEE0  data  a4
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   FLDMMDL_RAIL_GetHitBitsDir  0x0219E424  thumb  ov021
 *   FLDMMDL_RAIL_MOVE_GetLocationAttr  0x0219D724  thumb  ov021
 *   RAIL_ATTR_IsForceMoveUp  0x021BB1AC  thumb  ov021
 *   RAIL_ATTR_IsForceMoveDown  0x021BB1B8  thumb  ov021
 *   RAIL_ATTR_IsForceMoveLeft  0x021BB1C4  thumb  ov021
 *   RAIL_ATTR_IsForceMoveRight  0x021BB1D0  thumb  ov021
 *   RAIL_ATTR_IsForceMoveStop  0x021BB1DC  thumb  ov021
 *   RAIL_ATTR_IsSlipDown  0x021BB1E8  thumb  ov021
 *   gFieldPlayerNogridForcedMoveFuncs  0x021D8AB8  data  a4
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_SetDirDisp  0x0216D5D8  thumb
 *   gFieldPlayerNogridSpinDirs  0x021D8AB0  data  ov021  a4
 *   EVENTDATA_SYSTEM_SearchConnectIdByRailLocation  0x02162598  thumb  ov010
 *   FIELD_PLAYER_CORE_GetFieldMap  0x021A395C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_CORE_ChooseMoveDirFromKeys  0x021A3AB8  thumb  ov021
 *   FIELD_PLAYER_CORE_RememberKeyDirs  0x021A3AC4  thumb  ov021
 *   FIELD_PLAYER_CORE_StartFormChange  0x021A3CB0  thumb  ov021
 *   FIELD_PLAYER_CORE_StepFormChange  0x021A3CC0  thumb  ov021
 *   FIELD_PLAYER_CORE_FinishFormChange  0x021A3CE8  thumb  ov021
 */
#include "field_player_nogrid_types.h"

typedef signed int s32;

/* Heap, sound and memory helpers. */
extern u32 GFL_HEAP_Free(void *block);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int a, const char *file, u16 line);
void GFL_USE_PlaySeDefaultVolume(u32 seId);
void MI_CpuFill8(void *dst, int value, int size);
int GFL_USE_GetSeSlot(u32 seId);
void GFL_USE_StopSeSlot(int slot);

/* Field model (ov010). */
void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int dir);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
u16 FLDMMDL_GetObjCode(Mmdl *mmdl);
extern u16 FLDMMDL_GetDirMove(Mmdl *mmdl);
extern int FLDMMDL_CheckPossibleAcmd(Mmdl *mmdl);
extern void *FLDMMDL_FreeAcmd(Mmdl *mmdl);
void FLDMMDL_SetAcmd(Mmdl *mmdl, int acmdCode);
void FLDMMDL_SetDrawStatus(Mmdl *mmdl, u16 value);
u32 FLDMMDL_GetNowAttr(Mmdl *mmdl);
u32 *FLDMMDL_ClearStatusBit(Mmdl *mmdl, u32 bits);
extern u32 *FLDMMDL_SetStatusBit(Mmdl *mmdl, u32 bits); /* its third parameter is a scratch it never reads */
extern u16 FLDMMDL_GetMoveCode(Mmdl *mmdl);
extern void FLDMMDL_ChangeHeader(Mmdl *mmdl, void *header);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int dir);
extern int FLDMMDL_SetDirAll(Mmdl *mmdl, int dir);
extern void FLDMMDL_SetDirDisp(Mmdl *mmdl, int dir);
int FLDMMDL_ACMD_ConvertCodeByDir(int dir, int baseCode);

/* Field model on rails (ov021). */
extern void FLDMMDL_RAIL_GetNextLocation(Mmdl *mmdl, RailLocation *outLocation);
extern int FLDMMDL_RAIL_GetLocationByDir(Mmdl *mmdl, u32 dir, RailLocation *outLocation);
extern struct RailWork *FLDMMDL_RAIL_GetRailWork(Mmdl *mmdl);
extern void FLDMMDL_RAIL_SetLocation(Mmdl *mmdl, RailLocation *location);
extern int FLDMMDL_RAIL_GetHitBitsDir(Mmdl *mmdl, u32 dir, int *outAttr);
extern int FLDMMDL_RAIL_MOVE_GetLocationAttr(Mmdl *mmdl, RailLocation *location);
extern void FIELD_RAIL_WORK_GetPos(struct RailWork *railWork, void *outPos);

/* Tile attributes. */
u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32);
extern int MAP_ATTR_IsLedgeNorth(u16);
extern int MAP_ATTR_IsLedgeSouth(u16);
extern int MAP_ATTR_IsLedgeWest(u16);
extern int MAP_ATTR_IsLedgeEast(u16);
int MAP_ATTR_IsForcedSlide(u32 attr);
extern int RAIL_ATTR_IsForceMoveUp(int attr);
extern int RAIL_ATTR_IsForceMoveDown(int attr);
extern int RAIL_ATTR_IsForceMoveLeft(int attr);
extern int RAIL_ATTR_IsForceMoveRight(int attr);
extern int RAIL_ATTR_IsForceMoveStop(int attr);
extern int RAIL_ATTR_IsSlipDown(int attr);

/* Game system and event data. */
void *ICA_ANIME_GetField1C(void *gameSystem);
extern void *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern void *GAME_DATA_GetField158(void *gameData);
extern int EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(void *eventData, RailLocation *location);

/* Player core (field_player_core.c). */
struct FieldMap *FIELD_PLAYER_CORE_GetFieldMap(struct FieldPlayerCore *core);
Mmdl *FIELD_PLAYER_CORE_GetMmdl(struct FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetStepKind(struct FieldPlayerCore *core, u32 state);
u32 FIELD_PLAYER_CORE_GetFormCode(struct FieldPlayerCore *core);
u16 FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(struct FieldPlayerCore *core, u32 keyCont);
void FIELD_PLAYER_CORE_RememberKeyDirs(struct FieldPlayerCore *core, u32 keyCont);
int FIELD_PLAYER_CORE_StartFormChange(struct FieldPlayerCore *core, u32 flags);
int FIELD_PLAYER_CORE_StepFormChange(struct FieldPlayerCore *core);
void FIELD_PLAYER_CORE_FinishFormChange(struct FieldPlayerCore *core);

/* This file. */
FieldPlayerNogrid *FIELD_PLAYER_NOGRID_Create(struct FieldPlayerCore *core, int heapId);
void FIELD_PLAYER_NOGRID_Delete(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_AttachMmdl(FieldPlayerNogrid *player, RailLocation *location);
void FIELD_PLAYER_NOGRID_ClearRailWork(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_Update(FieldPlayerNogrid *player, u32 keyTrg, u32 keyCont);
int FIELD_PLAYER_NOGRID_IsBlocked(FieldPlayerNogrid *player);
u32 FIELD_PLAYER_NOGRID_IsForcedMove(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_SetRailLocation(FieldPlayerNogrid *player, RailLocation *location);
void FIELD_PLAYER_NOGRID_GetNextRailLocation(FieldPlayerNogrid *player, RailLocation *outLocation);
int FIELD_PLAYER_NOGRID_GetRailLocationByDir(FieldPlayerNogrid *player, u32 dir, RailLocation *outLocation);
void FIELD_PLAYER_NOGRID_GetRailPos(FieldPlayerNogrid *player, void *outPos);
struct RailWork *FIELD_PLAYER_NOGRID_GetRailWork(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_EndBlockedWalk(FieldPlayerNogrid *player);
int FIELD_PLAYER_NOGRID_CheckAction(FieldPlayerNogrid *player, u32 dir, u32 keyTrg, u32 keyCont, u32 forced);
void FIELD_PLAYER_NOGRID_StartAction(FieldPlayerNogrid *player, u32 action, u32 dir, u32 keyTrg, u32 keyCont, u32 forced);
void FIELD_PLAYER_NOGRID_UpdateFlagsAfterCheck(FieldPlayerNogrid *player, u32 keyCont, int action);
int FIELD_PLAYER_NOGRID_GetHitBits(FieldPlayerNogrid *player, Mmdl *mmdl, u32 dir, int *outAttr);
void FIELD_PLAYER_NOGRID_UpdateSpin(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_StartActionWalk(FieldPlayerNogrid *player, u32 action, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
int FIELD_PLAYER_NOGRID_CheckActionWalk(FieldPlayerNogrid *player, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
int FIELD_PLAYER_NOGRID_CheckWalkFromStand(FieldPlayerNogrid *player, Mmdl *mmdl, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
int FIELD_PLAYER_NOGRID_CheckWalkStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckWalkFromTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckWalkFromBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartWalkNone(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced);
void FIELD_PLAYER_NOGRID_StartWalkStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartWalkStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartWalkTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartWalkBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartWalkLedgeJump(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartActionSlow(FieldPlayerNogrid *player, u32 action, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
int FIELD_PLAYER_NOGRID_CheckActionSlow(FieldPlayerNogrid *player, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckSlowFromStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckSlowStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckSlowFromTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckSlowFromBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartSlowNone(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced);
void FIELD_PLAYER_NOGRID_StartSlowStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartSlowStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartSlowTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartSlowBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartSlowLedgeJump(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartActionRail(FieldPlayerNogrid *player, int action, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartRailNone(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced);
void FIELD_PLAYER_NOGRID_StartRailStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartRailStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartRailTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
void FIELD_PLAYER_NOGRID_StartRailBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckActionRail(FieldPlayerNogrid *player, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckRailFromStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckRailStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
int FIELD_PLAYER_NOGRID_CheckRailFromTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced);
u32 FIELD_PLAYER_NOGRID_CheckRailFromBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, u32 keyTrg, u32 keyCont, u16 dir, u32 forced);
void FIELD_PLAYER_NOGRID_SetFlags(FieldPlayerNogrid *player, u32 mask);
void FIELD_PLAYER_NOGRID_ClearFlags(FieldPlayerNogrid *player, u32 mask);
int FIELD_PLAYER_NOGRID_HasFlags(FieldPlayerNogrid *player, int mask);
void FIELD_PLAYER_NOGRID_SetForcedMove(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_ClearForcedMove(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_SetForcedMoveEnded(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_ClearForcedMoveEnded(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_ClearPending(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_SetSpinA(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_ClearSpinA(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_SetSpinB(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_ClearSpinB(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_SetFaceRight(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_ClearFaceRight(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_SetInputHold(FieldPlayerNogrid *player);
void FIELD_PLAYER_NOGRID_ClearInputHold(FieldPlayerNogrid *player);
u32 FIELD_PLAYER_NOGRID_GetForcedMoveKind(FieldPlayerNogrid *player);
u32 FIELD_PLAYER_NOGRID_RunForcedMove(FieldPlayerNogrid *player, u32 dir, u32 skipTileKind);
void FIELD_PLAYER_NOGRID_EndForcedMove(FieldPlayerNogrid *player);
u32 FIELD_PLAYER_NOGRID_ForcedSlide(FieldPlayerNogrid *player, u32 dir, u32 skipTileKind);
u32 FIELD_PLAYER_NOGRID_ForcedSlideSpinA(FieldPlayerNogrid *player, u32 dir);
u32 FIELD_PLAYER_NOGRID_ForcedSlideSpinB(FieldPlayerNogrid *player, u32 dir);
int FIELD_PLAYER_NOGRID_ForcedSlideWarnDir2(FieldPlayerNogrid *player, int dir, int skipTileKind);
int FIELD_PLAYER_NOGRID_ForcedSlideWarnDir3(FieldPlayerNogrid *player, int dir, int skipTileKind);
int FIELD_PLAYER_NOGRID_ForcedSlideFaceRight(FieldPlayerNogrid *player, int dir, int skipTileKind);
u32 FIELD_PLAYER_NOGRID_ForcedInputHold(FieldPlayerNogrid *player, u32 dir);
void FIELD_PLAYER_NOGRID_StartSpin(NogridSpin *spin, u8 variant);
void FIELD_PLAYER_NOGRID_StopSpin(NogridSpin *spin);
void FIELD_PLAYER_NOGRID_AdvanceSpin(NogridSpin *spin, Mmdl *mmdl);
int FIELD_PLAYER_NOGRID_InitInputHold(NogridInputHold *hold);
void FIELD_PLAYER_NOGRID_EnableInputHold(NogridInputHold *hold);
int FIELD_PLAYER_NOGRID_ResetInputHold(NogridInputHold *hold);
void FIELD_PLAYER_NOGRID_UpdateInputHold(NogridInputHold *hold, u32 dir, Mmdl *mmdl);
void FIELD_PLAYER_NOGRID_EndInputHoldFrame(NogridInputHold *hold);
int FIELD_PLAYER_NOGRID_GetInputHoldDir(NogridInputHold *hold, int dir);
u32 FIELD_PLAYER_NOGRID_IsInputHoldKept(NogridInputHold *hold);
int FIELD_PLAYER_NOGRID_HasConnectionAhead(FieldPlayerNogrid *player, u32 dir);

extern char d_021DDF04;                /* source file name string used by the heap allocation */
extern u16  gFieldPlayerNogridMmdlHeader[2];             /* header record handed to FLDMMDL_ChangeHeader; [1] is the object code */
extern u16  d_021DDEE0b[2];            /* second symbol at the same address (the pool needs both) */
extern const NogridForcedMoveFunc gFieldPlayerNogridForcedMoveFuncs[];  /* forced move handlers, indexed by tile kind */
extern const u8 gFieldPlayerNogridSpinDirs[][4];       /* spin tile direction sequences */


/* Creates the controller for the player core and attaches the player's field model. */
FieldPlayerNogrid *FIELD_PLAYER_NOGRID_Create(struct FieldPlayerCore *core, int heapId)
{
    FieldPlayerNogrid *player;

    player = GFL_HEAP_Alloc(heapId, 0x24, 1, &d_021DDF04, 0x1a0);
    player->core = core;
    player->fieldMap = FIELD_PLAYER_CORE_GetFieldMap(core);
    player->mmdl = FIELD_PLAYER_CORE_GetMmdl(player->core);
    if (FLDMMDL_GetMoveCode(player->mmdl) != 0x45) {
        gFieldPlayerNogridMmdlHeader[1] = FLDMMDL_GetObjCode(player->mmdl);
        FLDMMDL_ChangeHeader(player->mmdl, d_021DDEE0b);
    }
    player->railWork = FLDMMDL_RAIL_GetRailWork(player->mmdl);
    {
        RailLocation location = {0, 0, 0, 0, 0};
        FLDMMDL_RAIL_SetLocation(player->mmdl, &location);
    }
    FIELD_PLAYER_NOGRID_InitInputHold(&player->inputHold);
    {
        int kind = FIELD_PLAYER_CORE_GetFormCode(player->core);
        switch (kind) {
        case 2:
            FIELD_PLAYER_CORE_StartFormChange(player->core, 4);
            FIELD_PLAYER_CORE_FinishFormChange(player->core);
            break;
        case 3:
            FIELD_PLAYER_CORE_StartFormChange(player->core, 0x100);
            FIELD_PLAYER_CORE_FinishFormChange(player->core);
            break;
        }
    }
    return player;
}


void FIELD_PLAYER_NOGRID_Delete(FieldPlayerNogrid *player)
{
    GFL_HEAP_Free(player);
}


/* Attaches the model again after its header changed and stores its rail location. */
void FIELD_PLAYER_NOGRID_AttachMmdl(FieldPlayerNogrid *player, RailLocation *location)
{
    if (FLDMMDL_GetMoveCode(player->mmdl) != 0x45) {
        gFieldPlayerNogridMmdlHeader[1] = FLDMMDL_GetObjCode(player->mmdl);
        FLDMMDL_ChangeHeader(player->mmdl, d_021DDEE0b);
    }
    player->railWork = FLDMMDL_RAIL_GetRailWork(player->mmdl);
    FLDMMDL_RAIL_SetLocation(player->mmdl, location);
}


void FIELD_PLAYER_NOGRID_ClearRailWork(FieldPlayerNogrid *player)
{
    player->railWork = 0;
}


/* One frame: keys to direction, forced move, check, execute, bookkeeping. */
void FIELD_PLAYER_NOGRID_Update(FieldPlayerNogrid *player, u32 keyTrg, u32 keyCont)
{
    u32 inputDir;
    u32 moveDir;
    u32 action;

    inputDir = FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(player->core, keyCont);
    FIELD_PLAYER_CORE_StepFormChange(player->core);
    FIELD_PLAYER_NOGRID_UpdateInputHold(&player->inputHold, inputDir, player->mmdl);
    moveDir = FIELD_PLAYER_NOGRID_RunForcedMove(player, inputDir, 0);
    action = FIELD_PLAYER_NOGRID_CheckAction(player, moveDir, keyTrg, keyCont, 0);
    FIELD_PLAYER_NOGRID_UpdateFlagsAfterCheck(player, keyCont, action);
    FIELD_PLAYER_NOGRID_StartAction(player, action, moveDir, keyTrg, keyCont, 0);
    FIELD_PLAYER_NOGRID_UpdateSpin(player);
    FIELD_PLAYER_NOGRID_EndInputHoldFrame(&player->inputHold);
}


int FIELD_PLAYER_NOGRID_IsBlocked(FieldPlayerNogrid *player)
{
    if (player->moveMode == FIELD_PLAYER_NOGRID_MODE_BLOCKED) {
        return 1;
    }
    return 0;
}


u32 FIELD_PLAYER_NOGRID_IsForcedMove(FieldPlayerNogrid *player)
{
    u32 result = 1;
    if (FIELD_PLAYER_NOGRID_HasFlags(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE) == 0) {
        result = 0;
    }
    return result;
}


void FIELD_PLAYER_NOGRID_SetRailLocation(FieldPlayerNogrid *player, RailLocation *location)
{
    FLDMMDL_RAIL_SetLocation(player->mmdl, location);
}


void FIELD_PLAYER_NOGRID_GetNextRailLocation(FieldPlayerNogrid *player, RailLocation *outLocation)
{
    FLDMMDL_RAIL_GetNextLocation(player->mmdl, outLocation);
}


int FIELD_PLAYER_NOGRID_GetRailLocationByDir(FieldPlayerNogrid *player, u32 dir, RailLocation *outLocation)
{
    return FLDMMDL_RAIL_GetLocationByDir(player->mmdl, dir, outLocation);
}


void FIELD_PLAYER_NOGRID_GetRailPos(FieldPlayerNogrid *player, void *outPos)
{
    FIELD_RAIL_WORK_GetPos(player->railWork, outPos);
}


struct RailWork *FIELD_PLAYER_NOGRID_GetRailWork(FieldPlayerNogrid *player)
{
    return player->railWork;
}


/* Ends a blocked walk: frees the command, restores the facing direction. */
void FIELD_PLAYER_NOGRID_EndBlockedWalk(FieldPlayerNogrid *player)
{
    Mmdl *mmdl;
    int dir;

    if (player->moveMode == FIELD_PLAYER_NOGRID_MODE_BLOCKED) {
        mmdl = player->mmdl;
        dir = FLDMMDL_GetDirDisp(mmdl);
        FLDMMDL_FreeAcmd(mmdl);
        FLDMMDL_SetDirDispCheckPause(mmdl, dir);
        FLDMMDL_SetDrawStatus(mmdl, 0);
        FIELD_PLAYER_CORE_SetStepKind(player->core, 0);
    }
}


/* Picks the check function of the core's movement kind. */
int FIELD_PLAYER_NOGRID_CheckAction(FieldPlayerNogrid *player, u32 dir, u32 keyTrg, u32 keyCont, u32 forced)
{
    int action;

    switch (FIELD_PLAYER_CORE_GetFormCode(player->core)) {
    case FIELD_PLAYER_NOGRID_KIND_WALK:
        action = FIELD_PLAYER_NOGRID_CheckActionWalk(player, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_KIND_SLOW:
        action = FIELD_PLAYER_NOGRID_CheckActionSlow(player, keyTrg, keyCont, dir, forced);
        break;
    case 2:
    case 3:
        action = FIELD_PLAYER_NOGRID_CheckActionRail(player, keyTrg, keyCont, dir, forced);
        break;
    }
    return action;
}


/* Picks the start function of the core's movement kind. */
void FIELD_PLAYER_NOGRID_StartAction(FieldPlayerNogrid *player, u32 action, u32 dir, u32 keyTrg, u32 keyCont, u32 forced)
{
    switch (FIELD_PLAYER_CORE_GetFormCode(player->core)) {
    case FIELD_PLAYER_NOGRID_KIND_WALK:
        FIELD_PLAYER_NOGRID_StartActionWalk(player, action, keyTrg, keyCont, (u16)dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_KIND_SLOW:
        FIELD_PLAYER_NOGRID_StartActionSlow(player, action, keyTrg, keyCont, dir, forced);
        break;
    case 2:
    case 3:
        FIELD_PLAYER_NOGRID_StartActionRail(player, action, keyTrg, keyCont, (u16)dir, forced);
        break;
    }
}


void FIELD_PLAYER_NOGRID_UpdateFlagsAfterCheck(FieldPlayerNogrid *player, u32 keyCont, int action)
{
    FIELD_PLAYER_CORE_RememberKeyDirs(player->core, keyCont);
    FIELD_PLAYER_NOGRID_ClearPending(player);
    if (action == FIELD_PLAYER_NOGRID_ACTION_WALK)
        FIELD_PLAYER_NOGRID_ClearForcedMoveEnded(player);
}


/* Returns the hit bits of the tile next to the model in a direction. */
int FIELD_PLAYER_NOGRID_GetHitBits(FieldPlayerNogrid *player, Mmdl *mmdl, u32 dir, int *outAttr)
{
    return FLDMMDL_RAIL_GetHitBitsDir(mmdl, dir, outAttr);
}


/* Starts or stops the spin tile animation by the spin flags, then steps it. */
void FIELD_PLAYER_NOGRID_UpdateSpin(FieldPlayerNogrid *player)
{
    if (FIELD_PLAYER_NOGRID_HasFlags(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_A)) {
        FIELD_PLAYER_NOGRID_StartSpin(&player->spin, 0);
    } else if (FIELD_PLAYER_NOGRID_HasFlags(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_B)) {
        FIELD_PLAYER_NOGRID_StartSpin(&player->spin, 1);
    } else {
        FIELD_PLAYER_NOGRID_StopSpin(&player->spin);
    }
    FIELD_PLAYER_NOGRID_AdvanceSpin(&player->spin, player->mmdl);
}


void FIELD_PLAYER_NOGRID_StartActionWalk(FieldPlayerNogrid *player, u32 action, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    Mmdl *mmdl = player->mmdl;

    switch (action) {
    case FIELD_PLAYER_NOGRID_ACTION_NONE:
        FIELD_PLAYER_NOGRID_StartWalkNone(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_STAND:
        FIELD_PLAYER_NOGRID_StartWalkStand(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_WALK:
        FIELD_PLAYER_NOGRID_StartWalkStep(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_TURN:
        FIELD_PLAYER_NOGRID_StartWalkTurn(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_BLOCKED:
        FIELD_PLAYER_NOGRID_StartWalkBlocked(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_ACTION_LEDGE_JUMP:
        FIELD_PLAYER_NOGRID_StartWalkLedgeJump(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    }
}


/* Check for the walk kind: by the running mode. */
int FIELD_PLAYER_NOGRID_CheckActionWalk(FieldPlayerNogrid *player, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    int mode = player->moveMode;
    int action = 0;
    Mmdl *mmdl = player->mmdl;

    switch (mode) {
    case FIELD_PLAYER_NOGRID_MODE_STAND:
        action = FIELD_PLAYER_NOGRID_CheckWalkFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_MODE_WALK:
        action = FIELD_PLAYER_NOGRID_CheckWalkStep(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_MODE_TURN:
        action = FIELD_PLAYER_NOGRID_CheckWalkFromTurn(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    case FIELD_PLAYER_NOGRID_MODE_BLOCKED:
        action = FIELD_PLAYER_NOGRID_CheckWalkFromBlocked(player, mmdl, keyTrg, keyCont, dir, forced);
        break;
    }
    return action;
}


/* Walk kind, model standing: stand, turn first, or check the step. */
int FIELD_PLAYER_NOGRID_CheckWalkFromStand(FieldPlayerNogrid *player, Mmdl *mmdl, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
        if (dir != FIELD_PLAYER_NOGRID_DIR_NONE) {
            if (dir != FLDMMDL_GetDirDisp(mmdl) && forced == 0) {
                return FIELD_PLAYER_NOGRID_ACTION_TURN;
            }
            return FIELD_PLAYER_NOGRID_CheckWalkStep(player, mmdl, keyTrg, keyCont, dir, forced);
        }
        return FIELD_PLAYER_NOGRID_ACTION_STAND;
    }
    return FIELD_PLAYER_NOGRID_ACTION_NONE;
}


/* Walk kind, step check: walk, bump into a wall or jump a ledge by the hit bits of the next tile. */
int FIELD_PLAYER_NOGRID_CheckWalkStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    RailLocation nextLocation;
    u32 hitBits;
    u32 attr;
    u16 attrKind;
    int ledgeDir;

    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return FIELD_PLAYER_NOGRID_CheckWalkFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    hitBits = FIELD_PLAYER_NOGRID_GetHitBits(player, mmdl, dir, 0);
    if (forced == 1 && (hitBits & 2)) {
        hitBits = 0;
    }
    if (hitBits == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_WALK;
    }
    if (hitBits & 2) {
        FLDMMDL_RAIL_GetLocationByDir(mmdl, dir, &nextLocation);
        attr = FLDMMDL_RAIL_MOVE_GetLocationAttr(mmdl, &nextLocation);
        ledgeDir = FIELD_PLAYER_NOGRID_DIR_NONE;
        attrKind = MAP_ATTR_GetTerrainId(attr);
        MAP_ATTR_GetFlags(attr);
        if (MAP_ATTR_IsLedgeNorth(attrKind)) {
            ledgeDir = 0;
        } else if (MAP_ATTR_IsLedgeSouth(attrKind)) {
            ledgeDir = 1;
        } else if (MAP_ATTR_IsLedgeWest(attrKind)) {
            ledgeDir = 2;
        } else if (MAP_ATTR_IsLedgeEast(attrKind)) {
            ledgeDir = 3;
        }
        if (ledgeDir != FIELD_PLAYER_NOGRID_DIR_NONE && ledgeDir == dir) {
            return FIELD_PLAYER_NOGRID_ACTION_LEDGE_JUMP;
        }
    }
    return FIELD_PLAYER_NOGRID_ACTION_BLOCKED;
}


/* Walk kind, model turning. */
int FIELD_PLAYER_NOGRID_CheckWalkFromTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return FIELD_PLAYER_NOGRID_CheckWalkFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return FIELD_PLAYER_NOGRID_CheckWalkStep(player, mmdl, keyTrg, keyCont, dir, forced);
}


/* Walk kind, model walking into a wall: a new direction frees the command first. */
int FIELD_PLAYER_NOGRID_CheckWalkFromBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    int facing = FLDMMDL_GetDirDisp(mmdl);
    if (dir != FIELD_PLAYER_NOGRID_DIR_NONE && dir != facing) {
        FLDMMDL_FreeAcmd(mmdl);
        return FIELD_PLAYER_NOGRID_CheckWalkStep(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return FIELD_PLAYER_NOGRID_CheckWalkFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return FIELD_PLAYER_NOGRID_CheckWalkStep(player, mmdl, keyTrg, keyCont, dir, forced);
}


/* Walk kind, no action. */
void FIELD_PLAYER_NOGRID_StartWalkNone(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced)
{
}


/* Walk kind, stand: face the direction (the model's own one when no key). */
void FIELD_PLAYER_NOGRID_StartWalkStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        dir = FLDMMDL_GetDirDisp(mmdl);
    }
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_STAND;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 0);
}


/* Walk kind, step: forced step, run (B held) or walk. */
void FIELD_PLAYER_NOGRID_StartWalkStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    int acmdBase;
    if (forced == 1) {
        acmdBase = 0x14;
    } else if (keyCont & 2) {
        acmdBase = 0x58;
    } else {
        acmdBase = 0xc;
    }
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, acmdBase));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 1);
}


void FIELD_PLAYER_NOGRID_StartWalkTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x28));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_TURN;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 2);
}


/* Walk kind, blocked: bump animation; the bump sound plays when the map has no connection there. */
void FIELD_PLAYER_NOGRID_StartWalkBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x1c));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_BLOCKED;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 0);
    if (FIELD_PLAYER_NOGRID_HasConnectionAhead(player, dir) == 0) {
        GFL_USE_PlaySeDefaultVolume(0x55a);
    }
}


void FIELD_PLAYER_NOGRID_StartWalkLedgeJump(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x38));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 1);
}


void FIELD_PLAYER_NOGRID_StartActionSlow(FieldPlayerNogrid *player, u32 action, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    Mmdl *mmdl = player->mmdl;
    switch (action) {
    case 0: FIELD_PLAYER_NOGRID_StartSlowNone(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 1: FIELD_PLAYER_NOGRID_StartSlowStand(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 2: FIELD_PLAYER_NOGRID_StartSlowStep(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 3: FIELD_PLAYER_NOGRID_StartSlowTurn(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 4: FIELD_PLAYER_NOGRID_StartSlowBlocked(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 5: FIELD_PLAYER_NOGRID_StartSlowLedgeJump(player, mmdl, keyTrg, keyCont, dir, forced); break;
    }
}


int FIELD_PLAYER_NOGRID_CheckActionSlow(FieldPlayerNogrid *player, int keyTrg, int keyCont, u16 dir, int forced)
{
    int mode = player->moveMode;
    int action = 0;
    Mmdl *mmdl = player->mmdl;
    switch (mode) {
    case 0: action = FIELD_PLAYER_NOGRID_CheckSlowFromStand(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 1: action = FIELD_PLAYER_NOGRID_CheckSlowStep(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 2: action = FIELD_PLAYER_NOGRID_CheckSlowFromTurn(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 3: action = FIELD_PLAYER_NOGRID_CheckSlowFromBlocked(player, mmdl, keyTrg, keyCont, dir, forced); break;
    }
    return action;
}


/* Slow kind, same checks as the walk kind. */
int FIELD_PLAYER_NOGRID_CheckSlowFromStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
        if (dir != FIELD_PLAYER_NOGRID_DIR_NONE) {
            if (dir != FLDMMDL_GetDirDisp(mmdl) && forced == 0) {
                return FIELD_PLAYER_NOGRID_ACTION_TURN;
            }
            return FIELD_PLAYER_NOGRID_CheckSlowStep(player, mmdl, keyTrg, keyCont, dir, forced);
        }
        return FIELD_PLAYER_NOGRID_ACTION_STAND;
    }
    return FIELD_PLAYER_NOGRID_ACTION_NONE;
}


int FIELD_PLAYER_NOGRID_CheckSlowStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    RailLocation nextLocation;
    u32 hitBits;
    u32 attr;
    u16 attrKind;
    int ledgeDir;

    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return FIELD_PLAYER_NOGRID_CheckSlowFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    hitBits = FIELD_PLAYER_NOGRID_GetHitBits(player, mmdl, dir, 0);
    if (forced == 1 && (hitBits & 2)) {
        hitBits = 0;
    }
    if (hitBits == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_WALK;
    }
    if (hitBits & 2) {
        FLDMMDL_RAIL_GetLocationByDir(mmdl, dir, &nextLocation);
        attr = FLDMMDL_RAIL_MOVE_GetLocationAttr(mmdl, &nextLocation);
        ledgeDir = FIELD_PLAYER_NOGRID_DIR_NONE;
        attrKind = MAP_ATTR_GetTerrainId(attr);
        MAP_ATTR_GetFlags(attr);
        if (MAP_ATTR_IsLedgeNorth(attrKind)) {
            ledgeDir = 0;
        } else if (MAP_ATTR_IsLedgeSouth(attrKind)) {
            ledgeDir = 1;
        } else if (MAP_ATTR_IsLedgeWest(attrKind)) {
            ledgeDir = 2;
        } else if (MAP_ATTR_IsLedgeEast(attrKind)) {
            ledgeDir = 3;
        }
        if (ledgeDir != FIELD_PLAYER_NOGRID_DIR_NONE && ledgeDir == dir) {
            return FIELD_PLAYER_NOGRID_ACTION_LEDGE_JUMP;
        }
    }
    return FIELD_PLAYER_NOGRID_ACTION_BLOCKED;
}


int FIELD_PLAYER_NOGRID_CheckSlowFromTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return FIELD_PLAYER_NOGRID_CheckSlowFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return FIELD_PLAYER_NOGRID_CheckSlowStep(player, mmdl, keyTrg, keyCont, dir, forced);
}


int FIELD_PLAYER_NOGRID_CheckSlowFromBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    int facing = FLDMMDL_GetDirDisp(mmdl);
    if (dir != FIELD_PLAYER_NOGRID_DIR_NONE && dir != facing) {
        FLDMMDL_FreeAcmd(mmdl);
        return FIELD_PLAYER_NOGRID_CheckSlowStep(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return FIELD_PLAYER_NOGRID_CheckSlowFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return FIELD_PLAYER_NOGRID_CheckSlowStep(player, mmdl, keyTrg, keyCont, dir, forced);
}


/* Slow kind, no action. */
void FIELD_PLAYER_NOGRID_StartSlowNone(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced)
{
}


void FIELD_PLAYER_NOGRID_StartSlowStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        dir = FLDMMDL_GetDirDisp(mmdl);
    }
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_STAND;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 0);
}


void FIELD_PLAYER_NOGRID_StartSlowStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x14));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 1);
}


void FIELD_PLAYER_NOGRID_StartSlowTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x28));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_TURN;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 2);
}


void FIELD_PLAYER_NOGRID_StartSlowBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x1c));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_BLOCKED;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 0);
    if (FIELD_PLAYER_NOGRID_HasConnectionAhead(player, dir) == 0) {
        GFL_USE_PlaySeDefaultVolume(0x55a);
    }
}


void FIELD_PLAYER_NOGRID_StartSlowLedgeJump(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x38));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 1);
}


void FIELD_PLAYER_NOGRID_StartActionRail(FieldPlayerNogrid *player, int action, int keyTrg, int keyCont, u16 dir, int forced)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(player->core);
    switch (action) {
    case 0: FIELD_PLAYER_NOGRID_StartRailNone(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 1: FIELD_PLAYER_NOGRID_StartRailStand(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 2: FIELD_PLAYER_NOGRID_StartRailStep(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 3: FIELD_PLAYER_NOGRID_StartRailTurn(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 4: FIELD_PLAYER_NOGRID_StartRailBlocked(player, mmdl, keyTrg, keyCont, dir, forced); break;
    }
}


/* Rail kind, no action. */
void FIELD_PLAYER_NOGRID_StartRailNone(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, int dir, int forced)
{
}


void FIELD_PLAYER_NOGRID_StartRailStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        dir = FLDMMDL_GetDirDisp(mmdl);
    }
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_STAND;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 0);
}


void FIELD_PLAYER_NOGRID_StartRailStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, (forced == 1) ? 0x14 : 0x10));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 1);
}


void FIELD_PLAYER_NOGRID_StartRailTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x28));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_TURN;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 2);
}


void FIELD_PLAYER_NOGRID_StartRailBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x1c));
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_BLOCKED;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 0);
    if (FIELD_PLAYER_NOGRID_HasConnectionAhead(player, dir) == 0) {
        GFL_USE_PlaySeDefaultVolume(0x55a);
    }
}


/* Check for the rail kinds: by the running mode, on the core's model. */
int FIELD_PLAYER_NOGRID_CheckActionRail(FieldPlayerNogrid *player, int keyTrg, int keyCont, u16 dir, int forced)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(player->core);
    int action = 0;
    switch (player->moveMode) {
    case 0: action = FIELD_PLAYER_NOGRID_CheckRailFromStand(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 1: action = FIELD_PLAYER_NOGRID_CheckRailStep(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 2: action = FIELD_PLAYER_NOGRID_CheckRailFromTurn(player, mmdl, keyTrg, keyCont, dir, forced); break;
    case 3: action = FIELD_PLAYER_NOGRID_CheckRailFromBlocked(player, mmdl, keyTrg, keyCont, dir, forced); break;
    }
    return action;
}


int FIELD_PLAYER_NOGRID_CheckRailFromStand(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
        if (dir != FIELD_PLAYER_NOGRID_DIR_NONE) {
            if (dir != FLDMMDL_GetDirDisp(mmdl) && forced == 0) {
                return FIELD_PLAYER_NOGRID_ACTION_TURN;
            }
            return FIELD_PLAYER_NOGRID_CheckRailStep(player, mmdl, keyTrg, keyCont, dir, forced);
        }
        return FIELD_PLAYER_NOGRID_ACTION_STAND;
    }
    return FIELD_PLAYER_NOGRID_ACTION_NONE;
}


/* Rail kind, step check: the next tile's attribute decides between walk and bump. */
int FIELD_PLAYER_NOGRID_CheckRailStep(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    int hitBits;
    int attr;
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return FIELD_PLAYER_NOGRID_CheckRailFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    hitBits = FIELD_PLAYER_NOGRID_GetHitBits(player, mmdl, dir, &attr);
    if (forced == 1 && hitBits != 0 && (hitBits & 0x10) == 0) {
        hitBits = 0;
    }
    if (attr != -1) {
        int attrBits;
        MAP_ATTR_GetTerrainId(attr);
        attrBits = MAP_ATTR_GetFlags(attr);
        if (hitBits == 0) {
            if (attrBits & 2) {
                return FIELD_PLAYER_NOGRID_ACTION_WALK;
            }
            if (forced == 1) {
                return FIELD_PLAYER_NOGRID_ACTION_WALK;
            }
        }
    }
    return FIELD_PLAYER_NOGRID_ACTION_BLOCKED;
}


int FIELD_PLAYER_NOGRID_CheckRailFromTurn(FieldPlayerNogrid *player, Mmdl *mmdl, int keyTrg, int keyCont, u16 dir, int forced)
{
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    }
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
        return FIELD_PLAYER_NOGRID_CheckRailFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    return FIELD_PLAYER_NOGRID_CheckRailStep(player, mmdl, keyTrg, keyCont, dir, forced);
}


u32 FIELD_PLAYER_NOGRID_CheckRailFromBlocked(FieldPlayerNogrid *player, Mmdl *mmdl, u32 keyTrg, u32 keyCont, u16 dir, u32 forced)
{
    u32 facing = FLDMMDL_GetDirDisp(mmdl);

    if (dir != FIELD_PLAYER_NOGRID_DIR_NONE && dir != facing) {
        FLDMMDL_FreeAcmd(mmdl);
        return FIELD_PLAYER_NOGRID_CheckRailStep(player, mmdl, keyTrg, keyCont, dir, forced);
    }
    if (!FLDMMDL_CheckPossibleAcmd(mmdl))
        return FIELD_PLAYER_NOGRID_ACTION_NONE;
    if (dir == FIELD_PLAYER_NOGRID_DIR_NONE)
        return FIELD_PLAYER_NOGRID_CheckRailFromStand(player, mmdl, keyTrg, keyCont, dir, forced);
    return FIELD_PLAYER_NOGRID_CheckRailStep(player, mmdl, keyTrg, keyCont, dir, forced);
}


void FIELD_PLAYER_NOGRID_SetFlags(FieldPlayerNogrid *player, u32 mask)
{
    player->flags |= mask;
}


void FIELD_PLAYER_NOGRID_ClearFlags(FieldPlayerNogrid *player, u32 mask)
{
    player->flags &= ~mask;
}


int FIELD_PLAYER_NOGRID_HasFlags(FieldPlayerNogrid *player, int mask)
{
    if (player->flags & mask) {
        return 1;
    }
    return 0;
}


void FIELD_PLAYER_NOGRID_SetForcedMove(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_SetFlags(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE);
}


void FIELD_PLAYER_NOGRID_ClearForcedMove(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_ClearFlags(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE);
}


void FIELD_PLAYER_NOGRID_SetForcedMoveEnded(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_SetFlags(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE_ENDED);
}


void FIELD_PLAYER_NOGRID_ClearForcedMoveEnded(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_ClearFlags(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE_ENDED);
}


void FIELD_PLAYER_NOGRID_ClearPending(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_ClearFlags(player, FIELD_PLAYER_NOGRID_FLAG_PENDING);
}


void FIELD_PLAYER_NOGRID_SetSpinA(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_SetFlags(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_A);
}


void FIELD_PLAYER_NOGRID_ClearSpinA(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_ClearFlags(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_A);
}


void FIELD_PLAYER_NOGRID_SetSpinB(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_SetFlags(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_B);
}


void FIELD_PLAYER_NOGRID_ClearSpinB(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_ClearFlags(player, FIELD_PLAYER_NOGRID_FLAG_SPIN_B);
}


void FIELD_PLAYER_NOGRID_SetFaceRight(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_SetFlags(player, FIELD_PLAYER_NOGRID_FLAG_FACE_RIGHT);
}


void FIELD_PLAYER_NOGRID_ClearFaceRight(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_ClearFlags(player, FIELD_PLAYER_NOGRID_FLAG_FACE_RIGHT);
}


void FIELD_PLAYER_NOGRID_SetInputHold(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_SetFlags(player, FIELD_PLAYER_NOGRID_FLAG_INPUT_HOLD);
}


void FIELD_PLAYER_NOGRID_ClearInputHold(FieldPlayerNogrid *player)
{
    FIELD_PLAYER_NOGRID_ClearFlags(player, FIELD_PLAYER_NOGRID_FLAG_INPUT_HOLD);
}


/* Reads the tile under the model; returns the forced move kind (an index of the
 * handler table, 0 for none). */
u32 FIELD_PLAYER_NOGRID_GetForcedMoveKind(FieldPlayerNogrid *player)
{
    u32 attr = FLDMMDL_GetNowAttr(player->mmdl);

    if (!FIELD_PLAYER_NOGRID_HasFlags(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE_ENDED)) {
        attr = MAP_ATTR_GetTerrainId(attr);
        if (MAP_ATTR_IsForcedSlide(attr) == 1)
            return 1;
        if (RAIL_ATTR_IsForceMoveUp(attr) == 1)
            return 2;
        if (RAIL_ATTR_IsForceMoveDown(attr) == 1)
            return 3;
        if (RAIL_ATTR_IsForceMoveLeft(attr) == 1)
            return 4;
        if (RAIL_ATTR_IsForceMoveRight(attr) == 1)
            return 5;
        if (RAIL_ATTR_IsForceMoveStop(attr) == 1)
            return 6;
        if (RAIL_ATTR_IsSlipDown(attr) == 1)
            return 7;
    }
    return 0;
}


/* Runs the forced move of the tile under the model, or ends a running one. */
u32 FIELD_PLAYER_NOGRID_RunForcedMove(FieldPlayerNogrid *player, u32 dir, u32 skipTileKind)
{
    u32 kind;

    if (!FLDMMDL_CheckPossibleAcmd(player->mmdl))
        return dir;
    if (skipTileKind == 0) {
        kind = FIELD_PLAYER_NOGRID_GetForcedMoveKind(player);
        if (kind != 0)
            return gFieldPlayerNogridForcedMoveFuncs[kind](player, dir, skipTileKind);
    }
    FIELD_PLAYER_NOGRID_EndForcedMove(player);
    return dir;
}


/* Ends every forced move state that is set. */
void FIELD_PLAYER_NOGRID_EndForcedMove(FieldPlayerNogrid *player)
{
    Mmdl *mmdl = player->mmdl;

    if (FIELD_PLAYER_NOGRID_HasFlags(player, 0x59))
        FLDMMDL_ClearStatusBit(mmdl, 0x18);
    if (FIELD_PLAYER_NOGRID_HasFlags(player, FIELD_PLAYER_NOGRID_FLAG_FORCED_MOVE)) {
        FIELD_PLAYER_NOGRID_ClearForcedMove(player);
        FIELD_PLAYER_NOGRID_SetForcedMoveEnded(player);
        FIELD_PLAYER_CORE_SetStepKind(player->core, 0);
    }
    if (FIELD_PLAYER_NOGRID_HasFlags(player, 0x18)) {
        FIELD_PLAYER_NOGRID_ClearSpinA(player);
        FIELD_PLAYER_NOGRID_ClearSpinB(player);
        FLDMMDL_SetDirAll(mmdl, FLDMMDL_MOVE_GetDirTableValue(FLDMMDL_GetDirMove(mmdl)));
    }
    if (FIELD_PLAYER_NOGRID_HasFlags(player, FIELD_PLAYER_NOGRID_FLAG_FACE_RIGHT)) {
        FIELD_PLAYER_NOGRID_ClearFaceRight(player);
        FLDMMDL_SetDirAll(mmdl, 3);
    }
    if (FIELD_PLAYER_NOGRID_HasFlags(player, FIELD_PLAYER_NOGRID_FLAG_INPUT_HOLD)) {
        FIELD_PLAYER_NOGRID_ClearInputHold(player);
        FIELD_PLAYER_NOGRID_ResetInputHold(&player->inputHold);
    }
}


/* Forced move: keep sliding in the model's move direction until blocked. */
u32 FIELD_PLAYER_NOGRID_ForcedSlide(FieldPlayerNogrid *player, u32 dir, u32 skipTileKind)
{
    Mmdl *mmdl = player->mmdl;
    u32 moveDir = FLDMMDL_GetDirMove(mmdl);

    if (FIELD_PLAYER_NOGRID_GetHitBits(player, mmdl, moveDir, 0)) {
        FIELD_PLAYER_NOGRID_EndForcedMove(player);
        return dir;
    }
    FIELD_PLAYER_NOGRID_SetForcedMove(player);
    FIELD_PLAYER_NOGRID_ClearSpinA(player);
    FIELD_PLAYER_NOGRID_ClearSpinB(player);
    FLDMMDL_SetDirDispCheckPause(mmdl, moveDir);
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(moveDir, 0x10));
    FLDMMDL_SetStatusBit(mmdl, 0x18);
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 1);
    return moveDir;
}


/* Forced move: slide with the first spin animation. */
u32 FIELD_PLAYER_NOGRID_ForcedSlideSpinA(FieldPlayerNogrid *player, u32 dir)
{
    Mmdl *mmdl = player->mmdl;
    u32 moveDir = FLDMMDL_GetDirMove(mmdl);

    if (FIELD_PLAYER_NOGRID_GetHitBits(player, mmdl, moveDir, 0)) {
        FIELD_PLAYER_NOGRID_EndForcedMove(player);
        return dir;
    }
    FIELD_PLAYER_NOGRID_SetForcedMove(player);
    FIELD_PLAYER_NOGRID_SetSpinA(player);
    FIELD_PLAYER_NOGRID_ClearSpinB(player);
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(moveDir, 0x10));
    FLDMMDL_SetStatusBit(mmdl, 0x18);
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 1);
    return moveDir;
}


/* Forced move: slide with the second spin animation. */
u32 FIELD_PLAYER_NOGRID_ForcedSlideSpinB(FieldPlayerNogrid *player, u32 dir)
{
    Mmdl *mmdl = player->mmdl;
    u32 moveDir = FLDMMDL_GetDirMove(mmdl);

    if (FIELD_PLAYER_NOGRID_GetHitBits(player, mmdl, moveDir, 0)) {
        FIELD_PLAYER_NOGRID_EndForcedMove(player);
        return dir;
    }
    FIELD_PLAYER_NOGRID_SetForcedMove(player);
    FIELD_PLAYER_NOGRID_SetSpinB(player);
    FIELD_PLAYER_NOGRID_ClearSpinA(player);
    FLDMMDL_SetAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(moveDir, 0x10));
    FLDMMDL_SetStatusBit(mmdl, 0x18);
    player->moveMode = FIELD_PLAYER_NOGRID_MODE_WALK;
    FIELD_PLAYER_CORE_SetStepKind(player->core, 1);
    return moveDir;
}


/* Forced move: a slide that the model must not enter with move direction 2. */
int FIELD_PLAYER_NOGRID_ForcedSlideWarnDir2(FieldPlayerNogrid *player, int dir, int skipTileKind)
{
    if (FLDMMDL_GetDirMove(player->mmdl) == 2) {
        GFL_USE_PlaySeDefaultVolume(0x55e);
    }
    return FIELD_PLAYER_NOGRID_ForcedSlide(player, dir, skipTileKind);
}


/* Forced move: a slide that the model must not enter with move direction 3. */
int FIELD_PLAYER_NOGRID_ForcedSlideWarnDir3(FieldPlayerNogrid *player, int dir, int skipTileKind)
{
    if (FLDMMDL_GetDirMove(player->mmdl) == 3) {
        GFL_USE_PlaySeDefaultVolume(0x55e);
    }
    return FIELD_PLAYER_NOGRID_ForcedSlide(player, dir, skipTileKind);
}


/* Forced move: a slide that ends facing right. */
int FIELD_PLAYER_NOGRID_ForcedSlideFaceRight(FieldPlayerNogrid *player, int dir, int skipTileKind)
{
    int result = FIELD_PLAYER_NOGRID_ForcedSlide(player, dir, skipTileKind);
    FIELD_PLAYER_NOGRID_SetFaceRight(player);
    return result;
}


/* Forced move: the held direction keeps the model going while the keys are idle. */
u32 FIELD_PLAYER_NOGRID_ForcedInputHold(FieldPlayerNogrid *player, u32 dir)
{
    u32 result;

    if (!FIELD_PLAYER_NOGRID_HasFlags(player, FIELD_PLAYER_NOGRID_FLAG_INPUT_HOLD)) {
        FIELD_PLAYER_NOGRID_SetInputHold(player);
        FIELD_PLAYER_NOGRID_EnableInputHold(&player->inputHold);
    }
    result = (u16)FIELD_PLAYER_NOGRID_GetInputHoldDir(&player->inputHold, dir);
    if (FIELD_PLAYER_NOGRID_IsInputHoldKept(&player->inputHold)) {
        FLDMMDL_SetStatusBit(player->mmdl, 0x18);
        FLDMMDL_SetAcmd(player->mmdl, FLDMMDL_ACMD_ConvertCodeByDir(result, 8));
        FIELD_PLAYER_CORE_SetStepKind(player->core, 1);
        result = FIELD_PLAYER_NOGRID_DIR_NONE;
    } else {
        FLDMMDL_ClearStatusBit(player->mmdl, 0x18);
    }
    return result;
}


/* Starts the spin animation of a variant (or keeps it running). */
void FIELD_PLAYER_NOGRID_StartSpin(NogridSpin *spin, u8 variant)
{
    if (spin->active != 1 || variant != spin->variant) {
        GFL_USE_PlaySeDefaultVolume(0x6d1);
        spin->active = 1;
        spin->variant = variant;
        spin->phase = 0;
    }
}


void FIELD_PLAYER_NOGRID_StopSpin(NogridSpin *spin)
{
    if (spin->active) {
        spin->active = 0;
        spin->phase = 0;
        GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(0x6d1));
    }
}


/* Turns the model to the next direction of the spin sequence. */
void FIELD_PLAYER_NOGRID_AdvanceSpin(NogridSpin *spin, Mmdl *mmdl)
{
    if (spin->active) {
        spin->phase = (spin->phase + 1) % 4;
        FLDMMDL_SetDirDisp(mmdl, gFieldPlayerNogridSpinDirs[spin->variant][spin->phase]);
    }
}


int FIELD_PLAYER_NOGRID_InitInputHold(NogridInputHold *hold)
{
    MI_CpuFill8(hold, 0, 8);
    hold->heldDir = FIELD_PLAYER_NOGRID_DIR_NONE;
    return 9;
}


void FIELD_PLAYER_NOGRID_EnableInputHold(NogridInputHold *hold)
{
    hold->enabled = 1;
}


int FIELD_PLAYER_NOGRID_ResetInputHold(NogridInputHold *hold)
{
    return FIELD_PLAYER_NOGRID_InitInputHold(hold);
}


/* Counts the frames without a direction key; after 30 the hold is armed. */
void FIELD_PLAYER_NOGRID_UpdateInputHold(NogridInputHold *hold, u32 dir, Mmdl *mmdl)
{
    if (hold->enabled) {
        if (hold->idleDone != 0) {
            if (dir != FIELD_PLAYER_NOGRID_DIR_NONE) {
                hold->idleFrames = 0;
                hold->idleDone = 0;
                if (hold->keepDir)
                    hold->heldDir = dir;
            }
        } else if (dir == FIELD_PLAYER_NOGRID_DIR_NONE) {
            if (hold->idleFrames < 30)
                hold->idleFrames = hold->idleFrames + 1;
            else
                hold->idleDone = 1;
        }
        if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
            if (hold->idleDone == 0) {
                hold->keepDir = 0;
                hold->held = 0;
            } else {
                hold->keepDir = 1;
                hold->held = 1;
            }
        }
    }
}


void FIELD_PLAYER_NOGRID_EndInputHoldFrame(NogridInputHold *hold)
{
    if (hold->held) {
        hold->held = 0;
    }
    if (!hold->keepDir) {
        hold->heldDir = FIELD_PLAYER_NOGRID_DIR_NONE;
    }
}


int FIELD_PLAYER_NOGRID_GetInputHoldDir(NogridInputHold *hold, int dir)
{
    int result;
    if (hold->held) {
        return 1;
    }
    result = hold->heldDir;
    if (result == FIELD_PLAYER_NOGRID_DIR_NONE) {
        result = dir;
    }
    return result;
}


u32 FIELD_PLAYER_NOGRID_IsInputHoldKept(NogridInputHold *hold)
{
    return hold->keepDir;
}


/* True when the map has a connection at the tile ahead of the model in a direction. */
int FIELD_PLAYER_NOGRID_HasConnectionAhead(FieldPlayerNogrid *player, u32 dir)
{
    RailLocation location;
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(player->core);
    void *eventData;

    eventData = GAME_DATA_GetField158(ICA_ANIME_GetField1C(FIELDMAP_GetGameSystem(player->fieldMap)));
    FLDMMDL_RAIL_GetLocationByDir(mmdl, dir, &location);
    return EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(eventData, &location) != 0xFFFF;
}
