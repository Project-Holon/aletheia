/*
 * file:     svc_table_1.c
 * function: func_0200407E
 * address:  0x0200407E
 * packet:   pkt_0200407E
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_UncompressLZ16FromDevice), `swi N; bx lr` in the BIOS call table */

asm void func_0200407E(void)
{
    swi 0x12
    bx lr
}
