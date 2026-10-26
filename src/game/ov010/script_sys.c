/*
 * file:     script_sys.c
 * unit:     yes
 * function: SCRIPT_SYS_CreateScriptEventSimple, SCRIPT_SYS_CallScriptEvent, SCRIPT_SYS_ChangeScriptEvent, SCRIPT_SYS_HasVm, SCRIPT_SYS_Create, SCRIPT_SYS_Delete, SCRIPT_SYS_Main, SCRIPT_SYS_AddVm, SCRIPT_SYS_GetVm, SCRIPT_SYS_ChangeNextEvent, SCRIPT_SYS_SetNextEvent, SCRIPT_SYS_CallEndCallback, SCRIPT_SYS_HasEndCallback, SCRIPT_SYS_GetZoneId, SCRIPT_SYS_EventMain, SCRIPT_SYS_CreateScriptEvent, SCRIPT_SYS_CallEvent, SCRIPT_SYS_SetNextEventFromWork, SCRIPT_SYS_AddScript, SCRIPT_SYS_GetEventScriptWork, SCRIPT_SYS_GetFromWork, SCRIPT_SYS_ClearLocalWork, SCRIPT_SYS_RunInitScript, SCRIPT_SYS_RunRecoverScript, SCRIPT_SYS_RunScriptNow, SCRIPT_SYS_RunSpecialScript, SCRIPT_SYS_RunFieldInitScript, SCRIPT_SYS_RunFieldRecoverScript, SCRIPT_SYS_RunZoneChangeScript, SCRIPT_SYS_CreateSceneChangeEvent, SCRIPT_SYS_FindSpecialScript, SCRIPT_SYS_FindSceneScript, SCRIPT_SYS_CreateVm, SCRIPT_SYS_DeleteVm, SCRIPT_SYS_GetScriptFileId, SCRIPT_SYS_LoadScriptFile, SCRIPT_SYS_IsZoneScriptId, SCRIPT_SYS_IsChildScript, SCRIPT_SYS_ForceExitNet, SCRIPT_SYS_CheckCommandPermit, SCRIPT_SYS_SetCommandCheck
 * address:  0x02158768
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Original file script_sys.c: the create function 0x02158804 asserts with
 * "script_sys.c". The cut before 0x02158768 is likely, not certain: the
 * functions from there on call the script event creator (0x02158920) and the
 * script sys getters (0x021589DC, 0x02158894), and nothing before it does.
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GAME_EVENT_GetGameSystem 0x020124E4 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAME_EVENT_CallEvent 0x02012374 thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   d_02172888 0x02172888 data a1
 *   VM_Control  0x02011298  thumb
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   ZONEDATA_ResetEventFlagRange  0x02014368  thumb
 *   ZONEDATA_ClearEventWorkRange  0x020143D8  thumb
 *   GAME_DATA_GetEventData 0x02012844 thumb
 *   EVENTDATA_SYSTEM_GetSpecialScriptData 0x02162450 thumb ov010
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb
 *   SCRCMD_WORK_Create  0x0215A55C  thumb  ov010
 *   VM_Create  0x0201121C  thumb
 *   VM_Init  0x0201126C  thumb
 *   SCRCMD_WORK_LoadMsgData  0x0215A760  thumb  ov010
 *   VM_Start  0x0201127C  thumb
 *   VM_GetU32  0x0201134C  thumb
 *   d_0217062C     0x0217062C  data  ov010
 *   d_021705D8     0x021705D8  data  ov010
 *   VM_GetContext  0x02011324  thumb
 *   SCRCMD_WORK_Delete  0x0215A5A4  thumb  ov010
 *   VM_Delete  0x02011264  thumb
 *   GF_PANIC_Fail  0x02034714  arm
 *   ZONEDATA_GetScriptArcId  0x02013B5C  thumb
 *   ZONEDATA_GetMsgArcId  0x02013B68  thumb
 *   d_021701A8     0x021701A8  data  a4
 *   d_02172898     0x02172898  data  ov010  a1
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetCallMode  0x0215A5D4  thumb  ov010
 *   SCRCMD_WORK_GetCallParam  0x0215A5D8  thumb  ov010
 *   d_02170374     0x02170374  data  ov010
 *   VM_SetHook 0x02011328 thumb
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   SCRIPT_WORK_Create  0x02158E7C  thumb  ov010
 *   SCRIPT_WORK_Delete  0x02158F18  thumb  ov010
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   SCRIPT_WORK_SetTargetObj  0x02158F94  thumb  ov010
 */
