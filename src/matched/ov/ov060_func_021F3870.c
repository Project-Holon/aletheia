/*
 * function: func_021F3870
 * address:  0x021F3870
 * packet:   pkt_ov060_021F3870
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf filed for ov060 func_021F3880 (ov048 has a different function at
 * the same address).
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

int func_021F3870(int x)
{
    int r = x / 3;

    if (r > 9) {
        r = 9;
    }
    return r;
}
