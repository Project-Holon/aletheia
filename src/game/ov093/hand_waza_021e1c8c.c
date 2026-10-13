/*
 * file:     hand_waza_021e1c8c.c
 * unit:     yes
 * function: HAND_WAZA_SuckerPunchCheckNoEffect, HAND_WAZA_PursuitGetHandlers, HAND_WAZA_PursuitQueueIntercept, HAND_WAZA_PursuitAlwaysHitOnIntercept, HAND_WAZA_PursuitDoublePowerOnIntercept, HAND_WAZA_SelfDestructGetHandlers, HAND_WAZA_SelfDestructFaintOnHit, HAND_WAZA_SelfDestructPushUserCmd, HAND_WAZA_SelfDestructFaintOnFinish, HAND_WAZA_FocusEnergyGetHandlers
 * address:  0x021E1C8C
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
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_SERVER_FLOW_GetActionWordByPokeId  0x021C804C  thumb  ov093
 *   BTL_ACTION_GetFightMove  0x021D8340  thumb  ov093
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_CheckAllyMoveAutoHitById  0x021C8290  thumb  ov093
 *   BTL_SERVER_FLOW_AppendFrontOrder  0x021C831C  thumb  ov093
 *   BTL_SERVER_FLOW_TestStateFlagBit0  0x021C830C  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   gPursuitHandlers     0x021F2C48  data   ov093  a4
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   gSelfDestructHandlers     0x021F2C60  data   ov093  a4
 *   gFocusEnergyHandlers     0x021F24FC  data   ov093  a4
 */
#include "hand_waza_021e1c8c_types.h"

extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *poke, u32 flagId);
extern int BTL_SERVER_FLOW_GetActionWordByPokeId(struct BtlSvFlow *flow, int pokeId, u32 *actionWord);
extern u32 BTL_ACTION_GetFightMove(u32 *actionWord);
extern u32 WAZA_TOOL_IsDamaging(u32 moveId);
extern int BTL_MAIN_IsPokeSamePair(unsigned int pokeIdA, unsigned int pokeIdB);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlSvFlow *flow, unsigned int pokeId);
extern int BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(struct BtlSvFlow *flow, int pokeIdA, int pokeIdB, void *item);
extern void BTL_SERVER_FLOW_AppendFrontOrder(struct BtlSvFlow *flow, int pokeId);
extern unsigned int BTL_SERVER_FLOW_TestStateFlagBit0(struct BtlSvFlow *flow);
extern void BTLV_CORE_EventScaleDamage(int ratio);
extern void BTL_SERVER_FLOW_PushCmdRecord(struct BtlSvFlow *flow, int cmdKind, int pokeId);

