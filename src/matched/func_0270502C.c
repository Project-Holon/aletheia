/*
 * function: func_0270502C
 * address:  0x0270502C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02704FE4  0x02704FE4  code twl
 */

typedef unsigned int u32;

extern u32 func_02704FE4(u32);

asm void func_0270502C(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r1
@lbl_02705038:
    mov r0, r5
    bl func_02704FE4
    cmp r0, #0
    beq @lbl_02705038
    mov r0, r5, lsl #3
    add r0, r0, #0x4000000
    add r0, r0, #0x4300
    strh r4, [r0, #0x20]
    ldmfd sp!, {r3, r4, r5, pc}
}
