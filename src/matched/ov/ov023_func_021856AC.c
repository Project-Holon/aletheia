/*
 * function: func_021856AC
 * address:  0x021856AC
 * packet:   pkt_021856AC
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02185354  0x02185354  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_021861C4  0x021861C4  thumb  ov023
 */

extern void func_02185354(char *p);
extern void func_02186444(char *p, int v);
extern void func_021861C4(char *p, int a, int b);

int func_021856AC(char *p, int a1)
{
    func_021861C4(p, 6, 1);
    func_02186444(p, 0xd);
    func_02185354(p);
    return a1;
}
