/*
 * function: HAND_ITEM_GetInsectPlateHandlers
 * address: 0x021DF31C
 * packet: pkt_ov093_021DF31C
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
 *   gInsectPlateHandlers 0x021F14A4 data ov093 a4
 */

extern int gInsectPlateHandlers[];
int *HAND_ITEM_GetInsectPlateHandlers(int *p);

int *HAND_ITEM_GetInsectPlateHandlers(int *p)
{
    *p = 1;
    return gInsectPlateHandlers;
}
