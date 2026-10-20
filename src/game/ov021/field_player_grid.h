#ifndef GAME_OV021_FIELD_PLAYER_GRID_H
#define GAME_OV021_FIELD_PLAYER_GRID_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_player_grid.c, prototypes copied from their definitions. */

#include "../ov021/field_player_types.h"
#include "../ov021/field_player_types.h"
#include "../types.h"
#include "../ov021/field_player_grid_types.h"
#include "../sdk_fx.h"
#include "../ov010/fldmmdl_types.h"

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
int FIELD_PLAYER_GRID_GetStepHitFlags(FieldPlayerGrid *grid, Mmdl *mmdl, u16 dir, int *outAttr);
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
int FIELD_PLAYER_GRID_GetHopStepHitFlags(FieldPlayerGrid *grid, Mmdl *mmdl, u16 dir, int *outAttr);
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
/* END mkheaders: generated region */

#endif
