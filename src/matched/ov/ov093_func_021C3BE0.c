/*
 * function: BTL_SERVER_FLOW_ProcWeatherChanged
 * address: 0x021C3BE0
 * packet: pkt_ov093_021C3BE0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: Lock scalar word return preserves the complete r0 payload,
 * as in matched caller 021C3810; restore consumes the same word.
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_DispatchWeatherChangedEvent 0x021C7998 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_DispatchWeatherChangedEvent(u8 *, u32);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
void BTL_SERVER_FLOW_ProcWeatherChanged(u8 *p, u32 a)
{
    u32 old;
    int line = 0x2303;
    old = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, line);
    BTL_SERVER_FLOW_DispatchWeatherChangedEvent(p, a);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), old, line + 2);
}
