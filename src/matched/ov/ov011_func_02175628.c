/*
 * function: INTRUDE_COMM_HasConnectedPeers
 * address: 0x02175628
 * packet: pkt_ov011_02175628
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x02175646 precede existing 02175648 code.
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 */
typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern int GFL_NET_GetNegotiationNum(void);
int INTRUDE_COMM_HasConnectedPeers(void)
{
    if (func_0200FB24() != 0) return 0;
    if (GFL_NET_GetNegotiationNum() > 1) return 1;
    return 0;
}
