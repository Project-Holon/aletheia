/*
 * function: BTL_SERVER_FLOW_GetChosenSlot
 * address: 0x021BC55C
 * packet: pkt_ov093_021BC55C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Sole overlay blocker of pkt_ov093_021BACAC; byte getter with pool.
 */
typedef unsigned char u8;
u8 BTL_SERVER_FLOW_GetChosenSlot(u8 *p)
{
    return p[0x784];
}
