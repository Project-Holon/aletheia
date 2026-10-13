/*
 * function: BTL_HANDLER_ITEM_GetAmuletCoinHandlers
 * address: 0x021DF3F8
 * packet: pkt_ov093_021DF3F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF3A4.c and filed here.
 *
 * symbols:
 *   gAmuletCoinHandlers 0x021F161C data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetAmuletCoinHandlers(int *p);
extern int gAmuletCoinHandlers[];

int *BTL_HANDLER_ITEM_GetAmuletCoinHandlers(int *p)
{
    *p = 2;
    return gAmuletCoinHandlers;
}
