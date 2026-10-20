/*
 * file:     msl_printf.c
 * unit:     yes
 * function: parse_format, long2str, longlong2str, double2hex, round_decimal, float2str, __pformatter, MSL_C_LIB_SprintfWriteProc, vsnprintf, sprintf
 * address:  0x020924DC
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
 *   _ll_udiv  0x0209C00C  arm
 *   _ull_mod  0x0209C018  arm
 *   fabs  0x0209A504  arm
 *   __ctype_map  0x020A61DC  data  a2
 *   sMslNegInf     0x020A8A40  data  a1
 *   sMslNegInfLower     0x020A8A48  data  a1
 *   sMslPosInf     0x020A8A50  data  a1
 *   sMslPosInfLower     0x020A8A54  data  a1
 *   sMslNegNan     0x020A8A58  data  a1
 *   sMslNegNanLower     0x020A8A60  data  a1
 *   sMslPosNan     0x020A8A68  data  a1
 *   sMslPosNanLower     0x020A8A6C  data  a1
 *   sMslWideEmpty     0x020A8A70  data  a2
 *   sMslNarrowEmpty     0x020A8A74  data  a1
 *   MSL_C_LIB_WideToNarrow 0x020922CC arm arm9
 *   memcpy 0x02092344 arm arm9
 *   memchr 0x020923C4 arm arm9
 *   MSL_C_LIB_CallExitHook 0x02094750 arm arm9
 *   strlen 0x0209477C arm arm9
 *   strchr 0x02094A28 arm arm9
 *   __dtoa 0x020972F0 arm arm9
 *   _dls                         0x0209B9A0  arm
 *   _dneq                        0x0209BAC8  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "msl_crt_shared_types.h"
#include "msl_stdio_shared_types.h"
#include "msl_printf_shared_types.h"
extern void *__memcpy(void *dest, const void *src, unsigned long n);

#define __va_size(t) ((sizeof(t) + 3) & ~3)

#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))

typedef unsigned char uchar;

typedef long ptrdiff_t;

typedef long long intmax_t;

typedef struct {
    u8 *buf;
    u32 capacity;
    u32 length;
} MslStringBuf;

typedef uchar *va_list;

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

typedef struct {
    u16 reserved0;
    s16 exp;
    u8  length;
    u8  digits[1];
} Ctr;

#include "msl_fdlibm.h"

#include "msl_stdio.h"

#include "msl_string_mem.h"


const uchar *parse_format(const uchar *format_string, va_list *arg, print_format *format);

unsigned char *long2str(long num, unsigned char *buff, print_format format);

unsigned char *longlong2str(long long num, unsigned char *buff, print_format format);

unsigned char *double2hex(double num, unsigned char *buff, print_format format);

void round_decimal(Ctr *b, int idx);

unsigned char *float2str(double num, unsigned char *buff, print_format format);

int __pformatter(void *(*WriteProc)(void *, const uchar *, size_t), void *WriteProcArg, const uchar *format_str, va_list arg, int is_secure);

u32 MSL_C_LIB_SprintfWriteProc(u8 *sb, const void *src, u32 n);

u32 vsnprintf(u8 *dst, u32 n, const u8 *format, u8 *ap);

u32 sprintf(char *dst, char *fmt, ...);

#include "msl_stdlib.h"

#include "msl_string_str.h"


#include "msl_ansi_fp.h"

extern const unsigned short __ctype_map[];

extern char sMslNegInf[5]; /* "-INF" */

extern char sMslNegInfLower[5]; /* "-inf" */

extern char sMslPosInf[4]; /* "INF"  */

extern char sMslPosInfLower[4]; /* "inf"  */

extern char sMslNegNan[5]; /* "-NAN" */

extern char sMslNegNanLower[5]; /* "-nan" */

extern char sMslPosNan[4]; /* "NAN"  */

extern char sMslPosNanLower[4]; /* "nan"  */

