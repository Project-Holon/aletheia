/*
 * file:     unit_021D93D8.c
 * unit:     yes
 * function: BTL_TOKUSEI_ParalysisGuard_CheckAdd, BTL_TOKUSEI_ParalysisGuard_CureOnEntry, BTL_TOKUSEI_ParalysisGuard_CureOnPeriodicCheck, BTL_TOKUSEI_GetParalysisGuardHandlers, BTL_TOKUSEI_SleepGuard_CheckAdd, BTL_TOKUSEI_SleepGuard_BlockOwnerEvent0E, BTL_TOKUSEI_GetSleepGuardHandlers, BTL_TOKUSEI_FreezeGuard_CheckAdd, BTL_TOKUSEI_FreezeGuard_CureOnEntry, BTL_TOKUSEI_FreezeGuard_CureOnPeriodicCheck, BTL_TOKUSEI_GetFreezeGuardHandlers, BTL_TOKUSEI_PoisonGuard_CheckAdd, BTL_TOKUSEI_PoisonGuard_CureOnEntry, BTL_TOKUSEI_PoisonGuard_CureOnPeriodicCheck, BTL_TOKUSEI_GetPoisonGuardHandlers, BTL_TOKUSEI_BurnGuard_CheckAdd, BTL_TOKUSEI_BurnGuard_CureOnEntry, BTL_TOKUSEI_BurnGuard_CureOnPeriodicCheck, BTL_TOKUSEI_GetBurnGuardHandlers, BTL_TOKUSEI_ConfusionGuard_CheckAdd, BTL_TOKUSEI_ConfusionGuard_ShowBlockedMessage, BTL_TOKUSEI_ConfusionGuard_CureOnEntry, BTL_TOKUSEI_ConfusionGuard_CureOnPeriodicCheck, BTL_TOKUSEI_GetConfusionGuardHandlers, BTL_TOKUSEI_InfatuationGuard_CheckAdd, BTL_TOKUSEI_InfatuationGuard_CureOnEntry, BTL_TOKUSEI_InfatuationGuard_CureOnPeriodicCheck, BTL_TOKUSEI_InfatuationGuard_ShowBlockedMoveMessage, BTL_TOKUSEI_GetInfatuationGuardHandlers, BTL_TOKUSEI_BlockSickIfTargeted, BTL_TOKUSEI_ShowSickGuardMessage, BTL_TOKUSEI_SickGuard_ShowBlockedMessage, BTL_TOKUSEI_CureSickIfOwner, BTL_TOKUSEI_CureSick, BTL_TOKUSEI_Drizzle_StartRain, BTL_TOKUSEI_GetDrizzleHandlers, BTL_TOKUSEI_Drought_StartSun, BTL_TOKUSEI_GetDroughtHandlers, BTL_TOKUSEI_SandStream_StartSandstorm, BTL_TOKUSEI_GetSandStreamHandlers, BTL_TOKUSEI_SnowWarning_StartHail, BTL_TOKUSEI_GetSnowWarningHandlers, BTL_TOKUSEI_StartWeather, BTL_TOKUSEI_WeatherLock_ClearWeather, BTL_TOKUSEI_WeatherLock_SetFailFlag, BTL_TOKUSEI_GetWeatherLockHandlers, BTL_TOKUSEI_IceBody_HealInHail, BTL_TOKUSEI_GetIceBodyHandlers, BTL_TOKUSEI_RainDish_HealInRain, BTL_TOKUSEI_GetRainDishHandlers, BTL_TOKUSEI_HealInWeather, BTL_TOKUSEI_SolarPower_DamageInSun, BTL_TOKUSEI_SolarPower_BoostSpecialAttackInSun, BTL_TOKUSEI_StatLossGuard_BlockForeignDrop, BTL_TOKUSEI_StatLossGuard_BlockForeignChange, BTL_TOKUSEI_StatLossGuard_BlockTargetedA, BTL_TOKUSEI_StatLossGuard_BlockTargetedB, BTL_TOKUSEI_StatLossGuard_BlockIfFlagged, BTL_TOKUSEI_Simple_DoubleStatChange, BTL_TOKUSEI_Simple_SetOwnerFlag, BTL_TOKUSEI_GetSimpleHandlers, BTL_TOKUSEI_Hydration_CureStatusInRain, BTL_TOKUSEI_GetHydrationHandlers
 * address:  0x021D93D8
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
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_EVENT_GetVar   0x021D775C  thumb
 *   gParalysisGuardHandlers     0x021F0BFC  data   ov093  a4
 *   gSleepGuardHandlers     0x021F0D3C  data   ov093  a4
 *   gFreezeGuardHandlers     0x021F0C4C  data   ov093  a4
 *   gPoisonGuardHandlers     0x021F0C74  data   ov093  a4
 *   gConfusionGuardHandlers     0x021F0BB4  data   ov093  a4
 *   gBurnGuardHandlers     0x021F0C9C  data   ov093  a4
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   gInfatuationGuardHandlers     0x021F0CC4  data   ov093  a4
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_HasSick   0x021D62C4  thumb ov093
 *   gDrizzleHandlers     0x021F08D0  data   ov093  a4
 *   gDroughtHandlers     0x021F08E0  data   ov093  a4
 *   gSandStreamHandlers     0x021F08F0  data   ov093  a4
 *   gSnowWarningHandlers     0x021F0900  data   ov093  a4
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gSolarPowerHandlers     0x021F0930  data   ov093  a4
 *   gStatLossGuardHandlers 0x021F0CEC data a4
 *   func_021E85F8 0x021E85F8 thumb ov093
 *   gWeatherLockHandlers     0x021F0910  data   ov093  a4
 *   gIceBodyHandlers     0x021F05C0  data   ov093  a4
 *   gRainDishHandlers     0x021F0670  data   ov093  a4
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   gHydrationHandlers     0x021F05A8  data   a4
 *   gSimpleHandlers     0x021F0A88  data   ov093  a4
 */
