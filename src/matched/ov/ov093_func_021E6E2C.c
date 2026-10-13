/*
 * function: HAND_WAZA_AddMeFirst
 * address: 0x021E6E2C
 * packet: pkt_ov093_021E6E2C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6DAC.c and filed here.
 *
 * symbols:
 *   gMeFirstHandlers 0x021F2968 data a4
 */

int *HAND_WAZA_AddMeFirst(int *p);
extern int gMeFirstHandlers[];

int *HAND_WAZA_AddMeFirst(int *p)
{
    *p = 2;
    return gMeFirstHandlers;
}
