/*
 * function: HAND_WAZA_GetFlyHandlers
 * address: 0x021E61B0
 * packet: pkt_ov093_021E61B0
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6164.c and filed here.
 *
 * symbols:
 *   gFlyHandlers 0x021F2A88 data ov093 a4
 */

extern int gFlyHandlers[];
int *HAND_WAZA_GetFlyHandlers(int *p);

int *HAND_WAZA_GetFlyHandlers(int *p)
{
    *p = 2;
    return gFlyHandlers;
}
