/*
 * function: BTL_HANDLER_ITEM_GetRockIncenseHandlers
 * address: 0x021DF8DC
 * packet: pkt_ov093_021DF8DC
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
 *   gRockIncenseHandlers 0x021F1404 data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetRockIncenseHandlers(int *p);
extern int gRockIncenseHandlers[];

int *BTL_HANDLER_ITEM_GetRockIncenseHandlers(int *p)
{
    *p = 1;
    return gRockIncenseHandlers;
}
