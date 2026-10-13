/*
 * function: HAND_ITEM_GetIcyRockHandlers
 * address: 0x021DF480
 * packet: pkt_ov093_021DF480
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF3A4.c and filed here.
 *
 * symbols:
 *   gIcyRockHandlers 0x021F145C data ov093 a4
 */

int *HAND_ITEM_GetIcyRockHandlers(int *p);
extern int gIcyRockHandlers[];

int *HAND_ITEM_GetIcyRockHandlers(int *p)
{
    *p = 1;
    return gIcyRockHandlers;
}
