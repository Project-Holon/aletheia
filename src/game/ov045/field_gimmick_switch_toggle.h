#ifndef GAME_OV045_FIELD_GIMMICK_SWITCH_TOGGLE_H
#define GAME_OV045_FIELD_GIMMICK_SWITCH_TOGGLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_switch_toggle.c, prototypes copied from their definitions. */

struct FieldMap;
struct GameEvent;
struct GameSystem;
struct FldExpObjCnt;

#include "../ov045/field_gimmick_switch_toggle_types.h"

void FIELD_GIMMICK_SWITCH_TOGGLE_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SWITCH_TOGGLE_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SWITCH_TOGGLE_Update(struct FieldMap *fieldMap);
struct GameEvent *FIELD_GIMMICK_SWITCH_TOGGLE_StartSecondarySwitchEvent(struct GameSystem *gameSystem, int switchIndex);
struct GameEvent *FIELD_GIMMICK_SWITCH_TOGGLE_StartSwitchToggleEvent(struct GameSystem *gameSystem, int switchIndex);
void FIELD_GIMMICK_SWITCH_TOGGLE_ReplacePlayerIfRequirementMet(struct GameSystem *gameSystem, int requirementIndex);
int FIELD_GIMMICK_SWITCH_TOGGLE_IsRequirementMet(FieldGimmickSwitchToggleSave *save, int requirementIndex);
void FIELD_GIMMICK_SWITCH_TOGGLE_SetSwitchModelPose(struct FldExpObjCnt *expObj, int switchOn, int switchIndex, int usePrimaryModel);
int FIELD_GIMMICK_SWITCH_TOGGLE_IsSwitchOn(FieldGimmickSwitchToggleSave *save, int switchIndex);
int FIELD_GIMMICK_SWITCH_TOGGLE_SecondarySwitchEventProc(struct GameEvent *event, int *state, void *eventWork);
int FIELD_GIMMICK_SWITCH_TOGGLE_SwitchToggleEventProc(struct GameEvent *event, int *state, void *eventWork);
/* END mkheaders: generated region */

#endif
