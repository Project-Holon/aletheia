/*
 * function: parse_format
 * address:  0x020924DC
 * packet:   pkt_02092120
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   __ctype_map  0x020A61DC  data  a2
 */
typedef unsigned char uchar;
typedef uchar *va_list;
#define __va_size(t) ((sizeof(t) + 3) & ~3)
#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))

extern const unsigned short __ctype_map[];
#define isdigit(c) ((unsigned int)(c) < 0x80 ? (__ctype_map[c] & 8) : 0)

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