extern wchar_t sMslWideEmpty[];  /* L"" */

extern uchar sMslNarrowEmpty[];     /* ""  */

#define isdigit(c) ((unsigned int)(c) < 0x80 ? (__ctype_map[c] & 8) : 0)

/*
 * note:     MSL printf.c `parse_format`, the conversion-spec scanner that
 *           __pformatter (__pformatter) calls once per '%'.  Written from
 *           the Metrowerks source shape: `int c` and `int flag_found`, the
 *           flag loop as for(;;){flag_found = 1; switch; if (flag_found)
 *           c = *++s; else break;}, the length modifiers as a second switch
 *           with flag_found, `g`/`G` falling through into `e`/`E`, and the
 *           print_format struct copied out whole.  The two levers that
 *           closed it from 12 bytes out: isdigit's range test is UNSIGNED
 *           (`(unsigned int)c < 0x80`, the image's movhs/lsllo pair), and
 *           the length cases are ordered j, t, z (the image's arm bodies
 *           store 6, 8, 7 in that order).  All chars unsigned (ldrb).
 *           Under ../2.0/sp2 the same source is 1392 bytes; no pin.
 */
const uchar *parse_format(const uchar *format_string, va_list *arg, print_format *format)
{
    print_format f;
    const uchar *s = format_string;
    int c;
    int flag_found;

    f.justification_options = 1;
    f.sign_options = 0;
    f.precision_specified = 0;
    f.alternate_form = 0;
    f.argument_options = 0;
    f.field_width = 0;
    f.precision = 0;

    if ((c = *++s) == '%') {
        f.conversion_char = c;
        *format = f;
        return s + 1;
    }

    for (;;) {
        flag_found = 1;
        switch (c) {
        case '-':
            f.justification_options = 0;
            break;
        case '+':
            f.sign_options = 1;
            break;
        case ' ':
            if (f.sign_options != 1)
                f.sign_options = 2;
            break;
        case '#':
            f.alternate_form = 1;
            break;
        case '0':
            if (f.justification_options != 0)
                f.justification_options = 2;
            break;
        default:
            flag_found = 0;
        }
        if (flag_found)
            c = *++s;
        else
            break;
    }

    if (c == '*') {
        if ((f.field_width = va_arg(*arg, int)) < 0) {
            f.justification_options = 0;
            f.field_width = -f.field_width;
        }
        c = *++s;
    } else {
        while (isdigit(c)) {
            f.field_width = (f.field_width * 10) + (c - '0');
            c = *++s;
        }
    }

    if (f.field_width > 509) {
        f.conversion_char = 0xFF;
        *format = f;
        return s + 1;
    }

    if (c == '.') {
        f.precision_specified = 1;
        if ((c = *++s) == '*') {
            if ((f.precision = va_arg(*arg, int)) < 0)
                f.precision_specified = 0;
            c = *++s;
        } else {
            while (isdigit(c)) {
                f.precision = (f.precision * 10) + (c - '0');
                c = *++s;
            }
        }
    }

    flag_found = 1;

    switch (c) {
    case 'h':
        f.argument_options = 2;
        if (s[1] == 'h') {
            f.argument_options = 1;
            c = *++s;
        }
        break;
    case 'l':
        f.argument_options = 3;
        if (s[1] == 'l') {
            f.argument_options = 4;
            c = *++s;
        }
        break;
    case 'L':
        f.argument_options = 9;
        break;
    case 'j':
        f.argument_options = 6;
        break;
    case 't':
        f.argument_options = 8;
        break;
    case 'z':
        f.argument_options = 7;
        break;
    default:
        flag_found = 0;
    }

    if (flag_found)
        c = *++s;

    f.conversion_char = c;

    switch (c) {
    case 'd':
    case 'i':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
        if (f.argument_options == 9) {
            f.conversion_char = 0xFF;
            break;
        }
        if (!f.precision_specified)
            f.precision = 1;
        else if (f.justification_options == 2)
            f.justification_options = 1;
        break;

    case 'f':
    case 'F':
        if (f.argument_options == 2 || f.argument_options == 6 ||
            f.argument_options == 7 || f.argument_options == 8 ||
            f.argument_options == 4) {
            f.conversion_char = 0xFF;
            break;
        }
        if (!f.precision_specified)
            f.precision = 6;
        break;

    case 'a':
    case 'A':
        if (!f.precision_specified)
            f.precision = 13;
        if (f.argument_options == 2 || f.argument_options == 6 ||
            f.argument_options == 7 || f.argument_options == 8 ||
            f.argument_options == 4 || f.argument_options == 1)
            f.conversion_char = 0xFF;
        break;

    case 'g':
    case 'G':
        if (!f.precision)
            f.precision = 1;
    case 'e':
    case 'E':
        if (f.argument_options == 2 || f.argument_options == 1 ||
            f.argument_options == 6 || f.argument_options == 7 ||
            f.argument_options == 8 || f.argument_options == 4) {
            f.conversion_char = 0xFF;
            break;
        }
        if (!f.precision_specified)
            f.precision = 6;
        break;

    case 'p':
        f.conversion_char = 'x';
        f.alternate_form = 1;
        f.argument_options = 3;
        f.precision = 8;
        break;

    case 'c':
        if (f.argument_options == 3)
            f.argument_options = 5;
        else if (f.precision_specified || f.argument_options != 0)
            f.conversion_char = 0xFF;
        break;

    case 's':
        if (f.argument_options == 3)
            f.argument_options = 5;
        else if (f.argument_options != 0)
            f.conversion_char = 0xFF;
        break;

    case 'n':
        if (f.argument_options == 9)
            f.conversion_char = 0xFF;
        break;

    default:
        f.conversion_char = 0xFF;
        break;
    }

    *format = f;
    return s + 1;
}

