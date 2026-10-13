/*
 * function: func_02173DB0
 * address:  0x02173DB0
 * packet:   pkt_02173DB0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the byte at 0x282B of the fourth argument to 1.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char  u8;

void func_02173DB0(int a, int b, int c, u8 *p)
{
    p[0x282B] = 1;
}
