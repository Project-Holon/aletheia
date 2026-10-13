/*
 * function: BTL_HANDLER_ITEM_GetCustapBerryHandlers
 * address: 0x021DDEF0
 * packet: pkt_ov093_021DDEF0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDCA4.c and filed here.
 *
 * symbols:
 *   gCustapBerryHandlerTable 0x021F15EC data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetCustapBerryHandlers(int *p);
extern int gCustapBerryHandlerTable[];

int *BTL_HANDLER_ITEM_GetCustapBerryHandlers(int *p)
{
    *p = 2;
    return gCustapBerryHandlerTable;
}
