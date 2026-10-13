/*
 * function: HAND_WAZA_AddStealthRock
 * address: 0x021E54E0
 * packet: pkt_ov093_021E54E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E54AC.c and filed here.
 *
 * symbols:
 *   gStealthRockHandlers 0x021F26B4 data ov093 a4
 */

extern int gStealthRockHandlers[];
int *HAND_WAZA_AddStealthRock(int *p);

int *HAND_WAZA_AddStealthRock(int *p)
{
    *p = 1;
    return gStealthRockHandlers;
}
