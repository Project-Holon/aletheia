/*
 * file:     unit_021DE79C.c
 * unit:     yes
 * function: func_021DE79C, func_021DE7D8
 * address:  0x021DE79C
 * packet:   pkt_ov093_021DE79C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F1454     0x021F1454  data   a4
 */
#include "unit_021DDC44_types.h"

extern int func_021D775C(int varId);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern u16 func_021D5444(struct BtlPokeParam *poke);
extern void func_021D7704(int varId, int ratio);
extern int d_021F1454;

/* Deep Sea Scale, defense ratio event: doubles the special defense of a Clamperl (the holder is the defender). */
void func_021DE79C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        if (func_021D5444(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_CLAMPERL) {
            if (func_021D775C(BTL_EVAR_MOVE_CATEGORY) == BTL_MOVE_CATEGORY_SPECIAL)
                func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_DOUBLE);
        }
    }
}

/* Handler table getter of Metal Powder. */
int *func_021DE7D8(int *handlerCount)
{
    *handlerCount = 1;
    return &d_021F1454;
}
