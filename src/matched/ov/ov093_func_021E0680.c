/*
 * function: HAND_WAZA_GetWaterSportHandlers
 * address: 0x021E0680
 * packet: pkt_ov093_021E0680
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0628.c and filed here.
 *
 * symbols:
 *   gWaterSportHandlers 0x021F2664 data ov093 a4
 */

int *HAND_WAZA_GetWaterSportHandlers(int *p);
extern int gWaterSportHandlers[];

int *HAND_WAZA_GetWaterSportHandlers(int *p)
{
    *p = 1;
    return gWaterSportHandlers;
}
