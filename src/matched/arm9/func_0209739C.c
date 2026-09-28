/*
 * function: func_0209739C
 * address:  0x0209739C
 * packet:   pkt_0209739C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0209A368  0x0209A368  arm
 *   func_020968F4  0x020968F4  arm
 *   func_02096DF0  0x02096DF0  arm
 *   func_02096D10  0x02096D10  arm
 *   func_02096ED0  0x02096ED0  arm
 *   func_02097170  0x02097170  arm
 *   func_0209AB80  0x0209AB80  arm
 *   func_0209A7A8  0x0209A7A8  arm
 *   func_020921F4  0x020921F4  arm
 *   __float_huge   0x020A8814  data
 *   _f2d           0x0209BD38  arm
 *   _dfltu         0x0209B790  arm
 *   _dmul          0x0209B2E8  arm
 *   _dadd          0x0209AC04  arm
 *   _deq           0x0209BA3C  arm
 *   _dflt          0x0209B750  arm
 *   _ddiv          0x0209D1E0  arm
 *   _dsub          0x0209AF34  arm
 *   pow_10         0x020A8A7C  data
 *   s_020A8B90     0x020A8B90  data  a1
 *
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

/* ansi_fp.h */
typedef struct decimal {
    unsigned char sign;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} decimal;

#define FP_INFINITE 2
#define isinf(x) (func_020921F4(x) == FP_INFINITE)

extern float __float_huge;
extern const double pow_10[8];
extern const char s_020A8B90[];     /* "179769313486231580793728714053034151" */

extern double func_0209A368(double x, double y);                        /* copysign */
extern void func_020968F4(decimal *d, const char *s, short exp);        /* __str2dec */
extern int func_02096DF0(const decimal *x, const decimal *y);           /* __less_dec */
extern int func_02096D10(const decimal *x, const decimal *y);           /* __equals_dec */
extern void func_02096ED0(decimal *z, const decimal *x, const decimal *y); /* __minus_dec */
extern void func_02097170(decimal *d, double x);                        /* __num2dec_internal */
extern double func_0209AB80(double x, double y);                        /* pow */
extern double func_0209A7A8(double x, int n);                           /* ldexp */
extern int func_020921F4(double x);                                     /* __fpclassifyd */

double func_0209739C(const decimal *d)
{
    if (d->sig.length <= 0)
        return func_0209A368(0.0, d->sign == 0 ? 1.0 : -1.0);

    switch (d->sig.text[0]) {
    case '0':
        return func_0209A368(0.0, d->sign == 0 ? 1.0 : -1.0);
    case 'I':
        return func_0209A368((double)__float_huge, d->sign == 0 ? 1.0 : -1.0);
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
        decimal dec = *d;
        unsigned char *i = dec.sig.text;
        unsigned char *e = i + dec.sig.length;
        double first_guess;
        int exponent;

        for (; i < e; ++i)
            *i -= '0';
        dec.exp += dec.sig.length - 1;
        exponent = dec.exp;

        {
            decimal max;

            func_020968F4(&max, s_020A8B90, 308);
            if (func_02096DF0(&max, &dec))
                return func_0209A368((double)__float_huge, d->sign == 0 ? 1.0 : -1.0);
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
            temp1 = first_guess * pow_10[ndig - 1];
            temp2 = temp1 + ival;
            if (ival != 0 && temp1 == temp2)
                break;
            first_guess = temp2;
            exponent -= ndig;
        }

        if (exponent < 0)
            first_guess /= func_0209AB80(5.0, -exponent);
        else
            first_guess *= func_0209AB80(5.0, exponent);

        first_guess = func_0209A7A8(first_guess, exponent);
        if (isinf(first_guess))
            *(unsigned long long *)&first_guess = 0x7FEFFFFFFFFFFFFFULL;

        {
            decimal feval, feval2;
            decimal difflow, diffhigh;
            double guess;
            unsigned long long *ll = (unsigned long long *)&guess;
            int is_low = 0;

            func_02097170(&feval, first_guess);
            if (func_02096D10(&feval, &dec))
                goto done;
            if (func_02096DF0(&feval, &dec))
                is_low = 1;
            guess = first_guess;
            for (;;) {
                if (is_low) {
                    ++*ll;
                    if (isinf(guess))
                        goto done;
                } else
                    --*ll;
                func_02097170(&feval2, guess);
                if (is_low && !func_02096DF0(&feval2, &dec))
                    break;
                if (!is_low && !func_02096DF0(&dec, &feval2)) {
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
            func_02096ED0(&difflow, &dec, &feval);
            func_02096ED0(&diffhigh, &feval2, &dec);
            if (func_02096D10(&difflow, &diffhigh)) {
                if (*(unsigned long long *)&first_guess & 1)
                    first_guess = guess;
            } else if (!func_02096DF0(&difflow, &diffhigh))
                first_guess = guess;
        }
done:
        if (dec.sign)
            first_guess = -first_guess;
        return first_guess;
    }
}
