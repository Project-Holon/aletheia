/*
 * file:     vm.c
 * unit:     yes
 * function: VM_Reset, VM_Create, VM_Delete, VM_Init, VM_Start, VM_End, VM_Control, VM_GetContext, VM_SetHook, VM_ReadU16, VM_GetU32, VM_PushStack, VM_PopStack, VM_Jump, VM_Call, VM_Return, VM_SetWait
 * address:  0x020111EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from vm.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   _VmFileName 0x020A7268  data
 *   GFL_HEAP_Alloc   0x02030734  arm
 */
#include "script_vm_types.h"

extern u32 GFL_HEAP_Free(void *memory);

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void VM_Reset(ScriptVm *vm);

ScriptVm *VM_Create(u32 heapId, const ScriptVmParams *params);

void VM_Delete(ScriptVm *vm);

void VM_Init(ScriptVm *vm, void *user);

void VM_Start(ScriptVm *vm, u8 *pc);

ScriptVm *VM_End(ScriptVm *vm);

int VM_Control(ScriptVm *vm);

void *VM_GetContext(ScriptVm *vm);

void VM_SetHook(ScriptVm *vm, ScriptHookFn hook, void *arg);

u16 VM_ReadU16(ScriptVm *vm);

u32 VM_GetU32(ScriptVm *vm);

void VM_PushStack(ScriptVm *vm, u32 value);

u32 VM_PopStack(ScriptVm *vm);

void VM_Jump(ScriptVm *vm, u8 *pc);

void VM_Call(ScriptVm *vm, u8 *pc);

u8 *VM_Return(ScriptVm *vm);

void VM_SetWait(ScriptVm *vm, ScriptWaitFn wait);

extern const char _VmFileName[];

/*
 * The bottom two functions of the game's script virtual machine ("vm.c", the
 * __FILE__ string this unit's allocation site passes, at 0x020A7268, fixed by
 * the terminator of "net_save.c" at 0x020A725C).
 *
 * VM_Create is the constructor: it takes a heap id and a 12-byte
 * descriptor { u16 stackCap; u16 ringCap; const ScriptCmdFn *cmds;
 * u32 cmdCount; }, allocates the 0x30-byte context plus both arrays behind
 * it in one block, copies the descriptor into the head of the context (12
 * bytes, so the copy is an inlined ldm/stm triple,
 * docs/idioms/aggregate-assignment-is-ldm-stm.md), and points +0x1c at the
 * first array and +0x18 one ringCap past it.  Both capacities are read back
 * out of the caller's descriptor, not out of the context that was just
 * written, which is why the second ldrh addresses r5 and not r7.
 *
 * VM_Reset is the reset: program counter, both stack depths, the state
 * byte, the wait callback and the pre-dispatch hook all cleared, and both
 * arrays filled with zero at their declared capacities.  It is the shared
 * prologue of the two entry points in the next unit (VM_Init and
 * VM_Start, 0x0201126C and 0x0201127C).
 *
 * The 0x30-byte context is:
 *   +0x00 u16 stackCap      (0x100 for the field script system)
 *   +0x02 u16 ringCap       (0x40)
 *   +0x04 const ScriptCmdFn *cmds
 *   +0x08 u32 cmdCount
 *   +0x0c u8  stack depth
 *   +0x0d u8  state (0 stopped, 1 running, 2 waiting on the callback)
 *   +0x0e u8  ring depth
 *   +0x10 wait callback
 *   +0x14 u8 *pc
 *   +0x18 u32 *stack
 *   +0x1c u32 *ring
 *   +0x20 user object
 *   +0x24 pre-dispatch hook, +0x28 its argument
 *   +0x2c owner-defined word (the loaded script file, for the field system)
 *
 * The unit stops one word short of the Thumb-to-ARM veneer at 0x02011264
 * (`ldr r3,[pc,#0]; bx r3; .word 0x020307B0`), which no tu range may span
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020111EC.c \
 *       --addr 0x020111EC --thumb --cc 1.1p1
 */
void VM_Reset(ScriptVm *vm)
{
    vm->pc = 0;
    vm->cmpFlag = 0;
    vm->state = 0;
    vm->wait = 0;
    vm->depth = 0;
    MI_CpuFill8(vm->stack, 0, vm->params.stackCap * 4);
    MI_CpuFill8(vm->ring, 0, vm->params.ringCap * 4);
    vm->hook = 0;
    vm->hookArg = 0;
}

