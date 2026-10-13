/*
 * function: BTL_TOKUSEI_GetKlutzHandlers
 * address: 0x021DB7DC
 * packet: pkt_ov093_021DB7DC
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
 *   gKlutzHandlers 0x021F0D9C data ov093 a4
 */

int *BTL_TOKUSEI_GetKlutzHandlers(int *p);
extern int gKlutzHandlers[];

int *BTL_TOKUSEI_GetKlutzHandlers(int *p)
{
    *p = 7;
    return gKlutzHandlers;
}
