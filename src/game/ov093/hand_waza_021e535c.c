/*
 * file:     hand_waza_021e535c.c
 * unit:     yes
 * function: HAND_WAZA_SafeguardOnUncategorizedMoveNoTarget, HAND_WAZA_AddMist, HAND_WAZA_MistOnUncategorizedMoveNoTarget, HAND_WAZA_AddTailwind
 * address:  0x021E535C
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
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   HAND_WAZA_AddSideEffect  0x021E556C  thumb  ov093
 *   gMistHandlers     0x021F2794  data   ov093  a4
 *   gTailwindHandlers     0x021F25EC  data   ov093  a4
 */
#include "hand_waza_021e4754_types.h"

#define BTL_SIDE_EFFECT_STR_SAFEGUARD 0x84
#define BTL_SIDE_EFFECT_STR_MIST 0x88

void HAND_WAZA_SafeguardOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddMist(int *handlerCount);
void HAND_WAZA_MistOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddTailwind(int *handlerCount);
extern BtlEventHandler gMistHandlers[];
extern BtlEventHandler gTailwindHandlers[];

/*
 * Safeguard: a ward on the user's side for 5 turns.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_SafeguardOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    int side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    union BtlSickCont cont = BTLV_CORE_MakeSlotKind2Index(5);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_SAFEGUARD, cont, BTL_SIDE_EFFECT_STR_SAFEGUARD);
}

BtlEventHandler *HAND_WAZA_AddMist(int *handlerCount)
{
    *handlerCount = 1;
    return gMistHandlers;
}

/* Mist: a ward on the user's side for 5 turns. */
void HAND_WAZA_MistOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    union BtlSickCont cont = BTLV_CORE_MakeSlotKind2Index(5);
    int side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_MIST, cont, BTL_SIDE_EFFECT_STR_MIST);
}

BtlEventHandler *HAND_WAZA_AddTailwind(int *handlerCount)
{
    *handlerCount = 1;
    return gTailwindHandlers;
}
