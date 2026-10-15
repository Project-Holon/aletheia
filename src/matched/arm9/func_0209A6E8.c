/*
 * unit:     no
 * function: frexp
 * address:  0x0209A6E8
 * packet:   pkt_0209A0EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _dmul  0x0209B2E8  arm
 *
 * fdlibm frexp().  Word access goes through the address of the register
 * parameter `x`, which is why the prologue preserves r0-r3 even though this
 * is not a call that needs them.  Scaled subnormals are multiplied by the
 * inline double constant two54; the compiler keeps its zero low word in r5
 * and only pools the 0x43500000 high half.
 */

typedef int i32;

#define HI(x) (((i32 *)&(x))[1])
#define LO(x) (((i32 *)&(x))[0])

static const double two54 = 1.80143985094819840000e+16;

double frexp(double x, int *eptr)
{
    int hx;
    int ix;
    int lx;

    hx = HI(x);
    lx = LO(x);
    ix = 0x7fffffff & hx;
    *eptr = 0;
    if (ix >= 0x7ff00000 || ((ix | lx) == 0))
        return x;
    if (ix < 0x00100000)
    {
        x *= two54;
        hx = HI(x);
        ix = hx & 0x7fffffff;
        *eptr = -54;
    }
    *eptr += (ix >> 20) - 1022;
    hx = (hx & 0x800fffff) | 0x3fe00000;
    HI(x) = hx;
    return x;
}