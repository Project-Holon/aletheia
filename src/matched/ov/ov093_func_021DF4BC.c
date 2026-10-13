/*
 * function: BTL_HANDLER_ITEM_HeatRockExtendSunshine
 * address:  0x021DF4BC
 * packet:   pkt_ov093_021DF4BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BTL_HANDLER_ITEM_ExtendWeatherTurns  0x021DF4E0  thumb  ov093
 */
extern void BTL_HANDLER_ITEM_ExtendWeatherTurns(void *, int, int, int);
void BTL_HANDLER_ITEM_HeatRockExtendSunshine(void *a, int b, int c)
{
    BTL_HANDLER_ITEM_ExtendWeatherTurns(a, b, c, 1);
}
