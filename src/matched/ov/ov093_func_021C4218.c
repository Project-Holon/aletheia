/*
 * function: BTL_SERVER_FLOW_ProcDamageEndEvents
 * address:  0x021C4218
 * packet:   pkt_ov093_021C4218
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchDamageEndEvents  0x021C4268  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_DispatchDamageEndEvents(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_ProcDamageEndEvents(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u32 s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1D74, 9310);
    BTL_SERVER_FLOW_DispatchDamageEndEvents(p, a, b, c, s0, s1, s2, s3);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1D74), s, 9313);
}
