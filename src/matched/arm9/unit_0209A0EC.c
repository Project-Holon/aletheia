/*
 * unit:     yes
 * function: __kernel_sin
 * address:  0x0209A0EC
 * packet:   pkt_0209A0EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _dsub  0x0209AF34  arm
 *   _dmul  0x0209B2E8  arm
 *   _dadd  0x0209AC04  arm
 *   _dfix  0x0209C508  arm
 *
 * fdlibm __kernel_sin().  The machine entry is 0x0209A0EC, four bytes before
 * the disasm body label __kernel_sin: 0x0209A0EC is the compiler's
 * `push {r0-r3}` spilling the double arguments x (r0:r1) and y (r2:r3), so
 * the body reads them from the stack and pops 16 bytes on every return.
 * Both the stub address and the body label are worklist entries, so the unit
 * is anchored at the stub and the function list records the body label.
 *
 * Callees by address:
 *   func_0209B2E8  __dmul(double, double)
 *   func_0209AC04  __dadd(double, double)
 *   func_0209AF34  __dsub(double, double)
 *   func_0209C508  __d2s (double -> int)
 */

typedef int i32;

#define HI(x) (((i32 *)&(x))[1])

extern double func_0209B2E8(double x, double y);
extern double func_0209AC04(double x, double y);
extern double func_0209AF34(double x, double y);
extern int func_0209C508(double x);

double __kernel_sin(double x, double y, int iy)
{
    static const double half = 5.00000000000000000000e-01;
    static const double S1 = -1.66666666666666324348e-01;
    static const double S2 = 8.33333333332248946124e-03;
    static const double S3 = -1.98412698298579493134e-04;
    static const double S4 = 2.75573137070700676789e-06;
    static const double S5 = -2.50507602534068634195e-08;
    static const double S6 = 1.58969099521155010221e-10;

    double z, r, v;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix < 0x3e400000)
    {
        if ((int)x == 0)
            return x;
    }
    z = x * x;
    v = z * x;
    r = S2 + z * (S3 + z * (S4 + z * (S5 + z * S6)));
    if (iy == 0)
        return x + v * (S1 + z * r);
    else
        return x - ((z * (half * y - v * r) - y) - v * S1);
}
