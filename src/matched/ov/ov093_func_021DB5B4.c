/*
 * function: HAND_TOKUSEI_GetSuctionCupsHandlers
 * address: 0x021DB5B4
 * packet: pkt_ov093_021DB5B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DB560.c and filed here.
 *
 * symbols:
 *   gSuctionCupsHandlers 0x021F05F0 data ov093 a4
 */

int *HAND_TOKUSEI_GetSuctionCupsHandlers(int *p);
extern int gSuctionCupsHandlers[];

int *HAND_TOKUSEI_GetSuctionCupsHandlers(int *p)
{
    *p = 1;
    return gSuctionCupsHandlers;
}
