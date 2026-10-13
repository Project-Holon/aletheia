/*
 * function: HAND_WAZA_PursuitDoublePowerOnIntercept
 * address:  0x021E1D9C
 * packet:   pkt_ov093_021E1D9C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_TestStateFlagBit0  0x021C830C  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern unsigned int BTL_SERVER_FLOW_TestStateFlagBit0(u8 *p);
extern void BTLV_CORE_EventScaleDamage(int a);

void HAND_WAZA_PursuitDoublePowerOnIntercept(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_SERVER_FLOW_TestStateFlagBit0(a) != 0)
            BTLV_CORE_EventScaleDamage(2);
    }
}
