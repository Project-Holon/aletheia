/*
 * function: func_02704F9C
 * address:  0x02704F9C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_04004308   0x04004308  data twl
 */

typedef unsigned int u32;

extern u32 DAT_04004308[];

asm void func_02704F9C(void) {
    ldr r3, =DAT_04004308
    ldrh r0, [r3]
    tst r0, #1
    bxeq lr
    ldrh r2, [r3]
    ldr r0, =0xf1ff
    mov r1, #0
    and r2, r2, r0
    strh r2, [r3]
    strh r1, [r3, #8]
    add r0, r0, #0xe00
    strh r0, [r3, #0x10]
    ldrh r0, [r3, #0x1c]
    ldrh r0, [r3, #0x24]
    ldrh r0, [r3, #0x2c]
    bx lr
}
