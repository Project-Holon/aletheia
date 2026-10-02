/*
 * function: func_0218C8B0
 * address:  0x0218C8B0
 * packet:   pkt_ov021_0218C8B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C8FC  0x0218C8FC  thumb  ov021
 *   func_0218C88C  0x0218C88C  thumb  ov021
 */

extern int func_0218C8FC(void *p, int i);
extern void func_0218C88C(void *p, int a, int b);

int func_0218C8B0(void *p, int v)
{
    if (p == 0)
        return 1;
    if (func_0218C8FC(p, v) == 1) {
        func_0218C88C(p, v, 3);
        return 1;
    }
    return 0;
}