struct GameEvent;
typedef struct GameEvent GameEvent;
#include "../arm9/script_vm_types.h"

typedef void (*ScriptSysEndFunc)(void *event, void *arg);

/* 0x18-byte script system: up to three running script VMs */
typedef struct ScriptSys {
    u16 heapId;                 /* 0x00 */
    u8 vmCount;                 /* 0x02 */
    ScriptVm *vm[3];            /* 0x04 */
    ScriptSysEndFunc endFunc;   /* 0x10: run when the last VM ends */
    void *endArg;               /* 0x14 */
} ScriptSys;

/* 8-byte work of the script event (SCRIPT_SYS_CreateScriptEvent) */
typedef struct ScriptEventWork {
    void *scriptWork;           /* 0x00 */
    ScriptSys *scriptSys;       /* 0x04 */
} ScriptEventWork;

/* Start request handed to the script work when a VM is created */
typedef struct ScriptVmStart {
    u16 zoneId;
    u16 scriptId;
    int mode;
    int isChild;
    void *scriptWork;
} ScriptVmStart;

/* One row of the script id range table: ids lo..hi live in one script file */
typedef struct ScriptIdRange {
    u16 firstId;
    u16 lastId;
    u16 fileId;
    u16 textBank;
    u16 textMsgId;
} ScriptIdRange;

/* Per-command permit bits, one bit per call mode */
typedef struct ScriptCmdPermit {
    u8 allowInMode0 : 1;
    u8 allowInMode1 : 1;
    u8 allowInMode2 : 1;
} ScriptCmdPermit;

