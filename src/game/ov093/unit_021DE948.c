/*
 * file:     unit_021DE948.c
 * unit: yes
 * function: func_021DE948, func_021DE974
 * address: 0x021DE948
 * packet: pkt_ov093_021DE948
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DE974.
 * symbols:
 *   d_021F18EC 0x021F18EC data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int func_021D775C(int key);
extern void func_021D7704(int key, int multiplier);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern int d_021F18EC;

/* Choice Band: 1.5 times power for physical moves. */
void func_021DE948(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == 1)
            func_021D7704(BTL_EVAR_POWER_RATIO, 6144);
    }
}

int *func_021DE974(int *count)
{
    *count = 3;
    return &d_021F18EC;
}
