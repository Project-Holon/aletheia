#ifndef GAME_OV021_FIELD_PLAYER_H
#define GAME_OV021_FIELD_PLAYER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_player.c, prototypes copied from their definitions. */

struct PlayerWork;
struct FieldEffectObj;
struct GameSystem;
struct Mmdl;
struct RailWork;

#include "../ov021/field_flash_shared_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../sdk_fx.h"
#include "../types.h"
#include "../ov010/fldmmdl_types.h"
#include "../arm9/zonedata_types.h"
#include "../ov021/field_player_types.h"

FieldPlayer *FIELD_PLAYER_Create(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, u32 sex, u16 heapId);
int FIELD_PLAYER_Delete(FieldPlayer *player);
void FIELD_PLAYER_SaveToPlayerWork(FieldPlayer *player);
GameEvent *FIELD_PLAYER_TryPushBoulder(FieldPlayer *player, int a, int b, int c);
void FIELD_PLAYER_StartFormChange(FieldPlayer *player, u32 mask);
int FIELD_PLAYER_StepFormChange(FieldPlayer *player);
void FIELD_PLAYER_FinishFormChange(FieldPlayer *player);
void FIELD_PLAYER_ResetMoveWork(FieldPlayer *player);
void FIELD_PLAYER_SetRideEffect(FieldPlayer *player, struct FieldEffectObj *rideEffect);
struct FieldEffectObj *FIELD_PLAYER_GetRideEffect(FieldPlayer *player);
u16 FIELD_PLAYER_ChooseMoveDirFromKeys(FieldPlayer *player, u32 keys);
u32 FIELD_PLAYER_CheckMoveBusy(FieldPlayer *player);
void FIELD_PLAYER_ChangeToNormalForm(FieldPlayer *player);
void FIELD_PLAYER_UpdateStepPhase(FieldPlayer *player);
void FIELD_PLAYER_GetPos(FieldPlayer *player, VecFx32 *out);
void FIELD_PLAYER_SetPos(FieldPlayer *player, VecFx32 *pos);
u16 FIELD_PLAYER_GetDirDisp(FieldPlayer *player);
void FIELD_PLAYER_SetDirDisp(FieldPlayer *player, int dir);
FieldMap *FIELD_PLAYER_GetFieldMap(FieldPlayer *player);
Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *player);
u32 FIELD_PLAYER_GetStepKind(FieldPlayer *player);
u32 FIELD_PLAYER_GetStepPhase(FieldPlayer *player);
u32 FIELD_PLAYER_GetFormCode(FieldPlayer *player);
void FIELD_PLAYER_SetFormCode(FieldPlayer *player, u32 formCode);
u32 FIELD_PLAYER_GetSex(FieldPlayer *player);
struct GameSystem *FIELD_PLAYER_GetGameSystem(FieldPlayer *player);
u32 FIELD_PLAYER_GetNowAttribute(FieldPlayer *player);
u32 FIELD_PLAYER_GetFrontAttribute(FieldPlayer *player, u32 dir);
u16 FIELD_PLAYER_GetFormObjCode(int sex, int formSlot);
int FIELD_PLAYER_GetObjCodeOfFormCode(int sex, int formCode);
int FIELD_PLAYER_GetFormSlotOfObjCode(u16 objCode);
int FIELD_PLAYER_CheckNotWaterForm(FieldPlayer *player);
void FIELD_PLAYER_SetObjCode(FieldPlayer *player, u32 objCode);
void FIELD_PLAYER_ClearRememberedObjCode(FieldPlayer *player);
int FIELD_PLAYER_CheckFormModel(FieldPlayer *player);
int FIELD_PLAYER_CheckAnimePaused(FieldPlayer *player);
struct Mmdl *FIELD_PLAYER_SearchFrontMmdl(FieldPlayer *player);
struct Mmdl *FIELD_PLAYER_SearchFrontMmdlHeight(FieldPlayer *player, u32 limit);
void FIELD_PLAYER_GetGridPosInDir(FieldPlayer *player, u32 dir, s16 *gridX, s16 *gridY, s16 *gridZ);
void FIELD_PLAYER_GetPosInDir(FieldPlayer *player, int dir, VecFx32 *out);
void FIELD_PLAYER_GetFrontGridPos(FieldPlayer *player, s16 *gridX, s16 *gridY, s16 *gridZ);
void FIELD_PLAYER_GetMoveOffsetInDir(FieldPlayer *player, int dir, s32 *out);
int FIELD_PLAYER_GetFormSlot(FieldPlayer *player);
int FIELD_PLAYER_WaitModelReady(FieldPlayer *player);
int FIELD_PLAYER_CheckSurfStartAttr(FieldPlayer *player, int a, int b);
int FIELD_PLAYER_CheckWaterfallClimbAttr(FieldPlayer *player, int attrA, int attrB);
void FIELD_PLAYER_ResetGridHold(FieldPlayer *player, int a);
void FIELD_PLAYER_StopGridForcedMove(FieldPlayer *player);
int FIELD_PLAYER_GetGridHopLanded(FieldPlayer *player);
void FIELD_PLAYER_SetGridHopLanded(FieldPlayer *player, int a);
int FIELD_PLAYER_CheckMoveRestrictFlag(FieldPlayer *player);
void FIELD_PLAYER_CreateGrid(FieldPlayer *player, u32 heapId);
void FIELD_PLAYER_MoveGrid(FieldPlayer *player, u32 a, u32 b, u32 c);
void FIELD_PLAYER_GetNowGridPos(FieldPlayer *player, u16 *gridX, u16 *gridY, u16 *gridZ);
int FIELD_PLAYER_IsGridHopping(FieldPlayer *player);
void FIELD_PLAYER_FinishGridHop(FieldPlayer *player);
void FIELD_PLAYER_CreateNogrid(FieldPlayer *player, u32 heapId);
void FIELD_PLAYER_UpdateNogrid(FieldPlayer *player, u32 a, u32 b);
void FIELD_PLAYER_AttachNogridMmdl(FieldPlayer *player, const RailLocation *a);
void FIELD_PLAYER_ResetNogrid(FieldPlayer *player);
u32 FIELD_PLAYER_IsNogridForcedMove(FieldPlayer *player);
struct RailWork *FIELD_PLAYER_GetNogridRailWork(FieldPlayer *player);
void FIELD_PLAYER_SetNogridRailLocation(FieldPlayer *player, void *a);
void FIELD_PLAYER_GetNogridNextRailLocation(FieldPlayer *player, void *a);
int FIELD_PLAYER_GetNogridLocationByDir(FieldPlayer *player, u32 a, void *b);
void FIELD_PLAYER_GetNogridRailPos(FieldPlayer *player, void *outPos);
FieldPlayerGrid *FIELD_PLAYER_GetGrid(FieldPlayer *player);
/* END mkheaders: generated region */

#endif
