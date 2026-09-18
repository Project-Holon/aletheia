/*
 * unit:     yes
 * function: func_0209AA0C
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
 *
 * fdlibm sin().  The machine entry is 0x0209AA08, four bytes before the
 * disasm body label func_0209AA0C: the stub is the compiler's `push {r0-r3}`
 * spilling the register-passed double argument, so the body reads x from the
 * stack and pops 16 bytes on every return.  The unit is anchored at the stub
 * and the function list records the body label the worklist names.
 *
 * |x| <= pi/4 short-circuits to __kernel_sin(x, 0.0, 0); the general path
 * reduces with __ieee754_rem_pio2 and selects a kernel on n & 3.  Negation
 * and x-x lower to the MSL soft-float subtract helper _dsub.
 *
 * Callees by address:
 *   func_0209A0EC  __kernel_sin(double, double, int)
 *   func_02099224  __kernel_cos(double, double)
 *   func_02098B44  __ieee754_rem_pio2(double, double *)
 *   func_0209AF34  __dsub(double, double)
 */

typedef int i32;

#define HI(x) (((i32 *)&(x))[1])

extern double func_0209A0EC(double x, double y, int iy);
extern double func_02099224(double x, double y);
extern int func_02098B44(double x, double *y);
extern double func_0209AF34(double x, double y);

double func_0209AA0C(double x)
{
    double y[2];
    double z = 0.0;
    int n;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return func_0209A0EC(x, z, 0);
    else if (ix >= 0x7ff00000)
        return x - x;
    else
    {
        n = func_02098B44(x, y);
        switch (n & 3)
        {
        case 0:
            return func_0209A0EC(y[0], y[1], 1);
        case 1:
            return func_02099224(y[0], y[1]);
        case 2:
            return -func_0209A0EC(y[0], y[1], 1);
        default:
            return -func_02099224(y[0], y[1]);
        }
    }
}
