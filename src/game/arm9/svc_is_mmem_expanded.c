/*
 * file:     svc_is_mmem_expanded.c
 * function: SVC_IsMmemExpanded
 * address:  0x02004278
 * packet:   pkt_02004278
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_IsMmemExpanded, SVC stub in the arm9 secure area (swi 0xF; bx lr) */

asm void SVC_IsMmemExpanded(void)
{
    swi 0xF
    bx lr
}
