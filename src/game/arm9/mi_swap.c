/*
 * file:     mi_swap.c
 * function: MI_SwapWord
 * address:  0x020834B8
 * packet:   pkt_020834B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

/* hand-written in the original: swp instruction */
asm int MI_SwapWord(int data, int *dest)
{
    swp r0, r0, [r1]
    bx lr
}
