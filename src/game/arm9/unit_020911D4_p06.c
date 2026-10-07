/*
 * file:     unit_020911D4_p06.c
 * unit:     yes
 * function: func_020922B0, func_020922CC, func_02092344, func_02092364, func_020923B0, func_020923C4, func_020923F0, func_02092430, func_020924DC, func_020929E8, func_02092C38, func_02092F0C, func_020933B8, func_020934CC, func_02093BDC, func_02094488, func_020944CC, func_02094530, func_0209455C, func_02094694, func_020946C8, func_020946D8, func_02094750, func_02094778, func_0209477C, func_02094798, func_02094860, func_020948B0, func_020948E0, func_020949F4, func_02094A28, func_02094A60, func_02094B20, func_02094B8C, func_02095AA4, func_02095B2C, func_02095B3C, func_02095EAC, func_02095F40, func_02096004, func_020963F8, func_020964E0, func_020964F4, func_02096508, func_02096578, func_02096594, func_020965B4, func_02096620, func_02096670, func_020966B0, func_02096774, func_020968F4, func_02096990, func_02096D10, func_02096DF0, func_02096ED0, func_02097170, func_020972F0, func_0209739C, func_02097990
 * address:  0x020922B0
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
 *   g_020A8878  0x020A8878  data
 *   _u32_div_f  0x0209C2B0  arm
 *   _ll_udiv  0x0209C00C  arm
 *   _ull_mod  0x0209C018  arm
 *   func_0209A504  0x0209A504  arm
 *   _dneq  0x0209BAC8  arm
 *   _dls  0x0209B9A0  arm
 *   g_020A8A78  0x020A8A78  data
 *   g_02153FB0  0x02153FB0  data
 *   __float_huge  0x020A8814  data
 *   func_02091374  0x02091374  arm
 *   _fsub  0x0209CB8C  arm
 *   _f2d  0x0209BD38  arm
 *   _dsub  0x0209AF34  arm
 *   _dgr  0x0209B864  arm
 *   g_02153FAC  0x02153FAC  data
 *   FATFSi_FormatDriveEx  0x02095AA4  arm
 *   func_020921D8  0x020921D8  arm
 *   func_020921F4  0x020921F4  arm
 *   _deq  0x0209BA3C  arm
 *   func_0209AF34  0x0209AF34  arm
 *   func_0209A6E8  0x0209A6E8  arm
 *   func_02092144  0x02092144  arm
 *   func_0209A7A8  0x0209A7A8  arm
 *   func_0209C554  0x0209C554  arm
 *   func_0209A368  0x0209A368  arm
 *   func_0209AB80  0x0209AB80  arm
 *   _dfltu  0x0209B790  arm
 *   _dmul  0x0209B2E8  arm
 *   _dadd  0x0209AC04  arm
 *   _dflt  0x0209B750  arm
 *   _ddiv  0x0209D1E0  arm
 *   pow_10  0x020A8A7C  data
 */

typedef unsigned int u32;

extern unsigned char g_020A8878[];

typedef struct {
    unsigned char pad[4];
    u32 (*fn)(u32 *dst, u32 c);
} FuncTable;

typedef struct {
    unsigned char pad[8];
    FuncTable *table;
} Holder;

u32 func_020922B0(u32 *dst, u32 c)
{
    return ((Holder *)g_020A8878)->table->fn(dst, c);
}

#include "../../matched/include/Obj03036.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int size_t;

typedef signed int     s32;

typedef unsigned char uchar;

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

typedef struct { char style; short digits; } decform;

typedef struct {
    unsigned char sgn;
    char unused;
    short exp;
    struct { unsigned char length; unsigned char text[34]; unsigned char unused; } sig;
} decimal;

extern u32 func_020922B0(u32 *tmp, u32 c);
extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
extern void func_020972F0(const decform *f, double x, decimal *d);
extern double func_0209A504(double x);
u32 func_020922CC(u8 *dst, const u16 *src, u32 max);
void *func_02092344(void *dest, const void *src, size_t n);
void *func_02092364(void *dest, const void *src, size_t n);
void *func_020923B0(void *p, int c, u32 n);
u8 *func_020923C4(u8 *s, u32 c, u32 n);
int func_020923F0(const u8 *s1, const u8 *s2, u32 n);
void func_02092430(u8 *dest, u32 val, u32 count);
const uchar *func_020924DC(const uchar *format_string, va_list *arg, print_format *format);
unsigned char *func_020929E8(long num, unsigned char *buff, print_format format);
unsigned char *func_02092C38(long long num, unsigned char *buff, print_format format);
extern const unsigned short __ctype_map[];

