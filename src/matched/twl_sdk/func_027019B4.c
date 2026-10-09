/*
 * function: func_027019B4
 * address:  0x027019B4
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
 *   func_02087988  0x02087988  arm twl a2
 *   func_0208799C  0x0208799C  arm twl a2
 *   func_02087A04  0x02087A04  arm twl a2
 *   func_02088610  0x02088610  arm twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC8[];
extern void func_02087988(void);
extern void func_0208799C(void);
extern void func_02087A04(u32);
extern int func_02088610(u32, u32, u32);

asm void func_027019B4(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r0, r0, lsl #8
    and r3, r0, #0x7f00
    mov r0, r1, lsl #0x10
    orr r1, r3, #0x2000000
    and r0, r0, #0xff0000
    and r2, r2, #0xff
    orr r0, r1, r0
    orr r5, r2, r0
    bl func_02087988
    ldr r2, [pc, #0x74]
    ldrh r4, [r2]
    orr r1, r4, #0x100
    strh r1, [r2]
    bl func_0208799C
    ands r6, r4, #0x100
    bne @lbl_02701A00
    mov r0, #0x14
    bl func_02087A04
@lbl_02701A00:
    ldr r4, =data_02732FC8
    mov r3, r6, asr #8
    mov r1, r5
    mov r0, #0x15
    mov r2, #0
    str r3, [r4, #0x24]
    bl func_02088610
    cmp r0, #0
    bge @lbl_02701A50
    ldr r0, [r4, #0x24]
    cmp r0, #0
    bne @lbl_02701A48
    bl func_02087988
    ldr r2, [pc, #0x1c]
    ldrh r1, [r2]
    bic r1, r1, #0x100
    strh r1, [r2]
    bl func_0208799C
@lbl_02701A48:
    mov r0, #0
    ldmfd sp!, {r4, r5, r6, pc}
@lbl_02701A50:
    mov r0, #1
    ldmfd sp!, {r4, r5, r6, pc}
    streq r4, [r0], #-4
}
