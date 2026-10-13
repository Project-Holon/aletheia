/*
 * function: BTL_HANDLER_ITEM_GetWhiteHerbHandlers
 * address: 0x021DE21C
 * packet: pkt_ov093_021DE21C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE180.c and filed here.
 *
 * symbols:
 *   gWhiteHerbHandlerTable 0x021F1E3C data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetWhiteHerbHandlers(int *p);
extern int gWhiteHerbHandlerTable[];

int *BTL_HANDLER_ITEM_GetWhiteHerbHandlers(int *p)
{
    *p = 6;
    return gWhiteHerbHandlerTable;
}
