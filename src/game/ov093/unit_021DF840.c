/*
 * file:     unit_021DF840.c
 * unit:     yes
 * function: func_021DF840, func_021DF84C, func_021DF858, func_021DF864
 * address:  0x021DF840
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
 *   d_021F15BC     0x021F15BC  data   ov093  a4
 *   d_021F1484     0x021F1484  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F15BC[];
extern const BtlEventHandler d_021F1484[];

void func_021DF840(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF84C(int *handlerCount);
void func_021DF858(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF864(int *handlerCount);

/* Never-Melt Ice. */
void func_021DF840(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_ICE);
}

/* Spell Tag. */
const BtlEventHandler *func_021DF84C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F15BC;
}

/* Spell Tag. */
void func_021DF858(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_GHOST);
}

/* Twisted Spoon. */
const BtlEventHandler *func_021DF864(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1484;
}
