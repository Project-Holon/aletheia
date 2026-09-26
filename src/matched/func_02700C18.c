/*
 * function: func_02700C18
 * address:  0x02700C18
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
 *   func_027007C8  0x027007C8  code twl a2
 *   func_02087988  0x02087988  code twl a2
 *   func_0208799C  0x0208799C  code twl a2
 *   func_027019B4  0x027019B4  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC8[];
extern u32 func_027007C8(void);
extern void func_02087988(void);
extern void func_0208799C(void);
extern u32 func_027019B4(u32, u32, u32);

asm void func_02700C18(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r4, r0
    mov r7, r1
    mov r8, r2
    bl func_027007C8
    mov r6, r0
    cmp r6, #7
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    cmp r4, #1
    cmpne r4, #2
    cmpne r4, #3
    movne r0, #3
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    bl func_02087988
    ldr r5, =data_02732FC8
    ldr r1, [r5]
    cmp r1, #0
    beq @lbl_02700C74
    bl func_0208799C
    mov r0, #6
    cmp r6, #6
    movne r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02700C74:
    mov r6, #1
    str r6, [r5]
    bl func_0208799C
    str r7, [r5, #4]
    mov r7, #0
    str r8, [r5, #0xc]
    mov r0, r7
    mov r1, r6
    and r2, r4, #0xff
    str r6, [r5, #0x2c]
    bl func_027019B4
    cmp r0, #0
    moveq r7, #4
    mov r0, r7
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
