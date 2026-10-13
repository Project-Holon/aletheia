/*
 * file:     script_work.c
 * unit:     yes
 * function: SCRIPT_WORK_InitFieldParam, SCRIPT_WORK_Create, SCRIPT_WORK_Delete, SCRIPT_WORK_GetEvent, SCRIPT_WORK_GetGameSystem, SCRIPT_WORK_ResetFieldParam, SCRIPT_WORK_GetCmdWork, SCRIPT_WORK_GetWordSet, SCRIPT_WORK_GetMsgBuffer, SCRIPT_WORK_GetTempBuffer, SCRIPT_WORK_SetMsgData, SCRIPT_WORK_GetMsgData, SCRIPT_WORK_GetTrainerParam, SCRIPT_WORK_GetScriptId, SCRIPT_WORK_GetTargetObj, SCRIPT_WORK_SetTargetObj, SCRIPT_WORK_GetUserWorkPtr, SCRIPT_WORK_GetUserWork, SCRIPT_WORK_FreeUserWork, SCRIPT_WORK_GetLocalWork, SCRIPT_WORK_GetWorkPtr, SCRIPT_WORK_GetWorkValue, SCRIPT_WORK_SetWorkValue, SCRIPT_WORK_SetParams, SCRIPT_WORK_BackupLocalWork, SCRIPT_WORK_RestoreLocalWork, SCRIPT_WORK_SetReturnScriptId, SCRIPT_WORK_GetReturnScriptId, SCRIPT_WORK_SetReturnParam, SCRIPT_WORK_GetReturnParam, SCRIPT_WORK_SetReturnFlag, SCRIPT_WORK_GetReturnFlag, SCRIPT_WORK_GetTrainerEntry, SCRIPT_WORK_ClearCheckFlags, SCRIPT_WORK_SetCheckFlag, SCRIPT_WORK_ResetCheckFlag, SCRIPT_WORK_CheckFlag, SCRIPT_WORK_IsCheckFlagSet, SCRIPT_WORK_RunCheckTask, SCRIPT_WORK_CreateCheckTask, SCRIPT_WORK_CmdNop, SCRIPT_WORK_CmdDummy, SCRIPT_WORK_CmdHalt, SCRIPT_WORK_WaitTime, SCRIPT_WORK_CmdTimeWait, SCRIPT_WORK_CmdCall, SCRIPT_WORK_CmdReturn, SCRIPT_WORK_CmdDebugWork, SCRIPT_WORK_CmdDebugStack, SCRIPT_WORK_CmdLoadRegValue
 * address:  0x02158E54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Original file script_work.c: the create function 0x02158E7C asserts with
 * "script_work.c". 0x02158E54 is called only from the script work create and
 * reset functions, so the cut before it is likely.
 *
 * script_work.c continues in unit_021592F0.c (0x021592F0..0x0215930C) and
 * script_work_cmd.c (script command handlers, 0x0215932C..0x02159B38). The
 * three ranges are contiguous and merge into this file at cut time.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020122C0  0x020122C0  thumb
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb
 *   VM_GetU32  0x0201134C  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   func_02082A7C  0x02082A7C  arm
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb
 *   func_0201EC74  0x0201EC74  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   SCRCMD_WORK_CreateCommon  0x0215A514  thumb  ov010
 *   sScriptWorkFileName     0x0217289C  data  ov010  a1
 *   func_0201ED04  0x0201ED04  thumb
 *   SCRCMD_WORK_DeleteCommon  0x0215A554  thumb  ov010
 *   FLDMMDL_GetObjId 0x0216D588 thumb ov010
 *   MIi_CpuCopy16 0x02082A60 arm
 *   gScriptCheckFlags 0x02172BA0 data a4
 *   gScriptCheckHandlers     0x021705F0  data  ov010
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   func_02011290  0x02011290  thumb
 *   SCRCMD_WORK_CountDownWait  0x0215A690  thumb  ov010
 *   SCRCMD_WORK_SetWaitCount   0x0215A684  thumb  ov010
 *   VM_GetU16   0x02011330  thumb
 *   VM_SetWait   0x020113D0  thumb
 *   VM_Call  0x020113B4  thumb
 *   VM_Return  0x020113C4  thumb
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   VM_PopStack  0x02011398  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   SCRIPT_SYS_CreateScriptEvent  0x02158920  thumb  ov010
 *   SCRIPT_SYS_IsChildScript  0x02158DB0  thumb  ov010
 */
