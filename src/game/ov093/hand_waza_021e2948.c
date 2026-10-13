/*
 * file:     hand_waza_021e2948.c
 * unit:     yes
 * function: HAND_WAZA_PaybackDoublePowerIfTargetMoved, HAND_WAZA_EruptionGetHandlers
 * address:  0x021E2948
 * packet:   pkt_ov093_021E2948
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   gEruptionHandlers     0x021F24A4  data   ov093  a4
 */
#include "hand_waza_021e1c8c_types.h"

extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *poke, u32 flagId);
extern void BTLV_CORE_EventScaleDamage(int ratio);

void HAND_WAZA_PaybackDoublePowerIfTargetMoved(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_EruptionGetHandlers(int *handlerCount);
extern BtlEventHandler gEruptionHandlers[]; /* Eruption and Water Spout handler table */

/* Payback, base power event: the power doubles when the target has already moved this turn. */
void HAND_WAZA_PaybackDoublePowerIfTargetMoved(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_TURN_FLAG_MOVED))
            BTLV_CORE_EventScaleDamage(2);
    }
}

/* Eruption and Water Spout handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_EruptionGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gEruptionHandlers;
}
