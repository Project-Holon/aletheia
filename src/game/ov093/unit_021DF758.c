/*
 * file:     unit_021DF758.c
 * function: BTL_HANDLER_ITEM_BlackGlassesBoostPower, BTL_HANDLER_ITEM_GetBlackBeltHandlers
 * address:  0x021DF758
 * packet:   pkt_ov093_021DF758
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gBlackBeltHandlers     0x021F142C  data   ov093  a4
 *   BTL_HANDLER_ITEM_BoostMovePowerOfType  0x021DF93C  thumb  ov093
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gBlackBeltHandlers[];

void BTL_HANDLER_ITEM_BlackGlassesBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetBlackBeltHandlers(int *handlerCount);

/* Black Glasses: 1.2 times power for Dark moves of the holder. */
void BTL_HANDLER_ITEM_BlackGlassesBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_DARK);
}

/* Black Belt. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetBlackBeltHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBlackBeltHandlers;
}