ScriptVm *VM_Create(u32 heapId, const ScriptVmParams *params)
{
    u32 size;
    ScriptVm *vm;

    size = params->ringCap * 4 + sizeof(ScriptVm) + params->stackCap * 4;
    vm = (ScriptVm *)GFL_HEAP_Alloc(heapId, size, 0, _VmFileName, 96);
    MI_CpuFill8(vm, 0, size);
    vm->params = *params;
    vm->ring = (u32 *)(vm + 1);
    vm->stack = vm->ring + params->ringCap;
    return vm;
}

void VM_Delete(ScriptVm *vm)
{
    GFL_HEAP_Free(vm);
}

/*
 *           VM_GetContext, VM_SetHook
 *
 * The step function of the game's script virtual machine ("vm.c"), plus the
 * four small entry points around it.  The context layout and the
 * constructor are in src/matched/unit_020111EC.c.
 *
 * VM_Control is the interpreter core, called once per frame by the owner
 * of the context:
 *
 *   state 0  stopped, nothing to do
 *   state 1  running: fetch a u16 opcode with VM_ReadU16 (the cursor read
 *            that advances +0x14 by two), bounds-check it against +0x08, run
 *            the optional pre-dispatch hook at +0x24, then call
 *            cmds[opcode](vm, user).  A handler returning 1 yields for this
 *            frame; returning 0 continues straight into the next opcode, so
 *            the whole loop is one frame's worth of script.
 *   state 2  waiting: call the callback at +0x10 with (vm, user) every frame
 *            until it returns 1, then clear it and go back to running.  A
 *            null callback in this state is treated as "done waiting".
 *
 * Every abnormal exit (null pc, opcode past the table, hook veto) stops the
 * machine by writing 0 to +0x0d and returning 0, and every yield returns 1;
 * the default arm's `state = 0; return 1` and the handler's `return 1` share
 * one tail (docs/idioms/switch-arms-tail-merge.md).
 *
 * Two shapes in the switch are load-bearing and neither is optional.  The
 * arms are written in the order 0, 2, 1, default: state 2 falls through into
 * state 1 once its callback is gone, which is what puts the wait block
 * physically before the loop and lets the fall-through reach the loop head
 * with no branch.  And the interpreter loop leaves through `break` twice
 * over (out of the `for`, then out of the switch) rather than by returning
 * in place, so that the yield and the default arm's stop share one
 * `movs r0, #1; pop` tail; writing `return 1` at either site splits that
 * tail and costs four bytes
 * (docs/idioms/switch-arms-tail-merge.md,
 * docs/idioms/an-empty-switch-arm-breaks-to-the-last-epilogue-not-the-nearest.md).
 *
 * The wait callback has to be bound to a local: the original loads +0x10
 * once and both tests and calls that register, which a re-read of the field
 * across the call would not reproduce.
 *
 * VM_End, VM_GetContext and VM_SetHook carry no label in the
 * generated listing: none of the three saves `lr`, so disasm.py's prologue
 * sweep never fires and their bytes print as a `.word` run
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The field script system instantiates this VM in overlay 10 at
 * SCRIPT_SYS_CreateVm with a 609-entry command table at 0x0217062C; see the
 * "Script virtual machine" section of docs/ASSETS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201126C.c \
 *       --addr 0x0201126C --thumb --cc 1.1p1
 */
void VM_Init(ScriptVm *vm, void *user)
{
    VM_Reset(vm);
    vm->user = user;
}

void VM_Start(ScriptVm *vm, u8 *pc)
{
    VM_Reset(vm);
    vm->pc = pc;
    vm->state = 1;
}

ScriptVm *VM_End(ScriptVm *vm)
{
    vm->state = 0;
    vm->pc = 0;
    return vm;
}

/*
 * VM_End's bytes after its first `movs r1, #0` (where the caller's r1 is
 * stored to vm->state and vm->pc) were once filed as a separate function by
 * an early matching wave; they are part of VM_End, not an entry of their own.
 */
int VM_Control(ScriptVm *vm)
{
    u32 op;
    ScriptWaitFn wait;

    switch (vm->state) {
    case 0:
        return 0;
    case 2:
        wait = vm->wait;
        if (wait != 0) {
            if (wait(vm, vm->user) == 1) {
                vm->wait = 0;
                vm->state = 1;
            }
            return 1;
        }
        vm->state = 1;
        /* fall through */
    case 1:
        for (;;) {
            if (vm->pc == 0) {
                vm->state = 0;
                return 0;
            }
            op = VM_ReadU16(vm);
            if (op >= vm->params.cmdCount) {
                vm->state = 0;
                return 0;
            }
            if (vm->hook != 0) {
                if (vm->hook(vm, vm->user, vm->hookArg, op) == 0) {
                    vm->state = 0;
                    return 0;
                }
            }
            if (vm->params.cmds[op](vm, vm->user) == 1) {
                break;
            }
        }
        break;
    default:
        vm->state = 0;
        break;
    }

    return 1;
}

