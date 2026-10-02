/*
 * function: func_02097990
 * address:  0x02097990
 * packet:   pkt_02097990
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0209A6E8  0x0209A6E8  arm
 *   func_0209A7A8  0x0209A7A8  arm
 */


extern double func_0209A6E8(double x, int *eptr);
extern double func_0209A7A8(double x, int n);

double func_02097990(double x, int n)
{
    int t;
    double v = func_0209A6E8(x, &t);
    t += n;
    return func_0209A7A8(v, t);
}
