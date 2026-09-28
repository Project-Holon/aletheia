/*
 * function: func_021C7EF8
 * address:  0x021C7EF8
 * packet:   pkt_ov111_021C7EF8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C88B4  0x021C88B4  data
 *
 * Addresses are Black-image addresses.
 */

extern const int d_021C88B4[8];

int func_021C7EF8(int v)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (d_021C88B4[i] > v - 10000 && d_021C88B4[i] < v + 10000) {
            break;
        }
    }
    if (i == 8) {
        i = 0;
    }
    return i;
}
