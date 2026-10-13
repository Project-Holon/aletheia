/*
 * function: HAND_WAZA_ThrashGetHandlers
 * address: 0x021E21E8
 * packet: pkt_ov093_021E21E8
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
 *   gThrashHandlers 0x021F2C90 data ov093 a4
 */

int *HAND_WAZA_ThrashGetHandlers(int *p);
extern int gThrashHandlers[];

int *HAND_WAZA_ThrashGetHandlers(int *p)
{
    *p = 3;
    return gThrashHandlers;
}
