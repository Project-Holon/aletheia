/*
 * function: BTL_SERVER_FLOW_ClearSeenPokes
 * address:  0x021C84E8
 * packet:   pkt_ov093_021C84E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Extent 0x021C84E8..0x021C84F4 (8 bytes of code plus one pool word); the
 * handed size 76 also spans the already-matched leaf BTL_SERVER_FLOW_AddSeenPoke.
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

void BTL_SERVER_FLOW_ClearSeenPokes(u8 *p)
{
    p[0x785] = 0;
}
