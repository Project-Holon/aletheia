/*
 * file:     hand_waza_021e1478.c
 * unit:     yes
 * function: HAND_WAZA_SuperFangOnCalcFixedDamage, HAND_WAZA_AddDragonRage, HAND_WAZA_DragonRageOnCalcFixedDamage, HAND_WAZA_AddSonicBoom
 * address:  0x021E1478
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gDragonRageHandlers     0x021F26EC  data   ov093  a4
 *   gSonicBoomHandlers     0x021F256C  data   ov093  a4
 */
#include "hand_waza_021e10d8_types.h"

void HAND_WAZA_SuperFangOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddDragonRage(int *handlerCount);
void HAND_WAZA_DragonRageOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSonicBoom(int *handlerCount);
extern BtlEventHandler gDragonRageHandlers[];
extern BtlEventHandler gSonicBoomHandlers[];

/* Super Fang, event CALC_FIXED_DAMAGE: half of the target's current HP, at least 1. */
void HAND_WAZA_SuperFangOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    int hp;
    u16 damage;
    u8 defenderId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        defenderId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
        hp = func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, defenderId), BPP_VALUE_HP);
        damage = hp / 2;
        if (damage == 0) damage = 1;
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, damage);
    }
}

/* Dragon Rage: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddDragonRage(int *handlerCount)
{
    *handlerCount = 1;
    return gDragonRageHandlers;
}

/* Dragon Rage, event CALC_FIXED_DAMAGE: 40 damage. */
void HAND_WAZA_DragonRageOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, 40);
}

/* Sonic Boom (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSonicBoom(int *handlerCount)
{
    *handlerCount = 1;
    return gSonicBoomHandlers;
}
