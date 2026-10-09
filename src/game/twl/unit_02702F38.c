/*
 * file:     unit_02702F38.c
 * function: func_02702F38
 * address:  0x02702F38
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027026B4  0x027026B4  code twl
 *   func_027028E4  0x027028E4  code twl
 *   func_027026DC  0x027026DC  code twl
 *   func_020862B8  0x020862B8  code twl
 *   func_02703A34  0x02703A34  code twl
 *   func_02703A74  0x02703A74  code twl
 */

typedef unsigned int u32;

extern u32 func_027026B4(void);
extern u32 func_027028E4(u32, u32);
extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
extern void func_02703A34(u32, u32);
extern u32 func_02703A74(u32, u32);

asm void func_02702F38(u32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r4, r0
    bl func_027026B4
    cmp r0, #0
    moveq r0, #7
    ldmeqfd sp!, {r4, r5, r6, pc}
    mov r0, #1
    mov r1, #2
    bl func_027028E4
    cmp r0, #0
    beq @lbl_02702F6C
    cmp r0, #2
    ldmnefd sp!, {r4, r5, r6, pc}
@lbl_02702F6C:
    bl func_027026DC
    movs r5, r0
    beq @lbl_02702FA8
    add r0, r5, #0x2000
    ldr r0, [r0, #0x278]
    mov r6, #1
    mov r1, r6
    add r0, r0, #5
    bl func_020862B8
    add r0, r5, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #5]
    cmp r0, #1
    movne r6, #0
    b @lbl_02702FAC
@lbl_02702FA8:
    mov r6, #0
@lbl_02702FAC:
    cmp r6, #1
    moveq r0, #3
    ldmeqfd sp!, {r4, r5, r6, pc}
    mov r5, #5
    mov r0, r5
    mov r1, r4
    bl func_02703A34
    bl func_027026DC
    mov r0, r5
    mov r1, #0
    bl func_02703A74
    cmp r0, #0
    cmpne r0, #2
    moveq r0, #2
    ldmfd sp!, {r4, r5, r6, pc}
}
