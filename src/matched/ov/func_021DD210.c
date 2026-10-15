/*
 * function: BOX2_MAIN_IsWrappedDistance
 * address:  0x021DD210
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * True when the absolute difference of the two unsigned arguments
 * straddles half of the +0x15 counter, in the direction of the order.
 */

int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b)
{
    int d = a - b;
    if (d < 0)
        d = -d;
    if (a > b)
        return d >= ((unsigned)p[0x15] >> 1);
    return d < ((unsigned)p[0x15] >> 1);
}
