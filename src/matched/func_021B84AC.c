/*
 * function: func_021B84AC
 * address:  0x021B84AC
 * packet:   pkt_021B8230
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B84AC   0x021B84AC  thumb
 *   func_021B83FC   0x021B83FC  thumb  ov016

 *
 * Store c, then tail-call func_021B83FC with a and p+1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B84AC.c \
 *       --func func_021B84AC --addr 0x021B84AC --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_021B83FC(int, int *);

void func_021B84AC(int *p, int a, int c)
{
    *p = c;
    func_021B83FC(a, p + 1);
}
