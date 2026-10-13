/*
 * file:     hand_tokusei_021dc0bc.c
 * unit:     yes
 * function: HAND_TOKUSEI_Defeatist_HalvePowerAtLowHp, HAND_TOKUSEI_GetDefeatistHandlers, HAND_TOKUSEI_Multiscale_HalveDamageAtFullHp, HAND_TOKUSEI_GetMultiscaleHandlers
 * address:  0x021DC0BC
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
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gMultiscaleHandlers 0x021F0690 data a4
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   gDefeatistHandlers     0x021F07A8  data   ov093  a4
 */
#include "hand_tokusei_021dbaf0_types.h"

extern int BTL_EVENT_GetVar(int key);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);
void HAND_TOKUSEI_Defeatist_HalvePowerAtLowHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *HAND_TOKUSEI_GetDefeatistHandlers(int *handlerCount);
void HAND_TOKUSEI_Multiscale_HalveDamageAtFullHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *HAND_TOKUSEI_GetMultiscaleHandlers(int *handlerCount);
extern int gMultiscaleHandlers;
extern int gDefeatistHandlers[];

/* Defeatist: at half hit points or less, the power of the owner is halved. */
void HAND_TOKUSEI_Defeatist_HalvePowerAtLowHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    struct BtlPokeParam *owner;
    u32 hp;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
        hp = func_021D59B4(owner, BTL_POKEPARAM_VALUE_HP);
        if (hp <= BTL_CALC_DivideMaxHp(owner, 2)) {
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
        }
    }
}

int *HAND_TOKUSEI_GetDefeatistHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gDefeatistHandlers;
}

/* Multiscale: at full hit points, damage to the owner is halved. */
void HAND_TOKUSEI_Multiscale_HalveDamageAtFullHp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_POKEPARAM_IsHpFull(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId)))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

int *HAND_TOKUSEI_GetMultiscaleHandlers(int *handlerCount) { *handlerCount = 1; return &gMultiscaleHandlers; }
