/*
 * function: BTL_HANDLER_ITEM_GetMachoBraceHandlers
 * address: 0x021DE3C8
 * packet: pkt_ov093_021DE3C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE374.c and filed here.
 *
 * symbols:
 *   gMachoBraceHandlerTable 0x021F156C data ov093 a4
 */

extern int gMachoBraceHandlerTable[];
int *BTL_HANDLER_ITEM_GetMachoBraceHandlers(int *p);

int *BTL_HANDLER_ITEM_GetMachoBraceHandlers(int *p)
{
    *p = 1;
    return gMachoBraceHandlerTable;
}
