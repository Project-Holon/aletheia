/*
 * function: HAND_WAZA_AddGust
 * address: 0x021E2FDC
 * packet: pkt_ov093_021E2FDC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E2ED4.c and filed here.
 *
 * symbols:
 *   gGustHandlers 0x021F2A28 data ov093 a4
 */

int *HAND_WAZA_AddGust(int *p);
extern int gGustHandlers[];

int *HAND_WAZA_AddGust(int *p)
{
    *p = 2;
    return gGustHandlers;
}
