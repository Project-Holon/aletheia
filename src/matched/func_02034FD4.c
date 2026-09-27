/*
 * function: func_02034FD4
 * address:  0x02034FD4
 * packet:   pkt_02034FD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void func_02034FD4(void)
{
    ldrb r0, [r0, #0x38]
    tst r0, r1
    movne r0, #1
    moveq r0, #0
    bx lr
}
