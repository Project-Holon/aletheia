/*
 * file:     script_sys.c
 * unit:     yes
 * function: func_02158768, func_02158780, func_021587B0, func_021587E0, func_02158804, func_02158824, func_0215882C, func_0215886C, func_02158894, func_0215889C, func_021588A4, func_021588B0, func_021588C0, func_021588D0, func_021588DC, func_02158920, func_0215897C, func_0215898C, func_021589A0, func_021589D0, func_021589DC, func_021589F4, func_02158A10, func_02158A20, func_02158A34, func_02158A90, func_02158AC8, func_02158AD4, func_02158AE0, func_02158B00, func_02158B3C, func_02158B6C, func_02158BFC, func_02158CB4, func_02158CD0, func_02158D78, func_02158D90, func_02158DB0, func_02158DBC, func_02158DE8, func_02158E38
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
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C 0x0201296C thumb
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_020124E4 0x020124E4 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02012374 0x02012374 thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_02172888 0x02172888 data a1
 *   VM_Control  0x02011298  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020122C0  0x020122C0  thumb
 *   ZONEDATA_ResetEventFlagRange  0x02014368  thumb
 *   ZONEDATA_ClearEventWorkRange  0x020143D8  thumb
 *   func_02012844 0x02012844 thumb
 *   func_02162450 0x02162450 thumb ov010
 *   func_020143CC  0x020143CC  thumb
 *   func_0215A55C  0x0215A55C  thumb  ov010
 *   VM_Create  0x0201121C  thumb
 *   VM_Init  0x0201126C  thumb
 *   func_0215A760  0x0215A760  thumb  ov010
 *   VM_Start  0x0201127C  thumb
 *   func_0201134C  0x0201134C  thumb
 *   d_0217062C     0x0217062C  data  ov010
 *   d_021705D8     0x021705D8  data  ov010
 *   func_02011324  0x02011324  thumb
 *   func_0215A5A4  0x0215A5A4  thumb  ov010
 *   VM_Delete  0x02011264  thumb
 *   func_02034714  0x02034714  arm
 *   ZONEDATA_GetScriptArcId  0x02013B5C  thumb
 *   ZONEDATA_GetMsgArcId  0x02013B68  thumb
 *   d_021701A8     0x021701A8  data  a4
 *   d_02172898     0x02172898  data  ov010  a1
 *   func_0204A1BC 0x0204A1BC arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5D4  0x0215A5D4  thumb  ov010
 *   func_0215A5D8  0x0215A5D8  thumb  ov010
 *   d_02170374     0x02170374  data  ov010
 *   func_02011328 0x02011328 thumb
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02158E7C  0x02158E7C  thumb  ov010
 *   func_02158F18  0x02158F18  thumb  ov010
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_02158F94  0x02158F94  thumb  ov010
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

/* 8-byte work of the script event (func_02158920) */
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

