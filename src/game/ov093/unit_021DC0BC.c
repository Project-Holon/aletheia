/*
 * file:     unit_021DC0BC.c
 * unit:     yes
 * function: func_021DC0BC, func_021DC0F8, func_021DC104, func_021DC130
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gMultiscaleHandlers 0x021F0690 data a4
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   gDefeatistHandlers     0x021F07A8  data   ov093  a4
 */
#include "unit_021DBAF0_types.h"

extern int BTL_EVENT_GetVar(int key);
extern struct BtlPokeParam *func_021C7CF4(struct BtlServerFlow *flow, int pokeId);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);
void func_021DC0BC(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *func_021DC0F8(int *handlerCount);
void func_021DC104(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *func_021DC130(int *handlerCount);
extern int gMultiscaleHandlers;
extern int gDefeatistHandlers[];

/* Defeatist: at half hit points or less, the power of the owner is halved. */
void func_021DC0BC(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    struct BtlPokeParam *owner;
    u32 hp;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        owner = func_021C7CF4(flow, ownerId);
        hp = func_021D59B4(owner, BTL_POKEPARAM_VALUE_HP);
        if (hp <= BTL_CALC_DivideMaxHp(owner, 2)) {
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
        }
    }
}

int *func_021DC0F8(int *handlerCount)
{
    *handlerCount = 1;
    return gDefeatistHandlers;
}

/* Multiscale: at full hit points, damage to the owner is halved. */
void func_021DC104(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_POKEPARAM_IsHpFull(func_021C7CF4(flow, ownerId)))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

int *func_021DC130(int *handlerCount) { *handlerCount = 1; return &gMultiscaleHandlers; }
