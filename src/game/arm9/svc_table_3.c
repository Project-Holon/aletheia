/*
 * file:     svc_table_3.c
 * function: func_02004136
 * address:  0x02004136
 * packet:   pkt_02004136
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC stub in the arm9 secure area (SVC_CpuSetFast), `swi N; bx lr` in the BIOS call table */

asm void func_02004136(void)
{
    swi 0xC
    bx lr
}
