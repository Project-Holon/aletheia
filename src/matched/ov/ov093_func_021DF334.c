/*
 * function: HAND_ITEM_GetSpookyPlateHandlers
 * address: 0x021DF334
 * packet: pkt_ov093_021DF334
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
 *   gSpookyPlateHandlers 0x021F1374 data ov093 a4
 */

extern int gSpookyPlateHandlers[];
int *HAND_ITEM_GetSpookyPlateHandlers(int *p);

int *HAND_ITEM_GetSpookyPlateHandlers(int *p)
{
    *p = 1;
    return gSpookyPlateHandlers;
}
