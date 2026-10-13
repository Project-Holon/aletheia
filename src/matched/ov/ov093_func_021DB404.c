/*
 * function: HAND_TOKUSEI_GetForecastHandlers
 * address: 0x021DB404
 * packet: pkt_ov093_021DB404
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DB0E4_p02.c and filed here.
 *
 * symbols:
 *   gForecastHandlers 0x021F0DD4 data ov093 a4
 */

int *HAND_TOKUSEI_GetForecastHandlers(int *p);
extern int gForecastHandlers[];

int *HAND_TOKUSEI_GetForecastHandlers(int *p)
{
    *p = 9;
    return gForecastHandlers;
}
