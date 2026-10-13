/*
 * file:     unit_021DE7E4.c
 * unit:     yes
 * function: func_021DE7E4, func_021DE828
 * address:  0x021DE7E4
 * packet:   pkt_ov093_021DE7E4
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
 *   func_021D6D54  0x021D6D54  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F14AC     0x021F14AC  data   a4
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *flow, int pokeId);
extern u16 func_021D5444(void *pokeParam);
extern int func_021D6D54(void *pokeParam);
extern void func_021D7704(int key, int multiplier);
extern int d_021F14AC;

void func_021DE7E4(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *defender;
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        defender = func_021C7CF4(flow, pokeId);
        if (func_021D5444(defender) == BTL_ITEM_DITTO_SPECIES && func_021D6D54(defender) == 0) {
            if (func_021D775C(BTL_EVAR_DAMAGE_TYPE) == 1)
                func_021D7704(BTL_EVAR_POWER_RATIO, 4 << 11);
        }
    }
}

int *func_021DE828(int *count)
{
    *count = 1;
    return &d_021F14AC;
}
