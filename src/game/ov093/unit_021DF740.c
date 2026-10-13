/*
 * file:     unit_021DF740.c
 * function: func_021DF740, func_021DF74C
 * address:  0x021DF740
 * packet:   pkt_ov093_021DF740
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F13B4     0x021F13B4  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F13B4[];

void func_021DF740(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF74C(int *handlerCount);

/* Miracle Seed. */
void func_021DF740(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_GRASS);
}

/* Black Glasses. */
const BtlEventHandler *func_021DF74C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F13B4;
}
