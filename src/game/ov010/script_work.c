/*
 * file:     script_work.c
 * unit:     yes
 * function: func_02158E54, func_02158E7C, func_02158F18, func_02158F50, func_02158F54, func_02158F58, func_02158F6C, func_02158F74, func_02158F78, func_02158F7C, func_02158F80, func_02158F84, func_02158F88, func_02158F8C, func_02158F90, func_02158F94, func_02158FB4, func_02158FB8, func_02158FBC, func_02158FD0, func_02158FE0, func_0215901C, func_02159030, func_02159058, func_0215909C, func_021590D4, func_021590F4, func_021590FC, func_02159104, func_0215910C, func_02159114, func_0215911C, func_02159124, func_02159130, func_02159144, func_02159168, func_02159190, func_02159198, func_021591B4, func_02159204, func_02159240, func_02159244, func_02159248, func_02159254, func_02159260, func_02159284, func_0215929C, func_021592A8, func_021592C0, func_021592D8
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
 *   func_02045808  0x02045808  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02082A7C  0x02082A7C  arm
 *   func_02188C54  0x02188C54  thumb
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0215A514  0x0215A514  thumb  ov010
 *   sScriptWorkFileName     0x0217289C  data  ov010  a1
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0215A554  0x0215A554  thumb  ov010
 *   func_0216D588 0x0216D588 thumb ov010
 *   func_02082A60 0x02082A60 arm
 *   gScriptCheckFlags 0x02172BA0 data a4
 *   gScriptCheckHandlers     0x021705F0  data  ov010
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_02011290  0x02011290  thumb
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_0215A684   0x0215A684  thumb  ov010
 *   func_02011330   0x02011330  thumb
 *   func_020113D0   0x020113D0  thumb
 *   VM_Call  0x020113B4  thumb
 *   VM_Return  0x020113C4  thumb
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   VM_PopStack  0x02011398  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_02158920  0x02158920  thumb  ov010
 *   func_02158DB0  0x02158DB0  thumb  ov010
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
extern int func_02045808(void *buffer);
extern void *func_020120F4(void *gameSystem);
extern u32 func_0201296C(void *gameData);
extern void *func_020124E8(void *task);
extern void *func_020122C0(void *gameSystem, void *arg, ScriptCheckTaskFn callback, unsigned int size);
extern u16 *func_020143CC(u32 eventWork, u32 id);
extern u32 func_0201134C(ScriptVm *vm);
extern void *func_0201210C(void *gameSystem);
extern void *func_0215A5DC(ScriptVm *vm);
extern int func_02082A7C();
extern int func_02188C54();
extern void *func_0201EC74(u32 count, u32 size, u16 heapId);
extern void *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0215A514(ScriptWork *work, int heapId);
extern int func_0201ED04();
extern int func_0215A554();
extern u16 func_0216D588(void *obj);
extern void func_02082A60(const void *src, void *dst, unsigned int size);
extern void *func_0215A5F4(ScriptVm *vm);
extern void func_02011290(ScriptVm *vm);
extern int func_0215A690(void *cmdWork);
extern u16 func_02011330(ScriptVm *vm);
extern void func_0215A684(void *cmdWork, unsigned short count);
extern void func_020113D0(ScriptVm *vm, ScriptWaitFn waitFn);
extern void VM_Call(ScriptVm *vm, u8 *target);
extern u32 VM_Return(ScriptVm *vm);
extern void *func_0215A5E4(void *work);
extern unsigned int func_02159B10(ScriptVm *vm, ScriptWork *work);
extern u32 VM_PopStack(ScriptVm *vm);
extern int func_02158DB0(ScriptWork *parentWork);
extern const char sScriptWorkFileName[];
extern int gScriptCheckFlags;
extern ScriptCheckHandler gScriptCheckHandlers[];

int func_02158E54(ScriptFieldParam *fieldParam, void *gameSystem);
ScriptWork *func_02158E7C(u16 heapId, void *gameSystem, void *event, u16 scriptId, int targetObjParam, ScriptWork *parentWork);
int func_02158F18(ScriptWork *work);
void *func_02158F50(ScriptWork *work);
void *func_02158F54(ScriptWork *work);
ScriptFieldParam *func_02158F58(ScriptWork *work);
void *func_02158F6C(ScriptWork *work);
void *func_02158F74(ScriptWork *work);
void *func_02158F78(ScriptWork *work);
void *func_02158F7C(ScriptWork *work);
void func_02158F80(ScriptWork *work, void *msgData);
void *func_02158F84(ScriptWork *work);
u32 *func_02158F88(ScriptWork *work);
u16 func_02158F8C(ScriptWork *work);
void *func_02158F90(ScriptWork *work);
void func_02158F94(ScriptWork *work, void *targetObj);
void *func_02158FB4(ScriptWork *work);
void *func_02158FB8(ScriptWork *work);
void func_02158FBC(ScriptWork *work);
u16 *func_02158FD0(ScriptWork *work, u32 id);
u16 *func_02158FE0(ScriptWork *work, void *gameData, unsigned int id);
unsigned int func_0215901C(ScriptWork *work, void *gameData, unsigned int id);
int func_02159030(ScriptWork *work, u32 id, int value);
int func_02159058(ScriptWork *work, int param0, int param1, int param2, u16 param3);
void *func_0215909C(ScriptWork *work);
void func_021590D4(ScriptWork *work, void *backup);
void func_021590F4(ScriptWork *work, u32 scriptId);
u32 func_021590FC(ScriptWork *work);
void func_02159104(ScriptWork *work, u32 param);
u32 func_0215910C(ScriptWork *work);
ScriptWork *func_02159114(ScriptWork *work, u32 flag);
u32 func_0215911C(ScriptWork *work);
ScriptTrainerEntry *func_02159124(ScriptWork *work, int index);
void func_02159130(void);
void func_02159144(int flagId);
void func_02159168(int flagId);
int func_02159190(int flagId);
int func_02159198(int flagId);
int func_021591B4(int taskHandle, int taskArg, ScriptCheckTask *task);
void *func_02159204(ScriptVm *vm);
int func_02159240(void);
int func_02159244(void);
int func_02159248(ScriptVm *vm);
int func_02159254(ScriptVm *vm, void *cmdWork);
int func_02159260(ScriptVm *vm, void *cmdWork);
int func_02159284(ScriptVm *vm, void *work);
int func_0215929C(ScriptVm *vm, void *work);
int func_021592A8(ScriptVm *vm, ScriptWork *work);
int func_021592C0(ScriptVm *vm, ScriptWork *work);
int func_021592D8(ScriptVm *vm);

int func_02158E54(ScriptFieldParam *fieldParam, void *gameSystem)
{
    void *fieldSystem = func_0201210C(gameSystem);
    int result = func_02082A7C(0, fieldParam, 8);
    fieldParam->fieldSystem = fieldSystem;
    if (fieldSystem != 0) {
        result = func_02188C54(fieldSystem);
        fieldParam->mapSystem = (void *)result;
    }
    return result;
}

ScriptWork *func_02158E7C(u16 heapId, void *gameSystem, void *event, u16 scriptId, int targetObjParam, ScriptWork *parentWork)
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
    work->isChild = func_02158DB0(parentWork);
    if (work->isChild == 0) {
        work->wordSet = func_0201EC74(0x1C, 0x40, heapId);
        work->msgBuffer = func_020457B0(0x500, heapId);
        work->tempBuffer = func_020457B0(0x500, heapId);
    } else {
        work->wordSet = 0;
        work->msgBuffer = 0;
        work->tempBuffer = 0;
    }
    work->cmdWork = func_0215A514(work, heapId);
    func_02158E54(&work->fieldParam, gameSystem);
    if (work->isChild == 0)
        func_02159130();
    return work;
}

int func_02158F18(ScriptWork *work)
{
    work->magic = 0;
    if (work->wordSet != 0)
        func_0201ED04(work->wordSet);
    if (work->msgBuffer != 0)
        func_02045808(work->msgBuffer);
    if (work->tempBuffer != 0)
        func_02045808(work->tempBuffer);
    func_0215A554(work->cmdWork);
    return func_020307B0(work);
}

void *func_02158F50(ScriptWork *work) { return work->event; }

void *func_02158F54(ScriptWork *work) { return work->gameSystem; }

ScriptFieldParam *func_02158F58(ScriptWork *work)
{
    func_02158E54(&work->fieldParam, work->gameSystem);
    return &work->fieldParam;
}

void *func_02158F6C(ScriptWork *work) { return work->cmdWork; }

void *func_02158F74(ScriptWork *work) { return work->wordSet; }

void *func_02158F78(ScriptWork *work) { return work->msgBuffer; }

void *func_02158F7C(ScriptWork *work) { return work->tempBuffer; }

void func_02158F80(ScriptWork *work, void *msgData)
{
    work->msgData = msgData;
}

void *func_02158F84(ScriptWork *work)
{
    return work->msgData;
}

/* Callers in ov021 read the area parameter through this address. */
u32 *func_02158F88(ScriptWork *work)
{
    return &work->trainerParam;
}

