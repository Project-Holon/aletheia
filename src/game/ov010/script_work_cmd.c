/*
 * file:     script_work_cmd.c
 * unit:     yes
 * function: func_0215932C, func_02159340, func_02159370, func_02159398, func_021593B8, func_021593DC, func_021593F0, func_02159404, func_02159420, func_0215942C, func_0215944C, func_0215946C, func_0215948C, func_021594B0, func_021594E0, func_02159570, func_021595A0, func_021595CC, func_02159644, func_02159658, func_02159670, func_021596B4, func_021596E8, func_02159708, func_02159728, func_02159750, func_02159778, func_021597AC, func_021597CC, func_021597EC, func_0215980C, func_02159830, func_02159854, func_02159874, func_02159894, func_021598AC, func_021598C8, func_021598E4, func_021598EC, func_02159934, func_02159960, func_02159974, func_02159984, func_02159998, func_021599A8, func_02159A64, func_02159AE8, func_02159B10, func_02159B38
 * address:  0x0215932C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Continues script_work.c (script command handlers, VM_* calls).
 * script_work.c ends at 0x021592D8 and unit_021592F0.c (0x021592F0..0x0215930C)
 * sits between; this piece starts at 0x0215932C, so the three ranges are
 * contiguous and merge into script_work.c at cut time.
 *
 * symbols:
 *   func_02011330   0x02011330  thumb
 *   VM_PushStack  0x0201137C  thumb
 *   VM_PopStack  0x02011398  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021589A0  0x021589A0  thumb  ov010
 *   func_0215AA4C  0x0215AA4C  thumb  ov010
 *   func_021587E0  0x021587E0  thumb  ov010
 *   func_0215AA34  0x0215AA34  thumb  ov010
 *   func_0215AA48  0x0215AA48  thumb  ov010
 *   func_0215AA24  0x0215AA24  thumb  ov010
 *   func_02158A34  0x02158A34  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_02011290  0x02011290  thumb
 *   func_0201134C  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   d_021705DC     0x021705DC  data  ov010
 *   func_02012B38   0x02012B38  thumb
 *   func_02014474   0x02014474  thumb
 *   func_02014460  0x02014460  thumb
 *   func_02014314  0x02014314  thumb
 *   func_0201433C  0x0201433C  thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B1BB8  0x021B1BB8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_021B1BE8  0x021B1BE8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_GetQueueDepth  0x020288C4  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAllTask  0x0202972C  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159204 0x02159204 thumb ov010
 *   func_020362DC  0x020362DC  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02012DD0  0x02012DD0  thumb
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A153C  0x021A153C  thumb  ov021
 *   func_021A1548  0x021A1548  thumb  ov021
 *   func_021590FC  0x021590FC  thumb  ov010
 *   func_021D11D8  0x021D11D8  thumb
 *   func_021D1194  0x021D1194  thumb
 *   func_021590F4  0x021590F4  thumb  ov010
 *   func_02188C84  0x02188C84  thumb
 *   func_021D1164  0x021D1164  thumb
 *   func_021D11B0  0x021D11B0  thumb
 *   func_021A1524  0x021A1524  thumb  ov021
 *   func_021A1530  0x021A1530  thumb  ov021
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02012DAC  0x02012DAC  thumb
 *   func_02158FE0   0x02158FE0  thumb  ov010
 *   func_0215901C   0x0215901C  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10   0x02159B10  thumb  ov010
 *   func_0215A5D4  0x0215A5D4  thumb  ov010
 *   func_0215A5D8  0x0215A5D8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   VM_Call  0x020113B4  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldMapState;
struct FieldSoundSystem;
struct PlayerWork;
struct EventWork;
struct MoveModelSys;
struct TrainerRecord;
struct ScriptTask;
struct ScrcmdWork;
#include "../arm9/script_vm_types.h"
#include "script_work_types.h"

typedef struct ScrcmdWork ScrcmdWork;

/* Arm9 script VM primitives. */
extern u16 func_02011330(ScriptVm *vm);
extern s32 func_0201134C(ScriptVm *vm);
extern void VM_PushStack(ScriptVm *vm, u32 value);
extern u32 VM_PopStack(ScriptVm *vm);
extern void func_02011290(ScriptVm *vm);
extern void VM_Jump(ScriptVm *vm, u32 target);
extern void VM_Call(ScriptVm *vm, u32 target);
extern void func_020113D0(ScriptVm *vm, int (*waitFn)(ScriptVm *, ScrcmdWork *));
extern u64 _u32_div_f(u32 dividend, u32 divisor);

