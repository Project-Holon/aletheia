/*
 * function: func_021F5B24
 * address:  0x021F5B24
 * packet:   pkt_ov079_021F5B24
 * region:   ov079
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

int func_021F5B24(int *o)
{
    int s = o[12];

    if (s < 1) {
        int *p = o + 7;
        int v = o[7] + 0x1000;

        o[7] = v;
        if (v >= 0x10000) {
            *p = v - 0x10000;
            o[12] = s + 1;
        }
    } else if (s == 1) {
        int v = o[7] + 0x1000;

        o[7] = v;
        if (v >= 0x8000) {
            o[7] = 0x8000;
            o[12] = s + 1;
        }
    } else {
        o[14] = 1;
    }
    return o[14];
}
