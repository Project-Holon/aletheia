/*
 * file:     hand_waza_021e48c0.c
 * function: HAND_WAZA_ImprisonOnUncategorizedMove, HAND_WAZA_AddAromatherapy
 * address:  0x021E48C0
 * packet:   pkt_ov093_021E48C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gAromatherapyHandlers     0x021F2B88  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "hand_waza_021e4754_types.h"

#define BTL_FIELD_EFFECT_IMPRISON 3
#define BTL_STR_IMPRISON 0x24a

extern BtlEventHandler gAromatherapyHandlers[];
BtlEventHandler *HAND_WAZA_AddAromatherapy(int *handlerCount);

/* Imprison: the user seals the moves it knows against the opponents (field effect bound to the user). */
void HAND_WAZA_ImprisonOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct HandExAddFieldEffect *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_FIELD_EFFECT, pokeId);
        record->effectKind = BTL_FIELD_EFFECT_IMPRISON;
        record->cont = BTLV_CORE_MakeSlotKind3(pokeId);
        record->showMessage = 1;
        record->message.strType = BTL_STRTYPE_SET;
        record->message.strId = BTL_STR_IMPRISON;
        record->message.argCount = 1;
        record->message.args[0] = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}

BtlEventHandler *HAND_WAZA_AddAromatherapy(int *handlerCount)
{
    *handlerCount = 3;
    return gAromatherapyHandlers;
}
