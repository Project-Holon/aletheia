/*
 * file:     hand_waza_021e2188.c
 * unit:     yes
 * function: HAND_WAZA_AquaRingApplyEffect, HAND_WAZA_ThrashGetHandlers, HAND_WAZA_ThrashStartLock, HAND_WAZA_ThrashAdvanceTurn, HAND_WAZA_ThrashEndOnSleep, HAND_WAZA_UproarGetHandlers, HAND_WAZA_UproarStart, HAND_WAZA_UproarEndOnFailure, HAND_WAZA_UproarOnTurnEnd, HAND_WAZA_UproarPreventSleep, HAND_WAZA_UproarPreventSleepSilently, HAND_WAZA_RolloutGetHandlers, HAND_WAZA_RolloutStartLock, HAND_WAZA_RolloutEndOnDoneOrFail, HAND_WAZA_RolloutEndOnMoveEnd, HAND_WAZA_RolloutEndLock, HAND_WAZA_RolloutScalePower, HAND_WAZA_TripleKickRaisePower, HAND_WAZA_TripleKickCheckEachHit, HAND_WAZA_GyroBallGetHandlers, HAND_WAZA_GyroBallCalcPower, HAND_WAZA_RevengeGetHandlers
 * address:  0x021E2188
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerOfPoke  0x021E03D8  thumb  ov093
 *   gThrashHandlers     0x021F2C90  data   ov093  a4
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke 0x021C7D00 thumb ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds 0x021C7F68 thumb ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gUproarHandlers     0x021F2E78  data   ov093  a4
 *   HAND_WAZA_RemoveMoveHandlerById  0x021E03F8  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   gTripleKickHandlers     0x021F29C8  data   ov093  a4
 *   gRolloutHandlers     0x021F2EA0  data   ov093  a4
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper  0x021C81C8  thumb  ov093
 *   _s32_div_f     0x0209C0A4  arm
 *   gRevengeHandlers     0x021F2474  data   ov093  a4
 *   gGyroBallHandlers     0x021F248C  data   ov093  a4
 */
#include "hand_waza_021e1c8c_types.h"

extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *poke, int sickId);
extern int BTLV_CORE_MakeSlotKind1Empty(void);
extern u32 BTL_CALC_Random(u32 range);
extern void BTL_CALC_MakeSickContFromKind(int sickKind, struct BtlPokeParam *poke, union SickCont *out);
extern void HAND_WAZA_RemoveMoveHandlerOfPoke(struct BtlPokeParam *poke, int key);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(struct BtlSvFlow *flow, int pokeId);
extern HandPokeList *BTL_SERVER_FLOW_GetScratchBuffer(struct BtlSvFlow *flow, int slot);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(struct BtlSvFlow *flow, int targetCode, u8 *pokeIds);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *poke);
extern void HAND_WAZA_RemoveMoveHandlerById(int pokeId, int key);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *poke, u32 flagId);
extern void BTLV_CORE_EventScaleDamage(int ratio);
extern u16 BTL_SERVER_FLOW_CalcPokeSpeedWrapper(struct BtlSvFlow *flow, struct BtlPokeParam *poke, int flag);

