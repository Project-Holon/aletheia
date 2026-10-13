/*
 * file:     hand_waza_021e54ac.c
 * function: HAND_WAZA_ToxicSpikesOnUncategorizedMoveNoTarget, HAND_WAZA_AddStealthRock
 * address:  0x021E54AC
 * packet:   pkt_ov093_021E54AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 *
 * symbols:
 *   gStealthRockHandlers     0x021F26B4  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_MAIN_IsPokeIdInFirstPair  0x021B9A50  thumb  ov093
 *   HAND_WAZA_AddSideEffect  0x021E556C  thumb  ov093
 */
#include "hand_waza_021e4754_types.h"

#define BTL_SIDE_EFFECT_STR_TOXIC_SPIKES 0x98

extern BtlEventHandler gStealthRockHandlers[];
BtlEventHandler *HAND_WAZA_AddStealthRock(int *handlerCount);

/* Toxic Spikes: a permanent hazard on the opposing side. */
void HAND_WAZA_ToxicSpikesOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    union BtlSickCont cont = BTLV_CORE_MakeSlotKind1Empty();
    int side = BTL_MAIN_IsPokeIdInFirstPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_TOXIC_SPIKES, cont, BTL_SIDE_EFFECT_STR_TOXIC_SPIKES);
}

BtlEventHandler *HAND_WAZA_AddStealthRock(int *handlerCount)
{
    *handlerCount = 1;
    return gStealthRockHandlers;
}
