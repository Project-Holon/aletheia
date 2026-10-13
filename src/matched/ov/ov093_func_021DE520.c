/*
 * function: BTL_HANDLER_ITEM_GetRazorFangHandlers
 * address: 0x021DE520
 * packet: pkt_ov093_021DE520
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE4A0.c and filed here.
 *
 * symbols:
 *   gRazorFangHandlerTable 0x021F165C data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetRazorFangHandlers(int *p);
extern int gRazorFangHandlerTable[];

int *BTL_HANDLER_ITEM_GetRazorFangHandlers(int *p)
{
    *p = 2;
    return gRazorFangHandlerTable;
}
