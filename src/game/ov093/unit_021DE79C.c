/*
 * file:     unit_021DE79C.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_DeepSeaScaleDoubleSpDef, BTL_HANDLER_ITEM_GetMetalPowderHandlers
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gMetalPowderHandlerTable     0x021F1454  data   a4
 */
#include "unit_021DDC44_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *poke);
extern void BTL_EVENT_MultiplyVar(int varId, int ratio);
extern int gMetalPowderHandlerTable;

/* Deep Sea Scale, defense ratio event: doubles the special defense of a Clamperl (the holder is the defender). */
void BTL_HANDLER_ITEM_DeepSeaScaleDoubleSpDef(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_CLAMPERL) {
            if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_CATEGORY) == BTL_MOVE_CATEGORY_SPECIAL)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_DOUBLE);
        }
    }
}

/* Handler table getter of Metal Powder. */
int *BTL_HANDLER_ITEM_GetMetalPowderHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gMetalPowderHandlerTable;
}
