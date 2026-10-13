/*
 * file:     hand_waza_021e2988.c
 * unit:     yes
 * function: HAND_WAZA_EruptionOnWazaPower, HAND_WAZA_WringOutOnWazaPower, HAND_WAZA_BrineOnPowerRatio, HAND_WAZA_ReturnOnWazaPower
 * address:  0x021E2988
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
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gWringOutHandlers     0x021F2564  data   ov093  a4
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_CALC_MulRatioMin1  0x021D7B2C  thumb  ov093
 *   gBrineHandlers     0x021F24AC  data   ov093  a4
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gReturnHandlers     0x021F244C  data   ov093  a4
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   gFrustrationHandlers     0x021F241C  data  ov093  a4
 */
#include "hand_waza_021e2988_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern int func_021D59B4(struct BtlPokeParam *poke, int valueId);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern u16 WAZA_TOOL_GetPower(u32 moveId);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern int BTL_POKEPARAM_GetHpRatioFixed(struct BtlPokeParam *poke);
extern u32 BTL_CALC_MulRatioMin1(u32 value, u32 ratio);
extern void BTL_EVENT_MultiplyVar(int varId, int ratio);
extern void *BTL_POKEPARAM_GetMon(struct BtlPokeParam *poke);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 valueId, u32 arg);

void HAND_WAZA_EruptionOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddWringOut(int *handlerCount);
void HAND_WAZA_WringOutOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddBrine(int *handlerCount);
void HAND_WAZA_BrineOnPowerRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddReturn(int *handlerCount);
void HAND_WAZA_ReturnOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddFrustration(int *handlerCount);

extern BtlEventHandler gWringOutHandlers[];
extern BtlEventHandler gBrineHandlers[];
extern BtlEventHandler gReturnHandlers[];
extern BtlEventHandler gFrustrationHandlers[];

/* Eruption and Water Spout: the power falls with the user's remaining HP. */
void HAND_WAZA_EruptionOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *user;
    u32 hp;
    u32 maxHp;
    u32 power;
    u32 basePower;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        hp = func_021D59B4(user, BTL_VALUE_HP);
        maxHp = func_021D59B4(user, BTL_VALUE_MAX_HP);
        basePower = WAZA_TOOL_GetPower(BTL_EVENT_GetFactorKey(factor));
        power = basePower * hp / maxHp;
        if (power == 0)
            power = 1;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}

/* Wring Out and Crush Grip. */
BtlEventHandler *HAND_WAZA_AddWringOut(int *handlerCount)
{
    *handlerCount = 1;
    return gWringOutHandlers;
}

/* Wring Out and Crush Grip: 120 power at full HP of the target, scaled by its HP ratio. */
void HAND_WAZA_WringOutOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u32 power;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        power = BTL_CALC_MulRatioMin1(0x78, BTL_POKEPARAM_GetHpRatioFixed(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)))) / 100;
        if (power == 0)
            power = 1;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}

/* Brine. */
BtlEventHandler *HAND_WAZA_AddBrine(int *handlerCount)
{
    *handlerCount = 1;
    return gBrineHandlers;
}

/* Brine: double power when the target is at half HP or less. */
void HAND_WAZA_BrineOnPowerRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetHpRatioFixed(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))) <= 0x32 << 12)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 4 << 11);
    }
}

/* Return. */
BtlEventHandler *HAND_WAZA_AddReturn(int *handlerCount)
{
    *handlerCount = 1;
    return gReturnHandlers;
}

/* Return: power is the user's friendship times 10 over 25. */
void HAND_WAZA_ReturnOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u32 power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        power = (u32)(POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)), 9, 0) * 10) / 25;
        if (power == 0)
            power = 1;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}

/* Frustration. */
BtlEventHandler *HAND_WAZA_AddFrustration(int *handlerCount)
{
    *handlerCount = 1;
    return gFrustrationHandlers;
}