#include "../arm9/net.h"
#include "../arm9/gfl_heap_wrap.h"
struct GameSystem;
struct GameData;
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
#include "../arm9/game_event.h"
#include "../arm9/vm.h"
struct PlayerWork;
extern void ZONEDATA_ResetEventFlagRange(struct EventWork*, s32, s32);
extern void ZONEDATA_ClearEventWorkRange(struct EventWork *eventFlags, u32 first, u32 last);
struct EventDataSystem;
#include "eventdata_system.h"
struct EventWork;
extern u16 *ZONEDATA_GetEventWorkAddress(struct EventWork *ev, u32 workId);
struct ScrcmdWorkParam;
struct ScrcmdWork;
#include "scrcmd_work.h"
struct ScrcmdWork;
#include "../arm9/gf_panic.h"
extern u32 ZONEDATA_GetScriptArcId(u32 id);
#ifdef __MWERKS__
extern u16 ZONEDATA_GetMsgArcId(u16 id); /* original prototype; the definition differs in return type, argument width */
#else
extern u32 ZONEDATA_GetMsgArcId(u32);
#endif
#ifdef __MWERKS__
extern void *ARC_UTIL_LoadMember(s32 archiveID, s32 memberIdx, s32 decompress, s32 heapID); /* original prototype; the definition differs in argument width */
#else
#include "../arm9/arc_util.h"
#endif
#include "../arm9/gfl_use.h"
struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(void *fieldSys, u16 scriptId, void *target, int reserved);
void *SCRIPT_SYS_CallScriptEvent(void *parentEvent, u16 scriptId, void *target, void *parentWork, u16 reserved);
void *SCRIPT_SYS_ChangeScriptEvent(void *event, u16 scriptId, void *target, int reserved);
int SCRIPT_SYS_HasVm(void *scriptWork, int index);
ScriptSys *SCRIPT_SYS_Create(u32 heapId);
void SCRIPT_SYS_Delete(ScriptSys *sys);
int SCRIPT_SYS_Main(ScriptSys *sys);
int SCRIPT_SYS_AddVm(ScriptSys *sys, ScriptVm *vm);
ScriptVm *SCRIPT_SYS_GetVm(ScriptSys *sys, int index);
void SCRIPT_SYS_ChangeNextEvent(void *event, void *nextEvent);
void SCRIPT_SYS_SetNextEvent(ScriptSys *sys, void *nextEvent);
void SCRIPT_SYS_CallEndCallback(ScriptSys *sys, void *event);
int SCRIPT_SYS_HasEndCallback(ScriptSys *sys);
u16 SCRIPT_SYS_GetZoneId(void *fieldSys);
int SCRIPT_SYS_EventMain(struct GameEvent *event, int *seq, void *work);
struct GameEvent *SCRIPT_SYS_CreateScriptEvent(void *fieldSys, int reserved, u16 scriptId, void *target, void *parentWork);
void SCRIPT_SYS_CallEvent(void *vm, void *task);
void SCRIPT_SYS_SetNextEventFromWork(void *scriptWork, void *nextEvent);
int SCRIPT_SYS_AddScript(void *scriptWork, u16 zoneId, u16 scriptId);
void *SCRIPT_SYS_GetEventScriptWork(struct GameEvent *event);
ScriptSys *SCRIPT_SYS_GetFromWork(void *scriptWork);
void SCRIPT_SYS_ClearLocalWork(void *eventFlags);
void SCRIPT_SYS_RunInitScript(void *fieldSys, int reserved);
void SCRIPT_SYS_RunRecoverScript(void *fieldSys, int reserved);
void SCRIPT_SYS_RunScriptNow(void *fieldSys, void *scriptWork, u16 scriptId, int mode);
int SCRIPT_SYS_RunSpecialScript(void *fieldSys, int reserved, int key, int mode);
void SCRIPT_SYS_RunFieldInitScript(void *fieldSys, int reserved);
void SCRIPT_SYS_RunFieldRecoverScript(void *fieldSys, int reserved);
void SCRIPT_SYS_RunZoneChangeScript(void *fieldSys, int reserved);
void *SCRIPT_SYS_CreateSceneChangeEvent(void *fieldSys, int reserved);
u16 SCRIPT_SYS_FindSpecialScript(const u8 *table, int key);
u16 SCRIPT_SYS_FindSceneScript(const void *eventWork, const u8 *list, u32 key);
ScriptVm *SCRIPT_SYS_CreateVm(u16 heapId, void *scriptWork, u16 zoneId, u16 scriptId, int mode);
void SCRIPT_SYS_DeleteVm(ScriptVm *vm);
u16 SCRIPT_SYS_GetScriptFileId(unsigned zoneId, unsigned scriptId, u16 *outFileId, u16 *outTextBank, u16 *outTextMsgId);
u8 *SCRIPT_SYS_LoadScriptFile(int fileId, int heapId);
int SCRIPT_SYS_IsZoneScriptId(u16 scriptId);
int SCRIPT_SYS_IsChildScript(int mode);
void SCRIPT_SYS_ForceExitNet(void);
int SCRIPT_SYS_CheckCommandPermit(ScriptVm *vm, void *cmdWork, void *fieldSys, u32 cmdIndex);
void SCRIPT_SYS_SetCommandCheck(ScriptVm *vm);
struct ScriptWork;
#include "script_work.h"
struct ScriptWork;
extern const char d_02172888[];
extern const ScriptCmdFn d_0217062C[];
extern int d_021705D8;
extern const ScriptIdRange d_021701A8[];
extern char d_02172898[];
extern ScriptCmdPermit d_02170374[];


struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(void *fieldSys, u16 scriptId, void *target, int reserved)
{
    return SCRIPT_SYS_CreateScriptEvent(fieldSys, reserved, scriptId, target, 0);
}


void *SCRIPT_SYS_CallScriptEvent(void *parentEvent, u16 scriptId, void *target, void *parentWork, u16 reserved)
{
    struct GameEvent *scriptEvent = SCRIPT_SYS_CreateScriptEvent(GAME_EVENT_GetGameSystem(parentEvent), reserved, scriptId, target, parentWork);
    ScriptEventWork *eventWork = GAME_EVENT_GetWork(scriptEvent);
    GAME_EVENT_CallEvent(parentEvent, scriptEvent);
    return eventWork->scriptWork;
}


void *SCRIPT_SYS_ChangeScriptEvent(void *event, u16 scriptId, void *target, int reserved)
{
    void *fieldSys;
    void *eventWork;
    struct GameEvent *scriptEvent;
    fieldSys = GAME_EVENT_GetGameSystem(event);
    scriptEvent = SCRIPT_SYS_CreateScriptEvent(fieldSys, reserved, scriptId, target, 0);
    eventWork = GAME_EVENT_GetWork(scriptEvent);
    GAME_EVENT_ChangeEvent(event, scriptEvent);
    return ((ScriptEventWork *)eventWork)->scriptWork;
}


/*
 * Extent ends in two alignment padding bytes.
 */
