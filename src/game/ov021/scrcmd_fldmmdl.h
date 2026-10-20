#ifndef GAME_OV021_SCRCMD_FLDMMDL_H
#define GAME_OV021_SCRCMD_FLDMMDL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_fldmmdl.c, prototypes copied from their definitions. */

struct ScrcmdWork;
typedef struct ScrcmdWork ScrcmdWork;

#include "../ov010/fldmmdl_types.h"
#include "../types.h"
#include "../arm9/script_vm_types.h"

Mmdl *SCRCMD_FLDMMDL_GetMmdlByScriptId(ScrcmdWork *cmdWork, u32 objId);
int SCRCMD_FLDMMDL_StartMmdlAnime(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_CheckAnimeTasksDone(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_WaitAnimeTasks(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlMoveCode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_ChangeMmdlMoveCode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlGridPos(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetPlayerGridPos(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetPlayerDir(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_AddMmdl(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_DeleteMmdl(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_AddPartyFollowerMmdl(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_InitMmdlGridPosition(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlParam(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SetMmdlZoneDeleteOff(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_CheckMmdlPauseRelease(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_PauseMmdlsReleaseActive(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_PauseMmdls(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_FLDMMDL_UnpauseAllMmdls(ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_TurnTargetMmdlToPlayer(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SearchMmdlAtGrid(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SearchMmdlInFrontOfPlayer(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_CheckPlayerFormChangeDone(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartPlayerFormChangeAndWait(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartPlayerPosOffsetTween(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartPlayerOffsetTaskAgain(ScriptVm *vm, ScrcmdWork *cmdWork);
Mmdl *SCRCMD_FLDMMDL_GetPlayerMmdl(ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_TurnPlayerToFrontEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetPlayerForm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartMmdlMoveToGrid(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_CheckPlayerFormModel(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetPlayerRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartMmdlRailSlipDown(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SetPlayerRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SetMmdlRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartMmdlSpinRise(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartMmdlDropIn(ScriptVm *vm, ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
