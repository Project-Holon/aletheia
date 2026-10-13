/*
 * file:     unit_021DD588.c
 * unit:     yes
 * function: BTL_ITEM_RecoverHpPercentOfMaxHp, BTL_ITEM_GetFlavorHealAttackHandlers, BTL_ITEM_FlavorHealAttack, BTL_ITEM_FlavorHealAttackIfForcedUse, BTL_ITEM_GetFlavorHealDefenseHandlers, BTL_ITEM_FlavorHealDefense, BTL_ITEM_FlavorHealDefenseIfForcedUse, BTL_ITEM_GetFlavorHealSpeedHandlers, BTL_ITEM_FlavorHealSpeed, BTL_ITEM_FlavorHealSpeedIfForcedUse, BTL_ITEM_GetFlavorHealSpAttackHandlers, BTL_ITEM_FlavorHealSpAttack, BTL_ITEM_FlavorHealSpAttackIfForcedUse, BTL_ITEM_GetFlavorHealSpDefenseHandlers, BTL_ITEM_FlavorHealSpDefense, BTL_ITEM_FlavorHealSpDefenseIfForcedUse, BTL_ITEM_RequestUseAtHalfHpChecked, BTL_ITEM_RequestUseAtHalfHp, BTL_ITEM_RequestUseAtHalfHpDirect, BTL_ITEM_FlavorHeal, BTL_ITEM_GetRaiseAttackOneHandlers
 * address:  0x021DD588
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
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   BTL_HANDLER_ITEM_GetParam   0x021DCFF8  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   BTL_EVENT_GetFactorKey   0x021D70A8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *   gBtlItemFlavorHealDefenseHandlers 0x021F1C2C data a4
 *   gBtlItemFlavorHealSpeedHandlers 0x021F1C54 data a4
 *   gBtlItemFlavorHealSpAttackHandlers 0x021F1C7C data a4
 *   gBtlItemFlavorHealSpDefenseHandlers 0x021F1CA4 data a4
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_HANDLER_ITEM_HpBerryCheckAndUse 0x021DDE30 thumb ov093
 *   BTL_HANDLER_ITEM_IsHpAtOrBelowFraction 0x021DDEA4 thumb ov093
 *   BTL_HANDLER_ITEM_PushUseItem 0x021DD044 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetNatureStatMod  0x020189D0  thumb
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   gBtlItemFlavorHealAttackHandlers     0x021F1C04  data   ov093  a4
 *   gBtlItemRaiseAttackOneHandlers     0x021F1CCC  data   ov093  a4
 */
#include "unit_021DD588_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *func_021C7CF4(void *server, int pokeId);
extern int func_021D59B4(struct BtlPokeParam *pokeParam, int valueId);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int index);
extern void *func_021C88A4(void *server, int cmdKind, int pokeId);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern void func_021C88C8(void *server, void *cmd);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern int func_0209C2B0(int dividend, int divisor);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *pokeParam, int sickKind);
extern void BTL_HANDLER_ITEM_HpBerryCheckAndUse(struct BtlEventFactor *factor, void *server, int pokeId, int divisor, int checkMoveDamage);
extern int BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(void *server, int pokeId, unsigned int divisor);
extern void BTL_HANDLER_ITEM_PushUseItem(struct BtlEventFactor *factor, void *server, int pokeId);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *pokeParam, u32 divisor);
extern void *BTL_POKEPARAM_GetMon(struct BtlPokeParam *pokeParam);
extern int POKE_TOOL_GetNatureStatMod(void *mon, int statIndex);
extern void BTL_CALC_MakeSickContFromKind(int sickKind, struct BtlPokeParam *pokeParam, union SickCont *out);

extern int gBtlItemFlavorHealAttackHandlers[];
extern int gBtlItemFlavorHealDefenseHandlers[];
extern int gBtlItemFlavorHealSpeedHandlers[];
extern int gBtlItemFlavorHealSpAttackHandlers[];
extern int gBtlItemFlavorHealSpDefenseHandlers[];
extern int gBtlItemRaiseAttackOneHandlers[];

