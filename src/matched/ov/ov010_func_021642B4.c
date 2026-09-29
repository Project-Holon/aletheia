/*
 * function: func_021642B4
 * address:  0x021642B4
 * packet:   pkt_ov010_021642B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (word run in the listing), blocker of func_0219B13C and
 * func_0219BA6C (ov021).  Direction code 0..3 from a point pair.
 */

typedef unsigned short u16;

u16 func_021642B4(int x0, int y0, int x1, int y1)
{
    int r;

    if (x0 > x1) {
        return 2;
    }
    if (x0 < x1) {
        return 3;
    }
    r = 1;
    if (y0 > y1) {
        r = 0;
    }
    return r;
}
