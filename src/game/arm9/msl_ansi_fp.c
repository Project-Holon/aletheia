/*
 * file:     msl_ansi_fp.c
 * unit:     yes
 * function: __ull2dec, __timesdec, __str2dec, __two_exp, __equals_dec, __less_dec, __minus_dec, __num2dec, __dtoa, __dec2num
 * address:  0x020966B0
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from msl_c_lib.c by tools/splitfile.py.
 *
 * symbols:
 *   _ull_mod  0x0209C018  arm
 *   __float_huge  0x020A8814  data
 *   _dsub  0x0209AF34  arm
 *   _deq  0x0209BA3C  arm
 *   _dsub  0x0209AF34  arm
 *   frexp  0x0209A6E8  arm
 *   ldexp  0x0209A7A8  arm
 *   _ll_ufrom_d  0x0209C554  arm
 *   copysign  0x0209A368  arm
 *   pow  0x0209AB80  arm
 *   sMslAnsiFpPow10  0x020A8A7C  data
 *   s_020A8ABC     0x020A8ABC  data  a1
 *   s_020A8AEC     0x020A8AEC  data  a1
 *   s_020A8B14     0x020A8B14  data  a1
 *   s_020A8B2C     0x020A8B2C  data  a1
 *   s_020A8B3C     0x020A8B3C  data  a1
 *   s_020A8B44     0x020A8B44  data  a1
 *   s_020A8B4C     0x020A8B4C  data  a1
 *   s_020A8B54     0x020A8B54  data  a1
 *   s_020A8B5C     0x020A8B5C  data  a1
 *   s_020A8B60     0x020A8B60  data  a1
 *   s_020A8B64     0x020A8B64  data  a1
 *   s_020A8B68     0x020A8B68  data  a1
 *   s_020A8B6C     0x020A8B6C  data  a1
 *   s_020A8B70     0x020A8B70  data  a1
 *   s_020A8B74     0x020A8B74  data  a1
 *   s_020A8B78     0x020A8B78  data  a1
 *   s_020A8B7C     0x020A8B7C  data  a1
 *   s_020A8B80     0x020A8B80  data  a1
 *   s_020A8B84     0x020A8B84  data  a1
 *   s_020A8B88     0x020A8B88  data  a1
 *   s_020A8B8C     0x020A8B8C  data  a1
 *   s_020A8B90     0x020A8B90  data  a1
 *   MSL_C_LIB_PopCount64 0x02092144 arm arm9
 *   __signbitd 0x020921D8 arm arm9
 *   __fpclassifyd 0x020921F4 arm arm9
 *   MSL_C_LIB_IncrementDigits 0x02096620 arm arm9
 *   MSL_C_LIB_SetPrecision 0x02096670 arm arm9
 *   _dadd                        0x0209AC04  arm
 *   _ddiv                        0x0209D1E0  arm
 *   _dflt                        0x0209B750  arm
 *   _dfltu                       0x0209B790  arm
 *   _dmul                        0x0209B2E8  arm
 *   _f2d                         0x0209BD38  arm
 *   _ll_udiv                     0x0209C00C  arm
 */
#include "msl_crt_shared_types.h"
#include "msl_stdio_shared_types.h"
#include "msl_printf_shared_types.h"
#include "msl_strtod_shared_types.h"
#include "msl_wchar_shared_types.h"

#define FP_INFINITE 2

#define isinf(x) (__fpclassifyd(x) == FP_INFINITE)

struct MslDecString {
    u8  sign;
    u8  pad01;
    u16 exp;
    u8  length;
    u8  digits[32];
};

typedef struct {
    u8  reserved00[2];
    s16 key;
    volatile u8 length;
    u8  data[];
} MslStrRec;

typedef void (*DecFromStr)(decimal2 *d, const char *s, s16 exp);

extern double _dsub(double a, double b);

#include "msl_fdlibm.h"


                        /* copysign */

                        /* pow */

