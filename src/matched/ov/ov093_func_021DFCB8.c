/*
 * function: HAND_ITEM_RingTargetImmunityOverride
 * address:  0x021DFCB8
 * packet:   pkt_ov093_021DFCB8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_IsActionCounterSet  0x021C7EC4  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u32 BTL_SERVER_FLOW_IsActionCounterSet(u8 *p);

void HAND_ITEM_RingTargetImmunityOverride(int a, void *b, int c)
{
    if (BTL_SERVER_FLOW_IsActionCounterSet(b) == 0 && c == BTL_EVENT_GetVar(4))
        BTL_EVENT_OverwriteVar(75, 1);
}
