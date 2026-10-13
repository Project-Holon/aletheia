/*
 * function: BTL_HANDLER_ITEM_SoftSandBoostPower
 * address:  0x021DF710
 * packet:   pkt_ov093_021DF710
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_HANDLER_ITEM_BoostMovePowerOfType  0x021DF93C  thumb  ov093
 */

void BTL_HANDLER_ITEM_BoostMovePowerOfType(int, int, int, int);

void BTL_HANDLER_ITEM_SoftSandBoostPower(int a, int b, int c)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(a, b, c, 4);
}
