/*
 * file:     unit_021DB560.c
 * unit:     yes
 * function: func_021DB560, func_021DB5B4, func_021DB5C0, func_021DB62C, func_021DB644
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7090   0x021D7090  thumb
 *   d_021F05F0     0x021F05F0  data   ov093  a4
 *   d_021F0920     0x021F0920  data   ov093  a4
 */
#include "unit_021DB0E4_types.h"

/* Ability handlers: Suction Cups, Liquid Ooze. */

void func_021DB560(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DB5B4(int *handlerCount);
void func_021DB5C0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DB62C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DB644(int *handlerCount);
extern const BtlEventHandler d_021F05F0[];
extern const BtlEventHandler d_021F0920[];


/* Suction Cups: when the holder is the target, prevent the forced switch and show the message. */
void func_021DB560(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        if (func_021D76BC(BTL_EVAR_PREVENT_FLAG, 1) != 0) {
            msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
            msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
            func_021C8838(&msg->str, 2, 0x1c6);
            func_021C8860(&msg->str, pokeId);
            func_021C88C8(flow, msg);
        }
    }
}


const BtlEventHandler *func_021DB5B4(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F05F0;
}


/* Liquid Ooze: when the holder is the target of a draining move, damage the attacker by the drained amount instead. */
void func_021DB5C0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 amount;
    HandExDamage *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        amount = func_021D775C(BTL_EVAR_VOLUME);
        func_021D76BC(BTL_EVAR_VOLUME, 0);
        if (amount != 0) {
            cmd = func_021C88A4(flow, HANDEX_DAMAGE, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = func_021D775C(BTL_EVAR_ATTACKER_ID);
            cmd->amount = amount;
            func_021C8838(&cmd->str, 2, 0x1c9);
            func_021C8860(&cmd->str, cmd->pokeId);
            func_021C88C8(flow, cmd);
        }
    }
}


/* Liquid Ooze: remove the factor of the holder when the event that names the holder arrives. */
void func_021DB62C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D7090(factor);
}


const BtlEventHandler *func_021DB644(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F0920;
}
