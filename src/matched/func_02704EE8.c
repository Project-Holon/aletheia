/*
 * function: func_02704EE8
 * address:  0x02704EE8
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_04004006   0x04004006  data twl
 */

typedef unsigned int u32;

extern u32 DAT_04004006[];

asm void func_02704EE8(void) {
    ldr ip, =DAT_04004006
    ldr r0, =0xfffe
    ldrh r3, [ip]
    sub r2, ip, #2
    sub r1, r0, #1
    and r0, r3, r0
    strh r0, [ip]
    ldrh r0, [r2]
    and r0, r0, r1
    strh r0, [r2]
    bx lr
}
