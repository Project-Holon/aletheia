/*
 * function: HAND_ITEM_GetDampRockHandlers
 * address: 0x021DF4C8
 * packet: pkt_ov093_021DF4C8
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
 *   gDampRockHandlers 0x021F1514 data ov093 a4
 */

int *HAND_ITEM_GetDampRockHandlers(int *p);
extern int gDampRockHandlers[];

int *HAND_ITEM_GetDampRockHandlers(int *p)
{
    *p = 1;
    return gDampRockHandlers;
}
