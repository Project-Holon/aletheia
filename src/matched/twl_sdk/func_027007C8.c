/*
 * function: func_027007C8
 * address:  0x027007C8
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02733FC8  0x02733FC8  data twl a2
 *   data_02732FC8  0x02732FC8  data twl a2
 *   func_027019B4  0x027019B4  arm twl a2
 */

typedef unsigned int u32;

extern u32 data_02733FC8[];
extern u32 data_02732FC8[];
extern void func_027019B4(u32, u32, u32);

asm void func_027007C8(void) {
    stmdb sp!, {r3, lr}
    ldr r3, =data_02733FC8
    ldr r0, [r3, #0x1ac]
    cmp r0, #2
    bls @lbl_0270080C
    ldr r0, [r3, #0x124]
    cmp r0, #0
    beq @lbl_02700804
    ldr r0, =data_02732FC8
    mov r1, #1
    str r1, [r0, #0x2c]
    mov r2, #0
    mov r0, #0x10
    str r2, [r3, #0x124]
    bl func_027019B4
@lbl_02700804:
    mov r0, #7
    ldmfd sp!, {r3, pc}
@lbl_0270080C:
    cmp r0, #0
    movne r0, #6
    moveq r0, #0
    ldmfd sp!, {r3, pc}
}
