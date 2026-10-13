/*
 * file:     unit_021DF974.c
 * function: func_021DF974, func_021DF9BC
 * address:  0x021DF974
 * packet:   pkt_ov093_021DF974
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F157C     0x021F157C  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 */
#include "unit_021DF974_types.h"

extern BtlEventHandler d_021F157C[];

/* Lustrous Orb: Palkia's Dragon and Water moves get the item's power ratio. */
void func_021DF974(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId != func_021D775C(BTL_EVAR_ATTACKER_ID))
        return;
    if (func_021D5444(func_021C7CF4(flow, pokeId)) != SPECIES_PALKIA)
        return;
    moveType = func_021D775C(BTL_EVAR_MOVE_TYPE);
    if (moveType == POKETYPE_DRAGON || moveType == POKETYPE_WATER)
        func_021D7704(BTL_EVAR_MOVE_POWER_RATIO, func_021DD008(factor));
}

/* Adamant Orb handler table: one handler, move power. */
BtlEventHandler *func_021DF9BC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F157C;
}
