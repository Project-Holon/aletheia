/*
 * file:     hand_waza_021e3b64.c
 * unit:     yes
 * function: HAND_WAZA_ProtectCheckSuccess, HAND_WAZA_ProtectResetStreakOnFail, HAND_WAZA_ProtectActivate, HAND_WAZA_ProtectIncrementStreak, HAND_WAZA_GetBideHandlers, HAND_WAZA_BideAdvanceTurn, HAND_WAZA_BideSelectMessage, HAND_WAZA_BideCheckStoredDamage, HAND_WAZA_BideDecideTarget, HAND_WAZA_BideStoreDamage, HAND_WAZA_BideDoubleStoredDamage, HAND_WAZA_BideEndOnFail, HAND_WAZA_BideFindTarget, HAND_WAZA_BideCureStoringState, HAND_WAZA_GetRecycleHandlers, HAND_WAZA_RecycleRestoreItem, HAND_WAZA_GetPsychoShiftHandlers, HAND_WAZA_PsychoShiftTransferStatus, HAND_WAZA_GetPainSplitHandlers, HAND_WAZA_PainSplitAverageHp, HAND_WAZA_GetBellyDrumHandlers
 * address:  0x021E3B64
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
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021E8624  0x021E8624  thumb  ov093
 *   gProtectFailRange     0x021F2856  data   a1
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gBideHandlers     0x021F2FF8  data   a4
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Value  0x021E89D4  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 *   BTL_POKEPARAM_GetHitCount  0x021D6920  thumb  ov093
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   gPsychoShiftHandlers     0x021F27C4  data   a4
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Index15  0x021E8A58  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   gPainSplitHandlers     0x021F27BC  data   a4
 *   gBellyDrumHandlers 0x021F27B4 data a4
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   gRecycleHandlers     0x021F27CC  data   ov093  a4
 */
#include "hand_waza_021e396c_types.h"

#define BTL_EVENT_SIGNATURE struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId

