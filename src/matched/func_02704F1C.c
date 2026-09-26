/*
 * function: func_02704F1C
 * address:  0x02704F1C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   DAT_04004308   0x04004308  data twl
 */

typedef unsigned int u32;

extern u32 DAT_04004308[];

asm void func_02704F1C(void) {
    ldr r1, =DAT_04004308
    ldrh r0, [r1]
    tst r0, #1
    bxne lr
    ldrh r0, [r1]
    orr r0, r0, #1
    strh r0, [r1]
@lbl_02704F38:
    ldrh r0, [r1, #4]
    tst r0, #4
    bne @lbl_02704F38
    bx lr
}