#include "script_work_types.h"

typedef struct ScriptCheckTask ScriptCheckTask;
typedef int (*ScriptCheckHandler)(ScriptCheckTask *task, int *state);
typedef int (*ScriptCheckTaskFn)(int taskHandle, int taskArg, ScriptCheckTask *task);

/* Task state of the per-frame check run (15 handlers gated by the check flags). */
struct ScriptCheckTask {
    void *gameSystem;
    ScriptVm *vm;
    void *scriptCtl;
    int state;
    int index;
    int count;
};

typedef enum { SCRIPT_CHECK_BIT = 1 } ScriptCheckBit;

extern void *func_02030734(u32 heapId, u32 size, int align, const char *fileName, u16 line);
extern int func_020307B0(void *block);
extern int STRBUF_Delete(void *buffer);
extern void *GAMESYSTEM_GetGameData(void *gameSystem);
extern u32 GAME_DATA_GetEventWork(void *gameData);
extern void *func_020124E8(void *task);
extern void *func_020122C0(void *gameSystem, void *arg, ScriptCheckTaskFn callback, unsigned int size);
extern u16 *ZONEDATA_GetEventWorkAddress(u32 eventWork, u32 id);
extern u32 VM_GetU32(ScriptVm *vm);
extern void *GAMESYSTEM_GetFieldMap(void *gameSystem);
extern void *SCRCMD_WORK_GetGameSystem(ScriptVm *vm);
extern int func_02082A7C();
extern int FIELDMAP_GetMsgBg();
extern void *func_0201EC74(u32 count, u32 size, u16 heapId);
extern void *STRBUF_Create(u32 capacity, u32 heapId);
extern void *SCRCMD_WORK_CreateCommon(ScriptWork *work, int heapId);
extern int func_0201ED04();
extern int SCRCMD_WORK_DeleteCommon();
extern u16 FLDMMDL_GetObjId(void *obj);
extern void MIi_CpuCopy16(const void *src, void *dst, unsigned int size);
extern void *SCRCMD_WORK_GetScriptWork(ScriptVm *vm);
extern void func_02011290(ScriptVm *vm);
extern int SCRCMD_WORK_CountDownWait(void *cmdWork);
extern u16 VM_GetU16(ScriptVm *vm);
extern void SCRCMD_WORK_SetWaitCount(void *cmdWork, unsigned short count);
extern void VM_SetWait(ScriptVm *vm, ScriptWaitFn waitFn);
extern void VM_Call(ScriptVm *vm, u8 *target);
extern u32 VM_Return(ScriptVm *vm);
extern void *SCRCMD_WORK_GetGameData(void *work);
extern unsigned int SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScriptWork *work);
extern u32 VM_PopStack(ScriptVm *vm);
extern int SCRIPT_SYS_IsChildScript(ScriptWork *parentWork);
extern const char sScriptWorkFileName[];
extern int gScriptCheckFlags;
extern ScriptCheckHandler gScriptCheckHandlers[];

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
unsigned int SCRIPT_WORK_GetWorkValue(ScriptWork *work, void *gameData, unsigned int id);
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

int SCRIPT_WORK_InitFieldParam(ScriptFieldParam *fieldParam, void *gameSystem)
{
    void *fieldSystem = GAMESYSTEM_GetFieldMap(gameSystem);
    int result = func_02082A7C(0, fieldParam, 8);
    fieldParam->fieldSystem = fieldSystem;
    if (fieldSystem != 0) {
        result = FIELDMAP_GetMsgBg(fieldSystem);
        fieldParam->mapSystem = (void *)result;
    }
    return result;
}

