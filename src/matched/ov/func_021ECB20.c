/*
 * function: func_021ECB20
 * address:  0x021ECB20
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ECA6C  0x021ECA6C  thumb  ov170
 *
 * Dispatch flag bits 1 and 2 to the two range halves, with bit
 *   0x80 selecting the sub-range selector.  Matches on the tst-based ternary.
 */


extern void func_021ECA6C(char *, int, int, int, int);
void func_021ECB20(char *p, int f, int c)
{
    int t = (f & 0x80) ? 1 : 0;
    if (f & 1)
        func_021ECA6C(p, c, 0, 0x1e, t);
    if (f & 2)
        func_021ECA6C(p, c, 0x1e, 0x25, t);
}
