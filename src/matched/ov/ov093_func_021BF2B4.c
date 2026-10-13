/*
 * function: BTL_SERVER_FLOW_NotifyMoveFinished
 * address: 0x021BF2B4
 * packet: pkt_ov093_021BF2B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: The four-byte Lock getter returns its entire original word in
 * r0 (021CC8DA,021CC900); restore 021CC95C stores that word unchanged.
 * Scalar payload follows matched caller 021BCEFC and preserves every bit.
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_DispatchMoveResultEvent 0x021BF2EC thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Lock { u32 a:10, b:9, c:9, d:1, e:1, f:1, g:1; };
extern u32 BTL_SERVER_FLOW_BeginHandExScope(struct Lock *, int);
extern void BTL_SERVER_FLOW_DispatchMoveResultEvent(u8 *, u32, u32, int);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
void BTL_SERVER_FLOW_NotifyMoveFinished(u8 *p, u32 a, u32 b)
{
    int line = 0x1205;
    u32 old = BTL_SERVER_FLOW_BeginHandExScope((struct Lock *)(p + 0x1d74), line);
    BTL_SERVER_FLOW_DispatchMoveResultEvent(p, a, b, 0x27);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), old, line + 2);
}
