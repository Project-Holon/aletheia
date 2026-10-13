/*
 * file:     svc_cpu_set_fast.c
 * function: SVC_CpuFastSet
 * address:  0x02004136
 * packet:   pkt_02004136
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_CpuFastSet, SVC stub in the arm9 secure area (swi 0xC; bx lr) */

asm void SVC_CpuFastSet(void)
{
    swi 0xC
    bx lr
}