#include "unit_021D93D8_types.h"
#include "btl_pokeparam_types.h"

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, s32 multiplier);
extern void func_021C88B4(void *flow, int cmdKind, int pokeId);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern void func_021C8838(void *strParam, int strType, int strId);
extern void func_021C8860(void *strParam, u32 arg);
extern void func_021C88C8(void *flow, void *cmd);
extern struct BtlPokeParam *func_021C7CF4(void *flow, int pokeId);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickIndex);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
extern int func_021C8288(void *flow);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern int func_021E85F8(int pokeId);

int BTL_TOKUSEI_BlockSickIfTargeted(void *flow, int pokeId, int sickIndex);
void BTL_TOKUSEI_ShowSickGuardMessage(void *flow, void *flowCmd, int pokeId, int *work, u16 strId);
void BTL_TOKUSEI_CureSickIfOwner(void *flow, int pokeId, int sickIndex);
void BTL_TOKUSEI_CureSick(void *flow, int pokeId, int sickIndex);
void BTL_TOKUSEI_StartWeather(void *flow, int pokeId, int weather);
void BTL_TOKUSEI_HealInWeather(void *flow, int pokeId, int weather);

extern int gParalysisGuardHandlers[];
extern int gSleepGuardHandlers[];
extern int gFreezeGuardHandlers[];
extern int gPoisonGuardHandlers[];
extern int gConfusionGuardHandlers[];
extern int gBurnGuardHandlers[];
extern int gInfatuationGuardHandlers[];
extern int gDrizzleHandlers[];
extern int gDroughtHandlers[];
extern int gSandStreamHandlers[];
extern int gSnowWarningHandlers[];
extern int gSolarPowerHandlers[];
extern unsigned int gStatLossGuardHandlers;
extern int gWeatherLockHandlers[];
extern int gIceBodyHandlers[];
extern int gRainDishHandlers[];
extern int gHydrationHandlers[];
extern int gSimpleHandlers[];

void BTL_TOKUSEI_ParalysisGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = BTL_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_PARALYSIS);
}

void BTL_TOKUSEI_ParalysisGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_PARALYSIS);
}

void BTL_TOKUSEI_ParalysisGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_PARALYSIS);
}

int *BTL_TOKUSEI_GetParalysisGuardHandlers(int *count)
{
    *count = 5;
    return gParalysisGuardHandlers;
}

void BTL_TOKUSEI_SleepGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    int blocked;

    blocked = BTL_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_SLEEP);
    *work = blocked;
    if (blocked == 0)
        *work = BTL_TOKUSEI_BlockSickIfTargeted(flow, pokeId, 0xe);
}

