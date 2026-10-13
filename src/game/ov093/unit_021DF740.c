/*
 * file:     unit_021DF740.c
 * function: BTL_HANDLER_ITEM_MiracleSeedBoostPower, BTL_HANDLER_ITEM_GetBlackGlassesHandlers
 * address:  0x021DF740
 * packet:   pkt_ov093_021DF740
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gBlackGlassesHandlers     0x021F13B4  data   ov093  a4
 *   BTL_HANDLER_ITEM_BoostMovePowerOfType  0x021DF93C  thumb  ov093
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gBlackGlassesHandlers[];

void BTL_HANDLER_ITEM_MiracleSeedBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetBlackGlassesHandlers(int *handlerCount);

/* Miracle Seed. */
void BTL_HANDLER_ITEM_MiracleSeedBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_GRASS);
}

/* Black Glasses. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetBlackGlassesHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBlackGlassesHandlers;
}
