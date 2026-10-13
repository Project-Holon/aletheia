/*
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

asm void SVC_CpuSet(void)
{
    swi 0xb
    bx lr
}
