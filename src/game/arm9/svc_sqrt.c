/*
 * file:     svc_sqrt.c
 * function: SVC_Sqrt
 * address:  0x0200471C
 * packet:   pkt_0200471C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_Sqrt, SVC stub in the arm9 secure area (swi 0xD; bx lr) */

asm void SVC_Sqrt(void)
{
    swi 0xD
    bx lr
}
