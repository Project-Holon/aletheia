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

extern int func_0217B9BC(unsigned int x);
extern void func_0217BA10(char *p, int x);
extern int func_0217BA48(char *p, unsigned int *mask);
extern int func_0217BA6C(char *p, unsigned int *mask);

int func_0217BAA8(int a, int b, int *p, int *q)
{
    int r, t;
    *p = 0;
    *q = 0;
    if (func_0217B9BC(b) == 0)
        return 1;
    func_0217BA10((char *)a, b);
    r = func_0217BA48((char *)a, (unsigned int *)p);
    t = func_0217BA6C((char *)a, (unsigned int *)q);
    if (r == 0 || t == 0)
        return 1;
    return 0;
}
