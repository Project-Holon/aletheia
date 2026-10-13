/*
 * file:     unit_021DE374.c
 * function: BTL_HANDLER_ITEM_BrightPowderLowerAccuracy, BTL_HANDLER_ITEM_GetMachoBraceHandlers
 * address:  0x021DE374
 * packet:   pkt_ov093_021DE374
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gMachoBraceHandlerTable     0x021F156C  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */
#include "unit_021DDC44_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex);
extern void BTL_EVENT_MultiplyVar(int varId, s32 ratio);

void BTL_HANDLER_ITEM_BrightPowderLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);

/* Bright Powder, accuracy event: lowers the attacker's accuracy by the item percent (the holder is the defender). */
void BTL_HANDLER_ITEM_BrightPowderLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u32 percentLeft;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        percentLeft = 100 - BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, (int)(percentLeft > 0 ? (float)(percentLeft << 12) + 0.5f : (float)(percentLeft << 12) - 0.5f) / 100);
    }
}


extern int gMachoBraceHandlerTable[];
int *BTL_HANDLER_ITEM_GetMachoBraceHandlers(int *handlerCount);

/* Handler table getter of Macho Brace. */
int *BTL_HANDLER_ITEM_GetMachoBraceHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMachoBraceHandlerTable;
}