#include "msl_stdio.h"



#include "msl_wchar.h"


void __ull2dec(decimal2 *result, u64 val);

void __timesdec(decimal2 *result, const decimal2 *x, const decimal2 *y);

void __str2dec(struct MslDecString *dec, const u8 *s, u16 exponent);

void __two_exp(decimal2 *result, long exp);

int __equals_dec(MslStrRec *a, MslStrRec *b);

int __less_dec(MslStrRec *a, MslStrRec *b);

void __minus_dec(decimal2 *z, const decimal2 *x, const decimal2 *y);

void __num2dec(DB *r, double x);

void __dtoa(const decform *f, double x, decimal *p);

double __dec2num(const decimal2 *d);

extern float __float_huge;

extern const char s_020A8ABC[];

extern const char s_020A8AEC[];

extern const char s_020A8B14[];

extern const char s_020A8B2C[];

extern const char s_020A8B3C[];

extern const char s_020A8B44[];

extern const char s_020A8B4C[];

extern const char s_020A8B54[];

extern const char s_020A8B5C[];

extern const char s_020A8B60[];

extern const char s_020A8B64[];

extern const char s_020A8B68[];

extern const char s_020A8B6C[];

extern const char s_020A8B70[];

extern const char s_020A8B74[];

extern const char s_020A8B78[];

extern const char s_020A8B7C[];

extern const char s_020A8B80[];

extern const char s_020A8B84[];

extern const char s_020A8B88[];

extern const char s_020A8B8C[];

extern const double sMslAnsiFpPow10[8];

extern const char s_020A8B90[];     /* "179769313486231580793728714053034151" */

/*
 * MSL __ull2dec: unsigned long long -> decimal record (struct Bcd / DB in the
 * cluster headers, MSL's `decimal`).  Four lanes and ~2800 permuter compiles
 * left this at 192/196 bytes with the callee-saved set rotated by one and
 * one "declined live-range split" (`mov r4, r1`).  That split is the MSL
 * spelling itself: the digit is stored with
 *
 *     result->sig.text[result->sig.length++] = val % 10;
 *
 * i.e. the post-increment of the length FIELD in the subscript, which keeps
 * the old length live across the _ull_mod call as its own value.  With that
 * one line the whole divmod loop is byte-exact.  The remaining residue (the
 * in-place reversal) closed on two points: `end` derived from `start`
 * (`start + length - 1`, not `text + length - 1`), and the swap written as
 * four separate statements with the pointer steps last
 * (`temp = *start; *start = *end; *end = temp; start++; end--;`) -- the
 * post-increment forms put start/end in each other's registers.  No zero
 * special case: a zero value leaves length 0 and exponent -1, as the image
 * does.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__ull2dec.c \
 *       --func __ull2dec --addr 0x020966B0 --cc 1.1p1 --arm
 *   EXACT, 196 bytes, 2 relocation sites, all resolved.
 */
void __ull2dec(decimal2 *result, u64 val)
{
    result->sign = 0;
    result->sig.length = 0;

    for (; val != 0; val /= 10)
        result->sig.text[result->sig.length++] = val % 10;

    {
        u8 *dec_start = result->sig.text;
        u8 *end = dec_start + result->sig.length - 1;

        while (dec_start < end) {
            u8 temp = *dec_start;
            *dec_start = *end;
            *end = temp;
            dec_start++;
            end--;
        }
    }

    result->exp = result->sig.length - 1;
}