u16 func_02158F8C(ScriptWork *work)
{
    return work->scriptId;
}

void *func_02158F90(ScriptWork *work)
{
    return work->targetObj;
}

void func_02158F94(ScriptWork *work, void *targetObj)
{
    work->targetObj = targetObj;
    if (targetObj != 0) {
        u16 *slot = func_02158FD0(work, 0x8011);
        *slot = func_0216D588(targetObj);
    }
}

void *func_02158FB4(ScriptWork *work) { return &work->userWork; }

void *func_02158FB8(ScriptWork *work) { return work->userWork; }

void func_02158FBC(ScriptWork *work)
{
    if (work->userWork != 0) {
        func_020307B0(work->userWork);
        work->userWork = 0;
    }
}

u16 *func_02158FD0(ScriptWork *work, u32 id)
{
    return &work->localWorks[id - SCRIPT_LOCAL_WORK_BASE];
}

u16 *func_02158FE0(ScriptWork *work, void *gameData, unsigned int id)
{
    u32 eventWork = func_0201296C(gameData);
    if (id < 0x4000) return 0;
    if (id < 0x8000) return func_020143CC(eventWork, id);
    if (id < 0xc000) return func_02158FD0(work, id);
    return 0;
}

/*
 * extent: two-byte zero alignment padding follows the 18-byte function.
 * Return stays full-width: the fallback id has no halfword truncation.
 */
