/*
 * file:     hand_waza_021e30f8.c
 * unit:     yes
 * function: HAND_WAZA_BlizzardOnHitCheck, HAND_WAZA_AddEarthquake, HAND_WAZA_EarthquakeOnInvulnerableCheck, HAND_WAZA_EarthquakeOnDamageRatio
 * address:  0x021E30F8
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
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gJudgmentHandlers  0x021F25F4  data   a4
 *   gEarthquakeHandlers     0x021F2A58  data   ov093  a4
 */
#include "hand_waza_021e2988_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(struct BtlSvFlow *flow);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *poke, u32 contFlag);
extern void BTL_EVENT_MultiplyVar(int varId, s32 ratio);

void HAND_WAZA_BlizzardOnHitCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddEarthquake(int *handlerCount);
void HAND_WAZA_EarthquakeOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_EarthquakeOnDamageRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddJudgment(int *handlerCount);

extern BtlEventHandler gJudgmentHandlers[];
extern BtlEventHandler gEarthquakeHandlers[];

/* Blizzard: it never misses in hail. */
void HAND_WAZA_BlizzardOnHitCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_HAIL)
            BTL_EVENT_OverwriteVar(BTL_EVAR_HANDLED_FLAG, 1);
    }
}

/* Earthquake. */
BtlEventHandler *HAND_WAZA_AddEarthquake(int *handlerCount)
{
    *handlerCount = 2;
    return gEarthquakeHandlers;
}

/* Earthquake and Magnitude: they can hit a target that is underground (Dig). */
void HAND_WAZA_EarthquakeOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIDE_KIND) == BTL_CONT_FLAG_DIGGING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_FLAG, 0);
    }
}

/* Earthquake and Magnitude: double damage against a target that is underground. */
void HAND_WAZA_EarthquakeOnDamageRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_CONT_FLAG_DIGGING) != 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_DAMAGE_RATIO, BTL_RATIO_DOUBLE);
    }
}

/* Judgment. */
BtlEventHandler *HAND_WAZA_AddJudgment(int *handlerCount)
{
    *handlerCount = 1;
    return gJudgmentHandlers;
}
