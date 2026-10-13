/*
 * function: BTL_HANDLER_ITEM_GetBlackBeltHandlers
 * address: 0x021DF764
 * packet: pkt_ov093_021DF764
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF758.c and filed here.
 *
 * symbols:
 *   gBlackBeltHandlers 0x021F142C data ov093 a4
 */

extern int gBlackBeltHandlers[];
int *BTL_HANDLER_ITEM_GetBlackBeltHandlers(int *p);

int *BTL_HANDLER_ITEM_GetBlackBeltHandlers(int *p)
{
    *p = 1;
    return gBlackBeltHandlers;
}
