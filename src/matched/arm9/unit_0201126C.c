/*
 * unit:     yes
 * function: VM_Init, VM_Start, VM_End, VM_Control,
 *           VM_GetContext, VM_SetHook
 * address:  0x0201126C
 * packet:   pkt_020111EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_Reset  0x020111EC  thumb
 *   func_02011330  0x02011330  thumb
 *
 * The step function of the game's script virtual machine ("vm.c"), plus the
 * four small entry points around it.  The context layout and the
 * constructor are in src/matched/unit_020111EC.c.
 *
 * VM_Control is the interpreter core, called once per frame by the owner
 * of the context:
 *
 *   state 0  stopped, nothing to do
 *   state 1  running: fetch a u16 opcode with func_02011330 (the cursor read
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
 * func_02158BFC with a 609-entry command table at 0x0217062C; see the
 * "Script virtual machine" section of docs/ASSETS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201126C.c \
 *       --addr 0x0201126C --thumb --cc 1.1p1
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

extern void VM_Reset(ScriptVm *vm);
struct Stream;
extern u16 func_02011330(struct Stream *s);

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
            op = func_02011330((struct Stream *)vm);
            if (op >= vm->params.cmd_count) {
                vm->state = 0;
                return 0;
            }
            if (vm->hook != 0) {
                if (vm->hook(vm, vm->user, vm->hook_arg, op) == 0) {
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
    vm->hook_arg = arg;
}
