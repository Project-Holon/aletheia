/*
 * function: HAND_ITEM_GetBindingBandHandlers
 * address: 0x021DFCDC
 * packet: pkt_ov093_021DFCDC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFCB8.c and filed here.
 *
 * symbols:
 *   gBtlHandlerItemBindingBandHandlers 0x021F1524 data ov093 a4
 */

extern int gBtlHandlerItemBindingBandHandlers[];
int *HAND_ITEM_GetBindingBandHandlers(int *p);

int *HAND_ITEM_GetBindingBandHandlers(int *p)
{
    *p = 1;
    return gBtlHandlerItemBindingBandHandlers;
}