u32 func_020922CC(u8 *dst, const u16 *src, u32 max)
{
    u32 n = 0;
    u32 tmp;

    if (dst == 0 || src == 0)
        return 0;

    do {
        u32 k;

        if (*src == 0) {
            dst[n] = 0;
            break;
        }
        k = func_020922B0(&tmp, *src++);
        if (n + k > max)
            break;
        func_02094860(dst + n, (const u8 *)&tmp, k);
        n += k;
    } while (n <= max);

    return n;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Byte-wise memcpy (func_02092344) and memmove (func_02092364).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02092344.c \
 *       --addr 0x02092344 --arm
 */
void *func_02092344(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (n == 0) {
        return dest;
    }

    do {
        *d++ = *s++;
    } while (--n != 0);

    return dest;
}

void *func_02092364(void *dest, const void *src, size_t n)
{
    if ((const unsigned char *)src >= (unsigned char *)dest) {
        unsigned char *d = (unsigned char *)dest;
        const unsigned char *s = (const unsigned char *)src;

        if (n == 0) {
            return dest;
        }

        do {
            *d++ = *s++;
        } while (--n != 0);

        return dest;
    } else {
        const unsigned char *s = (const unsigned char *)src + n;
        unsigned char *d = (unsigned char *)dest + n;

        if (n == 0) {
            return dest;
        }

        do {
            *--d = *--s;
        } while (--n != 0);

        return dest;
    }
}

/*
 * String / memory utilities:
 *   func_020923B0 (20 B)  wraps func_02092430 (memset) and returns ptr
 *   func_020923C4 (44 B)  memchr (byte search)
 *   func_020923F0 (64 B)  memcmp (memory comparison)
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020923B0.c \
 *       --addr 0x020923B0
 */
void *func_020923B0(void *p, int c, u32 n)
{
    func_02092430(p, c, n);
    return p;
}

u8 *func_020923C4(u8 *s, u32 c, u32 n)
{
    u8 val = (u8)c;

    if (n != 0) {
        do {
            if (*s++ == val) {
                return s - 1;
            }
        } while (--n != 0);
    }
    return 0;
}

int func_020923F0(const u8 *s1, const u8 *s2, u32 n)
{
    u8 b1;
    u8 b2;

    if (n != 0) {
        do {
            b1 = *s1++;
            b2 = *s2++;
            if (b1 != b2) {
                b1 = *(s1 - 1);
                b2 = *(s2 - 1);
                return (b1 < b2) ? -1 : 1;
            }
        } while (--n != 0);
    }
    return 0;
}

void func_02092430(u8 *dest, u32 val, u32 count)
{
    u32 byte_val;
    u32 align;
    u32 tmp;
    u32 blocks;
    u32 words;

    byte_val = val & 0xff;
    if (count >= 0x20) {
        align = (u32)(-(s32)(u32)dest) & 3;
        if (align != 0) {
            count -= align;
            do {
                *dest++ = (u8)byte_val;
            } while (--align != 0);
        }

        if (byte_val != 0) {
            tmp = byte_val << 8;
            tmp |= (byte_val << 24) | (byte_val << 16);
            byte_val |= tmp;
        }

        blocks = count >> 5;
        if (blocks != 0) {
            do {
                ((struct Obj03036 *)dest)->f0 = byte_val;
                ((struct Obj03036 *)dest)->f4 = byte_val;
                ((struct Obj03036 *)dest)->f8 = byte_val;
                ((struct Obj03036 *)dest)->fC = byte_val;
                ((struct Obj03036 *)dest)->f10 = byte_val;
                ((struct Obj03036 *)dest)->f14 = byte_val;
                ((struct Obj03036 *)dest)->f18 = byte_val;
                ((struct Obj03036 *)dest)->f1C = byte_val;
                dest += 0x20;
            } while (--blocks != 0);
        }

        words = (count & 0x1f) >> 2;
        if (words != 0) {
            do {
                ((struct Obj03036 *)dest)->f0 = byte_val;
                dest += 4;
            } while (--words != 0);
        }

        count &= 3;
    }

    if (count != 0) {
        do {
            *dest++ = (u8)byte_val;
        } while (--count != 0);
    }
}

#define __va_size(t) ((sizeof(t) + 3) & ~3)

#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))

#define isdigit(c) ((unsigned int)(c) < 0x80 ? (__ctype_map[c] & 8) : 0)

/*
 * note:     MSL printf.c `parse_format`, the conversion-spec scanner that
 *           __pformatter (func_02093BDC) calls once per '%'.  Written from
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
const uchar *func_020924DC(const uchar *format_string, va_list *arg, print_format *format)
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
unsigned char *func_020929E8(long num, unsigned char *buff, print_format format)
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
 * note:     MSL printf.c `longlong2str`, the 64-bit twin of func_020929E8
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
unsigned char *func_02092C38(long long num, unsigned char *buff, print_format format)
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

extern char s_020A8A40[5]; /* "-INF" */
extern char s_020A8A48[5]; /* "-inf" */
extern char s_020A8A50[4]; /* "INF"  */
extern char s_020A8A54[4]; /* "inf"  */
extern char s_020A8A58[5]; /* "-NAN" */
extern char s_020A8A60[5]; /* "-nan" */
extern char s_020A8A68[4]; /* "NAN"  */
extern char s_020A8A6C[4]; /* "nan"  */

/*
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
 */
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

typedef signed short   s16;

typedef struct {
    u16 unk0;
    s16 num;
    u8  len;
    u8  str[1];
} Ctr;

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
 *   python3 tools/match.py one --src src/matched/func_020933B8.c \
 *       --func func_020933B8 --addr 0x020933B8 --arm --cc 1.1p1
 *   EXACT*, 276 bytes, no relocation sites.
 */
void func_020933B8(Ctr *b, s32 idx)
{
    u8 *p;
    u8 *q;
    u32 v;
    u32 carry;

    if (idx < 0) {
    reset:
        b->len = 1;
        b->num = 0;
        b->str[0] = '0';
        return;
    }
    if (idx >= b->len)
        return;
    p = b->str;
    q = p + idx + 1;
    v = (u8)(*--q - '0');
    if (v == 5) {
        u8 *s = p + b->len;
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
        b->num = b->num + 1;
        b->len = 1;
        b->str[0] = '1';
        return;
    }
    if (idx == 0)
        goto reset;
    b->len = (u8)idx;
}

typedef struct { char c[5]; } Str5;
typedef struct { char c[4]; } Str4;
extern char s_020A8A40[5]; /* "-INF" */
extern char s_020A8A48[5]; /* "-inf" */
extern char s_020A8A50[4]; /* "INF"  */
extern char s_020A8A54[4]; /* "inf"  */
extern char s_020A8A58[5]; /* "-NAN" */
extern char s_020A8A60[5]; /* "-nan" */
extern char s_020A8A68[4]; /* "NAN"  */
extern char s_020A8A6C[4]; /* "nan"  */

static inline int isupper(int c) { return ((c < 0 || c >= 0x80) ? 0 : (__ctype_map[c] & 0x200)); }

/*
 * note:     MSL printf.c `float2str`, the %e/%f/%g formatter.  REAL entry:
 *           0x020934CC is the home-area push {r0,r1,r2,r3}; the listing
 *           label sits four bytes late at 0x020934D0.  Wants a seed at
 *           0x020934CC and the 0x020934D0 label removed.  Callees:
 *           func_020972F0 = __num2dec, func_020933B8 = round_decimal,
 *           0x0209B9A0 = the runtime double `<` (__dcmp_4).  isupper() is
 *           an INLINE FUNCTION over __ctype_map, not a macro: as a macro
 *           its 0 arm is CSE'd with the 0.0 argument of `num < 0` and kept
 *           in r4 across the call (8 bytes short).  The inf/nan strcpy's
 *           are mwcc's __memcpy intrinsic from non-const char[N] externs
 *           (see func_02092F0C.c).  radix_marker is the constant '.'.
 */
unsigned char *func_020934CC(double num, unsigned char *buff, print_format format)
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
    func_020972F0(&form, num, &dec);

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
                __memcpy(p, s_020A8A40, 5);
            else
                __memcpy(p, s_020A8A48, 5);
        } else {
            p = buff - 4;
            if (isupper(format.conversion_char))
                __memcpy(p, s_020A8A50, 4);
            else
                __memcpy(p, s_020A8A54, 4);
        }
        return p;
    case 'N':
        if (dec.sgn) {
            p = buff - 5;
            if (isupper(format.conversion_char))
                __memcpy(p, s_020A8A58, 5);
            else
                __memcpy(p, s_020A8A60, 5);
        } else {
            p = buff - 4;
            if (isupper(format.conversion_char))
                __memcpy(p, s_020A8A68, 4);
            else
                __memcpy(p, s_020A8A6C, 4);
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
            func_020933B8((Ctr *)&dec, format.precision);

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
            func_020933B8((Ctr *)&dec, format.precision + 1);

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
            func_020933B8((Ctr *)&dec, dec.sig.length - (frac_digits - format.precision));
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

#include "../../matched/include/Obj07071.h"

typedef long ptrdiff_t;

typedef long long intmax_t;

typedef unsigned short wchar_t;

extern void *func_02092344(void *dest, const void *src, unsigned int n);
u32 func_02094488(u8 *p, const void *src, u32 n);

#define __va_size(t) ((sizeof(t) + 3) & ~3)

#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))

extern uchar *func_02094A28(const uchar *s, int c);                 /* strchr */
extern int func_0209477C(const u8 *s);                       /* strlen */
extern const uchar *func_020924DC(const uchar *s, va_list *arg, print_format *f); /* parse_format */
extern uchar *func_020929E8(long num, uchar *buff, print_format format);           /* long2str */
extern uchar *func_02092C38(long long num, uchar *buff, print_format format);      /* longlong2str */
extern uchar *func_020934CC(double num, uchar *buff, print_format format);         /* float2str */
extern uchar *func_02092F0C(double num, uchar *buff, print_format format);         /* double2hex */
extern void func_02094750(u32 a, u32 b, u32 c);               /* constraint violation */
extern u32 func_020922CC(u8 *dst, const u16 *src, u32 max);               /* wcstombs */
extern u8 *func_020923C4(u8 *s, u32 c, u32 n);                       /* memchr */
extern wchar_t s_020A8A70[];  /* L"" */
extern uchar s_020A8A74[];     /* ""  */

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
int func_02093BDC(void *(*WriteProc)(void *, const uchar *, size_t), void *WriteProcArg,
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
        if (!(curr_format = func_02094A28(format_ptr, '%'))) {
            num_chars = func_0209477C(format_ptr);
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
        format_ptr = func_020924DC(format_ptr, &arg, &format);

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
                if (!(buff_ptr = func_02092C38(long_long_num, buff + 512, format)))
                    goto conversion_error;
            } else {
                if (!(buff_ptr = func_020929E8(long_num, buff + 512, format)))
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
                if (!(buff_ptr = func_02092C38(long_long_num, buff + 512, format)))
                    goto conversion_error;
            } else {
                if (!(buff_ptr = func_020929E8(long_num, buff + 512, format)))
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
            if (!(buff_ptr = func_020934CC(long_double_num, buff + 512, format)))
                goto conversion_error;
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 'a':
        case 'A':
            if (format.argument_options == 9)
                long_double_num = va_arg(arg, long double);
            else
                long_double_num = va_arg(arg, double);
            if (!(buff_ptr = func_02092F0C(long_double_num, buff + 512, format)))
                goto conversion_error;
            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 's':
            if (format.argument_options == 5) {
                wchar_t *wcs_ptr = va_arg(arg, wchar_t *);
                if (is_secure && wcs_ptr == 0) {
                    func_02094750(0, 0, -1);
                    return -1;
                }
                if (wcs_ptr == 0)
                    wcs_ptr = s_020A8A70;
                if ((num_chars = func_020922CC(buff, wcs_ptr, sizeof(buff))) < 0)
                    goto conversion_error;
                buff_ptr = &buff[0];
            } else
                buff_ptr = va_arg(arg, uchar *);

            if (is_secure && buff_ptr == 0) {
                func_02094750(0, 0, -1);
                return -1;
            }
            if (buff_ptr == 0)
                buff_ptr = s_020A8A74;

            if (format.alternate_form) {
                num_chars = (unsigned char)*buff_ptr++;
                if (format.precision_specified && num_chars > format.precision)
                    num_chars = format.precision;
            } else if (format.precision_specified) {
                num_chars = format.precision;
                if ((string_end = (uchar *)func_020923C4(buff_ptr, 0, num_chars)) != 0)
                    num_chars = string_end - buff_ptr;
            } else
                num_chars = func_0209477C(buff_ptr);
            break;

        case 'n':
            buff_ptr = va_arg(arg, uchar *);
            if (is_secure) {
                func_02094750(0, 0, -1);
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
            num_chars = func_0209477C(curr_format);
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

u32 func_02094488(u8 *p, const void *src, u32 n)
{
    u32 pos = ((struct Obj07071 *)p)->f8;
    u32 cap = ((struct Obj07071 *)p)->f4;

    if (pos + n > cap)
        n = cap - pos;
    func_02092344(*(u8 * *)&((struct Obj07071 *)p)->f0 + pos, src, n);
    ((struct Obj07071 *)p)->f8 += n;
    return 1;
}

typedef int (*_compare_function)(const void *, const void *);

extern u32 func_02094488(u8 *p, const void *src, u32 n);

u32 func_020944CC(u8 *dst, u32 n, const u8 *format, u8 *ap);
u32 func_02094530(char *dst, u32 n, ...);
void func_0209455C(void *table_base, size_t num_members, size_t member_size, _compare_function compare_members);
u32 func_02094694(void);
extern u32 g_020A8A78;

/*
 *           That address is the home-area `push {r0,r1,r2,r3}` start of
 *           the function disasm.py labels at 0x02093BE0 (worklist pkt_020933B8,
 *           size 4); four bytes of caller-save home area cannot be produced
 *           from C, so no source file can ever earn the shard entry that
 *           would attest it.  The other site (func_02094488) resolved as
 *           `matched` once this packet's own shard was written.
 */
u32 func_020944CC(u8 *dst, u32 n, const u8 *format, u8 *ap)
{
    u32 state[3];
    u32 len;

    state[0] = (u32)dst;
    state[1] = n;
    state[2] = 0;
    len = func_02093BDC((void *(*)(void *, const uchar *, size_t))func_02094488, state, format, ap, 0);
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
u32 func_02094530(char *dst, u32 n, ...)
{
    u32 *p = (u32 *)((u32)&n & ~3u);

    return func_020944CC((u8 *)dst, 0xFFFFFFFFu, (const u8 *)n, (u8 *)(p + 1));
}

#define table_ptr(i) (((char *)table_base) + (member_size * ((i) - 1)))

#define swap(dst, src, cnt)                          \
    do {                                             \
        size_t n = (cnt);                            \
        unsigned char *p = (unsigned char *)(src);   \
        unsigned char *q = (unsigned char *)(dst);   \
        if (n) do {                                  \
            unsigned char a = *p;                    \
            unsigned char b = *q;                    \
            *q++ = a;                                \
            *p++ = b;                                \
        } while (--n);                               \
    } while (0)

/*
 * note:     MSL stdlib qsort.c `qsort` (heapsort), 312 bytes, the real open
 *           code of worklist row pkt_02094534 (0x02094534..0x0209455C is the
 *           tail of sprintf, already EXACT as src/matched/func_02094530.c).
 *           disasm.py has NO label at 0x0209455C (the listing folds
 *           0x02094534..0x02094750 into one block), so the worklist counts
 *           these 312 bytes as data-adjacent extent, not code: integrator,
 *           seed 0x0209455C in layout/function_starts.txt.  Levers: the
 *           swap macro's count is assigned before its two pointers (sets
 *           the mov r2 / ldr r4 / ldr r3 order) and the bytes are unsigned
 *           char (ldrb, MSL is char-unsigned).  Verified with
 *             python3 tools/match.py one --src src/matched/func_0209455C.c \
 *                 --func func_0209455C --addr 0x0209455C --arm
 */
void func_0209455C(void *table_base, size_t num_members, size_t member_size,
                   _compare_function compare_members)
{
    size_t l, r, j;
    char *lp;
    char *rp;
    char *ip;
    char *jp;
    char *kp;

    if (num_members < 2)
        return;

    r = num_members;
    l = (r / 2) + 1;

    lp = table_ptr(l);
    rp = table_ptr(r);

    for (;;) {
        if (l > 1) {
            l--;
            lp -= member_size;
        } else {
            swap(lp, rp, member_size);

            if (--r == 1)
                return;

            rp -= member_size;
        }

        j = l;

        jp = table_ptr(j);

        while (j * 2 <= r) {
            j *= 2;

            ip = jp;
            jp = table_ptr(j);

            if (j < r) {
                kp = jp + member_size;

                if (compare_members(jp, kp) < 0) {
                    j++;
                    jp = kp;
                }
            }

            if (compare_members(ip, jp) < 0)
                swap(ip, jp, member_size);
            else
                break;
        }
    }
}

u32 func_02094694(void)
{
    g_020A8A78 = g_020A8A78 * 0x41C64E6Du + 0x3039u;
    return (g_020A8A78 >> 16) & 0x7FFFu;
}

#include "../../matched/include/Obj00079.h"
#include "../../matched/include/Obj02480.h"

typedef void (*Hook02153FB0)(u32, u32, u32);

void func_020946C8(u32 v);
int func_020946D8(u32 *p, u32 a1, u32 a2);
void func_02094750(u32 a, u32 b, u32 c);
void func_02094778(void);
int func_0209477C(const u8 *s);
char *func_02094798(char *dst, const char *src);
u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
u8 *func_020948B0(u8 *dest, const u8 *src);
int func_020948E0(const char *s1, const char *s2);
int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
u8 *func_02094A28(const u8 *s, int c);
extern Hook02153FB0 g_02153FB0;

void func_020946C8(u32 v)
{
    g_020A8A78 = v;
}

int func_020946D8(u32 *p, u32 a1, u32 a2)
{
    switch (a2) {
    case 0: {
        u8 *q = (u8 *)*p;
        u8 c = *q;

        if (c == 0) {
            p[1] = 1;
            return -1;
        }
        *p = (u32)(q + 1);
        return c;
    }
    case 1:
        if (p[1] == 0)
            p[0] = p[0] - 1;
        else
            p[1] = 0;
        return (int)a1;
    case 2:
        return (int)p[1];
    default:
        return 0;
    }
}

/*
 * Calls the hook stored at 0x02153FB0 when it is set, otherwise falls through
 * to the default handler at 0x02094778.
 *
 * The hook is taken as a three-argument pointer because that is the only thing
 * that reproduces the original's `ldr r3` / `blx r3`: with a zero- or
 * one-argument callee the compiler puts the target in r0 or r1 and the head of
 * the function shifts.  The arguments are passed straight through, so nothing
 * in the bytes fixes their values.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02094750.c \
 *       --func func_02094750 --addr 0x02094750 --cc 1.1p1 --arm
 */
void func_02094750(u32 a, u32 b, u32 c)
{
    if (g_02153FB0 != 0) {
        g_02153FB0(a, b, c);
    } else {
        func_02094778();
    }
}

void func_02094778(void){ }

/*
 * A plain byte-string length counter (strlen over a u8 buffer, not the C
 * library helper): count bytes up to and including the NUL, then return the
 * count minus one.  Self-contained, no external symbol.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0209477C.c \
 *       --func func_0209477C --addr 0x0209477C --cc 1.1p1 --arm
 */
int func_0209477C(const u8 *s)
{
    int n = -1;

    do {
        n++;
    } while (*s++ != 0);

    return n;
}

#define K1 0xFEFEFEFF

#define K2 0x80808080

/*
 * MSL strcpy, the 4-byte-at-a-time form (MSL_C string.c).  If source and
 * destination share a 4-byte alignment, copy the (3 - align) leading bytes,
 * then whole words while the Mycroft null-byte test
 * (w + 0xFEFEFEFF) & ~w & 0x80808080 is clear (both constants are plain pool
 * words, no relocation), and finish byte by byte from the word that carries
 * the terminator.  A misaligned pair goes to the byte loop directly.
 *
 * HOW THE 2-BYTE WALL WAS CLOSED (wave 17).  docs/notes/pkt_02094798.c.txt
 * held this at 198/200 with the loop test's `and` accumulating into the
 * register holding w + K1 instead of the one holding ~w.  Every expression
 * spelling of the test left that choice alone.  MSL spells the test as three
 * statements on one mask local, `t = w + K1; t &= ~w; t &= K2;`, in both the
 * pre-loop and the loop test, and leaves the loop with `if (t) goto adjust`
 * inside `do { } while (1)`.  That source is EXACT under 1.1p1 and 1.2.
 */
char *func_02094798(char *dst, const char *src)
{
    u8 *destb;
    u8 *fromb;
    u32 w;
    u32 t;
    u32 align;

    fromb = (u8 *)src;
    destb = (u8 *)dst;

    if ((align = ((int)fromb & 3)) != ((int)destb & 3)) {
        goto bytecopy;
    }

    if (align) {
        if ((*destb = *fromb) == 0) {
            return dst;
        }
        for (align = 3 - align; align; align--) {
            if ((*(++destb) = *(++fromb)) == 0) {
                return dst;
            }
        }
        ++destb;
        ++fromb;
    }

    w = *(u32 *)fromb;
    t = w + K1;
    t &= ~w;
    t &= K2;
    if (t) {
        goto bytecopy;
    }
    destb -= 4;
    do {
        destb += 4;
        *(u32 *)destb = w;
        fromb += 4;
        w = *(u32 *)fromb;
        t = w + K1;
        t &= ~w;
        t &= K2;
        if (t) {
            goto adjust;
        }
    } while (1);

adjust:
    destb += 4;
bytecopy:
    if ((*destb = *fromb) == 0) {
        return dst;
    }
    do {
        if ((*(++destb) = *(++fromb)) == 0) {
            return dst;
        }
    } while (1);
    return dst;
}

/*
 * strncpy and strcat implementations in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02094860.c \
 *       --addr 0x02094860 --arm --cc 1.1p1
 */
u8 *func_02094860(u8 *dest, const u8 *src, u32 n)
{
    u8 *d = dest;

    if (n == 0) {
        return dest;
    }

    do {
        u8 *prev = d;
        *d++ = *src++;
        if (*prev == 0) {
            if (--n == 0) {
                return dest;
            }
            do {
                *d++ = 0;
            } while (--n != 0);
            return dest;
        }

        if (--n == 0) {
            return dest;
        }
    } while (1);
}

u8 *func_020948B0(u8 *dest, const u8 *src)
{
    u8 *d = dest;

    while (*d++)
        ;
    --d;
    while (*d++ = *src++)
        ;

    return dest;
}

/*
 * MSL strcmp, the 4-byte-at-a-time form.  Compare the first byte; if the two
 * pointers share a 4-byte alignment, copy the (3 - align) leading bytes one at
 * a time, then compare whole words using the Alan Mycroft null-byte test
 * (w + 0xFEFEFEFF) & ~w & 0x80808080 -- the two constants are the pool words at
 * 0x020949EC and 0x020949F0 and carry no relocation -- and fall into a
 * byte-by-byte epilogue at the word that carries the terminator.  A misaligned
 * pair, and a word mismatch, both enter that epilogue directly.
 *
 * HOW THE 2026-09-21 WALL WAS CLOSED.  docs/notes/func_020948E0.c.txt records
 * this as a 28-of-276-byte near miss "solely in register allocation between
 * r2, r4 and lr" (and that note's own source did not compile: it says
 * `(const u32 *)p2` for `s2`).  Two separate things were wrong, and both are
 * readable off the image:
 *
 *   1. ONE VARIABLE HOLDS BOTH THE WORD AND THE BYTE.  The image branches out
 *      of the word loop with `b #0x20949bc`, landing on `cmp r2, #0` -- and r2
 *      at that point holds the 32-bit WORD w1 just loaded by
 *      `ldr r2,[r0,#4]!`, not a byte.  That is sound (the haszero test has
 *      already proved no byte of the word is zero) and it is only expressible
 *      if the same `u32` names both.  Declaring a separate `unsigned char c1`
 *      for the byte adds a third value live across the word loop and widens
 *      the prologue to `push {r3, r4, r5, lr}` -- the documented symptom, and
 *      the whole 28-byte residue.
 *   2. THE FALL-THROUGH FROM find_in_word.  The image's find_in_word block at
 *      0x020949A8 ends with `popne {r4, pc}` and FALLS THROUGH into the
 *      epilogue's `cmp r2, #0`; the two `goto byte_loop` paths branch to that
 *      `cmp` instead.  Spelling the epilogue's first test as a fresh
 *      `*(const u8 *)s1 == 0` re-loads the byte and costs four bytes.
 *
 * Note the ASYMMETRY of the two haszero tests, which is in the image and is
 * not a transcription slip: the PRE-loop test at +0x74 is the full
 * `(w + C) & ~w & M` (three instructions, `mvn`/`add`/`and` then `tst`), while
 * the test INSIDE the loop at +0xA8 is only `(w + C) & M` -- `add lr,r2,r3` /
 * `tst lr,ip`, with no `mvn`.  Writing the full expression in both places
 * compiles the loop body two instructions long.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020948E0.c \
 *       --func func_020948E0 --addr 0x020948E0 --cc 1.1p1 --arm
 */
int func_020948E0(const char *s1, const char *s2)
{
    int diff;
    u32 align;
    u32 w1;
    u32 w2;

    w1 = *(const u8 *)&((struct Obj00079 *)s1)->f0;
    diff = w1 - *(const u8 *)&((struct Obj02480 *)s2)->f0;
    if (diff != 0) {
        return diff;
    }

    align = (u32)s1 & 3;
    if (((u32)s2 & 3) != align) {
        goto byte_loop;
    }

    if (align != 0) {
        if (w1 == 0) {
            return 0;
        }
        align = 3 - align;
        if (align != 0) {
            do {
                w1 = *(const u8 *)++s1;
                diff = w1 - *(const u8 *)++s2;
                if (diff != 0) {
                    return diff;
                }
                if (w1 == 0) {
                    return 0;
                }
            } while (--align != 0);
        }
        s1++;
        s2++;
    }

    w1 = *(const u32 *)s1;
    w2 = *(const u32 *)s2;
    if ((((w1 + 0xfefefeff) & ~w1) & 0x80808080) != 0) {
        goto find_in_word;
    }
    if (w1 != w2) {
        goto mismatch_word;
    }

    do {
        w1 = *(const u32 *)(s1 += 4);
        w2 = *(const u32 *)(s2 += 4);
        if (((w1 + 0xfefefeff) & 0x80808080) != 0) {
            goto find_in_word;
        }
    } while (w1 == w2);

mismatch_word:
    s1--;
    s2--;
    goto byte_loop;

find_in_word:
    w1 = *(const u8 *)&((struct Obj00079 *)s1)->f0;
    diff = w1 - *(const u8 *)&((struct Obj02480 *)s2)->f0;
    if (diff != 0) {
        return diff;
    }

byte_loop:
    if (w1 == 0) {
        return 0;
    }
    do {
        w1 = *(const u8 *)++s1;
        diff = w1 - *(const u8 *)++s2;
        if (diff != 0) {
            return diff;
        }
    } while (w1 != 0);

    return 0;
}

/*
 * strncmp and strchr implementations in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020949F4.c \
 *       --addr 0x020949F4 --arm --cc 1.1p1
 */
int func_020949F4(const u8 *s1, const u8 *s2, u32 n)
{
    if (n != 0) {
        do {
            u8 c2 = *s2++;
            u8 c1 = *s1++;
            if (c1 != c2) {
                return c1 - c2;
            }
            if (c1 == 0) {
                break;
            }
        } while (--n != 0);
    }

    return 0;
}

typedef struct decimal2 {
    unsigned char sign;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} decimal2;

typedef struct { unsigned char c[9]; } model9;

typedef struct { unsigned char c[5]; } model5;

int func_02094A60(const u8 *s, const u8 *reject);
u8 *func_02094B20(const u8 *s1, const u8 *s2);
extern const u16 __ctype_map[];
extern const u8 __upper_map[];
extern float __float_huge;
extern double __double_huge;
extern const model9 s_infinity;
extern const model5 s_nan;

u8 *func_02094A28(const u8 *s, int c)
{
    u8 m = (u8)c;
    u8 ch;

    ch = *s++;
    while (ch != 0) {
        if (ch == m)
            return (u8 *)s - 1;
        ch = *s++;
    }
    return m ? 0 : (u8 *)s - 1;
}

/*
 * strcspn, in the MSL string module this pseudo-family is made of
 * (func_020949F4 strncmp, func_02094A28 strchr, func_02094B20 strstr).
 * Builds a 32-byte bitmap of the reject set on the stack, then scans the
 * subject until a member is hit, returning the index of that byte.
 *
 * TWO SPELLINGS ARE LOAD-BEARING, and both were missed by the two earlier
 * lanes recorded in docs/notes/func_02094A60.c.txt and
 * docs/notes/pkt_02094A60.c.txt, which between them left this at
 * DIFF / 188 bytes against 192 / 124 concrete bytes out:
 *
 *  - The character is `int c`, NOT `u8 c`.  The original masks it with a
 *    separate `and ip, r4, #0xff` whose result lives across the pointer
 *    load and indexes the map as `ldrb r3, [lr, ip, asr #3]` -- an
 *    ARITHMETIC shift, which is what an `int` shift compiles to.  With
 *    `u8 c` the cast is a no-op, the mask disappears, the map index folds
 *    into the load and the function loses four bytes and a saved register
 *    (`push {r4, lr}` for the original's `push {r3, r4, r5, lr}`).  This
 *    one change alone takes the body from 124 concrete bytes out to 10,
 *    size-exact, with every byte from +0x30 to the epilogue identical.
 *
 *  - The clear loop's COUNTER must be declared BEFORE the cursor
 *    (`u32 i = 8;` then `u8 *p = map;`).  This is
 *    docs/idioms/declaration-order-decides-which-register-a-local-gets.md:
 *    the original puts the cursor in ip and the counter in r3
 *    (`add ip, sp, #0` / `mov r3, #8` / ... / `subs r3, r3, #1`), and the
 *    reverse declaration order hands them the opposite pair, the residual
 *    10 bytes.  `int i` instead of `u32 i` is 160 bytes out: the signed
 *    counter costs a separate `cmp`/`bgt` in place of `subs`/`bne`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02094A60.c \
 *       --func func_02094A60 --addr 0x02094A60 --cc 1.1p1 --arm
 *   EXACT, 192 bytes, no relocation sites.
 */
int func_02094A60(const u8 *s, const u8 *reject)
{
    u8 map[32];
    u32 i = 8;
    u8 *p = map;
    int c;
    const u8 *p_reject;
    const u8 *p_s;

    do {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    } while (--i);

    c = *reject;
    p_reject = reject + 1;

    if (c != 0) {
        do {
            map[(u8)c >> 3] |= (u8)(1 << (c & 7));
            c = *p_reject++;
        } while (c != 0);
    }

    c = *s;
    p_s = s + 1;

    if (c != 0) {
        do {
            if (map[(u8)c >> 3] & (u8)(1 << (c & 7))) {
                break;
            }
            c = *p_s++;
        } while (c != 0);
    }

    return (u32)(p_s - s) - 1;
}

/*
 * strstr implementation in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02094B20.c \
 *       --func func_02094B20 --addr 0x02094B20 --cc 1.1p1 --arm
 */
u8 *func_02094B20(const u8 *s1, const u8 *s2)
{
    u8 c2;
    u8 c1;
    const u8 *p;

    if (s2 == 0 || (c2 = *s2) == 0) {
        return (u8 *)s1;
    }

    c1 = *s1;
    p = s1 + 1;

    if (c1 != 0) {
        do {
            if (c1 == c2) {
                const u8 *p2 = s2 + 1;
                const u8 *p1 = p;
                u8 sc2, sc1;

                do {
                    sc2 = *p2++;
                    sc1 = *p1++;
                    if (sc1 != sc2) {
                        break;
                    }
                } while (sc1 != 0);

                if (sc2 == 0) {
                    return (u8 *)p - 1;
                }
            }
            c1 = *p++;
        } while (c1 != 0);
    }

    return 0;
}

extern double func_0209739C(const decimal2 *d);      /* __dec2num */
extern double func_02091374(const char *tagp);      /* nan */

#undef isdigit
#define isdigit(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))
#define isalpha(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x1))
#define isspace(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x100))
#define isxdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x400))
#define toupper(c)  (((c) < 0 || (c) >= 0x80) ? (c) : __upper_map[c])

#define INFINITY __float_huge
#define HUGE_VAL __double_huge

enum scan_states {
    start              = 0x0001,
    sig_start          = 0x0002,
    leading_sig_zeroes = 0x0004,
    int_digit_loop     = 0x0008,
    frac_start         = 0x0010,
    frac_digit_loop    = 0x0020,
    sig_end            = 0x0040,
    exp_start          = 0x0080,
    leading_exp_digit  = 0x0100,
    leading_exp_zeroes = 0x0200,
    exp_digit_loop     = 0x0400,
    finished           = 0x0800,
    failure            = 0x1000,
    nan_state          = 0x2000,
    infin_state        = 0x4000,
    hex_state          = 0x8000
};

enum hex_scan_states {
    not_hex                = 0x0000,
    hex_start              = 0x0001,
    hex_leading_sig_zeroes = 0x0002,
    hex_int_digit_loop     = 0x0004,
    hex_frac_digit_loop    = 0x0008,
    hex_sig_end            = 0x0010,
    hex_exp_start          = 0x0020,
    hex_leading_exp_digit  = 0x0040,
    hex_leading_exp_zeroes = 0x0080,
    hex_exp_digit_loop     = 0x0100
};

#define final_state(s) ((s) & (finished | failure))
#define success(s) ((s) & (leading_sig_zeroes | int_digit_loop | frac_digit_loop | \
                           leading_exp_zeroes | exp_digit_loop | finished))
#define hex_success(count, s) ((count) - 1 > 2 && ((s) & (hex_leading_sig_zeroes | \
                           hex_int_digit_loop | hex_frac_digit_loop | \
                           hex_leading_exp_zeroes | hex_exp_digit_loop)))

