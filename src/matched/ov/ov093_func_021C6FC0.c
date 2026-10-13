/*
 * function: BTL_SERVER_FLOW_ProcImmunityOverrideNotice
 * address:  0x021C6FC0
 * packet:   pkt_ov093_021C6FC0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_NotifyImmunityOverrideEvent  0x021C7008  thumb  ov093
 *   BTL_SERVER_FLOW_GetLockState  0x021C88E4  thumb  ov093
 *   BTL_SERVER_FLOW_PushNoEffectMessage  0x021C5750  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_SERVER_FLOW_BeginHandExScope(u8 *p, int line);
extern void BTL_SERVER_FLOW_NotifyImmunityOverrideEvent(u8 *p, u8 *q);
extern int BTL_SERVER_FLOW_GetLockState(u8 *p);
extern void BTL_SERVER_FLOW_PushNoEffectMessage(u8 *p, u8 *q);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_ProcImmunityOverrideNotice(u8 *p, u8 *q)
{
    u32 v = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1D74, 12246);
    BTL_SERVER_FLOW_NotifyImmunityOverrideEvent(p, q);
    if (BTL_SERVER_FLOW_GetLockState(p) != 2) BTL_SERVER_FLOW_PushNoEffectMessage(p, q);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1D74), v, 12253);
}
