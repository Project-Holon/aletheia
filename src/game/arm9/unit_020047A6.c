/*
 * file:     unit_020047A6.c
 * function: func_020047A6
 * address:  0x020047A6
 * packet:   pkt_020047A6
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_WaitVBlankIntr), `swi N; bx lr` in the BIOS call table */

asm void func_020047A6(void)
{
    swi 0x5
    bx lr
}
