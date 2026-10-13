/*
 * function: HAND_WAZA_ThunderOnHitCheck
 * address:  0x021E30A4
 * packet:   pkt_ov093_021E30A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_ThunderOnHitCheck(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(a) == 2)
            BTL_EVENT_OverwriteVar(0x51, 1);
    }
}
