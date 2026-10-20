#ifndef GAME_OV021_SCRCMD_GIMMICK_H
#define GAME_OV021_SCRCMD_GIMMICK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_gimmick.c, prototypes copied from their definitions. */

struct ScrcmdWork;

#include "../arm9/script_vm_types.h"

int SCRCMD_FIELD_GIMMICK_CART_LANES_CreateSwitchEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_CART_LANES_TransferSound(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_SetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_GetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_CreateEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CreateStateEventWithFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CreateStateEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_CART_LANES_UnlockLane(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_PLATE_DOORS_StartPlateEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_PLATE_DOORS_StartScriptedEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_CallLiftEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_CallElevatorEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_SnapElevatorToTop(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_SnapLiftToBottom(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_SWITCH_TOGGLE_StartSecondarySwitchEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEventU16(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_SWITCH_TOGGLE_ReplacePlayerIfRequirementMet(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
