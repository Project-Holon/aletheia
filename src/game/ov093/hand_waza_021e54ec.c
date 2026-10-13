/*
 * file:     hand_waza_021e54ec.c
 * unit:     yes
 * function: HAND_WAZA_StealthRockOnUncategorizedMoveNoTarget, HAND_WAZA_AddWideGuard, HAND_WAZA_WideGuardOnUncategorizedMoveNoTarget, HAND_WAZA_AddSideEffect, HAND_WAZA_AddTransform
 * address:  0x021E54EC
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
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_MAIN_IsPokeIdInFirstPair  0x021B9A50  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   HAND_WAZA_ProtectIncrementStreak  0x021E3C5C  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gTransformHandlers     0x021F2484  data   ov093  a4
 *   gWideGuardHandlers     0x021F2DF8  data   ov093  a4
 */
#define HAND_WAZA_DEFINES_ADD_SIDE_EFFECT
#include "hand_waza_021e4754_types.h"

#define BTL_SIDE_EFFECT_STR_STEALTH_ROCK 0x9c
#define BTL_SIDE_EFFECT_STR_WIDE_GUARD 0xa0

void HAND_WAZA_StealthRockOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddWideGuard(int *handlerCount);
void HAND_WAZA_WideGuardOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_AddSideEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work,
                   u8 side, int effectKind, union BtlSickCont cont, u16 messageId);
BtlEventHandler *HAND_WAZA_AddTransform(int *handlerCount);
extern void HAND_WAZA_ProtectIncrementStreak(struct BtlSvFlow *flow, int pokeId, int arg);
extern BtlEventHandler gTransformHandlers[];
extern BtlEventHandler gWideGuardHandlers[];

/*
 * Stealth Rock: a permanent hazard on the opposing side.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_StealthRockOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    union BtlSickCont cont = BTLV_CORE_MakeSlotKind1Empty();
    u8 side = BTL_MAIN_IsPokeIdInFirstPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_STEALTH_ROCK, cont, BTL_SIDE_EFFECT_STR_STEALTH_ROCK);
}

BtlEventHandler *HAND_WAZA_AddWideGuard(int *handlerCount)
{
    *handlerCount = 4;
    return gWideGuardHandlers;
}

/* Wide Guard: a ward on the user's side for 1 turn. */
void HAND_WAZA_WideGuardOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    union BtlSickCont cont;

    cont = BTLV_CORE_MakeSlotKind2Index(1);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, BTL_MAIN_IsPokeIdInSecondPair(pokeId), BTL_SIDE_EFFECT_WIDE_GUARD, cont, BTL_SIDE_EFFECT_STR_WIDE_GUARD);
    HAND_WAZA_ProtectIncrementStreak(flow, pokeId, 1);
}

/* Shared by the screens, wards and hazards: puts an effect of the given kind and duration on a side and shows the message. */
void HAND_WAZA_AddSideEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work,
                   u8 side, int effectKind, union BtlSickCont cont, u16 messageId)
{
    struct HandExAddSideEffect *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SIDE_EFFECT, pokeId);
        record->effectKind = effectKind;
        record->side = side;
        record->cont = cont;
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_STD, messageId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, side);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}

BtlEventHandler *HAND_WAZA_AddTransform(int *handlerCount)
{
    *handlerCount = 1;
    return gTransformHandlers;
}
