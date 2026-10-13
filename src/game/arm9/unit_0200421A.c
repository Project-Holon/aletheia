/*
 * file:     unit_0200421A.c
 * function: func_0200421A
 * address:  0x0200421A
 * packet:   pkt_0200421A
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area, `swi 0xb; bx lr` in the BIOS call table */
asm void func_0200421A(void)
{
    swi 0xb
    bx lr
}