/*
 * MSL __timesdec (ansi_fp.c): decimal * decimal -> decimal.  The Metrowerks
 * source verbatim: a 64-byte mantissa scratch filled backward from
 * `ip = mantissa + i + 1`, one column of `accumulator += *jp * *kp` per
 * output digit with the (j, k, l, t) window clamp, `% 10` / `/ 10` on an
 * unsigned long accumulator, exponents added as shorts, the leading carry
 * digit, a copy-out bounded at 32, and the round-half-even tail with its
 * `goto round` into __round_up (MSL_C_LIB_IncrementDigits).  Earlier lanes' hand bodies
 * sat at a one-register rotation of the callee-saved set; the original
 * declarations (in particular `ep = ip` as its own local and the per-column
 * block-scoped j/k/l/t) are what fix the allocation.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__timesdec.c \
 *       --func __timesdec --addr 0x02096774 --cc 1.1p1 --arm
 *   EXACT, 384 bytes, 1 relocation site, resolved.
 */
void __timesdec(decimal2 *result, const decimal2 *x, const decimal2 *y)
{
    unsigned long accumulator = 0;
    u8 mantissa[64];
    int i = x->sig.length + y->sig.length - 1;
    u8 *ip = mantissa + i + 1;
    u8 *ep = ip;

    result->sign = 0;

    for (; i > 0; i--) {
        int k = y->sig.length - 1;
        int j = i - k - 1;
        int l;
        int t;
        const u8 *jp;
        const u8 *kp;

        if (j < 0) {
            j = 0;
            k = i - 1;
        }

        jp = x->sig.text + j;
        kp = y->sig.text + k;
        l = k + 1;
        t = x->sig.length - j;

        if (l > t)
            l = t;

        for (; l > 0; l--, jp++, kp--)
            accumulator += *jp * *kp;

        *--ip = (u8)(accumulator % 10);
        accumulator /= 10;
    }

    result->exp = (s16)(x->exp + y->exp);

    if (accumulator > 0) {
        *--ip = (u8)accumulator;
        result->exp++;
    }

    for (i = 0; i < 32 && ip < ep; i++, ip++)
        result->sig.text[i] = *ip;

    result->sig.length = (u8)i;

    if (ip < ep && *ip >= 5) {
        if (*ip == 5) {
            u8 *jp = ip + 1;
            for (; jp < ep; jp++) {
                if (*jp != 0)
                    goto round;
            }
            if ((*(ip - 1) & 1) == 0)
                return;
        }
    round:
        MSL_C_LIB_IncrementDigits((u8 *)result, result->sig.length);
    }
}

/*
 * Decimal string to the packed digit record the bcd family shares: clear the
 * flag byte, store the caller's halfword parameter at +2, convert up to 32
 * digits into the byte array at +5, then decide whether the value is in range.
 * A string whose first unconsumed character is below '5' is accepted as is,
 * above '5' is rejected through MSL_C_LIB_IncrementDigits, and exactly '5' is accepted
 * only when some later digit is non-zero or the last converted digit is odd.
 *
 * The pointer is unsigned throughout: `const char *` gives `ldrsb` and signed
 * `poplt`/`ble` comparisons where the original has `ldrb` and the unsigned
 * `poplo`/`bhi`.
 *
 * Two spellings are pinned:
 *
 *  - all three rejection paths jump to one `tail` label, so the file has a
 *    single `bl 02096620`; writing the call out in each arm leaves three
 *    copies and 56 bytes of diff.
 *  - the trailing-zero scan is entered with `c = s[1]; s++;`, which is what
 *    the original's two-instruction entry (`ldrb r2, [r1, #1]` then `add r1,
 *    r1, #1`) is: the load is formed against the not-yet-incremented pointer
 *    and the increment follows.  The equivalent `s++; c = *s;` compiles to
 *    `add r1, r1, #1; ldrb r2, [r1]` - same length, same value, different
 *    order - and every later branch then targets an address four bytes off.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__str2dec.c \
 *       --func __str2dec --addr 0x020968F4 --cc 1.1p1 --arm
 *   EXACT, 156 bytes, 1 relocation site, resolved.
 */
