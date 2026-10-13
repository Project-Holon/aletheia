/*
 * file:     unit_021DF9C8.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_AdamantOrbMovePower, BTL_HANDLER_ITEM_GetIronBallHandlers, BTL_HANDLER_ITEM_IronBallSpeedRatio, BTL_HANDLER_ITEM_IronBallGroundCheck, BTL_HANDLER_ITEM_GetFloatStoneHandlers, BTL_HANDLER_ITEM_FloatStoneWeightRatio, BTL_HANDLER_ITEM_GetEvioliteHandlers, BTL_HANDLER_ITEM_EvioliteDefenseRatio, BTL_HANDLER_ITEM_GetRockyHelmetHandlers
 * address:  0x021DF9C8
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   gBtlHandlerItemIronBallHandlers     0x021F166C  data   ov093  a4
 *   gBtlHandlerItemFloatStoneHandlers     0x021F1504  data   ov093  a4
 *   func_021C818C  0x021C818C  thumb  ov093
 *   gBtlHandlerItemEvioliteHandlers     0x021F14FC  data   ov093  a4
 *   gBtlHandlerItemRockyHelmetHandlers     0x021F140C  data   ov093  a4
 */
#include "unit_021DF974_types.h"

extern BtlEventHandler gBtlHandlerItemIronBallHandlers[];
extern BtlEventHandler gBtlHandlerItemFloatStoneHandlers[];
extern BtlEventHandler gBtlHandlerItemEvioliteHandlers[];
extern BtlEventHandler gBtlHandlerItemRockyHelmetHandlers[];

/* Adamant Orb: Dialga's Dragon and Steel moves get the item's power ratio. */
void BTL_HANDLER_ITEM_AdamantOrbMovePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) != SPECIES_DIALGA)
        return;
    moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
    if (moveType == POKETYPE_DRAGON || moveType == POKETYPE_STEEL)
        BTL_EVENT_MultiplyVar(BTL_EVAR_MOVE_POWER_RATIO, BTL_HANDLER_ITEM_GetBoostRatio(factor));
}

/* Iron Ball handler table: speed ratio and ground check. */
BtlEventHandler *BTL_HANDLER_ITEM_GetIronBallHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlHandlerItemIronBallHandlers;
}

/* Iron Ball: halves the speed of the holder. */
void BTL_HANDLER_ITEM_IronBallSpeedRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int keyAndShift = 2; /* the same 2 is the poke id key and the shift of the 0.5 ratio */

    if (pokeId == BTL_EVENT_GetVar(keyAndShift))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, keyAndShift << 10);
}

/* Iron Ball: the holder counts as grounded. */
void BTL_HANDLER_ITEM_IronBallGroundCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

/* Float Stone handler table: weight ratio. */
BtlEventHandler *BTL_HANDLER_ITEM_GetFloatStoneHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemFloatStoneHandlers;
}

/* Float Stone: halves the weight of the holder. */
void BTL_HANDLER_ITEM_FloatStoneWeightRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int keyAndShift = 2; /* the same 2 is the poke id key and the shift of the 0.5 ratio */

    if (pokeId == BTL_EVENT_GetVar(keyAndShift))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, keyAndShift << 10);
}

/* Eviolite handler table: defense ratio. */
BtlEventHandler *BTL_HANDLER_ITEM_GetEvioliteHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemEvioliteHandlers;
}

/* Eviolite: x1.5 defense while the holder can still evolve. */
void BTL_HANDLER_ITEM_EvioliteDefenseRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && func_021C818C(flow, pokeId))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 6 << 10);
}

/* Rocky Helmet handler table: damage reaction. */
BtlEventHandler *BTL_HANDLER_ITEM_GetRockyHelmetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemRockyHelmetHandlers;
}
