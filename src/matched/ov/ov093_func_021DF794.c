/*
 * function: HAND_ITEM_GetMetalCoatHandlers
 * address: 0x021DF794
 * packet: pkt_ov093_021DF794
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF770.c and filed here.
 *
 * symbols:
 *   gMetalCoatHandlers 0x021F13C4 data ov093 a4
 */

int *HAND_ITEM_GetMetalCoatHandlers(int *p);
extern int gMetalCoatHandlers[];

int *HAND_ITEM_GetMetalCoatHandlers(int *p)
{
    *p = 1;
    return gMetalCoatHandlers;
}
