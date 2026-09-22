/*
 * unit:     no
 * function: func_0209A7A8
 * address:  0x0209A7A8
 * packet:   pkt_02098B44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 * note:     EXACT* not EXACT: the next function's own home-area push
 *           (0x0209AA08, sin's `push {r0, r1, r2, r3}`, already covered by
 *           src/matched/unit_0209AA08.c) carries no label of its own, so the
 *           printed extent is 612 against a compiled 608.  All 608 compared
 *           bytes match and all 12 relocations resolve.
 * symbols:
 *   func_020921F4  0x020921F4  arm
 *   func_0209A368  0x0209A368  arm
 *   _deq   0x0209BA3C  arm
 *   _dmul  0x0209B2E8  arm
 *   _dadd  0x0209AC04  arm
 *
 * MSL ldexp(double, int), with fdlibm scalbn() inlined into it.
 *
 * The wrapper is the first eight instructions: __fpclassify(x) (0x020921F4)
 * and, only when that says the value is finite-and-not-one-of-the-low-classes,
 * an equality test against 0.0 that lowers to the soft-float __dcmp_5 at
 * 0x0209BA3C.  Either test failing returns x untouched; everything after
 * 0x0209A7F8 is scalbn's own body.
 *
 * Identified by the full fdlibm scalbn constant set in the pool at 0x0209A9DC:
 * two54 (0x43500000), twom54 (0x3C900000), huge = 1.0e300
 * (0x7E37E43C_8800759C), tiny = 1.0e-300 (0x01A56E1F_C2F8F359) and the
 * +-50000 exponent clamps (0x0000C350 / 0xFFFF3CB0).
 *
 * The leading `push {r0, r1, r2, r3}` at 0x0209A7A8 is the home area for the
 * register-passed double: the body reads and writes x's words from
 * [sp, #0x10]/[sp, #0x14] through &x, and every return pops 16 bytes.
 * See the cluster header docs/families/cluster_02098B44.h.
 */

typedef int i32;
typedef unsigned int u32;

#define HI(x) (((i32 *)&(x))[1])
#define LO(x) (((i32 *)&(x))[0])

static const double two54   = 1.80143985094819840000e+16;
static const double twom54  = 5.55111512312578270212e-17;
static const double huge    = 1.0e+300;
static const double tiny    = 1.0e-300;

extern int func_020921F4(double x);
extern double func_0209A368(double x, double y);

double func_0209A7A8(double x, int n)
{
    i32 k, hx, lx;

    if (func_020921F4(x) <= 2 || x == 0.0)
        return x;

    hx = HI(x);
    lx = LO(x);
    k = (hx & 0x7ff00000) >> 20;
    if (k == 0)
    {
        if ((lx | (hx & 0x7fffffff)) == 0)
            return x;
        x *= two54;
        hx = HI(x);
        k = ((hx & 0x7ff00000) >> 20) - 54;
        if (n < -50000)
            return tiny * x;
    }
    if (k == 0x7ff)
        return x + x;
    k = k + n;
    if (k > 0x7fe)
        return huge * func_0209A368(huge, x);
    if (k > 0)
    {
        HI(x) = (hx & 0x800fffff) | (k << 20);
        return x;
    }
    if (k <= -54)
    {
        if (n > 50000)
            return huge * func_0209A368(huge, x);
        else
            return tiny * func_0209A368(tiny, x);
    }
    k += 54;
    HI(x) = (hx & 0x800fffff) | (k << 20);
    return x * twom54;
}
