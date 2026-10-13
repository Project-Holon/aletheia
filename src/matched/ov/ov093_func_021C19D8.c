/*
 * function: BTL_SERVER_FLOW_RunMoveUsedEventLocked
 * address: 0x021C19D8
 * packet: pkt_ov093_021C19D8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: Complete lock word returned in r0 at 021CC900; restore
 * 021CC95C stores the unchanged full r1 word. Scalar u32 preserves all bits.
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_RunMoveUsedEvent 0x021C1A10 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_RunMoveUsedEvent(u8 *p, u8 *a, u8 *q);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_RunMoveUsedEventLocked(u8 *p, u8 *a, u8 *q)
{
    u32 s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 6874);
    BTL_SERVER_FLOW_RunMoveUsedEvent(p, a, q);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, 6874 + 2);
}