void HAND_WAZA_ProtectCheckSuccess(BTL_EVENT_SIGNATURE, int *work);
void HAND_WAZA_ProtectResetStreakOnFail(BTL_EVENT_SIGNATURE, int *work);
void HAND_WAZA_ProtectActivate(BTL_EVENT_SIGNATURE, int *work);
void HAND_WAZA_ProtectIncrementStreak(struct BtlSvFlow *flow, int pokeId, int silent);
int *HAND_WAZA_GetBideHandlers(int *handlerCount);
void HAND_WAZA_BideAdvanceTurn(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideSelectMessage(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideCheckStoredDamage(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideDecideTarget(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideStoreDamage(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideDoubleStoredDamage(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideEndOnFail(BTL_EVENT_SIGNATURE, struct BideWork *work);
int HAND_WAZA_BideFindTarget(BTL_EVENT_SIGNATURE, struct BideWork *work);
void HAND_WAZA_BideCureStoringState(struct BtlSvFlow *flow, int pokeId, struct BideWork *work);
int *HAND_WAZA_GetRecycleHandlers(int *handlerCount);
void HAND_WAZA_RecycleRestoreItem(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetPsychoShiftHandlers(int *handlerCount);
void HAND_WAZA_PsychoShiftTransferStatus(BTL_EVENT_SIGNATURE);
int *HAND_WAZA_GetPainSplitHandlers(int *handlerCount);
void HAND_WAZA_PainSplitAverageHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
u32 *HAND_WAZA_GetBellyDrumHandlers(u32 *handlerCount);
extern const u8 gProtectFailRange[];
extern int gBideHandlers[];
extern int gPsychoShiftHandlers[];
extern int gPainSplitHandlers[];
extern int gRecycleHandlers[];
extern u32 gBellyDrumHandlers[];

/* Protect, Detect, Endure, event 0x1f: fails the move on consecutive use (chance from gProtectFailRange)
   and when the user acts last of the turn. */
void HAND_WAZA_ProtectCheckSuccess(BTL_EVENT_SIGNATURE, int *work)
{
    unsigned streak;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        streak = BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_COUNTER_PROTECT_STREAK);
        if (streak != 0) {
            if (streak >= BTL_PROTECT_STREAK_MAX + 1)
                streak = BTL_PROTECT_STREAK_MAX;
            if (BTL_CALC_Random(gProtectFailRange[streak]) != 0) {
                BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
                return;
            }
        }
        if (func_021E8624(flow, pokeId) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
    }
}

/* Protect, Detect, Endure, event 0x21 (the move failed): the streak restarts and the factor ends. */
void HAND_WAZA_ProtectResetStreakOnFail(BTL_EVENT_SIGNATURE, int *work)
{
    struct HandExSetCounter *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        record->pokeId = pokeId;
        record->counterId = BTL_COUNTER_PROTECT_STREAK;
        record->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        BTL_EVENT_RemoveFactor(factor);
    }
}

/* Protect and Detect, event 0xa0 (the move itself): sets the protected turn flag, raises the streak, shows the message. */
void HAND_WAZA_ProtectActivate(BTL_EVENT_SIGNATURE, int *work)
{
    struct HandExTurnFlag *turnFlag;
    struct HandExMessageRecord *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        BTL_SERVER_FLOW_GetPokeParam(flow, pokeId); /* the original discards this lookup */
        turnFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_TURN_FLAG, pokeId);
        turnFlag->pokeId = pokeId;
        turnFlag->flag = BTL_TURN_FLAG_PROTECTED;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, turnFlag);
        HAND_WAZA_ProtectIncrementStreak(flow, pokeId, 0);
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_PROTECT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&message->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    }
}

/* Raises the Protect streak counter of the Pokemon by one; silent goes into header flag bit 24. */
void HAND_WAZA_ProtectIncrementStreak(struct BtlSvFlow *flow, int pokeId, int silent)
{
    struct BtlPokeParam *bpp;
    struct HandExSetCounter *record;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
    record->value = BTL_POKEPARAM_GetCounter(bpp, BTL_COUNTER_PROTECT_STREAK) + 1;
    record->pokeId = pokeId;
    record->counterId = BTL_COUNTER_PROTECT_STREAK;
    record->header = (record->header & ~HANDEX_FLAG_SILENT) | ((silent & 1) << 24);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
}

/* Bide (move 117): handler table, 7 rows. */
int *HAND_WAZA_GetBideHandlers(int *handlerCount)
{
    *handlerCount = 7;
    return gBideHandlers;
}

/* Bide, event 0x24: turn by turn. Phase 0 starts the storing status, phase 1 keeps storing, later phases release. */
void HAND_WAZA_BideAdvanceTurn(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        switch (work->phase) {
        case 0:
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            record->sickKind = BTL_SICK_BIDE;
            record->sickCont = BTLV_CORE_MakeSlotKind1Value(BTL_EVENT_GetFactorKey(factor));
            record->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_PHASE, 2);
            work->storing = 1;
            work->phase = 1;
            work->storedDamage = 0;
            break;
        case 1:
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_PHASE, 2);
            work->phase = 2;
            break;
        case 2:
        default:
            BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, 1);
            HAND_WAZA_BideCureStoringState(flow, pokeId, work);
            break;
        }
    }
}

/* Bide, event 0x19: chooses the "storing energy" message of the first two turns. */
void HAND_WAZA_BideSelectMessage(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    struct HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        message = (struct HandExMessage *)BTL_EVENT_GetVar(BTL_EVAR_MESSAGE);
        switch (work->phase) {
        case 1:
            BTL_SERVER_FLOW_InitMsgRecord(message, BTL_MSG_KIND_SET, HAND_WAZA_STR_BIDE_STORING);
            BTL_SERVER_FLOW_AppendMsgRecordArg(message, pokeId);
            BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
            break;
        case 2:
            BTL_SERVER_FLOW_InitMsgRecord(message, BTL_MSG_KIND_SET, HAND_WAZA_STR_BIDE_STORING_MORE);
            BTL_SERVER_FLOW_AppendMsgRecordArg(message, pokeId);
            BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
            break;
        }
    }
}

