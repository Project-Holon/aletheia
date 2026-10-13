/*
 * function: HAND_WAZA_SolarBeamHalvePowerInBadWeather
 * address:  0x021E6480
 * packet:   pkt_ov093_021E6480
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_WAZA_SolarBeamHalvePowerInBadWeather(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && (u8)(BTL_SERVER_FLOW_GetEffectiveWeatherThunk(b) + 254) <= 2)
        BTL_EVENT_MultiplyVar(0x31, 2 << 10);
}
