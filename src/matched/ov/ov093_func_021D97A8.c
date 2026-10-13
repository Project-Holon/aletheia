/*
 * function: BTL_TOKUSEI_GetSnowWarningHandlers
 * address: 0x021D97A8
 * packet: pkt_ov093_021D97A8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   gSnowWarningHandlers 0x021F0900 data ov093 a4
 */

int *BTL_TOKUSEI_GetSnowWarningHandlers(int *p);
extern int gSnowWarningHandlers[];

int *BTL_TOKUSEI_GetSnowWarningHandlers(int *p)
{
    *p = 2;
    return gSnowWarningHandlers;
}
