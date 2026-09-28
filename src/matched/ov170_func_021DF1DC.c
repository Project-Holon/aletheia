/*
 * function: func_021DF1DC
 * address:  0x021DF1DC
 * packet:   pkt_ov170_021DF1DC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DF1BC 0x021DF1BC thumb
 *   _s32_div_f 0x0209C0A4 arm
 *   d_021EF798 0x021EF798 data a1
 */

extern int func_021DF1BC(int a, int b, const unsigned char *r);
extern const unsigned char d_021EF798[];

int func_021DF1DC(int x, int y)
{
    if (func_021DF1BC(x, y, d_021EF798) == 1) {
        if (x < 0xC)
            x = 0;
        else if (x >= 0x9C)
            x = 5;
        else
            x = (short)((x - 0xC) / 0x18);
        y -= 0x28;
        return x + (short)(y / 0x18) * 6;
    }
    return 0xFF;
}
