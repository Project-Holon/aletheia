/*
 * function: BTL_HANDLER_ITEM_GetDragonFangHandlers
 * address: 0x021DF894
 * packet: pkt_ov093_021DF894
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
 *   gDragonFangHandlers 0x021F15DC data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetDragonFangHandlers(int *p);
extern int gDragonFangHandlers[];

int *BTL_HANDLER_ITEM_GetDragonFangHandlers(int *p)
{
    *p = 1;
    return gDragonFangHandlers;
}
