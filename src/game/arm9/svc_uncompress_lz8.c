/*
 * file:     svc_uncompress_lz8.c
 * function: SVC_UncompressLZ8
 * address:  0x020044FE
 * packet:   pkt_020044FE
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_UncompressLZ8, SVC stub in the arm9 secure area (swi 0x11; bx lr) */

asm void SVC_UncompressLZ8(void)
{
    swi 0x11
    bx lr
}