/* Game data and system accessors. */
extern struct EventWork *func_0201296C(const struct GameData *gameData);
extern u32 func_020142E8(struct EventWork *eventWork, s32 flagId);
extern void func_02014314(struct EventWork *eventWork, int flagId);
extern void func_0201433C(struct EventWork *eventWork, int flagId);
extern struct MoveModelSys *func_02012B38(const struct GameData *gameData);
extern void func_02014474(struct MoveModelSys *sys, void *action);
extern u8 func_02014460(struct MoveModelSys *sys);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct FieldSoundSystem *func_02012A30(const struct GameData *gameData);
extern s32 FIELD_SOUND_SYSTEM_GetQueueDepth(struct FieldSoundSystem *soundSystem);
extern struct ScriptTask *FIELD_SOUND_SYSTEM_StartPopAllTask(struct GameSystem *gameSystem, u16 mode);
extern u32 func_020362DC(void);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern u8 func_02012E40(struct GameData *gameData);
extern int func_02012DD0(struct GameData *gameData);
extern void func_02012DAC(struct GameData *gameData);
extern struct TrainerRecord *func_02012F2C(struct GameData *gameData);
extern u32 func_02008DF0(struct TrainerRecord *record, int index);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern u16 func_02012AC8(const struct PlayerWork *player);

/* Field map overlay helpers. */
extern struct FieldMapState *func_02188CCC(struct FieldMap *fieldMap);
extern int func_02188C84(struct FieldMap *fieldMap);
extern u32 func_021A0F90(struct FieldMapState *state);
extern int func_021A153C(struct FieldMapState *state);
extern void func_021A1548(struct FieldMapState *state);
extern void func_021A1524(struct FieldMapState *state);
extern void func_021A1530(struct FieldMapState *state);
extern int func_021D1164(int mapId, struct FieldMap *fieldMap);
extern void func_021D11B0(int effectHandle);
extern void func_021D11D8(int effectHandle);
extern void func_021D1194(int effectHandle);
extern int func_021B1BB8(ScriptVm *vm, ScrcmdWork *cmdWork);
extern void func_021B1BE8(ScrcmdWork *cmdWork);

/* Script system and script work. */
extern int func_021589A0(ScriptWork *scriptWork, int zoneId, int scriptId);
extern int func_021587E0(ScriptWork *scriptWork, int childIndex);
extern void func_02158A34(void *first, void *second, int scriptId, int callParam);
extern void func_0215897C(ScriptWork *scriptWork, struct ScriptTask *task);
extern u16 *func_02158FE0(ScriptWork *scriptWork, struct GameData *gameData, u32 workId);
extern u32 func_0215901C(ScriptWork *scriptWork, struct GameData *gameData, u32 workId);
extern void func_021590F4(ScriptWork *scriptWork, u32 scriptId);
extern u32 func_021590FC(ScriptWork *scriptWork);
extern struct ScriptTask *func_02159204(ScrcmdWork *cmdWork);

/* Command work accessors. */
extern u8 func_0215AA4C(ScrcmdWork *cmdWork);
extern int func_0215AA34(ScrcmdWork *cmdWork);
extern void func_0215AA48(ScrcmdWork *cmdWork, int childIndex);
extern void *func_0215AA24(ScrcmdWork *cmdWork);
extern u32 func_0215A5D4(ScrcmdWork *cmdWork);
extern u32 func_0215A5D8(ScrcmdWork *cmdWork);
extern struct GameSystem *func_0215A5DC(ScrcmdWork *cmdWork);
extern struct GameData *func_0215A5E4(ScrcmdWork *cmdWork);
extern ScriptWork *func_0215A5F4(ScrcmdWork *cmdWork);

/* Condition table of the conditional jump and call commands, [condition][compare flag]. */
extern u8 d_021705DC[][3];