void __str2dec(struct MslDecString *dec, const u8 *s, u16 exponent)
{
    int i;
    u8 c;

    dec->exp = exponent;
    dec->sign = 0;
    i = 0;
    while (i < 32 && *s != 0) {
        dec->digits[i] = (u8)(*s++ - '0');
        i++;
    }
    dec->length = (u8)i;
    if (*s == 0)
        return;
    if (*s < 5)
        return;
    if (*s > 5)
        goto tail;
    c = s[1];
    s++;
    while (c != 0) {
        if (c != '0')
            goto tail;
        c = *++s;
    }
last:
    if ((dec->digits[i - 1] & 1) == 0)
        return;
tail:
    MSL_C_LIB_IncrementDigits((u8 *)dec, dec->length);
}

/*
 * MSL __two_exp (ansi_fp.c): 2^exp as a decimal record.  A switch over the
 * tabulated exponents -64, -53, -32, -16 and -8..8, each arm handing a digit
 * string and a decimal exponent to __str2dec (__str2dec); every other
 * exponent recurses on exp/2 (spelled the MSL way,
 * `((long)((0x80000000UL & exp) >> 31) + exp) >> 1`), squares the half with
 * __timesdec (__timesdec), and on an odd exponent copies the result to a
 * stack temporary and multiplies by "2" (exp > 0) or "5"e-1.  `decimal x2,
 * temp;` in that order puts temp at sp+0 and x2 at sp+0x26.
 *
 * Earlier notes (docs/notes/pkt_02096990.c.txt) held this out of scope for
 * lack of witnesses on the 21 digit strings; under the widened sole-ref
 * class every one resolves (`string` or `sole-ref`), so the body is EXACT.
 * The strings are declared by address because they sit in the packed MSL
 * rodata area and mwcc would otherwise emit its own copies.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__two_exp.c \
 *       --func __two_exp --addr 0x02096990 --cc 1.1p1 --arm
 *   EXACT, 896 bytes, 46 relocation sites, all resolved.
 */
void __two_exp(decimal2 *result, long exp)
{
    switch (exp) {
    case -64:
        ((DecFromStr)__str2dec)(result, s_020A8ABC, -20);
        return;
    case -53:
        ((DecFromStr)__str2dec)(result, s_020A8AEC, -16);
        return;
    case -32:
        ((DecFromStr)__str2dec)(result, s_020A8B14, -10);
        return;
    case -16:
        ((DecFromStr)__str2dec)(result, s_020A8B2C, -5);
        return;
    case -8:
        ((DecFromStr)__str2dec)(result, s_020A8B3C, -3);
        return;
    case -7:
        ((DecFromStr)__str2dec)(result, s_020A8B44, -3);
        return;
    case -6:
        ((DecFromStr)__str2dec)(result, s_020A8B4C, -2);
        return;
    case -5:
        ((DecFromStr)__str2dec)(result, s_020A8B54, -2);
        return;
    case -4:
        ((DecFromStr)__str2dec)(result, s_020A8B5C, -2);
        return;
    case -3:
        ((DecFromStr)__str2dec)(result, s_020A8B60, -1);
        return;
    case -2:
        ((DecFromStr)__str2dec)(result, s_020A8B64, -1);
        return;
    case -1:
        ((DecFromStr)__str2dec)(result, s_020A8B68, -1);
        return;
    case 0:
        ((DecFromStr)__str2dec)(result, s_020A8B6C, 0);
        return;
    case 1:
        ((DecFromStr)__str2dec)(result, s_020A8B70, 0);
        return;
    case 2:
        ((DecFromStr)__str2dec)(result, s_020A8B74, 0);
        return;
    case 3:
        ((DecFromStr)__str2dec)(result, s_020A8B78, 0);
        return;
    case 4:
        ((DecFromStr)__str2dec)(result, s_020A8B7C, 1);
        return;
    case 5:
        ((DecFromStr)__str2dec)(result, s_020A8B80, 1);
        return;
    case 6:
        ((DecFromStr)__str2dec)(result, s_020A8B84, 1);
        return;
    case 7:
        ((DecFromStr)__str2dec)(result, s_020A8B88, 2);
        return;
    case 8:
        ((DecFromStr)__str2dec)(result, s_020A8B8C, 2);
        return;
    }

    {
        decimal2 x2, temp;

        __two_exp(&x2, ((long)((0x80000000UL & exp) >> 31) + exp) >> 1);
        __timesdec(result, &x2, &x2);
        if (exp & 1) {
            temp = *result;
            if (exp > 0)
                ((DecFromStr)__str2dec)(&x2, s_020A8B70, 0);
            else
                ((DecFromStr)__str2dec)(&x2, s_020A8B68, -1);
            __timesdec(result, &temp, &x2);
        }
    }
}