#define fetch()    (count++, (*ReadProc)(ReadProcArg, 0, 0))
#define unfetch(c) (*ReadProc)(ReadProcArg, c, 1)

/*
 * MSL __strtold (C99 soft-float number scanner, decimal and hex paths).
 *
 * EXACT, 3864 bytes against 3864, 17 of 17 relocation sites resolved
 * (match.py one, 1.1p1 -O4,p, 2026-09-24, wave 21 lane A).
 *
 * What closed the MATCH cap: the two local model arrays.  MSL writes them
 * as `unsigned char model[] = "INFINITY";` and `... = "NAN(";`, which makes
 * the compiler emit anonymous string literals (@52/@70) into the object's
 * own .rodata; those two ABS32 pool words (+0x0EF0, +0x0EF4) had no name
 * and no witness.  Here each array is a one-member struct copied from an
 * extern pinned to the address the image's pool word names (0x020A62E4
 * "INFINITY", 0x020A62DC "NAN("), the same treatment as a __FILE__ string
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).  The
 * struct copy is byte-identical to the literal initialiser (same 4x2-byte
 * copy loop plus tail byte, same unrolled 5-byte copy).  s_infinity attests
 * by `string`, s_nan and __double_huge by sole-ref.
 *
 * Register colouring of the hex tail: the hex block declares hexresult,
 * ui2, ch2, p, hch in that order (wave 20 lane 20M); see
 * docs/idioms/declaration-position-orders-block-scope-colouring.md and
 * docs/notes/pkt_02094B8C.c.txt.
 */
