/*
 * function: BTL_CALC_GetSpeedBoostHandlers
 * address: 0x021D8C00
 * packet: pkt_ov093_021D8C00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D8B50.c and filed here.
 *
 * symbols:
 *   gSpeedBoostHandlers 0x021F0698 data ov093 a4
 */

int *BTL_CALC_GetSpeedBoostHandlers(int *p);
extern int gSpeedBoostHandlers[];

int *BTL_CALC_GetSpeedBoostHandlers(int *p)
{
    *p = 1;
    return gSpeedBoostHandlers;
}
