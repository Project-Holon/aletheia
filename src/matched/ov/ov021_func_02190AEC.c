/*
 * function: func_02190AEC
 * address:  0x02190AEC
 * packet:   pkt_ov021_02190AEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, sole blocker of ov010 func_0215A864's MATCH.
 */

unsigned func_02190AEC(unsigned a, unsigned b, unsigned c, int d)
{
    unsigned n = a * (b + c);
    unsigned r = (n + 7) >> 3;

    if (d && r * 8 - n < 6) {
        r++;
    }
    return r;
}