double func_02094B8C(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg,
                     int *chars_scanned, int *overflow)
{
    int scan_state = start;
    int hex_scan_state = not_hex;
    int count = 0;
    int spaces = 0;
    int c;
    decimal2 d = {0, 0, 0, {0, ""}};
    int sig_negative = 0;
    int exp_negative = 0;
    long exp_value = 0;
    int exp_adjust = 0;
    double result;
    int sign_detected = 0;
    unsigned char *chptr;
    unsigned char mantissa[8];
    unsigned char uch, uch1;
    unsigned long ui = 0;
    unsigned long chindex;
    int NibbleIndex;
    int expsign = 0;
    int exp_negsign = 0;
    unsigned intdigits = 0;
    unsigned maxdigits;

    *overflow = 0;
    c = fetch();

    while (count <= max_width && c != -1 && !final_state(scan_state))
    {
        switch (scan_state)
        {
        case start:
            if (isspace(c))
            {
                c = fetch();
                count--;
                spaces++;
                break;
            }
            switch (toupper(c))
            {
            case '-':
                sig_negative = 1;
            case '+':
                c = fetch();
                sign_detected = 1;
                break;
            case 'I':
                c = fetch();
                scan_state = infin_state;
                break;
            case 'N':
                c = fetch();
                scan_state = nan_state;
                break;
            default:
                scan_state = sig_start;
                break;
            }
            break;

        case infin_state:
        {
            int i = 1;
            model9 model = s_infinity;

            while ((i < 8) && (toupper(c) == model.c[i]))
            {
                i++;
                c = fetch();
            }
            if ((i == 3) || (i == 8))
            {
                if (sig_negative)
                    result = -INFINITY;
                else
                    result = INFINITY;
                *chars_scanned = spaces + i + sign_detected;
                return result;
            }
            else
                scan_state = failure;
            break;
        }

        case nan_state:
        {
            int i = 1, j = 0;
            model5 model = s_nan;
            char nan_arg[32] = "";

            while ((i < 4) && (toupper(c) == model.c[i]))
            {
                i++;
                c = fetch();
            }
            if ((i == 3) || (i == 4))
            {
                if (i == 4)
                {
                    while ((j < 32) && (isdigit(c) || isalpha(c) || c == '.'))
                    {
                        nan_arg[j++] = c;
                        c = fetch();
                    }
                    if (c != ')')
                    {
                        scan_state = failure;
                        break;
                    }
                    else
                        j++;
                }
                nan_arg[j] = '\0';
                if (sig_negative)
                    result = -func_02091374(nan_arg);
                else
                    result = func_02091374(nan_arg);
                *chars_scanned = spaces + i + j + sign_detected;
                return result;
            }
            else
                scan_state = failure;
            break;
        }

        case sig_start:
            if (c == '.')
            {
                scan_state = frac_start;
                c = fetch();
                break;
            }
            if (!isdigit(c))
            {
                scan_state = failure;
                break;
            }
            if (c == '0')
            {
                c = fetch();
                if (toupper(c) == 'X')
                {
                    scan_state = hex_state;
                    hex_scan_state = hex_start;
                }
                else
                    scan_state = leading_sig_zeroes;
                break;
            }
            scan_state = int_digit_loop;
            break;

        case leading_sig_zeroes:
            if (c == '0')
            {
                c = fetch();
                break;
            }
            scan_state = int_digit_loop;
            break;

        case int_digit_loop:
            if (!isdigit(c))
            {
                if (c == '.')
                {
                    scan_state = frac_digit_loop;
                    c = fetch();
                }
                else
                    scan_state = sig_end;
                break;
            }
            if (d.sig.length < 20)
                d.sig.text[d.sig.length++] = c;
            else
                exp_adjust++;
            c = fetch();
            break;

        case frac_start:
            if (!isdigit(c))
            {
                scan_state = failure;
                break;
            }
            scan_state = frac_digit_loop;
            break;

        case frac_digit_loop:
            if (!isdigit(c))
            {
                scan_state = sig_end;
                break;
            }
            if (d.sig.length < 20)
            {
                if (c != '0' || d.sig.length)
                    d.sig.text[d.sig.length++] = c;
                exp_adjust--;
            }
            c = fetch();
            break;

        case sig_end:
            if (toupper(c) == 'E')
            {
                scan_state = exp_start;
                c = fetch();
                break;
            }
            scan_state = finished;
            break;

        case exp_start:
            if (c == '+')
            {
                c = fetch();
            }
            else if (c == '-')
            {
                c = fetch();
                exp_negative = 1;
            }
            scan_state = leading_exp_digit;
            break;

        case leading_exp_digit:
            if (!isdigit(c))
            {
                scan_state = failure;
                break;
            }
            if (c == '0')
            {
                scan_state = leading_exp_zeroes;
                c = fetch();
                break;
            }
            scan_state = exp_digit_loop;
            break;

        case leading_exp_zeroes:
            if (c == '0')
            {
                c = fetch();
                break;
            }
            scan_state = exp_digit_loop;
            break;

        case exp_digit_loop:
            if (!isdigit(c))
            {
                scan_state = finished;
                break;
            }
            exp_value = exp_value * 10 + (c - '0');
            if (exp_value > 308)
                *overflow = 1;
            c = fetch();
            break;

        case hex_state:
            switch (hex_scan_state)
            {
            case hex_start:
                chptr = (unsigned char *)&mantissa;
                intdigits = 0;
                maxdigits = 14;
                chptr[0] = 0;
                chptr[1] = 0;
                chptr[2] = 0;
                chptr[3] = 0;
                chptr[4] = 0;
                chptr[5] = 0;
                chptr[6] = 0;
                chptr[7] = 0;
                NibbleIndex = 0;
                hex_scan_state = hex_leading_sig_zeroes;
                c = fetch();
                break;

            case hex_leading_sig_zeroes:
                if (c == '0')
                {
                    c = fetch();
                    break;
                }
                hex_scan_state = hex_int_digit_loop;
                break;

            case hex_int_digit_loop:
                if (!isxdigit(c))
                {
                    if (c == '.')
                    {
                        hex_scan_state = hex_frac_digit_loop;
                        c = fetch();
                    }
                    else
                        hex_scan_state = hex_sig_end;
                    break;
                }
                if (intdigits < maxdigits)
                {
                    intdigits++;
                    uch = chptr[NibbleIndex / 2];
                    c = toupper(c);
                    uch1 = (c >= 'A') ? c - 'A' + 10 : c - '0';
                    if (NibbleIndex % 2)
                        uch |= uch1;
                    else
                        uch |= (unsigned char)(uch1 << 4);
                    chptr[NibbleIndex++ / 2] = uch;
                    c = fetch();
                    break;
                }
                c = fetch();
                break;

            case hex_frac_digit_loop:
                if (!isxdigit(c))
                {
                    hex_scan_state = hex_sig_end;
                    break;
                }
                if (intdigits < maxdigits)
                {
                    uch = chptr[NibbleIndex / 2];
                    c = toupper(c);
                    uch1 = (c >= 'A') ? c - 'A' + 10 : c - '0';
                    if (NibbleIndex % 2)
                        uch |= uch1;
                    else
                        uch |= (unsigned char)(uch1 << 4);
                    chptr[NibbleIndex++ / 2] = uch;
                    c = fetch();
                    break;
                }
                c = fetch();
                break;

            case hex_sig_end:
                if (toupper(c) == 'P')
                {
                    hex_scan_state = hex_exp_start;
                    c = fetch();
                    break;
                }
                scan_state = finished;
                break;

            case hex_exp_start:
                if (c == '-')
                    exp_negsign = 1;
                else if (c != '+')
                {
                    unfetch(c);
                    count--;
                }
                hex_scan_state = hex_leading_exp_digit;
                c = fetch();
                break;

            case hex_leading_exp_digit:
                if (!isdigit(c))
                {
                    scan_state = failure;
                    break;
                }
                if (c == '0')
                {
                    hex_scan_state = hex_leading_exp_zeroes;
                    c = fetch();
                    break;
                }
                hex_scan_state = hex_exp_digit_loop;
                break;

            case hex_leading_exp_zeroes:
                if (c == '0')
                {
                    c = fetch();
                    break;
                }
                hex_scan_state = hex_exp_digit_loop;
                break;

            case hex_exp_digit_loop:
                if (!isdigit(c))
                {
                    scan_state = finished;
                    break;
                }
                expsign = expsign * 10 + (c - '0');
                if (exp_value > 0x7FFF)
                    *overflow = 1;
                c = fetch();
                break;
            }
            break;
        }
    }

    if (scan_state != hex_state ? !success(scan_state) : !hex_success(count, hex_scan_state))
    {
        count = 0;
        *chars_scanned = 0;
    }
    else
    {
        count--;
        *chars_scanned = count + spaces;
    }

    unfetch(c);

    if (hex_scan_state == not_hex)
    {
        if (exp_negative)
            exp_value = -exp_value;
        {
            int n = d.sig.length;
            unsigned char *p = &d.sig.text[n];

            while (n-- && *--p == '0')
                exp_adjust++;
            d.sig.length = n + 1;
            if (d.sig.length == 0)
                d.sig.text[d.sig.length++] = '0';
        }
        if (exp_value < -308 || exp_value > 308)
        {
            if (*overflow == 0 && d.sig.text[0] == '0' && d.sig.text[1] == 0)
                return 0.0;
            *overflow = 1;
        }
        exp_value += exp_adjust;
        if (*overflow)
        {
            if (exp_negative)
                return 0.0;
            else
                return sig_negative ? -HUGE_VAL : HUGE_VAL;
        }
        d.exp = (short)exp_value;
        result = func_0209739C(&d);
        if (result != 0.0 && result < 2.2250738585072014e-308)
        {
            *overflow = 1;
        }
        else if (result > 1.7976931348623157e+308)
        {
            *overflow = 1;
            result = HUGE_VAL;
        }
        if (sig_negative && success(scan_state))
            result = -result;
        return result;
    }
    else
    {
        double hexresult;
        unsigned long ui2;
        unsigned long ch2;
        unsigned char *p = (unsigned char *)&hexresult;
        unsigned char hch;

        if (exp_negsign)
            expsign = -expsign;
        expsign += intdigits * 4;
        hch = mantissa[0];
        for (ui = 0; ui < 4 && !(hch & (0x80 >> ui)); ui++)
            expsign--;
        expsign--;
        if ((chindex = ++ui) != 0)
        {
            uch1 = 0;
            for (chptr = mantissa + 7; chptr >= mantissa; chptr--)
            {
                hch = *chptr;
                *chptr = (hch << chindex) | uch1;
                uch1 = hch >> (8 - chindex);
            }
        }
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        for (ui2 = 0, ch2 = 12; ui2 < 52; ui2 += 8)
        {
            hch = mantissa[ui2 / 8];
            if (ui2 + 8 > 52)
                hch &= 0xff << (52 - ui2);
            NibbleIndex = ch2 % 8;
            p[ch2 / 8] |= (unsigned char)(hch >> NibbleIndex);
            ch2 += 8;
            p[ch2 / 8] |= (unsigned char)(hch << (8 - NibbleIndex));
        }
        expsign += exp_value + 0x3FF;
        if (expsign & ~0x7FF)
        {
            *overflow = 1;
            return 0.0;
        }
        p[0] |= (unsigned)(expsign << 21) >> 25;
        p[1] |= (unsigned)(expsign << 21) >> 17;
        if (sig_negative)
            p[0] |= 0x80;
        for (NibbleIndex = 0; NibbleIndex < 4; NibbleIndex++)
        {
            hch = p[NibbleIndex];
            p[NibbleIndex] = p[7 - NibbleIndex];
            p[7 - NibbleIndex] = hch;
        }
        return *(double *)p;
    }
}

