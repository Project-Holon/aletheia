/*
 * file:     unit_021DF770.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_BlackBeltBoostPower, BTL_HANDLER_ITEM_GetMagnetHandlers, BTL_HANDLER_ITEM_MagnetBoostPower, BTL_HANDLER_ITEM_GetMetalCoatHandlers
 * address:  0x021DF770
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_HANDLER_ITEM_BoostMovePowerOfType  0x021DF93C  thumb  ov093
 *   gMagnetHandlers     0x021F14C4  data   ov093  a4
 *   gMetalCoatHandlers     0x021F13C4  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gMagnetHandlers[];
extern const BtlEventHandler gMetalCoatHandlers[];

void BTL_HANDLER_ITEM_BlackBeltBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetMagnetHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_MagnetBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetMetalCoatHandlers(int *handlerCount);

/* Black Belt. */
void BTL_HANDLER_ITEM_BlackBeltBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_FIGHTING);
}

/* Magnet. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetMagnetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMagnetHandlers;
}

/* Magnet. */
void BTL_HANDLER_ITEM_MagnetBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_ELECTRIC);
}

/* Metal Coat. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetMetalCoatHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMetalCoatHandlers;
}
