/*
 * file:     hand_waza_021e55c4.c
 * unit:     yes
 * function: HAND_WAZA_TransformOnUncategorizedMove, HAND_WAZA_AddLunarDance
 * address:  0x021E55C4
 * packet:   pkt_ov093_021E55C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gLunarDanceHandlers     0x021F252C  data   ov093  a4
 */
#include "hand_waza_021e4754_types.h"

#define BTL_STR_TRANSFORM 0x284

extern BtlEventHandler gLunarDanceHandlers[];
BtlEventHandler *HAND_WAZA_AddLunarDance(int *handlerCount);

/* Transform: the user turns into the target. */
void HAND_WAZA_TransformOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct HandExTransform *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_TRANSFORM, pokeId);
        record->targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, BTL_STR_TRANSFORM);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, record->targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}

BtlEventHandler *HAND_WAZA_AddLunarDance(int *handlerCount)
{
    *handlerCount = 1;
    return gLunarDanceHandlers;
}
