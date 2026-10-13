/*
 * function: SVC_UncompressHuffmanFromDevice
 * address:  0x02004560
 * packet:   pkt_02004560
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     2026-10-12 lane HF0: hidden function filed. The star is the
 *           listing extent running over the secure-area data that follows.
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_UncompressHuffmanFromDevice), `swi N; bx lr` in the BIOS call table */

asm void SVC_UncompressHuffmanFromDevice(void)
{
    swi 0x13
    bx lr
}