void BTL_TOKUSEI_SleepGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_SLEEP);
}

void BTL_TOKUSEI_SleepGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_SLEEP);
}

void BTL_TOKUSEI_SleepGuard_BlockOwnerEvent0E(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(TKS_EVAR_FAIL_FLAG, 1);
}

int *BTL_TOKUSEI_GetSleepGuardHandlers(int *count)
{
    *count = 6;
    return gSleepGuardHandlers;
}

void BTL_TOKUSEI_FreezeGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = BTL_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_FREEZE);
}

void BTL_TOKUSEI_FreezeGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_FREEZE);
}

void BTL_TOKUSEI_FreezeGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_FREEZE);
}

int *BTL_TOKUSEI_GetFreezeGuardHandlers(int *count)
{
    *count = 5;
    return gFreezeGuardHandlers;
}

void BTL_TOKUSEI_PoisonGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = BTL_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_POISON);
}

void BTL_TOKUSEI_PoisonGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_POISON);
}

void BTL_TOKUSEI_PoisonGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_POISON);
}

int *BTL_TOKUSEI_GetPoisonGuardHandlers(int *count)
{
    *count = 5;
    return gPoisonGuardHandlers;
}

void BTL_TOKUSEI_BurnGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = BTL_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_BURN);
}

void BTL_TOKUSEI_BurnGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_BURN);
}

void BTL_TOKUSEI_BurnGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_BURN);
}

int *BTL_TOKUSEI_GetBurnGuardHandlers(int *count)
{
    *count = 5;
    return gBurnGuardHandlers;
}

void BTL_TOKUSEI_ConfusionGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = BTL_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_CONFUSION);
}

void BTL_TOKUSEI_ConfusionGuard_ShowBlockedMessage(void *factor, void *flow, int pokeId, int *work)
{
    BTL_TOKUSEI_ShowSickGuardMessage(factor, flow, pokeId, work, 0x165);
}

void BTL_TOKUSEI_ConfusionGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_CONFUSION);
}

void BTL_TOKUSEI_ConfusionGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_CONFUSION);
}

int *BTL_TOKUSEI_GetConfusionGuardHandlers(int *count)
{
    *count = 4;
    return gConfusionGuardHandlers;
}

void BTL_TOKUSEI_InfatuationGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = BTL_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_INFATUATION);
}

void BTL_TOKUSEI_InfatuationGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_INFATUATION);
}

void BTL_TOKUSEI_InfatuationGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_INFATUATION);
}

void BTL_TOKUSEI_InfatuationGuard_ShowBlockedMoveMessage(void *factor, void *flow, int pokeId)
{
    TokuseiMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_DEFENDER_ID) && (u16)BTL_EVENT_GetVar(TKS_EVAR_MOVE_ID) == 0x1bd) {
        if (BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
            func_021C88B4(flow, 2, pokeId);
            cmd = func_021C88A4(flow, 4, pokeId);
            func_021C8838(&cmd->strParam, 2, 0xd2);
            func_021C8860(&cmd->strParam, pokeId);
            func_021C88C8(flow, cmd);
            func_021C88B4(flow, 3, pokeId);
        }
    }
}

int *BTL_TOKUSEI_GetInfatuationGuardHandlers(int *count)
{
    *count = 5;
    return gInfatuationGuardHandlers;
}

int BTL_TOKUSEI_BlockSickIfTargeted(void *flow, int pokeId, int sickIndex)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_DEFENDER_ID) && sickIndex == BTL_EVENT_GetVar(TKS_EVAR_CONDITION))
        return BTL_EVENT_OverwriteVar(TKS_EVAR_FAIL_FLAG, 1);
    return 0;
}

void BTL_TOKUSEI_ShowSickGuardMessage(void *factor, void *flow, int pokeId, int *work, u16 strId)
{
    TokuseiMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_DEFENDER_ID) && *work == 1) {
        func_021C88B4(flow, 2, pokeId);
        cmd = func_021C88A4(flow, 4, pokeId);
        func_021C8838(&cmd->strParam, 2, strId);
        func_021C8860(&cmd->strParam, pokeId);
        func_021C88C8(flow, cmd);
        func_021C88B4(flow, 3, pokeId);
        *work = 0;
    }
}

