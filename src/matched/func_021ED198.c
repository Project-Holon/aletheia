/*
 * function: func_021ED198
 * address:  0x021ED198
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
 * Read the 2-short record for the sub-range then push it back with
 *   the first element biased by 4.
 */


extern void func_021EC548(int, short *, short *, int);
extern void func_021ED14C(char *, int, int);
void func_021ED198(char *p, int a, int c)
{
    short t[2];
    func_021EC548(a, t + 1, t, c);
    func_021ED14C(p, t[1], (short)(t[0] + 4));
}