ScriptWork *SCRIPT_WORK_Create(u16 heapId, void *gameSystem, void *event, u16 scriptId, int targetObjParam, ScriptWork *parentWork)
{
    ScriptWork *work = func_02030734(heapId, 0x14C, 1, sScriptWorkFileName, 0xAF);
    work->magic = SCRIPT_WORK_MAGIC;
    work->heapId = heapId;
    work->gameSystem = gameSystem;
    work->event = event;
    work->scriptId = scriptId;
    work->targetObj = 0;
    work->targetObjParam = targetObjParam;
    work->parentWork = parentWork;
    work->isChild = SCRIPT_SYS_IsChildScript(parentWork);
    if (work->isChild == 0) {
        work->wordSet = func_0201EC74(0x1C, 0x40, heapId);
        work->msgBuffer = STRBUF_Create(0x500, heapId);
        work->tempBuffer = STRBUF_Create(0x500, heapId);
    } else {
        work->wordSet = 0;
        work->msgBuffer = 0;
        work->tempBuffer = 0;
    }
    work->cmdWork = SCRCMD_WORK_CreateCommon(work, heapId);
    SCRIPT_WORK_InitFieldParam(&work->fieldParam, gameSystem);
    if (work->isChild == 0)
        SCRIPT_WORK_ClearCheckFlags();
    return work;
}

int SCRIPT_WORK_Delete(ScriptWork *work)
{
    work->magic = 0;
    if (work->wordSet != 0)
        func_0201ED04(work->wordSet);
    if (work->msgBuffer != 0)
        STRBUF_Delete(work->msgBuffer);
    if (work->tempBuffer != 0)
        STRBUF_Delete(work->tempBuffer);
    SCRCMD_WORK_DeleteCommon(work->cmdWork);
    return func_020307B0(work);
}

void *SCRIPT_WORK_GetEvent(ScriptWork *work) { return work->event; }

void *SCRIPT_WORK_GetGameSystem(ScriptWork *work) { return work->gameSystem; }

ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(ScriptWork *work)
{
    SCRIPT_WORK_InitFieldParam(&work->fieldParam, work->gameSystem);
    return &work->fieldParam;
}

void *SCRIPT_WORK_GetCmdWork(ScriptWork *work) { return work->cmdWork; }

void *SCRIPT_WORK_GetWordSet(ScriptWork *work) { return work->wordSet; }

void *SCRIPT_WORK_GetMsgBuffer(ScriptWork *work) { return work->msgBuffer; }

void *SCRIPT_WORK_GetTempBuffer(ScriptWork *work) { return work->tempBuffer; }

void SCRIPT_WORK_SetMsgData(ScriptWork *work, void *msgData)
{
    work->msgData = msgData;
}

void *SCRIPT_WORK_GetMsgData(ScriptWork *work)
{
    return work->msgData;
}

/* Callers in ov021 read the area parameter through this address. */
u32 *SCRIPT_WORK_GetTrainerParam(ScriptWork *work)
{
    return &work->trainerParam;
}

u16 SCRIPT_WORK_GetScriptId(ScriptWork *work)
{
    return work->scriptId;
}

void *SCRIPT_WORK_GetTargetObj(ScriptWork *work)
{
    return work->targetObj;
}

void SCRIPT_WORK_SetTargetObj(ScriptWork *work, void *targetObj)
{
    work->targetObj = targetObj;
    if (targetObj != 0) {
        u16 *slot = SCRIPT_WORK_GetLocalWork(work, 0x8011);
        *slot = FLDMMDL_GetObjId(targetObj);
    }
}

void *SCRIPT_WORK_GetUserWorkPtr(ScriptWork *work) { return &work->userWork; }

void *SCRIPT_WORK_GetUserWork(ScriptWork *work) { return work->userWork; }

void SCRIPT_WORK_FreeUserWork(ScriptWork *work)
{
    if (work->userWork != 0) {
        func_020307B0(work->userWork);
        work->userWork = 0;
    }
}

u16 *SCRIPT_WORK_GetLocalWork(ScriptWork *work, u32 id)
{
    return &work->localWorks[id - SCRIPT_LOCAL_WORK_BASE];
}

u16 *SCRIPT_WORK_GetWorkPtr(ScriptWork *work, void *gameData, unsigned int id)
{
    u32 eventWork = GAME_DATA_GetEventWork(gameData);
    if (id < 0x4000) return 0;
    if (id < 0x8000) return ZONEDATA_GetEventWorkAddress(eventWork, id);
    if (id < 0xc000) return SCRIPT_WORK_GetLocalWork(work, id);
    return 0;
}

/*
 * extent: two-byte zero alignment padding follows the 18-byte function.
 * Return stays full-width: the fallback id has no halfword truncation.
 */
