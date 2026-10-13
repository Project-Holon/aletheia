/*
 * file:     unit_021DF7A0.c
 * function: BTL_HANDLER_ITEM_MetalCoatBoostPower, BTL_HANDLER_ITEM_GetMysticWaterHandlers
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
 *   gMysticWaterHandlers     0x021F1444  data   ov093  a4
 *   BTL_HANDLER_ITEM_BoostMovePowerOfType  0x021DF93C  thumb  ov093
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gMysticWaterHandlers[];

void BTL_HANDLER_ITEM_MetalCoatBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetMysticWaterHandlers(int *handlerCount);

/* Metal Coat. */
void BTL_HANDLER_ITEM_MetalCoatBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_STEEL);
}

/* Mystic Water. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetMysticWaterHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMysticWaterHandlers;
}
