/*
 * function: BTL_HANDLER_ITEM_GetChilanBerryHandlers
 * address: 0x021DDCB8
 * packet: pkt_ov093_021DDCB8
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
 *   gChilanBerryHandlerTable 0x021F184C data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetChilanBerryHandlers(int *p);
extern int gChilanBerryHandlerTable[];

int *BTL_HANDLER_ITEM_GetChilanBerryHandlers(int *p)
{
    *p = 2;
    return gChilanBerryHandlerTable;
}
