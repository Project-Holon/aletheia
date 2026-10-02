/*
 * function: func_021A8B84
 * address:  0x021A8B84
 * packet:   pkt_ov021_021A8B84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D8D24  0x021D8D24  data  a4
 */

extern const int d_021D8D24[][7];
int func_021A8B84(int idx)
{
    int i;
    int n;
    i = 0;
    n = 0;
    for (; d_021D8D24[idx][i] != 0; i++) {
        if (d_021D8D24[idx][i] != 7) {
            n++;
        }
    }
    return n;
}
