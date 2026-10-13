/*
 * file:     svc_table_6.c
 * function: func_02004278
 * address:  0x02004278
 * packet:   pkt_02004278
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_IsMmemExpanded), `swi N; bx lr` in the BIOS call table */

asm void func_02004278(void)
{
    swi 0xF
    bx lr
}
