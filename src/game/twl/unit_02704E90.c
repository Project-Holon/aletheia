/*
 * file:     unit_02704E90.c
 * unit:     yes
 * function: func_02704E90, func_02704EE8, func_02704F1C, func_02704F4C, func_02704F9C, func_02704FE4, func_02705008, func_0270502C, func_0270505C, func_02705088, func_02705150
 * address:  0x02704E90
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DAT_04004006   0x04004006  data twl
 *   func_02087A04  0x02087A04  code twl
 *   DAT_04004308   0x04004308  data twl
 *   DAT_0400430c   0x0400430c  data twl
 */
typedef unsigned int u32;

extern void func_02087A04(u32);
asm void func_02704E90(void);
asm void func_02704EE8(void);
asm void func_02704F1C(void);
asm void func_02704F4C(u32 a0);
asm void func_02704F9C(void);
asm void func_02704FE4(u32 a0);
asm void func_02705008(u32 a0);
asm void func_0270502C(u32 a0, u32 a1);
asm void func_0270505C(void);
asm void func_02705088(void);
asm void func_02705150(void);
extern u32 DAT_04004006[];
extern u32 DAT_04004308[];
extern u32 DAT_0400430c[];




asm void func_02704E90(void) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr r4, =DAT_04004006
    ldr r5, =0xfffe
    ldrh r0, [r4]
    sub r3, r4, #2
    sub r1, r5, #1
    and r0, r0, r5
    strh r0, [r4]
    ldrh r2, [r3]
    mov r0, #2
    and r1, r2, r1
    orr r1, r1, #2
    strh r1, [r3]
    bl func_02087A04
    ldrh r0, [r4]
    and r0, r0, r5
    orr r0, r0, #1
    strh r0, [r4]
    bl func_02704F1C
    ldmfd sp!, {r3, r4, r5, pc}
}




asm void func_02704EE8(void) {
    ldr ip, =DAT_04004006
    ldr r0, =0xfffe
    ldrh r3, [ip]
    sub r2, ip, #2
    sub r1, r0, #1
    and r0, r3, r0
    strh r0, [ip]
    ldrh r0, [r2]
    and r0, r0, r1
    strh r0, [r2]
    bx lr
}




asm void func_02704F1C(void) {
    ldr r1, =DAT_04004308
    ldrh r0, [r1]
    tst r0, #1
    bxne lr
    ldrh r0, [r1]
    orr r0, r0, #1
    strh r0, [r1]
@lbl_02704F38:
    ldrh r0, [r1, #4]
    tst r0, #4
    bne @lbl_02704F38
    bx lr
}




asm void func_02704F4C(u32 a0) {
    stmdb sp!, {r4, lr}
    ldr r1, =DAT_0400430c
    mov r4, r0
@lbl_02704F58:
    ldrh r0, [r1]
    tst r0, #4
    bne @lbl_02704F58
    bl func_02704F9C
    ldr r3, =DAT_04004308
    mov r0, r4, lsl #25
    ldrh r2, [r3]
    ldr r1, =0xfffe
    orr r0, r2, r0, lsr #16
    strh r0, [r3]
    ldrh r0, [r3]
    and r0, r0, r1
    strh r0, [r3]
    ldmfd sp!, {r4, pc}
}




asm void func_02704F9C(void) {
    ldr r3, =DAT_04004308
    ldrh r0, [r3]
    tst r0, #1
    bxeq lr
    ldrh r2, [r3]
    ldr r0, =0xf1ff
    mov r1, #0
    and r2, r2, r0
    strh r2, [r3]
    strh r1, [r3, #8]
    add r0, r0, #0xe00
    strh r0, [r3, #0x10]
    ldrh r0, [r3, #0x1c]
    ldrh r0, [r3, #0x24]
    ldrh r0, [r3, #0x2c]
    bx lr
}




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


asm void func_0270505C(void)
{
}


asm void func_02705088(void)
{
}


asm void func_02705150(void)
{
}
