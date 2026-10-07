/*
 * function: func_021F5B44
 * address:  0x021F5B44
 * packet:   pkt_ov080_021F5B44
 * region:   ov080
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

int func_021F5B44(int *o)
{
    if (o[12] < 0x40) {
        o[7] += 0x200;
        o[12]++;
    } else {
        o[14] = 1;
    }
    return o[14];
}
