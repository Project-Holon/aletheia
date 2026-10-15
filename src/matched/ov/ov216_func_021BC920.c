/*
 * function: BEACON_DETAIL_GRA_IsPmsActive
 * address:  0x021BC920
 * packet:   pkt_021BC920
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call getter: loads p[0x56] and tail-calls sub_0202DBC4.
 *
 * symbols:
 *   sub_0202DBC4  0x0202DBC4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int sub_0202DBC4(u32);

int BEACON_DETAIL_GRA_IsPmsActive(u32 *p)
{
    return sub_0202DBC4(p[0x56]);
}
