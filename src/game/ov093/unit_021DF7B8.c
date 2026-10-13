/*
 * file:     unit_021DF7B8.c
 * function: func_021DF7B8, func_021DF7C4
 * address:  0x021DF7B8
 * packet:   pkt_ov093_021DF7B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F144C     0x021F144C  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F144C[];

void func_021DF7B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF7C4(int *handlerCount);

/* Mystic Water. */
void func_021DF7B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_WATER);
}

/* Sharp Beak. */
const BtlEventHandler *func_021DF7C4(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F144C;
}
