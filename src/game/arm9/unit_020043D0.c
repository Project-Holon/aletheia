/*
 * file:     unit_020043D0.c
 * function: func_020043D0
 * address:  0x020043D0
 * packet:   pkt_020043D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_UnpackBits), `swi N; bx lr` in the BIOS call table */

asm void func_020043D0(void)
{
    swi 0x10
    bx lr
}