int SCRIPT_SYS_HasVm(void *scriptWork, int index)
{
    ScriptSys *sys = SCRIPT_SYS_GetFromWork(scriptWork);
    if (!sys)
        return 0;
    if (SCRIPT_SYS_GetVm(sys, index))
        return 1;
    return 0;
}


/*
 * Allocates 0x18 bytes and initializes the leading heap halfword.
 */
ScriptSys *SCRIPT_SYS_Create(u32 heapId)
{
    ScriptSys *sys = GFL_HEAP_Alloc(heapId, sizeof(*sys), 1, d_02172888, 0xEF);
    sys->heapId = heapId;
    return sys;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into GFL_HEAP_Free, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SCRIPT_SYS_Delete.c \
 *       --func SCRIPT_SYS_Delete --addr 0x02158824 --region ov010 --cc dsi/1.1p1 --thumb
 */
void SCRIPT_SYS_Delete(ScriptSys *sys)
{
    GFL_HEAP_Free(sys);
}


int SCRIPT_SYS_Main(ScriptSys *sys)
{
    int i;

    for (i = 0; i < 3; i++) {
        ScriptVm *vm = sys->vm[i];
        if (vm != 0 && VM_Control(vm) == 0) {
            sys->vm[i] = 0;
            sys->vmCount--;
            SCRIPT_SYS_DeleteVm(vm);
        }
    }
    if (sys->vmCount != 0)
        return 1;
    return 0;
}


int SCRIPT_SYS_AddVm(ScriptSys *sys, ScriptVm *vm)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (sys->vm[i] == 0) {
            sys->vm[i] = vm;
            sys->vmCount++;
            return i;
        }
    }
    return 3;
}


ScriptVm *SCRIPT_SYS_GetVm(ScriptSys *sys, int index)
{
    return sys->vm[index];
}


/*
 * extent: 8-byte tail stub; existing labelled SCRIPT_SYS_SetNextEvent follows.
 */
void SCRIPT_SYS_ChangeNextEvent(void *event, void *nextEvent)
{
    GAME_EVENT_ChangeEvent(event, nextEvent);
}


/*
 * lever: Callback-field assignment before argument-field assignment hoists
 *        the callback pool load before both stores, preserving argument first.
 */
void SCRIPT_SYS_SetNextEvent(ScriptSys *sys, void *nextEvent)
{
    ScriptSysEndFunc endFunc = SCRIPT_SYS_ChangeNextEvent;
    sys->endFunc = endFunc;
    sys->endArg = nextEvent;
}


void SCRIPT_SYS_CallEndCallback(ScriptSys *sys, void *event)
{
    sys->endFunc(event, sys->endArg);
}


int SCRIPT_SYS_HasEndCallback(ScriptSys *sys)
{
    if (sys->endFunc != 0)
        return 1;
    return 0;
}


u16 SCRIPT_SYS_GetZoneId(void *fieldSys)
{
    return GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(fieldSys));
}


int SCRIPT_SYS_EventMain(struct GameEvent *event, int *seq, void *workPtr)
{
    ScriptEventWork *eventWork = workPtr;
    void *scriptWork;
    ScriptSys *sys;

    sys = eventWork->scriptSys;
    scriptWork = eventWork->scriptWork;
    if (SCRIPT_SYS_Main(sys) == 1) {
        return 0;
    }
    SCRIPT_WORK_Delete(scriptWork);
    if (SCRIPT_SYS_HasEndCallback(sys) == 1) {
        SCRIPT_SYS_CallEndCallback(sys, event);
        SCRIPT_SYS_Delete(sys);
        return 0;
    }
    SCRIPT_SYS_Delete(sys);
    return 1;
}


struct GameEvent *SCRIPT_SYS_CreateScriptEvent(void *fieldSys, int reserved, u16 scriptId, void *target, void *parentWork)
{
    struct GameEvent *event = GAME_EVENT_Create(fieldSys, 0, SCRIPT_SYS_EventMain, sizeof(ScriptEventWork));
    ScriptEventWork *eventWork = GAME_EVENT_GetWork(event);
    eventWork->scriptSys = SCRIPT_SYS_Create(4);
    eventWork->scriptWork = SCRIPT_WORK_Create(4, fieldSys, event, scriptId, parentWork, 0);
    SCRIPT_WORK_SetTargetObj(eventWork->scriptWork, target);
    SCRIPT_SYS_AddScript(eventWork->scriptWork, SCRIPT_SYS_GetZoneId(fieldSys), scriptId);
    return event;
}


