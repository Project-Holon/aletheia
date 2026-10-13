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
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_NotifyImmunityOverrideEvent  0x021C7008  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   BTL_SERVER_FLOW_PushNoEffectMessage  0x021C5750  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021CC8D8(u8 *p, int line);
extern void BTL_SERVER_FLOW_NotifyImmunityOverrideEvent(u8 *p, u8 *q);
extern int func_021C88E4(u8 *p);
extern void BTL_SERVER_FLOW_PushNoEffectMessage(u8 *p, u8 *q);
extern void func_021CC95C(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_ProcImmunityOverrideNotice(u8 *p, u8 *q)
{
    u32 v = func_021CC8D8(p + 0x1D74, 12246);
    BTL_SERVER_FLOW_NotifyImmunityOverrideEvent(p, q);
    if (func_021C88E4(p) != 2) BTL_SERVER_FLOW_PushNoEffectMessage(p, q);
    func_021CC95C((u32 *)(p + 0x1D74), v, 12253);
}
