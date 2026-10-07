/*
 * function: func_02701FD8
 * address:  0x02701FD8
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
 */

extern unsigned int data_02732FC8[];

asm void func_02701FD8(void) {
    ldr r1, =data_02732FC8
    str r0, [r1, #8]
    bx lr
}
