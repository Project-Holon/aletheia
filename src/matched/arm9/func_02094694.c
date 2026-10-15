/*
 * function: func_02094694
 * address:  0x02094694
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

u32 func_02094694(void)
{
    MslRandSeed = MslRandSeed * 0x41C64E6Du + 0x3039u;
    return (MslRandSeed >> 16) & 0x7FFFu;
}
