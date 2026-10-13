/*
 * function: func_020044FE
 * address:  0x020044FE
 * packet:   pkt_020044FE
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     2026-10-12 lane HF0: hidden function filed. The star is the
 *           listing extent running over the secure-area data that follows.
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_UncompressLZ8), `swi N; bx lr` in the BIOS call table */

asm void func_020044FE(void)
{
    swi 0x11
    bx lr
}
