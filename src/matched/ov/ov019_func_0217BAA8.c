/*
 * function: func_0217BAA8
 * address:  0x0217BAA8
 * packet:   pkt_ov019_0217BAA8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217B9BC  0x0217B9BC  thumb  ov019
 *   func_0217BA10  0x0217BA10  thumb  ov019
 *   func_0217BA48  0x0217BA48  thumb  ov019
 *   func_0217BA6C  0x0217BA6C  thumb  ov019
 */

extern int func_0217B9BC(int a);
extern void func_0217BA10(int a, int b);
extern int func_0217BA48(int a, int *p);
extern int func_0217BA6C(int a, int *p);

int func_0217BAA8(int a, int b, int *p, int *q)
{
    int r, t;
    *p = 0;
    *q = 0;
    if (func_0217B9BC(b) == 0)
        return 1;
    func_0217BA10(a, b);
    r = func_0217BA48(a, p);
    t = func_0217BA6C(a, q);
    if (r == 0 || t == 0)
        return 1;
    return 0;
}
