/*
 * file:     hand_waza_021e4ff4.c
 * function: HAND_WAZA_PowerTrickOnUncategorizedMove, HAND_WAZA_AddPowerSplit
 * address:  0x021E4FF4
 * packet:   pkt_ov093_021E4FF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gPowerSplitHandlers     0x021F26E4  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "hand_waza_021e4754_types.h"

#define BTL_STR_POWER_TRICK 0x305

extern BtlEventHandler gPowerSplitHandlers[];
BtlEventHandler *HAND_WAZA_AddPowerSplit(int *handlerCount);

/* Power Trick: the user swaps its attack and defense, and sets the flag that undoes it on the next use. */
void HAND_WAZA_PowerTrickOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    struct HandExSetContFlag *flagRecord;
    struct HandExSetStats *statsRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = pokeId;
        statsRecord->attack = func_021D58A8(user, BPP_VALUE_DEFENSE);
        statsRecord->defense = func_021D58A8(user, BPP_VALUE_ATTACK);
        statsRecord->setAttack = 1;
        statsRecord->setDefense = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&statsRecord->message, BTL_STRTYPE_SET, BTL_STR_POWER_TRICK);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&statsRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
        flagRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_CONT_FLAG, pokeId);
        flagRecord->pokeId = pokeId;
        flagRecord->flagId = BTL_CONT_FLAG_POWER_TRICK;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, flagRecord);
    }
}

BtlEventHandler *HAND_WAZA_AddPowerSplit(int *handlerCount)
{
    *handlerCount = 1;
    return gPowerSplitHandlers;
}
