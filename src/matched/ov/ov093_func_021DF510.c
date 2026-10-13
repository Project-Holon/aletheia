/*
 * function: BTL_HANDLER_ITEM_GetLightBallHandlers
 * address: 0x021DF510
 * packet: pkt_ov093_021DF510
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF48C.c and filed here.
 *
 * symbols:
 *   gLightBallHandlers 0x021F167C data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetLightBallHandlers(int *p);
extern int gLightBallHandlers[];

int *BTL_HANDLER_ITEM_GetLightBallHandlers(int *p)
{
    *p = 2;
    return gLightBallHandlers;
}
