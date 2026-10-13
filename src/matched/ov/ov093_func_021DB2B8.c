/*
 * function: BTL_TOKUSEI_Forecast_ResetFormWhenActive
 * address: 0x021DB2B8
 * packet: pkt_ov093_021DB2B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_TOKUSEI_Forecast_ResetForm 0x021DB318 thumb ov093
 */
extern void BTL_TOKUSEI_Forecast_ResetForm(int, void *, int);

void BTL_TOKUSEI_Forecast_ResetFormWhenActive(int a, void *b, int c, int *d)
{
    if (*d != 0) BTL_TOKUSEI_Forecast_ResetForm(a, b, c);
}
