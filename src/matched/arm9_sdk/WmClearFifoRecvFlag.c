/*
 * function: WmClearFifoRecvFlag
 * address:  0x0208E9A4
 * packet:   pkt_0208E9A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void WmClearFifoRecvFlag(void)
{
    ldr r2, =0x02FFFF96
    ldrh r1, [r2]
    tst r1, #1
    ldrne r0, =0x0000FFFE
    andne r0, r1, r0
    strneh r0, [r2]
    bx lr
}
