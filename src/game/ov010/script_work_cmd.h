#ifndef GAME_OV010_SCRIPT_WORK_CMD_H
#define GAME_OV010_SCRIPT_WORK_CMD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of script_work_cmd.c, prototypes copied from their definitions. */

struct ScrcmdWork;
typedef struct ScrcmdWork ScrcmdWork;

#include "../arm9/script_vm_types.h"
#include "../types.h"

int SCRIPT_WORK_CompareValues(unsigned int lhs, unsigned int rhs);
int SCRIPT_WORK_CmdCompareRegs(ScriptVm *vm);
int SCRIPT_WORK_CmdCompareRegConst(ScriptVm *vm);
int SCRIPT_WORK_CmdCompareWorkConst(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdCompareWorks(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdPushConst(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdPushWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdPopToWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdPopDiscard(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdAdd(ScriptVm *vm);
int SCRIPT_WORK_CmdSub(ScriptVm *vm);
int SCRIPT_WORK_CmdMul(ScriptVm *vm);
int SCRIPT_WORK_CmdDiv(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdPushEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdCompareStack(ScriptVm *vm);
int SCRIPT_WORK_CmdChangeScript(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_WaitChildScript(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdCallScript(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdEnd(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdJump(ScriptVm *vm);
int SCRIPT_WORK_CmdIfJump(ScriptVm *vm);
int SCRIPT_WORK_CmdIfCall(ScriptVm *vm);
int SCRIPT_WORK_CmdSetProcAction(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdGetContinueFlag(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdSetEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdResetEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdCheckEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdAddWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdSubWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdMulWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdDivWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdModWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdAndWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdOrWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdLoadWorkConst(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdCopyWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdLoadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdCallFieldCommand(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdPopAllBgm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdCallScriptEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_WaitKeyDecide(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdWaitKeyDecide(ScriptVm *vm);
int SCRIPT_WORK_WaitKeyAny(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdWaitKeyAny(ScriptVm *vm);
int SCRIPT_WORK_WaitReportSave(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_CmdReportSave(ScriptVm *vm, ScrcmdWork *cmdWork);
u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork);
unsigned short SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_GetPlayerZoneId(ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
