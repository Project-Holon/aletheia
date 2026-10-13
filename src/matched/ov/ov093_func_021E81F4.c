/*
 * function: HAND_WAZA_GetForesightHandlers
 * address: 0x021E81F4
 * packet: pkt_ov093_021E81F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E8190.c and filed here.
 *
 * symbols:
 *   gForesightOdorSleuthHandlers 0x021F2898 data ov093 a4
 */

extern int gForesightOdorSleuthHandlers[];
int *HAND_WAZA_GetForesightHandlers(int *p);

int *HAND_WAZA_GetForesightHandlers(int *p)
{
    *p = 2;
    return gForesightOdorSleuthHandlers;
}
