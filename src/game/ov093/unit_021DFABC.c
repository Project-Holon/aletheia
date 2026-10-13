/*
 * file:     unit_021DFABC.c
 * unit:     yes
 * function: func_021DFABC, func_021DFB40, func_021DFB4C, func_021DFB94, func_021DFBAC, func_021DFBF4, func_021DFC00, func_021DFCAC
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021D76BC   0x021D76BC  thumb
 *   d_021F1934     0x021F1934  data   ov093  a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   d_021F14CC     0x021F14CC  data   ov093  a4
 *   d_021F14BC     0x021F14BC  data   ov093  a4
 */
#include "unit_021DF974_types.h"

extern BtlEventHandler d_021F1934[];
extern BtlEventHandler d_021F14CC[];
extern BtlEventHandler d_021F14BC[];

/* Rocky Helmet: a contact move that hit the holder costs the attacker 1/6 of its max HP. */
void func_021DFABC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlLoseHpCmd *cmd;
    struct BtlPokeParam *attacker;
    int divisor;

    if (pokeId != func_021D775C(BTL_EVAR_DEFENDER_ID))
        return;
    if (func_021D775C(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0)
        return;
    if (!WAZA_TOOL_GetFlag(func_021D775C(BTL_EVAR_MOVE_ID), 0))
        return;
    cmd = (BtlLoseHpCmd *)func_021C88A4(flow, BTL_CMD_KIND_LOSE_HP, pokeId);
    cmd->pokeId = func_021D775C(BTL_EVAR_ATTACKER_ID);
    attacker = func_021C7CF4(flow, cmd->pokeId);
    divisor = (u8)func_021DCFF8(factor, BTL_ITEM_PARAM_DAMAGE_DIVISOR);
    cmd->amount = func_021D7B74(attacker, divisor);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 424);
    func_021C8860(&cmd->strParam, cmd->pokeId);
    func_021C88C8(flow, cmd);
}

/* Air Balloon handler table: enter field, ground check, damage reaction. */
BtlEventHandler *func_021DFB40(int *handlerCount)
{
    *handlerCount = 3;
    return d_021F1934;
}

/* Air Balloon: announces the balloon when the holder enters the field, unless a field effect forbids it. */
void func_021DFB4C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    if (func_021EF948(BTL_FIELD_EFFECT_GRAVITY_QUERY) != 0)
        return;
    cmd = (BtlMessageCmd *)func_021C88A4(flow, BTL_CMD_KIND_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0x198);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
}

/* Air Balloon: the holder counts as floating. */
void func_021DFB94(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D76BC(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

/* Air Balloon: when the holder is hit it loses the item and a message is shown. */
void func_021DFBAC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlSetItemCmd *cmd;

    if (pokeId != func_021D775C(BTL_EVAR_DEFENDER_ID))
        return;
    cmd = (BtlSetItemCmd *)func_021C88A4(flow, BTL_CMD_KIND_SET_ITEM, pokeId);
    cmd->pokeId = pokeId;
    cmd->itemId = 0;
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0x19b);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
}

/* Red Card handler table: damage reaction at the end of the move. */
BtlEventHandler *func_021DFBF4(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F14CC;
}

/* Red Card: after the holder is hit, the attacker is forced out of the field. */
void func_021DFC00(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlItemMessageCmd *messageCmd;
    BtlForceSwitchCmd *switchCmd;
    u8 attackerId;

    if (func_021E85F8(pokeId) == 0)
        return;
    attackerId = func_021D775C(BTL_EVAR_ATTACKER_ID);
    if (func_021C7D00(flow, attackerId) == 6)
        return;
    if (func_021D775C(BTL_EVAR_SHEER_FORCE_FLAG) != 0)
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
    switchCmd->pokeId = func_021D775C(BTL_EVAR_ATTACKER_ID);
    switchCmd->mode = BTL_FORCE_SWITCH_MODE_ITEM;
    switchCmd->strId = BTL_FORCE_SWITCH_STR_ID;
    func_021C88C8(flow, switchCmd);
}

/* Ring Target handler table: type immunity check. */
BtlEventHandler *func_021DFCAC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F14BC;
}
