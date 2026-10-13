/*
 * file:     hand_waza_021e6164.c
 * function: HAND_WAZA_WeatherHealSetRatio, HAND_WAZA_GetFlyHandlers
 * address:  0x021E6164
 * packet:   pkt_ov093_021E6164
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gFlyHandlers     0x021F2A88  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
#include "hand_waza_021e5620_types.h"

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(struct BtlServerFlow *flow);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int gFlyHandlers[];

/* Weather ids as BTL_SERVER_FLOW_GetEffectiveWeatherThunk returns them. */
#define BTL_WEATHER_SUN 1
#define BTL_WEATHER_RAIN 2
#define BTL_WEATHER_SAND 3
#define BTL_WEATHER_HAIL 4

void HAND_WAZA_WeatherHealSetRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetFlyHandlers(int *handlerCount);

/* Morning Sun, Synthesis and Moonlight: the heal ratio (4096 based) depends on the weather. */
void HAND_WAZA_WeatherHealSetRatio(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int healRatio;
    if (pokeId != BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        return;
    switch (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow)) {
    case BTL_WEATHER_SUN:
        healRatio = 0xaac;
        break;
    case BTL_WEATHER_RAIN:
    case BTL_WEATHER_SAND:
    case BTL_WEATHER_HAIL:
        healRatio = 2 << 9;
        break;
    default:
        healRatio = 2 << 10;
        break;
    }
    BTL_EVENT_OverwriteVar(BTL_EVAR_HEAL_RATIO, healRatio);
}


/* Fly getter: two handler rows. */
int *HAND_WAZA_GetFlyHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gFlyHandlers;
}
