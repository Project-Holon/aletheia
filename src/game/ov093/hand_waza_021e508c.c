/*
 * file:     hand_waza_021e508c.c
 * unit:     yes
 * function: HAND_WAZA_PowerSplitOnUncategorizedMove, HAND_WAZA_GuardSplitOnUncategorizedMove, HAND_WAZA_LockOnOnUncategorizedMove, HAND_WAZA_AddReflect, HAND_WAZA_ReflectOnUncategorizedMoveNoTarget, HAND_WAZA_AddLightScreen
 * address:  0x021E508C
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
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gGuardSplitHandlers 0x021F2704 data a4
 *   gLockOnHandlers 0x021F26DC data a4
 *   BTLV_CORE_MakeSlotKind4  0x021E8A28  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   HAND_WAZA_AddSideEffect  0x021E556C  thumb  ov093
 *   gReflectHandlers     0x021F25FC  data   ov093  a4
 *   gLightScreenHandlers     0x021F259C  data   ov093  a4
 */
#include "hand_waza_021e4754_types.h"

#define BTL_STR_POWER_SPLIT 0x448
#define BTL_STR_GUARD_SPLIT 0x44b
#define BTL_STR_LOCK_ON 0x28b
#define BTL_LOCK_ON_TURNS 2
#define BTL_SIDE_EFFECT_STR_REFLECT 0x7c

void HAND_WAZA_PowerSplitOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddGuardSplit(int *handlerCount);
void HAND_WAZA_GuardSplitOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddLockOn(int *handlerCount);
void HAND_WAZA_LockOnOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddReflect(int *handlerCount);
void HAND_WAZA_ReflectOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddLightScreen(int *handlerCount);
extern BtlEventHandler gGuardSplitHandlers[];
extern BtlEventHandler gLockOnHandlers[];
extern BtlEventHandler gReflectHandlers[];
extern BtlEventHandler gLightScreenHandlers[];

/* Power Split: the user and the target both take the average of their attack and of their special attack. */
void HAND_WAZA_PowerSplitOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    int averageAttack;
    int averageSpAttack;
    struct HandExSetStats *statsRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        averageAttack = (func_021D58A8(user, BPP_VALUE_ATTACK) + func_021D58A8(target, BPP_VALUE_ATTACK)) / 2;
        averageSpAttack = (func_021D58A8(user, BPP_VALUE_SP_ATTACK) + func_021D58A8(target, BPP_VALUE_SP_ATTACK)) / 2;
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = targetId;
        statsRecord->attack = averageAttack;
        statsRecord->spAttack = averageSpAttack;
        statsRecord->setAttack = 1;
        statsRecord->setSpAttack = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = pokeId;
        statsRecord->attack = averageAttack;
        statsRecord->spAttack = averageSpAttack;
        statsRecord->setAttack = 1;
        statsRecord->setSpAttack = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&statsRecord->message, BTL_STRTYPE_SET, BTL_STR_POWER_SPLIT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&statsRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
    }
}

BtlEventHandler *HAND_WAZA_AddGuardSplit(int *handlerCount)
{
    *handlerCount = 1;
    return gGuardSplitHandlers;
}

/* Guard Split: the user and the target both take the average of their defense and of their special defense. */
void HAND_WAZA_GuardSplitOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    int averageDefense;
    int averageSpDefense;
    struct HandExSetStats *statsRecord;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        averageDefense = (func_021D58A8(user, BPP_VALUE_DEFENSE) + func_021D58A8(target, BPP_VALUE_DEFENSE)) / 2;
        averageSpDefense = (func_021D58A8(user, BPP_VALUE_SP_DEFENSE) + func_021D58A8(target, BPP_VALUE_SP_DEFENSE)) / 2;
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = targetId;
        statsRecord->defense = averageDefense;
        statsRecord->spDefense = averageSpDefense;
        statsRecord->setDefense = 1;
        statsRecord->setSpDefense = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
        statsRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_STATS, pokeId);
        statsRecord->pokeId = pokeId;
        statsRecord->defense = averageDefense;
        statsRecord->spDefense = averageSpDefense;
        statsRecord->setDefense = 1;
        statsRecord->setSpDefense = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&statsRecord->message, BTL_STRTYPE_SET, BTL_STR_GUARD_SPLIT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&statsRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, statsRecord);
    }
}

BtlEventHandler *HAND_WAZA_AddLockOn(int *handlerCount)
{
    *handlerCount = 1;
    return gLockOnHandlers;
}

/* Lock-On and Mind Reader: the user's next move cannot miss the target (status lasts 2 turns). */
void HAND_WAZA_LockOnOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct HandExAddSick *record;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
        record->pokeId = pokeId;
        record->sickKind = BTL_SICK_LOCK_ON;
        record->sickCont = BTLV_CORE_MakeSlotKind4(targetId, BTL_LOCK_ON_TURNS);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STRTYPE_SET, BTL_STR_LOCK_ON);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}

BtlEventHandler *HAND_WAZA_AddReflect(int *handlerCount)
{
    *handlerCount = 1;
    return gReflectHandlers;
}

/*
 * Reflect: a screen on the user's side for 5 turns.
 * The cont value is a one-word struct result (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 */
void HAND_WAZA_ReflectOnUncategorizedMoveNoTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    union BtlSickCont cont = BTLV_CORE_MakeSlotKind2Index(5);
    int side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
    HAND_WAZA_AddSideEffect(factor, flow, pokeId, work, side, BTL_SIDE_EFFECT_REFLECT, cont, BTL_SIDE_EFFECT_STR_REFLECT);
}

BtlEventHandler *HAND_WAZA_AddLightScreen(int *handlerCount)
{
    *handlerCount = 1;
    return gLightScreenHandlers;
}