/*
 * String comparison over the length-prefixed string object used by the
 * 0x02096D10 family: byte +5 is a terminator flag, +2 is an s16 key, +4 is
 * the byte length and +5.. is the payload.  Two flag/length guards, a key
 * comparison, then a byte compare over the shorter of the two payloads; when
 * the compared prefix is exactly a's payload the tail of b is checked for a
 * terminator instead, and vice versa.  Returns 1 when the two are equivalent.
 *
 * Three measured levers (all needed, each costs a whole-function diff):
 *   - `volatile u8 f04`.  The second loop re-reads the length out of the
 *     object on every iteration (`ldrb r1, [r0, #4]` after the payload test)
 *     instead of hoisting it; a plain field lets mwcc hoist it and the loop
 *     comes out one instruction short.
 *   - the bound is an `int` copy: `la`/`lb` are locals, so `if (la > lb)`
 *     compares two sign-unknown ints and mwcc emits `movgt`.  Comparing the
 *     u8 fields directly tells mwcc both are 0..255 and it uses `movhi`
 *     instead, which is four bytes that differ.
 *   - `p = a; if (n == la) p = b;`.  As a ternary mwcc keeps the result in
 *     b's register (r1); the two-statement form lets it coalesce p with `a`
 *     and the whole tail allocates as the original does.
 */
int __equals_dec(MslStrRec *a, MslStrRec *b)
{
    MslStrRec *p;
    int i, n;
    int la, lb;

    if (a->data[0] == 0)
        return b->data[0] == 0;
    if (b->data[0] == 0)
        return a->data[0] == 0;
    if (a->key != b->key)
        goto fail;
    i = 0;
    la = a->length;
    lb = b->length;
    n = la;
    if (la > lb)
        n = lb;
    for (; i < n; i++) {
        if (a->data[i] != b->data[i])
            return 0;
    }
    p = a;
    if (n == la)
        p = b;
    for (; i < p->length; i++) {
        if (p->data[i] != 0)
            return 0;
    }
    return 1;
fail:
    return 0;
}

/*
 * The ordering sibling of __equals_dec: same length-prefixed string object
 * (byte +5 terminator flag, s16 key at +2, byte length at +4, payload from +5)
 * but it returns 1 when a sorts before b and 0 otherwise, so the payload loop
 * is a two-sided compare instead of a single inequality.  When the common
 * prefix is exactly a's payload, b's tail must hold terminators only, and a
 * non-terminator there means a is a proper prefix and sorts first (return 1);
 * the s16 keys break the tie when they differ.
 *
 * Levers, all measured:
 *   - `volatile u8 f04` again: the tail loop re-reads b's length every
 *     iteration (`ldrb r0, [r1, #4]` under the payload test) rather than
 *     hoisting it, so a plain field comes out four bytes short.
 *   - the tail is a do/while guarded by the second `&&`: `if (n == la && i <
 *     lb) { do {...} while (i < b->length); }`.  The entry test compares against
 *     the cached lb (r4) while the back edge re-reads b->length, which is what
 *     distinguishes this shape from `for (; i < lb; i++)` (whose back edge
 *     would use the cached value and lose the volatile read).
 *   - `if (a->key != b->key) goto keycmp; ... keycmp: return a->key < b->key;`
 *     -- the s16 tie-break sits out of line after the final `return 0`, as a
 *     single `if (...) return ...;` the front end if-converts it inline and
 *     the whole tail shifts.
 *   - `int lb, la;`: declaration order decides which of the two lengths gets
 *     r4 and which r5; the `la, lb` order swaps them and costs seven bytes.
 */
