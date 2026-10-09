/*
 * file:     unit_020911D4_p09.c
 * unit:     yes
 * function: func_0209A0F0, func_0209A368, func_0209A394, func_0209A504, func_0209A524, func_0209A6E8, func_0209A7A8, func_0209AA0C, func_0209AB80, func_0209AB8C
 * address:  0x0209A0EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _dsub  0x0209AF34  arm
 *   _dmul  0x0209B2E8  arm
 *   _dadd  0x0209AC04  arm
 *   _dfix  0x0209C508  arm
 *   _dgr  0x0209B864  arm
 *   func_020921F4  0x020921F4  arm
 *   _deq  0x0209BA3C  arm
 *   func_020979BC  0x020979BC  arm
 *   g_020A60DC  0x020A60DC  data
 */

/* Matched units compiled in this file, entered 4 bytes before their function:
 * unit_0209A0EC (0x0209A0EC) holds func_0209A0F0
 * unit_0209A390 (0x0209A390) holds func_0209A394
 * unit_0209AA08 (0x0209AA08) holds func_0209AA0C
 */

typedef int i32;

#define HI(x) (((i32 *)&(x))[1])

extern double func_0209B2E8(double x, double y);
extern double func_0209AC04(double x, double y);
extern double func_0209AF34(double x, double y);
extern int func_0209C508(double x);

/*
 * fdlibm __kernel_sin().  The machine entry is 0x0209A0EC, four bytes before
 * the disasm body label func_0209A0F0: 0x0209A0EC is the compiler's
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
double func_0209A0F0(double x, double y, int iy)
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

typedef unsigned int u32;

extern double func_02099224(double x, double y);
extern double func_0209A0EC(double x, double y, int iy);
extern int func_02098B44(double x, double *y);
double func_0209A368(double x, double y);
double func_0209A394(double x);

/*
 * note:     EXACT* not EXACT: scan_listing puts the next label 4 bytes past
 *           this function's real end (0x0209A390, a pool-adjacent follower),
 *           so the printed extent is 44 against a compiled 40.  Bytes all
 *           match and there are no relocation sites.
 *
 * MSL copysign(): combines the magnitude of the first double with the sign
 * of the second, reading both hi words off the stack after `push {r0-r3}`
 * (the address-of-a-register-parameter idiom, doubled for two doubles).
 */
double func_0209A368(double x, double y)
{
    ((u32 *)&x)[1] = (((u32 *)&x)[1] & 0x7fffffff) | (((u32 *)&y)[1] & 0x80000000);
    return x;
}

#define HI(x) (((i32 *)&(x))[1])

/*
 * fdlibm cos().  The machine entry is 0x0209A390, four bytes before the
 * disasm label func_0209A394: the disassembler never saw the real entry
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
double func_0209A394(double x)
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

double func_0209A504(double x);
double func_0209A524(double x);

/*
 * MSL fabs(): the hi word of the double is cleared via `&x`, which is the
 * address-of-a-register-parameter idiom and produces `push {r0-r3}`; the
 * mask folds to `bic r1, r1, #0x80000000`.
 */
double func_0209A504(double x)
{
    ((u32 *)&x)[1] &= 0x7fffffff;
    return x;
}

#define HI(x) (((i32 *)&(x))[1])

#define LO(x) (((i32 *)&(x))[0])

static const double huge = 1.0e300;

/*
 * fdlibm floor().  Identified by its two pool constants: huge = 1.0e300
 * (0x7E37E43C_8800759C, the classic fdlibm inexact-raising addend) and
 * 0xBFF00000, the high word of -1.0 that the |x| < 1, x < 0 arm returns.
 * The `huge + x > 0.0` guard is a soft-float __dadd followed by __dcmp_2,
 * which is why every arm of the function calls out twice.
 *
 * The leading `push {r0, r1, r2, r3}` at 0x0209A524 is the home area for the
 * register-passed double: the body reads x's words from [sp, #0x20]/[sp,
 * #0x24] through &x, and every return pops 16 bytes.  See the cluster header
 * docs/families/cluster_02098B44.h.
 */
