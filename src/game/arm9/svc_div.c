/*
 * file:     svc_div.c
 * function: SVC_Div
 * address:  0x020042E2
 * packet:   pkt_020042E2
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_Div, SVC stub in the arm9 secure area (swi 0x9; bx lr) */

asm void SVC_Div(void)
{
    swi 0x9
    bx lr
}
