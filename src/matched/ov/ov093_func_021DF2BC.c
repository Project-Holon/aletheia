/*
 * function: HAND_ITEM_GetZapPlateHandlers
 * address: 0x021DF2BC
 * packet: pkt_ov093_021DF2BC
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
 *   gZapPlateHandlers 0x021F136C data ov093 a4
 */

extern int gZapPlateHandlers[];
int *HAND_ITEM_GetZapPlateHandlers(int *p);

int *HAND_ITEM_GetZapPlateHandlers(int *p)
{
    *p = 1;
    return gZapPlateHandlers;
}
