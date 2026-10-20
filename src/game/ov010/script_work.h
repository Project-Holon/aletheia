#ifndef GAME_OV010_SCRIPT_WORK_H
#define GAME_OV010_SCRIPT_WORK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of script_work.c, prototypes copied from their definitions. */

struct ScriptCheckTask;
typedef struct ScriptCheckTask ScriptCheckTask;

#include "../ov010/script_work_types.h"
#include "../types.h"
#include "../arm9/script_vm_types.h"

int SCRIPT_WORK_InitFieldParam(ScriptFieldParam *fieldParam, void *gameSystem);
ScriptWork *SCRIPT_WORK_Create(u16 heapId, void *gameSystem, void *event, u16 scriptId, int targetObjParam, ScriptWork *parentWork);
int SCRIPT_WORK_Delete(ScriptWork *work);
void *SCRIPT_WORK_GetEvent(ScriptWork *work);
void *SCRIPT_WORK_GetGameSystem(ScriptWork *work);
ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(ScriptWork *work);
void *SCRIPT_WORK_GetCmdWork(ScriptWork *work);
void *SCRIPT_WORK_GetWordSet(ScriptWork *work);
void *SCRIPT_WORK_GetMsgBuffer(ScriptWork *work);
void *SCRIPT_WORK_GetTempBuffer(ScriptWork *work);
void SCRIPT_WORK_SetMsgData(ScriptWork *work, void *msgData);
void *SCRIPT_WORK_GetMsgData(ScriptWork *work);
u32 *SCRIPT_WORK_GetTrainerParam(ScriptWork *work);
u16 SCRIPT_WORK_GetScriptId(ScriptWork *work);
void *SCRIPT_WORK_GetTargetObj(ScriptWork *work);
void SCRIPT_WORK_SetTargetObj(ScriptWork *work, void *targetObj);
void *SCRIPT_WORK_GetUserWorkPtr(ScriptWork *work);
void *SCRIPT_WORK_GetUserWork(ScriptWork *work);
void SCRIPT_WORK_FreeUserWork(ScriptWork *work);
u16 *SCRIPT_WORK_GetLocalWork(ScriptWork *work, u32 id);
u16 *SCRIPT_WORK_GetWorkPtr(ScriptWork *work, void *gameData, unsigned int id);
unsigned short SCRIPT_WORK_GetWorkValue(ScriptWork *work, void *gameData, unsigned short id);
int SCRIPT_WORK_SetWorkValue(ScriptWork *work, u32 id, int value);
int SCRIPT_WORK_SetParams(ScriptWork *work, int param0, int param1, int param2, u16 param3);
void *SCRIPT_WORK_BackupLocalWork(ScriptWork *work);
void SCRIPT_WORK_RestoreLocalWork(ScriptWork *work, void *backup);
void SCRIPT_WORK_SetReturnScriptId(ScriptWork *work, u32 scriptId);
u32 SCRIPT_WORK_GetReturnScriptId(ScriptWork *work);
void SCRIPT_WORK_SetReturnParam(ScriptWork *work, u32 param);
u32 SCRIPT_WORK_GetReturnParam(ScriptWork *work);
ScriptWork *SCRIPT_WORK_SetReturnFlag(ScriptWork *work, u32 flag);
u32 SCRIPT_WORK_GetReturnFlag(ScriptWork *work);
ScriptTrainerEntry *SCRIPT_WORK_GetTrainerEntry(ScriptWork *work, int index);
void SCRIPT_WORK_ClearCheckFlags(void);
void SCRIPT_WORK_SetCheckFlag(int flagId);
void SCRIPT_WORK_ResetCheckFlag(int flagId);
int SCRIPT_WORK_CheckFlag(int flagId);
int SCRIPT_WORK_IsCheckFlagSet(int flagId);
int SCRIPT_WORK_RunCheckTask(int taskHandle, int taskArg, ScriptCheckTask *task);
void *SCRIPT_WORK_CreateCheckTask(ScriptVm *vm);
int SCRIPT_WORK_CmdNop(void);
int SCRIPT_WORK_CmdDummy(void);
int SCRIPT_WORK_CmdHalt(ScriptVm *vm);
int SCRIPT_WORK_WaitTime(ScriptVm *vm, void *cmdWork);
int SCRIPT_WORK_CmdTimeWait(ScriptVm *vm, void *cmdWork);
int SCRIPT_WORK_CmdCall(ScriptVm *vm, void *work);
int SCRIPT_WORK_CmdReturn(ScriptVm *vm, void *work);
int SCRIPT_WORK_CmdDebugWork(ScriptVm *vm, ScriptWork *work);
int SCRIPT_WORK_CmdDebugStack(ScriptVm *vm, ScriptWork *work);
int SCRIPT_WORK_CmdLoadRegValue(ScriptVm *vm);
/* END mkheaders: generated region */

#endif
