/*
 * file:     unit_021DF870.c
 * unit:     yes
 * function: func_021DF870, func_021DF87C, func_021DF888, func_021DF894, func_021DF8A0, func_021DF8AC, func_021DF8B8, func_021DF8C4, func_021DF8D0, func_021DF8DC
 * address:  0x021DF870
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
 *   d_021F15E4     0x021F15E4  data   ov093  a4
 *   d_021F15DC     0x021F15DC  data   ov093  a4
 *   d_021F159C     0x021F159C  data   ov093  a4
 *   d_021F155C     0x021F155C  data   ov093  a4
 *   d_021F1404     0x021F1404  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F15E4[];
extern const BtlEventHandler d_021F15DC[];
extern const BtlEventHandler d_021F159C[];
extern const BtlEventHandler d_021F155C[];
extern const BtlEventHandler d_021F1404[];

void func_021DF870(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF87C(int *handlerCount);
void func_021DF888(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF894(int *handlerCount);
void func_021DF8A0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF8AC(int *handlerCount);
void func_021DF8B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF8C4(int *handlerCount);
void func_021DF8D0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF8DC(int *handlerCount);

/* Twisted Spoon. */
void func_021DF870(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_PSYCHIC);
}

/* Charcoal. */
const BtlEventHandler *func_021DF87C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F15E4;
}

/* Charcoal. */
void func_021DF888(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_FIRE);
}

/* Dragon Fang. */
const BtlEventHandler *func_021DF894(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F15DC;
}

/* Dragon Fang. */
void func_021DF8A0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_DRAGON);
}

/* Silk Scarf. */
const BtlEventHandler *func_021DF8AC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F159C;
}

/* Silk Scarf. */
void func_021DF8B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_NORMAL);
}

/* Odd Incense. */
const BtlEventHandler *func_021DF8C4(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F155C;
}

/* Odd Incense. */
void func_021DF8D0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_PSYCHIC);
}

/* Rock Incense. */
const BtlEventHandler *func_021DF8DC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1404;
}
