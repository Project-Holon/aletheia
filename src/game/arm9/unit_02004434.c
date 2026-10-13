/*
 * file:     unit_02004434.c
 * function: func_02004434
 * address:  0x02004434
 * packet:   pkt_02004434
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_SoftReset), `swi N; bx lr` in the BIOS call table */

asm void func_02004434(void)
{
    swi 0x0
    bx lr
}
