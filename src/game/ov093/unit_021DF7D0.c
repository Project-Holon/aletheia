/*
 * file:     unit_021DF7D0.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_SharpBeakBoostPower, BTL_HANDLER_ITEM_GetPoisonBarbHandlers, BTL_HANDLER_ITEM_PoisonBarbBoostPower, BTL_HANDLER_ITEM_PoisonBarbFlingPoison, BTL_HANDLER_ITEM_GetNeverMeltIceHandlers
 * address:  0x021DF7D0
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   gPoisonBarbHandlers     0x021F170C  data   ov093  a4
 *   gNeverMeltIceHandlers     0x021F15AC  data    a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gPoisonBarbHandlers[];
extern const BtlEventHandler gNeverMeltIceHandlers[];

void BTL_HANDLER_ITEM_SharpBeakBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetPoisonBarbHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_PoisonBarbBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_PoisonBarbFlingPoison(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetNeverMeltIceHandlers(int *handlerCount);

/* Sharp Beak. */
void BTL_HANDLER_ITEM_SharpBeakBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_FLYING);
}

/* Poison Barb: two entries. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetPoisonBarbHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gPoisonBarbHandlers;
}

/* Poison Barb. */
void BTL_HANDLER_ITEM_PoisonBarbBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_POISON);
}

/*
 * Poison Barb, Fling: poison the target. Same shape as the Light Ball
 * version, with the poison condition.
 */
void BTL_HANDLER_ITEM_PoisonBarbFlingPoison(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    flingerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_POISON;
    cmd->sickCont = BTL_CALC_MakeDefaultSickCont(TKS_SICK_POISON);
    func_021C88C8(flow, cmd);
}

/* Never-Melt Ice. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetNeverMeltIceHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gNeverMeltIceHandlers;
}
