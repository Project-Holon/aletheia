/*
 * file:     unit_021DD87C.c
 * unit:     yes
 * function: func_021DD87C, func_021DD88C, func_021DD898, func_021DD8A8, func_021DD8B4, func_021DD8C4, func_021DD8D0, func_021DD8E0, func_021DD8EC, func_021DD8FC, func_021DD908, func_021DD980, func_021DD98C, func_021DD9E8, func_021DDA1C, func_021DDA28, func_021DDA6C, func_021DDAB8
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
 *   d_021F1CF4     0x021F1CF4  data   ov093  a4
 *   d_021F1D1C     0x021F1D1C  data   ov093  a4
 *   d_021F1D44     0x021F1D44  data   ov093  a4
 *   d_021F1D6C     0x021F1D6C  data   ov093  a4
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5BDC   0x021D5BDC  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021D70A8   0x021D70A8  thumb ov093
 *   d_021F1D94     0x021F1D94  data   ov093  a4
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   d_021F1364     0x021F1364  data  ov093  a1
 *   d_021F1DBC     0x021F1DBC  data   ov093  a4
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   d_021F16CC     0x021F16CC  data   ov093  a4
 *   d_021F175C     0x021F175C  data   ov093  a4
 */
#include "unit_021DD588_types.h"

extern int func_021D775C(int varId);
extern struct BtlPokeParam *func_021C7CF4(void *server, int pokeId);
extern int func_021D5BDC(struct BtlPokeParam *pokeParam, u32 contFlag);
extern void *func_021C88A4(void *server, int cmdKind, int pokeId);
extern void func_021C88C8(void *server, void *cmd);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern u8 *func_021C8120(void *server, int size);
extern int func_021D5D14(struct BtlPokeParam *pokeParam, int statId, int amount);
extern u32 func_021D78AC(u32 range);
extern int func_021D62C4(struct BtlPokeParam *pokeParam, int sickKind);
extern void func_021DD044(struct BtlEventFactor *factor, void *server, int pokeId);
extern int func_021DCFF8(struct BtlEventFactor *factor, int index);
extern int func_021D7B74(struct BtlPokeParam *pokeParam, u32 divisor);

extern int d_021F1CF4[];
extern int d_021F1D1C[];
extern int d_021F1D44[];
extern int d_021F1D6C[];
extern int d_021F1D94[];
extern u8 d_021F1364[BTL_RANK_KIND_COUNT];
extern int d_021F1DBC[];
extern int d_021F16CC[];
extern int d_021F175C[];

void func_021DD87C(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021DD88C(int *handlerCount);
void func_021DD898(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021DD8A8(int *handlerCount);
void func_021DD8B4(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021DD8C4(int *handlerCount);
void func_021DD8D0(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021DD8E0(int *handlerCount);
void func_021DD8EC(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021DD8FC(int *handlerCount);
void func_021DD908(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021DD980(int *handlerCount);
void func_021DD98C(struct BtlEventFactor *factor, void *server, u8 pokeId);
void func_021DD9E8(void *server, int pokeId, int statId, int amount);
int *func_021DDA1C(int *handlerCount);
void func_021DDA28(struct BtlEventFactor *factor, void *server, int pokeId);
void func_021DDA6C(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021DDAB8(int *handlerCount);

void func_021DD87C(struct BtlEventFactor *factor, void *server, int pokeId)
{
    func_021DD9E8(server, pokeId, BTL_RANK_ATTACK, 1);
}

int *func_021DD88C(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F1CF4;
}

void func_021DD898(struct BtlEventFactor *factor, void *server, int pokeId)
{
    func_021DD9E8(server, pokeId, BTL_RANK_DEFENSE, 1);
}

int *func_021DD8A8(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F1D1C;
}

void func_021DD8B4(struct BtlEventFactor *factor, void *server, int pokeId)
{
    func_021DD9E8(server, pokeId, BTL_RANK_SPEED, 1);
}

int *func_021DD8C4(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F1D44;
}

void func_021DD8D0(struct BtlEventFactor *factor, void *server, int pokeId)
{
    func_021DD9E8(server, pokeId, BTL_RANK_SP_ATTACK, 1);
}

int *func_021DD8E0(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F1D6C;
}

void func_021DD8EC(struct BtlEventFactor *factor, void *server, int pokeId)
{
    func_021DD9E8(server, pokeId, BTL_RANK_SP_DEFENSE, 1);
}

int *func_021DD8FC(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F1D94;
}

void func_021DD908(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HandExSetContFlag *flagCmd;
    HandExMessage *messageCmd;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    if (func_021D5BDC(func_021C7CF4(server, pokeId), BTL_CONT_FLAG_CRITICAL_UP) != 0)
        return;
    flagCmd = func_021C88A4(server, HANDEX_KIND_SET_CONT_FLAG, pokeId);
    flagCmd->pokeId = pokeId;
    flagCmd->flagId = BTL_CONT_FLAG_CRITICAL_UP;
    func_021C88C8(server, flagCmd);
    messageCmd = func_021C88A4(server, HANDEX_KIND_MESSAGE, pokeId);
    func_021C8838(&messageCmd->str, HANDEX_STR_SET, 1001);
    func_021C8860(&messageCmd->str, pokeId);
    func_021C8860(&messageCmd->str, func_021D70A8(factor));
    func_021C88C8(server, messageCmd);
}

int *func_021DD980(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F1DBC;
}

void func_021DD98C(struct BtlEventFactor *factor, void *server, u8 pokeId)
{
    struct BtlPokeParam *pokeParam = func_021C7CF4(server, pokeId);
    u8 *candidates = func_021C8120(server, BTL_RANK_KIND_COUNT);
    u32 candidateCount;
    u32 i;
    u8 statId;

    i = 0;
    candidateCount = 0;
    for (; i < BTL_RANK_KIND_COUNT; i++) {
        statId = d_021F1364[i];
        if (func_021D5D14(pokeParam, statId, 1) != 0)
            candidates[candidateCount++] = statId;
    }
    if (candidateCount != 0)
        func_021DD9E8(server, pokeId, candidates[func_021D78AC(candidateCount)], 2);
}

void func_021DD9E8(void *server, int pokeId, int statId, int amount)
{
    HandExRankEffect *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        cmd = func_021C88A4(server, HANDEX_KIND_RANK_EFFECT, pokeId);
        cmd->rankKind = statId;
        cmd->volume = amount;
        cmd->pokeCount = 1;
        cmd->pokeId = pokeId;
        func_021C88C8(server, cmd);
    }
}

int *func_021DDA1C(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F16CC;
}

void func_021DDA28(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021D775C(BTL_EVAR_HIT_SUBSTITUTE) == 0
        && func_021D775C(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE
        && func_021D62C4(func_021C7CF4(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0)
        func_021DD044(factor, server, pokeId);
}

void func_021DDA6C(struct BtlEventFactor *factor, void *server, int pokeId)
{
    struct BtlPokeParam *pokeParam;
    HandExRecoverHp *cmd;
    u8 divisor;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        pokeParam = func_021C7CF4(server, pokeId);
        divisor = func_021DCFF8(factor, 2);
        cmd = func_021C88A4(server, HANDEX_KIND_RECOVER_HP, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = func_021D7B74(pokeParam, divisor);
        func_021C88C8(server, cmd);
    }
}

int *func_021DDAB8(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F175C;
}
