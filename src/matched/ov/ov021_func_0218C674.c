/*
 * function: func_0218C674
 * address:  0x0218C674
 * packet:   pkt_ov021_0218C674
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C530  0x0218C530  thumb  ov021
 *   func_0218B924  0x0218B924  thumb  ov021
 *   func_0218BCB0  0x0218BCB0  thumb  ov021
 */

unsigned char func_0218C530(int b);
int func_0218B924(unsigned char *p, int v);
int func_0218BCB0(int x);

int func_0218C674(unsigned char *p, int b)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= *(unsigned short *)(p + 0x1AC))
        v = 0;
    return func_0218BCB0(func_0218B924(p, v));
}
