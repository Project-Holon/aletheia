/*
 * function: func_02704F4C
 * address:  0x02704F4C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_0400430c   0x0400430c  data twl
 *   func_02704F9C  0x02704F9C  arm twl
 *   DAT_04004308   0x04004308  data twl
 */

typedef unsigned int u32;

extern u32 DAT_0400430c[];
extern void func_02704F9C(void);
extern u32 DAT_04004308[];

asm void func_02704F4C(u32 a0) {
    stmdb sp!, {r4, lr}
    ldr r1, =DAT_0400430c
    mov r4, r0
@lbl_02704F58:
    ldrh r0, [r1]
    tst r0, #4
    bne @lbl_02704F58
    bl func_02704F9C
    ldr r3, =DAT_04004308
    mov r0, r4, lsl #25
    ldrh r2, [r3]
    ldr r1, =0xfffe
    orr r0, r2, r0, lsr #16
    strh r0, [r3]
    ldrh r0, [r3]
    and r0, r0, r1
    strh r0, [r3]
    ldmfd sp!, {r4, pc}
}
