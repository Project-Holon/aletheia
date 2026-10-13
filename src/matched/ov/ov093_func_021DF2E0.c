/*
 * function: HAND_ITEM_GetFistPlateHandlers
 * address: 0x021DF2E0
 * packet: pkt_ov093_021DF2E0
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
 *   gFistPlateHandlers 0x021F1494 data ov093 a4
 */

extern int gFistPlateHandlers[];
int *HAND_ITEM_GetFistPlateHandlers(int *p);

int *HAND_ITEM_GetFistPlateHandlers(int *p)
{
    *p = 1;
    return gFistPlateHandlers;
}
