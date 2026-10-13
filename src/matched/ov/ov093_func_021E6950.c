/*
 * function: HAND_WAZA_AddDefenseCurl
 * address: 0x021E6950
 * packet: pkt_ov093_021E6950
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E65B0_p03.c and filed here.
 *
 * symbols:
 *   gDefenseCurlHandlers 0x021F2754 data ov093 a4
 */

int *HAND_WAZA_AddDefenseCurl(int *p);
extern int gDefenseCurlHandlers[];

int *HAND_WAZA_AddDefenseCurl(int *p)
{
    *p = 1;
    return gDefenseCurlHandlers;
}
