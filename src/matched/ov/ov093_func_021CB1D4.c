/*
 * function: BTL_SERVER_FLOW_ProcTargetChange
 * address:  0x021CB1D4
 * packet:   pkt_ov093_021CB1D4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_QueryTargetChangeEvent  0x021CB274  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern u8 BTL_SERVER_FLOW_QueryTargetChangeEvent(u8 *p, u8 *a, u8 *b, u32 d);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

u8 BTL_SERVER_FLOW_ProcTargetChange(u8 *p, u8 *a, u8 *b, u32 d)
{
    u32 s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1D74, 611);
    u8 r = BTL_SERVER_FLOW_QueryTargetChangeEvent(p, a, b, d);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1D74), s, 613);
    return r;
}
