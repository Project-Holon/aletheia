/*
 * file:     hand_waza_021e15e8.c
 * unit:     yes
 * function: HAND_WAZA_PsywaveOnCalcFixedDamage, HAND_WAZA_AddStockpile, HAND_WAZA_StockpileOnMoveFailCheck, HAND_WAZA_StockpileOnMoveEffect, HAND_WAZA_StockpileUseOnMoveFailCheck, HAND_WAZA_SpitUpOnGetMovePower, HAND_WAZA_StockpileUseOnMoveEnd
 * address:  0x021E15E8
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
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   gSpitUpHandlers 0x021F2BD0 data a4
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gSwallowHandlers 0x021F2BE8 data a4
 *   gStockpileHandlers     0x021F2948  data   ov093  a4
 */
#include "hand_waza_021e10d8_types.h"

void HAND_WAZA_PsywaveOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddStockpile(int *handlerCount);
void HAND_WAZA_StockpileOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_StockpileOnMoveEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSpitUp(int *handlerCount);
void HAND_WAZA_StockpileUseOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_SpitUpOnGetMovePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_StockpileUseOnMoveEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSwallow(int *handlerCount);
extern BtlEventHandler gSpitUpHandlers[];
extern BtlEventHandler gSwallowHandlers[];
extern BtlEventHandler gStockpileHandlers[];

#define STOCKPILE_MAX 3

/* Psywave, event CALC_FIXED_DAMAGE: level times a random 50 to 150 percent, at least 1. */
void HAND_WAZA_PsywaveOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    u8 level;
    u16 percent;
    u16 damage;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        level = func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_VALUE_LEVEL);
        percent = BTL_CALC_Random(101) + 50;
        damage = (level * percent) / 100;
        if (damage == 0) damage = 1;
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, damage);
    }
}

/* Stockpile: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddStockpile(int *handlerCount)
{
    *handlerCount = 2;
    return gStockpileHandlers;
}

/* Stockpile, event MOVE_FAIL_CHECK: fails when the user has stockpiled three times. */
void HAND_WAZA_StockpileOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID) && BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_COUNTER_STOCKPILE) >= STOCKPILE_MAX)
        BTL_EVENT_OverwriteVar(HANDVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
}

/*
 * Stockpile, event MOVE_EFFECT: counts one more stockpile, shows the message
 * and raises Defense and Special Defense by one stage each; the two stat
 * counters only count when the stage really rose.
 * Lever: zeroOrCount is 0 (counter index) first and the new stockpile count later.
 */
void HAND_WAZA_StockpileOnMoveEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *poke;
    struct HandExSetCounter *setCounter;
    struct HandExMessageRecord *messageRecord;
    struct HandExRankChange *rank;
    u32 stockpile;
    int zeroOrCount;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        zeroOrCount = 0;
        stockpile = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE);
        if (stockpile >= STOCKPILE_MAX) return;
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->pokeId = pokeId;
        setCounter->counterIndex = zeroOrCount;
        zeroOrCount = stockpile + 1;
        setCounter->value = zeroOrCount;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x2d1);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, zeroOrCount);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->pokeCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_DEFENSE;
        rank->volume = 1;
        rank->flagB = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->header |= HANDEX_FLAG_AFTER_SUCCESS;
        setCounter->pokeId = pokeId;
        setCounter->counterIndex = BPP_COUNTER_STOCKPILE_DEFENSE;
        setCounter->value = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE_DEFENSE) + 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->pokeCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_SP_DEFENSE;
        rank->volume = 1;
        rank->flagB = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->header |= HANDEX_FLAG_AFTER_SUCCESS;
        setCounter->pokeId = pokeId;
        setCounter->counterIndex = BPP_COUNTER_STOCKPILE_SP_DEFENSE;
        setCounter->value = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE_SP_DEFENSE) + 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
    }
}

/* Spit Up: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSpitUp(int *handlerCount)
{
    *handlerCount = 3;
    return gSpitUpHandlers;
}

/* Spit Up and Swallow, event MOVE_FAIL_CHECK: fails when the user has not stockpiled. */
void HAND_WAZA_StockpileUseOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID) && BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_COUNTER_STOCKPILE) == 0)
        BTL_EVENT_OverwriteVar(HANDVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
}

static inline void SetBasePower(int power)
{
    BTL_EVENT_OverwriteVar(HANDVAR_BASE_POWER, power);
}

/*
 * Spit Up, event GET_MOVE_POWER: 100 power for each stockpile.
 * Lever: the product passed through a static inline helper is computed before the
 * helper's constant first argument is loaded (no result copy).
 */
void HAND_WAZA_SpitUpOnGetMovePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        SetBasePower(BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_COUNTER_STOCKPILE) * 100);
}

/*
 * Spit Up and Swallow, event MOVE_END: takes back the Defense and Special
 * Defense that the stockpiles gave, shows the message and resets the counters.
 */
void HAND_WAZA_StockpileUseOnMoveEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *poke;
    int defenseStages;
    int spDefenseStages;
    int stockpile;
    struct HandExRankChange *rank;
    struct HandExSetCounter *setCounter;
    struct HandExMessageRecord *messageRecord;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_POKE_ID)) return;
    poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    defenseStages = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE_DEFENSE);
    spDefenseStages = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE_SP_DEFENSE);
    stockpile = BTL_POKEPARAM_GetCounter(poke, BPP_COUNTER_STOCKPILE);
    if (defenseStages != 0) {
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->pokeCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_DEFENSE;
        rank->volume = -defenseStages;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->pokeId = pokeId;
        setCounter->counterIndex = BPP_COUNTER_STOCKPILE_DEFENSE;
        setCounter->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
    }
    if (spDefenseStages != 0) {
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
        rank->pokeCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_SP_DEFENSE;
        rank->volume = -spDefenseStages;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->pokeId = pokeId;
        setCounter->counterIndex = BPP_COUNTER_STOCKPILE_SP_DEFENSE;
        setCounter->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
    }
    if (stockpile != 0) {
        setCounter = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_COUNTER, pokeId);
        setCounter->pokeId = pokeId;
        setCounter->counterIndex = BPP_COUNTER_STOCKPILE;
        setCounter->value = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setCounter);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 724);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}

/* Swallow (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSwallow(int *handlerCount)
{
    *handlerCount = 3;
    return gSwallowHandlers;
}
