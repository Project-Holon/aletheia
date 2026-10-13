/*
 * function: BTL_TOKUSEI_GetStormDrainHandlers
 * address: 0x021DB410
 * packet: pkt_ov093_021DB410
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DB0E4_p02.c and filed here.
 *
 * symbols:
 *   gStormDrainHandlers 0x021F0A58 data ov093 a4
 */

int *BTL_TOKUSEI_GetStormDrainHandlers(int *p);
extern int gStormDrainHandlers[];

int *BTL_TOKUSEI_GetStormDrainHandlers(int *p)
{
    *p = 3;
    return gStormDrainHandlers;
}
