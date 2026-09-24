/*
 * function: func_021B82D0
 * address:  0x021B82D0
 * packet:   pkt_021B8230
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B82D0   0x021B82D0  thumb
 *
 * Store c through p, then tail-call func_0215F454 with the same arguments.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B82D0.c \
 *       --func func_021B82D0 --addr 0x021B82D0 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_0215F454(unsigned int, unsigned char *, unsigned char);

void func_021B82D0(unsigned int a, unsigned char *p, unsigned char c)
{
    *p = c;
    func_0215F454(a, p, c);
}
