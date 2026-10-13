/*
 * function: func_0200407E
 * address:  0x0200407E
 * packet:   pkt_0200407E
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     2026-10-12 lane HF0: hidden function filed. The star is the
 *           listing extent running over the secure-area data that follows.
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_UncompressLZ16FromDevice), `swi N; bx lr` in the BIOS call table */

asm void func_0200407E(void)
{
    swi 0x12
    bx lr
}