void HAND_WAZA_SuckerPunchCheckNoEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_PursuitGetHandlers(int *handlerCount);
void HAND_WAZA_PursuitQueueIntercept(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_PursuitAlwaysHitOnIntercept(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_PursuitDoublePowerOnIntercept(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_SelfDestructGetHandlers(int *handlerCount);
void HAND_WAZA_SelfDestructFaintOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_SelfDestructPushUserCmd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_SelfDestructFaintOnFinish(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_FocusEnergyGetHandlers(int *handlerCount);
extern BtlEventHandler gPursuitHandlers[]; /* Pursuit handler table */
extern BtlEventHandler gSelfDestructHandlers[]; /* Self-Destruct and Explosion handler table */
extern BtlEventHandler gFocusEnergyHandlers[]; /* Focus Energy handler table (first row; used by unit_021E1E38) */



/*
 * Sucker Punch, no-effect check: the move fails unless the target still has
 * to act this turn with a damaging move.
 * The 12-byte tail (movs r1,#3; str r1,[r0]; ldr r0,[pc]; bx lr; .word) is an
 * unlabelled follower stub, not part of this function.
 * Lever: targetPoke = BTL_SERVER_FLOW_GetPokeParam(...) bound to a local before `targetWillAttack = 0`
 * keeps the `movs r4, #0` between the argument setup and the BTL_POKEPARAM_TestTurnFlag call.
 */
void HAND_WAZA_SuckerPunchCheckNoEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u32 targetAction;
    u8 targetId;
    int targetWillAttack;
    struct BtlPokeParam *targetPoke;
    u32 targetMove;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        targetPoke = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        targetWillAttack = 0;
        if (BTL_POKEPARAM_TestTurnFlag(targetPoke, BTL_TURN_FLAG_ACTION_FINISHED) == 0) {
            if (BTL_SERVER_FLOW_GetActionWordByPokeId(flow, targetId, &targetAction) != 0 && (targetMove = BTL_ACTION_GetFightMove(&targetAction)) != 0 && WAZA_TOOL_IsDamaging(targetMove) != 0)
                targetWillAttack = 1;
        }
        if (targetWillAttack == 0) {
            if ((targetMove = BTL_ACTION_GetFightMove(&targetAction)) == 0 || WAZA_TOOL_IsDamaging(targetMove) == 0) {
                if (BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0)
                    BTL_SERVER_FLOW_InitMsgRecord((HandExStr *)BTL_EVENT_GetVar(BTL_EVAR_NO_EFFECT_STRING), HANDEX_STR_STD, 0x47);
            }
        }
    }
}



/* Pursuit handler table getter: three handlers. */
BtlEventHandler *HAND_WAZA_PursuitGetHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gPursuitHandlers;
}



/*
 * Pursuit, before-switch event: when the Pokemon that leaves is an opponent
 * and the move can reach it, put this Pokemon on the list of Pokemon that
 * strike first.
 */
void HAND_WAZA_PursuitQueueIntercept(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u32 actionWord;
    u8 switchingId;

    if (BTL_SERVER_FLOW_GetActionWordByPokeId(flow, pokeId, &actionWord) != 0) {
        switchingId = BTL_EVENT_GetVar(BTL_EVAR_SWITCHING_POKE_ID);
        if (BTL_MAIN_IsPokeSamePair(switchingId, pokeId) == 0) {
            BTL_SERVER_FLOW_GetPokeViewPos(flow, switchingId);
            BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
            if (BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(flow, pokeId, switchingId, 0) == 0)
                BTL_SERVER_FLOW_AppendFrontOrder(flow, pokeId);
        }
    }
}





/* Pursuit, always-hit query: a pursuit that interrupts a switch cannot miss. */
void HAND_WAZA_PursuitAlwaysHitOnIntercept(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_SERVER_FLOW_TestStateFlagBit0(flow))
        BTL_EVENT_OverwriteVar(BTL_EVAR_RESULT_FLAG, 1);
}




/* Pursuit, base power event: a pursuit that interrupts a switch hits with double power. */
void HAND_WAZA_PursuitDoublePowerOnIntercept(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_TestStateFlagBit0(flow) != 0)
            BTLV_CORE_EventScaleDamage(2);
    }
}


/* Self-Destruct and Explosion handler table getter: three handlers. */
BtlEventHandler *HAND_WAZA_SelfDestructGetHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gSelfDestructHandlers;
}


/* Self-Destruct and Explosion, move hit event: the user faints. */
void HAND_WAZA_SelfDestructFaintOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExFaint *faint;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        faint = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FAINT, pokeId);
        faint->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, faint);
    }
}




/* Self-Destruct and Explosion, move execute query: push the user's explosion command. */
void HAND_WAZA_SelfDestructPushUserCmd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_SERVER_FLOW_PushCmdRecord(flow, 0x3b, pokeId);
}




/* Self-Destruct and Explosion, move finished event: the user faints (also when the move missed). */
void HAND_WAZA_SelfDestructFaintOnFinish(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExFaint *faint;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        faint = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FAINT, pokeId);
        faint->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, faint);
    }
}


/* Focus Energy handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_FocusEnergyGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFocusEnergyHandlers;
}
