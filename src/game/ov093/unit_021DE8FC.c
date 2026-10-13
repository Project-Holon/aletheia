/*
 * file:     unit_021DE8FC.c
 * unit:     yes
 * function: func_021DE8FC, func_021DE93C
 * address:  0x021DE8FC
 * packet:   pkt_ov093_021DE8FC
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
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F18D4     0x021F18D4  data   a4
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *flow, int pokeId);
extern u16 func_021D5444(void *pokeParam);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern void func_021D7704(int key, int multiplier);
extern int d_021F18D4;

/* Thick Club: Cubone and Marowak (species 104, 105) double their physical attack. */
void func_021DE8FC(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if ((u32)func_021D5444(func_021C7CF4(flow, pokeId)) - 0x68 <= 1) {
            if (WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == 1)
                func_021D7704(BTL_EVAR_POWER_RATIO, 2 << 12);
        }
    }
}

int *func_021DE93C(int *count)
{
    *count = 3;
    return &d_021F18D4;
}
