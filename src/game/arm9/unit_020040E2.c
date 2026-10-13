/*
 * file:     unit_020040E2.c
 * function: func_020040E2
 * address:  0x020040E2
 * packet:   pkt_020040E2
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_Halt), `swi N; bx lr` in the BIOS call table */

asm void func_020040E2(void)
{
    swi 0x6
    bx lr
}
