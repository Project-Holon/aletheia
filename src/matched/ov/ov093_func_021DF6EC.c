/*
 * function: BTL_HANDLER_ITEM_GetSilverPowderHandlers
 * address: 0x021DF6EC
 * packet: pkt_ov093_021DF6EC
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
 *   gSilverPowderHandlers 0x021F14F4 data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetSilverPowderHandlers(int *p);
extern int gSilverPowderHandlers[];

int *BTL_HANDLER_ITEM_GetSilverPowderHandlers(int *p)
{
    *p = 1;
    return gSilverPowderHandlers;
}
