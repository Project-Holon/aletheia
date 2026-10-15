/*
 * function: BOX2_MAIN_HitBoxGrid
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
 *   BOX2_MAIN_HitRect 0x021DF1BC thumb
 *   _s32_div_f 0x0209C0A4 arm
 *   d_021EF798 0x021EF798 data a1
 */

extern int BOX2_MAIN_HitRect(int a, int b, unsigned char *r);
extern const unsigned char d_021EF798[];

int BOX2_MAIN_HitBoxGrid(short x, int y)
{
    if (BOX2_MAIN_HitRect(x, y, (unsigned char *)d_021EF798) == 1) {
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
