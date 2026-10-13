/*
 * file:     hand_waza_021e3a48.c
 * unit:     yes
 * function: HAND_WAZA_FalseSwipeLeaveOneHp, HAND_WAZA_GetEndureHandlers, HAND_WAZA_EndureBraceUp, HAND_WAZA_EndureSurviveAtOneHp, HAND_WAZA_EndureRemoveAtTurnEnd, HAND_WAZA_GetProtectHandlers, HAND_WAZA_ProtectResetStreakAfterOtherMove
 * address:  0x021E3A48
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   HAND_WAZA_ProtectIncrementStreak  0x021E3C5C  thumb  ov093
 *   BTL_EVENT_RemoveFactor   0x021D7040  thumb
 *   gEndureHandlers     0x021F2FC8  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   gProtectMoveIds     0x021F284C  data   a2
 *   gProtectHandlers     0x021F2D58  data   ov093  a4
 */
#include "hand_waza_021e396c_types.h"

void HAND_WAZA_FalseSwipeLeaveOneHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetEndureHandlers(int *handlerCount);
void HAND_WAZA_EndureBraceUp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, struct EndureWork *work);
void HAND_WAZA_EndureSurviveAtOneHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, struct EndureWork *work);
void HAND_WAZA_EndureRemoveAtTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetProtectHandlers(int *handlerCount);
void HAND_WAZA_ProtectResetStreakAfterOtherMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
extern int gEndureHandlers[];
extern const u16 gProtectMoveIds[];
extern int gProtectHandlers[];

/* False Swipe (move 206), event 0x74: a lethal hit leaves the target with 1 HP (survive result 2). */
void HAND_WAZA_FalseSwipeLeaveOneHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_GENERIC_FLAG) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_SURVIVE_RESULT, 2);
    }
}

/* Endure (move 203): handler table, 6 rows. The first three handlers are shared with Protect. */
int *HAND_WAZA_GetEndureHandlers(int *handlerCount)
{
    *handlerCount = 6;
    return gEndureHandlers;
}

/* Endure, event 0xa0 (the move itself): shows the message, marks the user as braced and raises the streak. */
void HAND_WAZA_EndureBraceUp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, struct EndureWork *work)
{
    struct HandExMessageRecord *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_ENDURE_BRACED);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        work->braced = 1;
        HAND_WAZA_ProtectIncrementStreak(flow, pokeId, 0);
    }
}

/* Endure, event 0x74: a lethal hit on the braced user leaves 1 HP (survive result 1). */
void HAND_WAZA_EndureSurviveAtOneHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, struct EndureWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (work->braced != 0) {
            if (BTL_EVENT_GetVar(BTL_EVAR_GENERIC_FLAG) != 0)
                BTL_EVENT_OverwriteVar(BTL_EVAR_SURVIVE_RESULT, 1);
        }
    }
}

/* Endure, event 0x76: the factor ends with the turn. */
void HAND_WAZA_EndureRemoveAtTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_RemoveFactor(factor);
}

/* Protect (move 182) and Detect (move 197): handler table, 4 rows. */
int *HAND_WAZA_GetProtectHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gProtectHandlers;
}

/* Protect, Detect and Endure, event 3: when the user last used a move outside the protect family, the streak restarts. */
void HAND_WAZA_ProtectResetStreakAfterOtherMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    unsigned i;
    int lastMoveId;
    struct HandExSetCounter *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        lastMoveId = BTL_POKEPARAM_GetLastUsedMoveId(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        for (i = 0; i < 5; i++) {
            if (lastMoveId == gProtectMoveIds[i])
                return;
        }
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        record->pokeId = pokeId;
        record->counterId = BTL_COUNTER_PROTECT_STREAK;
        record->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}
