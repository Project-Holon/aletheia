/*
 * function: BTL_SERVER_FLOW_NotifyMoveStart
 * address:  0x021BE924
 * packet:   pkt_ov093_021BE924
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchMoveStartEvent  0x021BE95C  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_DispatchMoveStartEvent(u8 *p, u8 *a, u32 v);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_NotifyMoveStart(u8 *p, u8 *a, u32 v)
{
    u32 s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1D74, 3985);
    BTL_SERVER_FLOW_DispatchMoveStartEvent(p, a, v);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1D74), s, 3987);
}
