/*
 * function: HAND_ITEM_MetalCoatBoostPower
 * address:  0x021DF7A0
 * packet:   pkt_ov093_021DF7A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_BoostMovePowerOfType  0x021DF93C  thumb  ov093
 */

void HAND_ITEM_BoostMovePowerOfType(int, int, int, int);

void HAND_ITEM_MetalCoatBoostPower(int a, int b, int c)
{
    HAND_ITEM_BoostMovePowerOfType(a, b, c, 8);
}
