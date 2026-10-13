/*
 * function: HAND_WAZA_AddEarthquake
 * address: 0x021E311C
 * packet: pkt_ov093_021E311C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E30F8.c and filed here.
 *
 * symbols:
 *   gEarthquakeHandlers 0x021F2A58 data ov093 a4
 */

int *HAND_WAZA_AddEarthquake(int *p);
extern int gEarthquakeHandlers[];

int *HAND_WAZA_AddEarthquake(int *p)
{
    *p = 2;
    return gEarthquakeHandlers;
}