unsigned int func_0215901C(ScriptWork *work, void *gameData, unsigned int id)
{
    u16 *value = func_02158FE0(work, gameData, id);
    if (value) id = *value;
    return id;
}

int func_02159030(ScriptWork *work, u32 id, int value)
{
    void *gameData = func_020120F4(work->gameSystem);
    u16 *slot = func_02158FE0(work, gameData, id);
    if (slot == 0)
        return 0;
    *slot = value;
    return 1;
}

int func_02159058(ScriptWork *work, int param0, int param1, int param2, u16 param3)
{
    func_02159030(work, 0x8000, param0);
    func_02159030(work, 0x8001, param1);
    func_02159030(work, 0x8002, param2);
    return func_02159030(work, 0x8003, param3);
}

void *func_0215909C(ScriptWork *work)
{
    void *backup = func_02030734(work->heapId, 0x7e, 1, sScriptWorkFileName, 0x21b);
    func_02082A60(func_02158FD0(work, 0x8020), backup, 0x7e);
    return backup;
}

void func_021590D4(ScriptWork *work, void *backup)
{
    u16 *localWorks = func_02158FD0(work, 0x8020);
    func_02082A60(backup, localWorks, 0x7e);
    func_020307B0(backup);
}

void func_021590F4(ScriptWork *work, u32 scriptId) { work->returnScriptId = scriptId; }

u32 func_021590FC(ScriptWork *work) { return work->returnScriptId; }

void func_02159104(ScriptWork *work, u32 param)
{
    work->returnParam = param;
}

u32 func_0215910C(ScriptWork *work)
{
    return work->returnParam;
}

ScriptWork *func_02159114(ScriptWork *work, u32 flag) { work->returnFlag = flag; return work; }

u32 func_0215911C(ScriptWork *work) { return work->returnFlag; }

ScriptTrainerEntry *func_02159124(ScriptWork *work, int index)
{
    return &work->trainers[index];
}

void func_02159130(void)
{
    func_02082A7C(0, &gScriptCheckFlags, 4);
}

