/*
 * function: CTRDG_IsExistedAtInit
 * address:  0x02090EF4
 * packet:   pkt_02090EF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void CTRDG_IsExistedAtInit(void)
{
    ldr r1, =0x02FFFC30
    ldr r0, =0x0000FFFF
    ldrh	r1, [r1]
    cmp	r1, r0
    movne	r0, #1
    moveq	r0, #0
    bx	lr
}
