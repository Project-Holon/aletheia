/*
 * function: ENCEFF_UpdateGridSpreadCell
 * address:  0x021F5B94
 * packet:   pkt_ov081_021F5B94
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

int ENCEFF_UpdateGridSpreadCell(int *o)
{
    if (o[0] < 0x100000) {
        int a = o[0];
        int b = o[9];

        o[2] = 0x1000;
        o[0] = a + b;
        o[9] = b + 0x1000;
        if (o[7] < 0x8000)
            o[7] += 0x200;
        else
            o[7] = 0x8000;
    } else {
        o[14] = 1;
    }
    return o[14];
}
