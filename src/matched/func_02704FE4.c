/*
 * function: func_02704FE4
 * address:  0x02704FE4
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   DAT_0400430c   0x0400430c  data twl
 */

typedef unsigned int u32;

extern u32 DAT_0400430c[];

asm void func_02704FE4(u32 a0) {
    ldr r1, =DAT_0400430c
    mov r2, #1
    ldrh r1, [r1]
    mov r0, r2, lsl r0
    tst r1, r0, lsl #13
    movne r2, #0
    mov r0, r2
    bx lr
}
