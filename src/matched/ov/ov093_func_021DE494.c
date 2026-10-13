/*
 * function: BTL_HANDLER_ITEM_GetLaggingTailHandlers
 * address: 0x021DE494
 * packet: pkt_ov093_021DE494
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE3D4.c and filed here.
 *
 * symbols:
 *   gLaggingTailHandlerTable 0x021F1394 data ov093 a4
 */

extern int gLaggingTailHandlerTable[];
int *BTL_HANDLER_ITEM_GetLaggingTailHandlers(int *p);

int *BTL_HANDLER_ITEM_GetLaggingTailHandlers(int *p)
{
    *p = 1;
    return gLaggingTailHandlerTable;
}
