/*
 * function: BTL_HANDLER_ITEM_GetSmoothRockHandlers
 * address: 0x021DF498
 * packet: pkt_ov093_021DF498
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
 *   gSmoothRockHandlers 0x021F1464 data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetSmoothRockHandlers(int *p);
extern int gSmoothRockHandlers[];

int *BTL_HANDLER_ITEM_GetSmoothRockHandlers(int *p)
{
    *p = 1;
    return gSmoothRockHandlers;
}
