/*
 * function: BTL_CALC_GetSteadfastHandlers
 * address: 0x021D869C
 * packet: pkt_ov093_021D869C
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
 *   gSteadfastHandlers 0x021F07B0 data ov093 a4
 */

int *BTL_CALC_GetSteadfastHandlers(int *p);
extern int gSteadfastHandlers[];

int *BTL_CALC_GetSteadfastHandlers(int *p)
{
    *p = 1;
    return gSteadfastHandlers;
}
