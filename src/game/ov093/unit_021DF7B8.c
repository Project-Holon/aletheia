/*
 * file:     unit_021DF7B8.c
 * function: BTL_HANDLER_ITEM_MysticWaterBoostPower, BTL_HANDLER_ITEM_GetSharpBeakHandlers
 * address:  0x021DF7B8
 * packet:   pkt_ov093_021DF7B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gSharpBeakHandlers     0x021F144C  data   ov093  a4
 *   BTL_HANDLER_ITEM_BoostMovePowerOfType  0x021DF93C  thumb  ov093
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gSharpBeakHandlers[];

void BTL_HANDLER_ITEM_MysticWaterBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetSharpBeakHandlers(int *handlerCount);

/* Mystic Water. */
void BTL_HANDLER_ITEM_MysticWaterBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_WATER);
}

/* Sharp Beak. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetSharpBeakHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSharpBeakHandlers;
}