/*
 * Queue a task on the script's event list.
 */
void SCRIPT_SYS_CallEvent(void *scriptWork, void *task)
{
    GAME_EVENT_CallEvent(SCRIPT_WORK_GetEvent(scriptWork), task);
}


void SCRIPT_SYS_SetNextEventFromWork(void *scriptWork, void *nextEvent)
{
    ScriptSys *sys = SCRIPT_SYS_GetFromWork(scriptWork);
    if (sys != 0)
        SCRIPT_SYS_SetNextEvent(sys, nextEvent);
}


/*
 * Extent ends in two alignment padding bytes.
 */
int SCRIPT_SYS_AddScript(void *scriptWork, u16 zoneId, u16 scriptId) {
    ScriptSys *sys = SCRIPT_SYS_GetFromWork(scriptWork);
    if (sys)
        return SCRIPT_SYS_AddVm(sys, SCRIPT_SYS_CreateVm(sys->heapId, scriptWork, zoneId, scriptId, 0));
    return 3;
}


void *SCRIPT_SYS_GetEventScriptWork(struct GameEvent *event)
{
    ScriptEventWork *eventWork = GAME_EVENT_GetWork(event);
    return eventWork->scriptWork;
}


ScriptSys *SCRIPT_SYS_GetFromWork(void *scriptWork)
{
    void *event = SCRIPT_WORK_GetEvent(scriptWork);
    if (event == 0)
        return 0;
    return ((ScriptEventWork *)GAME_EVENT_GetWork(event))->scriptSys;
}


void SCRIPT_SYS_ClearLocalWork(void *eventFlags)
{
    ZONEDATA_ResetEventFlagRange(eventFlags, 0, 0x63);
    ZONEDATA_ClearEventWorkRange(eventFlags, 0x4000, 0x401F);
}


void SCRIPT_SYS_RunInitScript(void *fieldSys, int reserved) { SCRIPT_SYS_RunScriptNow(fieldSys, 0, 9600, 2); }


void SCRIPT_SYS_RunRecoverScript(void *fieldSys, int reserved) { SCRIPT_SYS_RunScriptNow(fieldSys, 0, 9601, 2); }


/*
 * Narrow parameter scriptId matches SCRIPT_WORK_Create's stored halfword and
 * restores spill/call scheduling. The remaining two bytes are zero
 * alignment padding.
 */
void SCRIPT_SYS_RunScriptNow(void *fieldSys, void *scriptWork, u16 scriptId, int mode)
{
    void *tempWork = 0;
    ScriptVm *vm;
    if (scriptWork == 0) {
        tempWork = SCRIPT_WORK_Create(4, fieldSys, (struct GameEvent *)tempWork, scriptId, tempWork, (struct ScriptWork *)(uptr)mode);
        scriptWork = tempWork;
    }
    vm = SCRIPT_SYS_CreateVm(4, scriptWork, SCRIPT_SYS_GetZoneId(fieldSys), scriptId, mode);
    while (VM_Control(vm) == 1)
        ;
    SCRIPT_SYS_DeleteVm(vm);
    if (tempWork != 0)
        SCRIPT_WORK_Delete(tempWork);
}


int SCRIPT_SYS_RunSpecialScript(void *fieldSys, int reserved, int key, int mode) {
    u16 scriptId = SCRIPT_SYS_FindSpecialScript((u8 *)EVENTDATA_SYSTEM_GetSpecialScriptData(GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(fieldSys))), key);
    if (scriptId == 0xffff) return 0;
    SCRIPT_SYS_RunScriptNow(fieldSys, 0, scriptId, mode);
    return 1;
}


void SCRIPT_SYS_RunFieldInitScript(void *fieldSys, int reserved)
{
    SCRIPT_SYS_RunSpecialScript(fieldSys, reserved, 4, 1);
}


void SCRIPT_SYS_RunFieldRecoverScript(void *fieldSys, int reserved)
{
    SCRIPT_SYS_RunSpecialScript(fieldSys, reserved, 3, 1);
}


/*
 * Two arm9 frame calls, an overlay reset, then the four-argument submit.
 */
void SCRIPT_SYS_RunZoneChangeScript(void *fieldSys, int reserved)
{
    SCRIPT_SYS_ClearLocalWork(GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(fieldSys)));
    SCRIPT_SYS_RunSpecialScript(fieldSys, reserved, 2, 2);
}


