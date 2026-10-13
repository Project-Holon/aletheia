/*
 * function: BTL_HANDLER_ITEM_DragonFangBoostPower
 * address:  0x021DF8A0
 * packet:   pkt_ov093_021DF8A0
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

void BTL_HANDLER_ITEM_DragonFangBoostPower(int a, int b, int c)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(a, b, c, 15);
}
