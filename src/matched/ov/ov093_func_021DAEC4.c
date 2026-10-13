/*
 * function: BTL_ABILITY_DampSkipAftermath
 * address: 0x021DAEC4
 * packet: pkt_ov093_021DAEC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DA624_p02.c and filed here.
 */

int BTL_ABILITY_DampSkipAftermath(int a, int b, int c, int d, unsigned short e);

int BTL_ABILITY_DampSkipAftermath(int a, int b, int c, int d, unsigned short e)
{
    if (c == 4 && e == 0x6A) {
        return 1;
    }
    return 0;
}
