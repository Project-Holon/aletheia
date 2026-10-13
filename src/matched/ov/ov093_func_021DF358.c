/*
 * function: HAND_ITEM_GetIronPlateHandlers
 * address: 0x021DF358
 * packet: pkt_ov093_021DF358
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
 *   gIronPlateHandlers 0x021F1424 data ov093 a4
 */

extern int gIronPlateHandlers[];
int *HAND_ITEM_GetIronPlateHandlers(int *p);

int *HAND_ITEM_GetIronPlateHandlers(int *p)
{
    *p = 1;
    return gIronPlateHandlers;
}
