/*
 * function: func_027038BC
 * address:  0x027038BC
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027026DC  0x027026DC  code twl
 *   func_020862D4  0x020862D4  code twl
 *   func_02703A74  0x02703A74  code twl
 */

typedef unsigned int u32;

extern u32 func_027026DC(void);
extern void func_020862D4(u32, u32);
extern u32 func_02703A74(u32, u32, u32, u32, u32);

asm void func_027038BC(u32 a0) {
    stmdb sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #4
    mov r6, r0
    bl func_027026DC
    ldrh r1, [r6, #2]
    mov r4, r0
    cmp r1, #0
    beq @lbl_027038F0
    cmp r1, #0xb
    addne sp, sp, #4
    ldmnefd sp!, {r3, r4, r5, r6, pc}
    mov r5, #0
    b @lbl_027038F4
@lbl_027038F0:
    mov r5, #1
@lbl_027038F4:
    ldrh r0, [r6, #4]
    add r0, r4, r0, lsl #2
    add r0, r0, #0x2000
    ldr r0, [r0, #0x2d4]
    cmp r0, #0
    beq @lbl_02703930
    mov r0, r6
    mov r1, #0x10
    bl func_020862D4
    ldrh r1, [r6, #4]
    mov r0, r6
    add r1, r4, r1, lsl #2
    add r1, r1, #0x2000
    ldr r1, [r1, #0x2d4]
    blx r1
@lbl_02703930:
    cmp r5, #0
    addne sp, sp, #4
    ldmnefd sp!, {r3, r4, r5, r6, pc}
    ldrh r2, [r6, #4]
    mov r0, #0xa
    mov r1, #3
    str r2, [sp]
    ldr r2, [r6, #0xc]
    mov r3, #0
    bl func_02703A74
    add sp, sp, #4
    ldmfd sp!, {r3, r4, r5, r6, pc}
}
