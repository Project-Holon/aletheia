/*
 * unit:     yes
 * function: func_0209A390
 * address:  0x0209A390
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
 * fdlibm cos().  The machine entry is 0x0209A390, four bytes before the
 * disasm label func_0209A390: the disassembler never saw the real entry
 * because nothing calls cos by name, so it labelled the body and left the
 * prologue stub as an unlabelled word.  That stub is the compiler's
 * `push {r0-r3}` for the register-passed double argument, which is why the
 * body reads x from [sp, #0x20]/[sp, #0x24] and why every return ends
 * `add sp, sp, #0x10` to pop the spilled pair.  Comparing from the label
 * alone starts after the stub and cannot line up; anchored here the whole
 * 372-byte function matches, and the header's function list records the
 * body label so the worklist entry at 0x0209A394 is covered too.
 *
 * |x| <= pi/4 short-circuits to __kernel_cos(x, 0.0); the general path
 * reduces with __ieee754_rem_pio2 and selects a kernel on n & 3.  Unary
 * minus and x-x lower to the MSL soft-float subtract helper _dsub (the
 * table entry `__dadd_dsub` at 0x0209AF34 is its subtract entry).
 *
 * Callees by address:
 *   func_02099224  __kernel_cos(double, double)
 *   func_0209A0EC  __kernel_sin(double, double, int)
 *   func_02098B44  __ieee754_rem_pio2(double, double *)
 */

typedef int i32;

#define HI(x) (((i32 *)&(x))[1])

extern double func_02099224(double x, double y);
extern double func_0209A0EC(double x, double y, int iy);
extern int func_02098B44(double x, double *y);

double func_0209A390(double x)
{
    double y[2];
    double z = 0.0;
    int n;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return func_02099224(x, z);
    else if (ix >= 0x7ff00000)
        return x - x;
    else
    {
        n = func_02098B44(x, y);
        switch (n & 3)
        {
        case 0:
            return func_02099224(y[0], y[1]);
        case 1:
            return -func_0209A0EC(y[0], y[1], 1);
        case 2:
            return -func_02099224(y[0], y[1]);
        default:
            return func_0209A0EC(y[0], y[1], 1);
        }
    }
}
