/*
 * file:     svc_uncompress_lz16_from_device.c
 * function: SVC_UncompressLZ16FromDevice
 * address:  0x0200407E
 * packet:   pkt_0200407E
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_UncompressLZ16FromDevice, SVC stub in the arm9 secure area (swi 0x12; bx lr) */

asm void SVC_UncompressLZ16FromDevice(void)
{
    swi 0x12
    bx lr
}