typedef unsigned long long u64;

extern int func_020946D8(u32 *p, u32 a1, u32 a2);
extern u32 _u32_div_f(u32 a, u32 b);
u64 func_02095AA4(u32 a0, u32 *a1);
int func_02095B2C(char *path);
u32 func_02095B3C(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
u32 func_02095EAC(u32 a0, u32 *a1, u32 mode);
extern u32 g_02153FAC;

/*
 * PROMOTED from src/pending/ with no change to the C (lane r5c, 2026-09-19):
 * the park's only blocker was the PC24 at +0x34, and 0x02094B8C is now a
 * layout/runtime_arm9.txt entry (_msl_scanf_strtod_core), so that site
 * attests as `runtime` and every relocation resolves:
 *
 *   +0034 PC24 func_02094B8C   -> 02094B8C  [runtime x1, e.g. 02094B8C]
 *   +0058 PC24 func_0209A504   -> 0209A504  [label x15, e.g. 02093310]
 *   +0080 ABS32 func_020946D8  -> 020946D8  [literal x15, e.g. 02095F38]
 *   +0084 ABS32 g_02153FAC     -> 02153FAC  [literal x35, e.g. 02091D34]
 *
 * EXACT* and not EXACT: the compiled body is 136 bytes and the listing extent
 * is 152, because the follower at 0x02095B2C is the linker stub
 * (`ldr ip,[pc,#4]; mov r1,#0; bx ip; .word 0x02095AA4`), which carries no
 * func_ label and is not producible from C, so the inferred extent runs long
 * over it.  No byte inside the compared range differs.
 */
u64 func_02095AA4(u32 a0, u32 *a1)
{
    u32 buf[4];
    u64 r;

    buf[1] = 0;
    buf[0] = a0;
    r = ((u64 (*)(u32, u32, u32 *, u32 *, u32 *))func_02094B8C)(0x7FFFFFFFu, (u32)func_020946D8, buf, &buf[3], &buf[2]);
    if (a1 != 0)
        *a1 = a0 + buf[3];
    ((void (*)(u32, u32))func_0209A504)((u32)r, (u32)(r >> 32));
    if (buf[2] != 0)
        g_02153FAC = 0x22;
    return r;
}

/*
 * sdk:      FATFS_FormatDrive (libfatfs.TWL.HYB.a fatfs_api.o)
 */
int func_02095B2C(char *path)
{
    return func_02095AA4((u32)path, 0);
}

#define isspace(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x100))

#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))

#define isalpha(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x1))

#define toupper(c) (((c) < 0 || (c) >= 0x80) ? (c) : __upper_map[c])

enum { dec_start = 1, check_for_zero = 2, leading_zero = 4, need_digit = 8,
       digit_loop = 16, dec_finished = 32, dec_failure = 64 };

#undef final_state
#define final_state(s) ((s) & (dec_finished | dec_failure))

#undef success
#define success(s)     ((s) & (leading_zero | digit_loop | dec_finished))

#define fetch()        (count++, (*ReadProc)(ReadProcArg, 0, 0))

#define unfetch(c)     (*ReadProc)(ReadProcArg, c, 1)

/*
 * MSL __strtoul: the scan-state machine every strtol/strtoul/atoi entry
 * drives (func_02095EAC and func_02095F40 are two of its wrappers).  The
 * source is the Metrowerks one nearly verbatim: the power-of-two scan
 * states (start 1 .. failure 0x40, `tst #0x60` = final_state, `tst #0x34`
 * = success), fetch() as `(count++, ReadProc(arg, 0, 0))` and unfetch as
 * `ReadProc(arg, c, 1)`, the `c = fetch(); count--; spaces++;` whitespace
 * skip, and the <ctype.h> macros written as `(c < 0 || c >= 0x80) ? 0 :
 * __ctype_map[c] & bit` -- mwcc folds that pair of signed tests into the
 * image's single unsigned `cmp #0x80 / movhs`.  Bits: 0x100 space, 8 digit,
 * 1 alpha; __upper_map is the 128-byte toupper table sitting directly below
 * __ctype_map.  EOF and ULONG_MAX share the one `mvn fp, #0` register.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02095B3C.c \
 *       --func func_02095B3C --addr 0x02095B3C --cc 1.1p1 --arm
 *   EXACT, 880 bytes, 4 relocation sites, all resolved.
 */
u32 func_02095B3C(int base, int max_width, int (*ReadProc)(void *, int, int),
                  void *ReadProcArg, int *chars_scanned, int *negative,
                  int *overflow)
{
    int scan_state = dec_start;
    int count = 0;
    int spaces = 0;
    u32 value = 0;
    u32 value_max = 0;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1)
        scan_state = dec_failure;
    else
        c = fetch();

    if (base != 0)
        value_max = 0xFFFFFFFFu / base;

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
        case dec_start:
            if (isspace(c)) {
                c = fetch();
                count--;
                spaces++;
                break;
            }
            if (c == '+') {
                c = fetch();
            } else if (c == '-') {
                c = fetch();
                *negative = 1;
            }
            scan_state = check_for_zero;
            break;
        case check_for_zero:
            if (base == 0 || base == 16) {
                if (c == '0') {
                    scan_state = leading_zero;
                    c = fetch();
                    break;
                }
            }
            scan_state = need_digit;
            break;
        case leading_zero:
            if (c == 'X' || c == 'x') {
                base = 16;
                scan_state = need_digit;
                c = fetch();
                break;
            }
            if (base == 0)
                base = 8;
            scan_state = digit_loop;
            break;
        case need_digit:
        case digit_loop:
            if (base == 0)
                base = 10;
            if (!value_max)
                value_max = 0xFFFFFFFFu / base;
            if (isdigit(c)) {
                if ((c -= '0') >= base) {
                    if (scan_state == digit_loop)
                        scan_state = dec_finished;
                    else
                        scan_state = dec_failure;
                    c += '0';
                    break;
                }
            } else if (!isalpha(c) || (toupper(c) - 'A' + 10) >= base) {
                if (scan_state == digit_loop)
                    scan_state = dec_finished;
                else
                    scan_state = dec_failure;
                break;
            } else {
                c = toupper(c) - 'A' + 10;
            }
            if (value > value_max)
                *overflow = 1;
            value *= base;
            if (c > (0xFFFFFFFFu - value))
                *overflow = 1;
            value += c;
            scan_state = digit_loop;
            c = fetch();
            break;
        }
    }

    if (!success(scan_state)) {
        count = value = 0;
        *chars_scanned = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }
    unfetch(c);
    return value;
}

