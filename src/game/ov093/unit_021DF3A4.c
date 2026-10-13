/*
 * file:     unit_021DF3A4.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_SmokeBallShowEscapeMessage, BTL_HANDLER_ITEM_GetAmuletCoinHandlers, BTL_HANDLER_ITEM_AmuletCoinFlagDoublePrizeOnEnter, BTL_HANDLER_ITEM_AmuletCoinFlagDoublePrizeOnEnterDone, BTL_HANDLER_ITEM_GetGriseousOrbHandlers, BTL_HANDLER_ITEM_GriseousOrbBoostDragonGhostPower, BTL_HANDLER_ITEM_GetIcyRockHandlers
 * address:  0x021DF3A4
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
 *   BTLV_CORE_EventTrySetFlagIfAttacker  0x021E889C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C888C  0x021C888C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8408  0x021C8408  thumb  ov093
 *   gAmuletCoinHandlers     0x021F161C  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gGriseousOrbHandlers     0x021F1534  data   ov093  a4
 *   gIcyRockHandlers     0x021F145C  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gAmuletCoinHandlers[];
extern const BtlEventHandler gGriseousOrbHandlers[];
extern const BtlEventHandler gIcyRockHandlers[];

void BTL_HANDLER_ITEM_SmokeBallShowEscapeMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetAmuletCoinHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_AmuletCoinFlagDoublePrizeOnEnter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_AmuletCoinFlagDoublePrizeOnEnterDone(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetGriseousOrbHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_GriseousOrbBoostDragonGhostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetIcyRockHandlers(int *handlerCount);

/* Smoke Ball (guess): after the escape check passes, show the escape message with its sound. */
void BTL_HANDLER_ITEM_SmokeBallShowEscapeMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    TokuseiMessageCmd *msg;

    if (BTLV_CORE_EventTrySetFlagIfAttacker(factor, flow, pokeId) != 0) {
        msg = (TokuseiMessageCmd *)func_021C88A4(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        func_021C8838(&msg->strParam, BTL_STR_TYPE_STANDARD, 0x3ec);
        func_021C8860(&msg->strParam, pokeId);
        func_021C8860(&msg->strParam, BTL_EVENT_GetFactorKey(factor));
        func_021C888C(&msg->strParam, 0x56a);
        func_021C88C8(flow, msg);
    }
}

/* Amulet Coin and Luck Incense: two entries. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetAmuletCoinHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gAmuletCoinHandlers;
}

/* Amulet Coin: when the holder enters, flag the prize money as doubled. */
void BTL_HANDLER_ITEM_AmuletCoinFlagDoublePrizeOnEnter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        func_021C8408(flow, pokeId);
}

/*
 * Amulet Coin: the same flag again at the second enter event, without the
 * holder check.
 */
void BTL_HANDLER_ITEM_AmuletCoinFlagDoublePrizeOnEnterDone(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021C8408(flow, pokeId);
}

const BtlEventHandler *BTL_HANDLER_ITEM_GetGriseousOrbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gGriseousOrbHandlers;
}

/* Griseous Orb: 1.2 times power for Dragon and Ghost moves of a Giratina. */
void BTL_HANDLER_ITEM_GriseousOrbBoostDragonGhostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) != BTL_SPECIES_GIRATINA)
        return;
    moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
    if (moveType == BTL_TYPE_DRAGON || moveType == BTL_TYPE_GHOST)
        BTL_EVENT_MultiplyVar(BTL_EVAR_MOVE_POWER_RATIO, 0x1333);
}

const BtlEventHandler *BTL_HANDLER_ITEM_GetIcyRockHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gIcyRockHandlers;
}
