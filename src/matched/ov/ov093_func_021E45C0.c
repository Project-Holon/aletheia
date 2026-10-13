/*
 * function: HAND_WAZA_GetConversion2Handlers
 * address: 0x021E45C0
 * packet: pkt_ov093_021E45C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E4340_p01.c and filed here.
 *
 * symbols:
 *   gConversion2Handlers 0x021F2784 data ov093 a4
 */

int *HAND_WAZA_GetConversion2Handlers(int *p);
extern int gConversion2Handlers[];

int *HAND_WAZA_GetConversion2Handlers(int *p)
{
    *p = 1;
    return gConversion2Handlers;
}
