/*
 * file:     unit_021DF48C.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_IcyRockExtendHail, BTL_HANDLER_ITEM_GetSmoothRockHandlers, BTL_HANDLER_ITEM_SmoothRockExtendSandstorm, BTL_HANDLER_ITEM_GetHeatRockHandlers, BTL_HANDLER_ITEM_HeatRockExtendSunshine, BTL_HANDLER_ITEM_GetDampRockHandlers, BTL_HANDLER_ITEM_DampRockExtendRain, BTL_HANDLER_ITEM_ExtendWeatherTurns, BTL_HANDLER_ITEM_GetLightBallHandlers, BTL_HANDLER_ITEM_LightBallDoublePikachuAttack, BTL_HANDLER_ITEM_LightBallFlingParalyze, BTL_HANDLER_ITEM_GetToxicOrbHandlers, BTL_HANDLER_ITEM_ToxicOrbPoisonHolderOnTurnEnd, BTL_HANDLER_ITEM_ToxicOrbFlingPoison, BTL_HANDLER_ITEM_GetFlameOrbHandlers, BTL_HANDLER_ITEM_FlameOrbBurnHolderOnTurnEnd, BTL_HANDLER_ITEM_FlameOrbFlingBurn, BTL_HANDLER_ITEM_GetSilverPowderHandlers, BTL_HANDLER_ITEM_SilverPowderBoostPower, BTL_HANDLER_ITEM_GetSoftSandHandlers, BTL_HANDLER_ITEM_SoftSandBoostPower, BTL_HANDLER_ITEM_GetHardStoneHandlers, BTL_HANDLER_ITEM_HardStoneBoostPower, BTL_HANDLER_ITEM_GetMiracleSeedHandlers
 * address:  0x021DF48C
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
 *   gSmoothRockHandlers     0x021F1464  data   ov093  a4
 *   gHeatRockHandlers     0x021F151C  data   a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gDampRockHandlers     0x021F1514  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   gLightBallHandlers     0x021F167C  data   ov093  a4
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Index15  0x021E8A58  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   gToxicOrbHandlers     0x021F168C  data   ov093  a4
 *   gFlameOrbHandlers     0x021F169C  data   ov093  a4
 *   BTL_HANDLER_ITEM_BoostMovePowerOfType  0x021DF93C  thumb  ov093
 *   gSilverPowderHandlers     0x021F14F4  data   ov093  a4
 *   gSoftSandHandlers     0x021F13FC  data   ov093  a4
 *   gHardStoneHandlers     0x021F13AC  data   ov093  a4
 *   gMiracleSeedHandlers     0x021F137C  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler gSmoothRockHandlers[];
extern const BtlEventHandler gHeatRockHandlers[];
extern const BtlEventHandler gDampRockHandlers[];
extern const BtlEventHandler gLightBallHandlers[];
extern const BtlEventHandler gToxicOrbHandlers[];
extern const BtlEventHandler gFlameOrbHandlers[];
extern const BtlEventHandler gSilverPowderHandlers[];
extern const BtlEventHandler gSoftSandHandlers[];
extern const BtlEventHandler gHardStoneHandlers[];
extern const BtlEventHandler gMiracleSeedHandlers[];

void BTL_HANDLER_ITEM_IcyRockExtendHail(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetSmoothRockHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_SmoothRockExtendSandstorm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetHeatRockHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_HeatRockExtendSunshine(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetDampRockHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_DampRockExtendRain(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_ExtendWeatherTurns(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int weather);
const BtlEventHandler *BTL_HANDLER_ITEM_GetLightBallHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_LightBallDoublePikachuAttack(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_LightBallFlingParalyze(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetToxicOrbHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_ToxicOrbPoisonHolderOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_ToxicOrbFlingPoison(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetFlameOrbHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_FlameOrbBurnHolderOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_FlameOrbFlingBurn(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetSilverPowderHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_SilverPowderBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetSoftSandHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_SoftSandBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetHardStoneHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_HardStoneBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_HANDLER_ITEM_GetMiracleSeedHandlers(int *handlerCount);

/* Icy Rock: hail lasts longer. */
void BTL_HANDLER_ITEM_IcyRockExtendHail(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_ExtendWeatherTurns(factor, flow, pokeId, BTL_WEATHER_HAIL);
}

const BtlEventHandler *BTL_HANDLER_ITEM_GetSmoothRockHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSmoothRockHandlers;
}

/* Smooth Rock: sandstorm lasts longer. */
void BTL_HANDLER_ITEM_SmoothRockExtendSandstorm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_ExtendWeatherTurns(factor, flow, pokeId, BTL_WEATHER_SAND);
}

