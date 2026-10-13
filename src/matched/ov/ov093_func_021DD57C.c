/*
 * function: HAND_ITEM_AddSitrusBerry
 * address: 0x021DD57C
 * packet: pkt_ov093_021DD57C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DCAE8.c and filed here.
 *
 * symbols:
 *   gSitrusBerryHandlers 0x021F1BDC data ov093 a4
 */

int *HAND_ITEM_AddSitrusBerry(int *p);
extern int gSitrusBerryHandlers[];

int *HAND_ITEM_AddSitrusBerry(int *p)
{
    *p = 5;
    return gSitrusBerryHandlers;
}
