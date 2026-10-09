/*
 * function: func_02703960
 * address:  0x02703960
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027028E4  0x027028E4  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   func_02703A34  0x02703A34  arm twl
 *   func_02082D44  0x02082D44  arm twl
 *   func_02703B24  0x02703B24  arm twl
 */

typedef unsigned int u32;

extern u32 func_027028E4(u32, u32);
extern void func_020862D4(u32, u32);
extern void func_02703A34(u32, u32);
extern void func_02082D44(u32, u32, u32);
extern u32 func_02703B24(u32, u32);

asm void func_02703960(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x24
    mov r6, r0
    mov r5, r1
    mov r0, #1
    mov r1, #3
    bl func_027028E4
    cmp r0, #0
    beq @lbl_02703990
    cmp r0, #2
    addne sp, sp, #0x24
    ldmnefd sp!, {r3, r4, r5, r6, pc}
@lbl_02703990:
    cmp r5, #0
    addeq sp, sp, #0x24
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, pc}
    mov r0, r5
    mov r1, #0x22
    bl func_020862D4
    ldrh r0, [r5]
    cmp r0, #7
    addls pc, pc, r0, lsl #2
    b @lbl_027039DC
    b @lbl_027039DC
    b @lbl_027039DC
    b @lbl_027039DC
    b @lbl_027039DC
    b @lbl_027039E8
    b @lbl_027039E8
    b @lbl_027039E8
    b @lbl_027039E8
@lbl_027039DC:
    add sp, sp, #0x24
    mov r0, #5
    ldmfd sp!, {r3, r4, r5, r6, pc}
@lbl_027039E8:
    mov r4, #0x12
    mov r0, r4
    mov r1, r6
    bl func_02703A34
    strh r4, [sp]
    ldrh r3, [r5]
    add r1, sp, #4
    add r0, r5, #2
    mov r2, #0x20
    strh r3, [sp, #2]
    bl func_02082D44
    add r0, sp, #0
    mov r1, #0x24
    bl func_02703B24
    cmp r0, #0
    cmpne r0, #2
    moveq r0, #2
    add sp, sp, #0x24
    ldmfd sp!, {r3, r4, r5, r6, pc}
}
