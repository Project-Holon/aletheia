/*
 * function: func_02078530
 * address:  0x02078530
 * packet:   pkt_02078530
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
*/

asm void func_02078530(void)
{
    ldrsb	r1, [r0, #3]
    cmp	r1, #0
    ldrne	r0, [r0]
    bx	lr
}
