/*
 * function: SOCLi_RoundUp4
 * address:  0x0215F0C8
 * packet:   pkt_ov009_0215F0C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SOCLi_RoundUp4  0x0215F0C8  arm
*/

typedef unsigned long u32;

u32 SOCLi_RoundUp4(u32 size)
{
    return (size + 3) & ~3;
}
