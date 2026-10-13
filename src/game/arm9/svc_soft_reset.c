/*
 * file:     svc_soft_reset.c
 * function: SVC_SoftReset
 * address:  0x02004434
 * packet:   pkt_02004434
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_SoftReset, SVC stub in the arm9 secure area (swi 0x0; bx lr) */

asm void SVC_SoftReset(void)
{
    swi 0x0
    bx lr
}
