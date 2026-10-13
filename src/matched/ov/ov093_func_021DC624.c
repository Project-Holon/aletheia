/*
 * function: HAND_TOKUSEI_GetSandRushHandlers
 * address: 0x021DC624
 * packet: pkt_ov093_021DC624
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC57C.c and filed here.
 *
 * symbols:
 *   gSandRushHandlers 0x021F0950 data ov093 a4
 */

int *HAND_TOKUSEI_GetSandRushHandlers(int *p);
extern int gSandRushHandlers[];

int *HAND_TOKUSEI_GetSandRushHandlers(int *p)
{
    *p = 2;
    return gSandRushHandlers;
}
