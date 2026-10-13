/*
 * function: func_02004694
 * address:  0x02004694
 * packet:   pkt_02004694
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     2026-10-12 lane HF0: hidden function filed. The star is the
 *           listing extent running over the secure-area data that follows.
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_UncompressRL8), `swi N; bx lr` in the BIOS call table */

asm void func_02004694(void)
{
    swi 0x14
    bx lr
}
