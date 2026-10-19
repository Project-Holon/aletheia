/*
 * function: Set_WLLA_LINK_STAT
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
 *   Set_WLLA_LINK_STAT   0x021B84AC  thumb
 *   func_021B83FC   0x021B83FC  thumb  ov016

 *
 * Store c, then tail-call func_021B83FC with a and p+1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/Set_WLLA_LINK_STAT.c \
 *       --func Set_WLLA_LINK_STAT --addr 0x021B84AC --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_021B83FC(int, int *);

void Set_WLLA_LINK_STAT(int *p, int a, int c)
{
    *p = c;
    func_021B83FC(a, p + 1);
}
