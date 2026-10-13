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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F0690 0x021F0690 data a4
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   d_021F07A8     0x021F07A8  data   ov093  a4
 */
#include "unit_021DBAF0_types.h"

extern int func_021D775C(int key);
extern struct BtlPokeParam *func_021C7CF4(struct BtlServerFlow *flow, int pokeId);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern u32 func_021D7B60(struct BtlPokeParam *bpp, u32 divisor);
extern void func_021D7704(int key, int ratio);
extern int func_021D5B48(struct BtlPokeParam *bpp);
void func_021DC0BC(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *func_021DC0F8(int *handlerCount);
void func_021DC104(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *func_021DC130(int *handlerCount);
extern int d_021F0690;
extern int d_021F07A8[];

/* Defeatist: at half hit points or less, the power of the owner is halved. */
void func_021DC0BC(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    struct BtlPokeParam *owner;
    u32 hp;
    if (ownerId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        owner = func_021C7CF4(flow, ownerId);
        hp = func_021D59B4(owner, BTL_POKEPARAM_VALUE_HP);
        if (hp <= func_021D7B60(owner, 2)) {
            func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_5);
        }
    }
}

int *func_021DC0F8(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F07A8;
}

/* Multiscale: at full hit points, damage to the owner is halved. */
void func_021DC104(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021D5B48(func_021C7CF4(flow, ownerId)))
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

int *func_021DC130(int *handlerCount) { *handlerCount = 1; return &d_021F0690; }