void HAND_WAZA_AquaRingApplyEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_ThrashGetHandlers(int *handlerCount);
void HAND_WAZA_ThrashStartLock(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_ThrashAdvanceTurn(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_ThrashEndOnSleep(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_UproarGetHandlers(int *handlerCount);
void HAND_WAZA_UproarStart(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, HandWazaWork *work);
void HAND_WAZA_UproarEndOnFailure(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_UproarOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_UproarPreventSleep(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_UproarPreventSleepSilently(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
BtlEventHandler *HAND_WAZA_RolloutGetHandlers(int *handlerCount);
void HAND_WAZA_RolloutStartLock(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RolloutEndOnDoneOrFail(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RolloutEndOnMoveEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RolloutEndLock(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RolloutScalePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
BtlEventHandler *HAND_WAZA_TripleKickGetHandlers(int *handlerCount);
void HAND_WAZA_TripleKickRaisePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_TripleKickCheckEachHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_GyroBallGetHandlers(int *handlerCount);
void HAND_WAZA_GyroBallCalcPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_RevengeGetHandlers(int *handlerCount);
extern BtlEventHandler gThrashHandlers[]; /* Thrash, Petal Dance and Outrage handler table */
/*
 * lever: Word return from BTLV_CORE_MakeSlotKind2 reserves the unused aggregate slot;
 * u8 pokeId in the Uproar start handler schedules its stack reload after the zero store at 021E23CE.
 */
extern BtlEventHandler gUproarHandlers[]; /* Uproar handler table */
extern BtlEventHandler gTripleKickHandlers[]; /* Triple Kick handler table */
extern BtlEventHandler gRolloutHandlers[]; /* Rollout and Ice Ball handler table */
extern BtlEventHandler gRevengeHandlers[]; /* Revenge and Avalanche handler table */
extern BtlEventHandler gGyroBallHandlers[]; /* Gyro Ball handler table */




/* Aqua Ring, status move effect: add the Aqua Ring condition unless the user has it. */
void HAND_WAZA_AquaRingApplyEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExAddSick *addSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_AQUA_RING) == 0) {
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->sickKind = BTL_SICK_AQUA_RING;
            addSick->sickCont.raw = BTLV_CORE_MakeSlotKind1Empty();
            addSick->pokeId = pokeId;
            BTL_SERVER_FLOW_InitMsgRecord(&addSick->str, HANDEX_STR_SET, 0x259);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&addSick->str, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
        }
    }
}




/* Thrash, Petal Dance and Outrage handler table getter: three handlers. */
BtlEventHandler *HAND_WAZA_ThrashGetHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gThrashHandlers;
}




/*
 * Thrash family, move execute query: lock the user into the move for two or
 * three turns, unless it is locked already.
 * Lever: BTLV_CORE_MakeSlotKind2 returns a one-word struct, which reserves the
 * third frame word (`sub sp, #0xc` with push {r4-r7, lr}); see
 * docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md.
 */
void HAND_WAZA_ThrashStartLock(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    HandExAddSick *addSick;
    u8 lockTurns;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_MOVE_LOCK) == 0 && work->active == 0) {
            lockTurns = BTL_CALC_Random(2) + 2;
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->sickKind = BTL_SICK_MOVE_LOCK;
            addSick->sickCont = BTLV_CORE_MakeSlotKind2(lockTurns, BTL_EVENT_GetFactorKey(factor));
            addSick->suppressMessage = 0;
            addSick->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            work->active = 1;
            work->count = lockTurns;
        }
    }
}






/*
 * Thrash family, move end event: count down the lock. A failed move ends it;
 * when the turns run out the user becomes confused.
 */
void HAND_WAZA_ThrashAdvanceTurn(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    struct BtlPokeParam *poke;
    HandExCureSick *cureSick;
    HandExAddSick *addSick;
    int removeFactor;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (work->active != 0) {
            removeFactor = 0;
            if (work->count != 0)
                work->count = work->count - 1;
            if (BTL_EVENT_GetVar(BTL_EVAR_RESULT_FLAG) == 0) {
                cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
                cureSick->sickKind = BTL_SICK_MOVE_LOCK;
                removeFactor = 1;
                cureSick->pokeCount = 1;
                cureSick->pokeIds[0] = pokeId;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
            }
            if (work->count == 0) {
                addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
                addSick->sickKind = BTL_SICK_CONFUSION;
                BTL_CALC_MakeSickContFromKind(BTL_SICK_CONFUSION, poke, &addSick->sickCont);
                removeFactor = 1;
                addSick->fromMove = 1;
                addSick->pokeId = pokeId;
                BTL_SERVER_FLOW_InitMsgRecord(&addSick->str, HANDEX_STR_SET, 0x168);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&addSick->str, pokeId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            }
            if (removeFactor != 0)
                HAND_WAZA_RemoveMoveHandlerOfPoke(poke, BTL_EVENT_GetFactorKey(factor));
        }
    }
}






