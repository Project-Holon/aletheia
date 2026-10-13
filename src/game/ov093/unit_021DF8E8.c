/*
 * file:     unit_021DF8E8.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_RockIncenseBoostPower, BTL_HANDLER_ITEM_GetSeaIncenseHandlers, BTL_HANDLER_ITEM_SeaIncenseBoostPower, BTL_HANDLER_ITEM_GetWaveIncenseHandlers, BTL_HANDLER_ITEM_WaveIncenseBoostPower, BTL_HANDLER_ITEM_GetRoseIncenseHandlers, BTL_HANDLER_ITEM_RoseIncenseBoostPower, BTL_HANDLER_ITEM_BoostMovePowerOfType, BTL_HANDLER_ITEM_GetLustrousOrbHandlers
 * address:  0x021DF8E8
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
 *   gSeaIncenseHandlers     0x021F1544  data   ov093  a4
 *   gWaveIncenseHandlers     0x021F14DC  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 *   gRoseIncenseHandlers     0x021F1414  data    a4
 *   gLustrousOrbHandlers     0x021F141C  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gSeaIncenseHandlers[];
extern const BtlEventHandler gWaveIncenseHandlers[];
extern const BtlEventHandler gRoseIncenseHandlers[];
extern const BtlEventHandler gLustrousOrbHandlers[];

void BTL_HANDLER_ITEM_RockIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetSeaIncenseHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_SeaIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetWaveIncenseHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_WaveIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetRoseIncenseHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_RoseIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_BoostMovePowerOfType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int moveType);
const BtlEventHandler *BTL_HANDLER_ITEM_GetLustrousOrbHandlers(int *handlerCount);

/* Rock Incense. */
void BTL_HANDLER_ITEM_RockIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_ROCK);
}

/* Sea Incense. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetSeaIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSeaIncenseHandlers;
}

/* Sea Incense. */
void BTL_HANDLER_ITEM_SeaIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_WATER);
}

/* Wave Incense. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetWaveIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWaveIncenseHandlers;
}

/* Wave Incense. */
void BTL_HANDLER_ITEM_WaveIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_WATER);
}

/* Rose Incense. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetRoseIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRoseIncenseHandlers;
}

/* Rose Incense. */
void BTL_HANDLER_ITEM_RoseIncenseBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_GRASS);
}

/*
 * Type boost items: when the holder attacks with a move of the given type,
 * scale the move power by the ratio that the item parameter gives.
 */
void BTL_HANDLER_ITEM_BoostMovePowerOfType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int moveType)
{
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (moveType != BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE))
        return;
    BTL_EVENT_MultiplyVar(BTL_EVAR_MOVE_POWER_RATIO, BTL_HANDLER_ITEM_GetBoostRatio(factor));
}

/* Lustrous Orb. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetLustrousOrbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gLustrousOrbHandlers;
}
