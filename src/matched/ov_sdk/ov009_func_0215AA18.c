/*
 * function: get_seqno
 * address:  0x0215AA18
 * packet:   pkt_ov009_0215AA18
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      get_seqno (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   g_021A826C  0x021A826C  data
 */

struct net_vars {
    char pad0[0x78];
    unsigned long long seed;
    unsigned long long mul;
    unsigned long long add;
};

extern struct net_vars g_021A826C;

unsigned long get_seqno(void)
{
    g_021A826C.seed = g_021A826C.mul * g_021A826C.seed + g_021A826C.add;
    return (unsigned long)(g_021A826C.seed >> 32);
}
