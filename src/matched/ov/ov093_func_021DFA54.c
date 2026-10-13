/*
 * function: BTL_HANDLER_ITEM_GetFloatStoneHandlers
 * address: 0x021DFA54
 * packet: pkt_ov093_021DFA54
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF9C8.c and filed here.
 *
 * symbols:
 *   gBtlHandlerItemFloatStoneHandlers 0x021F1504 data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetFloatStoneHandlers(int *p);
extern int gBtlHandlerItemFloatStoneHandlers[];

int *BTL_HANDLER_ITEM_GetFloatStoneHandlers(int *p)
{
    *p = 1;
    return gBtlHandlerItemFloatStoneHandlers;
}
