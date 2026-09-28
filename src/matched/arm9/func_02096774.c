/*
 * function: func_02096774
 * address:  0x02096774
 * packet:   pkt_020949F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL __timesdec (ansi_fp.c): decimal * decimal -> decimal.  The Metrowerks
 * source verbatim: a 64-byte mantissa scratch filled backward from
 * `ip = mantissa + i + 1`, one column of `accumulator += *jp * *kp` per
 * output digit with the (j, k, l, t) window clamp, `% 10` / `/ 10` on an
 * unsigned long accumulator, exponents added as shorts, the leading carry
 * digit, a copy-out bounded at 32, and the round-half-even tail with its
 * `goto round` into __round_up (func_02096620).  Earlier lanes' hand bodies
 * sat at a one-register rotation of the callee-saved set; the original
 * declarations (in particular `ep = ip` as its own local and the per-column
 * block-scoped j/k/l/t) are what fix the allocation.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02096774.c \
 *       --func func_02096774 --addr 0x02096774 --cc 1.1p1 --arm
 *   EXACT, 384 bytes, 1 relocation site, resolved.
 *
 * symbols:
 *   func_02096620  0x02096620  arm
 */
typedef unsigned char u8;
typedef signed short s16;

typedef struct decimal {
    char sign;
    char unused;
    s16 exp;
    struct {
        u8 length;
        u8 text[32];
        u8 unused;
    } sig;
} decimal;

extern void func_02096620(decimal *d, int digits);

void func_02096774(decimal *result, const decimal *x, const decimal *y)
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
        func_02096620(result, result->sig.length);
    }
}