/*
 * MSL strtoul: the unsigned member of the strtoX wrapper family over the
 * scanner core at 0x02095B3C.  Four lanes and twenty-five spellings left this
 * at one instruction out (+0x70, `mvnne r0, #0` against 1.1p1's
 * `subne r0, r1, #0x23` fold from the 0x22 errno value) because every one of
 * them RETURNED the -1 from inside the error block.  The MSL source does not:
 *
 *     if (overflow) { value = ULONG_MAX; errno = ERANGE; }
 *     else if (negative) value = -value;
 *     return value;
 *
 * The -1 is assigned to the result variable BEFORE the errno store, the
 * negation is an ELSE-IF, and there is one return.  Under that shape the
 * value is a definition of `r` rather than a return constant and the back
 * end rematerialises it with `mvn`; the same compiler, no pin.  The return
 * type is u32 (unsigned long) and the core's return is u32 as well.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02095EAC.c \
 *       --func func_02095EAC --addr 0x02095EAC --cc 1.1p1 --arm
 *   EXACT, 148 bytes, 3 relocation sites, all resolved.
 */
u32 func_02095EAC(u32 a0, u32 *a1, u32 mode)
{
    u32 len;
    u32 sign;
    u32 err;
    u32 buf[2];
    u32 r;

    buf[0] = a0;
    buf[1] = 0;
    r = func_02095B3C(mode, 0x7FFFFFFFu, (int (*)(void *, int,  int))((u32)func_020946D8), buf, (int *)(&len), (int *)(&sign), (int *)(&err));
    if (a1 != 0)
        *a1 = a0 + len;
    if (err != 0) {
        r = 0xFFFFFFFFu;
        g_02153FAC = 0x22;
    } else if (sign != 0)
        r = -r;
    return r;
}

#include "../../matched/include/Obj00749.h"

typedef int s32;

typedef long long s64;

extern u32 func_02095B3C(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
s32 func_02095F40(u32 a0, u32 *a1, u32 a2);
u64 func_02096004(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
s64 func_020963F8(u32 a0, u32 *a1, u32 a2);
int func_020964E0(u32 a0);
long long func_020964F4(u32 a0);
int func_02096508(u8 *p, int v);
int func_02096578(const u16 *s);
u16 *func_02096594(u16 *d, const u16 *s);

/*
 * The 32-bit member of the decimal-to-integer family (func_02095EAC,
 * func_020963F8 are its siblings and differ only in their callee and in the
 * width of the clamped result).  It runs the parser at 0x02095B3C over a
 * five-word working buffer with the sign flag 0x7FFFFFFF and the default
 * radix, stores the end-of-digits pointer through the optional out parameter,
 * and clamps the parsed magnitude to the s32 range: with a cleared sign a
 * magnitude above 0x7FFFFFFF does not fit and with a set sign the magnitude
 * may reach 0x80000000, after which the result is negated.
 *
 * Two things pin the source shape:
 *
 *  - The three range conditions have to be ONE disjunction.  Written as an
 *    if/else the shared error block is laid out after the final return and
 *    the whole tail shifts; as `||` the block lands exactly where the
 *    original has it, between the second range test and the negation, and
 *    the second test's branch inverts to `bls` over the error block.
 *  - The saturating values are INT_MIN for a set sign and INT_MAX for a
 *    cleared one.  mwcc materialises the pair as `movne r0, #0x80000000` /
 *    `mvneq r0, #0x80000000`, and the second is a `mvn` of 0x80000000, i.e.
 *    0x7FFFFFFF, not the same value written twice: a source whose two arms
 *    are equal is folded to a single `mov` and loses both the compare and
 *    twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02095F40.c \
 *       --func func_02095F40 --addr 0x02095F40 --cc 1.1p1 --arm
 *   EXACT, 196 bytes, 3 relocation sites, all resolved.
 */
s32 func_02095F40(u32 a0, u32 *a1, u32 a2)
{
    u32 buf[5];
    s32 r;
    s32 v;

    buf[0] = a0;
    buf[1] = 0;
    r = (s32)func_02095B3C(a2, 0x7FFFFFFFu, (int (*)(void *, int,  int))func_020946D8, buf,
                           (int *)(&buf[4]), (int *)(&buf[3]), (int *)(&buf[2]));
    if (a1 != 0)
        *a1 = a0 + buf[4];
    if (buf[2] != 0 ||
        (buf[3] == 0 && (u32)r > 0x7FFFFFFFu) ||
        (buf[3] != 0 && (u32)r > 0x80000000u)) {
        v = (buf[3] != 0) ? (s32)0x80000000 : (s32)0x7FFFFFFF;
        g_02153FAC = 0x22;
        return v;
    }
    if (buf[3] != 0)
        r = -r;
    return r;
}

#define isspace(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x100))

#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))

#define isalpha(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x1))

#define toupper(c) (((c) < 0 || (c) >= 0x80) ? (c) : __upper_map[c])

#define fetch()        (count++, (*ReadProc)(ReadProcArg, 0, 0))

#define unfetch(c)     (*ReadProc)(ReadProcArg, c, 1)

/*
 * MSL __strtoull: the 64-bit twin of src/matched/func_02095B3C.c (__strtoul),
 * driven by the strtoll wrapper func_020963F8.  Identical source with
 * `value`/`value_max` widened to unsigned long long and ULLONG_MAX in both
 * places; ULLONG_MAX / base goes through _ll_udiv with the int base
 * sign-extended (`asr r3, sb, #0x1f`), and the constant -1 lives in one stack
 * slot (sp+0x18) that serves both EOF and ULLONG_MAX.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02096004.c \
 *       --func func_02096004 --addr 0x02096004 --cc 1.1p1 --arm
 *   EXACT, 1012 bytes, 4 relocation sites, all resolved.
 */
u64 func_02096004(int base, int max_width, int (*ReadProc)(void *, int, int),
                  void *ReadProcArg, int *chars_scanned, int *negative,
                  int *overflow)
{
    int scan_state = dec_start;
    int count = 0;
    int spaces = 0;
    u64 value = 0;
    u64 value_max = 0;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1)
        scan_state = dec_failure;
    else
        c = fetch();

    if (base != 0)
        value_max = 0xFFFFFFFFFFFFFFFFull / base;

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
        case dec_start:
            if (isspace(c)) {
                c = fetch();
                count--;
                spaces++;
                break;
            }
            if (c == '+') {
                c = fetch();
            } else if (c == '-') {
                c = fetch();
                *negative = 1;
            }
            scan_state = check_for_zero;
            break;
        case check_for_zero:
            if (base == 0 || base == 16) {
                if (c == '0') {
                    scan_state = leading_zero;
                    c = fetch();
                    break;
                }
            }
            scan_state = need_digit;
            break;
        case leading_zero:
            if (c == 'X' || c == 'x') {
                base = 16;
                scan_state = need_digit;
                c = fetch();
                break;
            }
            if (base == 0)
                base = 8;
            scan_state = digit_loop;
            break;
        case need_digit:
        case digit_loop:
            if (base == 0)
                base = 10;
            if (!value_max)
                value_max = 0xFFFFFFFFFFFFFFFFull / base;
            if (isdigit(c)) {
                if ((c -= '0') >= base) {
                    if (scan_state == digit_loop)
                        scan_state = dec_finished;
                    else
                        scan_state = dec_failure;
                    c += '0';
                    break;
                }
            } else if (!isalpha(c) || (toupper(c) - 'A' + 10) >= base) {
                if (scan_state == digit_loop)
                    scan_state = dec_finished;
                else
                    scan_state = dec_failure;
                break;
            } else {
                c = toupper(c) - 'A' + 10;
            }
            if (value > value_max)
                *overflow = 1;
            value *= base;
            if (c > (0xFFFFFFFFFFFFFFFFull - value))
                *overflow = 1;
            value += c;
            scan_state = digit_loop;
            c = fetch();
            break;
        }
    }

    if (!success(scan_state)) {
        count = value = 0;
        *chars_scanned = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }
    unfetch(c);
    return value;
}

