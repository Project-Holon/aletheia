/*
 * function: func_0218C7D8
 * address:  0x0218C7D8
 * packet:   pkt_ov021_0218C7D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C654  0x0218C654  thumb  ov021
 *   func_0218C724  0x0218C724  thumb  ov021
 */

int func_0218C654(void *p, int b, int c);
int func_0218C724(void *p, int r);

int func_0218C7D8(void *p, int b, int c)
{
    int r = func_0218C654(p, b, c);
    if (r == 0)
        return 0;
    return func_0218C724(p, r);
}
