/*
 * function: HAND_ITEM_GetBigRootHandlers
 * address: 0x021DF364
 * packet: pkt_ov093_021DF364
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DEFC4.c and filed here.
 *
 * symbols:
 *   gBigRootHandlers 0x021F153C data ov093 a4
 */

extern int gBigRootHandlers[];
int *HAND_ITEM_GetBigRootHandlers(int *p);

int *HAND_ITEM_GetBigRootHandlers(int *p)
{
    *p = 1;
    return gBigRootHandlers;
}
