/*
 * function: HAND_WAZA_GetWeatherHealHandlers
 * address: 0x021E6158
 * packet: pkt_ov093_021E6158
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E5B78.c and filed here.
 *
 * symbols:
 *   gWeatherHealHandlers 0x021F240C data ov093 a4
 */

int *HAND_WAZA_GetWeatherHealHandlers(int *p);
extern int gWeatherHealHandlers[];

int *HAND_WAZA_GetWeatherHealHandlers(int *p)
{
    *p = 1;
    return gWeatherHealHandlers;
}