void BTL_ITEM_RecoverHpPercentOfMaxHp(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ITEM_GetFlavorHealAttackHandlers(int *handlerCount);
void BTL_ITEM_FlavorHealAttack(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_FlavorHealAttackIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ITEM_GetFlavorHealDefenseHandlers(int *handlerCount);
void BTL_ITEM_FlavorHealDefense(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_FlavorHealDefenseIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ITEM_GetFlavorHealSpeedHandlers(int *handlerCount);
void BTL_ITEM_FlavorHealSpeed(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_FlavorHealSpeedIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ITEM_GetFlavorHealSpAttackHandlers(int *handlerCount);
void BTL_ITEM_FlavorHealSpAttack(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_FlavorHealSpAttackIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ITEM_GetFlavorHealSpDefenseHandlers(int *handlerCount);
void BTL_ITEM_FlavorHealSpDefense(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_FlavorHealSpDefenseIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_RequestUseAtHalfHpChecked(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_RequestUseAtHalfHp(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_RequestUseAtHalfHpDirect(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_FlavorHeal(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int statIndex);
int *BTL_ITEM_GetRaiseAttackOneHandlers(int *handlerCount);

void BTL_ITEM_RecoverHpPercentOfMaxHp(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HandExRecoverHp *cmd;
    int maxHp;
    u8 percent;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    maxHp = func_021D59B4(func_021C7CF4(server, pokeId), BTL_VALUE_MAX_HP);
    percent = (u8)BTL_HANDLER_ITEM_GetParam(factor, 2);
    cmd = func_021C88A4(server, HANDEX_KIND_RECOVER_HP, pokeId);
    cmd->pokeId = pokeId;
    cmd->amount = func_0209C2B0(maxHp * percent, 100);
    func_021C8838(&cmd->str, HANDEX_STR_SET, 908);
    func_021C8860(&cmd->str, pokeId);
    func_021C8860(&cmd->str, BTL_EVENT_GetFactorKey(factor));
    func_021C88C8(server, cmd);
}

int *BTL_ITEM_GetFlavorHealAttackHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemFlavorHealAttackHandlers;
}

void BTL_ITEM_FlavorHealAttack(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 0); }

void BTL_ITEM_FlavorHealAttackIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 0);
}

int *BTL_ITEM_GetFlavorHealDefenseHandlers(int *handlerCount) { *handlerCount = 5; return gBtlItemFlavorHealDefenseHandlers; }

void BTL_ITEM_FlavorHealDefense(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 1); }

void BTL_ITEM_FlavorHealDefenseIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 1);
}

int *BTL_ITEM_GetFlavorHealSpeedHandlers(int *handlerCount) { *handlerCount = 5; return gBtlItemFlavorHealSpeedHandlers; }

void BTL_ITEM_FlavorHealSpeed(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 2); }

void BTL_ITEM_FlavorHealSpeedIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 2);
}

int *BTL_ITEM_GetFlavorHealSpAttackHandlers(int *handlerCount) { *handlerCount = 5; return gBtlItemFlavorHealSpAttackHandlers; }

void BTL_ITEM_FlavorHealSpAttack(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 3); }

void BTL_ITEM_FlavorHealSpAttackIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 3);
}

int *BTL_ITEM_GetFlavorHealSpDefenseHandlers(int *handlerCount) { *handlerCount = 5; return gBtlItemFlavorHealSpDefenseHandlers; }

void BTL_ITEM_FlavorHealSpDefense(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 4); }

void BTL_ITEM_FlavorHealSpDefenseIfForcedUse(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) BTL_ITEM_FlavorHeal(factor, server, pokeId, work, 4);
}

void BTL_ITEM_RequestUseAtHalfHpChecked(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_USED] == 0 && BTL_POKEPARAM_HasSick(func_021C7CF4(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0) BTL_HANDLER_ITEM_HpBerryCheckAndUse(factor, server, pokeId, 2, 1);
}

void BTL_ITEM_RequestUseAtHalfHp(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_USED] == 0 && BTL_POKEPARAM_HasSick(func_021C7CF4(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0) BTL_HANDLER_ITEM_HpBerryCheckAndUse(factor, server, pokeId, 2, 0);
}

void BTL_ITEM_RequestUseAtHalfHpDirect(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_USED] == 0 && BTL_POKEPARAM_HasSick(func_021C7CF4(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0 && BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(server, pokeId, 2) != 0) BTL_HANDLER_ITEM_PushUseItem(factor, server, pokeId);
}

void BTL_ITEM_FlavorHeal(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int statIndex)
{
    struct BtlPokeParam *pokeParam;
    HandExRecoverHp *healCmd;
    HandExAddSick *sickCmd;

    if (work[ITEM_WORK_USED] == 0 && pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        pokeParam = func_021C7CF4(server, pokeId);
        healCmd = func_021C88A4(server, HANDEX_KIND_RECOVER_HP, pokeId);
        healCmd->pokeId = pokeId;
        healCmd->amount = BTL_CALC_DivideMaxHpMin1(pokeParam, BTL_HANDLER_ITEM_GetParam(factor, 2));
        func_021C8838(&healCmd->str, HANDEX_STR_SET, 908);
        func_021C8860(&healCmd->str, pokeId);
        func_021C8860(&healCmd->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(server, healCmd);
        if (POKE_TOOL_GetNatureStatMod(BTL_POKEPARAM_GetMon(pokeParam), statIndex) == -1) {
            sickCmd = func_021C88A4(server, HANDEX_KIND_ADD_SICK, pokeId);
            sickCmd->pokeId = pokeId;
            sickCmd->sickKind = BTL_SICK_CONFUSION;
            BTL_CALC_MakeSickContFromKind(BTL_SICK_CONFUSION, pokeParam, &sickCmd->sickCont);
            func_021C88C8(server, sickCmd);
        }
        work[ITEM_WORK_USED] = 1;
    }
}

int *BTL_ITEM_GetRaiseAttackOneHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gBtlItemRaiseAttackOneHandlers;
}