extern int func_0203CD98(void);
extern int func_0203CEAC(int);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_020307B0();
extern void *func_020120F4(const void *p);
extern void *func_0201296C(const void *p);
int func_0203CDBC();
extern void *func_020124E4(GameEvent *event);
extern void *func_020124E8(GameEvent *event);
extern void func_02012374(GameEvent *parent, GameEvent *child);
extern int func_0201235C();
extern int VM_Control(ScriptVm *vm);
extern u8 *func_020120F8(const void *p);
extern u16 func_02012AC8(const void *p);
extern GameEvent *func_020122C0(void *owner, void *a, int (*eventFunc)(void *, int *, ScriptEventWork *), unsigned int size);
extern int ZONEDATA_ResetEventFlagRange(void *eventFlags, int first, int last);
extern int ZONEDATA_ClearEventWorkRange(void *eventFlags, int first, int last);
extern void *func_02012844(const void *p);
extern void *func_02162450(void *p);
extern u16 *func_020143CC(void *eventFlags, u32 id);
extern void *func_0215A55C(const ScriptVmStart *, int heapId);
extern ScriptVm *VM_Create(u32 heapId, const ScriptVmParams *params);
extern void VM_Init(ScriptVm *vm, void *user);
extern void func_0215A760(void *startData, unsigned textBank, unsigned textMsgId);
extern void VM_Start(ScriptVm *vm, u8 *pc);
extern u32 func_0201134C(ScriptVm *vm);
extern void *func_02011324(ScriptVm *vm);
extern int func_0215A5A4(void *vmCtx);
extern int VM_Delete();
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 ZONEDATA_GetScriptArcId(u32 id);
extern u16 ZONEDATA_GetMsgArcId(u16);
extern void *func_0204A1BC(int archive, int fileId, int a, int heapId);
extern int GFL_NET_ClearExitFlag();
extern int GFL_NET_IRC_WIRELESS_Exit();
extern u32 GFL_NET_Main(void);
extern int GFL_USE_PollPowerExit();
extern void *func_0201210C(const void *p);
extern u32 func_0215A5D4(void *p);
extern u32 func_0215A5D8(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_02011328(ScriptVm *vm, ScriptHookFn hook, void *hookArg);
GameEvent *func_02158768(void *fieldSys, u16 scriptId, void *target, int reserved);
void *func_02158780(void *parentEvent, u16 scriptId, void *target, void *parentWork, u16 reserved);
void *func_021587B0(void *event, u16 scriptId, void *target, int reserved);
int func_021587E0(void *scriptWork, int index);
ScriptSys *func_02158804(u32 heapId);
void func_02158824(ScriptSys *sys);
int func_0215882C(ScriptSys *sys);
int func_0215886C(ScriptSys *sys, ScriptVm *vm);
ScriptVm *func_02158894(ScriptSys *sys, int index);
void func_0215889C(void *event, void *nextEvent);
void func_021588A4(ScriptSys *sys, void *nextEvent);
void func_021588B0(ScriptSys *sys, void *event);
int func_021588C0(ScriptSys *sys);
u16 func_021588D0(void *fieldSys);
int func_021588DC(void *event, int *seq, ScriptEventWork *work);
GameEvent *func_02158920(void *fieldSys, int reserved, u16 scriptId, void *target, void *parentWork);
void func_0215897C(void *vm, void *task);
void func_0215898C(void *scriptWork, void *nextEvent);
int func_021589A0(void *scriptWork, u16 zoneId, u16 scriptId);
void *func_021589D0(GameEvent *event);
ScriptSys *func_021589DC(void *scriptWork);
int func_021589F4(void *eventFlags);
void func_02158A10(void *fieldSys, int reserved);
void func_02158A20(void *fieldSys, int reserved);
void func_02158A34(void *fieldSys, void *scriptWork, u16 scriptId, int mode);
int func_02158A90(void *fieldSys, int reserved, int key, int mode);
void func_02158AC8(void *fieldSys, int reserved);
void func_02158AD4(void *fieldSys, int reserved);
void func_02158AE0(void *fieldSys, int reserved);
void *func_02158B00(void *fieldSys, int reserved);
u16 func_02158B3C(const u8 *table, int key);
u16 func_02158B6C(const void *eventWork, const u8 *list, u32 key);
ScriptVm *func_02158BFC(u16 heapId, void *scriptWork, u16 zoneId, u16 scriptId, int mode);
int func_02158CB4(ScriptVm *vm);
u16 func_02158CD0(unsigned zoneId, unsigned scriptId, u16 *outFileId, u16 *outTextBank, u16 *outTextMsgId);
u8 *func_02158D78(int fileId, int heapId);
int func_02158D90(u16 scriptId);
int func_02158DB0(int mode);
void func_02158DBC(void);
int func_02158DE8(ScriptVm *vm, void *cmdWork, void *fieldSys, u32 cmdIndex);
void func_02158E38(ScriptVm *vm);
void *func_02158E7C(u16 heapId, void *fieldSys, GameEvent *event, u16 scriptId, void *parentWork, int mode);
int func_02158F18(void *scriptWork);
void *func_02158F50(void *p);
void func_02158F94(void *scriptWork, void *target);
extern const char d_02172888[];
extern const ScriptCmdFn d_0217062C[];
extern int d_021705D8;
extern const ScriptIdRange d_021701A8[];
extern char d_02172898[];
extern ScriptCmdPermit d_02170374[];


GameEvent *func_02158768(void *fieldSys, u16 scriptId, void *target, int reserved)
{
    return func_02158920(fieldSys, reserved, scriptId, target, 0);
}


void *func_02158780(void *parentEvent, u16 scriptId, void *target, void *parentWork, u16 reserved)
{
    GameEvent *scriptEvent = func_02158920(func_020124E4(parentEvent), reserved, scriptId, target, parentWork);
    ScriptEventWork *eventWork = func_020124E8(scriptEvent);
    func_02012374(parentEvent, scriptEvent);
    return eventWork->scriptWork;
}


void *func_021587B0(void *event, u16 scriptId, void *target, int reserved)
{
    void *fieldSys;
    void *eventWork;
    GameEvent *scriptEvent;
    fieldSys = func_020124E4(event);
    scriptEvent = func_02158920(fieldSys, reserved, scriptId, target, 0);
    eventWork = func_020124E8(scriptEvent);
    func_0201235C(event, scriptEvent);
    return ((ScriptEventWork *)eventWork)->scriptWork;
}


/*
 * Extent ends in two alignment padding bytes.
 */
int func_021587E0(void *scriptWork, int index)
{
    ScriptSys *sys = func_021589DC(scriptWork);
    if (!sys)
        return 0;
    if (func_02158894(sys, index))
        return 1;
    return 0;
}


/*
 * Allocates 0x18 bytes and initializes the leading heap halfword.
 */
ScriptSys *func_02158804(u32 heapId)
{
    ScriptSys *sys = func_02030734(heapId, 0x18, 1, d_02172888, 0xEF);
    sys->heapId = heapId;
    return sys;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158824.c \
 *       --func func_02158824 --addr 0x02158824 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02158824(ScriptSys *sys)
{
    func_020307B0(sys);
}


int func_0215882C(ScriptSys *sys)
{
    int i;

    for (i = 0; i < 3; i++) {
        ScriptVm *vm = sys->vm[i];
        if (vm != 0 && VM_Control(vm) == 0) {
            sys->vm[i] = 0;
            sys->vmCount--;
            func_02158CB4(vm);
        }
    }
    if (sys->vmCount != 0)
        return 1;
    return 0;
}


int func_0215886C(ScriptSys *sys, ScriptVm *vm)
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


ScriptVm *func_02158894(ScriptSys *sys, int index)
{
    return sys->vm[index];
}


/*
 * extent: 8-byte tail stub; existing labelled func_021588A4 follows.
 */
void func_0215889C(void *event, void *nextEvent)
{
    func_0201235C(event, nextEvent);
}


/*
 * lever: Callback-field assignment before argument-field assignment hoists
 *        the callback pool load before both stores, preserving argument first.
 */
void func_021588A4(ScriptSys *sys, void *nextEvent)
{
    ScriptSysEndFunc endFunc = func_0215889C;
    sys->endFunc = endFunc;
    sys->endArg = nextEvent;
}


void func_021588B0(ScriptSys *sys, void *event)
{
    sys->endFunc(event, sys->endArg);
}


int func_021588C0(ScriptSys *sys)
{
    if (sys->endFunc != 0)
        return 1;
    return 0;
}


u16 func_021588D0(void *fieldSys)
{
    return func_02012AC8(func_020120F8(fieldSys));
}


int func_021588DC(void *event, int *seq, ScriptEventWork *eventWork)
{
    void *scriptWork;
    ScriptSys *sys;

    sys = eventWork->scriptSys;
    scriptWork = eventWork->scriptWork;
    if (func_0215882C(sys) == 1) {
        return 0;
    }
    func_02158F18(scriptWork);
    if (func_021588C0(sys) == 1) {
        func_021588B0(sys, event);
        func_02158824(sys);
        return 0;
    }
    func_02158824(sys);
    return 1;
}


GameEvent *func_02158920(void *fieldSys, int reserved, u16 scriptId, void *target, void *parentWork)
{
    GameEvent *event = func_020122C0(fieldSys, 0, func_021588DC, 8);
    ScriptEventWork *eventWork = func_020124E8(event);
    eventWork->scriptSys = func_02158804(4);
    eventWork->scriptWork = func_02158E7C(4, fieldSys, event, scriptId, parentWork, 0);
    func_02158F94(eventWork->scriptWork, target);
    func_021589A0(eventWork->scriptWork, func_021588D0(fieldSys), scriptId);
    return event;
}


/*
 * Queue a task on the script's event list.
 */
void func_0215897C(void *scriptWork, void *task)
{
    func_02012374(func_02158F50(scriptWork), task);
}


void func_0215898C(void *scriptWork, void *nextEvent)
{
    ScriptSys *sys = func_021589DC(scriptWork);
    if (sys != 0)
        func_021588A4(sys, nextEvent);
}


/*
 * Extent ends in two alignment padding bytes.
 */
int func_021589A0(void *scriptWork, u16 zoneId, u16 scriptId) {
    ScriptSys *sys = func_021589DC(scriptWork);
    if (sys)
        return func_0215886C(sys, func_02158BFC(sys->heapId, scriptWork, zoneId, scriptId, 0));
    return 3;
}


void *func_021589D0(GameEvent *event)
{
    ScriptEventWork *eventWork = func_020124E8(event);
    return eventWork->scriptWork;
}


ScriptSys *func_021589DC(void *scriptWork)
{
    void *event = func_02158F50(scriptWork);
    if (event == 0)
        return 0;
    return ((ScriptEventWork *)func_020124E8(event))->scriptSys;
}


int func_021589F4(void *eventFlags)
{
    ZONEDATA_ResetEventFlagRange(eventFlags, 0, 0x63);
    return ZONEDATA_ClearEventWorkRange(eventFlags, 0x4000, 0x401F);
}


void func_02158A10(void *fieldSys, int reserved) { func_02158A34(fieldSys, 0, 9600, 2); }


void func_02158A20(void *fieldSys, int reserved) { func_02158A34(fieldSys, 0, 9601, 2); }


/*
 * Narrow parameter scriptId matches func_02158E7C's stored halfword and
 * restores spill/call scheduling. The remaining two bytes are zero
 * alignment padding.
 */
void func_02158A34(void *fieldSys, void *scriptWork, u16 scriptId, int mode)
{
    void *tempWork = 0;
    ScriptVm *vm;
    if (scriptWork == 0) {
        tempWork = func_02158E7C(4, fieldSys, (GameEvent *)tempWork, scriptId, tempWork, mode);
        scriptWork = tempWork;
    }
    vm = func_02158BFC(4, scriptWork, func_021588D0(fieldSys), scriptId, mode);
    while (VM_Control(vm) == 1)
        ;
    func_02158CB4(vm);
    if (tempWork != 0)
        func_02158F18(tempWork);
}


int func_02158A90(void *fieldSys, int reserved, int key, int mode) {
    u16 scriptId = func_02158B3C(func_02162450(func_02012844(func_020120F4(fieldSys))), key);
    if (scriptId == 0xffff) return 0;
    func_02158A34(fieldSys, 0, scriptId, mode);
    return 1;
}


void func_02158AC8(void *fieldSys, int reserved)
{
    func_02158A90(fieldSys, reserved, 4, 1);
}


void func_02158AD4(void *fieldSys, int reserved)
{
    func_02158A90(fieldSys, reserved, 3, 1);
}


/*
 * Two arm9 frame calls, an overlay reset, then the four-argument submit.
 */
void func_02158AE0(void *fieldSys, int reserved)
{
    func_021589F4(func_0201296C(func_020120F4(fieldSys)));
    func_02158A90(fieldSys, reserved, 2, 2);
}


void *func_02158B00(void *fieldSys, int reserved)
{
    void *eventWork = func_020120F4(fieldSys);
    u16 scriptId = func_02158B6C(eventWork, func_02162450(func_02012844(eventWork)), 1);
    if (scriptId == 0xffff) return 0;
    return func_02158768(fieldSys, scriptId, 0, reserved);
}


u16 func_02158B3C(const u8 *table, int key) {
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
u16 func_02158B6C(const void *eventWork, const u8 *list, u32 key)
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
  eventFlags = func_0201296C(eventWork);
  for (;; p += 6)
  {
    u16 workId = RD16(p);
    u16 expected;
    if (workId == 0)
      return 0xFFFF;
    if (workId == 0)
      return 0xFFFF;
    expected = RD16(p + 2);
    if (expected == *func_020143CC(eventFlags, workId))
      return RD16(p + 4);
  }

}


ScriptVm *func_02158BFC(u16 heapId, void *scriptWork, u16 zoneId, u16 scriptId, int mode)
{
    ScriptVmStart start;
    ScriptVmParams params;
    u16 fileInfo[4];
    int isChild, wordCount;
    void *startData;
    ScriptVm *vm;

    isChild = func_02158DB0(mode);
    start.zoneId = zoneId;
    start.scriptId = scriptId;
    start.mode = mode;
    start.isChild = isChild;
    start.scriptWork = scriptWork;
    startData = func_0215A55C(&start, heapId);
    params.stackCap = 0x100;
    params.ringCap = 0x40;
    params.cmds = d_0217062C;
    params.cmdCount = d_021705D8;
    vm = VM_Create(heapId, &params);
    VM_Init(vm, startData);
    wordCount = func_02158CD0(zoneId, scriptId, &fileInfo[2], &fileInfo[1], &fileInfo[0]);
    vm->data = func_02158D78(fileInfo[2], heapId);
    if (isChild == 0) {
        if (fileInfo[0] != -1)
            func_0215A760(startData, fileInfo[1], fileInfo[0]);
    }
    VM_Start(vm, vm->data);
    vm->pc += wordCount << 2;
    vm->pc += func_0201134C(vm);
    func_02158E38(vm);
    return vm;
}


int func_02158CB4(ScriptVm *vm)
{
    func_0215A5A4(func_02011324(vm));
    func_020307B0(vm->data);
    return VM_Delete(vm);
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
u16 func_02158CD0(unsigned zoneId, unsigned scriptId, u16 *outFileId, u16 *outTextBank, u16 *outTextMsgId)
{
    unsigned i;
    const ScriptIdRange *table = d_021701A8;
    const ScriptIdRange *range;
    for (i = 0; i < 46; i++) {
        if (scriptId < table[i].firstId)
            continue;
        if (scriptId > table[i].lastId)
            func_02034714(d_02172898, (int)0, d_02172898);
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
u8 *func_02158D78(int fileId, int heapId) {
    u8 *result = 0;
    if (result == 0) result = (u8 *)func_0204A1BC(0x39, fileId, (int)result, heapId);
    return result;
}


/*
 * Unlabelled leaf (a .word run in the ov010 listing): 0 for 2000, 1 below
 * 0x291C, else 0.  Callee of ov021 func_0218A0E4, func_0218A278 and
 * func_02189BD0.
 * Addresses are Black-image addresses.
 */
int func_02158D90(u16 scriptId)
{
    if (scriptId == 2000)
        return 0;
    if (scriptId < 0x291C)
        return 1;
    return 0;
}


int func_02158DB0(int mode)
{
    if (mode == 0)
        return 0;
    return 1;
}


void func_02158DBC(void)
{
    if (func_0203CD98() != 0) {
        GFL_NET_ClearExitFlag();
        func_0203CEAC(0);
        GFL_NET_IRC_WIRELESS_Exit();
        while (func_0203CDBC(GFL_NET_Main()) == 0)
            ;
    }
    for (;;)
        GFL_USE_PollPowerExit();
}


int func_02158DE8(ScriptVm *vm, void *cmdWork, void *fieldSys, u32 cmdIndex)
{
    int callMode, permitted;
    func_0201210C(fieldSys);
    func_0215A5D4(cmdWork);
    callMode = func_0215A5D8(cmdWork);
    permitted = 0;
    switch (callMode) {
    case 0: permitted = d_02170374[cmdIndex].allowInMode0; break;
    case 1: permitted = d_02170374[cmdIndex].allowInMode1; break;
    case 2: permitted = d_02170374[cmdIndex].allowInMode2; break;
    }
    if (permitted == 0)
        func_02158DBC();
    return permitted;
}


/*
 * ARM9 interface evidence: 02011324 reads +0x20; 02011328 stores r1/r2 at +0x24/+0x28.
 */
void func_02158E38(ScriptVm *vm) {
    void *cmdWork = func_0215A5DC(func_02011324(vm));
    func_02011328(vm, func_02158DE8, cmdWork);
}
