/*
 * function: func_020043D0
 * address:  0x020043D0
 * packet:   pkt_020043D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     2026-10-12 lane HF0: hidden function filed. The star is the
 *           listing extent running over the secure-area data that follows.
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_UnpackBits), `swi N; bx lr` in the BIOS call table */

asm void func_020043D0(void)
{
    swi 0x10
    bx lr
}
