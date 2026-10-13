/*
 * file:     unit_021DD87C.c
 * unit:     yes
 * function: BTL_ITEM_RaiseAttackOne, BTL_ITEM_GetRaiseDefenseOneHandlers, BTL_ITEM_RaiseDefenseOne, BTL_ITEM_GetRaiseSpeedOneHandlers, BTL_ITEM_RaiseSpeedOne, BTL_ITEM_GetRaiseSpAttackOneHandlers, BTL_ITEM_RaiseSpAttackOne, BTL_ITEM_GetRaiseSpDefenseOneHandlers, BTL_ITEM_RaiseSpDefenseOne, BTL_ITEM_GetRaiseCriticalRateHandlers, BTL_ITEM_RaiseCriticalRate, BTL_ITEM_GetRaiseRandomStatHandlers, BTL_ITEM_RaiseRandomStatTwo, BTL_ITEM_RaiseStat, BTL_ITEM_GetSuperEffectiveHitRecoverHandlers, BTL_ITEM_RequestUseOnSuperEffectiveHit, BTL_ITEM_RecoverHpByMaxHpDivisor, BTL_ITEM_GetWeakenDamageFireHandlers
 * address:  0x021DD87C
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
 *   gBtlItemRaiseDefenseOneHandlers     0x021F1CF4  data   ov093  a4
 *   gBtlItemRaiseSpeedOneHandlers     0x021F1D1C  data   ov093  a4
 *   gBtlItemRaiseSpAttackOneHandlers     0x021F1D44  data   ov093  a4
 *   gBtlItemRaiseSpDefenseOneHandlers     0x021F1D6C  data   ov093  a4
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_TestContFlag   0x021D5BDC  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   BTL_EVENT_GetFactorKey   0x021D70A8  thumb ov093
 *   gBtlItemRaiseCriticalRateHandlers     0x021F1D94  data   ov093  a4
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   gBtlItemRaiseStatCandidates     0x021F1364  data  ov093  a1
 *   gBtlItemRaiseRandomStatHandlers     0x021F1DBC  data   ov093  a4
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_HANDLER_ITEM_PushUseItem  0x021DD044  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   gBtlItemSuperEffectiveHitRecoverHandlers     0x021F16CC  data   ov093  a4
 *   gBtlItemWeakenDamageFireHandlers     0x021F175C  data   ov093  a4
 */
#include "unit_021DD588_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *func_021C7CF4(void *server, int pokeId);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *pokeParam, u32 contFlag);
extern void *func_021C88A4(void *server, int cmdKind, int pokeId);
extern void func_021C88C8(void *server, void *cmd);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern u8 *func_021C8120(void *server, int size);
extern int func_021D5D14(struct BtlPokeParam *pokeParam, int statId, int amount);
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *pokeParam, int sickKind);
extern void BTL_HANDLER_ITEM_PushUseItem(struct BtlEventFactor *factor, void *server, int pokeId);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int index);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *pokeParam, u32 divisor);

extern int gBtlItemRaiseDefenseOneHandlers[];
extern int gBtlItemRaiseSpeedOneHandlers[];
extern int gBtlItemRaiseSpAttackOneHandlers[];
extern int gBtlItemRaiseSpDefenseOneHandlers[];
extern int gBtlItemRaiseCriticalRateHandlers[];
extern u8 gBtlItemRaiseStatCandidates[BTL_RANK_KIND_COUNT];
extern int gBtlItemRaiseRandomStatHandlers[];
extern int gBtlItemSuperEffectiveHitRecoverHandlers[];
extern int gBtlItemWeakenDamageFireHandlers[];

void BTL_ITEM_RaiseAttackOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ITEM_GetRaiseDefenseOneHandlers(int *handlerCount);
void BTL_ITEM_RaiseDefenseOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ITEM_GetRaiseSpeedOneHandlers(int *handlerCount);
void BTL_ITEM_RaiseSpeedOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ITEM_GetRaiseSpAttackOneHandlers(int *handlerCount);
void BTL_ITEM_RaiseSpAttackOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ITEM_GetRaiseSpDefenseOneHandlers(int *handlerCount);
void BTL_ITEM_RaiseSpDefenseOne(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ITEM_GetRaiseCriticalRateHandlers(int *handlerCount);
void BTL_ITEM_RaiseCriticalRate(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ITEM_GetRaiseRandomStatHandlers(int *handlerCount);
void BTL_ITEM_RaiseRandomStatTwo(struct BtlEventFactor *factor, void *server, u8 pokeId);
void BTL_ITEM_RaiseStat(void *server, int pokeId, int statId, int amount);
int *BTL_ITEM_GetSuperEffectiveHitRecoverHandlers(int *handlerCount);
void BTL_ITEM_RequestUseOnSuperEffectiveHit(struct BtlEventFactor *factor, void *server, int pokeId);
void BTL_ITEM_RecoverHpByMaxHpDivisor(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ITEM_GetWeakenDamageFireHandlers(int *handlerCount);

void BTL_ITEM_RaiseAttackOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    BTL_ITEM_RaiseStat(server, pokeId, BTL_RANK_ATTACK, 1);
}

int *BTL_ITEM_GetRaiseDefenseOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseDefenseOneHandlers;
}

void BTL_ITEM_RaiseDefenseOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    BTL_ITEM_RaiseStat(server, pokeId, BTL_RANK_DEFENSE, 1);
}

