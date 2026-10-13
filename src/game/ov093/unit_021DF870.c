/*
 * file:     unit_021DF870.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_TwistedSpoonBoostPower, BTL_HANDLER_ITEM_GetCharcoalHandlers, BTL_HANDLER_ITEM_CharcoalBoostPower, BTL_HANDLER_ITEM_GetDragonFangHandlers, BTL_HANDLER_ITEM_DragonFangBoostPower, BTL_HANDLER_ITEM_GetSilkScarfHandlers, BTL_HANDLER_ITEM_SilkScarfBoostPower, BTL_HANDLER_ITEM_GetOddIncenseHandlers, BTL_HANDLER_ITEM_OddIncenseBoostPower, BTL_HANDLER_ITEM_GetRockIncenseHandlers
 * address:  0x021DF870
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
 *   gCharcoalHandlers     0x021F15E4  data   ov093  a4
 *   gDragonFangHandlers     0x021F15DC  data   ov093  a4
 *   gSilkScarfHandlers     0x021F159C  data   ov093  a4
 *   gOddIncenseHandlers     0x021F155C  data   ov093  a4
 *   gRockIncenseHandlers     0x021F1404  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gCharcoalHandlers[];
extern const BtlEventHandler gDragonFangHandlers[];
extern const BtlEventHandler gSilkScarfHandlers[];
extern const BtlEventHandler gOddIncenseHandlers[];
extern const BtlEventHandler gRockIncenseHandlers[];

void BTL_HANDLER_ITEM_TwistedSpoonBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetCharcoalHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_CharcoalBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetDragonFangHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_DragonFangBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetSilkScarfHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_SilkScarfBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetOddIncenseHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_OddIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetRockIncenseHandlers(int *handlerCount);

/* Twisted Spoon. */
void BTL_HANDLER_ITEM_TwistedSpoonBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_PSYCHIC);
}

/* Charcoal. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetCharcoalHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gCharcoalHandlers;
}

/* Charcoal. */
void BTL_HANDLER_ITEM_CharcoalBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_FIRE);
}

/* Dragon Fang. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetDragonFangHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gDragonFangHandlers;
}

/* Dragon Fang. */
void BTL_HANDLER_ITEM_DragonFangBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_DRAGON);
}

/* Silk Scarf. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetSilkScarfHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSilkScarfHandlers;
}

/* Silk Scarf. */
void BTL_HANDLER_ITEM_SilkScarfBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_NORMAL);
}

/* Odd Incense. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetOddIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gOddIncenseHandlers;
}

/* Odd Incense. */
void BTL_HANDLER_ITEM_OddIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_PSYCHIC);
}

/* Rock Incense. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetRockIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRockIncenseHandlers;
}
