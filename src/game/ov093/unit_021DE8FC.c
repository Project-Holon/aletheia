/*
 * file:     unit_021DE8FC.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_ThickClub_DoubleAttack, BTL_HANDLER_ITEM_GetChoiceBandHandlers
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F18D4     0x021F18D4  data   a4
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(void *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetSpecies(void *pokeParam);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern int d_021F18D4;

/* Thick Club: Cubone and Marowak (species 104, 105) double their physical attack. */
void BTL_HANDLER_ITEM_ThickClub_DoubleAttack(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if ((u32)BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) - 0x68 <= 1) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 1)
                BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 2 << 12);
        }
    }
}

int *BTL_HANDLER_ITEM_GetChoiceBandHandlers(int *count)
{
    *count = 3;
    return &d_021F18D4;
}
