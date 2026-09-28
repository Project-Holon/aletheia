/*
 * unit:     yes
 * function: func_020111EC, func_0201121C
 * address:  0x020111EC
 * packet:   pkt_020111EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734       0x02030734  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   unit_020111EC_File 0x020A7268  data
 *
 * The bottom two functions of the game's script virtual machine ("vm.c", the
 * __FILE__ string this unit's allocation site passes, at 0x020A7268, fixed by
 * the terminator of "net_save.c" at 0x020A725C).
 *
 * func_0201121C is the constructor: it takes a heap id and a 12-byte
 * descriptor { u16 stack_cap; u16 ring_cap; const ScriptCmdFn *cmds;
 * u32 cmd_count; }, allocates the 0x30-byte context plus both arrays behind
 * it in one block, copies the descriptor into the head of the context (12
 * bytes, so the copy is an inlined ldm/stm triple,
 * docs/idioms/aggregate-assignment-is-ldm-stm.md), and points +0x1c at the
 * first array and +0x18 one ring_cap past it.  Both capacities are read back
 * out of the caller's descriptor, not out of the context that was just
 * written, which is why the second ldrh addresses r5 and not r7.
 *
 * func_020111EC is the reset: program counter, both stack depths, the state
 * byte, the wait callback and the pre-dispatch hook all cleared, and both
 * arrays filled with zero at their declared capacities.  It is the shared
 * prologue of the two entry points in the next unit (func_0201126C and
 * func_0201127C, 0x0201126C and 0x0201127C).
 *
 * The 0x30-byte context is:
 *   +0x00 u16 stack_cap      (0x100 for the field script system)
 *   +0x02 u16 ring_cap       (0x40)
 *   +0x04 const ScriptCmdFn *cmds
 *   +0x08 u32 cmd_count
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct ScriptVm;

typedef int (*ScriptCmdFn)(struct ScriptVm *vm, void *user);
typedef int (*ScriptWaitFn)(struct ScriptVm *vm, void *user);
typedef int (*ScriptHookFn)(struct ScriptVm *vm, void *user, void *arg, u32 op);

typedef struct ScriptVmParams {
    u16 stack_cap;
    u16 ring_cap;
    const ScriptCmdFn *cmds;
    u32 cmd_count;
} ScriptVmParams;

typedef struct ScriptVm {
    ScriptVmParams params;
    u8 depth;
    u8 state;
    u8 ring_depth;
    u8 pad_0f;
    ScriptWaitFn wait;
    u8 *pc;
    u32 *stack;
    u32 *ring;
    void *user;
    ScriptHookFn hook;
    void *hook_arg;
    void *data;
} ScriptVm;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          int line);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern const char unit_020111EC_File[];

void func_020111EC(ScriptVm *vm)
{
    vm->pc = 0;
    vm->ring_depth = 0;
    vm->state = 0;
    vm->wait = 0;
    vm->depth = 0;
    MI_CpuFill8(vm->stack, 0, vm->params.stack_cap * 4);
    MI_CpuFill8(vm->ring, 0, vm->params.ring_cap * 4);
    vm->hook = 0;
    vm->hook_arg = 0;
}

ScriptVm *func_0201121C(u32 heapId, const ScriptVmParams *params)
{
    u32 size;
    ScriptVm *vm;

    size = params->ring_cap * 4 + sizeof(ScriptVm) + params->stack_cap * 4;
    vm = (ScriptVm *)sub_02030734(heapId, size, 0, unit_020111EC_File, 96);
    MI_CpuFill8(vm, 0, size);
    vm->params = *params;
    vm->ring = (u32 *)(vm + 1);
    vm->stack = vm->ring + params->ring_cap;
    return vm;
}
