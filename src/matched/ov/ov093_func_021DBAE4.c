/*
 * function: HAND_TOKUSEI_GetMagnetPullHandlers
 * address: 0x021DBAE4
 * packet: pkt_ov093_021DBAE4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DB9AC.c and filed here.
 *
 * symbols:
 *   gMagnetPullHandlers 0x021F06D8 data ov093 a4
 */

int *HAND_TOKUSEI_GetMagnetPullHandlers(int *p);
extern int gMagnetPullHandlers[];

int *HAND_TOKUSEI_GetMagnetPullHandlers(int *p)
{
    *p = 1;
    return gMagnetPullHandlers;
}