void *SCRIPT_SYS_CreateSceneChangeEvent(void *fieldSys, int reserved)
{
    void *eventWork = GAMESYSTEM_GetGameData(fieldSys);
    u16 scriptId = SCRIPT_SYS_FindSceneScript(eventWork, (u8 *)EVENTDATA_SYSTEM_GetSpecialScriptData(GAME_DATA_GetEventData(eventWork)), 1);
    if (scriptId == 0xffff) return 0;
    return SCRIPT_SYS_CreateScriptEventSimple(fieldSys, scriptId, 0, reserved);
}


u16 SCRIPT_SYS_FindSpecialScript(const u8 *table, int key) {
    for (;;) {
        u16 id = table[0] + (table[1] << 8);
        if (id == 0) return 0xffff;
        if (key == id) return (u16)(table[2] + (table[3] << 8));
        table += 6;
    }
}


inline static u16 RD16(const u8 *p)
{
  return (u16) (p[0] + (p[1] << 8));
}


/*
 * levers: wave76 reused cursor p across both parsing phases; p += 6 at the
 * matched key, then p += key before save accessor. Local base/q produced
 * DIFF40; cursor reuse alone31, resetting it through base129; in-place
 * advances give EXACT. Permuter300 previously consumed, not repeated.
 */
u16 SCRIPT_SYS_FindSceneScript(const void *eventWork, const u8 *list, u32 key)
{
  const u8 *p = list;
  void *eventFlags;
  for (;; p += 6)
  {
    u32 id = RD16(p);
    if (id == 0)
      return 0xFFFF;
    if (key == id)
    {
      key = ((p[2] + (p[3] << 8)) + (p[4] << 16)) + (p[5] << 24);
      p += 6;
      break;
    }
  }

  if (key == 0)
    return 0xFFFF;
  p += key;
  eventFlags = (struct GameData *)GAME_DATA_GetEventWork((struct GameData *)eventWork);
  for (;; p += 6)
  {
    u16 workId = RD16(p);
    u16 expected;
    if (workId == 0)
      return 0xFFFF;
    if (workId == 0)
      return 0xFFFF;
    expected = RD16(p + 2);
    if (expected == *ZONEDATA_GetEventWorkAddress(eventFlags, workId))
      return RD16(p + 4);
  }

}


ScriptVm *SCRIPT_SYS_CreateVm(u16 heapId, void *scriptWork, u16 zoneId, u16 scriptId, int mode)
{
    ScriptVmStart start;
    ScriptVmParams params;
    u16 fileInfo[4];
    int isChild, wordCount;
    void *startData;
    ScriptVm *vm;

    isChild = SCRIPT_SYS_IsChildScript(mode);
    start.zoneId = zoneId;
    start.scriptId = scriptId;
    start.mode = mode;
    start.isChild = isChild;
    start.scriptWork = scriptWork;
    startData = SCRCMD_WORK_Create((struct ScrcmdWorkParam *)(&start), heapId);
    params.stackCap = 0x100;
    params.ringCap = 0x40;
    params.cmds = d_0217062C;
    params.cmdCount = d_021705D8;
    vm = VM_Create(heapId, &params);
    VM_Init(vm, startData);
    wordCount = SCRIPT_SYS_GetScriptFileId(zoneId, scriptId, &fileInfo[2], &fileInfo[1], &fileInfo[0]);
    vm->data = SCRIPT_SYS_LoadScriptFile(fileInfo[2], heapId);
    if (isChild == 0) {
        if (fileInfo[0] != -1)
            SCRCMD_WORK_LoadMsgData(startData, fileInfo[1], fileInfo[0]);
    }
    VM_Start(vm, vm->data);
    vm->pc += wordCount << 2;
    vm->pc += VM_GetU32(vm);
    SCRIPT_SYS_SetCommandCheck(vm);
    return vm;
}


void SCRIPT_SYS_DeleteVm(ScriptVm *vm)
{
    SCRCMD_WORK_Delete(VM_GetContext(vm));
    GFL_HEAP_Free(vm->data);
    VM_Delete(vm);
}


