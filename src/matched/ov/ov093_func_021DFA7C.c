/*
 * function: BTL_HANDLER_ITEM_GetEvioliteHandlers
 * address: 0x021DFA7C
 * packet: pkt_ov093_021DFA7C
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
 *   gBtlHandlerItemEvioliteHandlers 0x021F14FC data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetEvioliteHandlers(int *p);
extern int gBtlHandlerItemEvioliteHandlers[];

int *BTL_HANDLER_ITEM_GetEvioliteHandlers(int *p)
{
    *p = 1;
    return gBtlHandlerItemEvioliteHandlers;
}