int *BTL_ITEM_GetRaiseSpeedOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseSpeedOneHandlers;
}

void BTL_ITEM_RaiseSpeedOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    BTL_ITEM_RaiseStat(server, pokeId, BTL_RANK_SPEED, 1);
}

int *BTL_ITEM_GetRaiseSpAttackOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseSpAttackOneHandlers;
}

void BTL_ITEM_RaiseSpAttackOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    BTL_ITEM_RaiseStat(server, pokeId, BTL_RANK_SP_ATTACK, 1);
}

int *BTL_ITEM_GetRaiseSpDefenseOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseSpDefenseOneHandlers;
}

void BTL_ITEM_RaiseSpDefenseOne(struct BtlEventFactor *factor, void *server, int pokeId)
{
    BTL_ITEM_RaiseStat(server, pokeId, BTL_RANK_SP_DEFENSE, 1);
}

int *BTL_ITEM_GetRaiseCriticalRateHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseCriticalRateHandlers;
}

void BTL_ITEM_RaiseCriticalRate(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HandExSetContFlag *flagCmd;
    HandExMessage *messageCmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (BTL_POKEPARAM_TestContFlag(func_021C7CF4(server, pokeId), BTL_CONT_FLAG_CRITICAL_UP) != 0)
        return;
    flagCmd = func_021C88A4(server, HANDEX_KIND_SET_CONT_FLAG, pokeId);
    flagCmd->pokeId = pokeId;
    flagCmd->flagId = BTL_CONT_FLAG_CRITICAL_UP;
    func_021C88C8(server, flagCmd);
    messageCmd = func_021C88A4(server, HANDEX_KIND_MESSAGE, pokeId);
    func_021C8838(&messageCmd->str, HANDEX_STR_SET, 1001);
    func_021C8860(&messageCmd->str, pokeId);
    func_021C8860(&messageCmd->str, BTL_EVENT_GetFactorKey(factor));
    func_021C88C8(server, messageCmd);
}

int *BTL_ITEM_GetRaiseRandomStatHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseRandomStatHandlers;
}

void BTL_ITEM_RaiseRandomStatTwo(struct BtlEventFactor *factor, void *server, u8 pokeId)
{
    struct BtlPokeParam *pokeParam = func_021C7CF4(server, pokeId);
    u8 *candidates = func_021C8120(server, BTL_RANK_KIND_COUNT);
    u32 candidateCount;
    u32 i;
    u8 statId;

    i = 0;
    candidateCount = 0;
    for (; i < BTL_RANK_KIND_COUNT; i++) {
        statId = gBtlItemRaiseStatCandidates[i];
        if (func_021D5D14(pokeParam, statId, 1) != 0)
            candidates[candidateCount++] = statId;
    }
    if (candidateCount != 0)
        BTL_ITEM_RaiseStat(server, pokeId, candidates[BTL_CALC_Random(candidateCount)], 2);
}

void BTL_ITEM_RaiseStat(void *server, int pokeId, int statId, int amount)
{
    HandExRankEffect *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        cmd = func_021C88A4(server, HANDEX_KIND_RANK_EFFECT, pokeId);
        cmd->rankKind = statId;
        cmd->volume = amount;
        cmd->pokeCount = 1;
        cmd->pokeId = pokeId;
        func_021C88C8(server, cmd);
    }
}

int *BTL_ITEM_GetSuperEffectiveHitRecoverHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemSuperEffectiveHitRecoverHandlers;
}

void BTL_ITEM_RequestUseOnSuperEffectiveHit(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0
        && BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE
        && BTL_POKEPARAM_HasSick(func_021C7CF4(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0)
        BTL_HANDLER_ITEM_PushUseItem(factor, server, pokeId);
}

void BTL_ITEM_RecoverHpByMaxHpDivisor(struct BtlEventFactor *factor, void *server, int pokeId)
{
    struct BtlPokeParam *pokeParam;
    HandExRecoverHp *cmd;
    u8 divisor;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        pokeParam = func_021C7CF4(server, pokeId);
        divisor = BTL_HANDLER_ITEM_GetParam(factor, 2);
        cmd = func_021C88A4(server, HANDEX_KIND_RECOVER_HP, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(pokeParam, divisor);
        func_021C88C8(server, cmd);
    }
}

int *BTL_ITEM_GetWeakenDamageFireHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageFireHandlers;
}