double func_0209A524(double x)
{
    i32 i0, i1, j0;
    u32 i, j;

    i0 = HI(x);
    i1 = LO(x);
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20)
    {
        if (j0 < 0)
        {
            if (huge + x > 0.0)
            {
                if (i0 >= 0)
                {
                    i0 = i1 = 0;
                }
                else if (((i0 & 0x7fffffff) | i1) != 0)
                {
                    i0 = 0xbff00000;
                    i1 = 0;
                }
            }
        }
        else
        {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0)
                return x;
            if (huge + x > 0.0)
            {
                if (i0 < 0)
                    i0 += (0x00100000) >> j0;
                i0 &= (~i);
                i1 = 0;
            }
        }
    }
    else if (j0 > 51)
    {
        if (j0 == 0x400)
            return x + x;
        else
            return x;
    }
    else
    {
        i = ((u32)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0)
            return x;
        if (huge + x > 0.0)
        {
            if (i0 < 0)
            {
                if (j0 == 20)
                    i0 += 1;
                else
                {
                    j = i1 + (1 << (52 - j0));
                    if (j < (u32)i1)
                        i0 += 1;
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }
    HI(x) = i0;
    LO(x) = i1;
    return x;
}

extern int func_020921F4(double x);
extern double func_0209A368(double x, double y);
double func_0209A6E8(double x, int *eptr);
double func_0209A7A8(double x, int n);

#define HI(x) (((i32 *)&(x))[1])

#define LO(x) (((i32 *)&(x))[0])

static const double two54 = 1.80143985094819840000e+16;

/*
 * fdlibm frexp().  Word access goes through the address of the register
 * parameter `x`, which is why the prologue preserves r0-r3 even though this
 * is not a call that needs them.  Scaled subnormals are multiplied by the
 * inline double constant two54; the compiler keeps its zero low word in r5
 * and only pools the 0x43500000 high half.
 */
double func_0209A6E8(double x, int *eptr)
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

#define HI(x) (((i32 *)&(x))[1])

#define LO(x) (((i32 *)&(x))[0])

static const double twom54  = 5.55111512312578270212e-17;

static const double tiny    = 1.0e-300;

/*
 * note:     EXACT* not EXACT: the next function's own home-area push
 *           (0x0209AA08, sin's `push {r0, r1, r2, r3}`, already covered by
 *           src/matched/unit_0209AA08.c) carries no label of its own, so the
 *           printed extent is 612 against a compiled 608.  All 608 compared
 *           bytes match and all 12 relocations resolve.
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

extern void func_020979BC(void);
double func_0209AA0C(double x);
void func_0209AB80(void);

#define HI(x) (((i32 *)&(x))[1])

/*
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

void func_0209AB80(void)
{
    func_020979BC();
}

typedef unsigned char u8;

extern const u8 g_020A60DC[];

/*
 * note:     EXACT* not EXACT: the label following this function in the
 *           listing is the veneer block at 0x0209AC04 (0x0209ABEC/0x0209ABF8
 *           are unlabelled), so the printed extent is 120 against a compiled
 *           96.  All 96 compared bytes (code + literal pool) match and the
 *           single relocation resolves via `literal`.
 * Case-insensitive string compare: each byte is mapped through the 256-byte
 * table at 0x020A60DC when it is below 0x80, then compared as unsigned.
 * The `>= 0` half of the guard is what emits the `cmp #0; blt` before the
 * `cmp #0x80; ldrblt`, even though the byte load is unsigned.
 *
 * The interleaved declarations (`int c1; u8 m1; int c2; u8 m2;`) matter:
 * they make mwccarm color the c1 mask into ip and the raw c2 into lr, which
 * is what the original does.  Declaring the two mask temps together instead
 * swaps those two scratch registers (9-byte DIFF).
 */
int func_0209AB8C(const u8 *s1, const u8 *s2)
{
    const u8 *tab = g_020A60DC;
    int c1;
    u8 m1;
    int c2;
    u8 m2;

    for (;;)
    {
        c1 = *s1++;
        if (c1 >= 0 && c1 < 0x80)
            c1 = tab[c1];
        m1 = (u8)c1;

        c2 = *s2++;
        if (c2 >= 0 && c2 < 0x80)
            c2 = tab[c2];
        m2 = (u8)c2;

        if (m1 < m2)
            return -1;
        if (m1 > m2)
            return 1;
        if (m1 == 0)
            return 0;
    }
}
