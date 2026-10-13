/*
 * function: HAND_TOKUSEI_Forecast_ApplyWeatherFormOnEntry
 * address: 0x021DB274
 * packet: pkt_ov093_021DB274
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_TOKUSEI_Forecast_ApplyWeatherForm 0x021DB254 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void HAND_TOKUSEI_Forecast_ApplyWeatherForm(int,void *,int,int *);

void HAND_TOKUSEI_Forecast_ApplyWeatherFormOnEntry(int a, void *b, int c, int *d)
{
    if (c == BTL_EVENT_GetVar(2)) HAND_TOKUSEI_Forecast_ApplyWeatherForm(a, b, c, d);
}
