/*
 * function: __num2dec
 * address:  0x02097170
 * packet:   pkt_02096D10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   __signbitd  0x020921D8  arm
 *   __fpclassifyd  0x020921F4  arm
 *   _deq           0x0209BA3C  arm
 *   func_0209AF34  0x0209AF34  arm
 *   frexp  0x0209A6E8  arm
 *   MSL_C_LIB_PopCount64  0x02092144  arm
 *   __two_exp  0x02096990  arm
 *   ldexp  0x0209A7A8  arm
 *   func_0209C554  0x0209C554  arm
 *   __ull2dec  0x020966B0  arm
 *   __timesdec  0x02096774  arm
 *
 * MSL `__num2dec` -- convert a double to the 38-byte packed decimal record
 * (DB) that this family's other functions add, subtract, multiply and print.
 * The record is { u8 sign; u8 pad; s16 exp10; u8 ndigits; u8 digits[33] }.
 *
 * Three paths:
 *   1. x == 0.0                 -> sign, exp 0, one digit, digit = 0.
 *   2. NaN or infinity          -> __fpclassifyd (the MSL fpclassify: 1 = NaN,
 *      2 = Inf, 3 = zero, 4 = normal, 5 = subnormal) returns <= 2; the record
 *      gets one digit, 'N' (0x4E) for NaN and 'I' (0x49) for infinity.  The
 *      classify call is written TWICE, once for the guard and once for the
 *      digit, because the image calls 0x020921F4 twice (0x02097170+0x70 and
 *      +0x94); a cached result loses the second `bl`.
 *   3. finite non-zero: take the absolute value (`0.0 - x` through _dsub),
 *      frexp it into f in [0.5,1) with binary exponent e, then work out how
 *      many mantissa bits are significant:
 *        v  = the mantissa bits of f with the hidden bit forced on
 *        k  = 53 - popcount64((v & -v) - 1)      -- 53 minus the trailing
 *             zero count, i.e. the number of significant mantissa bits
 *      `__two_exp(&b, e - k)` builds the decimal record of 2^(e-k) (the
 *      recursive power-of-two formatter, dense switch over -32..+8), and
 *      `__ull2dec(&a, (u64)ldexp(f, k))` builds the decimal record of the
 *      exact integer mantissa.  `__timesdec(r, &a, &b)` multiplies the two
 *      records, and the sign is stamped last.
 *
 * THE ONE LEVER, and it is worth four instructions (376 bytes against 384).
 * `g = f;` before the bit read.  The bit pattern is taken through the address
 * of a SECOND double (`*(u64 *)&g`), not of `f` itself.  With one variable,
 * mwcc gives `f` a stack home, writes it there and RELOADS it with
 * `ldr r0,[sp] / ldr r1,[sp,#4]` after the popcount call for the ldexp
 * argument.  With the copy, `f` stays a pure register value in r4:r6 across
 * both calls (`mov r4,r0 / mov r6,r1` after frexp, `mov r0,r4 / mov r1,r6`
 * before ldexp) and only `g`'s home is written (`str r4,[sp] / str r6,[sp,#4]`
 * at +0x118), which is exactly the image.  That copy is also what widens the
 * prologue to `push {r3-r8,sb,lr}`: one more callee-saved register is needed
 * to hold f across the popcount.  A union over one variable does NOT do it --
 * it compiles byte for byte the same as the single-variable form.
 *
 * The zero test is spelled `x == 0.0`, a real double comparison, not a call:
 * mwcc lowers it to `bl _deq` (0x0209BA3C, __dcmp_5) followed IMMEDIATELY by
 * the conditional branch, because the helper returns condition flags.  An
 * explicit `extern int func_0209BA3C(double, double)` whose result is tested
 * costs an extra `cmp r0, #0`.  `_deq` is the name mwcc emits, so it is what
 * the symbols: block has to pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__num2dec.c \
 *       --func __num2dec --addr 0x02097170 --cc 1.1p1 --arm
 *   EXACT, 384 bytes, 12 of 12 relocation sites resolved.
 */

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u8  f0;
    u8  f1;
    s16 f2;
    u8  f4;
    u8  buf[33];
} DB;

extern int __signbitd(double v);
extern int __fpclassifyd(double v);
extern double func_0209AF34(double a, double b);
extern double frexp(double x, int *eptr);
extern u32 MSL_C_LIB_PopCount64(u64 x);
struct decimal;
extern void __two_exp(struct decimal *result, long exp);
extern double ldexp(double x, int n);
extern u64 func_0209C554(double x);
extern void __ull2dec(struct decimal *result, unsigned long long val);
extern void __timesdec(struct decimal *result, const struct decimal *x, const struct decimal *y);

void __num2dec(DB *r, double x)
{
    DB a;
    DB b;
    int e;
    u64 v;
    int k;
    double f;
    double g;
    u8 neg;

    neg = __signbitd(x) != 0;
    if (x == 0.0) {
        r->f0 = neg;
        r->f2 = 0;
        r->f4 = 1;
        r->buf[0] = 0;
        return;
    }
    if (__fpclassifyd(x) <= 2) {
        r->f0 = neg;
        r->f2 = 0;
        r->f4 = 1;
        r->buf[0] = (__fpclassifyd(x) == 1) ? 0x4E : 0x49;
        return;
    }
    if (neg)
        x = func_0209AF34(0.0, x);
    f = frexp(x, &e);
    g = f;
    v = *(u64 *)&g | 0x0010000000000000ULL;
    k = 0x35 - MSL_C_LIB_PopCount64((v & -v) - 1);
    __two_exp((struct decimal *)(&b), e - k);
    __ull2dec((struct decimal *)(&a), func_0209C554(ldexp(f, k)));
    __timesdec((struct decimal *)r, (const struct decimal *)(&a), (const struct decimal *)(&b));
    r->f0 = neg;
}
