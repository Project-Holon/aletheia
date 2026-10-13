/*
 * function: HAND_WAZA_AddAromatherapy
 * address: 0x021E4920
 * packet: pkt_ov093_021E4920
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E48C0.c and filed here.
 *
 * symbols:
 *   gAromatherapyHandlers 0x021F2B88 data ov093 a4
 */

extern int gAromatherapyHandlers[];
int *HAND_WAZA_AddAromatherapy(int *p);

int *HAND_WAZA_AddAromatherapy(int *p)
{
    *p = 3;
    return gAromatherapyHandlers;
}
