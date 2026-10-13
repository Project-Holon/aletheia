/*
 * function: HAND_WAZA_GetSkyDropHandlers
 * address: 0x021E7FA8
 * packet: pkt_ov093_021E7FA8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E7E58.c and filed here.
 *
 * symbols:
 *   gSkyDropHandlers 0x021F2F98 data ov093 a4
 */

int *HAND_WAZA_GetSkyDropHandlers(int *p);
extern int gSkyDropHandlers[];

int *HAND_WAZA_GetSkyDropHandlers(int *p)
{
    *p = 6;
    return gSkyDropHandlers;
}
