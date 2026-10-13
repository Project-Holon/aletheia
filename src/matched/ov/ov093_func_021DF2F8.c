/*
 * function: HAND_ITEM_GetEarthPlateHandlers
 * address: 0x021DF2F8
 * packet: pkt_ov093_021DF2F8
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
 *   gEarthPlateHandlers 0x021F14E4 data ov093 a4
 */

extern int gEarthPlateHandlers[];
int *HAND_ITEM_GetEarthPlateHandlers(int *p);

int *HAND_ITEM_GetEarthPlateHandlers(int *p)
{
    *p = 1;
    return gEarthPlateHandlers;
}
