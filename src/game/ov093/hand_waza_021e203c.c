/*
 * file:     hand_waza_021e203c.c
 * unit:     yes
 * function: HAND_WAZA_PayDayScatterCoins, HAND_WAZA_RageGetHandlers, HAND_WAZA_RageKeepOnExecute, HAND_WAZA_RageRaiseAttackOnHit, HAND_WAZA_RageEndOnActionStart, HAND_WAZA_AquaRingGetHandlers
 * address:  0x021E203C
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_TryAddMainCounter  0x021C83E8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerOfPoke  0x021E03D8  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gRageHandlers     0x021F2C78  data   ov093  a4
 *   gAquaRingHandlers     0x021F2514  data   ov093  a4
 */
#include "hand_waza_021e1c8c_types.h"

extern int func_021D59B4(struct BtlPokeParam *poke, int valueId);
extern int BTL_SERVER_FLOW_TryAddMainCounter(struct BtlSvFlow *flow, int coins, int pokeId);
extern void HAND_WAZA_RemoveMoveHandlerOfPoke(struct BtlPokeParam *poke, int key);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *poke);

void HAND_WAZA_PayDayScatterCoins(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_RageGetHandlers(int *handlerCount);
void HAND_WAZA_RageKeepOnExecute(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
void HAND_WAZA_RageRaiseAttackOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_RageEndOnActionStart(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work);
BtlEventHandler *HAND_WAZA_AquaRingGetHandlers(int *handlerCount);
extern BtlEventHandler gRageHandlers[]; /* Rage handler table */
extern BtlEventHandler gAquaRingHandlers[]; /* Aqua Ring handler table */


/* Pay Day, move hit event: scatter coins worth five times the user's level. */
void HAND_WAZA_PayDayScatterCoins(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int level;
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        level = func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_VALUE_LEVEL);
        if (BTL_SERVER_FLOW_TryAddMainCounter(flow, level * 5, pokeId) != 0) {
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_STD, 0x7a);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        }
    }
}


/* Rage handler table getter: three handlers. */
BtlEventHandler *HAND_WAZA_RageGetHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gRageHandlers;
}


/* Rage, move execute query: using Rage again keeps the rage; any other move ends it. */
void HAND_WAZA_RageKeepOnExecute(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    int usedMoveId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        usedMoveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (usedMoveId == BTL_EVENT_GetFactorKey(factor)) {
            work->active = 1;
            return;
        }
        HAND_WAZA_RemoveMoveHandlerOfPoke(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_EVENT_GetFactorKey(factor));
    }
}




/* Rage, damage end event: while the rage lasts, being hit raises Attack by one stage. */
void HAND_WAZA_RageRaiseAttackOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExRankEffect *rank;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0 && BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0) {
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->statId = BTL_RANK_ATTACK;
        rank->amount = 1;
        rank->showMessage = 0;
        rank->targetCount = 1;
        rank->targets[0] = pokeId;
        rank->fromMove = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&rank->str, HANDEX_STR_SET, 0x214);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rank->str, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
    }
}




/* Rage, action start event: the rage ends when the Pokemon starts its next action. */
void HAND_WAZA_RageEndOnActionStart(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->active != 0)
        HAND_WAZA_RemoveMoveHandlerOfPoke(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_EVENT_GetFactorKey(factor));
}


/* Aqua Ring handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_AquaRingGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gAquaRingHandlers;
}
