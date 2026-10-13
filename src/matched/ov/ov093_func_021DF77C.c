/*
 * function: HAND_ITEM_GetMagnetHandlers
 * address: 0x021DF77C
 * packet: pkt_ov093_021DF77C
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
 *   gMagnetHandlers 0x021F14C4 data ov093 a4
 */

int *HAND_ITEM_GetMagnetHandlers(int *p);
extern int gMagnetHandlers[];

int *HAND_ITEM_GetMagnetHandlers(int *p)
{
    *p = 1;
    return gMagnetHandlers;
}
