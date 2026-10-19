#ifndef GAME_ARM9_SCRIPT_VM_TYPES_H
#define GAME_ARM9_SCRIPT_VM_TYPES_H

/* Script VM (ica_anime.c, 0x02011xxx): a 0x30-byte interpreter context with a
 * call stack, a register file and a command table. The field script system,
 * the battle effect VM and the trainer AI all run on it. */

#include "../types.h"

struct ScriptVm;

typedef int (*ScriptCmdFn)(struct ScriptVm *vm, void *user);
typedef int (*ScriptWaitFn)(struct ScriptVm *vm, void *user);
typedef int (*ScriptHookFn)(struct ScriptVm *vm, void *user, void *arg, u32 op);

/* Creation parameters for the VM allocator (0x0201121C). */
typedef struct ScriptVmParams {
    u16 stackCap;                /* 0x00: call stack entries */
    u16 ringCap;                 /* 0x02: register file entries */
    const ScriptCmdFn *cmds;     /* 0x04: command table */
    u32 cmdCount;                /* 0x08 */
} ScriptVmParams;

typedef struct ScriptVm {
    ScriptVmParams params;       /* 0x00 */
    u8 depth;                    /* 0x0C: call stack depth */
    u8 state;                    /* 0x0D */
    u8 cmpFlag;                  /* 0x0E: compare result, 0 less, 1 equal, 2 greater */
    u8 pad0F;
    ScriptWaitFn wait;           /* 0x10 */
    u8 *pc;                      /* 0x14: script cursor */
    u32 *stack;                  /* 0x18 */
    u32 *ring;                   /* 0x1C: register file */
    void *user;                  /* 0x20 */
    ScriptHookFn hook;           /* 0x24 */
    void *hookArg;               /* 0x28 */
    void *data;                  /* 0x2C: script file */
} ScriptVm;

#endif
