/*
 * file:     svc_uncompress_rl16_from_device.c
 * function: SVC_UncompressRL16FromDevice
 * address:  0x020045CC
 * packet:   pkt_020045CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_UncompressRL16FromDevice, SVC stub in the arm9 secure area (swi 0x15; bx lr) */

asm void SVC_UncompressRL16FromDevice(void)
{
    swi 0x15
    bx lr
}
