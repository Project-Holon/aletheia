/*
 * function: func_02034F74
 * address:  0x02034F74
 * packet:   pkt_02034F74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void func_02034F74(void)
{
    ldrb r2, [r0, #0x38]
    orr r1, r2, r1
    strb r1, [r0, #0x38]
    bx lr
}
