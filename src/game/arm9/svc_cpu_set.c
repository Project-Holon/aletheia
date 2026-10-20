/*
 * file:     svc_cpu_set.c
 * function: SVC_CpuSet
 * address:  0x0200421A
 * packet:   pkt_0200421A
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

#include "../types.h"

/* hand-written in the original: SVC_CpuSet, SVC stub in the arm9 secure area (swi 0xb; bx lr) */
asm void SVC_CpuSet(const void *srcp, void *destp, u32 cpuSetParam)
{
    swi 0xb
    bx lr
}
