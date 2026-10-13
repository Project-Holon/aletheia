/*
 * function: HAND_WAZA_AddAssist
 * address: 0x021E6BE8
 * packet: pkt_ov093_021E6BE8
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
 *   gAssistHandlers 0x021F270C data ov093 a4
 */

int *HAND_WAZA_AddAssist(int *p);
extern int gAssistHandlers[];

int *HAND_WAZA_AddAssist(int *p)
{
    *p = 1;
    return gAssistHandlers;
}
