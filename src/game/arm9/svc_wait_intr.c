/*
 * file:     svc_wait_intr.c
 * function: SVC_WaitIntr
 * address:  0x020041B2
 * packet:   pkt_020041B2
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_WaitIntr, SVC stub in the arm9 secure area (swi 0x4; bx lr) */

asm void SVC_WaitIntr(void)
{
    swi 0x4
    bx lr
}
