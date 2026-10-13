/*
 * function: BTL_TOKUSEI_GetStenchHandlers
 * address: 0x021DB9D0
 * packet: pkt_ov093_021DB9D0
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
 *   gStenchHandlers 0x021F06F0 data ov093 a4
 */

int *BTL_TOKUSEI_GetStenchHandlers(int *p);
extern int gStenchHandlers[];

int *BTL_TOKUSEI_GetStenchHandlers(int *p)
{
    *p = 1;
    return gStenchHandlers;
}