int __less_dec(MslStrRec *a, MslStrRec *b)
{
    int i, n;
    int lb, la;

    if (a->data[0] == 0)
        return b->data[0] != 0;
    if (b->data[0] == 0)
        return 0;
    if (a->key != b->key)
        goto keycmp;
    i = 0;
    la = a->length;
    lb = b->length;
    n = la;
    if (la > lb)
        n = lb;
    for (; i < n; i++) {
        if (a->data[i] < b->data[i])
            return 1;
        if (b->data[i] < a->data[i])
            return 0;
    }
    if (n == la && i < lb) {
        do {
            if (b->data[i] != 0)
                return 1;
            i++;
        } while (i < b->length);
    }
    return 0;
keycmp:
    return a->key < b->key;
}

/*
 * MSL __minus_dec (ansi_fp.c): z = x - y on decimal records, with rounding
 * of the digits of y that fall past z's precision.  Three lanes left a hand
 * body at 95 concrete bytes out with the size exact (an allocator tie between
 * the text base and the y->sig.length temporary, docs/notes/pkt_02096ED0.c.txt).
 * The Metrowerks source closes it outright: the declarations
 * `int zlen, dexp; u8 *ib, *i, *ie; const u8 *jb, *j, *jn;`, the borrow loops
 * written `while (*k == 0) --k; while (k != i) { --*k; *++k += 10; }`, the
 * round-down flag with `goto done` out of the trailing-zero scan, and the
 * `u8 dl` narrowing (the image's `and r5, r4, #0xff`) on the leading-zero
 * shift.  Argument order is (dest, minuend, subtrahend): the 38-byte opening
 * copy is `*z = *x`.  No relocations.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__minus_dec.c \
 *       --func __minus_dec --addr 0x02096ED0 --cc 1.1p1 --arm
 *   EXACT, 672 bytes, 0 relocation sites.
 */
void __minus_dec(decimal2 *z, const decimal2 *x, const decimal2 *y)
{
    int zlen, dexp;
    u8 *ib, *i, *ie;
    const u8 *jb, *j, *jn;

    *z = *x;

    if (y->sig.text[0] == 0)
        return;

    zlen = z->sig.length;
    if (zlen < y->sig.length)
        zlen = y->sig.length;

    dexp = z->exp - y->exp;
    zlen += dexp;

    if (zlen > 32)
        zlen = 32;

    while (z->sig.length < zlen)
        z->sig.text[z->sig.length++] = 0;

    ib = z->sig.text;
    i = ib + zlen;

    if (y->sig.length + dexp < zlen)
        i = ib + (y->sig.length + dexp);

    jb = y->sig.text;
    j = jb + (i - ib - dexp);
    jn = j;

    while (i > ib && j > jb) {
        --i;
        --j;
        if (*i < *j) {
            u8 *k = i - 1;
            while (*k == 0)
                --k;
            while (k != i) {
                --*k;
                *++k += 10;
            }
        }
        *i -= *j;
    }

    if (jn - jb < y->sig.length) {
        int round_down = 0;
        if (*jn < 5)
            round_down = 1;
        else if (*jn == 5) {
            const u8 *je = y->sig.text + y->sig.length;

            for (j = jn + 1; j < je; ++j)
                if (*j != 0)
                    goto done;

            i = ib + (jn - jb) + dexp - 1;

            if (*i & 1)
                round_down = 1;
        }
        if (round_down) {
            if (*i < 1) {
                u8 *k = i - 1;

                while (*k == 0)
                    --k;
                while (k != i) {
                    --*k;
                    *++k += 10;
                }
            }

            *i -= 1;
        }
    }
done:
    for (i = ib; *i == 0; ++i) {
    }

    if (i > ib) {
        u8 dl = (u8)(i - ib);
        z->exp -= dl;
        ie = ib + z->sig.length;
        for (; i < ie; ++i, ++ib)
            *ib = *i;
        z->sig.length -= dl;
    }

    ib = z->sig.text;

    for (i = ib + z->sig.length; i > ib;) {
        --i;
        if (*i != 0)
            break;
    }

    z->sig.length = (u8)(i - ib + 1);
}