/*
 * Input evidence: ov010 callers 0215F278/02164946 pass 11/7;
 * ov021 flag setters pass fixed IDs 0..13 (e.g. 021B5316 passes 0,
 * 021AEE1E passes 13). No traced setter call supplies a negative ID.
 * These primary paths make 1 << flagId defined; no new bound is assumed.
 */
void func_02159144(int flagId)
{
    if (flagId < 14 && !func_02159198(flagId)) gScriptCheckFlags |= 1 << flagId;
}

/*
 * lever: enum-typed bit keeps the shifted mask opaque; plain int folds
 * the complement to mvns and shortens the body by four bytes.
 * Input evidence: ov010 sites 0215F298/021649D6/02164A14 pass 11/7/7;
 * ov021 flag clearers pass fixed IDs 0..13 (021B52D8 passes 0,
 * 021AF03A passes 13; 021B10C8 forwards its saved literal 3).
 * On these traced paths flagId is nonnegative and below 14 before the shift.
 */
void func_02159168(int flagId)
{
    if (flagId < 14 && func_02159198(flagId)) {
        ScriptCheckBit bit = SCRIPT_CHECK_BIT;
        gScriptCheckFlags &= (bit << flagId) ^ -1;
    }
}

/* Tail call through a pool word and bx r3 (docs/idioms/tail-call-is-a-pool-word-and-bx.md). */
int func_02159190(int flagId)
{
    return func_02159198(flagId);
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
int func_02159198(int flagId)
{
    if (flagId >= 14) return 0;
    if ((gScriptCheckFlags >> flagId) & 1) return 1;
    return 0;
}

int func_021591B4(int taskHandle, int taskArg, ScriptCheckTask *task)
{
    do {
        ScriptCheckHandler handler = gScriptCheckHandlers[task->index];
        if (handler == 0)
            return 1;
        if (func_02159198(task->index)) {
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

void *func_02159204(ScriptVm *vm)
{
    void *scriptCtl = func_0215A5F4(vm);
    void *gameSystem = func_0215A5DC(vm);
    void *taskHandle = func_020122C0(gameSystem, 0, func_021591B4, sizeof(ScriptCheckTask));
    ScriptCheckTask *task = func_020124E8(taskHandle);
    task->gameSystem = gameSystem;
    task->vm = vm;
    task->scriptCtl = scriptCtl;
    task->index = 0;
    task->state = 0;
    task->count = 15;
    return taskHandle;
}

int func_02159240(void) { return 0; }

int func_02159244(void) { return 0; }

int func_02159248(ScriptVm *vm)
{
    func_02011290(vm);
    return 1;
}

/*
 * Recursive MATCH unblocker: tail-call thunk at the pool word 0x0215A691
 * (func_0215A690). Matched so the ABS32 site in func_02159260 attests as
 * `matched`.
 */
int func_02159254(ScriptVm *vm, void *cmdWork)
{
    return func_0215A690(cmdWork);
}

/*
 * Registers the wait count under the key the VM yields and installs the
 * in-overlay wait callback the pool names.
 */
int func_02159260(ScriptVm *vm, void *cmdWork)
{
    func_0215A684(cmdWork, func_02011330(vm));
    func_020113D0(vm, func_02159254);
    return 1;
}

int func_02159284(ScriptVm *vm, void *work)
{
    u32 offset = func_0201134C(vm);
    VM_Call(vm, vm->pc + offset);
    return 0;
}

int func_0215929C(ScriptVm *vm, void *work)
{
    VM_Return(vm);
    return 0;
}

int func_021592A8(ScriptVm *vm, ScriptWork *work)
{
    func_0215A5E4(work);
    func_02159B10(vm, work);
    return 0;
}

int func_021592C0(ScriptVm *vm, ScriptWork *work)
{
    VM_PopStack(vm);
    func_02159B10(vm, work);
    return 0;
}

static inline u8 ReadScriptByte(ScriptVm *vm)
{
    u8 value = *vm->pc;
    vm->pc++;
    return value;
}

int func_021592D8(ScriptVm *vm)
{
    u8 index = ReadScriptByte(vm);
    u8 value = ReadScriptByte(vm);
    vm->ring[index] = value;
    return 0;
}
