/*
 * function: BTL_HANDLER_ITEM_IcyRockExtendHail
 * address:  0x021DF48C
 * packet:   pkt_ov093_021DF48C
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
void BTL_HANDLER_ITEM_IcyRockExtendHail(void *a, int b, int c)
{
    BTL_HANDLER_ITEM_ExtendWeatherTurns(a, b, c, 3);
}
