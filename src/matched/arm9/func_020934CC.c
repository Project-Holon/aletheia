/*
 * function: float2str
 * address:  0x020934CC
 * packet:   pkt_020929E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note:     MSL printf.c `float2str`, the %e/%f/%g formatter.  REAL entry:
 *           0x020934CC is the home-area push {r0,r1,r2,r3}; the listing
 *           label sits four bytes late at 0x020934D0.  Wants a seed at
 *           0x020934CC and the 0x020934D0 label removed.  Callees:
 *           __dtoa = __num2dec, round_decimal = round_decimal,
 *           0x0209B9A0 = the runtime double `<` (__dcmp_4).  isupper() is
 *           an INLINE FUNCTION over __ctype_map, not a macro: as a macro
 *           its 0 arm is CSE'd with the 0.0 argument of `num < 0` and kept
 *           in r4 across the call (8 bytes short).  The inf/nan strcpy's
 *           are mwcc's __memcpy intrinsic from non-const char[N] externs
 *           (see double2hex.c).  radix_marker is the constant '.'.
 *
 * symbols:
 *   round_decimal  0x020933B8  arm
 *   __dtoa  0x020972F0  arm
 *   _dls           0x0209B9A0  arm
 *   __ctype_map    0x020A61DC  data  a2
 *   sMslNegInf     0x020A8A40  data  a1
 *   sMslNegInfLower     0x020A8A48  data  a1
 *   sMslPosInf     0x020A8A50  data  a1
 *   sMslPosInfLower     0x020A8A54  data  a1
 *   sMslNegNan     0x020A8A58  data  a1
 *   sMslNegNanLower     0x020A8A60  data  a1
 *   sMslPosNan     0x020A8A68  data  a1
 *   sMslPosNanLower     0x020A8A6C  data  a1
 */
typedef struct {
    unsigned char justification_options;
    unsigned char sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} print_format;

typedef struct { char style; short digits; } decform;
typedef struct {
    unsigned char sgn;
    char unused;
    short exp;
    struct { unsigned char length; unsigned char text[34]; unsigned char unused; } sig;
} decimal;

typedef struct { char c[5]; } Str5;
typedef struct { char c[4]; } Str4;
extern char sMslNegInf[5]; /* "-INF" */
extern char sMslNegInfLower[5]; /* "-inf" */
extern char sMslPosInf[4]; /* "INF"  */
extern char sMslPosInfLower[4]; /* "inf"  */
extern char sMslNegNan[5]; /* "-NAN" */
extern char sMslNegNanLower[5]; /* "-nan" */
extern char sMslPosNan[4]; /* "NAN"  */
extern char sMslPosNanLower[4]; /* "nan"  */

extern const unsigned short __ctype_map[];
static inline int isupper(int c) { return ((c < 0 || c >= 0x80) ? 0 : (__ctype_map[c] & 0x200)); }

extern void __dtoa(const decform *f, double x, decimal *d);
extern void round_decimal(decimal *d, int digits);

unsigned char *float2str(double num, unsigned char *buff, print_format format)
{
    decimal dec;
    decform form;
    unsigned char *p;
    unsigned char *q;
    int n, digits, sign;
    int int_digits, frac_digits;

    if (format.precision > 509)
        return 0;

    form.style = 0;
    form.digits = 0x20;
    __dtoa(&form, num, &dec);

    p = dec.sig.text + dec.sig.length;
    while (dec.sig.length > 1 && *--p == '0') {
        --dec.sig.length;
        ++dec.exp;
    }

    switch (dec.sig.text[0]) {
    case '0':
        dec.exp = 0;
        break;
    case 'I':
        if (num < 0) {
            p = buff - 5;
            if (isupper(format.conversion_char))
                __memcpy(p, sMslNegInf, 5);
            else
                __memcpy(p, sMslNegInfLower, 5);
        } else {
            p = buff - 4;
            if (isupper(format.conversion_char))
                __memcpy(p, sMslPosInf, 4);
            else
                __memcpy(p, sMslPosInfLower, 4);
        }
        return p;
    case 'N':
        if (dec.sgn) {
            p = buff - 5;
            if (isupper(format.conversion_char))
                __memcpy(p, sMslNegNan, 5);
            else
                __memcpy(p, sMslNegNanLower, 5);
        } else {
            p = buff - 4;
            if (isupper(format.conversion_char))
                __memcpy(p, sMslPosNan, 4);
            else
                __memcpy(p, sMslPosNanLower, 4);
        }
        return p;
    }

    dec.exp += dec.sig.length - 1;

    p = buff;
    *--p = 0;

    switch (format.conversion_char) {
    case 'g':
    case 'G':
        if (dec.sig.length > format.precision)
            round_decimal(&dec, format.precision);

        if (dec.exp < -4 || dec.exp >= format.precision) {
            if (format.alternate_form)
                --format.precision;
            else
                format.precision = dec.sig.length - 1;

            if (format.conversion_char == 'g')
                format.conversion_char = 'e';
            else
                format.conversion_char = 'E';

            goto e_format;
        }

        if (format.alternate_form)
            format.precision -= dec.exp + 1;
        else if ((format.precision = dec.sig.length - (dec.exp + 1)) < 0)
            format.precision = 0;

        goto f_format;

    case 'e':
    case 'E':
    e_format:
        if (dec.sig.length > format.precision + 1)
            round_decimal(&dec, format.precision + 1);

        n = dec.exp;
        sign = '+';
        if (n < 0) {
            n = -n;
            sign = '-';
        }

        for (digits = 0; n || digits < 2; ++digits) {
            *--p = n % 10 + '0';
            n /= 10;
        }

        *--p = sign;
        *--p = format.conversion_char;

        if (buff - p + format.precision > 509)
            return 0;

        if (dec.sig.length < format.precision + 1)
            for (n = format.precision + 2 - dec.sig.length; --n;)
                *--p = '0';

        for (n = dec.sig.length, q = dec.sig.text + dec.sig.length; --n;)
            *--p = *--q;

        if (format.precision || format.alternate_form)
            *--p = '.';

        *--p = dec.sig.text[0];

        if (dec.sgn)
            *--p = '-';
        else if (format.sign_options == 1)
            *--p = '+';
        else if (format.sign_options == 2)
            *--p = ' ';
        break;

    case 'f':
    case 'F':
    f_format:
        if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0)
            frac_digits = 0;

        if (frac_digits > format.precision) {
            round_decimal(&dec, dec.sig.length - (frac_digits - format.precision));
            if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0)
                frac_digits = 0;
        }

        if ((int_digits = dec.exp + 1) < 0)
            int_digits = 0;

        if (int_digits + frac_digits > 509)
            return 0;

        q = dec.sig.text + dec.sig.length;

        for (digits = 0; digits < (format.precision - frac_digits); ++digits)
            *--p = '0';

        for (digits = 0; digits < frac_digits && digits < dec.sig.length; ++digits)
            *--p = *--q;

        for (; digits < frac_digits; ++digits)
            *--p = '0';

        if (format.precision || format.alternate_form)
            *--p = '.';

        if (int_digits) {
            for (digits = 0; digits < int_digits - dec.sig.length; ++digits)
                *--p = '0';
            for (; digits < int_digits; ++digits)
                *--p = *--q;
        } else
            *--p = '0';

        if (dec.sgn)
            *--p = '-';
        else if (format.sign_options == 1)
            *--p = '+';
        else if (format.sign_options == 2)
            *--p = ' ';
        break;
    }

    return p;
}
