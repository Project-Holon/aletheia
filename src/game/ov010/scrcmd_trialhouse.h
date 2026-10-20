#ifndef GAME_OV010_SCRCMD_TRIALHOUSE_H
#define GAME_OV010_SCRCMD_TRIALHOUSE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_trialhouse.c, prototypes copied from their definitions. */

struct ScrcmdWork;
typedef struct ScrcmdWork ScrcmdWork;

#include "../arm9/script_vm_types.h"

int SCRCMD_TRIALHOUSE_CreateWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_FreeWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_SetBattleMode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartPartySelect(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_LoadRecord(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartTrainerMessage(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartBattle(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_SetRecordSource(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_SetRank(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_GetRank(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartDownload(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_GetRankAndScore(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_GetSaveState(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartSaveEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartAward(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_GetClearFlags(ScriptVm *vm, ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
