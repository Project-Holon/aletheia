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
 *   frexp  0x0209A6E8  arm
 *   ldexp  0x0209A7A8  arm
 */


extern double frexp(double x, int *eptr);
extern double ldexp(double x, int n);

double func_02097990(double x, int n)
{
    int t;
    double v = frexp(x, &t);
    t += n;
    return ldexp(v, t);
}