/* Bide, event 0x1f: on release the move fails when no damage was stored or nobody hit the user. */
void HAND_WAZA_BideCheckStoredDamage(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (work->phase >= 2) {
            if (work->storedDamage == 0)
                BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
            else if (work->targetId == BTL_POKEID_NONE)
                BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
            work->phase = 3;
        }
    }
}

/* Bide, event 0x29: on release the target is the Pokemon that hit the user last. */
void HAND_WAZA_BideDecideTarget(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    int targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (work->phase >= 2) {
            targetId = HAND_WAZA_BideFindTarget(factor, flow, pokeId, work);
            work->targetId = targetId;
            BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, targetId);
        }
    }
}

/* Bide, event 0x4b: while storing, adds the damage the user takes (not into a substitute). */
void HAND_WAZA_BideStoreDamage(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0) {
            if (work->storing != 0)
                work->storedDamage += BTL_EVENT_GetVar(BTL_EVAR_DAMAGE);
        }
    }
}

/* Bide, event 0x46: on release the damage is twice the stored damage. */
void HAND_WAZA_BideDoubleStoredDamage(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    int damage;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (work->phase >= 2) {
            BTL_SERVER_FLOW_GetPokeParam(flow, pokeId); /* the original discards this lookup */
            damage = work->storedDamage;
            if (damage != 0)
                damage *= 2;
            BTL_EVENT_OverwriteVar(BTL_EVAR_FIXED_DAMAGE, damage);
            work->phase = 3;
        }
    }
}

/* Bide, event 0x21 (the move failed): ends the storing status. */
void HAND_WAZA_BideEndOnFail(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_WAZA_BideCureStoringState(flow, pokeId, work);
}

/* Bide: finds the Pokemon to hit on release. It is the attacker of the first hit recorded in the last three turns;
   when that Pokemon has left its position, a random opponent is taken. Returns 0x1F when nothing hit the user. */
int HAND_WAZA_BideFindTarget(BTL_EVENT_SIGNATURE, struct BideWork *work)
{
    u8 scratch[16]; /* hit record at +6 (attacker id at +0xB), later the list of candidate ids */
    struct BtlPokeParam *bpp;
    unsigned turnAgo;
    int attackerId;
    int side;
    int candidateCount;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    for (turnAgo = 0; turnAgo < 3; turnAgo++) {
        if (BTL_POKEPARAM_GetHitCount(bpp, (u8)turnAgo) != 0) {
            BTL_POKEPARAM_GetHitRecord(bpp, (u8)turnAgo, (int)0, (u16 *)(&scratch[6]));
            attackerId = scratch[0xb];
            if (BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, attackerId) == BTL_SLOT_NONE) {
                side = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
                candidateCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(0x100 | side), scratch);
                if (candidateCount != 0)
                    attackerId = scratch[(u8)BTL_CALC_Random(candidateCount)];
                else
                    attackerId = BTL_POKEID_NONE;
            }
            return attackerId;
        }
    }
    return BTL_POKEID_NONE;
}

/* Bide: when the storing status is on, cures it and clears the flag. */
void HAND_WAZA_BideCureStoringState(struct BtlSvFlow *flow, int pokeId, struct BideWork *work)
{
    struct HandExCureSick *record;

    if (work->storing != 0) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
        record->sickKind = BTL_SICK_BIDE;
        record->pokeCount = 1;
        record->pokeIds[0] = pokeId;
        record->suppressMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        work->storing = 0;
    }
}

/* Recycle (move 278): handler table, 1 row. */
int *HAND_WAZA_GetRecycleHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRecycleHandlers;
}

/* Recycle, event 0xa0: if the user holds nothing and consumed an item, gives it back with a message. */
void HAND_WAZA_RecycleRestoreItem(BTL_EVENT_SIGNATURE)
{
    struct BtlPokeParam *bpp;
    int consumedItem;
    struct HandExSetItem *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetItem(bpp) == 0) {
            consumedItem = BTL_POKEPARAM_GetConsumedItem(bpp);
            if (consumedItem != 0) {
                record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_ITEM, pokeId);
                record->itemId = consumedItem;
                record->pokeId = pokeId;
                record->announce = 1;
                BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_RECYCLE);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, consumedItem);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            }
        }
    }
}

