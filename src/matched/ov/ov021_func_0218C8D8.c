/*
 * function: func_0218C8D8
 * address:  0x0218C8D8
 * packet:   pkt_ov021_0218C8D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218C910  0x0218C910  thumb  ov021
 *   func_0218C89C  0x0218C89C  thumb  ov021
 */

int func_0218C910(unsigned char *p);
void func_0218C89C(unsigned char *p, int v);

int func_0218C8D8(void *p)
{
    if (p == 0)
        return 1;
    if (func_0218C910(p) == 1) {
        func_0218C89C(p, 3);
        return 1;
    }
    return 0;
}
