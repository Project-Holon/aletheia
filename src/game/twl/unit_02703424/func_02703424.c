/*
 * function: func_02703424
 * address:  0x02703424
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027028E4  0x027028E4  code twl
 *   func_027026DC  0x027026DC  code twl
 *   func_020862B8  0x020862B8  code twl
 *   func_02703A34  0x02703A34  code twl
 *   func_02703A74  0x02703A74  code twl
 */

typedef unsigned int u32;

extern u32 func_027028E4(u32, u32);
extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
extern void func_02703A34(u32, u32);
extern u32 func_02703A74(u32, u32);

asm void func_02703424(u32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r4, r0
    mov r0, #1
    mov r1, #4
    bl func_027028E4
    cmp r0, #0
    beq @lbl_02703448
    cmp r0, #2
    ldmnefd sp!, {r4, r5, r6, pc}
@lbl_02703448:
    bl func_027026DC
    movs r5, r0
    beq @lbl_02703484
    add r0, r5, #0x2000
    ldr r0, [r0, #0x278]
    mov r6, #1
    mov r1, r6
    add r0, r0, #9
    bl func_020862B8
    add r0, r5, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #9]
    cmp r0, #1
    movne r6, #0
    b @lbl_02703488
@lbl_02703484:
    mov r6, #0
@lbl_02703488:
    cmp r6, #1
    moveq r0, #3
    ldmeqfd sp!, {r4, r5, r6, pc}
    mov r5, #9
    mov r0, r5
    mov r1, r4
    bl func_02703A34
    mov r0, r5
    mov r1, #0
    bl func_02703A74
    cmp r0, #0
    cmpne r0, #2
    moveq r0, #2
    ldmfd sp!, {r4, r5, r6, pc}
}