int func_0215932C(unsigned int lhs, unsigned int rhs);
int func_021595A0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_02159960(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_02159984(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_021599A8(ScriptVm *vm, ScrcmdWork *cmdWork);
u16 *func_02159AE8(ScriptVm *vm, ScrcmdWork *cmdWork);
unsigned int func_02159B10(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_02159B38(ScrcmdWork *cmdWork);

int func_0215932C(unsigned int lhs, unsigned int rhs)
{
    if (lhs < rhs) return 0;
    if (lhs == rhs) return 1;
    return 2;
}

static inline int ReadByte(ScriptVm *vm)
{
    int value = *vm->pc;
    vm->pc++;
    return value;
}

/*
 * extent: two-byte zero alignment padding follows the 46-byte function.
 * lever: inline byte reader binds the load before incrementing the cursor;
 * a postincrement expression schedules the cursor store before the load.
 */
int func_02159340(ScriptVm *vm)
{
    u8 lhs, rhs;
    lhs = vm->ring[ReadByte(vm)];
    rhs = vm->ring[ReadByte(vm)];
    vm->cmpFlag = func_0215932C(lhs, rhs);
    return 0;
}

int func_02159370(ScriptVm *vm)
{
    u8 lhs, rhs;
    lhs = vm->ring[ReadByte(vm)];
    rhs = ReadByte(vm);
    vm->cmpFlag = func_0215932C(lhs, rhs);
    return 0;
}

/*
 * Halfword out of the record the overlay looks up, classified through an
 * arm9 call, and the class byte stored back on the object.
 */
int func_02159398(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 workValue = *func_02159AE8(vm, cmdWork);

    vm->cmpFlag = func_0215932C(workValue, func_02011330(vm));

    return 0;
}

int func_021593B8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *lhs = func_02159AE8(vm, cmdWork);
    u16 *rhs = func_02159AE8(vm, cmdWork);
    vm->cmpFlag = func_0215932C(*lhs, *rhs);
    return 0;
}

int func_021593DC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_PushStack(vm, func_02011330(vm));
    return 0;
}

int func_021593F0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_PushStack(vm, func_02159B10(vm, cmdWork));
    return 0;
}

int func_02159404(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 value = VM_PopStack(vm);
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    *workPtr = value;
    return 0;
}

int func_02159420(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_PopStack(vm);
    return 0;
}

/*
 * One arm9 getter read twice, folded with '+', written back
 * through the arm9 setter.
 */
int func_0215942C(ScriptVm *vm)
{
    int top = VM_PopStack(vm);
    int below = VM_PopStack(vm);

    VM_PushStack(vm, below + top);

    return 0;
}

/*
 * One arm9 getter read twice, folded with '-', written back
 * through the arm9 setter.
 */
int func_0215944C(ScriptVm *vm)
{
    int top = VM_PopStack(vm);
    VM_PushStack(vm, VM_PopStack(vm) - top);
    return 0;
}

/*
 * One arm9 getter read twice, folded with '*', written back
 * through the arm9 setter.
 */
int func_0215946C(ScriptVm *vm)
{
    int top = VM_PopStack(vm);
    int below = VM_PopStack(vm);
    VM_PushStack(vm, below * top);
    return 0;
}

int func_0215948C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 divisor = VM_PopStack(vm);
    u32 dividend = VM_PopStack(vm);
    VM_PushStack(vm, (u32)_u32_div_f(dividend, divisor));
    return 0;
}

int func_021594B0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = func_0215A5E4(cmdWork);
    struct EventWork *eventWork = func_0201296C(gameData);
    u32 flagId = func_02159B10(vm, cmdWork);
    VM_PushStack(vm, func_020142E8(eventWork, flagId));
    return 0;
}

int func_021594E0(ScriptVm *vm)
{
    u32 top = VM_PopStack(vm);
    u32 below = VM_PopStack(vm);
    int result;
    switch (func_02011330(vm)) {
    case 0: result = (below < top) ? 1 : 0; break;
    case 1: result = (below == top) ? 1 : 0; break;
    case 2: result = (below > top) ? 1 : 0; break;
    case 3: result = (below <= top) ? 1 : 0; break;
    case 4: result = (below >= top) ? 1 : 0; break;
    case 5: result = (below != top) ? 1 : 0; break;
    case 6: result = (below == 1 || top == 1) ? 1 : 0; break;
    case 7: result = (below == 1 && top == 1) ? 1 : 0; break;
    default: result = 0; break;
    }
    VM_PushStack(vm, result);
    return 0;
}

int func_02159570(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    int scriptId;

    func_0215A5DC(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    scriptId = func_02011330(vm);
    func_021589A0(scriptWork, func_02159B38(cmdWork), scriptId);
    return 1;
}

int func_021595A0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    if (func_021587E0(scriptWork, func_0215AA4C(cmdWork)) == 0) {
        func_0215AA34(cmdWork);
        return 1;
    }
    return 0;
}