/*
 * Looks up scriptId in a table of 46 range records (firstId, lastId, fileId,
 * textBank, textMsgId). Writes the last three to the outputs and returns
 * scriptId - firstId. Past the table it falls back to two lookups by zoneId,
 * or to fixed outputs when scriptId is 0.
 * 2026-10-05 (wave P15): the table is const and the three outputs are
 * stored directly from the record. The old DIFF 14 B draft copied b and c
 * into u16 locals; that form is not needed.
 */
u16 SCRIPT_SYS_GetScriptFileId(unsigned zoneId, unsigned scriptId, u16 *outFileId, u16 *outTextBank, u16 *outTextMsgId)
{
    unsigned i;
    const ScriptIdRange *table = d_021701A8;
    const ScriptIdRange *range;
    for (i = 0; i < 46; i++) {
        if (scriptId < table[i].firstId)
            continue;
        if (scriptId > table[i].lastId)
            GF_PANIC_Fail(d_02172898, (int)0, d_02172898);
        range = &table[i];
        *outFileId = range->fileId;
        *outTextBank = range->textBank;
        *outTextMsgId = range->textMsgId;
        return scriptId - table[i].firstId;
    }
    if (scriptId >= 1) {
        u16 fileId = (u16)ZONEDATA_GetScriptArcId((u16)zoneId);
        u16 textMsgId = ZONEDATA_GetMsgArcId(zoneId);
        *outFileId = fileId;
        *outTextBank = 3;
        *outTextMsgId = textMsgId;
        return scriptId - 1;
    }
    *outFileId = 0x356;
    *outTextBank = 3;
    *outTextMsgId = 0x9E;
    return 0;
}


/*
 * The null pointer local is the branch condition, not parameter heapId.
 * Lever: a-null-pointer-local-tested-reuses-the-movs-flags.md.
 * Extent follower 0x02158D90 already has its own matched shard.
 */
u8 *SCRIPT_SYS_LoadScriptFile(int fileId, int heapId) {
    u8 *result = 0;
    if (result == 0) result = (u8 *)ARC_UTIL_LoadMember(0x39, fileId, (sptr)result, heapId);
    return result;
}


/*
 * Unlabelled leaf (a .word run in the ov010 listing): 0 for 2000, 1 below
 * 0x291C, else 0.  Callee of ov021 FIELD_EVENT_CHECK_CheckCommEvents, FIELD_EVENT_CHECK_CheckRailEvents and
 * FIELD_EVENT_CHECK_CheckGridEvents.
 * Addresses are Black-image addresses.
 */
int SCRIPT_SYS_IsZoneScriptId(u16 scriptId)
{
    if (scriptId == 2000)
        return 0;
    if (scriptId < 0x291C)
        return 1;
    return 0;
}


int SCRIPT_SYS_IsChildScript(int mode)
{
    if (mode == 0)
        return 0;
    return 1;
}


void SCRIPT_SYS_ForceExitNet(void)
{
    int session;
    if (GFL_NET_GetRunState() != 0) {
        GFL_NET_ClearExitFlag();
        GFL_NET_Exit(0);
        GFL_NET_IRC_WIRELESS_Exit();
        for (;;) {
            GFL_NET_Main();
            session = GFL_NET_IsSessionNull();
            if (session != 0)
                break;
        }
    }
    for (;;)
        GFL_USE_PollPowerExit();
}


int SCRIPT_SYS_CheckCommandPermit(ScriptVm *vm, void *cmdWork, void *fieldSys, u32 cmdIndex)
{
    int callMode, permitted;
    GAMESYSTEM_GetFieldMap(fieldSys);
    SCRCMD_WORK_GetCallMode(cmdWork);
    callMode = SCRCMD_WORK_GetCallParam(cmdWork);
    permitted = 0;
    switch (callMode) {
    case 0: permitted = d_02170374[cmdIndex].allowInMode0; break;
    case 1: permitted = d_02170374[cmdIndex].allowInMode1; break;
    case 2: permitted = d_02170374[cmdIndex].allowInMode2; break;
    }
    if (permitted == 0)
        SCRIPT_SYS_ForceExitNet();
    return permitted;
}


/*
 * ARM9 interface evidence: 02011324 reads +0x20; 02011328 stores r1/r2 at +0x24/+0x28.
 */
void SCRIPT_SYS_SetCommandCheck(ScriptVm *vm) {
    void *cmdWork = SCRCMD_WORK_GetGameSystem(VM_GetContext(vm));
    VM_SetHook(vm, SCRIPT_SYS_CheckCommandPermit, cmdWork);
}
