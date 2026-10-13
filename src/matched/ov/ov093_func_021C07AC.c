/*
 * function: BTL_SERVER_FLOW_ReducePPByEvent
 * address: 0x021C07AC
 * packet: pkt_ov093_021C07AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two alignment bytes at 0x021C07D2 precede matched BTL_SERVER_FLOW_QueryMovePPCostEvent.
 * lever: Wide forwarded arguments avoid truncations absent before the first call.
 * symbols:
 *   BTL_SERVER_FLOW_QueryMovePPCostEvent 0x021C07D4 thumb ov093
 *   BTL_SERVER_FLOW_ConsumeMovePP 0x021C0898 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_SERVER_FLOW_QueryMovePPCostEvent(u8 *, u8 *, u32, u32, int);
extern int BTL_SERVER_FLOW_ConsumeMovePP(u8 *, u8 *, u32, u32);
int BTL_SERVER_FLOW_ReducePPByEvent(u8 *p, u8 *a, u32 c, u32 d, int e)
{
    u8 result = BTL_SERVER_FLOW_QueryMovePPCostEvent(p, a, d, c, e);
    return BTL_SERVER_FLOW_ConsumeMovePP(p, a, d, result);
}
