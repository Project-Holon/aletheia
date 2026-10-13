/*
 * file:     unit_021DF758.c
 * function: func_021DF758, func_021DF764
 * address:  0x021DF758
 * packet:   pkt_ov093_021DF758
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F142C     0x021F142C  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F142C[];

void func_021DF758(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF764(int *handlerCount);

/* Black Glasses: 1.2 times power for Dark moves of the holder. */
void func_021DF758(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_DARK);
}

/* Black Belt. */
const BtlEventHandler *func_021DF764(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F142C;
}
