/*
 * function: func_0217C274
 * address: 0x0217C274
 * packet: pkt_ov018_0217C274
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D63C 0x0216D63C thumb ov010
 */
extern int func_0216D63C(char *, int);
void func_0217C274(unsigned int *out, char *p)
{
    int lo;
    lo = func_0216D63C(p, 1);
    *out = lo | (func_0216D63C(p, 2) << 16);
}