unsigned int SCRIPT_WORK_GetWorkValue(ScriptWork *work, void *gameData, unsigned int id)
{
    u16 *value = SCRIPT_WORK_GetWorkPtr(work, gameData, id);
    if (value) id = *value;
    return id;
}

int SCRIPT_WORK_SetWorkValue(ScriptWork *work, u32 id, int value)
{
    void *gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    u16 *slot = SCRIPT_WORK_GetWorkPtr(work, gameData, id);
    if (slot == 0)
        return 0;
    *slot = value;
    return 1;
}

int SCRIPT_WORK_SetParams(ScriptWork *work, int param0, int param1, int param2, u16 param3)
{
    SCRIPT_WORK_SetWorkValue(work, 0x8000, param0);
    SCRIPT_WORK_SetWorkValue(work, 0x8001, param1);
    SCRIPT_WORK_SetWorkValue(work, 0x8002, param2);
    return SCRIPT_WORK_SetWorkValue(work, 0x8003, param3);
}

void *SCRIPT_WORK_BackupLocalWork(ScriptWork *work)
{
    void *backup = func_02030734(work->heapId, 0x7e, 1, sScriptWorkFileName, 0x21b);
    MIi_CpuCopy16(SCRIPT_WORK_GetLocalWork(work, 0x8020), backup, 0x7e);
    return backup;
}

void SCRIPT_WORK_RestoreLocalWork(ScriptWork *work, void *backup)
{
    u16 *localWorks = SCRIPT_WORK_GetLocalWork(work, 0x8020);
    MIi_CpuCopy16(backup, localWorks, 0x7e);
    func_020307B0(backup);
}

void SCRIPT_WORK_SetReturnScriptId(ScriptWork *work, u32 scriptId) { work->returnScriptId = scriptId; }

u32 SCRIPT_WORK_GetReturnScriptId(ScriptWork *work) { return work->returnScriptId; }

void SCRIPT_WORK_SetReturnParam(ScriptWork *work, u32 param)
{
    work->returnParam = param;
}

u32 SCRIPT_WORK_GetReturnParam(ScriptWork *work)
{
    return work->returnParam;
}

ScriptWork *SCRIPT_WORK_SetReturnFlag(ScriptWork *work, u32 flag) { work->returnFlag = flag; return work; }

u32 SCRIPT_WORK_GetReturnFlag(ScriptWork *work) { return work->returnFlag; }

ScriptTrainerEntry *SCRIPT_WORK_GetTrainerEntry(ScriptWork *work, int index)
{
    return &work->trainers[index];
}

void SCRIPT_WORK_ClearCheckFlags(void)
{
    func_02082A7C(0, &gScriptCheckFlags, 4);
}

/*
 * Input evidence: ov010 callers 0215F278/02164946 pass 11/7;
 * ov021 flag setters pass fixed IDs 0..13 (e.g. 021B5316 passes 0,
 * 021AEE1E passes 13). No traced setter call supplies a negative ID.
 * These primary paths make 1 << flagId defined; no new bound is assumed.
 */
void SCRIPT_WORK_SetCheckFlag(int flagId)
{
    if (flagId < 14 && !SCRIPT_WORK_IsCheckFlagSet(flagId)) gScriptCheckFlags |= 1 << flagId;
}

/*
 * lever: enum-typed bit keeps the shifted mask opaque; plain int folds
 * the complement to mvns and shortens the body by four bytes.
 * Input evidence: ov010 sites 0215F298/021649D6/02164A14 pass 11/7/7;
 * ov021 flag clearers pass fixed IDs 0..13 (021B52D8 passes 0,
 * 021AF03A passes 13; 021B10C8 forwards its saved literal 3).
 * On these traced paths flagId is nonnegative and below 14 before the shift.
 */
void SCRIPT_WORK_ResetCheckFlag(int flagId)
{
    if (flagId < 14 && SCRIPT_WORK_IsCheckFlagSet(flagId)) {
        ScriptCheckBit bit = SCRIPT_CHECK_BIT;
        gScriptCheckFlags &= (bit << flagId) ^ -1;
    }
}

/* Tail call through a pool word and bx r3 (docs/idioms/tail-call-is-a-pool-word-and-bx.md). */
int SCRIPT_WORK_CheckFlag(int flagId)
{
    return SCRIPT_WORK_IsCheckFlagSet(flagId);
}