/*
 *           range: the only branch to it anywhere in the image is the bl in
 *           this function (it has a func_ label, but the label class needs a
 *           branch from outside the compared range as well), so that one
 *           relocation stays wildcarded and the file cannot be EXACT.  The
 *           file becomes EXACT* the day 0x02096004 gets a shard entry.
 *
 * bcd_to_s64: the 64-bit sibling of func_02095EAC/func_02095F40.  It hands
 * the decimal parser func_02096004 a working buffer, a pointer to the first
 * byte after the parsed digits and a sign flag, then clamps the parsed
 * magnitude to the s64 range: with a zero sign a magnitude above
 * 0x7FFFFFFFFFFFFFFF does not fit, with a set sign the magnitude may reach
 * 0x8000000000000000, and the result is negated for the sign.
 *
 * The error path returns the saturating extremes of the original's own sign
 * flag, which is why the reserved word g_02153FAC is set to 0x22 there.
 *
 * The bounded-magnitude test has to be one disjunction: written as an
 * if/else the shared error block is laid out after the final return and the
 * whole tail moves (66 bytes), while `||` over the three conditions places it
 * exactly where the original has it, between the second range test and the
 * negation.  The `-r` and the return then share one epilogue.
 *
 * trailing star: the listing's extent for this address runs to 0x02096508
 * because everything between the last code byte (0x020964D8) and the next
 * label is unlabelled: this function's own two-word pool at 0x020964D8 and
 * two sixteen-byte argument-defaulting thunks at 0x020964E0 and 0x020964F4
 * (`ldr ip,[pc,#8]; mov r1,#0; mov r2,#0xa; bx ip` -> 0x02095F40 and
 * 0x020963F8).  Needs seeds for both thunk addresses in
 * layout/function_starts.txt; neither is producible from C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020963F8.c \
 *       --func func_020963F8 --addr 0x020963F8 --cc 1.1p1 --arm
 *   MATCH* with no concrete byte differing; EXACT* once the symbols above
 *   are declared and the two thunk addresses are labelled.
 */
s64 func_020963F8(u32 a0, u32 *a1, u32 a2)
{
    u32 buf[5];
    s64 r;
    s64 v;

    buf[0] = a0;
    buf[1] = 0;
    r = (s64)func_02096004(a2, 0x7FFFFFFFu, (int (*)(void *, int,  int))func_020946D8, buf,
                           (int *)(&buf[4]), (int *)(&buf[3]), (int *)(&buf[2]));
    if (a1 != 0)
        *a1 = a0 + buf[4];
    if (buf[2] != 0 ||
        (buf[3] == 0 && (u64)r > 0x7FFFFFFFFFFFFFFFULL) ||
        (buf[3] != 0 && (u64)r > 0x8000000000000000ULL)) {
        v = (buf[3] != 0) ? (s64)0x8000000000000000ULL
                          : (s64)0x7FFFFFFFFFFFFFFFULL;
        g_02153FAC = 0x22;
        return v;
    }
    if (buf[3] != 0)
        r = -r;
    return r;
}

/*
 * Argument-defaulting thunk: call the s32 decimal parser func_02095F40 with
 * a null out-pointer and radix 10.  It is the `atoi` entry point the overlay
 * error parser uses.  Reproducible from C as an ordinary tail call; the
 * previous note that claimed otherwise was wrong.
 */
int func_020964E0(u32 a0)
{
    return func_02095F40(a0, 0, 10);
}

/*
 * Argument-defaulting thunk: call the s64 decimal parser func_020963F8 with
 * a null out-pointer and radix 10.  Reproducible from C as an ordinary tail
 * call; the previous note that claimed otherwise was wrong.
 */
long long func_020964F4(u32 a0)
{
    return func_020963F8(a0, 0, 10);
}

/*
 * note:     the trailing star is the two unlabelled leaves that follow in the
 *           word run -- func_02096578 (0x02096578) and func_02096594
 *           (0x02096594), both matched in this window -- so the listing extent
 *           runs to 0x020965B4.  Wants seeds for both addresses in
 *           layout/function_starts.txt.
 */
int func_02096508(u8 *p, int v)
{
    u32 f;

    if (p == 0 || ((((struct Obj00749 *)p)->f4 << 22) >> 29) == 0)
        return 0;

    f = ((struct Obj00749 *)p)->f4;
    switch ((f << 20) >> 30) {
    case 0:
        if (v > 0)
            ((struct Obj00749 *)p)->f4 = (f & ~0xc00u) | 0x800u;
        else if (v < 0)
            ((struct Obj00749 *)p)->f4 = (f & ~0xc00u) | 0x400u;
        break;
    case 1:
        v = -1;
        break;
    case 2:
        v = 1;
        break;
    }
    return v;
}

int func_02096578(const u16 *s)
{
    int n = -1;
    u16 c;

    do {
        c = *s++;
        n++;
    } while (c != 0);
    return n;
}

/*
 * note:     the second of the two unlabelled leaves trailing func_02096508's
 *           word run (the first is func_02096578, its own file).  It is
 *           func_02096578's wide-string copy counterpart: a `do { t = p;
 *           *p = *s++; p++; } while (*t);` loop, which is what keeps the
 *           `mov ip, r3` / `ldrh r2, [ip]` re-read of the character just
 *           stored -- the store and the loop test go through two different
 *           pointer variables, so the value is not forwarded into the compare.
 */
u16 *func_02096594(u16 *d, const u16 *s)
{
    u16 *r = d;
    u16 *p = d;
    u16 *t;

    do {
        t = p;
        *p = *s++;
        p++;
    } while (*t);
    return r;
}

#include "../../matched/include/Obj11699.h"

typedef struct {
    u8 unk00[4];
    u8 unk04;
} Obj02096670;

extern int func_020965B4(u8 *p, int i);
int sub_020965B4(u8 *p, int i);
void func_02096620(u8 *p, int idx);
void func_02096670(Obj02096670 *p, int v);
void func_020966B0(decimal2 *result, u64 val);

int sub_020965B4(u8 *p, int i)
{
    u8 *q = p + 5 + i;

    if (q[0] > 5) return 1;
    if (q[0] < 5) return -1;
    for (q++; q < p + 5 + p[4]; q++) {
        if (*q) return 1;
    }
    return ((p + 5)[i - 1] & 1) ? 1 : -1;
}

void func_02096620(u8 *p, int idx)
{
    u8 *base = p + 5;
    u8 *cur = base + idx - 1;

    for (;;) {
        if (*cur < 9) {
            *cur = *cur + 1;
            return;
        }
        if (cur == base) {
            *cur = 1;
            ((struct Obj11699 *)p)->f2 = ((struct Obj11699 *)p)->f2 + 1;
            return;
        }
        *cur = 0;
        cur--;
    }
}

/*
 * closed:   blocker func_020965B4 is now a manifest entry (matched class)
 *
 * Clamps the new value against the count byte at +4, records it and, when the
 * worker returns non-negative, propagates it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02096670.c \
 *       --func func_02096670 --addr 0x02096670 --cc 1.1p1 --arm
 */
void func_02096670(Obj02096670 *p, int v)
{
    int r;

    if (v <= 0) {
        return;
    }
    if (v >= p->unk04) {
        return;
    }
    r = func_020965B4((u8 *)p, v);
    p->unk04 = v;
    if (r < 0) {
        return;
    }
    func_02096620((u8 *)p, v);
}

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
 *   python3 tools/match.py one --src src/matched/func_020966B0.c \
 *       --func func_020966B0 --addr 0x020966B0 --cc 1.1p1 --arm
 *   EXACT, 196 bytes, 2 relocation sites, all resolved.
 */
void func_020966B0(decimal2 *result, u64 val)
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

struct P020968F4 {
    u8  f00;
    u8  pad01;
    u16 f02;
    u8  f04;
    u8  f05[32];
};

extern void func_02096620(u8 *p, int idx);
void func_02096774(decimal2 *result, const decimal2 *x, const decimal2 *y);

/*
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
 */
void func_02096774(decimal2 *result, const decimal2 *x, const decimal2 *y)
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
        func_02096620((u8 *)result, result->sig.length);
    }
}

/*
 * Decimal string to the packed digit record the bcd family shares: clear the
 * flag byte, store the caller's halfword parameter at +2, convert up to 32
 * digits into the byte array at +5, then decide whether the value is in range.
 * A string whose first unconsumed character is below '5' is accepted as is,
 * above '5' is rejected through func_02096620, and exactly '5' is accepted
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
 *   python tools/match.py one --src src/matched/func_020968F4.c \
 *       --func func_020968F4 --addr 0x020968F4 --cc 1.1p1 --arm
 *   EXACT, 156 bytes, 1 relocation site, resolved.
 */
void func_020968F4(struct P020968F4 *p, const u8 *s, u16 v)
{
    int i;
    u8 c;

    p->f02 = v;
    p->f00 = 0;
    i = 0;
    while (i < 32 && *s != 0) {
        p->f05[i] = (u8)(*s++ - '0');
        i++;
    }
    p->f04 = (u8)i;
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
    if ((p->f05[i - 1] & 1) == 0)
        return;
tail:
    func_02096620((u8 *)p, p->f04);
}

typedef struct {
    u8  pad00[2];
    s16 f02;
    volatile u8 f04;
    u8  f05[];
} Str;

typedef void (*DecFromStr)(decimal2 *d, const char *s, s16 exp);
void func_02096990(decimal2 *result, long exp);
int func_02096D10(Str *a, Str *b);
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

/*
 * MSL __two_exp (ansi_fp.c): 2^exp as a decimal record.  A switch over the
 * tabulated exponents -64, -53, -32, -16 and -8..8, each arm handing a digit
 * string and a decimal exponent to __str2dec (func_020968F4); every other
 * exponent recurses on exp/2 (spelled the MSL way,
 * `((long)((0x80000000UL & exp) >> 31) + exp) >> 1`), squares the half with
 * __timesdec (func_02096774), and on an odd exponent copies the result to a
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
 *   python3 tools/match.py one --src src/matched/func_02096990.c \
 *       --func func_02096990 --addr 0x02096990 --cc 1.1p1 --arm
 *   EXACT, 896 bytes, 46 relocation sites, all resolved.
 */
