/*
 * file:     hand_tokusei_021d93d8.c
 * unit:     yes
 * function: HAND_TOKUSEI_ParalysisGuard_CheckAdd, HAND_TOKUSEI_ParalysisGuard_CureOnEntry, HAND_TOKUSEI_ParalysisGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetParalysisGuardHandlers, HAND_TOKUSEI_SleepGuard_CheckAdd, HAND_TOKUSEI_SleepGuard_BlockOwnerEvent0E, HAND_TOKUSEI_GetSleepGuardHandlers, HAND_TOKUSEI_FreezeGuard_CheckAdd, HAND_TOKUSEI_FreezeGuard_CureOnEntry, HAND_TOKUSEI_FreezeGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetFreezeGuardHandlers, HAND_TOKUSEI_PoisonGuard_CheckAdd, HAND_TOKUSEI_PoisonGuard_CureOnEntry, HAND_TOKUSEI_PoisonGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetPoisonGuardHandlers, HAND_TOKUSEI_BurnGuard_CheckAdd, HAND_TOKUSEI_BurnGuard_CureOnEntry, HAND_TOKUSEI_BurnGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetBurnGuardHandlers, HAND_TOKUSEI_ConfusionGuard_CheckAdd, HAND_TOKUSEI_ConfusionGuard_ShowBlockedMessage, HAND_TOKUSEI_ConfusionGuard_CureOnEntry, HAND_TOKUSEI_ConfusionGuard_CureOnPeriodicCheck, HAND_TOKUSEI_GetConfusionGuardHandlers, HAND_TOKUSEI_InfatuationGuard_CheckAdd, HAND_TOKUSEI_InfatuationGuard_CureOnEntry, HAND_TOKUSEI_InfatuationGuard_CureOnPeriodicCheck, HAND_TOKUSEI_InfatuationGuard_ShowBlockedMoveMessage, HAND_TOKUSEI_GetInfatuationGuardHandlers, HAND_TOKUSEI_BlockSickIfTargeted, HAND_TOKUSEI_ShowSickGuardMessage, HAND_TOKUSEI_SickGuard_ShowBlockedMessage, HAND_TOKUSEI_CureSickIfOwner, HAND_TOKUSEI_CureSick, HAND_TOKUSEI_Drizzle_StartRain, HAND_TOKUSEI_GetDrizzleHandlers, HAND_TOKUSEI_Drought_StartSun, HAND_TOKUSEI_GetDroughtHandlers, HAND_TOKUSEI_SandStream_StartSandstorm, HAND_TOKUSEI_GetSandStreamHandlers, HAND_TOKUSEI_SnowWarning_StartHail, HAND_TOKUSEI_GetSnowWarningHandlers, HAND_TOKUSEI_StartWeather, HAND_TOKUSEI_WeatherLock_ClearWeather, HAND_TOKUSEI_WeatherLock_SetFailFlag, HAND_TOKUSEI_GetWeatherLockHandlers, HAND_TOKUSEI_IceBody_HealInHail, HAND_TOKUSEI_GetIceBodyHandlers, HAND_TOKUSEI_RainDish_HealInRain, HAND_TOKUSEI_GetRainDishHandlers, HAND_TOKUSEI_HealInWeather, HAND_TOKUSEI_SolarPower_DamageInSun, HAND_TOKUSEI_SolarPower_BoostSpecialAttackInSun, HAND_TOKUSEI_StatLossGuard_BlockForeignDrop, HAND_TOKUSEI_StatLossGuard_BlockForeignChange, HAND_TOKUSEI_StatLossGuard_BlockTargetedA, HAND_TOKUSEI_StatLossGuard_BlockTargetedB, HAND_TOKUSEI_StatLossGuard_BlockIfFlagged, HAND_TOKUSEI_Simple_DoubleStatChange, HAND_TOKUSEI_Simple_SetOwnerFlag, HAND_TOKUSEI_GetSimpleHandlers, HAND_TOKUSEI_Hydration_CureStatusInRain, HAND_TOKUSEI_GetHydrationHandlers
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
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gInfatuationGuardHandlers     0x021F0CC4  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_HasSick   0x021D62C4  thumb ov093
 *   gDrizzleHandlers     0x021F08D0  data   ov093  a4
 *   gDroughtHandlers     0x021F08E0  data   ov093  a4
 *   gSandStreamHandlers     0x021F08F0  data   ov093  a4
 *   gSnowWarningHandlers     0x021F0900  data   ov093  a4
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
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
#include "hand_tokusei_021d93d8_types.h"
#include "btl_pokeparam_types.h"

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, s32 multiplier);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *flow, int cmdKind, int pokeId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(void *flow, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *strParam, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *strParam, u32 arg);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *flow, void *cmd);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(void *flow, int pokeId);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickIndex);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(void *flow);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern int func_021E85F8(int pokeId);

int HAND_TOKUSEI_BlockSickIfTargeted(void *flow, int pokeId, int sickIndex);
void HAND_TOKUSEI_ShowSickGuardMessage(void *flow, void *flowCmd, int pokeId, int *work, u16 strId);
void HAND_TOKUSEI_CureSickIfOwner(void *flow, int pokeId, int sickIndex);
void HAND_TOKUSEI_CureSick(void *flow, int pokeId, int sickIndex);
void HAND_TOKUSEI_StartWeather(void *flow, int pokeId, int weather);
void HAND_TOKUSEI_HealInWeather(void *flow, int pokeId, int weather);

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

void HAND_TOKUSEI_ParalysisGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_PARALYSIS);
}

void HAND_TOKUSEI_ParalysisGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_PARALYSIS);
}

void HAND_TOKUSEI_ParalysisGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_PARALYSIS);
}

int *HAND_TOKUSEI_GetParalysisGuardHandlers(int *count)
{
    *count = 5;
    return gParalysisGuardHandlers;
}

void HAND_TOKUSEI_SleepGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    int blocked;

    blocked = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_SLEEP);
    *work = blocked;
    if (blocked == 0)
        *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, 0xe);
}

void HAND_TOKUSEI_SleepGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_SLEEP);
}

void HAND_TOKUSEI_SleepGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_SLEEP);
}

void HAND_TOKUSEI_SleepGuard_BlockOwnerEvent0E(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

int *HAND_TOKUSEI_GetSleepGuardHandlers(int *count)
{
    *count = 6;
    return gSleepGuardHandlers;
}

void HAND_TOKUSEI_FreezeGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_FREEZE);
}

void HAND_TOKUSEI_FreezeGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_FREEZE);
}

void HAND_TOKUSEI_FreezeGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_FREEZE);
}

int *HAND_TOKUSEI_GetFreezeGuardHandlers(int *count)
{
    *count = 5;
    return gFreezeGuardHandlers;
}

void HAND_TOKUSEI_PoisonGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_POISON);
}

void HAND_TOKUSEI_PoisonGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_POISON);
}

void HAND_TOKUSEI_PoisonGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_POISON);
}

int *HAND_TOKUSEI_GetPoisonGuardHandlers(int *count)
{
    *count = 5;
    return gPoisonGuardHandlers;
}

void HAND_TOKUSEI_BurnGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_BURN);
}

void HAND_TOKUSEI_BurnGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_BURN);
}

void HAND_TOKUSEI_BurnGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_BURN);
}

int *HAND_TOKUSEI_GetBurnGuardHandlers(int *count)
{
    *count = 5;
    return gBurnGuardHandlers;
}

void HAND_TOKUSEI_ConfusionGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_CONFUSION);
}

void HAND_TOKUSEI_ConfusionGuard_ShowBlockedMessage(void *factor, void *flow, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowSickGuardMessage(factor, flow, pokeId, work, 0x165);
}

void HAND_TOKUSEI_ConfusionGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_CONFUSION);
}

void HAND_TOKUSEI_ConfusionGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_CONFUSION);
}

int *HAND_TOKUSEI_GetConfusionGuardHandlers(int *count)
{
    *count = 4;
    return gConfusionGuardHandlers;
}

void HAND_TOKUSEI_InfatuationGuard_CheckAdd(void *factor, void *flow, int pokeId, int *work)
{
    *work = HAND_TOKUSEI_BlockSickIfTargeted(flow, pokeId, TKS_SICK_INFATUATION);
}

void HAND_TOKUSEI_InfatuationGuard_CureOnEntry(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSickIfOwner(flow, pokeId, TKS_SICK_INFATUATION);
}

void HAND_TOKUSEI_InfatuationGuard_CureOnPeriodicCheck(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_CureSick(flow, pokeId, TKS_SICK_INFATUATION);
}

void HAND_TOKUSEI_InfatuationGuard_ShowBlockedMoveMessage(void *factor, void *flow, int pokeId)
{
    TokuseiMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && (u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) == 0x1bd) {
        if (BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
            BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 4, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, 2, 0xd2);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
        }
    }
}

int *HAND_TOKUSEI_GetInfatuationGuardHandlers(int *count)
{
    *count = 5;
    return gInfatuationGuardHandlers;
}

int HAND_TOKUSEI_BlockSickIfTargeted(void *flow, int pokeId, int sickIndex)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && sickIndex == BTL_EVENT_GetVar(BTL_EVAR_SICK_ID))
        return BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
    return 0;
}

void HAND_TOKUSEI_ShowSickGuardMessage(void *factor, void *flow, int pokeId, int *work, u16 strId)
{
    TokuseiMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && *work == 1) {
        BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 4, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, 2, strId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
        *work = 0;
    }
}

void HAND_TOKUSEI_SickGuard_ShowBlockedMessage(void *factor, void *flow, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowSickGuardMessage(factor, flow, pokeId, work, 0xd2);
}

void HAND_TOKUSEI_CureSickIfOwner(void *flow, int pokeId, int sickIndex)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_TOKUSEI_CureSick(flow, pokeId, sickIndex);
}

void HAND_TOKUSEI_CureSick(void *flow, int pokeId, int sickIndex)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), sickIndex) != 0) {
        TokuseiCureSickCmd *cmd;

        BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0xb, pokeId);
        cmd->sickIndex = sickIndex;
        cmd->showMessage = 1;
        cmd->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
    }
}

void HAND_TOKUSEI_Drizzle_StartRain(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_RAIN);
}

int *HAND_TOKUSEI_GetDrizzleHandlers(int *count)
{
    *count = 2;
    return gDrizzleHandlers;
}

void HAND_TOKUSEI_Drought_StartSun(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_SUN);
}

int *HAND_TOKUSEI_GetDroughtHandlers(int *count)
{
    *count = 2;
    return gDroughtHandlers;
}

void HAND_TOKUSEI_SandStream_StartSandstorm(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_SAND);
}

int *HAND_TOKUSEI_GetSandStreamHandlers(int *count)
{
    *count = 2;
    return gSandStreamHandlers;
}

void HAND_TOKUSEI_SnowWarning_StartHail(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_StartWeather(flow, pokeId, TKS_WEATHER_HAIL);
}

int *HAND_TOKUSEI_GetSnowWarningHandlers(int *count)
{
    *count = 2;
    return gSnowWarningHandlers;
}

void HAND_TOKUSEI_StartWeather(void *flow, int pokeId, int weather)
{
    TokuseiWeatherCmd *cmd;
    int cmdFlagKind = 2;

    if (pokeId == BTL_EVENT_GetVar(cmdFlagKind)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0x1d, pokeId);
        cmd->flags |= cmdFlagKind << 22;
        cmd->weather = weather;
        cmd->turns = 0xff;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

void HAND_TOKUSEI_WeatherLock_ClearWeather(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        TokuseiWeatherCmd *cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0x1d, pokeId);

        cmd->flags |= 2 << 22;
        cmd->weather = 0;
        cmd->announce = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, 1, 0x5e);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

void HAND_TOKUSEI_WeatherLock_SetFailFlag(void)
{
    BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

int *HAND_TOKUSEI_GetWeatherLockHandlers(int *count)
{
    *count = 2;
    return gWeatherLockHandlers;
}

void HAND_TOKUSEI_IceBody_HealInHail(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_HealInWeather(flow, pokeId, TKS_WEATHER_HAIL);
}

int *HAND_TOKUSEI_GetIceBodyHandlers(int *count)
{
    *count = 1;
    return gIceBodyHandlers;
}

void HAND_TOKUSEI_RainDish_HealInRain(void *factor, void *flow, int pokeId)
{
    HAND_TOKUSEI_HealInWeather(flow, pokeId, TKS_WEATHER_RAIN);
}

int *HAND_TOKUSEI_GetRainDishHandlers(int *count)
{
    *count = 1;
    return gRainDishHandlers;
}

void HAND_TOKUSEI_HealInWeather(void *flow, int pokeId, int weather)
{
    struct BtlPokeParam *bpp;
    TokuseiHpCmd *cmd;

    if (weather == BTL_EVENT_GetVar(BTL_EVAR_WEATHER) && pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 5, pokeId);
        cmd->flags |= 0x800000;
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(bpp, 0x10);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
    }
}

void HAND_TOKUSEI_SolarPower_DamageInSun(void *factor, void *flow, int pokeId)
{
    int damage;
    TokuseiHpCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_WEATHER) == TKS_WEATHER_SUN) {
        damage = BTL_CALC_DivideMaxHpMin1(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 8);
        BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = damage;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
    }
}

void HAND_TOKUSEI_SolarPower_BoostSpecialAttackInSun(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == TKS_WEATHER_SUN) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 2)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, 0x1800);
    }
}

int *HAND_TOKUSEI_GetSolarPowerHandlers(int *count)
{
    *count = 2;
    return gSolarPowerHandlers;
}

void HAND_TOKUSEI_StatLossGuard_BlockForeignDrop(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) != 8)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void HAND_TOKUSEI_StatLossGuard_BlockForeignChange(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void HAND_TOKUSEI_StatLossGuard_BlockTargetedA(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void HAND_TOKUSEI_StatLossGuard_BlockTargetedB(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(0x47, 1);
}

void HAND_TOKUSEI_StatLossGuard_BlockIfFlagged(void *factor, void *flow, int pokeId)
{
    if (func_021E85F8(pokeId) != 0 && BTL_EVENT_GetVar(5) == 1)
        BTL_EVENT_OverwriteVar(0x47, 1);
}

void *HAND_TOKUSEI_GetStatLossGuardHandlers(int *count)
{
    *count = 5;
    return &gStatLossGuardHandlers;
}

void HAND_TOKUSEI_Simple_DoubleStatChange(void *factor, void *flow, int pokeId)
{
    unsigned short doubled;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        doubled = BTL_EVENT_GetVar(BTL_EVAR_EFFECT_PERCENT) * 2;
        BTL_EVENT_OverwriteVar(BTL_EVAR_EFFECT_PERCENT, doubled);
    }
}

void HAND_TOKUSEI_Simple_SetOwnerFlag(void *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(0x45, 1);
}

int *HAND_TOKUSEI_GetSimpleHandlers(int *count)
{
    *count = 3;
    return gSimpleHandlers;
}

void HAND_TOKUSEI_Hydration_CureStatusInRain(void *factor, void *flow, int pokeId)
{
    TokuseiCureSickCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == TKS_WEATHER_RAIN) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) {
            BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0xb, pokeId);
            cmd->sickIndex = 0x24;
            cmd->pokeId = pokeId;
            cmd->showMessage = 1;
            cmd->flags |= 0x2000000;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
        }
    }
}

int *HAND_TOKUSEI_GetHydrationHandlers(int *count)
{
    *count = 1;
    return gHydrationHandlers;
}
