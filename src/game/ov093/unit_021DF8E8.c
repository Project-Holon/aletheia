/*
 * file:     unit_021DF8E8.c
 * unit:     yes
 * function: func_021DF8E8, func_021DF8F4, func_021DF900, func_021DF90C, func_021DF918, func_021DF924, func_021DF930, func_021DF93C, func_021DF968
 * address:  0x021DF8E8
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
 *   d_021F1544     0x021F1544  data   ov093  a4
 *   d_021F14DC     0x021F14DC  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 *   d_021F1414     0x021F1414  data    a4
 *   d_021F141C     0x021F141C  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F1544[];
extern const BtlEventHandler d_021F14DC[];
extern const BtlEventHandler d_021F1414[];
extern const BtlEventHandler d_021F141C[];

void func_021DF8E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF8F4(int *handlerCount);
void func_021DF900(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF90C(int *handlerCount);
void func_021DF918(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF924(int *handlerCount);
void func_021DF930(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DF93C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int moveType);
const BtlEventHandler *func_021DF968(int *handlerCount);

/* Rock Incense. */
void func_021DF8E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_ROCK);
}

/* Sea Incense. */
const BtlEventHandler *func_021DF8F4(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1544;
}

/* Sea Incense. */
void func_021DF900(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_WATER);
}

/* Wave Incense. */
const BtlEventHandler *func_021DF90C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F14DC;
}

/* Wave Incense. */
void func_021DF918(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_WATER);
}

/* Rose Incense. */
const BtlEventHandler *func_021DF924(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1414;
}

/* Rose Incense. */
void func_021DF930(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_GRASS);
}

/*
 * Type boost items: when the holder attacks with a move of the given type,
 * scale the move power by the ratio that the item parameter gives.
 */
void func_021DF93C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int moveType)
{
    if (pokeId != func_021D775C(BTL_EVAR_ATTACKER_ID))
        return;
    if (moveType != func_021D775C(BTL_EVAR_MOVE_TYPE))
        return;
    func_021D7704(BTL_EVAR_MOVE_POWER_RATIO, func_021DD008(factor));
}

/* Lustrous Orb. */
const BtlEventHandler *func_021DF968(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F141C;
}
