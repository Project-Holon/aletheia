#ifndef GAME_OV021_FIELD_PLAYER_NOGRID_H
#define GAME_OV021_FIELD_PLAYER_NOGRID_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_player_nogrid.c, prototypes copied from their definitions. */

struct FieldPlayerCore;
struct RailWork;

#include "../ov021/field_player_nogrid_types.h"
#include "../arm9/zonedata_types.h"
#include "../types.h"
#include "../ov010/fldmmdl_types.h"

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
/* END mkheaders: generated region */

#endif
