/*
 * function: HAND_ITEM_GetColburBerryHandlers
 * address: 0x021DDC78
 * packet: pkt_ov093_021DDC78
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDC64.c and filed here.
 *
 * symbols:
 *   gColburBerryHandlers 0x021F182C data ov093 a4
 */

extern int gColburBerryHandlers[];
int *HAND_ITEM_GetColburBerryHandlers(int *p);

int *HAND_ITEM_GetColburBerryHandlers(int *p)
{
    *p = 2;
    return gColburBerryHandlers;
}