int func_021595CC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    int scriptId = func_02011330(vm);
    if (func_0215A5D4(cmdWork) == 0) {
        func_0215AA48(cmdWork, func_021589A0(scriptWork, func_02159B38(cmdWork), scriptId));
        func_0215AA24(cmdWork);
        func_020113D0(vm, func_021595A0);
        return 1;
    }
    func_0215AA24(cmdWork);
    func_02158A34(gameSystem, scriptWork, scriptId, func_0215A5D8(cmdWork));
    func_0215AA34(cmdWork);
    return 0;
}

int func_02159644(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    func_0215A5F4(cmdWork);
    func_02011290(vm);
    return 1;
}

int func_02159658(ScriptVm *vm)
{
    s32 offset = func_0201134C(vm);
    VM_Jump(vm, (u32)vm->pc + offset);
    return 0;
}

int func_02159670(ScriptVm *vm)
{
    u8 *pc = vm->pc;
    u8 condition = *pc;
    int offset;
    vm->pc = pc + 1;
    offset = func_0201134C(vm);
    if (condition == 0xFF) {
        if (VM_PopStack(vm) == 1)
            goto end;
    } else {
        if (d_021705DC[condition][vm->cmpFlag] != 1)
            goto end;
    }
    VM_Jump(vm, (u32)(vm->pc + offset));
end:
    return 0;
}

/*
 * prototype: 020113B4's matched ARM9 unit copies the full-word second
 * input unchanged into +0x14; original caller supplies a cursor address.
 * Pointer declaration preserves that payload and matches the fixed flags.
 */
int func_021596B4(ScriptVm *vm)
{
    u8 *pc = vm->pc;
    u8 condition = *pc;
    int offset;
    vm->pc = pc + 1;
    offset = func_0201134C(vm);
    if (d_021705DC[condition][vm->cmpFlag] == 1)
        VM_Call(vm, (u32)(vm->pc + offset));
    return 0;
}

/*
 * The record's arm9 handle and the caller's second argument are the two
 * operands of the arm9 pair call.
 */
int func_021596E8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    void *action = (void *)func_02011330(vm);
    func_02014474(func_02012B38(func_0215A5E4(cmdWork)), action);
    return 0;
}

int func_02159708(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    struct MoveModelSys *moveModelSys = func_02012B38(func_0215A5E4(cmdWork));
    *workPtr = func_02014460(moveModelSys);
    return 0;
}

int func_02159728(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = func_0215A5E4(cmdWork);
    struct EventWork *eventWork = func_0201296C(gameData);
    int flagId = func_02159B10(vm, cmdWork);
    func_02014314(eventWork, flagId);
    return 0;
}

int func_02159750(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = func_0215A5E4(cmdWork);
    struct EventWork *eventWork = func_0201296C(gameData);
    int flagId = func_02159B10(vm, cmdWork);
    func_0201433C(eventWork, flagId);
    return 0;
}

int func_02159778(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct EventWork *eventWork = func_0201296C(func_0215A5E4(cmdWork));
    u32 flagId = func_02159B10(vm, cmdWork);
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    *workPtr = func_020142E8(eventWork, flagId);
    return 0;
}

/*
 * extent: two bytes of zero alignment padding at 0x021597CA.
 */
int func_021597AC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    *workPtr = *workPtr + func_02159B10(vm, cmdWork);
    return 0;
}

int func_021597CC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    u32 value = func_02159B10(vm, cmdWork);
    *workPtr = *workPtr - value;
    return 0;
}

/*
 * extent: two bytes of zero alignment padding at 0x0215980A.
 */
int func_021597EC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    *workPtr = *workPtr * func_02159B10(vm, cmdWork);
    return 0;
}

int func_0215980C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    u32 divisor = func_02159B10(vm, cmdWork);
    *workPtr = (u32)_u32_div_f(*workPtr, divisor);
    return 0;
}

/*
 * extent: two bytes of zero alignment padding at 0x02159852.
 * prototype: named runtime helper has opaque combined scalar return;
 * the original and compiled helper arguments are numerator r0, divisor r1.
 * low word is original r0 output, high word is original r1 remainder.
 * The original admits zero divisors. Direct helper call preserves that
 * behavior without expressing undefined C remainder on a zero divisor.
 * Fixed-flag run 1 proves u64 return in r0/r1: high-word extraction emits
 * no shift, and strh r1 immediately follows the original helper call.
 */
int func_02159830(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    u32 divisor = func_02159B10(vm, cmdWork);
    *workPtr = (u32)(_u32_div_f(*workPtr, divisor) >> 32);
    return 0;
}

int func_02159854(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    u32 value = func_02159B10(vm, cmdWork);
    *workPtr = value & *workPtr;
    return 0;
}

