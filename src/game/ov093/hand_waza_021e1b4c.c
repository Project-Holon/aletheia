/*
 * file:     hand_waza_021e1b4c.c
 * unit:     yes
 * function: HAND_WAZA_LastResortOnMoveFailCheck, HAND_WAZA_AddSnore, HAND_WAZA_SnoreOnActionCheck, HAND_WAZA_SnoreOnMoveFailCheck, HAND_WAZA_AddNightmare, HAND_WAZA_NightmareOnNoEffectCheck, HAND_WAZA_AddSuckerPunch
 * address:  0x021E1B4C
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
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   BTL_POKEPARAM_GetMoveUsedFlag  0x021D54E0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   gSnoreHandlers     0x021F2978  data   ov093  a4
 *   gNightmareHandlers     0x021F24DC  data   ov093  a4
 *   gSuckerPunchHandlers     0x021F24B4  data   ov093  a4
 */
#include "hand_waza_021e10d8_types.h"

#define MOVE_LAST_RESORT 0x183

void HAND_WAZA_LastResortOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSnore(int *handlerCount);
void HAND_WAZA_SnoreOnActionCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_SnoreOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddNightmare(int *handlerCount);
void HAND_WAZA_NightmareOnNoEffectCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSuckerPunch(int *handlerCount);
extern BtlEventHandler gSnoreHandlers[];
extern BtlEventHandler gNightmareHandlers[];
extern BtlEventHandler gSuckerPunchHandlers[];

/*
 * Last Resort, event MOVE_FAIL_CHECK: fails unless the user knows Last Resort,
 * knows at least two moves and has used every other move.
 */
void HAND_WAZA_LastResortOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *poke;
    u8 moveCount;
    u8 slot;
    u8 usedCount;
    int hasLastResort;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        moveCount = BTL_POKEPARAM_GetMoveCount(poke);
        usedCount = 0;
        hasLastResort = 0;
        for (slot = 0; slot < moveCount; slot++) {
            if (BTL_POKEPARAM_GetMoveId(poke, slot) == MOVE_LAST_RESORT) {
                hasLastResort = 1;
            } else if (BTL_POKEPARAM_GetMoveUsedFlag(poke, slot)) {
                usedCount++;
            }
        }
        if (hasLastResort == 0 || moveCount < 2 || usedCount < moveCount - 1)
            BTL_EVENT_OverwriteVar(HANDVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}

/* Snore: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSnore(int *handlerCount)
{
    *handlerCount = 2;
    return gSnoreHandlers;
}

/* Snore, event ACTION_CHECK: sleep does not stop the user from using the move. */
void HAND_WAZA_SnoreOnActionCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID) && BTL_EVENT_GetVar(HANDVAR_FAIL_REASON) == BTL_FAIL_REASON_ASLEEP)
        BTL_EVENT_OverwriteVar(HANDVAR_GENERAL_FLAG, 1);
}

/* Snore, event MOVE_FAIL_CHECK: the move works only while the user is asleep. */
void HAND_WAZA_SnoreOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    int sickSleep = BTL_SICK_SLEEP;
    struct BtlPokeParam *poke;
    int failReasonKey;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        failReasonKey = HANDVAR_FAIL_REASON;
        if (BTL_EVENT_GetVar(failReasonKey) == BTL_FAIL_REASON_ASLEEP) {
            BTL_EVENT_OverwriteVar(failReasonKey, 0);
            return;
        }
        if (BTL_POKEPARAM_HasSick(poke, sickSleep) == 0)
            BTL_EVENT_OverwriteVar(failReasonKey, BTL_FAIL_REASON_MOVE_FAILED);
    }
}

/* Nightmare: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddNightmare(int *handlerCount)
{
    *handlerCount = 1;
    return gNightmareHandlers;
}

/* Nightmare, event NO_EFFECT_CHECK: no effect on a target that is not asleep. */
void HAND_WAZA_NightmareOnNoEffectCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    u8 defenderId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        defenderId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, defenderId), BTL_SICK_SLEEP) == 0)
            BTL_EVENT_OverwriteVar(HANDVAR_NO_EFFECT_FLAG, 1);
    }
}

/* Sucker Punch (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSuckerPunch(int *handlerCount)
{
    *handlerCount = 1;
    return gSuckerPunchHandlers;
}