/*
 * Input evidence: direct callers are 0215914C, 02159170, 021591D0.
 * Set/clear callers use fixed nonnegative IDs 0..13; the 02159190 tail
 * forwarder has constant-ID callers in ov010/ov021/ov082 (021F5756: 3).
 * The task caller's index starts at zero (0215922E), advances by one
 * (021591EA), and sees a NULL callback at table index 14 (02170628)
 * before the test call. Its fourteen callbacks leave task+0x10 alone;
 * state updates use only task+0x0c. Thus shifted IDs are 0..13 on the
 * traced primary paths; no invented guard or domain was added.
 */
int SCRIPT_WORK_IsCheckFlagSet(int flagId)
{
    if (flagId >= 14) return 0;
    if ((gScriptCheckFlags >> flagId) & 1) return 1;
    return 0;
}

int SCRIPT_WORK_RunCheckTask(int taskHandle, int taskArg, ScriptCheckTask *task)
{
    do {
        ScriptCheckHandler handler = gScriptCheckHandlers[task->index];
        if (handler == 0)
            return 1;
        if (SCRIPT_WORK_IsCheckFlagSet(task->index)) {
            if (handler(task, &task->state)) {
                task->index++;
                task->state = 0;
            } else {
                return 0;
            }
        } else {
            task->index++;
            task->state = 0;
        }
    } while (task->index < task->count);
    return 1;
}

void *SCRIPT_WORK_CreateCheckTask(ScriptVm *vm)
{
    void *scriptCtl = SCRCMD_WORK_GetScriptWork(vm);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(vm);
    void *taskHandle = func_020122C0(gameSystem, 0, SCRIPT_WORK_RunCheckTask, sizeof(ScriptCheckTask));
    ScriptCheckTask *task = func_020124E8(taskHandle);
    task->gameSystem = gameSystem;
    task->vm = vm;
    task->scriptCtl = scriptCtl;
    task->index = 0;
    task->state = 0;
    task->count = 15;
    return taskHandle;
}

int SCRIPT_WORK_CmdNop(void) { return 0; }

int SCRIPT_WORK_CmdDummy(void) { return 0; }

int SCRIPT_WORK_CmdHalt(ScriptVm *vm)
{
    func_02011290(vm);
    return 1;
}

/*
 * Recursive MATCH unblocker: tail-call thunk at the pool word 0x0215A691
 * (SCRCMD_WORK_CountDownWait). Matched so the ABS32 site in SCRIPT_WORK_CmdTimeWait attests as
 * `matched`.
 */
int SCRIPT_WORK_WaitTime(ScriptVm *vm, void *cmdWork)
{
    return SCRCMD_WORK_CountDownWait(cmdWork);
}

/*
 * Registers the wait count under the key the VM yields and installs the
 * in-overlay wait callback the pool names.
 */
int SCRIPT_WORK_CmdTimeWait(ScriptVm *vm, void *cmdWork)
{
    SCRCMD_WORK_SetWaitCount(cmdWork, VM_GetU16(vm));
    VM_SetWait(vm, SCRIPT_WORK_WaitTime);
    return 1;
}

int SCRIPT_WORK_CmdCall(ScriptVm *vm, void *work)
{
    u32 offset = VM_GetU32(vm);
    VM_Call(vm, vm->pc + offset);
    return 0;
}

int SCRIPT_WORK_CmdReturn(ScriptVm *vm, void *work)
{
    VM_Return(vm);
    return 0;
}

int SCRIPT_WORK_CmdDebugWork(ScriptVm *vm, ScriptWork *work)
{
    SCRCMD_WORK_GetGameData(work);
    SCRIPT_WORK_ReadWorkValue(vm, work);
    return 0;
}

int SCRIPT_WORK_CmdDebugStack(ScriptVm *vm, ScriptWork *work)
{
    VM_PopStack(vm);
    SCRIPT_WORK_ReadWorkValue(vm, work);
    return 0;
}

static inline u8 ReadScriptByte(ScriptVm *vm)
{
    u8 value = *vm->pc;
    vm->pc++;
    return value;
}

int SCRIPT_WORK_CmdLoadRegValue(ScriptVm *vm)
{
    u8 index = ReadScriptByte(vm);
    u8 value = ReadScriptByte(vm);
    vm->ring[index] = value;
    return 0;
}