void func_02096990(decimal2 *result, long exp)
{
    switch (exp) {
    case -64:
        ((DecFromStr)func_020968F4)(result, s_020A8ABC, -20);
        return;
    case -53:
        ((DecFromStr)func_020968F4)(result, s_020A8AEC, -16);
        return;
    case -32:
        ((DecFromStr)func_020968F4)(result, s_020A8B14, -10);
        return;
    case -16:
        ((DecFromStr)func_020968F4)(result, s_020A8B2C, -5);
        return;
    case -8:
        ((DecFromStr)func_020968F4)(result, s_020A8B3C, -3);
        return;
    case -7:
        ((DecFromStr)func_020968F4)(result, s_020A8B44, -3);
        return;
    case -6:
        ((DecFromStr)func_020968F4)(result, s_020A8B4C, -2);
        return;
    case -5:
        ((DecFromStr)func_020968F4)(result, s_020A8B54, -2);
        return;
    case -4:
        ((DecFromStr)func_020968F4)(result, s_020A8B5C, -2);
        return;
    case -3:
        ((DecFromStr)func_020968F4)(result, s_020A8B60, -1);
        return;
    case -2:
        ((DecFromStr)func_020968F4)(result, s_020A8B64, -1);
        return;
    case -1:
        ((DecFromStr)func_020968F4)(result, s_020A8B68, -1);
        return;
    case 0:
        ((DecFromStr)func_020968F4)(result, s_020A8B6C, 0);
        return;
    case 1:
        ((DecFromStr)func_020968F4)(result, s_020A8B70, 0);
        return;
    case 2:
        ((DecFromStr)func_020968F4)(result, s_020A8B74, 0);
        return;
    case 3:
        ((DecFromStr)func_020968F4)(result, s_020A8B78, 0);
        return;
    case 4:
        ((DecFromStr)func_020968F4)(result, s_020A8B7C, 1);
        return;
    case 5:
        ((DecFromStr)func_020968F4)(result, s_020A8B80, 1);
        return;
    case 6:
        ((DecFromStr)func_020968F4)(result, s_020A8B84, 1);
        return;
    case 7:
        ((DecFromStr)func_020968F4)(result, s_020A8B88, 2);
        return;
    case 8:
        ((DecFromStr)func_020968F4)(result, s_020A8B8C, 2);
        return;
    }

    {
        decimal2 x2, temp;

        func_02096990(&x2, ((long)((0x80000000UL & exp) >> 31) + exp) >> 1);
        func_02096774(result, &x2, &x2);
        if (exp & 1) {
            temp = *result;
            if (exp > 0)
                ((DecFromStr)func_020968F4)(&x2, s_020A8B70, 0);
            else
                ((DecFromStr)func_020968F4)(&x2, s_020A8B68, -1);
            func_02096774(result, &temp, &x2);
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
int func_02096D10(Str *a, Str *b)
{
    Str *p;
    int i, n;
    int la, lb;

    if (a->f05[0] == 0)
        return b->f05[0] == 0;
    if (b->f05[0] == 0)
        return a->f05[0] == 0;
    if (a->f02 != b->f02)
        goto fail;
    i = 0;
    la = a->f04;
    lb = b->f04;
    n = la;
    if (la > lb)
        n = lb;
    for (; i < n; i++) {
        if (a->f05[i] != b->f05[i])
            return 0;
    }
    p = a;
    if (n == la)
        p = b;
    for (; i < p->f04; i++) {
        if (p->f05[i] != 0)
            return 0;
    }
    return 1;
fail:
    return 0;
}

int func_02096DF0(Str *a, Str *b);
void func_02096ED0(decimal2 *z, const decimal2 *x, const decimal2 *y);

/*
 * The ordering sibling of func_02096D10: same length-prefixed string object
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
 *     lb) { do {...} while (i < b->f04); }`.  The entry test compares against
 *     the cached lb (r4) while the back edge re-reads b->f04, which is what
 *     distinguishes this shape from `for (; i < lb; i++)` (whose back edge
 *     would use the cached value and lose the volatile read).
 *   - `if (a->f02 != b->f02) goto keycmp; ... keycmp: return a->f02 < b->f02;`
 *     -- the s16 tie-break sits out of line after the final `return 0`, as a
 *     single `if (...) return ...;` the front end if-converts it inline and
 *     the whole tail shifts.
 *   - `int lb, la;`: declaration order decides which of the two lengths gets
 *     r4 and which r5; the `la, lb` order swaps them and costs seven bytes.
 */
int func_02096DF0(Str *a, Str *b)
{
    int i, n;
    int lb, la;

    if (a->f05[0] == 0)
        return b->f05[0] != 0;
    if (b->f05[0] == 0)
        return 0;
    if (a->f02 != b->f02)
        goto keycmp;
    i = 0;
    la = a->f04;
    lb = b->f04;
    n = la;
    if (la > lb)
        n = lb;
    for (; i < n; i++) {
        if (a->f05[i] < b->f05[i])
            return 1;
        if (b->f05[i] < a->f05[i])
            return 0;
    }
    if (n == la && i < lb) {
        do {
            if (b->f05[i] != 0)
                return 1;
            i++;
        } while (i < b->f04);
    }
    return 0;
keycmp:
    return a->f02 < b->f02;
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
 *   python3 tools/match.py one --src src/matched/func_02096ED0.c \
 *       --func func_02096ED0 --addr 0x02096ED0 --cc 1.1p1 --arm
 *   EXACT, 672 bytes, 0 relocation sites.
 */
void func_02096ED0(decimal2 *z, const decimal2 *x, const decimal2 *y)
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

typedef struct {
    u8  f0;
    u8  f1;
    s16 f2;
    u8  f4;
    u8  buf[33];
} DB;

extern int func_020921D8(double v);
extern int func_020921F4(double v);
extern double func_0209AF34(double a, double b);
extern double func_0209A6E8(double x, int *eptr);
extern u32 func_02092144(u64 x);
struct decimal2;
extern void func_02096990(struct decimal2 *result, long exp);
extern double func_0209A7A8(double x, int n);
extern u64 func_0209C554(double x);
extern void func_020966B0(struct decimal2 *result, unsigned long long val);
extern void func_02096774(struct decimal2 *result, const struct decimal2 *x, const struct decimal2 *y);

/*
 * MSL `__num2dec` -- convert a double to the 38-byte packed decimal record
 * (DB) that this family's other functions add, subtract, multiply and print.
 * The record is { u8 sign; u8 pad; s16 exp10; u8 ndigits; u8 digits[33] }.
 *
 * Three paths:
 *   1. x == 0.0                 -> sign, exp 0, one digit, digit = 0.
 *   2. NaN or infinity          -> func_020921F4 (the MSL fpclassify: 1 = NaN,
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
 *      `func_02096990(&b, e - k)` builds the decimal record of 2^(e-k) (the
 *      recursive power-of-two formatter, dense switch over -32..+8), and
 *      `func_020966B0(&a, (u64)ldexp(f, k))` builds the decimal record of the
 *      exact integer mantissa.  `func_02096774(r, &a, &b)` multiplies the two
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
 *   python3 tools/match.py one --src src/matched/func_02097170.c \
 *       --func func_02097170 --addr 0x02097170 --cc 1.1p1 --arm
 *   EXACT, 384 bytes, 12 of 12 relocation sites resolved.
 */
void func_02097170(DB *r, double x)
{
    DB a;
    DB b;
    int e;
    u64 v;
    int k;
    double f;
    double g;
    u8 neg;

    neg = func_020921D8(x) != 0;
    if (x == 0.0) {
        r->f0 = neg;
        r->f2 = 0;
        r->f4 = 1;
        r->buf[0] = 0;
        return;
    }
    if (func_020921F4(x) <= 2) {
        r->f0 = neg;
        r->f2 = 0;
        r->f4 = 1;
        r->buf[0] = (func_020921F4(x) == 1) ? 0x4E : 0x49;
        return;
    }
    if (neg)
        x = func_0209AF34(0.0, x);
    f = func_0209A6E8(x, &e);
    g = f;
    v = *(u64 *)&g | 0x0010000000000000ULL;
    k = 0x35 - func_02092144((v & -v) - 1);
    func_02096990((struct decimal2 *)(&b), e - k);
    func_020966B0((struct decimal2 *)(&a), func_0209C554(func_0209A7A8(f, k)));
    func_02096774((struct decimal2 *)r, (const struct decimal2 *)(&a), (const struct decimal2 *)(&b));
    r->f0 = neg;
}

#include "../../matched/include/Obj16714.h"

void func_020972F0(const decform *f, double x, decimal *p)
{
    int n = f->digits;
    int i;

    func_02097170((DB *)p, x);
    if (p->sig.text[0] > 9)
        return;
    if (n > 0x20)
        n = 0x20;
    func_02096670((Obj02096670 *)p, n);
    while (p->sig.length < n)
        p->sig.text[p->sig.length++] = 0;
    p->exp -= (s16)(p->sig.length - 1);
    for (i = 0; i < p->sig.length; i++)
        p->sig.text[i] += 0x30;
}

/* ansi_fp.h */
double func_02097990(double x, int n);
extern const double pow_10[8];

#define FP_INFINITE 2

#define isinf(x) (func_020921F4(x) == FP_INFINITE)

extern const char s_020A8B90[];     /* "179769313486231580793728714053034151" */

extern double func_0209A368(double x, double y);                        /* copysign */
struct P020968F4;
extern void func_020968F4(struct P020968F4 *p, const u8 *s, u16 v);        /* __str2dec */
extern double func_0209AB80(double x, double y);                        /* pow */
extern double func_0209A7A8(double x, int n);                           /* ldexp */
extern int func_020921F4(double x);                                     /* __fpclassifyd */

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
double func_0209739C(const decimal2 *d)
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

            func_020968F4((struct P020968F4 *)(&max), (const u8 *)s_020A8B90, 308);
            if (func_02096DF0((Str *)&max, (Str *)&dec))
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
            decimal2 feval, feval2;
            decimal2 difflow, diffhigh;
            double guess;
            unsigned long long *ll = (unsigned long long *)&guess;
            int is_low = 0;

            func_02097170((DB *)&feval, first_guess);
            if (func_02096D10((Str *)&feval, (Str *)&dec))
                goto done;
            if (func_02096DF0((Str *)&feval, (Str *)&dec))
                is_low = 1;
            guess = first_guess;
            for (;;) {
                if (is_low) {
                    ++*ll;
                    if (isinf(guess))
                        goto done;
                } else
                    --*ll;
                func_02097170((DB *)&feval2, guess);
                if (is_low && !func_02096DF0((Str *)&feval2, (Str *)&dec))
                    break;
                if (!is_low && !func_02096DF0((Str *)&dec, (Str *)&feval2)) {
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
            if (func_02096D10((Str *)&difflow, (Str *)&diffhigh)) {
                if (*(unsigned long long *)&first_guess & 1)
                    first_guess = guess;
            } else if (!func_02096DF0((Str *)&difflow, (Str *)&diffhigh))
                first_guess = guess;
        }
done:
        if (dec.sign)
            first_guess = -first_guess;
        return first_guess;
    }
}

double func_02097990(double x, int n)
{
    int t;
    double v = func_0209A6E8(x, &t);
    t += n;
    return func_0209A7A8(v, t);
}
