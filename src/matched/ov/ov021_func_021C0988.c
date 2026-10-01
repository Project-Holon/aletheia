/*
 * function: func_021C0988
 * address:  0x021C0988
 * packet:   pkt_ov021_021C0988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases each of the p[0x14] handles (EXACT*: unlabelled follower at 0x021C09A8).
 *
 * symbols:
 *   func_0218C860  0x0218C860  thumb  ov021
 */

typedef unsigned char u8;

extern void func_0218C860(int);

void func_021C0988(u8 *p)
{
    int i;

    for (i = 0; i < p[0x14]; i++)
        func_0218C860(((int *)(p + 0x1C))[i]);
}
