/*
 * function: BTL_HANDLER_ITEM_GetHabanBerryHandlers
 * address: 0x021DDC58
 * packet: pkt_ov093_021DDC58
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDC44.c and filed here.
 *
 * symbols:
 *   gHabanBerryHandlerTable 0x021F181C data ov093 a4
 */

extern int gHabanBerryHandlerTable[];
int *BTL_HANDLER_ITEM_GetHabanBerryHandlers(int *p);

int *BTL_HANDLER_ITEM_GetHabanBerryHandlers(int *p)
{
    *p = 2;
    return gHabanBerryHandlerTable;
}
