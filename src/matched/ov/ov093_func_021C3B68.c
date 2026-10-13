/*
 * function: BTL_SERVER_FLOW_TryChangeWeather
 * address: 0x021C3B68
 * packet: pkt_ov093_021C3B68
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_FLOW_CanChangeWeather 0x021C3B8C thumb ov093
 *   BTL_SERVER_FLOW_ApplyWeatherChange 0x021C3BB8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_SERVER_FLOW_CanChangeWeather(void *, u32, u32);
extern void BTL_SERVER_FLOW_ApplyWeatherChange(u8 *p, u32 a, u32 b);
int BTL_SERVER_FLOW_TryChangeWeather(u8 *p, int a, u8 b)
{
    if (BTL_SERVER_FLOW_CanChangeWeather(p, a, b)) {
        BTL_SERVER_FLOW_ApplyWeatherChange(p, a, b);
        return 1;
    }
    return 0;
}
