/*
 * file:     unit_021DE834.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_QuickPowder_DoubleSpeed, BTL_HANDLER_ITEM_SoulDew_BoostSpAttack, BTL_HANDLER_ITEM_SoulDew_BoostSpDefense
 * address:  0x021DE834
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F16AC     0x021F16AC  data   a4
 *   d_021F13A4     0x021F13A4  data   a4
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(void *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetSpecies(void *pokeParam);
extern int BTL_POKEPARAM_IsTransformed(void *pokeParam);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern int d_021F16AC;
extern int d_021F13A4;

void BTL_HANDLER_ITEM_QuickPowder_DoubleSpeed(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *pokeParam;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        pokeParam = func_021C7CF4(flow, pokeId);
        if (BTL_POKEPARAM_GetSpecies(pokeParam) == BTL_ITEM_DITTO_SPECIES && BTL_POKEPARAM_IsTransformed(pokeParam) == 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 2 << 12);
    }
}

int *BTL_HANDLER_ITEM_GetSoulDewHandlers(int *count)
{
    *count = 2;
    return &d_021F16AC;
}

/* Soul Dew: Latias and Latios (species 380, 381) get 1.5 times special attack. */
void BTL_HANDLER_ITEM_SoulDew_BoostSpAttack(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if ((u32)BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) - 380 <= 1) {
            if (BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == 2)
                BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 6144);
        }
    }
}

/* Soul Dew: the same species get 1.5 times special defense. */
void BTL_HANDLER_ITEM_SoulDew_BoostSpDefense(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if ((u32)BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) - 380 <= 1) {
            if (BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == 2)
                BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 6 << 10);
        }
    }
}

int *BTL_HANDLER_ITEM_GetThickClubHandlers(int *count)
{
    *count = 1;
    return &d_021F13A4;
}
