/*
 * function: BTL_HANDLER_ITEM_GetCharcoalHandlers
 * address: 0x021DF87C
 * packet: pkt_ov093_021DF87C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF870.c and filed here.
 *
 * symbols:
 *   gCharcoalHandlers 0x021F15E4 data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetCharcoalHandlers(int *p);
extern int gCharcoalHandlers[];

int *BTL_HANDLER_ITEM_GetCharcoalHandlers(int *p)
{
    *p = 1;
    return gCharcoalHandlers;
}
