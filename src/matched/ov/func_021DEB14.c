/*
 * function: BOX2_MAIN_WrapOffset
 * address:  0x021DEB14
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Add the 3rd/4th parameter to the signed byte at +0x19 and fold the
 * +0x15 field in: add it when negative (signed), subtract it when the
 * result is at or above the unsigned byte.
 */

unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a)
{
    signed char v = (signed char)p[0x19] + a;
    if (v < 0)
        v = v + (signed char)p[0x15];
    else if (v >= p[0x15])
        v = v - (signed char)p[0x15];
    return v;
}
