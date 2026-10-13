/*
 * file:     unit_021DE7E4.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_MetalPowder_DoubleDefense, BTL_HANDLER_ITEM_GetQuickPowderHandlers
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F14AC     0x021F14AC  data   a4
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(void *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetSpecies(void *pokeParam);
extern int BTL_POKEPARAM_IsTransformed(void *pokeParam);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern int d_021F14AC;

void BTL_HANDLER_ITEM_MetalPowder_DoubleDefense(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *defender;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        defender = func_021C7CF4(flow, pokeId);
        if (BTL_POKEPARAM_GetSpecies(defender) == BTL_ITEM_DITTO_SPECIES && BTL_POKEPARAM_IsTransformed(defender) == 0) {
            if (BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == 1)
                BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 4 << 11);
        }
    }
}

int *BTL_HANDLER_ITEM_GetQuickPowderHandlers(int *count)
{
    *count = 1;
    return &d_021F14AC;
}
