/*
 * file:     unit_021DF7A0.c
 * function: func_021DF7A0, func_021DF7AC
 * address:  0x021DF7A0
 * packet:   pkt_ov093_021DF7A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F1444     0x021F1444  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F1444[];

void func_021DF7A0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF7AC(int *handlerCount);

/* Metal Coat. */
void func_021DF7A0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_STEEL);
}

/* Mystic Water. */
const BtlEventHandler *func_021DF7AC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1444;
}
