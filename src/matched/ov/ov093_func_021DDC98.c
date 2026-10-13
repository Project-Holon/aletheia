/*
 * function: BTL_HANDLER_ITEM_GetBabiriBerryHandlers
 * address: 0x021DDC98
 * packet: pkt_ov093_021DDC98
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDC84.c and filed here.
 *
 * symbols:
 *   gBabiriBerryHandlerTable 0x021F183C data ov093 a4
 */

extern int gBabiriBerryHandlerTable[];
int *BTL_HANDLER_ITEM_GetBabiriBerryHandlers(int *p);

int *BTL_HANDLER_ITEM_GetBabiriBerryHandlers(int *p)
{
    *p = 2;
    return gBabiriBerryHandlerTable;
}
