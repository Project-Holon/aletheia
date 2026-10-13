/*
 * function: BTL_HANDLER_ITEM_PoisonBarbBoostPower
 * address:  0x021DF7E8
 * packet:   pkt_ov093_021DF7E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 *
 * symbols:
 *   BTL_HANDLER_ITEM_BoostMovePowerOfType  0x021DF93C  thumb  ov093
 */

void BTL_HANDLER_ITEM_BoostMovePowerOfType(int, int, int, int);

void BTL_HANDLER_ITEM_PoisonBarbBoostPower(int a, int b, int c)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(a, b, c, 3);
}
