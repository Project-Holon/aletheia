/*
 * function: func_021BA174
 * address:  0x021BA174
 * packet:   pkt_ov172_021BA174
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Zero-fills a byte buffer, then runs func_021B6A00 over it.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B6A00  0x021B6A00  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

extern void func_02082BCC(void *p, int v, int n);
extern int func_021B6A00(void *a0, unsigned a1, void *a2);

int func_021BA174(int unused, void *a, void *buf, unsigned n)
{
    func_02082BCC(buf, 0, n);
    return func_021B6A00(a, n, buf);
}
