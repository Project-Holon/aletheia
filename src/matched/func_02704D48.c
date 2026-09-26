/*
 * function: func_02704D48
 * address:  0x02704D48
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   DAT_02734450   0x02734450  data twl
 */

typedef unsigned int u32;

extern u32 DAT_02734450[];

asm void func_02704D48(u32 a0, u32 a1, u32 a2, u32 a3) {
    ldr ip, =DAT_02734450
    str r0, [ip, #0x4c]
    str r1, [ip, #0x50]
    str r2, [ip, #0x54]
    strb r3, [ip, #0x58]
    bx lr
}
