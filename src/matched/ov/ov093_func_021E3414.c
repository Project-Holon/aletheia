/*
 * function: HAND_WAZA_AddKnockOff
 * address: 0x021E3414
 * packet: pkt_ov093_021E3414
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E324C.c and filed here.
 *
 * symbols:
 *   gKnockOffHandlers 0x021F2844 data ov093 a4
 */

extern int gKnockOffHandlers[];
int *HAND_WAZA_AddKnockOff(int *p);

int *HAND_WAZA_AddKnockOff(int *p)
{
    *p = 1;
    return gKnockOffHandlers;
}
