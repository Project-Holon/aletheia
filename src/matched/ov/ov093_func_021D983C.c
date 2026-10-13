/*
 * function: BTL_TOKUSEI_GetWeatherLockHandlers
 * address: 0x021D983C
 * packet: pkt_ov093_021D983C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   gWeatherLockHandlers 0x021F0910 data ov093 a4
 */

int *BTL_TOKUSEI_GetWeatherLockHandlers(int *p);
extern int gWeatherLockHandlers[];

int *BTL_TOKUSEI_GetWeatherLockHandlers(int *p)
{
    *p = 2;
    return gWeatherLockHandlers;
}