int func_02159874(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    u32 value = func_02159B10(vm, cmdWork);
    *workPtr = value | *workPtr;
    return 0;
}

int func_02159894(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    *workPtr = func_02011330(vm);
    return 0;
}

int func_021598AC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *dstPtr = func_02159AE8(vm, cmdWork);
    u16 *srcPtr = func_02159AE8(vm, cmdWork);
    *dstPtr = *srcPtr;
    return 0;
}

int func_021598C8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = func_02159AE8(vm, cmdWork);
    *workPtr = func_02159B10(vm, cmdWork);
    return 0;
}

/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_021B1BB8, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021598E4.c \
 *       --func func_021598E4 --addr 0x021598E4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_021598E4(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    return func_021B1BB8(vm, cmdWork);
}

int func_021598EC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    struct GameData *gameData = func_020120F4(gameSystem);
    int popped = 0;
    func_021B1BE8(cmdWork);
    if (FIELD_SOUND_SYSTEM_GetQueueDepth(func_02012A30(gameData))) {
        func_0215897C(scriptWork, FIELD_SOUND_SYSTEM_StartPopAllTask(gameSystem, popped));
        popped = 1;
    }
    return popped;
}

/*
 * extent: two bytes of zero alignment padding at 0x0215995E.
 */
int func_02159934(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct ScriptTask *task;
    func_0215A5DC(cmdWork);
    task = func_02159204(cmdWork);
    if (task == 0)
        return 1;
    func_0215897C(scriptWork, task);
    return 1;
}

int func_02159960(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if ((func_020362DC() & 3) == 0)
        return 0;
    return 1;
}

int func_02159974(ScriptVm *vm)
{
    func_020113D0(vm, func_02159960);
    return 1;
}

int func_02159984(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if ((func_020362DC() & 0xf3) == 0)
        return 0;
    return 1;
}

int func_02159998(ScriptVm *vm)
{
    func_020113D0(vm, func_02159984);
    return 1;
}

int func_021599A8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = func_0215A5E4(cmdWork);
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct FieldMapState *mapState;
    int done;
    mapState = func_02188CCC(func_0201210C(func_0215A5DC(cmdWork)));
    if (func_02012E40(gameData) == 0) {
        done = 1;
        if (func_021A0F90(mapState) == 7) {
            if (func_021A153C(mapState) == 0)
                done = 0;
        }
    } else {
        switch (func_02012DD0(gameData)) {
        case 0:
        case 1:
            done = 0;
            break;
        case 2:
            *func_02159AE8(vm, cmdWork) = 1;
            done = 0;
            break;
        case 3:
            *func_02159AE8(vm, cmdWork) = 0;
            done = 1;
            if (func_021A0F90(mapState) == 7)
                func_021A1548(mapState);
            break;
        }
    }
    if (done == 1) {
        int effectHandle = func_021590FC(scriptWork);
        func_021D11D8(effectHandle);
        func_021D1194(effectHandle);
        func_021590F4(scriptWork, 0);
    }
    return done;
}

int func_02159A64(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct GameData *gameData = func_0215A5E4(cmdWork);
    int mapId, effectHandle;
    struct FieldMap *fieldMap;
    struct FieldMapState *mapState;
    fieldMap = func_0201210C(func_0215A5DC(cmdWork));
    mapId = func_02188C84(fieldMap);
    mapState = func_02188CCC(fieldMap);
    effectHandle = func_021D1164(mapId, fieldMap);
    func_021D11B0(effectHandle);
    if (func_021A0F90(mapState) == 7) {
        func_021A1524(mapState);
        func_021A1530(mapState);
    }
    func_021590F4(scriptWork, effectHandle);
    func_02008DF0(func_02012F2C(gameData), 1);
    func_02012DAC(gameData);
    func_020113D0(vm, func_021599A8);
    return 1;
}

/*
 * Two record lookups on the second argument and a classification of the
 * first, submitted as three arguments.
 */
u16 *func_02159AE8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = func_0215A5E4(cmdWork);
    return func_02158FE0(func_0215A5F4(cmdWork), gameData, func_02011330(vm));
}

/*
 * Same three-argument submission as its neighbour, aimed at the second
 * overlay handler.
 */
unsigned int func_02159B10(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = func_0215A5E4(cmdWork);
    return func_0215901C(func_0215A5F4(cmdWork), gameData, func_02011330(vm));
}

int func_02159B38(ScrcmdWork *cmdWork)
{
    struct PlayerWork *player = func_020127A4(func_0215A5E4(cmdWork));
    return func_02012AC8(player);
}
