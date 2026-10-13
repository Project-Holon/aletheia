/*
 * function: BTLV_GAUGE_CalcPixelChange
 * address:  0x022080B0
 * packet:   pkt_ov094_022080B0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

int BTLV_GAUGE_CalcPixelChange(int a, int b, int c, unsigned int d)
{
    int k;
    int x;
    int p;
    int q;
    int r;

    k = (d << 27) >> 24;
    x = a - b;
    if (x < 0) {
        x = 0;
    } else if (x > c) {
        x = c;
    }
    p = (a * k) / c;
    q = (x * k) / c;
    r = (signed char)p - (signed char)q;
    r = (signed char)r;
    if (r < 0) {
        r = -r;
    }
    return r;
}
