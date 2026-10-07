/*
 * function: func_02700CEC
 * address:  0x02700CEC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   func_027007C8  0x027007C8  code twl a2
 *   func_02087988  0x02087988  code twl a2
 *   func_0208799C  0x0208799C  code twl a2
 *   func_020870D0  0x020870D0  code twl a2
 *   func_027019B4  0x027019B4  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC8[];
extern u32 data_02733FC8[];
extern u32 func_027007C8(void);
extern void func_02087988(void);
extern void func_0208799C(void);
extern void func_020870D0(void);
extern u32 func_027019B4(u32, u32, u32);

asm void func_02700CEC(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r4, r0
    mov r8, r1
    mov r7, r2
    bl func_027007C8
    mov r6, r0
    cmp r6, #7
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    cmp r4, #0
    cmpne r4, #1
    cmpne r4, #2
    movne r0, #3
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    bl func_02087988
    ldr r5, =data_02732FC8
    ldr r1, [r5]
    cmp r1, #0
    beq @lbl_02700D48
    bl func_0208799C
    mov r0, #6
    cmp r6, #6
    movne r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02700D48:
    mov r6, #1
    str r6, [r5]
    bl func_0208799C
    str r8, [r5, #4]
    str r7, [r5, #0xc]
    cmp r4, #0
    streq r6, [r5, #0x2c]
    ldr r0, =data_02733FC8
    strne r6, [r5, #0x28]
    str r4, [r0, #0x124]
    ldr r1, [r0, #0x1ac]
    cmp r1, #0
    moveq r1, #0
    streq r1, [r0, #0x1a8]
    bl func_020870D0
    ldr r3, =data_02732FC8
    and r2, r4, #0xff
    str r0, [r3, #0x50]
    str r1, [r3, #0x54]
    mov r0, #0x10
    mov r1, #1
    bl func_027019B4
    cmp r0, #0
    movne r0, #0
    moveq r0, #4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
