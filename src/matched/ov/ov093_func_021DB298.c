/*
 * function: HAND_TOKUSEI_Forecast_RefreshWeatherForm
 * address: 0x021DB298
 * packet: pkt_ov093_021DB298
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   HAND_TOKUSEI_Forecast_SetFormForWeather 0x021DB374 thumb ov093
 */
typedef unsigned char  u8;
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern void HAND_TOKUSEI_Forecast_SetFormForWeather(void *,int,unsigned int);

void HAND_TOKUSEI_Forecast_RefreshWeatherForm(int a, void *b, int c, int *d)
{
    if (*d != 0) HAND_TOKUSEI_Forecast_SetFormForWeather(b, c, BTL_SERVER_FLOW_GetEffectiveWeatherThunk(b));
}
