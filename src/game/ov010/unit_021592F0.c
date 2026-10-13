/*
 * file:     unit_021592F0.c
 * function: func_021592F0, func_0215930C
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
 *   func_0201134C  0x0201134C  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Script VM context: program counter and the local variable array. */
#include "../arm9/script_vm_types.h"

extern u32 func_0201134C(ScriptVm *vm);

static inline u8 ScriptVm_ReadU8(ScriptVm *vm)
{
    u8 value = *vm->pc;
    vm->pc++;
    return value;
}

/* Script command: ring[index byte] = 32-bit immediate. */
int func_021592F0(ScriptVm *vm, void *user)
{
    u8 index = ScriptVm_ReadU8(vm);
    u32 value = func_0201134C(vm);
    vm->ring[index] = value;
    return 0;
}


/* Script command: ring[dest byte] = ring[source byte]. */
int func_0215930C(ScriptVm *vm)
{
    u8 dest = ScriptVm_ReadU8(vm);
    u8 source = ScriptVm_ReadU8(vm);
    vm->ring[dest] = vm->ring[source];
    return 0;
}
