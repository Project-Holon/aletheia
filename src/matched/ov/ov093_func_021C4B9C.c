/*
 * function: BTL_SERVER_FLOW_OnSideEffectExpired
 * address: 0x021C4B9C
 * packet: pkt_ov093_021C4B9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Callback adapter passed to the ov095 walker HAND_SIDE_TickTurns by
 * BTL_SERVER_FLOW_ProcSideEffectsExpire: swaps the first and third arguments and tail calls
 * BTL_SERVER_FLOW_PushSideEffectExpireMessage through r3. Filed as a witness for BTL_SERVER_FLOW_ProcSideEffectsExpire.
 *
 * symbols:
 *   BTL_SERVER_FLOW_PushSideEffectExpireMessage 0x021C4BAC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_SERVER_FLOW_PushSideEffectExpireMessage(u8 *p, int k, int v);

void BTL_SERVER_FLOW_OnSideEffectExpired(int v, int k, u8 *p)
{
    BTL_SERVER_FLOW_PushSideEffectExpireMessage(p, k, v);
}
