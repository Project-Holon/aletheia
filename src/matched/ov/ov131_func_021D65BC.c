/*
 * function: func_021D65BC
 * address:  0x021D65BC
 * packet:   pkt_021D65BC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D44C8  0x021D44C8  thumb
 *
 * Addresses are Black-image addresses.
 */

extern int func_021D44C8(char *p);

int func_021D65BC(int a, int b, int c, int d)
{
    int r = func_021D44C8((char *)d);

    if (r == 1)
        return 1;
    if (r == 2)
        return 1;
    return 0;
}
