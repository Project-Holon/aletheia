/*
 * function: BTL_CALC_GetSlowStartHandlers
 * address: 0x021D8A30
 * packet: pkt_ov093_021D8A30
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D87C8.c and filed here.
 *
 * symbols:
 *   gSlowStartHandlers 0x021F0D6C data ov093 a4
 */

int *BTL_CALC_GetSlowStartHandlers(int *p);
extern int gSlowStartHandlers[];

int *BTL_CALC_GetSlowStartHandlers(int *p)
{
    *p = 6;
    return gSlowStartHandlers;
}
