/*
 * file:     hand_waza_021e492c.c
 * unit:     yes
 * function: HAND_WAZA_AromatherapyOnUncategorizedMoveNoTarget, HAND_WAZA_AddHealBell, HAND_WAZA_HealBellOnUncategorizedMoveNoTarget, HAND_WAZA_CureParty, HAND_WAZA_CollectStatusedPokeIds, HAND_WAZA_AddMemento, HAND_WAZA_MementoOnUncategorizedMove, HAND_WAZA_AddSpite, HAND_WAZA_SpiteOnUncategorizedMove, HAND_WAZA_AddPsychUp
 * address:  0x021E492C
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
 *   gHealBellHandlers     0x021F2BA0  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPartyOfPoke  0x021C7FCC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed  0x021C7FE0  thumb  ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer  0x021C8120  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_NextSerialNumberThunk  0x021C83CC  thumb  ov093
 *   gMementoHandlers     0x021F2744  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId  0x021D67B8  thumb  ov093
 *   BTL_POKEPARAM_FindMoveSlot  0x021D5778  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPChecked  0x021D5584  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gSpiteHandlers     0x021F273C  data   ov093  a4
 *   gPsychUpHandlers     0x021F25BC  data   ov093  a4
 */
#include "hand_waza_021e4754_types.h"

#define BTL_PARTY_CURE_MAX 12
#define BTL_MOVE_SLOT_COUNT 4
#define BTL_STR_CURE_PARTY_AROMATHERAPY 0x70
#define BTL_STR_CURE_PARTY_HEAL_BELL 0x6f
#define BTL_STR_SPITE 641
#define BTL_SPITE_PP_MAX 4

void HAND_WAZA_AromatherapyOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddHealBell(int *handlerCount);
void HAND_WAZA_HealBellOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_CureParty(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u16 messageId);
u8 HAND_WAZA_CollectStatusedPokeIds(struct BtlParty *party, u8 startIndex, u8 limit, u8 *outIds);
BtlEventHandler *HAND_WAZA_AddMemento(int *handlerCount);
void HAND_WAZA_MementoOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddSpite(int *handlerCount);
void HAND_WAZA_SpiteOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddPsychUp(int *handlerCount);
extern BtlEventHandler gHealBellHandlers[];
extern BtlEventHandler gMementoHandlers[];
extern BtlEventHandler gSpiteHandlers[];
extern BtlEventHandler gPsychUpHandlers[];

/* Aromatherapy: cure the status of the whole party (message 0x70). */
void HAND_WAZA_AromatherapyOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HAND_WAZA_CureParty(factor, flow, pokeId, work, BTL_STR_CURE_PARTY_AROMATHERAPY);
}

BtlEventHandler *HAND_WAZA_AddHealBell(int *handlerCount)
{
    *handlerCount = 3;
    return gHealBellHandlers;
}

/* Heal Bell: cure the status of the whole party (message 0x6f). */
void HAND_WAZA_HealBellOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HAND_WAZA_CureParty(factor, flow, pokeId, work, BTL_STR_CURE_PARTY_HEAL_BELL);
}

/* Shared body of Aromatherapy and Heal Bell: show the message, then cure every party member (and the ally's party in doubles). */
void HAND_WAZA_CureParty(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u16 messageId)
{
    struct BtlParty *ownParty;
    struct BtlParty *allyParty;
    u8 *curedIds;
    struct HandExMessage *messageRecord;
    struct HandExCureSick *cureRecord;
    u8 curedCount;
    u8 i;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        ownParty = BTL_SERVER_FLOW_GetPartyOfPoke(flow, pokeId);
        allyParty = BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed(flow, pokeId);
        curedIds = BTL_SERVER_FLOW_GetScratchBuffer(flow, BTL_PARTY_CURE_MAX);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, BTL_STRTYPE_STD, messageId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
        curedCount = HAND_WAZA_CollectStatusedPokeIds(ownParty, 0, BTL_PARTY_CURE_MAX, curedIds);
        if (allyParty != 0)
            curedCount = curedCount + HAND_WAZA_CollectStatusedPokeIds(allyParty, curedCount, BTL_PARTY_CURE_MAX, curedIds);
        if (curedCount != 0) {
            if (curedCount > BTL_PARTY_CURE_MAX)
                curedCount = BTL_PARTY_CURE_MAX;
            cureRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureRecord->pokeCount = curedCount;
            for (i = 0; i < curedCount; i++)
                cureRecord->pokeIds[i] = curedIds[i];
            cureRecord->sickKind = BTL_SICK_ALL_MAJOR;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureRecord);
        }
    }
}

