/*
 * function: HAND_ITEM_GetRedCardHandlers
 * address: 0x021DFBF4
 * packet: pkt_ov093_021DFBF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFABC.c and filed here.
 *
 * symbols:
 *   gBtlHandlerItemRedCardHandlers 0x021F14CC data ov093 a4
 */

int *HAND_ITEM_GetRedCardHandlers(int *p);
extern int gBtlHandlerItemRedCardHandlers[];

int *HAND_ITEM_GetRedCardHandlers(int *p)
{
    *p = 1;
    return gBtlHandlerItemRedCardHandlers;
}
