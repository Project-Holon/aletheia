/*
 * function: func_027001F0
 * address:  0x027001F0
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
 *   data_02733FC8  0x02733FC8  data twl a2
 *   data_0273417C  0x0273417C  data twl a2
 *   func_02085DBC  0x02085DBC  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC8[];
extern u32 data_02733FC8[];
extern u32 data_0273417C[];
extern void func_02085DBC(u32*, u32, u32);

asm void func_027001F0(void) {
    stmdb sp!, {r3, lr}
    ldr r0, =data_02732FC8
    mov r1, #1
    ldr r3, =data_02733FC8
    str r1, [r0]
    ldr r0, [r3, #0x1ac]
    mov r1, #0
    add ip, r0, #1
    ldr r0, =data_0273417C
    mov r2, r1
    str ip, [r3, #0x1ac]
    bl func_02085DBC
    ldmfd sp!, {r3, pc}
}
