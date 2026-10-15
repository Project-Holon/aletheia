/*
 * function: OSi_CountLeadingZeros
 * address:  0x02087EA0
 * packet:   pkt_02087EA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm int OSi_CountLeadingZeros(unsigned int x)
{
    clz r0, r0
    bx lr
}