/* Collects the ids of the party members that have a major status into outIds, starting at startIndex and stopping at limit; returns how many were added. */
u8 HAND_WAZA_CollectStatusedPokeIds(struct BtlParty *party, u8 startIndex, u8 limit, u8 *outIds)
{
    u8 addedCount;
    u8 i;
    u8 memberCount = BTL_SLOT_GetCount(party);
    struct BtlPokeParam *member;

    addedCount = 0;
    for (i = 0; i < memberCount; i++) {
        if (startIndex >= limit)
            break;
        member = BTL_SLOT_GetPokeParam(party, i);
        if (BTL_POKEPARAM_GetMajorStatusIndex(member) != 0) {
            outIds[startIndex] = BTL_POKEPARAM_GetPokeId(member);
            startIndex = startIndex + 1;
            addedCount = addedCount + 1;
        }
    }
    return addedCount;
}

/*
 * Sibling of src/matched/ov170_func_021E2650.c and ov170_func_021E376C.c.
 * The image computes r + 0x1E
 * separately for func_021DEFEC and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
BtlEventHandler *HAND_WAZA_AddMemento(int *handlerCount)
{
    *handlerCount = 1;
    return gMementoHandlers;
}

/* Memento: the user lowers the target's attack and special attack by 2 stages each, then faints. */
void HAND_WAZA_MementoOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    u32 serialNumber;
    enum { BTL_RANK_KIND_ATTACK = 1 } rankKind;
    int volume;
    struct HandExRankChange *rankRecord;
    struct HandExKillPoke *killRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        serialNumber = BTL_SERVER_FLOW_NextSerialNumberThunk(flow);
        rankKind = BTL_RANK_KIND_ATTACK;
        rankRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_CHANGE, pokeId);
        rankRecord->pokeCount = rankKind;
        rankRecord->pokeId = targetId;
        rankRecord->rankKind = rankKind;
        volume = rankKind - 3;
        rankRecord->volume = volume;
        rankRecord->serialNumber = serialNumber;
        rankRecord->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankRecord);
        rankRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_CHANGE, pokeId);
        rankRecord->pokeCount = rankKind;
        rankRecord->pokeId = targetId;
        rankRecord->rankKind = 3;
        rankRecord->volume = volume;
        rankRecord->serialNumber = serialNumber;
        rankRecord->showMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankRecord);
        killRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_KILL_POKE, pokeId);
        killRecord->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, killRecord);
    }
}

BtlEventHandler *HAND_WAZA_AddSpite(int *handlerCount)
{
    *handlerCount = 1;
    return gSpiteHandlers;
}

/* Spite: the target loses up to 4 PP of the move it used last. */
void HAND_WAZA_SpiteOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    int moveId;
    int moveSlot;
    u8 amount;
    struct HandExReducePp *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        moveId = BTL_POKEPARAM_GetLastSelectedMoveId(target);
        moveSlot = BTL_POKEPARAM_FindMoveSlot(target, moveId);
        if (moveSlot != BTL_MOVE_SLOT_COUNT) {
            amount = BTL_POKEPARAM_GetMovePPChecked(target, moveSlot);
            if (amount > BTL_SPITE_PP_MAX)
                amount = BTL_SPITE_PP_MAX;
            if (amount != 0) {
                record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REDUCE_PP, pokeId);
                record->pokeId = targetId;
                record->amount = amount;
                record->moveSlot = moveSlot;
                BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, BTL_STR_SPITE);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, targetId);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, moveId);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, amount);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            }
        }
    }
}

BtlEventHandler *HAND_WAZA_AddPsychUp(int *handlerCount)
{
    *handlerCount = 1;
    return gPsychUpHandlers;
}
