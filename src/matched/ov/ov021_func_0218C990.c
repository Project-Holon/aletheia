/*
 * function: func_0218C990
 * address:  0x0218C990
 * packet:   pkt_ov021_0218C990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C944  0x0218C944  thumb  ov021
 */

int func_0218C944(unsigned char *p, int a, int b);

int func_0218C990(unsigned char *p, int v)
{
    if (p == 0)
        return 0;
    return func_0218C944(p, *(int *)(p + 4), v);
}
