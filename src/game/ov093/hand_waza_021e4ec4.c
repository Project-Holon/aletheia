/*
 * file:     hand_waza_021e4ec4.c
 * unit: yes
 * function: HAND_WAZA_GuardSwapOnUncategorizedMove, HAND_WAZA_AddPowerTrick
 * address: 0x021E4EC4
 * packet: pkt_ov093_021E4EC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gPowerTrickHandlers 0x021F26BC data a4
 */
#include "hand_waza_021e4754_types.h"

#define BTL_STR_GUARD_SWAP 679

extern BtlEventHandler gPowerTrickHandlers[];
BtlEventHandler *HAND_WAZA_AddPowerTrick(int *handlerCount);

/* Guard Swap: the user and the target swap their defense and special defense stages. */
void HAND_WAZA_GuardSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    struct BtlPokeParam *user;
    u32 userDefenseRank;
    u32 userSpDefenseRank;
    struct HandExSetRanks *ranksRecord;
    struct HandExMessage *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        userDefenseRank = func_021D59B4(user, BPP_VALUE_DEFENSE_RANK);
        userSpDefenseRank = func_021D59B4(user, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = pokeId;
        ranksRecord->ranks[0] = func_021D59B4(user, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[2] = func_021D59B4(user, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[1] = func_021D59B4(target, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[3] = func_021D59B4(target, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = func_021D59B4(user, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = func_021D59B4(user, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = func_021D59B4(user, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = targetId;
        ranksRecord->ranks[0] = func_021D59B4(target, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[2] = func_021D59B4(target, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[1] = userDefenseRank;
        ranksRecord->ranks[3] = userSpDefenseRank;
        ranksRecord->ranks[4] = func_021D59B4(target, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = func_021D59B4(target, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = func_021D59B4(target, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_SET, BTL_STR_GUARD_SWAP);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}

BtlEventHandler *HAND_WAZA_AddPowerTrick(int *handlerCount)
{
    *handlerCount = 1;
    return gPowerTrickHandlers;
}
