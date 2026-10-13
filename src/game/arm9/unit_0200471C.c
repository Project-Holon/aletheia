/*
 * file:     unit_0200471C.c
 * function: func_0200471C
 * address:  0x0200471C
 * packet:   pkt_0200471C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_Sqrt), `swi N; bx lr` in the BIOS call table */

asm void func_0200471C(void)
{
    swi 0xD
    bx lr
}