/*
 * note:     MSL printf.c `long2str`: the 32-bit integer conversion of the
 *           printf back end, written as the MSL source has it.  The format
 *           descriptor is MSL's 16-byte `print_format` passed BY VALUE
 *           (six u8 option bytes, then int field_width at +8 and int
 *           precision at +0xC), which is what the home-area push and the
 *           [sp,#0x40..0x4c] reads are.  The dead 64-bit INT_MIN guard in
 *           the image (`asr r0,sl,#31; cmp r0,#0x80000000; cmpeq sl,#0`) is
 *           the source comparing the 32-bit `num` against the 64-bit
 *           constant 0x8000000000000000 (LLONG_MIN), promoted.  The digit
 *           pointer is `unsigned char *` (the `*p != '0'` test is ldrb).
 */
unsigned char *long2str(long num, unsigned char *buff, print_format format)
{
    unsigned long unsigned_num, base;
    unsigned char *p;
    int n, digits;
    int minus = 0;

    unsigned_num = num;
    minus = 0;
    p = buff;
    *--p = 0;
    digits = 0;

    if (!num && !format.precision && !(format.alternate_form && format.conversion_char == 'o'))
        return p;

    switch (format.conversion_char) {
    case 'd':
    case 'i':
        base = 10;
        if (num < 0) {
            if (num != 0x8000000000000000LL)
                unsigned_num = -num;
            minus = 1;
        }
        break;
    case 'o':
        base = 8;
        format.sign_options = 0;
        break;
    case 'u':
        base = 10;
        format.sign_options = 0;
        break;
    case 'x':
    case 'X':
        base = 16;
        format.sign_options = 0;
        break;
    }

    do {
        n = unsigned_num % base;
        unsigned_num /= base;
        if (n < 10)
            n += '0';
        else {
            n -= 10;
            if (format.conversion_char == 'x')
                n += 'a';
            else
                n += 'A';
        }
        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    if (base == 8 && format.alternate_form && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format.justification_options == 2) {
        format.precision = format.field_width;
        if (minus || format.sign_options)
            --format.precision;
        if (base == 16 && format.alternate_form)
            format.precision -= 2;
    }

    if (buff - p + format.precision > 509)
        return 0;

    while (digits < format.precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format.alternate_form) {
        *--p = format.conversion_char;
        *--p = '0';
    }

    if (minus)
        *--p = '-';
    else if (format.sign_options == 1)
        *--p = '+';
    else if (format.sign_options == 2)
        *--p = ' ';

    return p;
}

/*
 * note:     MSL printf.c `longlong2str`, the 64-bit twin of long2str
 *           (same source template over long long).  This is the REAL entry:
 *           the listing labels 0x02092C38 as a 4-byte row and 0x02092C3C as
 *           the function, but 0x02092C38 is the home-area push
 *           {r0,r1,r2,r3} that saves no lr, so disasm.py placed the label
 *           four bytes late.  Wants a seed at 0x02092C38 in
 *           layout/function_starts.txt and the label at 0x02092C3C removed
 *           (that is also what the trailing star is: the listing extent at
 *           0x02092C38 is 4 bytes, the body is 724).  `%` and `/` on
 *           unsigned long long emit _ull_mod / _ll_udiv, the standard mwcc
 *           names of the two runtime divmod entry points.
 */
unsigned char *longlong2str(long long num, unsigned char *buff, print_format format)
{
    unsigned long long unsigned_num, base;
    unsigned char *p;
    int n, digits;
    int minus = 0;

    unsigned_num = num;
    minus = 0;
    p = buff;
    *--p = 0;
    digits = 0;

    if (!num && !format.precision && !(format.alternate_form && format.conversion_char == 'o'))
        return p;

    switch (format.conversion_char) {
    case 'd':
    case 'i':
        base = 10;
        if (num < 0) {
            if (num != 0x8000000000000000LL)
                unsigned_num = -num;
            minus = 1;
        }
        break;
    case 'o':
        base = 8;
        format.sign_options = 0;
        break;
    case 'u':
        base = 10;
        format.sign_options = 0;
        break;
    case 'x':
    case 'X':
        base = 16;
        format.sign_options = 0;
        break;
    }

    do {
        n = unsigned_num % base;
        unsigned_num /= base;
        if (n < 10)
            n += '0';
        else {
            n -= 10;
            if (format.conversion_char == 'x')
                n += 'a';
            else
                n += 'A';
        }
        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    if (base == 8 && format.alternate_form && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format.justification_options == 2) {
        format.precision = format.field_width;
        if (minus || format.sign_options)
            --format.precision;
        if (base == 16 && format.alternate_form)
            format.precision -= 2;
    }

    if (buff - p + format.precision > 509)
        return 0;

    while (digits < format.precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format.alternate_form) {
        *--p = format.conversion_char;
        *--p = '0';
    }

    if (minus)
        *--p = '-';
    else if (format.sign_options == 1)
        *--p = '+';
    else if (format.sign_options == 2)
        *--p = ' ';

    return p;
}

/*
 * note:     MSL printf.c `double2hex`, the `%a`/`%A` formatter.  REAL
 *           entry: 0x02092F0C is the home-area push {r0,r1,r2,r3}; the
 *           listing label sits four bytes late at 0x02092F10 (the trailing
 *           star is that 4-byte listing extent, the body is 1196 bytes with
 *           its pool).  Wants a seed at 0x02092F0C and the 0x02092F10 label
 *           removed.  Callees: __dtoa = __num2dec, long2str =
 *           long2str (for the binary exponent), fabs = fabs,
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
 */
unsigned char *double2hex(double num, unsigned char *buff, print_format format)
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
    __dtoa(&form, num, &dec);

    switch (dec.sig.text[0]) {
    case '0':
        dec.exp = 0;
        break;
    case 'I':
        if (dec.sgn) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                __memcpy(p, sMslNegInf, 5);
            else
                __memcpy(p, sMslNegInfLower, 5);
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                __memcpy(p, sMslPosInf, 4);
            else
                __memcpy(p, sMslPosInfLower, 4);
        }
        return p;
    case 'N':
        if (dec.sgn) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                __memcpy(p, sMslNegNan, 5);
            else
                __memcpy(p, sMslNegNanLower, 5);
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                __memcpy(p, sMslPosNan, 4);
            else
                __memcpy(p, sMslPosNanLower, 4);
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

    p = long2str(exp, buff, exp_format);
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

    if (fabs(ld) != 0.0)
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

/*
 * MSL printf back end: the decimal rounding / odometer carry on the digit
 * buffer `__num2dec`-style control block.  Rounds the ASCII digit string in
 * place at position `idx`, propagating a carry leftwards, and renormalises
 * the exponent field when the carry runs off the top.
 *
 *   +0x00  u16 unk0
 *   +0x02  s16 num     decimal exponent (ldrsh at 0x020934A0, strh at reset)
 *   +0x04  u8  len     significant-digit count
 *   +0x05  u8  str[]   '0'..'9' ASCII digits
 *
 * THE ONE SPELLING THAT MATTERS (this closed a 12-byte residue that four
 * earlier lanes could not move; see docs/notes/pkt_020933B8.c.txt for the
 * seven spellings that all landed on the same 264-byte if-converted form).
 * The carry loop must be a `while (idx != 0)` whose DECREMENT lives inside
 * the continue path, not a `for (; idx != 0; idx--)`:
 *
 *     if (carry != 0 || v == 0) { idx--; continue; }
 *     *q = (u8)(v + '0');
 *     break;
 *
 * Written as a `for` (or with the break arm as the positive condition),
 * mwcc 1.1p1 if-converts the two-instruction write arm to `addne`/`strbne`
 * and fuses the decrement into `subs r1, r1, #1`, which is 12 bytes short.
 * With the decrement on the continue path the write arm is no longer on the
 * fall-through, so it stays a real block (`add ip, r4, #0x30` / `strb ip,
 * [r3]` / `b END`) and the loop test stays its own `cmp r1, #0` / `bne`,
 * exactly as the image has it at 0x0209347C..0x02093494.
 *
 * Two spellings carried over from the note and still required:
 *   - the reset block is `len = 1; num = 0; str[0] = '0';` in that order;
 *   - the `idx == 0` tail must be an explicit `goto reset;` back into the
 *     `idx < 0` block, or the 5-instruction reset is duplicated inline.
 *
 * The trailing star is the unlabelled follower at 0x020934CC (a
 * `push {r0, r1, r2, r3}` argument home area, the real start of the
 * function disasm.py labels at 0x020934D0): the listing extent runs 280
 * bytes, the body is 276.  Wants a seed at 0x020934CC in
 * layout/function_starts.txt.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/round_decimal.c \
 *       --func round_decimal --addr 0x020933B8 --arm --cc 1.1p1
 *   EXACT*, 276 bytes, no relocation sites.
 */
void round_decimal(Ctr *b, int idx)
{
    u8 *p;
    u8 *q;
    u32 v;
    u32 carry;

    if (idx < 0) {
    reset:
        b->length = 1;
        b->exp = 0;
        b->digits[0] = '0';
        return;
    }
    if (idx >= b->length)
        return;
    p = b->digits;
    q = p + idx + 1;
    v = (u8)(*--q - '0');
    if (v == 5) {
        u8 *s = p + b->length;
        do {
            s--;
        } while (s > q && *s == '0');
        if (s == q)
            carry = (u8)q[-1] & 1;
        else
            carry = 1;
    } else {
        carry = v > 5;
    }
    while (idx != 0) {
        v = (u8)((*--q - '0') + carry);
        carry = v > 9;
        if (carry != 0 || v == 0) {
            idx--;
            continue;
        }
        *q = (u8)(v + '0');
        break;
    }
    if (carry != 0) {
        b->exp = b->exp + 1;
        b->length = 1;
        b->digits[0] = '1';
        return;
    }
    if (idx == 0)
        goto reset;
    b->length = (u8)idx;
}

static inline int isupper(int c) { return ((c < 0 || c >= 0x80) ? 0 : (__ctype_map[c] & 0x200)); }

/*
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
 */
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
            round_decimal((Ctr *)&dec, format.precision);

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
            round_decimal((Ctr *)&dec, format.precision + 1);

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
            round_decimal((Ctr *)&dec, dec.sig.length - (frac_digits - format.precision));
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

/*
 * note:     MSL printf.c `__pformatter`, the vfprintf core.  REAL entry:
 *           0x02093BDC is the home-area push {r0,r1,r2,r3} (forced by &arg);
 *           the listing label sits four bytes late at 0x02093BE0 (the star).
 *           Signature (WriteProc, WriteProcArg, format_str, va_list arg,
 *           int is_secure); is_secure is the stack word [sp,#0x260].
 *           Shape levers that were load-bearing: every char is unsigned
 *           (ldrb, not ldrsb); the argument_options enum has the C99 cases
 *           6 = intmax_t (long long) and 8 = ptrdiff_t, each with its own
 *           va_arg arm; an explicit `case 0xFF:` beside `default:` (it is
 *           what makes the conversion switch a two-level range tree with
 *           the 'A'..'G' and 'd'..'x' jump tables); `%s` with L"" (wide)
 *           first, so the pool order is 0x020A8A70 (L"") then 0x020A8A74
 *           ("") -- the NARROW empty string is at 0x020A8A74, not 0x70.
 */
int __pformatter(void *(*WriteProc)(void *, const uchar *, size_t), void *WriteProcArg,
                  const uchar *format_str, va_list arg, int is_secure)
{
    int num_chars, chars_written, field_width;
    const uchar *format_ptr;
    const uchar *curr_format;
    print_format format;
    long long_num;
    long long long_long_num;
    long double long_double_num;
    uchar buff[512];
    uchar *buff_ptr;
    uchar *string_end;
    uchar fill_char = ' ';

    format_ptr = format_str;
    chars_written = 0;

    while (*format_ptr) {
        if (!(curr_format = strchr(format_ptr, '%'))) {
            num_chars = strlen(format_ptr);
            chars_written += num_chars;
            if (num_chars && !(*WriteProc)(WriteProcArg, format_ptr, num_chars))
                return -1;
            break;
        }

        num_chars = curr_format - format_ptr;
        chars_written += num_chars;
        if (num_chars && !(*WriteProc)(WriteProcArg, format_ptr, num_chars))
            return -1;

        format_ptr = curr_format;
        format_ptr = parse_format(format_ptr, &arg, &format);

        switch (format.conversion_char) {
        case 'd':
        case 'i':
            if (format.argument_options == 3)
                long_num = va_arg(arg, long);
            else if (format.argument_options == 4)
                long_long_num = va_arg(arg, long long);
            else if (format.argument_options == 6)
                long_long_num = va_arg(arg, intmax_t);
            else if (format.argument_options == 7)
                long_num = va_arg(arg, size_t);
            else if (format.argument_options == 8)
                long_num = va_arg(arg, ptrdiff_t);
            else
                long_num = va_arg(arg, int);

            if (format.argument_options == 2)
                long_num = (short)long_num;
            if (format.argument_options == 1)
                long_num = (signed char)long_num;

            if (format.argument_options == 4 || format.argument_options == 6) {
                if (!(buff_ptr = longlong2str(long_long_num, buff + 512, format)))
                    goto conversion_error;
            } else {
                if (!(buff_ptr = long2str(long_num, buff + 512, format)))
                    goto conversion_error;
            }
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (format.argument_options == 3)
                long_num = va_arg(arg, unsigned long);
            else if (format.argument_options == 4)
                long_long_num = va_arg(arg, long long);
            else if (format.argument_options == 6)
                long_long_num = va_arg(arg, intmax_t);
            else if (format.argument_options == 7)
                long_num = va_arg(arg, size_t);
            else if (format.argument_options == 8)
                long_num = va_arg(arg, ptrdiff_t);
            else
                long_num = va_arg(arg, unsigned int);

            if (format.argument_options == 2)
                long_num = (unsigned short)long_num;
            if (format.argument_options == 1)
                long_num = (unsigned char)long_num;

            if (format.argument_options == 4 || format.argument_options == 6) {
                if (!(buff_ptr = longlong2str(long_long_num, buff + 512, format)))
                    goto conversion_error;
            } else {
                if (!(buff_ptr = long2str(long_num, buff + 512, format)))
                    goto conversion_error;
            }
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 'f':
        case 'F':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            if (format.argument_options == 9)
                long_double_num = va_arg(arg, long double);
            else
                long_double_num = va_arg(arg, double);
            if (!(buff_ptr = float2str(long_double_num, buff + 512, format)))
                goto conversion_error;
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 'a':
        case 'A':
            if (format.argument_options == 9)
                long_double_num = va_arg(arg, long double);
            else
                long_double_num = va_arg(arg, double);
            if (!(buff_ptr = double2hex(long_double_num, buff + 512, format)))
                goto conversion_error;
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 's':
            if (format.argument_options == 5) {
                wchar_t *wcs_ptr = va_arg(arg, wchar_t *);
                if (is_secure && wcs_ptr == 0) {
                    MSL_C_LIB_CallExitHook(0, 0, -1);
                    return -1;
                }
                if (wcs_ptr == 0)
                    wcs_ptr = sMslWideEmpty;
                if ((num_chars = MSL_C_LIB_WideToNarrow(buff, wcs_ptr, sizeof(buff))) < 0)
                    goto conversion_error;
                buff_ptr = &buff[0];
            } else
                buff_ptr = va_arg(arg, uchar *);

            if (is_secure && buff_ptr == 0) {
                MSL_C_LIB_CallExitHook(0, 0, -1);
                return -1;
            }
            if (buff_ptr == 0)
                buff_ptr = sMslNarrowEmpty;

            if (format.alternate_form) {
                num_chars = (unsigned char)*buff_ptr++;
                if (format.precision_specified && num_chars > format.precision)
                    num_chars = format.precision;
            } else if (format.precision_specified) {
                num_chars = format.precision;
                if ((string_end = (uchar *)memchr(buff_ptr, 0, num_chars)) != 0)
                    num_chars = string_end - buff_ptr;
            } else
                num_chars = strlen(buff_ptr);
            break;

        case 'n':
            buff_ptr = va_arg(arg, uchar *);
            if (is_secure) {
                MSL_C_LIB_CallExitHook(0, 0, -1);
                return -1;
            }
            switch (format.argument_options) {
            case 0: *(int *)buff_ptr = chars_written; break;
            case 2: *(short *)buff_ptr = chars_written; break;
            case 3: *(long *)buff_ptr = chars_written; break;
            case 6: *(intmax_t *)buff_ptr = chars_written; break;
            case 7: *(size_t *)buff_ptr = chars_written; break;
            case 8: *(ptrdiff_t *)buff_ptr = chars_written; break;
            case 4: *(long long *)buff_ptr = chars_written; break;
            }
            continue;

        case 'c':
            buff_ptr = buff;
            *buff_ptr = va_arg(arg, int);
            num_chars = 1;
            break;

        case '%':
            buff_ptr = buff;
            *buff_ptr = '%';
            num_chars = 1;
            break;

        case 0xFF:
        default:
        conversion_error:
            num_chars = strlen(curr_format);
            chars_written += num_chars;
            if (num_chars && !(*WriteProc)(WriteProcArg, curr_format, num_chars))
                return -1;
            return chars_written;
        }

        field_width = num_chars;

        if (format.justification_options != 0) {
            fill_char = (format.justification_options == 2) ? '0' : ' ';
            if (((*buff_ptr == '+') || (*buff_ptr == '-') || (*buff_ptr == ' ')) && (fill_char == '0')) {
                if ((*WriteProc)(WriteProcArg, buff_ptr, 1) == 0)
                    return -1;
                ++buff_ptr;
                num_chars--;
            }
            if ((format.justification_options == 2) && ((format.conversion_char == 'a') || (format.conversion_char == 'A'))) {
                if (num_chars < 2)
                    return -1;
                if ((*WriteProc)(WriteProcArg, buff_ptr, 2) == 0)
                    return -1;
                num_chars -= 2;
                buff_ptr += 2;
            }
            while (field_width < format.field_width) {
                if ((*WriteProc)(WriteProcArg, &fill_char, 1) == 0)
                    return -1;
                ++field_width;
            }
        }

        if (num_chars && !(*WriteProc)(WriteProcArg, buff_ptr, num_chars))
            return -1;

        if (format.justification_options == 0)
            while (field_width < format.field_width) {
                uchar blank = ' ';
                if ((*WriteProc)(WriteProcArg, &blank, 1) == 0)
                    return -1;
                ++field_width;
            }

        chars_written += field_width;
    }

    return chars_written;
}

u32 MSL_C_LIB_SprintfWriteProc(u8 *sb, const void *src, u32 n)
{
    u32 pos = ((MslStringBuf *)sb)->length;
    u32 cap = ((MslStringBuf *)sb)->capacity;

    if (pos + n > cap)
        n = cap - pos;
    memcpy(*(u8 * *)&((MslStringBuf *)sb)->buf + pos, src, n);
    ((MslStringBuf *)sb)->length += n;
    return 1;
}

/*
 *           That address is the home-area `push {r0,r1,r2,r3}` start of
 *           the function disasm.py labels at 0x02093BE0 (worklist pkt_020933B8,
 *           size 4); four bytes of caller-save home area cannot be produced
 *           from C, so no source file can ever earn the shard entry that
 *           would attest it.  The other site (MSL_C_LIB_SprintfWriteProc) resolved as
 *           `matched` once this packet's own shard was written.
 */
u32 vsnprintf(u8 *dst, u32 n, const u8 *format, u8 *ap)
{
    u32 state[3];
    u32 len;

    state[0] = (u32)dst;
    state[1] = n;
    state[2] = 0;
    len = __pformatter((void *(*)(void *, const uchar *, size_t))MSL_C_LIB_SprintfWriteProc, state, format, ap, 0);
    if (dst == 0)
        return len;
    if (len < n) {
        dst[len] = 0;
        return len;
    }
    if (n != 0)
        *(u8 *)((char *)dst + n - 1) = 0;
    return len;
}

/*
 * note:     this is the REAL start of the function the worklist and the
 *           listing label at 0x02094534: the first instruction is the
 *           argument home area `push {r0,r1,r2,r3}`, which saves no lr, so
 *           disasm.py put its label four bytes late.  Wants a seed at
 *           0x02094530 in layout/function_starts.txt and the label at
 *           0x02094534 removed.
 *
 *           in this packet because its own `bl 0x02093BDC` site cannot be
 *           attested), so the single call site here stays wildcarded.  The C
 *           itself is byte-correct: 36 bytes, home push included.
 */
u32 sprintf(char *dst, char *fmt, ...)
{
    u32 *p = (u32 *)((u32)&fmt & ~3u);

    return vsnprintf((u8 *)dst, 0xFFFFFFFFu, (const u8 *)fmt, (u8 *)(p + 1));
}
