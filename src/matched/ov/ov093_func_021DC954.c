/*
 * function: BTL_ABILITY_GetRattledHandlers
 * address: 0x021DC954
 * packet: pkt_ov093_021DC954
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC6EC.c and filed here.
 *
 * symbols:
 *   gRattledHandlers 0x021F05B0 data ov093 a4
 */

int *BTL_ABILITY_GetRattledHandlers(int *p);
extern int gRattledHandlers[];

int *BTL_ABILITY_GetRattledHandlers(int *p)
{
    *p = 1;
    return gRattledHandlers;
}
