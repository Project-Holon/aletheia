/*
 * function: HAND_WAZA_AddHex
 * address: 0x021E7000
 * packet: pkt_ov093_021E7000
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6FC8.c and filed here.
 *
 * symbols:
 *   gHexHandlers 0x021F2524 data ov093 a4
 */

extern int gHexHandlers[];
int *HAND_WAZA_AddHex(int *p);

int *HAND_WAZA_AddHex(int *p)
{
    *p = 1;
    return gHexHandlers;
}
