/*
 * function: HAND_ITEM_GetBlackGlassesHandlers
 * address: 0x021DF74C
 * packet: pkt_ov093_021DF74C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF740.c and filed here.
 *
 * symbols:
 *   gBlackGlassesHandlers 0x021F13B4 data ov093 a4
 */

extern int gBlackGlassesHandlers[];
int *HAND_ITEM_GetBlackGlassesHandlers(int *p);

int *HAND_ITEM_GetBlackGlassesHandlers(int *p)
{
    *p = 1;
    return gBlackGlassesHandlers;
}
