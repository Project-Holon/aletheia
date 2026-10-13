/*
 * function: SVC_UncompressRL16FromDevice
 * address:  0x020045CC
 * packet:   pkt_020045CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     2026-10-12 lane HF0: hidden function filed. The star is the
 *           listing extent running over the secure-area data that follows.
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_UncompressRL16FromDevice), `swi N; bx lr` in the BIOS call table */

asm void SVC_UncompressRL16FromDevice(void)
{
    swi 0x15
    bx lr
}
