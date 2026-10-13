/*
 * file:     unit_021DF974.c
 * function: BTL_HANDLER_ITEM_LustrousOrbMovePower, BTL_HANDLER_ITEM_GetAdamantOrbHandlers
 * address:  0x021DF974
 * packet:   pkt_ov093_021DF974
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gBtlHandlerItemAdamantOrbHandlers     0x021F157C  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 */
#include "unit_021DF974_types.h"

extern BtlEventHandler gBtlHandlerItemAdamantOrbHandlers[];

/* Lustrous Orb: Palkia's Dragon and Water moves get the item's power ratio. */
void BTL_HANDLER_ITEM_LustrousOrbMovePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) != SPECIES_PALKIA)
        return;
    moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
    if (moveType == POKETYPE_DRAGON || moveType == POKETYPE_WATER)
        BTL_EVENT_MultiplyVar(BTL_EVAR_MOVE_POWER_RATIO, BTL_HANDLER_ITEM_GetBoostRatio(factor));
}

/* Adamant Orb handler table: one handler, move power. */
BtlEventHandler *BTL_HANDLER_ITEM_GetAdamantOrbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemAdamantOrbHandlers;
}
