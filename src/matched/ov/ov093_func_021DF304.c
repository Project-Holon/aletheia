/*
 * function: HAND_ITEM_GetSkyPlateHandlers
 * address: 0x021DF304
 * packet: pkt_ov093_021DF304
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
 *   gSkyPlateHandlers 0x021F1594 data ov093 a4
 */

extern int gSkyPlateHandlers[];
int *HAND_ITEM_GetSkyPlateHandlers(int *p);

int *HAND_ITEM_GetSkyPlateHandlers(int *p)
{
    *p = 1;
    return gSkyPlateHandlers;
}
