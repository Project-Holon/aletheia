/*
 * function: BTL_HANDLER_ITEM_GetRowapBerryHandlers
 * address: 0x021DE0EC
 * packet: pkt_ov093_021DE0EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE0DC.c and filed here.
 *
 * symbols:
 *   gRowapBerryHandlerTable 0x021F162C data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetRowapBerryHandlers(int *p);
extern int gRowapBerryHandlerTable[];

int *BTL_HANDLER_ITEM_GetRowapBerryHandlers(int *p)
{
    *p = 2;
    return gRowapBerryHandlerTable;
}
