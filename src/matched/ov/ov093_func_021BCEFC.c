/*
 * function: BTL_SERVER_FLOW_NotifyActionStart
 * address: 0x021BCEFC
 * packet: pkt_ov093_021BCEFC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: BTL_SERVER_FLOW_BeginHandExScope returns its four-byte Lock in r0; use the
 * full-word payload spelling of matched caller BTL_SERVER_FLOW_ProcPreTurnMoveCheck. The entire
 * BTL_SERVER_FLOW_EndHandExScope body is str r1,[r0]; bx lr, retaining every payload bit.
 * Aggregate spelling added eight bytes of frame; paired fixed-flag
 * runs were DIFF (60 bytes) and EXACT (56 bytes). Calls and stores agree.
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_DispatchActionStartEvent 0x021BCF34 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Lock { u32 a:10, b:9, c:9, d:1, e:1, f:1, g:1; };
extern u32 BTL_SERVER_FLOW_BeginHandExScope(struct Lock *, int);
extern void BTL_SERVER_FLOW_DispatchActionStartEvent(u8 *, u8 *, u32);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
void BTL_SERVER_FLOW_NotifyActionStart(u8 *p, u8 *a, u32 k)
{
    int line = 0x854;
    u32 old = BTL_SERVER_FLOW_BeginHandExScope((struct Lock *)(p + 0x1d74), line);
    BTL_SERVER_FLOW_DispatchActionStartEvent(p, a, k);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), old, line + 3);
}
