/*
 * function: func_0218BC8C
 * address:  0x0218BC8C
 * packet:   pkt_ov021_0218BC8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int func_0218BC8C(int *p)
{
    unsigned int i;
    int n;
    for (i = 0, n = 0; i < 4; i++) {
        if (p[i + 1] != -1)
            n++;
    }
    return n;
}
