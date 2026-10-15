/*
 * unit:     yes
 * function: __kernel_cos
 * address:  0x02099224
 * packet:   pkt_02099224
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
 * fdlibm __kernel_cos(x, y).  The machine entry is 0x02099224, four bytes
 * before the disasm body label __kernel_cos: the stub is the compiler's
 * push {r0-r3} spilling the register-passed doubles, because HI(x) takes
 * the address of x.  The body is MSL runtime (layout/runtime_arm9.txt,
 * _msl_double_minimax_poly); the unit exists so the 4-byte worklist row at
 * the stub is reproduced as part of the function it belongs to.  Upstream
 * fdlibm k_cos.c transcribed unchanged; EXACT on the first compile.
 *
 * Callees by address:
 *   func_0209B2E8  __dmul, func_0209AC04  __dadd, func_0209AF34  __dsub,
 *   func_0209C508  __d2s (double -> int)
 */

typedef int i32;

#define HI(x) (((i32 *)&(x))[1])
#define LO(x) (((i32 *)&(x))[0])

double __kernel_cos(double x, double y)
{
    static const double one = 1.00000000000000000000e+00;
    static const double C1 = 4.16666666666666019037e-02;
    static const double C2 = -1.38888888888741095749e-03;
    static const double C3 = 2.48015872894767294178e-05;
    static const double C4 = -2.75573143513906633035e-07;
    static const double C5 = 2.08757232129817482790e-09;
    static const double C6 = -1.13596475577881948265e-11;

    double a, hz, z, r, qx;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix < 0x3e400000)
    {
        if ((int)x == 0)
            return one;
    }
    z = x * x;
    r = z * (C1 + z * (C2 + z * (C3 + z * (C4 + z * (C5 + z * C6)))));
    if (ix < 0x3FD33333)
        return one - (0.5 * z - (z * r - x * y));
    else
    {
        if (ix > 0x3fe90000)
        {
            qx = 0.28125;
        }
        else
        {
            HI(qx) = ix - 0x00200000;
            LO(qx) = 0;
        }
        hz = 0.5 * z - qx;
        a = one - qx;
        return a - (hz - (z * r - x * y));
    }
}
