/*
 * file:     unit_021DE6CC.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_MuscleBandBoostPhysical, BTL_HANDLER_ITEM_WiseGlassesBoostSpecial, BTL_HANDLER_ITEM_DeepSeaToothDoubleSpAtk
 * address:  0x021DE6CC
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_HANDLER_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gWiseGlassesHandlerTable     0x021F148C  data   ov093  a4
 *   gDeepSeaToothHandlerTable     0x021F13EC  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   gDeepSeaScaleHandlerTable     0x021F139C  data   a4
 */
#include "unit_021DDC44_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern int BTL_HANDLER_ITEM_GetBoostRatio(struct BtlEventFactor *factor);
extern void BTL_EVENT_MultiplyVar(int varId, int ratio);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *poke);
void BTL_HANDLER_ITEM_MuscleBandBoostPhysical(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_HANDLER_ITEM_GetWiseGlassesHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_WiseGlassesBoostSpecial(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_HANDLER_ITEM_GetDeepSeaToothHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_DeepSeaToothDoubleSpAtk(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_HANDLER_ITEM_GetDeepSeaScaleHandlers(int *handlerCount);
extern int gWiseGlassesHandlerTable;
extern int gDeepSeaToothHandlerTable;
extern int gDeepSeaScaleHandlerTable;


/* Muscle Band, move power event: boosts physical moves by the item percent. */
void BTL_HANDLER_ITEM_MuscleBandBoostPhysical(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == BTL_MOVE_CATEGORY_PHYSICAL)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_HANDLER_ITEM_GetBoostRatio(factor));
    }
}


/* Handler table getter of Wise Glasses. */
int *BTL_HANDLER_ITEM_GetWiseGlassesHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gWiseGlassesHandlerTable;
}


/* Wise Glasses, move power event: boosts special moves by the item percent. */
void BTL_HANDLER_ITEM_WiseGlassesBoostSpecial(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == BTL_MOVE_CATEGORY_SPECIAL)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_HANDLER_ITEM_GetBoostRatio(factor));
    }
}


/* Handler table getter of Deep Sea Tooth. */
int *BTL_HANDLER_ITEM_GetDeepSeaToothHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gDeepSeaToothHandlerTable;
}


/* Deep Sea Tooth, attack ratio event: doubles the special attack of a Clamperl. */
void BTL_HANDLER_ITEM_DeepSeaToothDoubleSpAtk(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_CLAMPERL) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == BTL_MOVE_CATEGORY_SPECIAL)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_DOUBLE);
        }
    }
}


/* Handler table getter of Deep Sea Scale. */
int *BTL_HANDLER_ITEM_GetDeepSeaScaleHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gDeepSeaScaleHandlerTable;
}
