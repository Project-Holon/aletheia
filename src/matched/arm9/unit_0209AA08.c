/*
 * unit:     yes
 * function: sin
 * address:  0x0209AA08
 * packet:   pkt_0209A0EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _dsub  0x0209AF34  arm
 *   __kernel_sin  0x0209A0EC  arm
 *   __ieee754_rem_pio2  0x02098B44  arm
 *   __kernel_cos  0x02099224  arm
 *
 * fdlibm sin().  The machine entry is 0x0209AA08, four bytes before the
 * disasm body label sin: the stub is the compiler's `push {r0-r3}`
 * spilling the register-passed double argument, so the body reads x from the
 * stack and pops 16 bytes on every return.  The unit is anchored at the stub
 * and the function list records the body label the worklist names.
 *
 * |x| <= pi/4 short-circuits to __kernel_sin(x, 0.0, 0); the general path
 * reduces with __ieee754_rem_pio2 and selects a kernel on n & 3.  Negation
 * and x-x lower to the MSL soft-float subtract helper _dsub.
 *
 * Callees by address:
 *   __kernel_sin  __kernel_sin(double, double, int)
 *   __kernel_cos  __kernel_cos(double, double)
 *   __ieee754_rem_pio2  __ieee754_rem_pio2(double, double *)
 *   func_0209AF34  __dsub(double, double)
 */

typedef int i32;

#define HI(x) (((i32 *)&(x))[1])

extern double __kernel_sin(double x, double y, int iy);
extern double __kernel_cos(double x, double y);
extern int __ieee754_rem_pio2(double x, double *y);
extern double func_0209AF34(double x, double y);

double sin(double x)
{
    double y[2];
    double z = 0.0;
    int n;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return __kernel_sin(x, z, 0);
    else if (ix >= 0x7ff00000)
        return x - x;
    else
    {
        n = __ieee754_rem_pio2(x, y);
        switch (n & 3)
        {
        case 0:
            return __kernel_sin(y[0], y[1], 1);
        case 1:
            return __kernel_cos(y[0], y[1]);
        case 2:
            return -__kernel_sin(y[0], y[1], 1);
        default:
            return -__kernel_cos(y[0], y[1]);
        }
    }
}
