/*
 * file:     unit_02704E90_p02.c
 * unit:     yes
 * function: func_02704FE4, func_02705008, func_0270502C
 * address:  0x02704FE4
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DAT_0400430c   0x0400430c  data twl
 */
typedef unsigned int u32;

asm void func_02704FE4(u32 a0);
asm void func_02705008(u32 a0);
asm void func_0270502C(u32 a0, u32 a1);
extern u32 DAT_0400430c[];


asm void func_02704FE4(u32 a0) {
    ldr r1, =DAT_0400430c
    mov r2, #1
    ldrh r1, [r1]
    mov r0, r2, lsl r0
    tst r1, r0, lsl #13
    movne r2, #0
    mov r0, r2
    bx lr
}


asm void func_02705008(u32 a0) {
    ldr r1, =DAT_0400430c
    mov r2, #1
    ldrh r1, [r1]
    mov r0, r2, lsl r0
    tst r1, r0, lsl #10
    moveq r2, #0
    mov r0, r2
    bx lr
}


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