/* Thrash family, turn end event: a sleeping user loses the lock and the factor ends. */
void HAND_WAZA_ThrashEndOnSleep(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    HandExCureSick *cureSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_HasSick(poke, BTL_SICK_SLEEP) != 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->sickKind = BTL_SICK_MOVE_LOCK;
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
            HAND_WAZA_RemoveMoveHandlerOfPoke(poke, BTL_EVENT_GetFactorKey(factor));
        }
    }
}



/* Uproar handler table getter: five handlers. */
BtlEventHandler *HAND_WAZA_UproarGetHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gUproarHandlers;
}



/*
 * Uproar, move hit event: lock the user into the move for three turns, show
 * the uproar message and wake every sleeping Pokemon.
 */
void HAND_WAZA_UproarStart(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, HandWazaWork *work)
{
    HandExAddSick *addSick;
    HandExMessage *message;
    HandExCureSick *cureSick;
    HandPokeList *pokeList;
    u32 position;
    unsigned i;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) return;
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_MOVE_LOCK) != 0) return;
    if (work->active != 0) return;
    addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
    addSick->sickKind = BTL_SICK_MOVE_LOCK;
    addSick->sickCont = BTLV_CORE_MakeSlotKind2(3, BTL_EVENT_GetFactorKey(factor));
    addSick->suppressMessage = 0;
    addSick->pokeId = pokeId;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
    message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, 703);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    position = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId);
    pokeList = BTL_SERVER_FLOW_GetScratchBuffer(flow, 7);
    pokeList->count = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(position | BTL_TARGET_CODE_ALL_POKES), pokeList->pokeIds);
    for (i = 0; i < pokeList->count; i++) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeList->pokeIds[i]), BTL_SICK_SLEEP) != 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->sickKind = BTL_SICK_SLEEP;
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeList->pokeIds[i];
            BTL_SERVER_FLOW_InitMsgRecord(&cureSick->str, HANDEX_STR_SET, 706);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cureSick->str, pokeList->pokeIds[i]);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
        }
    }
    work->active = 1;
}





/* Uproar, move end event: a failed move ends the lock. */
void HAND_WAZA_UproarEndOnFailure(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExCureSick *cureSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_RESULT_FLAG) == 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->sickKind = BTL_SICK_MOVE_LOCK;
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
        }
    }
}





/*
 * Uproar, turn end event: while the lock lasts the uproar goes on; when it
 * has ended the Pokemon calms down and the factor is removed.
 */
void HAND_WAZA_UproarOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    struct BtlPokeParam *poke;
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->active != 0) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_IsFainted(poke) == 0) {
            if (BTL_POKEPARAM_HasSick(poke, BTL_SICK_MOVE_LOCK) == 0) {
                message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
                BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, 0x2CE);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, pokeId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
                HAND_WAZA_RemoveMoveHandlerOfPoke(poke, BTL_EVENT_GetFactorKey(factor));
            } else {
                message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
                BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, 0x2CB);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, pokeId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
            }
        }
    }
}





/* Uproar, sick blocked query: while it lasts, a Pokemon cannot fall asleep; show why. */
void HAND_WAZA_UproarPreventSleep(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    HandExMessage *message;
    u8 defenderId;

    if (work->active != 0 && BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) == BTL_SICK_SLEEP && BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1) != 0) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, (u16)(defenderId == pokeId ? 0x2C8 : 0x2C5));
        BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, defenderId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    }
}




/* Uproar, obedience override event: while it lasts, the prevent flag is set. */
void HAND_WAZA_UproarPreventSleepSilently(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    if (work->active != 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
}



/* Rollout and Ice Ball handler table getter: five handlers. */
BtlEventHandler *HAND_WAZA_RolloutGetHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gRolloutHandlers;
}



