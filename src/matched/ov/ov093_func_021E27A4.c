/*
 * function: HAND_WAZA_GyroBallGetHandlers
 * address: 0x021E27A4
 * packet: pkt_ov093_021E27A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E2188.c and filed here.
 *
 * symbols:
 *   gGyroBallHandlers 0x021F248C data ov093 a4
 */

int *HAND_WAZA_GyroBallGetHandlers(int *p);
extern int gGyroBallHandlers[];

int *HAND_WAZA_GyroBallGetHandlers(int *p)
{
    *p = 1;
    return gGyroBallHandlers;
}
