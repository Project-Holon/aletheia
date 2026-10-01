/*
 * function: func_0218C6F4
 * address:  0x0218C6F4
 * packet:   pkt_ov021_0218C6F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C530  0x0218C530  thumb  ov021
 *   func_0218C47C  0x0218C47C  thumb  ov021
 */

unsigned char func_0218C530(int b);
int func_0218C47C(void *p, int id);

int func_0218C6F4(unsigned char *p, int b, int id)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= *(unsigned short *)(p + 0x1AC))
        v = 0;
    return func_0218C47C(*(unsigned char **)(p + 0x1D8) + v * 0x18, id);
}
