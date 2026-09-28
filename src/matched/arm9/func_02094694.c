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
 *   g_020A8A78     0x020A8A78  data
 */

typedef unsigned int u32;

extern u32 g_020A8A78;

u32 func_02094694(void)
{
    g_020A8A78 = g_020A8A78 * 0x41C64E6Du + 0x3039u;
    return (g_020A8A78 >> 16) & 0x7FFFu;
}
