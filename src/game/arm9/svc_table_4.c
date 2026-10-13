/*
 * file:     svc_table_4.c
 * function: func_020041B2
 * address:  0x020041B2
 * packet:   pkt_020041B2
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_WaitIntr), `swi N; bx lr` in the BIOS call table */

asm void func_020041B2(void)
{
    swi 0x4
    bx lr
}
