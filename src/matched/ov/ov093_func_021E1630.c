/*
 * function: HAND_WAZA_AddStockpile
 * address: 0x021E1630
 * packet: pkt_ov093_021E1630
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E15E8.c and filed here.
 *
 * symbols:
 *   gStockpileHandlers 0x021F2948 data ov093 a4
 */

int *HAND_WAZA_AddStockpile(int *p);
extern int gStockpileHandlers[];

int *HAND_WAZA_AddStockpile(int *p)
{
    *p = 2;
    return gStockpileHandlers;
}