/* Rollout and Ice Ball, move execute query: lock the user into the move for five hits. */
void HAND_WAZA_RolloutStartLock(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    struct BtlPokeParam *poke;
    HandExAddSick *addSick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_HasSick(poke, BTL_SICK_MOVE_LOCK) == 0 && BTL_POKEPARAM_HasSick(poke, BTL_SICK_SLEEP) == 0 && work->active == 0) {
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->sickKind = BTL_SICK_MOVE_LOCK;
            addSick->sickCont = BTLV_CORE_MakeSlotKind2(5, BTL_EVENT_GetFactorKey(factor));
            addSick->suppressMessage = 0;
            addSick->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            work->count = 0;
            work->limit = 5;
            work->active = 1;
        }
    }
}








/* Rollout and Ice Ball, move done and move failed events: the lock ends. */
void HAND_WAZA_RolloutEndOnDoneOrFail(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_WAZA_RolloutEndLock(factor, flow, pokeId, work);
}








/* Rollout and Ice Ball, move end event: a failed move ends the lock. */
void HAND_WAZA_RolloutEndOnMoveEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_RESULT_FLAG) == 0)
            HAND_WAZA_RolloutEndLock(factor, flow, pokeId, work);
    }
}







/* Rollout and Ice Ball: cure the lock and remove the factors of the move. */
void HAND_WAZA_RolloutEndLock(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    HandExCureSick *cureSick;

    cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
    cureSick->pokeIds[0] = pokeId;
    cureSick->pokeCount = 1;
    cureSick->sickKind = BTL_SICK_MOVE_LOCK;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
    work->active = 0;
    HAND_WAZA_RemoveMoveHandlerById(pokeId, BTL_EVENT_GetFactorKey(factor));
}







/*
 * Rollout and Ice Ball, base power event: the power doubles with every hit
 * already made and once more when Defense Curl was used; the factor ends
 * after the last hit.
 */
void HAND_WAZA_RolloutScalePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    struct BtlPokeParam *poke;
    u32 i;
    int ratio;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        ratio = 1;
        for (i = 0; i < work->count; i++)
            ratio <<= 1;
        if (BTL_POKEPARAM_TestContFlag(poke, BTL_CONT_FLAG_DEFENSE_CURL))
            ratio <<= 1;
        BTLV_CORE_EventScaleDamage(ratio);
        work->count++;
        if ((int)work->count >= work->limit)
            HAND_WAZA_RemoveMoveHandlerById(pokeId, BTL_EVENT_GetFactorKey(factor));
    }
}







/* Triple Kick handler table getter: two handlers. */
BtlEventHandler *HAND_WAZA_TripleKickGetHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gTripleKickHandlers;
}





/* Triple Kick, base power event: ten times the number of the hit. */
void HAND_WAZA_TripleKickRaisePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    int hitNumber;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        hitNumber = work->count + 1;
        work->count = hitNumber;
        BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, hitNumber * 10);
    }
}




/* 021E278C  Triple Kick, multi-hit count event: check accuracy for every hit */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E27A2; movs r0, #0x42; movs r1, #1; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
void HAND_WAZA_TripleKickCheckEachHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_CHECK_EACH_HIT_FLAG, 1);
}



/* Gyro Ball handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_GyroBallGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gGyroBallHandlers;
}



/* Gyro Ball, base power event: 25 times the target speed over the user speed, plus one, at most 150. */
void HAND_WAZA_GyroBallCalcPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *userPoke;
    struct BtlPokeParam *targetPoke;
    int userSpeed;
    int targetSpeed;
    u32 power;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        userPoke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        targetPoke = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        userSpeed = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(flow, userPoke, 0);
        targetSpeed = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(flow, targetPoke, 0);
        power = targetSpeed * 25 / userSpeed + 1;
        if (power > 0x96)
            power = 0x96;
        BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, power);
    }
}



/* Revenge and Avalanche handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_RevengeGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRevengeHandlers;
}
