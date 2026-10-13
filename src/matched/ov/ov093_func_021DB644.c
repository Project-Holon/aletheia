/*
 * function: BTL_TOKUSEI_GetLiquidOozeHandlers
 * address: 0x021DB644
 * packet: pkt_ov093_021DB644
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DB560.c and filed here.
 *
 * symbols:
 *   gLiquidOozeHandlers 0x021F0920 data ov093 a4
 */

int *BTL_TOKUSEI_GetLiquidOozeHandlers(int *p);
extern int gLiquidOozeHandlers[];

int *BTL_TOKUSEI_GetLiquidOozeHandlers(int *p)
{
    *p = 2;
    return gLiquidOozeHandlers;
}