void BTL_TOKUSEI_SickGuard_ShowBlockedMessage(void *factor, void *flow, int pokeId, int *work)
{
    BTL_TOKUSEI_ShowSickGuardMessage(factor, flow, pokeId, work, 0xd2);
}

void BTL_TOKUSEI_CureSickIfOwner(void *flow, int pokeId, int sickIndex)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_POKE_ID))
        BTL_TOKUSEI_CureSick(flow, pokeId, sickIndex);
}

void BTL_TOKUSEI_CureSick(void *flow, int pokeId, int sickIndex)
{
    if (BTL_POKEPARAM_HasSick(func_021C7CF4(flow, pokeId), sickIndex) != 0) {
        TokuseiCureSickCmd *cmd;

        func_021C88B4(flow, 2, pokeId);
        cmd = func_021C88A4(flow, 0xb, pokeId);
        cmd->sickIndex = sickIndex;
        cmd->showMessage = 1;
        cmd->pokeId = pokeId;
        func_021C88C8(flow, cmd);
        func_021C88B4(flow, 3, pokeId);
    }
}

void BTL_TOKUSEI_Drizzle_StartRain(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_RAIN);
}

int *BTL_TOKUSEI_GetDrizzleHandlers(int *count)
{
    *count = 2;
    return gDrizzleHandlers;
}

void BTL_TOKUSEI_Drought_StartSun(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_SUN);
}

int *BTL_TOKUSEI_GetDroughtHandlers(int *count)
{
    *count = 2;
    return gDroughtHandlers;
}

void BTL_TOKUSEI_SandStream_StartSandstorm(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_SAND);
}

int *BTL_TOKUSEI_GetSandStreamHandlers(int *count)
{
    *count = 2;
    return gSandStreamHandlers;
}

void BTL_TOKUSEI_SnowWarning_StartHail(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_HAIL);
}

int *BTL_TOKUSEI_GetSnowWarningHandlers(int *count)
{
    *count = 2;
    return gSnowWarningHandlers;
}

void BTL_TOKUSEI_StartWeather(void *flow, int pokeId, int weather)
{
    TokuseiWeatherCmd *cmd;
    int cmdFlagKind = 2;

    if (pokeId == BTL_EVENT_GetVar(cmdFlagKind)) {
        cmd = func_021C88A4(flow, 0x1d, pokeId);
        cmd->flags |= cmdFlagKind << 22;
        cmd->weather = weather;
        cmd->turns = 0xff;
        func_021C88C8(flow, cmd);
    }
}

void BTL_TOKUSEI_WeatherLock_ClearWeather(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_POKE_ID)) {
        TokuseiWeatherCmd *cmd = func_021C88A4(flow, 0x1d, pokeId);

        cmd->flags |= 2 << 22;
        cmd->weather = 0;
        cmd->announce = 1;
        func_021C8838(&cmd->strParam, 1, 0x5e);
        func_021C88C8(flow, cmd);
    }
}

void BTL_TOKUSEI_WeatherLock_SetFailFlag(void)
{
    BTL_EVENT_OverwriteVar(TKS_EVAR_FAIL_FLAG, 1);
}

int *BTL_TOKUSEI_GetWeatherLockHandlers(int *count)
{
    *count = 2;
    return gWeatherLockHandlers;
}

void BTL_TOKUSEI_IceBody_HealInHail(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_HealInWeather(flow, pokeId, TKS_WEATHER_HAIL);
}

int *BTL_TOKUSEI_GetIceBodyHandlers(int *count)
{
    *count = 1;
    return gIceBodyHandlers;
}

void BTL_TOKUSEI_RainDish_HealInRain(void *factor, void *flow, int pokeId)
{
    BTL_TOKUSEI_HealInWeather(flow, pokeId, TKS_WEATHER_RAIN);
}

int *BTL_TOKUSEI_GetRainDishHandlers(int *count)
{
    *count = 1;
    return gRainDishHandlers;
}

