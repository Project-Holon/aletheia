/*
 * file:     unit_02004632.c
 * function: func_02004632
 * address:  0x02004632
 * packet:   pkt_02004490
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 16: the CCERR of 2026-09-20 no longer reproduces; EXACT* (the
 *           listing extent runs over the data that follows this 4-byte SVC
 *           stub).  A Thumb `asm` function: swi, then return.
 */

/* hand-written in the original: SVC stub in the arm9 secure area, `swi; bx lr` in the BIOS call table */
asm void func_02004632(void)
{
    swi 0xe
    bx lr
}