/*
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
 * explicit `extern int _deq(double, double)` whose result is tested
 * costs an extra `cmp r0, #0`.  `_deq` is the name mwcc emits, so it is what
 * the symbols: block has to pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__num2dec.c \
 *       --func __num2dec --addr 0x02097170 --cc 1.1p1 --arm
 *   EXACT, 384 bytes, 12 of 12 relocation sites resolved.
 */
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
        r->sign = neg;
        r->exp = 0;
        r->length = 1;
        r->digits[0] = 0;
        return;
    }
    if (__fpclassifyd(x) <= 2) {
        r->sign = neg;
        r->exp = 0;
        r->length = 1;
        r->digits[0] = (__fpclassifyd(x) == 1) ? 0x4E : 0x49;
        return;
    }
    if (neg)
        x = _dsub(0.0, x);
    f = frexp(x, &e);
    g = f;
    v = *(u64 *)&g | 0x0010000000000000ULL;
    k = 0x35 - MSL_C_LIB_PopCount64((v & -v) - 1);
    __two_exp((struct decimal2 *)(&b), e - k);
    __ull2dec((struct decimal2 *)(&a), (u64)ldexp(f, k));
    __timesdec((struct decimal2 *)r, (const struct decimal2 *)(&a), (const struct decimal2 *)(&b));
    r->sign = neg;
}

void __dtoa(const decform *f, double x, decimal *p)
{
    int n = f->digits;
    int i;

    __num2dec((DB *)p, x);
    if (p->sig.text[0] > 9)
        return;
    if (n > 0x20)
        n = 0x20;
    MSL_C_LIB_SetPrecision((DB *)p, n);
    while (p->sig.length < n)
        p->sig.text[p->sig.length++] = 0;
    p->exp -= (s16)(p->sig.length - 1);
    for (i = 0; i < p->sig.length; i++)
        p->sig.text[i] += 0x30;
}

/*
 * MSL ansi_fp.c __dec2num (decimal record -> double), written fresh in the
 * MSL layout (wave 18).  Callees: copysign 0x0209A368, __str2dec 0x020968F4,
 * __less_dec 0x02096DF0, __equals_dec 0x02096D10, __minus_dec 0x02096ED0,
 * __num2dec_internal 0x02097170, pow 0x0209AB80, ldexp 0x0209A7A8,
 * __fpclassifyd 0x020921F4.  EXACT under dsi/1.1p1 and dsi/1.2 alike.
 *
 * The refinement loop tests is_low directly (`if (is_low) { ++; isinf exit }
 * else --`); there is no is_high variable.  The image's `mov r7, #1 /
 * movne r7, #0` before the loop is the compiler's negated if-condition
 * (!is_low), hoisted as a loop invariant.  An explicit is_high = !is_low with
 * `if (!is_high)` gives the same loop body but makes 1.1p1 hoist &x64, &dec
 * and the `& 1` mask's zero to +0x2A0 instead of the loop preheader +0x3A4
 * (the 718-721 byte wall of waves 9 to 17).  is_low is initialised to 0 at
 * its declaration and set by `if (__less_dec(...)) is_low = 1`; ll points at
 * guess from its declaration.
 */
