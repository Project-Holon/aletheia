/*
 * file:     svc_uncompress_rl8.c
 * function: SVC_UncompressRL8
 * address:  0x02004694
 * packet:   pkt_02004694
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_UncompressRL8, SVC stub in the arm9 secure area (swi 0x14; bx lr) */

asm void SVC_UncompressRL8(void)
{
    swi 0x14
    bx lr
}
