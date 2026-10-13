/*
 * file:     svc_uncompress_huffman_from_device.c
 * function: SVC_UncompressHuffmanFromDevice
 * address:  0x02004560
 * packet:   pkt_02004560
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_UncompressHuffmanFromDevice, SVC stub in the arm9 secure area (swi 0x13; bx lr) */

asm void SVC_UncompressHuffmanFromDevice(void)
{
    swi 0x13
    bx lr
}