double __dec2num(const decimal2 *d)
{
    if (d->sig.length <= 0)
        return copysign(0.0, d->sign == 0 ? 1.0 : -1.0);

    switch (d->sig.text[0]) {
    case '0':
        return copysign(0.0, d->sign == 0 ? 1.0 : -1.0);
    case 'I':
        return copysign((double)__float_huge, d->sign == 0 ? 1.0 : -1.0);
    case 'N':
        {
            double result;
            unsigned long long *ll = (unsigned long long *)&result;

            *ll = 0x7FF0000000000000ULL;
            if (d->sign)
                *ll |= 0x8000000000000000ULL;
            *ll |= 0x0008000000000000ULL;
            return result;
        }
    }

    {
        decimal2 dec = *d;
        unsigned char *i = dec.sig.text;
        unsigned char *e = i + dec.sig.length;
        double first_guess;
        int exponent;

        for (; i < e; ++i)
            *i -= '0';
        dec.exp += dec.sig.length - 1;
        exponent = dec.exp;

        {
            decimal2 max;

            __str2dec((struct MslDecString *)(&max), (const u8 *)s_020A8B90, 308);
            if (__less_dec((MslStrRec *)&max, (MslStrRec *)&dec))
                return copysign((double)__float_huge, d->sign == 0 ? 1.0 : -1.0);
        }

        i = dec.sig.text;
        first_guess = *i++;

        while (i < e) {
            unsigned long ival = 0;
            int j;
            double temp1, temp2;
            int ndig = (int)(e - i) % 8;

            if (ndig == 0)
                ndig = 8;
            for (j = 0; j < ndig; ++j, ++i)
                ival = ival * 10 + *i;
            temp1 = first_guess * sMslAnsiFpPow10[ndig - 1];
            temp2 = temp1 + ival;
            if (ival != 0 && temp1 == temp2)
                break;
            first_guess = temp2;
            exponent -= ndig;
        }

        if (exponent < 0)
            first_guess /= pow(5.0, -exponent);
        else
            first_guess *= pow(5.0, exponent);

        first_guess = ldexp(first_guess, exponent);
        if (isinf(first_guess))
            *(unsigned long long *)&first_guess = 0x7FEFFFFFFFFFFFFFULL;

        {
            decimal2 feval, feval2;
            decimal2 difflow, diffhigh;
            double guess;
            unsigned long long *ll = (unsigned long long *)&guess;
            int is_low = 0;

            __num2dec((DB *)&feval, first_guess);
            if (__equals_dec((MslStrRec *)&feval, (MslStrRec *)&dec))
                goto done;
            if (__less_dec((MslStrRec *)&feval, (MslStrRec *)&dec))
                is_low = 1;
            guess = first_guess;
            for (;;) {
                if (is_low) {
                    ++*ll;
                    if (isinf(guess))
                        goto done;
                } else
                    --*ll;
                __num2dec((DB *)&feval2, guess);
                if (is_low && !__less_dec((MslStrRec *)&feval2, (MslStrRec *)&dec))
                    break;
                if (!is_low && !__less_dec((MslStrRec *)&dec, (MslStrRec *)&feval2)) {
                    double tg;

                    difflow = feval;
                    feval = feval2;
                    feval2 = difflow;
                    tg = first_guess;
                    first_guess = guess;
                    guess = tg;
                    break;
                }
                feval = feval2;
                first_guess = guess;
            }
            __minus_dec(&difflow, &dec, &feval);
            __minus_dec(&diffhigh, &feval2, &dec);
            if (__equals_dec((MslStrRec *)&difflow, (MslStrRec *)&diffhigh)) {
                if (*(unsigned long long *)&first_guess & 1)
                    first_guess = guess;
            } else if (!__less_dec((MslStrRec *)&difflow, (MslStrRec *)&diffhigh))
                first_guess = guess;
        }
done:
        if (dec.sign)
            first_guess = -first_guess;
        return first_guess;
    }
}
