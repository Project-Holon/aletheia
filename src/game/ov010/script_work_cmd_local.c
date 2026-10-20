/*
 * file:     script_work_cmd_local.c
 * function: SCRIPT_WORK_CmdSetLocalU32, SCRIPT_WORK_CmdCopyLocal
 * address:  0x021592F0
 * packet:   pkt_021592F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../types.h"

/* Script VM context: program counter and the local variable array. */
#include "../arm9/script_vm_types.h"

#include "../arm9/vm.h"

static inline u8 ScriptVm_ReadU8(ScriptVm *vm)
{
    u8 value = *vm->pc;
    vm->pc++;
    return value;
}

/* Script command: ring[index byte] = 32-bit immediate. */
int SCRIPT_WORK_CmdSetLocalU32(ScriptVm *vm, void *user)
{
    u8 index = ScriptVm_ReadU8(vm);
    u32 value = VM_GetU32(vm);
    vm->ring[index] = value;
    return 0;
}

/* Script command: ring[dest byte] = ring[source byte]. */
int SCRIPT_WORK_CmdCopyLocal(ScriptVm *vm)
{
    u8 dest = ScriptVm_ReadU8(vm);
    u8 source = ScriptVm_ReadU8(vm);
    vm->ring[dest] = vm->ring[source];
    return 0;
}
