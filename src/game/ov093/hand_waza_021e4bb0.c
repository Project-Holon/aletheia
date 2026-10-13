/*
 * file:     hand_waza_021e4bb0.c
 * unit:     yes
 * function: HAND_WAZA_PsychUpOnUncategorizedMove, HAND_WAZA_AddHeartSwap, HAND_WAZA_HeartSwapOnUncategorizedMove, HAND_WAZA_PowerSwapOnUncategorizedMove
 * address:  0x021E4BB0
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   gPowerSwapHandlers 0x021F2724 data a4
 *   gGuardSwapHandlers 0x021F2544 data a4
 *   gHeartSwapHandlers     0x021F275C  data   ov093  a4
 */
#include "hand_waza_021e4754_types.h"

#define BTL_RANK_BACKUP_SIZE 28
#define BTL_STR_PSYCH_UP 0x417
#define BTL_STR_HEART_SWAP 673
#define BTL_STR_POWER_SWAP 676

void HAND_WAZA_PsychUpOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddHeartSwap(int *handlerCount);
void HAND_WAZA_HeartSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddPowerSwap(int *handlerCount);
void HAND_WAZA_PowerSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddGuardSwap(int *handlerCount);
extern BtlEventHandler gHeartSwapHandlers[];
extern BtlEventHandler gPowerSwapHandlers[];
extern BtlEventHandler gGuardSwapHandlers[];

/* Psych Up: the user copies all stat stages of the target. */
void HAND_WAZA_PsychUpOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *target;
    struct HandExSetRanks *ranksRecord;
    struct HandExMessage *messageRecord;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = pokeId;
        ranksRecord->ranks[0] = func_021D59B4(target, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[1] = func_021D59B4(target, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[2] = func_021D59B4(target, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[3] = func_021D59B4(target, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = func_021D59B4(target, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = func_021D59B4(target, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = func_021D59B4(target, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_SET, BTL_STR_PSYCH_UP);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}

BtlEventHandler *HAND_WAZA_AddHeartSwap(int *handlerCount)
{
    *handlerCount = 1;
    return gHeartSwapHandlers;
}

/* Heart Swap: the user and the target swap all stat stages. */
void HAND_WAZA_HeartSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    struct BtlPokeParam *user;
    u32 *userRanks;
    int i;
    struct HandExSetRanks *ranksRecord;
    struct HandExMessage *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        userRanks = (u32 *)BTL_SERVER_FLOW_GetScratchBuffer(flow, BTL_RANK_BACKUP_SIZE);
        for (i = BPP_VALUE_ATTACK_RANK; i <= BPP_VALUE_EVASION_RANK; i++) {
            userRanks[i - 1] = func_021D59B4(user, i);
        }
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = pokeId;
        ranksRecord->ranks[0] = func_021D59B4(target, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[1] = func_021D59B4(target, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[2] = func_021D59B4(target, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[3] = func_021D59B4(target, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = func_021D59B4(target, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = func_021D59B4(target, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = func_021D59B4(target, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = targetId;
        ranksRecord->ranks[0] = userRanks[0];
        ranksRecord->ranks[1] = userRanks[1];
        ranksRecord->ranks[2] = userRanks[2];
        ranksRecord->ranks[3] = userRanks[3];
        ranksRecord->ranks[4] = userRanks[4];
        ranksRecord->ranks[5] = userRanks[5];
        ranksRecord->ranks[6] = userRanks[6];
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_SET, BTL_STR_HEART_SWAP);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}

BtlEventHandler *HAND_WAZA_AddPowerSwap(int *handlerCount)
{
    *handlerCount = 1;
    return gPowerSwapHandlers;
}

/* Power Swap: the user and the target swap their attack and special attack stages. */
void HAND_WAZA_PowerSwapOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    struct BtlPokeParam *user;
    u32 userAttackRank;
    u32 userSpAttackRank;
    struct HandExSetRanks *ranksRecord;
    struct HandExMessage *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        userAttackRank = func_021D59B4(user, BPP_VALUE_ATTACK_RANK);
        userSpAttackRank = func_021D59B4(user, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = pokeId;
        ranksRecord->ranks[0] = func_021D59B4(target, BPP_VALUE_ATTACK_RANK);
        ranksRecord->ranks[2] = func_021D59B4(target, BPP_VALUE_SP_ATTACK_RANK);
        ranksRecord->ranks[1] = func_021D59B4(user, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[3] = func_021D59B4(user, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = func_021D59B4(user, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = func_021D59B4(user, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = func_021D59B4(user, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        ranksRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_RANKS, pokeId);
        ranksRecord->pokeId = targetId;
        ranksRecord->ranks[0] = userAttackRank;
        ranksRecord->ranks[2] = userSpAttackRank;
        ranksRecord->ranks[1] = func_021D59B4(target, BPP_VALUE_DEFENSE_RANK);
        ranksRecord->ranks[3] = func_021D59B4(target, BPP_VALUE_SP_DEFENSE_RANK);
        ranksRecord->ranks[4] = func_021D59B4(target, BPP_VALUE_SPEED_RANK);
        ranksRecord->ranks[5] = func_021D59B4(target, BPP_VALUE_ACCURACY_RANK);
        ranksRecord->ranks[6] = func_021D59B4(target, BPP_VALUE_EVASION_RANK);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, ranksRecord);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_SET, BTL_STR_POWER_SWAP);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}

BtlEventHandler *HAND_WAZA_AddGuardSwap(int *handlerCount)
{
    *handlerCount = 1;
    return gGuardSwapHandlers;
}
