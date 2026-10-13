/*
 * file:     unit_021DFABC.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_RockyHelmetDamageReaction, BTL_HANDLER_ITEM_GetAirBalloonHandlers, BTL_HANDLER_ITEM_AirBalloonEnterField, BTL_HANDLER_ITEM_AirBalloonGroundCheck, BTL_HANDLER_ITEM_AirBalloonPop, BTL_HANDLER_ITEM_GetRedCardHandlers, BTL_HANDLER_ITEM_RedCardForceSwitch, BTL_HANDLER_ITEM_GetRingTargetHandlers
 * address:  0x021DFABC
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
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   gBtlHandlerItemAirBalloonHandlers     0x021F1934  data   ov093  a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   gBtlHandlerItemRedCardHandlers     0x021F14CC  data   ov093  a4
 *   gBtlHandlerItemRingTargetHandlers     0x021F14BC  data   ov093  a4
 */
#include "unit_021DF974_types.h"

extern BtlEventHandler gBtlHandlerItemAirBalloonHandlers[];
extern BtlEventHandler gBtlHandlerItemRedCardHandlers[];
extern BtlEventHandler gBtlHandlerItemRingTargetHandlers[];

/* Rocky Helmet: a contact move that hit the holder costs the attacker 1/6 of its max HP. */
void BTL_HANDLER_ITEM_RockyHelmetDamageReaction(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlLoseHpCmd *cmd;
    struct BtlPokeParam *attacker;
    int divisor;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0)
        return;
    if (!WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), 0))
        return;
    cmd = (BtlLoseHpCmd *)func_021C88A4(flow, BTL_CMD_KIND_LOSE_HP, pokeId);
    cmd->pokeId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    attacker = func_021C7CF4(flow, cmd->pokeId);
    divisor = (u8)BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_DAMAGE_DIVISOR);
    cmd->amount = BTL_CALC_DivideMaxHpMin1(attacker, divisor);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 424);
    func_021C8860(&cmd->strParam, cmd->pokeId);
    func_021C88C8(flow, cmd);
}

/* Air Balloon handler table: enter field, ground check, damage reaction. */
BtlEventHandler *BTL_HANDLER_ITEM_GetAirBalloonHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gBtlHandlerItemAirBalloonHandlers;
}

/* Air Balloon: announces the balloon when the holder enters the field, unless a field effect forbids it. */
void BTL_HANDLER_ITEM_AirBalloonEnterField(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (BTL_FIELD_GetStaticSlotObject(BTL_FIELD_EFFECT_GRAVITY_QUERY) != 0)
        return;
    cmd = (BtlMessageCmd *)func_021C88A4(flow, BTL_CMD_KIND_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0x198);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
}

/* Air Balloon: the holder counts as floating. */
void BTL_HANDLER_ITEM_AirBalloonGroundCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

/* Air Balloon: when the holder is hit it loses the item and a message is shown. */
void BTL_HANDLER_ITEM_AirBalloonPop(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlSetItemCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    cmd = (BtlSetItemCmd *)func_021C88A4(flow, BTL_CMD_KIND_SET_ITEM, pokeId);
    cmd->pokeId = pokeId;
    cmd->itemId = 0;
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0x19b);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
}

/* Red Card handler table: damage reaction at the end of the move. */
BtlEventHandler *BTL_HANDLER_ITEM_GetRedCardHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemRedCardHandlers;
}

/* Red Card: after the holder is hit, the attacker is forced out of the field. */
void BTL_HANDLER_ITEM_RedCardForceSwitch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlItemMessageCmd *messageCmd;
    BtlForceSwitchCmd *switchCmd;
    u8 attackerId;

    if (func_021E85F8(pokeId) == 0)
        return;
    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (func_021C7D00(flow, attackerId) == 6)
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_SHEER_FORCE_FLAG) != 0)
        return;
    if (func_021C7F24(flow, attackerId) == 0)
        return;
    if (func_021C83D4(flow) != 0)
        return;
    messageCmd = (BtlItemMessageCmd *)func_021C88A4(flow, BTL_CMD_KIND_ITEM_MESSAGE, pokeId);
    func_021C8838(&messageCmd->strParam, BTL_STR_TYPE_STANDARD, 0x1a1);
    func_021C8860(&messageCmd->strParam, pokeId);
    func_021C8860(&messageCmd->strParam, attackerId);
    func_021C88C8(flow, messageCmd);
    switchCmd = (BtlForceSwitchCmd *)func_021C88A4(flow, BTL_CMD_KIND_FORCE_SWITCH, pokeId);
    switchCmd->pokeId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    switchCmd->mode = BTL_FORCE_SWITCH_MODE_ITEM;
    switchCmd->strId = BTL_FORCE_SWITCH_STR_ID;
    func_021C88C8(flow, switchCmd);
}

/* Ring Target handler table: type immunity check. */
BtlEventHandler *BTL_HANDLER_ITEM_GetRingTargetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemRingTargetHandlers;
}
