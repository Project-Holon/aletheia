/*
 * function: func_021DB4B4
 * address: 0x021DB4B4
 * packet: pkt_ov119_021DB4B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * Position of a slot: 0 and 1 are special, the rest on a 6-column grid.
 * Lever: the remainder is stored back into the same local as the dividend
 * (b = b % 6); a separate remainder local stays in r1 and changes colours.
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 */
int func_021DB4B4(int a)
{
    int b, q;

    if (a == 0)
        return 0;
    if (a == 1)
        return 0x30;
    b = a - 2;
    q = b / 6;
    b = b % 6;
    return q * 0xa0 + 0x60 + b * 0x1a;
}
