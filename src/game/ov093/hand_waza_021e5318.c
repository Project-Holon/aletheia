/*
 * file:     hand_waza_021e5318.c
 * function: HAND_WAZA_LightScreenOnUncategorizedMoveNoTarget, HAND_WAZA_AddSafeguard
 * address:  0x021E5318
 * packet:   pkt_ov093_021E5318
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 *
 * symbols:
 *   gSafeguardHandlers     0x021F25CC  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   HAND_WAZA_AddSideEffect  0x021E556C  thumb  ov093
 */
#include "hand_waza_021e4754_types.h"

#define BTL_SIDE_EFFECT_STR_LIGHT_SCREEN 0x80

extern BtlEventHandler gSafeguardHandlers[];
BtlEventHandler *HAND_WAZA_AddSafeguard(int *handlerCount);

/*
 * Light Screen: a screen on the user's side for 5 turns.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_LightScreenOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    union BtlSickCont cont = BTLV_CORE_MakeSlotKind2Index(5);
    int side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_LIGHT_SCREEN, cont, BTL_SIDE_EFFECT_STR_LIGHT_SCREEN);
}

BtlEventHandler *HAND_WAZA_AddSafeguard(int *handlerCount)
{
    *handlerCount = 1;
    return gSafeguardHandlers;
}
