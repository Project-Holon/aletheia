/*
 * file:     hand_waza_021e3050.c
 * unit:     yes
 * function: HAND_WAZA_SkyUppercutOnInvulnerableCheck, HAND_WAZA_AddThunder, HAND_WAZA_ThunderOnInvulnerableCheck, HAND_WAZA_ThunderOnHitCheck, HAND_WAZA_ThunderOnAccuracyCheck, HAND_WAZA_AddBlizzard
 * address:  0x021E3050
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   gThunderHandlers     0x021F2D08  data   ov093  a4
 *   gBlizzardHandlers     0x021F246C  data   ov093  a4
 */
#include "hand_waza_021e2988_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(struct BtlSvFlow *flow);

void HAND_WAZA_SkyUppercutOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddThunder(int *handlerCount);
void HAND_WAZA_ThunderOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_ThunderOnHitCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_ThunderOnAccuracyCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddBlizzard(int *handlerCount);

extern BtlEventHandler gThunderHandlers[];
extern BtlEventHandler gBlizzardHandlers[];

/* Sky Uppercut: it can hit a target that flies high (Fly, Bounce). */
void HAND_WAZA_SkyUppercutOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIDE_KIND) == BTL_CONT_FLAG_FLYING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_FLAG, 0);
    }
}

/* Thunder and Hurricane. */
BtlEventHandler *HAND_WAZA_AddThunder(int *handlerCount)
{
    *handlerCount = 3;
    return gThunderHandlers;
}

/* Thunder and Hurricane: they can hit a target that flies high. */
void HAND_WAZA_ThunderOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_HIDE_KIND) == BTL_CONT_FLAG_FLYING)
            BTL_EVENT_OverwriteVar(BTL_EVAR_AVOID_FLAG, 0);
    }
}

/* Thunder and Hurricane: they never miss in rain. */
void HAND_WAZA_ThunderOnHitCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_RAIN)
            BTL_EVENT_OverwriteVar(BTL_EVAR_HANDLED_FLAG, 1);
    }
}

/* Thunder and Hurricane: the accuracy falls to 50 in harsh sunlight. */
void HAND_WAZA_ThunderOnAccuracyCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SUN)
            BTL_EVENT_OverwriteVar(BTL_EVAR_ACCURACY, 0x32);
    }
}

/* Blizzard. */
BtlEventHandler *HAND_WAZA_AddBlizzard(int *handlerCount)
{
    *handlerCount = 1;
    return gBlizzardHandlers;
}
