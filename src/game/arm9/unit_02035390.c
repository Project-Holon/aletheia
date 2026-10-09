/*
 * file:     unit_02035390.c
 * function: DWCi_IsFold
 * address:  0x02035390
 * packet:   pkt_02035390
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void DWCi_IsFold(void)
{
    ldr r0, =0x02FFFFA8
    ldrh r0, [r0]
    and r0, r0, #0x8000
    movs r0, r0, asr #15
    movne r0, #1
    moveq r0, #0
    bx lr
}
