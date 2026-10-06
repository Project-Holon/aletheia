/*
 * function: func_021ED14C
 * address:  0x021ED14C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC08C  0x021EC08C  thumb  ov170
 *
 * One range call with the sub-range selector.
 */



extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
void func_021ED14C(int a, int b, int c)
{
    func_021EC08C((char *)a, 10, b, c, 0);
}
