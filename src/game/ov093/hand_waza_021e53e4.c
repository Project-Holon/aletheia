/*
 * file:     hand_waza_021e53e4.c
 * unit:     yes
 * function: HAND_WAZA_TailwindOnUncategorizedMoveNoTarget, HAND_WAZA_AddLuckyChant, HAND_WAZA_LuckyChantOnUncategorizedMoveNoTarget, HAND_WAZA_AddSpikes, HAND_WAZA_SpikesOnUncategorizedMoveNoTarget, HAND_WAZA_AddToxicSpikes
 * address:  0x021E53E4
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
 *   gLuckyChantHandlers     0x021F260C  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_MAIN_IsPokeIdInFirstPair  0x021B9A50  thumb  ov093
 *   gSpikesHandlers     0x021F2604  data   ov093  a4
 *   gToxicSpikesHandlers     0x021F243C  data   ov093  a4
 */
#include "hand_waza_021e4754_types.h"

#define BTL_SIDE_EFFECT_STR_TAILWIND 0x8c
#define BTL_SIDE_EFFECT_STR_LUCKY_CHANT 0x90
#define BTL_SIDE_EFFECT_STR_SPIKES 0x94

void HAND_WAZA_TailwindOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddLuckyChant(int *handlerCount);
void HAND_WAZA_LuckyChantOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddSpikes(int *handlerCount);
void HAND_WAZA_SpikesOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddToxicSpikes(int *handlerCount);
extern BtlEventHandler gLuckyChantHandlers[];
extern BtlEventHandler gSpikesHandlers[];
extern BtlEventHandler gToxicSpikesHandlers[];

/*
 * Tailwind: a wind on the user's side for 4 turns.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_TailwindOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    union BtlSickCont cont = BTLV_CORE_MakeSlotKind2Index(4);
    int side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_TAILWIND, cont, BTL_SIDE_EFFECT_STR_TAILWIND);
}

BtlEventHandler *HAND_WAZA_AddLuckyChant(int *handlerCount)
{
    *handlerCount = 1;
    return gLuckyChantHandlers;
}

/* Lucky Chant: a ward on the user's side for 5 turns. */
void HAND_WAZA_LuckyChantOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    union BtlSickCont cont = BTLV_CORE_MakeSlotKind2Index(5);
    int side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_LUCKY_CHANT, cont, BTL_SIDE_EFFECT_STR_LUCKY_CHANT);
}

BtlEventHandler *HAND_WAZA_AddSpikes(int *handlerCount)
{
    *handlerCount = 1;
    return gSpikesHandlers;
}

/* Spikes: a permanent hazard on the opposing side. */
void HAND_WAZA_SpikesOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    union BtlSickCont cont = BTLV_CORE_MakeSlotKind1Empty();
    int side = BTL_MAIN_IsPokeIdInFirstPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_SPIKES, cont, BTL_SIDE_EFFECT_STR_SPIKES);
}

BtlEventHandler *HAND_WAZA_AddToxicSpikes(int *handlerCount)
{
    *handlerCount = 1;
    return gToxicSpikesHandlers;
}