const BtlEventHandler *BTL_HANDLER_ITEM_GetHeatRockHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHeatRockHandlers;
}

/* Heat Rock: sunshine lasts longer. */
void BTL_HANDLER_ITEM_HeatRockExtendSunshine(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_ExtendWeatherTurns(factor, flow, pokeId, BTL_WEATHER_SUN);
}

const BtlEventHandler *BTL_HANDLER_ITEM_GetDampRockHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gDampRockHandlers;
}

/* Damp Rock: rain lasts longer. */
void BTL_HANDLER_ITEM_DampRockExtendRain(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_ExtendWeatherTurns(factor, flow, pokeId, BTL_WEATHER_RAIN);
}

/* Weather rocks: when the holder sets the given weather, replace its turn count with the item parameter. */
void BTL_HANDLER_ITEM_ExtendWeatherTurns(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int weather)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && weather == BTL_EVENT_GetVar(BTL_EVAR_WEATHER))
        BTL_EVENT_OverwriteVar(BTL_EVAR_WEATHER_TURNS, BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_BOOST_PERCENT));
}

/* Light Ball: two entries. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetLightBallHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gLightBallHandlers;
}

/* Light Ball: doubles the attack ratio of a Pikachu. */
void BTL_HANDLER_ITEM_LightBallDoublePikachuAttack(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_PIKACHU)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
}

/* Light Ball, Fling: paralyze the target. */
void BTL_HANDLER_ITEM_LightBallFlingParalyze(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    flingerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_PARALYSIS;
    cmd->sickCont = BTL_CALC_MakeDefaultSickCont(TKS_SICK_PARALYSIS);
    func_021C88C8(flow, cmd);
}

/* Toxic Orb: two entries. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetToxicOrbHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gToxicOrbHandlers;
}

/* Toxic Orb: at turn end badly poison the holder and show the message. */
void BTL_HANDLER_ITEM_ToxicOrbPoisonHolderOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
    cmd->sickKind = TKS_SICK_POISON;
    cmd->sickCont = BTLV_CORE_MakeSlotKind1Index15();
    cmd->hideMessage = 0;
    cmd->pokeId = pokeId;
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0xf0);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C8860(&cmd->strParam, BTL_EVENT_GetFactorKey(factor));
    func_021C88C8(flow, cmd);
}

/*
 * Toxic Orb, Fling: badly poison the target.
 *
 * BTLV_CORE_MakeSlotKind1Index15 returns the condition record by value; that is what reserves
 * the empty frame word (push r3 / sub sp, #4). An int return drops it.
 */
void BTL_HANDLER_ITEM_ToxicOrbFlingPoison(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    flingerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_POISON;
    cmd->sickCont = BTLV_CORE_MakeSlotKind1Index15();
    func_021C88C8(flow, cmd);
}

/* Flame Orb: two entries. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetFlameOrbHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gFlameOrbHandlers;
}

/* Flame Orb: at turn end burn the holder and show the message. */
void BTL_HANDLER_ITEM_FlameOrbBurnHolderOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
    cmd->sickKind = TKS_SICK_BURN;
    cmd->sickCont = BTL_CALC_MakeDefaultSickCont(TKS_SICK_BURN);
    cmd->hideMessage = 0;
    cmd->pokeId = pokeId;
    /* The message argument is written here and again by the second append below. */
    cmd->strParam.args[1] = BTL_EVENT_GetFactorKey(factor);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0x102);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C8860(&cmd->strParam, BTL_EVENT_GetFactorKey(factor));
    func_021C88C8(flow, cmd);
}

/* Flame Orb, Fling: burn the target. */
void BTL_HANDLER_ITEM_FlameOrbFlingBurn(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    flingerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_BURN;
    cmd->sickCont = BTL_CALC_MakeDefaultSickCont(TKS_SICK_BURN);
    func_021C88C8(flow, cmd);
}

/* Silver Powder. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetSilverPowderHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSilverPowderHandlers;
}

void BTL_HANDLER_ITEM_SilverPowderBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_BUG);
}

/* Soft Sand. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetSoftSandHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSoftSandHandlers;
}

void BTL_HANDLER_ITEM_SoftSandBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_GROUND);
}

/* Hard Stone. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetHardStoneHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHardStoneHandlers;
}

void BTL_HANDLER_ITEM_HardStoneBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_HANDLER_ITEM_BoostMovePowerOfType(factor, flow, pokeId, BTL_TYPE_ROCK);
}

/* Miracle Seed. */
const BtlEventHandler *BTL_HANDLER_ITEM_GetMiracleSeedHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMiracleSeedHandlers;
}
