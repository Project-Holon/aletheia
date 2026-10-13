/*
 * file:     unit_021DF840.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_NeverMeltIceBoostPower, BTL_HANDLER_ITEM_GetSpellTagHandlers, BTL_HANDLER_ITEM_SpellTagBoostPower, BTL_HANDLER_ITEM_GetTwistedSpoonHandlers
 * address:  0x021DF840
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
 *   gSpellTagHandlers     0x021F15BC  data   ov093  a4
 *   gTwistedSpoonHandlers     0x021F1484  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gSpellTagHandlers[];
extern const BtlEventHandler gTwistedSpoonHandlers[];

void BTL_HANDLER_ITEM_NeverMeltIceBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetSpellTagHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_SpellTagBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetTwistedSpoonHandlers(int *handlerCount);

/* Never-Melt Ice. */
void BTL_HANDLER_ITEM_NeverMeltIceBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_ICE);
}

/* Spell Tag. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetSpellTagHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSpellTagHandlers;
}

/* Spell Tag. */
void BTL_HANDLER_ITEM_SpellTagBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_GHOST);
}

/* Twisted Spoon. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetTwistedSpoonHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTwistedSpoonHandlers;
}
