/*
 * file:     hand_waza_021e14e4.c
 * unit:     yes
 * function: HAND_WAZA_SonicBoomOnCalcFixedDamage, HAND_WAZA_AddEndeavor, HAND_WAZA_EndeavorOnNoEffectCheck, HAND_WAZA_EndeavorOnCalcFixedDamage, HAND_WAZA_AddLevelDamage, HAND_WAZA_LevelDamageOnCalcFixedDamage, HAND_WAZA_AddPsywave
 * address:  0x021E14E4
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
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   gEndeavorHandlers     0x021F2938  data   ov093  a4
 *   gLevelDamageHandlers     0x021F2554  data   ov093  a4
 *   gPsywaveHandlers     0x021F2494  data   ov093  a4
 */
#include "hand_waza_021e10d8_types.h"

void HAND_WAZA_SonicBoomOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddEndeavor(int *handlerCount);
void HAND_WAZA_EndeavorOnNoEffectCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_EndeavorOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddLevelDamage(int *handlerCount);
void HAND_WAZA_LevelDamageOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddPsywave(int *handlerCount);
extern BtlEventHandler gEndeavorHandlers[];
extern BtlEventHandler gLevelDamageHandlers[];
extern BtlEventHandler gPsywaveHandlers[];

/* Sonic Boom, event CALC_FIXED_DAMAGE: 20 damage. */
void HAND_WAZA_SonicBoomOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, 20);
}

/* Endeavor: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddEndeavor(int *handlerCount)
{
    *handlerCount = 2;
    return gEndeavorHandlers;
}

/* Endeavor, event NO_EFFECT_CHECK: no effect when the target has no more HP than the user. */
void HAND_WAZA_EndeavorOnNoEffectCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *defender;
    struct BtlPokeParam *attacker;
    u8 defenderId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        defenderId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
        defender = BTL_SERVER_FLOW_GetPokeParam(flow, defenderId);
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (func_021D59B4(defender, BPP_VALUE_HP) - func_021D59B4(attacker, BPP_VALUE_HP) <= 0) {
            BTL_EVENT_OverwriteVar(HANDVAR_NO_EFFECT_FLAG, 1);
        }
    }
}

/* Endeavor, event CALC_FIXED_DAMAGE: the target's HP minus the user's HP. */
void HAND_WAZA_EndeavorOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *attacker;
    int damage;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        damage = func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID)), BPP_VALUE_HP) - func_021D59B4(attacker, BPP_VALUE_HP);
        if (damage < 0) damage = 1;
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, damage);
    }
}

/* Seismic Toss and Night Shade: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddLevelDamage(int *handlerCount)
{
    *handlerCount = 1;
    return gLevelDamageHandlers;
}

/* Seismic Toss and Night Shade, event CALC_FIXED_DAMAGE: damage equal to the user's level. */
void HAND_WAZA_LevelDamageOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    int level;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    level = (unsigned char)func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_VALUE_LEVEL);
    BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, level);
}

/* Psywave (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddPsywave(int *handlerCount)
{
    *handlerCount = 1;
    return gPsywaveHandlers;
}
