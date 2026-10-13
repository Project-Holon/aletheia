/*
 * file:     unit_021DE834.c
 * unit:     yes
 * function: func_021DE834, func_021DE878, func_021DE8B4
 * address:  0x021DE834
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
 *   func_021D6D54  0x021D6D54  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F16AC     0x021F16AC  data   a4
 *   d_021F13A4     0x021F13A4  data   a4
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *flow, int pokeId);
extern u16 func_021D5444(void *pokeParam);
extern int func_021D6D54(void *pokeParam);
extern void func_021D7704(int key, int multiplier);
extern int d_021F16AC;
extern int d_021F13A4;

void func_021DE834(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *pokeParam;
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        pokeParam = func_021C7CF4(flow, pokeId);
        if (func_021D5444(pokeParam) == BTL_ITEM_DITTO_SPECIES && func_021D6D54(pokeParam) == 0)
            func_021D7704(BTL_EVAR_POWER_RATIO, 2 << 12);
    }
}

int *func_021DE86C(int *count)
{
    *count = 2;
    return &d_021F16AC;
}

/* Soul Dew: Latias and Latios (species 380, 381) get 1.5 times special attack. */
void func_021DE878(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if ((u32)func_021D5444(func_021C7CF4(flow, pokeId)) - 380 <= 1) {
            if (func_021D775C(BTL_EVAR_DAMAGE_TYPE) == 2)
                func_021D7704(BTL_EVAR_POWER_RATIO, 6144);
        }
    }
}

/* Soul Dew: the same species get 1.5 times special defense. */
void func_021DE8B4(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        if ((u32)func_021D5444(func_021C7CF4(flow, pokeId)) - 380 <= 1) {
            if (func_021D775C(BTL_EVAR_DAMAGE_TYPE) == 2)
                func_021D7704(BTL_EVAR_POWER_RATIO, 6 << 10);
        }
    }
}

int *func_021DE8F0(int *count)
{
    *count = 1;
    return &d_021F13A4;
}
