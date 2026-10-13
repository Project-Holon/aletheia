/*
 * file:     hand_waza_021e2ed4.c
 * unit:     yes
 * function: HAND_WAZA_LowKickOnWazaPower, HAND_WAZA_WeatherBallOnWazaTypeCheck, HAND_WAZA_WeatherBallOnWazaPower, HAND_WAZA_AddGust, HAND_WAZA_GustOnInvulnerableCheck, HAND_WAZA_GustOnWazaPower
 * address:  0x021E2ED4
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
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_CalcPokeWeight  0x021C83A0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gWeatherBallHandlers     0x021F2A18  data  ov093  a4
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   gSkyUppercutHandlers  0x021F2464  data   ov093  a4
 *   gGustHandlers     0x021F2A28  data   ov093  a4
 */
#include "hand_waza_021e2988_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *poke);
extern u32 BTL_SERVER_FLOW_CalcPokeWeight(struct BtlSvFlow *flow, int pokeId);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(struct BtlSvFlow *flow);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(struct BtlSvFlow *flow, int variant);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *poke, u32 contFlag);
extern void BTLV_CORE_EventScaleDamage(int ratio);

void HAND_WAZA_LowKickOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddWeatherBall(int *handlerCount);
void HAND_WAZA_WeatherBallOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_WeatherBallOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddGust(int *handlerCount);
void HAND_WAZA_GustOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_GustOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddSkyUppercut(int *handlerCount);

extern BtlEventHandler gWeatherBallHandlers[];
extern BtlEventHandler gSkyUppercutHandlers[];
extern BtlEventHandler gGustHandlers[];

/* Low Kick and Grass Knot: power from the weight of the target (in tenths of a kilogram). */
void HAND_WAZA_LowKickOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u32 weight;
    int power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        weight = BTL_SERVER_FLOW_CalcPokeWeight(flow, BTL_POKEPARAM_GetPokeId(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))));
        if (weight >= 2000) {
            power = 0x78;
        } else if (weight >= 1000) {
            power = 100;
        } else if (weight >= 500) {
            power = 80;
        } else if (weight >= 250) {
            power = 60;
        } else {
            power = 40;
            if (weight < 100)
                power = 20;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}

/* Weather Ball. */
BtlEventHandler *HAND_WAZA_AddWeatherBall(int *handlerCount)
{
    *handlerCount = 2;
    return gWeatherBallHandlers;
}

/* Weather Ball: the type and the animation variant follow the weather. */
void HAND_WAZA_WeatherBallOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    int variant;
    int weather;
    u8 type;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        weather = BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow);
        type = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
        variant = 0;
        switch (weather) {
        case BTL_WEATHER_SUN:
            type = POKETYPE_FIRE;
            variant = 1;
            break;
        case BTL_WEATHER_RAIN:
            type = POKETYPE_WATER;
            variant = 4;
            break;
        case BTL_WEATHER_SAND:
            type = POKETYPE_ROCK;
            variant = 3;
            break;
        case BTL_WEATHER_HAIL:
            type = POKETYPE_ICE;
            variant = 2;
            break;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, type);
        BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, variant);
    }
}

/* Weather Ball: double power in any weather. */
void HAND_WAZA_WeatherBallOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, BTL_EVENT_GetVar(BTL_EVAR_WAZA_POWER) * 2);
    }
}

/* Gust and Twister. */
BtlEventHandler *HAND_WAZA_AddGust(int *handlerCount)
{
    *handlerCount = 2;
    return gGustHandlers;
}

/* Gust and Twister: they can hit a target that flies high (Fly, Bounce). */
void HAND_WAZA_GustOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIDE_KIND) == BTL_CONT_FLAG_FLYING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_FLAG, 0);
    }
}

/* Gust and Twister: double damage against a target that flies high. */
void HAND_WAZA_GustOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_CONT_FLAG_FLYING) != 0)
            BTLV_CORE_EventScaleDamage(2);
    }
}

/* Sky Uppercut. */
BtlEventHandler *HAND_WAZA_AddSkyUppercut(int *handlerCount)
{
    *handlerCount = 1;
    return gSkyUppercutHandlers;
}