/* Psycho Shift (move 375): handler table, 1 row. */
int *HAND_WAZA_GetPsychoShiftHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPsychoShiftHandlers;
}

/*
 * Psycho Shift, event 0xa0: moves the major status of the user to a target that has none.
 * Frame: 0x1c bytes of locals needs the two BTL_POKEPARAM_GetMajorStatusIndex calls and
 * BTLV_CORE_MakeSlotKind1Index15 declared as returning a one-word struct (OneWordResult); see
 * docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md.
 * OneWordResult on BTL_POKEPARAM_GetSickContRaw or BTL_CALC_MakeDefaultSickCont as well gives a larger frame.
 */
void HAND_WAZA_PsychoShiftTransferStatus(BTL_EVENT_SIGNATURE)
{
    struct BtlPokeParam *userBpp;
    int sickKind;
    u8 targetId;
    int sickCont;
    struct HandExAddSick *addSick;
    struct HandExCureSick *cureSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        userBpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        sickKind = BTL_POKEPARAM_GetMajorStatusIndex(userBpp).value;
        if (sickKind != 0) {
            targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
            if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, targetId)).value == 0) {
                sickCont = BTL_POKEPARAM_GetSickContRaw(userBpp, sickKind);
                addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
                addSick->sickKind = sickKind;
                if (sickKind == BTL_SICK_POISON && BTLV_CORE_IsSlotKind1Index15(sickCont) != 0)
                    addSick->sickCont = BTLV_CORE_MakeSlotKind1Index15();
                else
                    addSick->sickCont.value = BTL_CALC_MakeDefaultSickCont(sickKind);
                addSick->pokeId = targetId;
                addSick->replaceExisting = 1;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
                cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
                cureSick->sickKind = sickKind;
                cureSick->pokeCount = 1;
                cureSick->pokeIds[0] = pokeId;
                cureSick->header |= HANDEX_FLAG_SILENT;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
                BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 0);
            }
        }
    }
}

/* Pain Split (move 220): handler table, 1 row. */
int *HAND_WAZA_GetPainSplitHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPainSplitHandlers;
}

/* Pain Split, event 0xa0: both Pokemon end with the average of their current HP. */
void HAND_WAZA_PainSplitAverageHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *userBpp;
    struct BtlPokeParam *targetBpp;
    u32 userHp;
    u32 targetHp;
    u32 averageHp;
    struct HandExChangeHp *changeHp;
    struct HandExMessageRecord *message;
    struct HandExRefreshHpGauge *gauge;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
    userBpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    targetBpp = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
    userHp = func_021D59B4(userBpp, BPP_VALUE_HP);
    targetHp = func_021D59B4(targetBpp, BPP_VALUE_HP);
    averageHp = (userHp + targetHp) / 2;
    changeHp = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_HP, pokeId);
    changeHp->pokeCount = 2;
    changeHp->pokeIds[0] = pokeId;
    changeHp->amounts[0] = averageHp - userHp;
    changeHp->pokeIds[1] = targetId;
    changeHp->amounts[1] = averageHp - targetHp;
    changeHp->updateGauge = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, changeHp);
    message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&message->message, BTL_MSG_KIND_STD, HAND_WAZA_STR_PAIN_SPLIT);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    gauge = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REFRESH_HP_GAUGE, pokeId);
    gauge->pokeId = pokeId;
    gauge->mode = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, gauge);
    gauge = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REFRESH_HP_GAUGE, pokeId);
    gauge->pokeId = targetId;
    gauge->mode = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, gauge);
}

/* Belly Drum (move 187): handler table, 1 row (its handler is the first function of the next unit). */
u32 *HAND_WAZA_GetBellyDrumHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gBellyDrumHandlers;
}
