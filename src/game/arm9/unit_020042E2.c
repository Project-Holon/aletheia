/*
 * file:     unit_020042E2.c
 * function: func_020042E2
 * address:  0x020042E2
 * packet:   pkt_020042E2
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_Div), `swi N; bx lr` in the BIOS call table */

asm void func_020042E2(void)
{
    swi 0x9
    bx lr
}
