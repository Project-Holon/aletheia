/*
 * file:     unit_021DE6CC.c
 * unit:     yes
 * function: func_021DE6CC, func_021DE70C, func_021DE74C
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F148C     0x021F148C  data   ov093  a4
 *   d_021F13EC     0x021F13EC  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   d_021F139C     0x021F139C  data   a4
 */
#include "unit_021DDC44_types.h"

extern int func_021D775C(int varId);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern int func_021DD008(struct BtlEventFactor *factor);
extern void func_021D7704(int varId, int ratio);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern u16 func_021D5444(struct BtlPokeParam *poke);
void func_021DE6CC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021DE700(int *handlerCount);
void func_021DE70C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021DE740(int *handlerCount);
void func_021DE74C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021DE790(int *handlerCount);
extern int d_021F148C;
extern int d_021F13EC;
extern int d_021F139C;


/* Muscle Band, move power event: boosts physical moves by the item percent. */
void func_021DE6CC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == BTL_MOVE_CATEGORY_PHYSICAL)
            func_021D7704(BTL_EVAR_POWER_RATIO, func_021DD008(factor));
    }
}


/* Handler table getter of Wise Glasses. */
int *func_021DE700(int *handlerCount)
{
    *handlerCount = 1;
    return &d_021F148C;
}


/* Wise Glasses, move power event: boosts special moves by the item percent. */
void func_021DE70C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == BTL_MOVE_CATEGORY_SPECIAL)
            func_021D7704(BTL_EVAR_POWER_RATIO, func_021DD008(factor));
    }
}


/* Handler table getter of Deep Sea Tooth. */
int *func_021DE740(int *handlerCount)
{
    *handlerCount = 1;
    return &d_021F13EC;
}


/* Deep Sea Tooth, attack ratio event: doubles the special attack of a Clamperl. */
void func_021DE74C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (func_021D5444(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_CLAMPERL) {
            if (WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == BTL_MOVE_CATEGORY_SPECIAL)
                func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_DOUBLE);
        }
    }
}


/* Handler table getter of Deep Sea Scale. */
int *func_021DE790(int *handlerCount)
{
    *handlerCount = 1;
    return &d_021F139C;
}
