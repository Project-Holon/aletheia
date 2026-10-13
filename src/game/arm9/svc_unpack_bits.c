/*
 * file:     svc_unpack_bits.c
 * function: SVC_UnpackBits
 * address:  0x020043D0
 * packet:   pkt_020043D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_UnpackBits, SVC stub in the arm9 secure area (swi 0x10; bx lr) */

asm void SVC_UnpackBits(void)
{
    swi 0x10
    bx lr
}
