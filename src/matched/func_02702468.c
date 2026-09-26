/*
 * function: func_02702468
 * address:  0x02702468
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02087988  0x02087988  code twl
 *   func_02090ECC  0x02090ECC  code twl
 *   func_0208799C  0x0208799C  code twl
 *   DAT_027341a0   0x027341a0  data twl
 *   func_02088498  0x02088498  code twl
 *   func_020885EC  0x020885EC  code twl
 *   func_020862B8  0x020862B8  code twl
 *   func_020821C0  0x020821C0  code twl
 *   DAT_027341a4   0x027341a4  data twl
 *   func_020862D4  0x020862D4  code twl
 *   func_027026EC  0x027026EC  code twl
 *   func_02085D94  0x02085D94  code twl
 *   func_02085DBC  0x02085DBC  code twl
 *   func_020885A0  0x020885A0  code twl
 *   func_02702740  0x02702740  code twl
 *   func_02082BCC  0x02082BCC  code twl
 */

typedef unsigned int u32;

extern u32 func_02087988(void);
extern u32 func_02090ECC(void);
extern void func_0208799C(u32);
extern u32 DAT_027341a0[];
extern void func_02088498(void);
extern u32 func_020885EC(u32, u32);
extern void func_020862B8(u32, u32);
extern void func_020821C0(u32, u32, u32, u32, u32);
extern u32 DAT_027341a4[];
extern void func_020862D4(u32, u32);
extern void func_027026EC(void);
extern void func_02085D94(u32, u32, u32);
extern void func_02085DBC(u32, u32, u32);
extern void func_020885A0(u32, u32);
extern void func_02702740(void);
extern void func_02082BCC(u32, u32, u32);

asm void func_02702468(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r9, r0
    mov r5, r1
    mov r4, r2
    bl func_02087988
    mov r7, r0
    bl func_02090ECC
    cmp r0, #0
    bne @lbl_0270249C
    mov r0, r7
    bl func_0208799C
    mov r0, #3
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
@lbl_0270249C:
    ldr r0, =DAT_027341a0
    ldrb r0, [r0]
    cmp r0, #0
    beq @lbl_027024BC
    mov r0, r7
    bl func_0208799C
    mov r0, #3
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
@lbl_027024BC:
    cmp r9, #0
    bne @lbl_027024D4
    mov r0, r7
    bl func_0208799C
    mov r0, #5
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
@lbl_027024D4:
    cmp r4, #3
    bls @lbl_027024EC
    mov r0, r7
    bl func_0208799C
    mov r0, #5
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
@lbl_027024EC:
    tst r9, #0x1f
    beq @lbl_02702504
    mov r0, r7
    bl func_0208799C
    mov r0, #5
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
@lbl_02702504:
    bl func_02088498
    mov r6, #1
    mov r1, r6
    mov r0, #0x16
    bl func_020885EC
    cmp r0, #0
    bne @lbl_02702530
    mov r0, r7
    bl func_0208799C
    mov r0, #4
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
@lbl_02702530:
    mov r0, r9
    mov r1, r5
    bl func_020862B8
    mov r8, #0
    mov r0, r4
    mov r1, r9
    mov r2, r8
    mov r3, r5
    str r6, [sp]
    bl func_020821C0
    ldr r6, =DAT_027341a4
    mov r1, #4
    mov r0, r6
    str r9, [r6]
    bl func_020862D4
    ldr r2, [r6]
    add r0, r2, #0x2e0
    add r1, r0, #0x2000
    add r0, r2, #0x2000
    str r1, [r0, #0x274]
    ldr r0, [r6]
    add r0, r0, #0x2000
    ldr r1, [r0, #0x274]
    add r1, r1, #0x20
    str r1, [r0, #0x278]
    ldr r0, [r6]
    add r0, r0, #0x2000
    ldr r1, [r0, #0x278]
    add r1, r1, #0xc0
    str r1, [r0, #0x27c]
    bl func_027026EC
    ldr r0, [r6]
    mov r2, #0x20
    add r0, r0, #0x2200
    strh r4, [r0, #0x80]
    ldr r1, [r6]
    add r0, r1, #0x2000
    add r1, r1, #0x20
    add r1, r1, #0x2000
    bl func_02085D94
    mov r4, #0x8000
    mov r9, #2
    mov r5, #1
@lbl_027025DC:
    ldr r0, [r6]
    mov r1, r8, lsl #8
    strh r4, [r0, r1]
    ldr r0, [r6]
    mov r1, r9
    add r0, r0, r8, lsl #8
    bl func_020862D4
    ldr r1, [r6]
    mov r2, r5
    add r0, r1, #0x2000
    add r1, r1, r8, lsl #8
    bl func_02085DBC
    add r8, r8, #1
    cmp r8, #0x20
    @lbl_02702614: dcd 0xbafffff0
    ldr r1, =func_02702740
    mov r0, #0x16
    bl func_020885A0
    ldr r6, =DAT_027341a4
    mov r4, #0
    ldr r0, [r6]
    mov r1, r4
    add r0, r0, #0x120
    add r0, r0, #0x2000
    mov r2, #0x154
    bl func_02082BCC
    ldr r0, [r6]
    ldr r1, =DAT_027341a0
    add r0, r0, #0x2000
    strb r5, [r1]
    ldr r0, [r0, #0x278]
    ldr r1, =0x22e0
    strh r5, [r0, #0x24]
    ldr r0, [r6]
    bl func_020862D4
    ldr r0, =0x27341a0
    mov r1, r5
    bl func_020862D4
    mov r0, r7
    bl func_0208799C
    mov r0, r4
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
