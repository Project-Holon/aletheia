/*
 * function: func_02701FE8
 * address:  0x02701FE8
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC8[];

asm void func_02701FE8(void) {
    stmdb sp!, {r3, lr}
    ldr r1, =data_02732FC8
    ldr r2, [r1]
    cmp r2, #0
    movne r2, #0
    strne r2, [r1]
    ldr r1, =data_02732FC8
    ldr r3, [r1, #4]
    cmp r3, #0
    ldmeqfd sp!, {r3, pc}
    mov r2, #0
    str r2, [r1, #4]
    ldr r1, [r1, #0xC]
    blx r3
    ldmfd sp!, {r3, pc}
}
