/*
 * file:     unit_021DFCB8.c
 * function: BTL_HANDLER_ITEM_RingTargetImmunityOverride, BTL_HANDLER_ITEM_GetBindingBandHandlers
 * address:  0x021DFCB8
 * packet:   pkt_ov093_021DFCB8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gBtlHandlerItemBindingBandHandlers     0x021F1524  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 */
#include "unit_021DF974_types.h"

extern BtlEventHandler gBtlHandlerItemBindingBandHandlers[];

/* Ring Target: the holder as defender loses its type immunities. */
void BTL_HANDLER_ITEM_RingTargetImmunityOverride(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021C7EC4(flow) == 0 && pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_IMMUNITY_OVERRIDE_FLAG, 1);
}

/* Binding Band handler table. */
BtlEventHandler *BTL_HANDLER_ITEM_GetBindingBandHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBtlHandlerItemBindingBandHandlers;
}
