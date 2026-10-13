/*
 * file:     unit_021DB560.c
 * unit:     yes
 * function: BTL_TOKUSEI_SuctionCups_BlockForcedSwitch, BTL_TOKUSEI_GetSuctionCupsHandlers, BTL_TOKUSEI_LiquidOoze_DamageAttacker, BTL_TOKUSEI_LiquidOoze_RemoveFactorOnEventA3, BTL_TOKUSEI_GetLiquidOozeHandlers
 * address:  0x021DB560
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_EVENT_MarkFactorDead   0x021D7090  thumb
 *   gSuctionCupsHandlers     0x021F05F0  data   ov093  a4
 *   gLiquidOozeHandlers     0x021F0920  data   ov093  a4
 */
#include "unit_021DB0E4_types.h"

/* Ability handlers: Suction Cups, Liquid Ooze. */

void BTL_TOKUSEI_SuctionCups_BlockForcedSwitch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_TOKUSEI_GetSuctionCupsHandlers(int *handlerCount);
void BTL_TOKUSEI_LiquidOoze_DamageAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_TOKUSEI_LiquidOoze_RemoveFactorOnEventA3(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_TOKUSEI_GetLiquidOozeHandlers(int *handlerCount);
extern const BtlEventHandler gSuctionCupsHandlers[];
extern const BtlEventHandler gLiquidOozeHandlers[];


/* Suction Cups: when the holder is the target, prevent the forced switch and show the message. */
void BTL_TOKUSEI_SuctionCups_BlockForcedSwitch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1) != 0) {
            msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
            msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
            func_021C8838(&msg->str, 2, 0x1c6);
            func_021C8860(&msg->str, pokeId);
            func_021C88C8(flow, msg);
        }
    }
}


const BtlEventHandler *BTL_TOKUSEI_GetSuctionCupsHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSuctionCupsHandlers;
}


/* Liquid Ooze: when the holder is the target of a draining move, damage the attacker by the drained amount instead. */
void BTL_TOKUSEI_LiquidOoze_DamageAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 amount;
    HandExDamage *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        amount = BTL_EVENT_GetVar(BTL_EVAR_VOLUME);
        BTL_EVENT_OverwriteVar(BTL_EVAR_VOLUME, 0);
        if (amount != 0) {
            cmd = func_021C88A4(flow, HANDEX_DAMAGE, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
            cmd->amount = amount;
            func_021C8838(&cmd->str, 2, 0x1c9);
            func_021C8860(&cmd->str, cmd->pokeId);
            func_021C88C8(flow, cmd);
        }
    }
}


/* Liquid Ooze: remove the factor of the holder when the event that names the holder arrives. */
void BTL_TOKUSEI_LiquidOoze_RemoveFactorOnEventA3(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_MarkFactorDead(factor);
}


const BtlEventHandler *BTL_TOKUSEI_GetLiquidOozeHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gLiquidOozeHandlers;
}
