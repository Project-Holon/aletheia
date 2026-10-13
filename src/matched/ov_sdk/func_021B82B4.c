/*
 * function: AOSS_Sendto
 * address:  0x021B82B4
 * packet:   pkt_021B82B4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   AOSS_Sendto   0x021B82B4  thumb
 *
 * Store a byte through arg 4, then pass it on as the fifth argument of func_0215F5B4.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Sendto.c \
 *       --func AOSS_Sendto --addr 0x021B82B4 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_0215F5B4(int, int, int, int, void *);

void AOSS_Sendto(int a, int b, int c, int d, unsigned char *p, int v)
{
    *p = (unsigned char)v;
    func_0215F5B4(a, b, c, d, p);
}
