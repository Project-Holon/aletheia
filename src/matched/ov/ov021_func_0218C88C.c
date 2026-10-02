/*
 * function: func_0218C88C
 * address:  0x0218C88C
 * packet:   pkt_ov021_0218C88C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C3B0  0x0218C3B0  thumb  ov021
 */

void func_0218C3B0(unsigned char *p, int i, int c);

void func_0218C88C(unsigned char *p, int v, int c)
{
    if (p != 0) {
        *(int *)(p + 4) = v;
        func_0218C3B0(p + 0xC, v, c);
    }
}
