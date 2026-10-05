/*
 * function: func_02092F0C
 * address:  0x02092F0C
 * packet:   pkt_020929E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note:     MSL printf.c `double2hex`, the `%a`/`%A` formatter.  REAL
 *           entry: 0x02092F0C is the home-area push {r0,r1,r2,r3}; the
 *           listing label sits four bytes late at 0x02092F10 (the trailing
 *           star is that 4-byte listing extent, the body is 1196 bytes with
 *           its pool).  Wants a seed at 0x02092F0C and the 0x02092F10 label
 *           removed.  Callees: func_020972F0 = __num2dec, func_020929E8 =
 *           long2str (for the binary exponent), func_0209A504 = fabs,
 *           0x0209BAC8 = the runtime double `!=` (__dcmp_6 in
 *           layout/runtime_arm9.txt).
 *           The inf/nan spellings are MSL's `strcpy(p, "-INF")` etc.; the
 *           image copies them with mwcc's `__memcpy` intrinsic, paired
 *           ldrb/strb with the source in r3.  Written as __memcpy from a
 *           NON-const `char[N]` extern (a C string literal's own type): a
 *           struct copy, or __memcpy from a `const char[]`, reorders the
 *           loads and moves the source to r1.  The byte-swap loop walks a
 *           named pointer `b` to num (the permuter's lever: without it the
 *           index and base registers trade places).
 *
 * symbols:
 *   func_020929E8  0x020929E8  arm
 *   func_020972F0  0x020972F0  arm
 *   func_0209A504  0x0209A504  arm
 *   _dneq          0x0209BAC8  arm
 *   s_020A8A40     0x020A8A40  data  a1
 *   s_020A8A48     0x020A8A48  data  a1
 *   s_020A8A50     0x020A8A50  data  a1
 *   s_020A8A54     0x020A8A54  data  a1
 *   s_020A8A58     0x020A8A58  data  a1
 *   s_020A8A60     0x020A8A60  data  a1
 *   s_020A8A68     0x020A8A68  data  a1
 *   s_020A8A6C     0x020A8A6C  data  a1
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

extern unsigned char *func_020929E8(long num, unsigned char *buff, print_format format);
extern void func_020972F0(const decform *f, double x, decimal *d);
extern double func_0209A504(double x);
extern char s_020A8A40[5]; /* "-INF" */
extern char s_020A8A48[5]; /* "-inf" */
extern char s_020A8A50[4]; /* "INF"  */
extern char s_020A8A54[4]; /* "inf"  */
extern char s_020A8A58[5]; /* "-NAN" */
extern char s_020A8A60[5]; /* "-nan" */
extern char s_020A8A68[4]; /* "NAN"  */
extern char s_020A8A6C[4]; /* "nan"  */

unsigned char *func_02092F0C(double num, unsigned char *buff, print_format format)
{
    unsigned char *p;
    unsigned char *q;
    unsigned char working_byte;
    double ld;
    long exp;
    print_format exp_format;
    int hex_precision;
    int mantissa_bit;
    unsigned long snum;
    decform form;
    decimal dec;
    int i;
    unsigned char *b;

    p = buff;
    ld = num;

    if (format.precision > 509)
        return 0;

    form.style = 0;
    form.digits = 0x20;
    func_020972F0(&form, num, &dec);

    switch (dec.sig.text[0]) {
    case '0':
        dec.exp = 0;
        break;
    case 'I':
        if (dec.sgn) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                __memcpy(p, s_020A8A40, 5);
            else
                __memcpy(p, s_020A8A48, 5);
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                __memcpy(p, s_020A8A50, 4);
            else
                __memcpy(p, s_020A8A54, 4);
        }
        return p;
    case 'N':
        if (dec.sgn) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                __memcpy(p, s_020A8A58, 5);
            else
                __memcpy(p, s_020A8A60, 5);
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                __memcpy(p, s_020A8A68, 4);
            else
                __memcpy(p, s_020A8A6C, 4);
        }
        return p;
    }

    exp_format.justification_options = 1;
    exp_format.sign_options = 1;
    exp_format.precision_specified = 0;
    exp_format.alternate_form = 0;
    exp_format.argument_options = 0;
    exp_format.field_width = 0;
    exp_format.precision = 1;
    exp_format.conversion_char = 'd';

    b = (unsigned char *)&num;
    for (i = 0; i < 4; i++) {
        unsigned char t = b[i];
        b[i] = b[7 - i];
        b[7 - i] = t;
    }

    snum = ((unsigned char *)&num)[0] << 25;
    snum |= ((unsigned char *)&num)[1] << 17;
    snum = (snum >> 21) & 0x7FF;
    if (snum)
        exp = snum - 0x3FF;
    else
        exp = 0;

    p = func_020929E8(exp, buff, exp_format);
    if (format.conversion_char == 'a')
        *--p = 'p';
    else
        *--p = 'P';

    q = (unsigned char *)&num;
    for (hex_precision = format.precision, mantissa_bit = hex_precision * 4 + 11;
         hex_precision >= 1; --hex_precision, mantissa_bit -= 4) {
        if (mantissa_bit < 64) {
            working_byte = q[mantissa_bit >> 3] >> (7 - (mantissa_bit & 7));
            if ((mantissa_bit & ~7) != ((mantissa_bit - 4) & ~7))
                working_byte |= ((q[(mantissa_bit >> 3) - 1] << 8) >> (7 - (mantissa_bit & 7)));
            working_byte &= 0x0f;
            if (working_byte < 10)
                working_byte += '0';
            else if (format.conversion_char == 'a')
                working_byte += 'a' - 10;
            else
                working_byte += 'A' - 10;
        } else
            working_byte = '0';
        *--p = working_byte;
    }

    if (format.precision || format.alternate_form)
        *--p = '.';

    if (func_0209A504(ld) != 0.0)
        *--p = '1';
    else
        *--p = '0';

    if (format.conversion_char == 'a')
        *--p = 'x';
    else
        *--p = 'X';
    *--p = '0';

    if (dec.sgn)
        *--p = '-';
    else if (format.sign_options == 1)
        *--p = '+';
    else if (format.sign_options == 2)
        *--p = ' ';

    return p;
}
