/*
 * function: HAND_TOKUSEI_GetRunAwayHandlers
 * address: 0x021DB128
 * packet: pkt_ov093_021DB128
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DB0E4_p01.c and filed here.
 *
 * symbols:
 *   gRunAwayHandlers 0x021F08B0 data ov093 a4
 */

int *HAND_TOKUSEI_GetRunAwayHandlers(int *p);
extern int gRunAwayHandlers[];

int *HAND_TOKUSEI_GetRunAwayHandlers(int *p)
{
    *p = 2;
    return gRunAwayHandlers;
}
