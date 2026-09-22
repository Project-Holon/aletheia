/*
 * function: func_02093BDC
 * address:  0x02093BDC
 * packet:   pkt_020929E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH*
 *
 * blocker:  sole-ref/code or matched for func_020923C4 (memchr).  Every
 *           concrete byte is right (2220 bytes, home push through the pool);
 *           the one open site is the `bl 0x020923C4` of the %.*s path.  Its
 *           only caller image-wide is this call, and although memchr is
 *           byte-exact inside src/matched/unit_020923B0.c, that unit's shard
 *           entry (pkt_020923B0) lists only func_020923B0 as a member, so the
 *           `matched` class does not see 0x020923C4, and disasm.py has no
 *           label there (a leaf; it prints as .word).  Integrator fix: list
 *           func_020923C4 / func_020923F0 as members of unit_020923B0 in
 *           pkt_020923B0, or seed 0x020923C4 in layout/function_starts.txt
 *           (then sole-ref/code carries it).  No C change can close it.
 *
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
 *
 * symbols:
 *   func_020922CC  0x020922CC  arm
 *   func_020923C4  0x020923C4  arm
 *   func_020924DC  0x020924DC  arm
 *   func_020929E8  0x020929E8  arm
 *   func_02092C38  0x02092C38  arm
 *   func_02092F0C  0x02092F0C  arm
 *   func_020934CC  0x020934CC  arm
 *   func_0209477C  0x0209477C  arm
 *   func_02094750  0x02094750  arm
 *   func_02094A28  0x02094A28  arm
 *   s_020A8A70     0x020A8A70  data  a2
 *   s_020A8A74     0x020A8A74  data  a1
 */
typedef unsigned long size_t;
typedef long ptrdiff_t;
typedef long long intmax_t;
typedef unsigned short wchar_t;
typedef unsigned char uchar;
typedef uchar *va_list;
#define __va_size(t) ((sizeof(t) + 3) & ~3)
#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))

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

extern uchar *func_02094A28(const uchar *s, int c);                 /* strchr */
extern size_t func_0209477C(const uchar *s);                       /* strlen */
extern const uchar *func_020924DC(const uchar *s, va_list *arg, print_format *f); /* parse_format */
extern uchar *func_020929E8(long num, uchar *buff, print_format format);           /* long2str */
extern uchar *func_02092C38(long long num, uchar *buff, print_format format);      /* longlong2str */
extern uchar *func_020934CC(double num, uchar *buff, print_format format);         /* float2str */
extern uchar *func_02092F0C(double num, uchar *buff, print_format format);         /* double2hex */
extern void func_02094750(const uchar *msg, void *ptr, int error);               /* constraint violation */
extern int func_020922CC(uchar *dst, const wchar_t *src, size_t n);               /* wcstombs */
extern void *func_020923C4(const void *s, int c, size_t n);                       /* memchr */
extern wchar_t s_020A8A70[];  /* L"" */
extern uchar s_020A8A74[];     /* ""  */

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
