/*
 * function: srand
 * address:  0x020946C8
 * packet:   pkt_02094488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MslRandSeed     0x020A8A78  data
 */

typedef unsigned int u32;

extern u32 MslRandSeed;

void srand(u32 v)
{
    MslRandSeed = v;
}
