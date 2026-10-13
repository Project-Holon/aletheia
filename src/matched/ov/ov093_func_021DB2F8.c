/*
 * function: BTL_TOKUSEI_Forecast_ResetFormOnEvent6A
 * address: 0x021DB2F8
 * packet: pkt_ov093_021DB2F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_TOKUSEI_Forecast_ResetForm 0x021DB318 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_TOKUSEI_Forecast_ResetForm(int,void *,int);

void BTL_TOKUSEI_Forecast_ResetFormOnEvent6A(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2)) BTL_TOKUSEI_Forecast_ResetForm(a, b, c);
}