void BTL_TOKUSEI_HealInWeather(void *flow, int pokeId, int weather)
{
    struct BtlPokeParam *bpp;
    TokuseiHpCmd *cmd;

    if (weather == BTL_EVENT_GetVar(TKS_EVAR_WEATHER) && pokeId == BTL_EVENT_GetVar(TKS_EVAR_POKE_ID)) {
        bpp = func_021C7CF4(flow, pokeId);
        cmd = func_021C88A4(flow, 5, pokeId);
        cmd->flags |= 0x800000;
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(bpp, 0x10);
        func_021C88C8(flow, cmd);
        BTL_EVENT_OverwriteVar(TKS_EVAR_FAIL_FLAG, 1);
    }
}

void BTL_TOKUSEI_SolarPower_DamageInSun(void *factor, void *flow, int pokeId)
{
    int damage;
    TokuseiHpCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_POKE_ID) && BTL_EVENT_GetVar(TKS_EVAR_WEATHER) == TKS_WEATHER_SUN) {
        damage = BTL_CALC_DivideMaxHpMin1(func_021C7CF4(flow, pokeId), 8);
        func_021C88B4(flow, 2, pokeId);
        cmd = func_021C88A4(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = damage;
        func_021C88C8(flow, cmd);
        func_021C88B4(flow, 3, pokeId);
    }
}

void BTL_TOKUSEI_SolarPower_BoostSpecialAttackInSun(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_ATTACKER_ID) && func_021C8288(flow) == TKS_WEATHER_SUN) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(TKS_EVAR_MOVE_ID)) == 2)
            BTL_EVENT_MultiplyVar(TKS_EVAR_POWER_RATIO, 0x1800);
    }
}

int *BTL_TOKUSEI_GetSolarPowerHandlers(int *count)
{
    *count = 2;
    return gSolarPowerHandlers;
}

void BTL_TOKUSEI_StatLossGuard_BlockForeignDrop(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_DEFENDER_ID) && pokeId != BTL_EVENT_GetVar(TKS_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(TKS_EVAR_CONDITION) != 8)
        BTL_EVENT_OverwriteVar(TKS_EVAR_FAIL_FLAG, 1);
}

void BTL_TOKUSEI_StatLossGuard_BlockForeignChange(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_DEFENDER_ID) && pokeId != BTL_EVENT_GetVar(TKS_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(TKS_EVAR_FAIL_FLAG, 1);
}

void BTL_TOKUSEI_StatLossGuard_BlockTargetedA(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(TKS_EVAR_FAIL_FLAG, 1);
}

void BTL_TOKUSEI_StatLossGuard_BlockTargetedB(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(0x47, 1);
}

void BTL_TOKUSEI_StatLossGuard_BlockIfFlagged(void *factor, void *flow, int pokeId)
{
    if (func_021E85F8(pokeId) != 0 && BTL_EVENT_GetVar(5) == 1)
        BTL_EVENT_OverwriteVar(0x47, 1);
}

void *BTL_TOKUSEI_GetStatLossGuardHandlers(int *count)
{
    *count = 5;
    return &gStatLossGuardHandlers;
}

void BTL_TOKUSEI_Simple_DoubleStatChange(void *factor, void *flow, int pokeId)
{
    unsigned short doubled;

    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_ATTACKER_ID)) {
        doubled = BTL_EVENT_GetVar(TKS_EVAR_CHANGE_AMOUNT) * 2;
        BTL_EVENT_OverwriteVar(TKS_EVAR_CHANGE_AMOUNT, doubled);
    }
}

void BTL_TOKUSEI_Simple_SetOwnerFlag(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(0x45, 1);
}

int *BTL_TOKUSEI_GetSimpleHandlers(int *count)
{
    *count = 3;
    return gSimpleHandlers;
}

void BTL_TOKUSEI_Hydration_CureStatusInRain(void *factor, void *flow, int pokeId)
{
    TokuseiCureSickCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(TKS_EVAR_POKE_ID) && func_021C8288(flow) == TKS_WEATHER_RAIN) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(func_021C7CF4(flow, pokeId))) {
            func_021C88B4(flow, 2, pokeId);
            cmd = func_021C88A4(flow, 0xb, pokeId);
            cmd->sickIndex = 0x24;
            cmd->pokeId = pokeId;
            cmd->showMessage = 1;
            cmd->flags |= 0x2000000;
            func_021C88C8(flow, cmd);
            func_021C88B4(flow, 3, pokeId);
        }
    }
}

int *BTL_TOKUSEI_GetHydrationHandlers(int *count)
{
    *count = 1;
    return gHydrationHandlers;
}
