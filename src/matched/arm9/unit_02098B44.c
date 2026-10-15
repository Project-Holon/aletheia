/*
 * unit:     yes
 * function: func_02098B44
 * address:  0x02098B44
 * packet:   pkt_02098B44
 * region:   arm9
 * compiler: 1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _dsub        0x0209AF34  arm
 *   _dmul        0x0209B2E8  arm
 *   _dadd        0x0209AC04  arm
 *   _dfix        0x0209C508  arm
 *   _dflt        0x0209B750  arm
 *   _deq         0x0209BA3C  arm
 *   fabs  0x0209A504  arm
 *   __kernel_rem_pio2  0x0209953C  arm
 *   npio2_hw     0x020A6320  data
 *   two_over_pi  0x020A63A0  data
 *
 * fdlibm __ieee754_rem_pio2(x, y), e_rem_pio2.c transcribed unchanged.  The
 * machine entry is 0x02098B44, four bytes before the disasm body label
 * func_02098B44: the compiler's push {r0-r3} spilling the register-passed
 * double, because HI(x) takes the address of x.  The body is MSL runtime
 * (layout/runtime_arm9.txt, _msl_double_fn_1); the unit exists so the 4-byte
 * worklist row at the stub is reproduced as part of its function.
 *
 * Front end dsi/1.2 (wave 17): the loop store tx[i] = (double)(int)z is two
 * str (1.1p1 merges them into stm), the same pin that fits __ieee754_pow at
 * 0x020979BC.  Fabs = fabs, __kernel_rem_pio2 = __kernel_rem_pio2;
 * npio2_hw and two_over_pi resolve through the sole-ref/data class.
 */

typedef int i32;

#define HI(x) (((i32 *)&(x))[1])
#define LO(x) (((i32 *)&(x))[0])

extern const i32 npio2_hw[];
extern const i32 two_over_pi[];
extern double fabs(double x);
extern int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const i32 *ipio2);

static const double
zero =  0.00000000000000000000e+00,
half =  5.00000000000000000000e-01,
two24 =  1.67772160000000000000e+07,
invpio2 =  6.36619772367581382433e-01,
pio2_1  =  1.57079632673412561417e+00,
pio2_1t =  6.07710050650619224932e-11,
pio2_2  =  6.07710050630396597660e-11,
pio2_2t =  2.02226624879595063154e-21,
pio2_3  =  2.02226624871116645580e-21,
pio2_3t =  8.47842766036889956997e-32;

int func_02098B44(double x, double *y)
{
    double z, w, t, r, fn;
    double tx[3];
    int e0, i, j, nx, n, ix, hx;

    hx = HI(x);
    ix = hx & 0x7fffffff;
    if (ix <= 0x3fe921fb)
    {
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    if (ix < 0x4002d97c)
    {
        if (hx > 0)
        {
            z = x - pio2_1;
            if (ix != 0x3ff921fb)
            {
                y[0] = z - pio2_1t;
                y[1] = (z - y[0]) - pio2_1t;
            }
            else
            {
                z -= pio2_2;
                y[0] = z - pio2_2t;
                y[1] = (z - y[0]) - pio2_2t;
            }
            return 1;
        }
        else
        {
            z = x + pio2_1;
            if (ix != 0x3ff921fb)
            {
                y[0] = z + pio2_1t;
                y[1] = (z - y[0]) + pio2_1t;
            }
            else
            {
                z += pio2_2;
                y[0] = z + pio2_2t;
                y[1] = (z - y[0]) + pio2_2t;
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb)
    {
        t = fabs(x);
        n = (int)(t * invpio2 + half);
        fn = (double)n;
        r = t - fn * pio2_1;
        w = fn * pio2_1t;
        if (n < 32 && ix != npio2_hw[n - 1])
        {
            y[0] = r - w;
        }
        else
        {
            j = ix >> 20;
            y[0] = r - w;
            i = j - (((HI(y[0])) >> 20) & 0x7ff);
            if (i > 16)
            {
                t = r;
                w = fn * pio2_2;
                r = t - w;
                w = fn * pio2_2t - ((t - r) - w);
                y[0] = r - w;
                i = j - (((HI(y[0])) >> 20) & 0x7ff);
                if (i > 49)
                {
                    t = r;
                    w = fn * pio2_3;
                    r = t - w;
                    w = fn * pio2_3t - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0)
        {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        }
        else
            return n;
    }
    if (ix >= 0x7ff00000)
    {
        y[0] = y[1] = x - x;
        return 0;
    }
    LO(z) = LO(x);
    e0 = (ix >> 20) - 1046;
    HI(z) = ix - (e0 << 20);
    for (i = 0; i < 2; i++)
    {
        tx[i] = (double)((int)(z));
        z = (z - tx[i]) * two24;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == zero)
        nx--;
    n = __kernel_rem_pio2(tx, y, e0, nx, 2, two_over_pi);
    if (hx < 0)
    {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}
