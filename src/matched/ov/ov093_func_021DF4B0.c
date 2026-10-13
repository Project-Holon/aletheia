/*
 * function: HAND_ITEM_GetHeatRockHandlers
 * address: 0x021DF4B0
 * packet: pkt_ov093_021DF4B0
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
 *   gHeatRockHandlers 0x021F151C data a4
 */

int *HAND_ITEM_GetHeatRockHandlers(int *p);
extern int gHeatRockHandlers[];

int *HAND_ITEM_GetHeatRockHandlers(int *p)
{
    *p = 1;
    return gHeatRockHandlers;
}
