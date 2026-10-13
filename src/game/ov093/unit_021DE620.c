/*
 * file:     unit_021DE620.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_ZoomLensRaiseAccuracy, BTL_HANDLER_ITEM_LaxIncenseLowerAccuracy
 * address:  0x021DE620
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gLaxIncenseHandlerTable     0x021F1474  data   ov093  a4
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   gMuscleBandHandlerTable     0x021F13E4  data   a4
 */
#include "unit_021DDC44_types.h"

#define TURN_FLAG_ACTED 1   /* the Pokemon has acted this turn */

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *poke, u32 flag);
extern int BTL_HANDLER_ITEM_GetBoostRatio(struct BtlEventFactor *factor);
extern void BTL_EVENT_MultiplyVar(int varId, int ratio);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex);
void BTL_HANDLER_ITEM_ZoomLensRaiseAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_HANDLER_ITEM_GetLaxIncenseHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_LaxIncenseLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_HANDLER_ITEM_GetMuscleBandHandlers(int *handlerCount);
extern int gLaxIncenseHandlerTable;
extern int gMuscleBandHandlerTable;


/* Zoom Lens, accuracy event: raises the accuracy by the item percent when the defender has already acted. */
void BTL_HANDLER_ITEM_ZoomLensRaiseAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 defenderId;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        if (BTL_POKEPARAM_TestTurnFlag(func_021C7CF4(flow, defenderId), TURN_FLAG_ACTED) != 0)
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_HANDLER_ITEM_GetBoostRatio(factor));
    }
}


/* Handler table getter of Lax Incense. */
int *BTL_HANDLER_ITEM_GetLaxIncenseHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gLaxIncenseHandlerTable;
}


/* Lax Incense, accuracy event: lowers the attacker's accuracy by the item percent (the holder is the defender). */
void BTL_HANDLER_ITEM_LaxIncenseLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 percentLeft;
    float ratio;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        percentLeft = 100 - BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
        if (percentLeft != 0)
            ratio = 0.5f + (float)(percentLeft << 12);
        else
            ratio = (float)(percentLeft << 12) - 0.5f;
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, (int)ratio / 100);
    }
}


/* Handler table getter of Muscle Band. */
int *BTL_HANDLER_ITEM_GetMuscleBandHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return &gMuscleBandHandlerTable;
}
