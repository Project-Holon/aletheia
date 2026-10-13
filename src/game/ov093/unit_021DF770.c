/*
 * file:     unit_021DF770.c
 * unit:     yes
 * function: func_021DF770, func_021DF77C, func_021DF788, func_021DF794
 * address:  0x021DF770
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
 *   func_021DF93C  0x021DF93C  thumb  ov093
 *   d_021F14C4     0x021F14C4  data   ov093  a4
 *   d_021F13C4     0x021F13C4  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F14C4[];
extern const BtlEventHandler d_021F13C4[];

void func_021DF770(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF77C(int *handlerCount);
void func_021DF788(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF794(int *handlerCount);

/* Black Belt. */
void func_021DF770(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_FIGHTING);
}

/* Magnet. */
const BtlEventHandler *func_021DF77C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F14C4;
}

/* Magnet. */
void func_021DF788(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_ELECTRIC);
}

/* Metal Coat. */
const BtlEventHandler *func_021DF794(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F13C4;
}
