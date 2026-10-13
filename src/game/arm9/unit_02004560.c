/*
 * file:     unit_02004560.c
 * function: func_02004560
 * address:  0x02004560
 * packet:   pkt_02004560
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_UncompressHuffmanFromDevice), `swi N; bx lr` in the BIOS call table */

asm void func_02004560(void)
{
    swi 0x13
    bx lr
}