void *VM_GetContext(ScriptVm *vm)
{
    return vm->user;
}

void VM_SetHook(ScriptVm *vm, ScriptHookFn hook, void *arg)
{
    vm->hook = hook;
    vm->hookArg = arg;
}

/*
 *           VM_Jump, VM_Call, VM_Return
 *
 * Seven functions, no external calls at all, over two small structs read and
 * written by cursor.  Two of the seven carry no label in the generated
 * listing at all: VM_GetU32 and VM_Jump, both leaves whose
 * prologue (or total absence of one) saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * VM_Jump is four bytes, `str r1, [r0, #0x14]; bx lr`: the plain
 * setter of the +0x14 field that VM_Call and VM_Return reach only
 * through a history ring.
 *
 * VM_ReadU16 and VM_GetU32 are a matched pair, a little-endian u16
 * and u32 read off a byte cursor at +0x14, advancing it by 2 and by 4.
 * VM_GetU32 carries no label in the generated listing: it opens with
 * `push {r4, r5}`, which saves no `lr`, so disasm.py's prologue sweep never
 * fires on it and its 48 bytes print as a `.word` run between VM_ReadU16
 * and VM_PushStack (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Its four byte reads are built MSB-first through a Horner chain
 * (((0 + b3) << 8 + b2) << 8 + b1) << 8 + b0, which is what the register
 * allocator does with a `for` loop counting down; the two-byte version is
 * small enough that the same loop unrolls into the flat expression used
 * below.
 *
 * VM_PushStack and VM_PopStack are a fixed-capacity ring: a byte count at
 * +0xC bounded by a halfword capacity at +0x0, backed by a `u32` array
 * pointed to by +0x18.  VM_PushStack pushes if there is room and returns
 * whether it did; VM_PopStack pops the oldest entry, or 0 if the ring is
 * empty (and leaves the count at 0 rather than going negative).
 *
 * VM_Call and VM_Return are a different struct's accessors for a
 * plain u32 field at +0x14, the same offset VM_Jump sets directly:
 * VM_Call pushes the field's old value onto a VM_PushStack ring
 * before overwriting it with the new one, and VM_Return pops a
 * VM_PopStack ring back into the field.  Both take the ring struct
 * pointer as the same first argument as the field's owner, so the two
 * structs are declared distinctly here (Ring and Cur) even though nothing
 * in this file proves they are not the same struct in the original; only
 * the offsets that are read are declared.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011330.c \
 *       --addr 0x02011330 --thumb
 */
u16 VM_ReadU16(ScriptVm *vm)
{
    u8  lo, hi;
    u16 high;

    lo = *vm->pc;
    vm->pc = vm->pc + 1;
    hi = *vm->pc;
    vm->pc = vm->pc + 1;
    high = (u16)(hi << 8);
    return lo + high;
}

u32 VM_GetU32(ScriptVm *vm)
{
    u8  b0, b1, b2, b3;
    u32 value;

    b0 = *vm->pc;
    vm->pc = vm->pc + 1;
    b1 = *vm->pc;
    vm->pc = vm->pc + 1;
    b2 = *vm->pc;
    vm->pc = vm->pc + 1;
    b3 = *vm->pc;
    vm->pc = vm->pc + 1;

    value = 0;
    value = value + b3;
    value = value << 8;
    value = value + b2;
    value = value << 8;
    value = value + b1;
    value = value << 8;
    value = value + b0;
    return value;
}

void VM_PushStack(ScriptVm *vm, u32 value)
{
    if (vm->depth + 1 < vm->params.stackCap) {
        vm->stack[vm->depth] = value;
        vm->depth = vm->depth + 1;
    }
}

u32 VM_PopStack(ScriptVm *vm)
{
    if (vm->depth == 0) {
        return 0;
    }
    vm->depth = vm->depth - 1;
    return vm->stack[vm->depth];
}

void VM_Jump(ScriptVm *vm, u8 *pc)
{
    vm->pc = pc;
}

void VM_Call(ScriptVm *vm, u8 *pc)
{
    u8 *ret = vm->pc;
    VM_PushStack(vm, (u32)ret);
    vm->pc = pc;
}

u8 *VM_Return(ScriptVm *vm)
{
    vm->pc = (u8 *)VM_PopStack(vm);
    return vm->pc;
}

void VM_SetWait(ScriptVm *vm, ScriptWaitFn wait)
{
    vm->state = 2;
    vm->wait = wait;
}
