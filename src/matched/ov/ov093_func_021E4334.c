/*
 * function: HAND_WAZA_GetAcupressureHandlers
 * address: 0x021E4334
 * packet: pkt_ov093_021E4334
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E4154.c and filed here.
 *
 * symbols:
 *   gAcupressureHandlers 0x021F27A4 data ov093 a4
 */

extern int gAcupressureHandlers[];
int *HAND_WAZA_GetAcupressureHandlers(int *p);

int *HAND_WAZA_GetAcupressureHandlers(int *p)
{
    *p = 1;
    return gAcupressureHandlers;
}
