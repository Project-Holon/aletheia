/*
 * function: BTL_CALC_OvergrowBoostGrass
 * address: 0x021D8C74
 * packet: pkt_ov093_021D8C74
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
 *   BTL_CALC_PinchBoostType 0x021D8CAC thumb
 */

void BTL_CALC_OvergrowBoostGrass(int a, int b, int c);
void BTL_CALC_PinchBoostType(int a, int b, int c);

void BTL_CALC_OvergrowBoostGrass(int a, int b, int c)
{
    BTL_CALC_PinchBoostType(b, c, 11);
}
