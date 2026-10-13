/*
 * function: HAND_WAZA_AddNaturePower
 * address: 0x021E6B14
 * packet: pkt_ov093_021E6B14
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6AD8_p01.c and filed here.
 *
 * symbols:
 *   gNaturePowerHandlers 0x021F2928 data ov093 a4
 */

int *HAND_WAZA_AddNaturePower(int *p);
extern int gNaturePowerHandlers[];

int *HAND_WAZA_AddNaturePower(int *p)
{
    *p = 2;
    return gNaturePowerHandlers;
}
