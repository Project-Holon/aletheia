/*
 * function: BTL_CALC_GetThickFatHandlers
 * address: 0x021D86F0
 * packet: pkt_ov093_021D86F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D8684.c and filed here.
 *
 * symbols:
 *   gThickFatHandlers 0x021F05B8 data ov093 a4
 */

int *BTL_CALC_GetThickFatHandlers(int *p);
extern int gThickFatHandlers[];

int *BTL_CALC_GetThickFatHandlers(int *p)
{
    *p = 1;
    return gThickFatHandlers;
}
