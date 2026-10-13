/*
 * file:     unit_021DFCB8.c
 * function: func_021DFCB8, func_021DFCDC
 * address:  0x021DFCB8
 * packet:   pkt_ov093_021DFCB8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F1524     0x021F1524  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 */
#include "unit_021DF974_types.h"

extern BtlEventHandler d_021F1524[];

/* Ring Target: the holder as defender loses its type immunities. */
void func_021DFCB8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021C7EC4(flow) == 0 && pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID))
        func_021D76BC(BTL_EVAR_IMMUNITY_OVERRIDE_FLAG, 1);
}

/* Binding Band handler table. */
BtlEventHandler *func_021DFCDC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1524;
}
