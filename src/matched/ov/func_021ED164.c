/*
 * function: func_021ED164
 * address:  0x021ED164
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC548  0x021EC548  thumb  ov170
 *   func_021ED14C  0x021ED14C  thumb  ov170
 *
 * Twin of func_021ED198 with both shorts biased by 8.
 */


extern void func_021EC548(unsigned i, short *x, short *y, int mode);
extern void func_021ED14C(char *, int, int);
void func_021ED164(char *p, int a, int c)
{
    short t[2];
    func_021EC548(a, t + 1, t, c);
    func_021ED14C(p, (short)(t[1] + 8), (short)(t[0] + 8));
}
