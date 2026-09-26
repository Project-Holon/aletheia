/*
 * function: func_02701940
 * address:  0x02701940
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
 *   func_02087988  0x02087988  code twl a2
 *   func_0208799C  0x0208799C  code twl a2
 *   func_027019B4  0x027019B4  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC8[];
extern u32 data_02733FC8[];
extern void func_02087988(void);
extern void func_0208799C(void);
extern u32 func_027019B4(u32, u32, u32);

asm void func_02701940(void) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    mov r7, r1
    mov r6, r2
    bl func_02087988
    ldr r4, =data_02732FC8
    ldr r1, [r4]
    cmp r1, #0
    beq @lbl_02701970
    bl func_0208799C
    mov r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02701970:
    mov r5, #1
    str r5, [r4]
    bl func_0208799C
    str r7, [r4, #4]
    ldr r3, =data_02733FC8
    str r6, [r4, #0xc]
    mov r1, r5
    and r2, r8, #0xff
    mov r0, #0x40
    str r8, [r3, #0x1a8]
    bl func_027019B4
    cmp r0, #0
    movne r0, #0
    moveq r0, #4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
