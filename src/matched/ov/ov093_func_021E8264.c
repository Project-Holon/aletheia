/*
 * function: HAND_WAZA_GetGrowthHandlers
 * address: 0x021E8264
 * packet: pkt_ov093_021E8264
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E8200.c and filed here.
 *
 * symbols:
 *   gGrowthHandlers 0x021F26A4 data ov093 a4
 */

int *HAND_WAZA_GetGrowthHandlers(int *p);
extern int gGrowthHandlers[];

int *HAND_WAZA_GetGrowthHandlers(int *p)
{
    *p = 1;
    return gGrowthHandlers;
}
