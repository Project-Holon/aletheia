/*
 * function: func_027044F8
 * address:  0x027044F8
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   DAT_02734450   0x02734450  data twl
 *   func_02087B20  0x02087B20  code twl
 *   func_02704C5C  0x02704C5C  code twl
 *   func_02704D48  0x02704D48  code twl
 *   func_02704BE0  0x02704BE0  code twl
 *   func_02087A04  0x02087A04  code twl
 */

typedef unsigned int u32;

extern u32 DAT_02734450[];
extern u32 func_02087B20(void);
extern u32 func_02704C5C(void);
extern void func_02704D48(u32, u32, u32, u32);
extern u32 func_02704BE0(u32, u32);
extern void func_02087A04(u32);

asm void func_027044F8(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldr r8, =DAT_02734450
    mov r4, r0
    ldr r0, [r8, #4]
    mov r7, r1
    cmp r0, #0
    mov r6, r2
    mov r5, r3
    mov r9, #0
    movne r0, #3
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r0, #1
    str r0, [r8, #4]
    bl func_02087B20
    cmp r0, #0
    streq r9, [r8, #4]
    moveq r0, #4
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    bl func_02704C5C
    cmp r0, #0
    strne r9, [r8, #4]
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r0, r9
    mov r1, r9
    mov r2, r9
    mov r3, #0xc1
    bl func_02704D48
    mov r1, r4, lsl #16
    ldrb r0, [r8, #0x58]
    mov r1, r1, lsr #16
    bl func_02704BE0
    cmp r0, #0
    streq r9, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    ldr r8, =DAT_02734450
    mov r0, r9
    mov r4, #0
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_027045B8
@lbl_027045A4:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_027045A4
@lbl_027045B8:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc2
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_02704614
@lbl_02704600:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_02704600
@lbl_02704614:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc3
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7, #2]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_02704670
@lbl_0270465C:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_0270465C
@lbl_02704670:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc4
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7, #4]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_027046CC
@lbl_027046B8:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_027046B8
@lbl_027046CC:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc5
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7, #6]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x82dc
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_02704728
@lbl_02704714:
    mov r0, r9
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_02704714
@lbl_02704728:
    mov r0, r4
    mov r1, r4
    mov r2, r4
    mov r3, #0xc6
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    ldrh r1, [r7, #8]
    bl func_02704BE0
    cmp r0, #0
    streq r4, [r8, #4]
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r7, =0x82dc
    mov r0, r7
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    beq @lbl_02704784
@lbl_02704770:
    mov r0, r7
    bl func_02087A04
    bl func_02704C5C
    cmp r0, #0
    bne @lbl_02704770
@lbl_02704784:
    mov r0, r6
    mov r1, r5
    mov r2, r4
    mov r3, #0xc7
    bl func_02704D48
    ldrb r0, [r8, #0x58]
    mov r1, r4
    bl func_02704BE0
    cmp r0, #0
    moveq r0, #5
    streq r4, [r8, #4]
    movne r0, r4
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
