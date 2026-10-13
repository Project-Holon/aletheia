/*
 * function: BTL_TOKUSEI_GetPressureHandlers
 * address: 0x021DB8DC
 * packet: pkt_ov093_021DB8DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DB650.c and filed here.
 *
 * symbols:
 *   gPressureHandlers 0x021F0AB8 data ov093 a4
 */

int *BTL_TOKUSEI_GetPressureHandlers(int *p);
extern int gPressureHandlers[];

int *BTL_TOKUSEI_GetPressureHandlers(int *p)
{
    *p = 3;
    return gPressureHandlers;
}
