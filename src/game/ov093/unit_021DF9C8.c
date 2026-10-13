/*
 * file:     unit_021DF9C8.c
 * unit:     yes
 * function: func_021DF9C8, func_021DFA14, func_021DFA20, func_021DFA3C, func_021DFA54, func_021DFA60, func_021DFA7C, func_021DFA88, func_021DFAB0
 * address:  0x021DF9C8
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
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D76BC   0x021D76BC  thumb
 *   d_021F166C     0x021F166C  data   ov093  a4
 *   d_021F1504     0x021F1504  data   ov093  a4
 *   func_021C818C  0x021C818C  thumb  ov093
 *   d_021F14FC     0x021F14FC  data   ov093  a4
 *   d_021F140C     0x021F140C  data   ov093  a4
 */
#include "unit_021DF974_types.h"

extern BtlEventHandler d_021F166C[];
extern BtlEventHandler d_021F1504[];
extern BtlEventHandler d_021F14FC[];
extern BtlEventHandler d_021F140C[];

/* Adamant Orb: Dialga's Dragon and Steel moves get the item's power ratio. */
void func_021DF9C8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId != func_021D775C(BTL_EVAR_ATTACKER_ID))
        return;
    if (func_021D5444(func_021C7CF4(flow, pokeId)) != SPECIES_DIALGA)
        return;
    moveType = func_021D775C(BTL_EVAR_MOVE_TYPE);
    if (moveType == POKETYPE_DRAGON || moveType == POKETYPE_STEEL)
        func_021D7704(BTL_EVAR_MOVE_POWER_RATIO, func_021DD008(factor));
}

/* Iron Ball handler table: speed ratio and ground check. */
BtlEventHandler *func_021DFA14(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F166C;
}

/* Iron Ball: halves the speed of the holder. */
void func_021DFA20(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int keyAndShift = 2; /* the same 2 is the poke id key and the shift of the 0.5 ratio */

    if (pokeId == func_021D775C(keyAndShift))
        func_021D7704(BTL_EVAR_RATIO, keyAndShift << 10);
}

/* Iron Ball: the holder counts as grounded. */
void func_021DFA3C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D76BC(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

/* Float Stone handler table: weight ratio. */
BtlEventHandler *func_021DFA54(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1504;
}

/* Float Stone: halves the weight of the holder. */
void func_021DFA60(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int keyAndShift = 2; /* the same 2 is the poke id key and the shift of the 0.5 ratio */

    if (pokeId == func_021D775C(keyAndShift))
        func_021D7704(BTL_EVAR_RATIO, keyAndShift << 10);
}

/* Eviolite handler table: defense ratio. */
BtlEventHandler *func_021DFA7C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F14FC;
}

/* Eviolite: x1.5 defense while the holder can still evolve. */
void func_021DFA88(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021C818C(flow, pokeId))
        func_021D7704(BTL_EVAR_RATIO, 6 << 10);
}

/* Rocky Helmet handler table: damage reaction. */
BtlEventHandler *func_021DFAB0(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F140C;
}
