#ifndef GAME_OV021_FIELD_PLAYER_CORE_H
#define GAME_OV021_FIELD_PLAYER_CORE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_player_core.c, prototypes copied from their definitions. */

struct PlayerWork;
struct GameSystem;
struct FieldEffectObj;

#include "../ov021/field_player_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../sdk_fx.h"
#include "../types.h"
#include "../ov010/fldmmdl_types.h"

FieldPlayerCore *FIELD_PLAYER_CORE_Create(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, u32 sex, u16 heapId);
void FIELD_PLAYER_CORE_Delete(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_UpdateStepPhase(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_GetPos(FieldPlayerCore *core, VecFx32 *out);
void FIELD_PLAYER_CORE_SetPos(FieldPlayerCore *core, VecFx32 *pos);
u16 FIELD_PLAYER_CORE_GetDirDisp(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetDirDisp(FieldPlayerCore *core, int dir);
void FIELD_PLAYER_CORE_SetObjCode(FieldPlayerCore *core, u32 objCode);
void FIELD_PLAYER_CORE_ClearRememberedObjCode(FieldPlayerCore *core);
FieldMap *FIELD_PLAYER_CORE_GetFieldMap(FieldPlayerCore *core);
Mmdl *FIELD_PLAYER_CORE_GetMmdl(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetStepKind(FieldPlayerCore *core, u32 stepKind);
u32 FIELD_PLAYER_CORE_GetStepKind(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetStepPhase(FieldPlayerCore *core, u32 stepPhase);
u32 FIELD_PLAYER_CORE_GetStepPhase(FieldPlayerCore *core);
u32 FIELD_PLAYER_CORE_GetFormCode(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetFormCode(FieldPlayerCore *core, u32 formCode);
u32 FIELD_PLAYER_CORE_GetSex(FieldPlayerCore *core);
struct GameSystem *FIELD_PLAYER_CORE_GetGameSystem(FieldPlayerCore *core);
struct PlayerWork *FIELD_PLAYER_CORE_GetPlayerWork(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_ApplyFormCodeModel(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetFormSlotModel(FieldPlayerCore *core, int formSlot);
int FIELD_PLAYER_CORE_WaitModelReady(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_GetFormSlot(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_CheckFormModel(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_CheckAnimePaused(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_CheckAcmdPossible(FieldPlayerCore *core);
u16 FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(FieldPlayerCore *core, u32 keys);
void FIELD_PLAYER_CORE_RememberKeyDirs(FieldPlayerCore *core, u32 keys);
void FIELD_PLAYER_CORE_SetRideEffect(FieldPlayerCore *core, struct FieldEffectObj *rideEffect);
struct FieldEffectObj *FIELD_PLAYER_CORE_GetRideEffect(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_ChangeModel(FieldPlayerCore *core, int objCode);
void FIELD_PLAYER_CORE_SetFormCodeModel(FieldPlayerCore *core, int formCode);
int FIELD_PLAYER_CORE_CheckPlainModel(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_CheckDrawProcReady(FieldPlayerCore *core);
u16 FIELD_PLAYER_CORE_SelectMoveDir(FieldPlayerCore *core, u32 keys);
void FIELD_PLAYER_CORE_StoreKeyDirs(FieldPlayerCore *core, int keys);
int FIELD_PLAYER_CORE_GetHorzDirFromKeys(u32 keys);
int FIELD_PLAYER_CORE_GetVertDirFromKeys(u32 keys);
u16 FIELD_PLAYER_CORE_RunFormSteps(FieldPlayerCore *core, int formSlot);
int FIELD_PLAYER_CORE_GetLowestFormSlot(u32 mask);
FieldPlayerCore *FIELD_PLAYER_CORE_StartFormChange(FieldPlayerCore *core, u32 mask);
int FIELD_PLAYER_CORE_StepFormChange(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_FinishFormChange(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_ChangeToObjCode(FieldPlayerCore *core, u32 objCode);
int FIELD_PLAYER_CORE_ChangeToFormSlot(FieldPlayerCore *core, u32 formSlot);
int FIELD_PLAYER_CORE_FinishFormSlotChange(FieldPlayerCore *core, int formSlot);
int FIELD_PLAYER_CORE_FormStepNormal(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepCycle(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepCycleDone(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSurf(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepRestoreModel(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepRestoreModelDone(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot4(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot4Done(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot5(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot5Done(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot6(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot6Done(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot9(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot9Done(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepDive(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot8(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_FormStepSlot8Done(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_PostZoneBgmChange(FieldPlayerCore *core);
/* END mkheaders: generated region */

#endif
