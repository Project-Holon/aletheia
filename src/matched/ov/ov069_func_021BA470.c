/*
 * function: func_021BA470
 * address:  0x021BA470
 * packet:   pkt_ov069_021BA470
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: remaining count after a - 10 per page, capped at 10.
 *
 * symbols:
 */

int func_021BA470(int a, int b, int c)
{
    int r = c - a * 10;

    if (r > 10)
        r = 10;
    return r;
}
