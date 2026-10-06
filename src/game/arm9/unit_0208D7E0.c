/*
 * file:     unit_0208D7E0.c
 * unit:     yes
 * function: func_0208D7E0, func_0208D80C, func_0208D834
 * address:  0x0208D7E0
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
 *   string_put_char    0x0208D708  arm
 *   string_fill_char   0x0208D734  arm
 *   string_put_string  0x0208D788  arm
 *   _ll_udiv           0x0209C00C  arm
 */
typedef char *va_list;

typedef unsigned long long u64;

typedef unsigned long u32;

typedef long long s64;

struct dst_string_tag {
    unsigned long len;
    char *cur;
    char *base;
};

extern void string_put_char(struct dst_string_tag *p, char c);
extern void string_fill_char(struct dst_string_tag *p, char c, int n);
extern void string_put_string(struct dst_string_tag *p, const char *s, int n);
int STD_TSPrintf(char *dst, const char *fmt, ...);
int OS_SNPrintf(char *dst, int n, const char *fmt, ...);
int STD_TVSNPrintf(char *dst, unsigned long len, const char *fmt, va_list vlist);

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))

#define va_end(v)


int STD_TSPrintf(char *dst, const char *fmt, ...)
{
    int r;
    va_list vlist;
    va_start(vlist, fmt);
    r = STD_TVSNPrintf(dst, 0x7FFFFFFF, fmt, vlist);
    va_end(vlist);
    return r;
}

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))

#define va_end(v)


int OS_SNPrintf(char *dst, int n, const char *fmt, ...)
{
    int r;
    va_list vlist;
    va_start(vlist, fmt);
    r = STD_TVSNPrintf(dst, n, fmt, vlist);
    va_end(vlist);
    return r;
}

#define __va_size(t) ((sizeof(t) + 3) & ~3)

#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))


enum {
    flag_blank = 0x001,
    flag_plus = 0x002,
    flag_sharp = 0x004,
    flag_minus = 0x008,
    flag_zero = 0x010,
    flag_l1 = 0x020,
    flag_h1 = 0x040,
    flag_l2 = 0x080,
    flag_h2 = 0x100,
    flag_unsigned = 0x1000
};


int STD_TVSNPrintf(char *dst, unsigned long len, const char *fmt, va_list vlist)
{
    char buf[24];
    int n_buf;
    char prefix[2];
    int n_prefix;
    const char *s = fmt;
    struct dst_string_tag str;

    str.len = len, str.cur = str.base = dst;

    while (*s) {
        if ((unsigned int)(((unsigned char)*s ^ 0x20) - 0xA1) < 0x3C) {
            string_put_char(&str, *s++);
            if (*s)
                string_put_char(&str, *s++);
        } else if (*s != '%') {
            string_put_char(&str, *s++);
        } else {
            int flag = 0, width = 0, precision = -1, radix = 10;
            char hex_char = 'a' - 10;
            const char *p_start = s;

            for (;;) {
                switch (*++s) {
                case '+':
                    if (s[-1] != ' ')
                        break;
                    flag |= flag_plus;
                    continue;
                case ' ':
                    flag |= flag_blank;
                    continue;
                case '-':
                    flag |= flag_minus;
                    continue;
                case '0':
                    flag |= flag_zero;
                    continue;
                }
                break;
            }

            if (*s == '*') {
                ++s, width = va_arg(vlist, int);
                if (width < 0)
                    width = -width, flag |= flag_minus;
            } else {
                while ((*s >= '0') && (*s <= '9'))
                    width = (width * 10) + *s++ - '0';
            }

            if (*s == '.') {
                ++s, precision = 0;
                if (*s == '*') {
                    ++s, precision = va_arg(vlist, int);
                    if (precision < 0)
                        precision = -1;
                } else {
                    while ((*s >= '0') && (*s <= '9'))
                        precision = (precision * 10) + *s++ - '0';
                }
            }

            switch (*s) {
            case 'h':
                if (*++s != 'h')
                    flag |= flag_h1;
                else
                    ++s, flag |= flag_h2;
                break;
            case 'l':
                if (*++s != 'l')
                    flag |= flag_l1;
                else
                    ++s, flag |= flag_l2;
                break;
            }

            switch (*s) {
            case 'd':
            case 'i':
                goto put_integer;
            case 'o':
                radix = 8;
                flag |= flag_unsigned;
                goto put_integer;
            case 'u':
                flag |= flag_unsigned;
                goto put_integer;
            case 'X':
                hex_char = 'A' - 10;
                goto put_hexadecimal;
            case 'x':
                goto put_hexadecimal;
            case 'p':
                flag |= flag_sharp;
                precision = 8;
                goto put_hexadecimal;
            case 'c':
                if (precision >= 0)
                    goto put_invalid;
                {
                    int c = va_arg(vlist, int);
                    width -= 1;
                    if (flag & flag_minus) {
                        string_put_char(&str, (char)c);
                        string_fill_char(&str, ' ', width);
                    } else {
                        char pad = (char)((flag & flag_zero) ? '0' : ' ');
                        string_fill_char(&str, pad, width);
                        string_put_char(&str, (char)c);
                    }
                    ++s;
                }
                break;
            case 's':
                {
                    int n_buf = 0;
                    const char *p_buf = va_arg(vlist, const char *);
                    if (precision < 0) {
                        while (p_buf[n_buf])
                            ++n_buf;
                    } else {
                        while ((n_buf < precision) && p_buf[n_buf])
                            ++n_buf;
                    }
                    width -= n_buf;
                    if (flag & flag_minus) {
                        string_put_string(&str, p_buf, n_buf);
                        string_fill_char(&str, ' ', width);
                    } else {
                        char pad = (char)((flag & flag_zero) ? '0' : ' ');
                        string_fill_char(&str, pad, width);
                        string_put_string(&str, p_buf, n_buf);
                    }
                    ++s;
                }
                break;
            case '%':
                if (p_start + 1 != s)
                    goto put_invalid;
                string_put_char(&str, *s++);
                break;
            default:
                goto put_invalid;

            put_invalid:
                string_put_string(&str, p_start, s - p_start);
                break;

            put_hexadecimal:
                radix = 16;
                flag |= flag_unsigned;
            put_integer:
                {
                    u64 val = 0;
                    n_prefix = 0;

                    if (flag & flag_minus)
                        flag &= ~flag_zero;
                    if (precision < 0)
                        precision = 1;
                    else
                        flag &= ~flag_zero;

                    if (flag & flag_unsigned) {
                        if (flag & flag_h2)
                            val = (unsigned char)va_arg(vlist, int);
                        else if (flag & flag_h1)
                            val = (unsigned short)va_arg(vlist, int);
                        else if (flag & flag_l2)
                            val = va_arg(vlist, u64);
                        else
                            val = va_arg(vlist, unsigned long);
                        flag &= ~(flag_plus | flag_blank);
                        if (flag & flag_sharp) {
                            if (radix == 16) {
                                if (val != 0) {
                                    prefix[0] = (char)(hex_char + ('x' - 'a' + 10));
                                    prefix[1] = '0';
                                    n_prefix = 2;
                                }
                            } else if (radix == 8) {
                                prefix[0] = '0';
                                n_prefix = 1;
                            }
                        }
                    } else {
                        if (flag & flag_h2)
                            val = (u64)(s64)(char)va_arg(vlist, int);
                        else if (flag & flag_h1)
                            val = (u64)(s64)(short)va_arg(vlist, int);
                        else if (flag & flag_l2)
                            val = va_arg(vlist, u64);
                        else
                            val = (u64)(s64)va_arg(vlist, long);
                        if ((val >> 32) & 0x80000000) {
                            val = ~val + 1;
                            prefix[0] = '-';
                            n_prefix = 1;
                        } else {
                            if (val || precision) {
                                if (flag & flag_plus) {
                                    prefix[0] = '+';
                                    n_prefix = 1;
                                } else if (flag & flag_blank) {
                                    prefix[0] = ' ';
                                    n_prefix = 1;
                                }
                            }
                        }
                    }
                    n_buf = 0;
                    switch (radix) {
                    case 8:
                        while (val != 0) {
                            int d = (int)(val & 0x07);
                            val >>= 3;
                            buf[n_buf++] = (char)(d + '0');
                        }
                        break;
                    case 10:
                        if ((val >> 32) == 0) {
                            u32 v = (u32)val;
                            while (v != 0) {
                                u32 r = v / 10;
                                int d = (int)(v - (r * 10));
                                v = r;
                                buf[n_buf++] = (char)(d + '0');
                            }
                        } else {
                            while (val != 0) {
                                u64 r = val / 10;
                                int d = (int)(val - (r * 10));
                                val = r;
                                buf[n_buf++] = (char)(d + '0');
                            }
                        }
                        break;
                    case 16:
                        while (val != 0) {
                            int d = (int)(val & 0x0f);
                            val >>= 4;
                            buf[n_buf++] = (char)((d < 10) ? (d + '0') : (d + hex_char));
                        }
                        break;
                    }
                    if ((n_prefix > 0) && (prefix[0] == '0')) {
                        n_prefix = 0;
                        buf[n_buf++] = '0';
                    }
                }
                {
                    int n_pad = precision - n_buf;
                    if (flag & flag_zero) {
                        if (n_pad < width - n_buf - n_prefix)
                            n_pad = width - n_buf - n_prefix;
                    }
                    if (n_pad > 0)
                        width -= n_pad;
                    width -= n_prefix + n_buf;
                    if (!(flag & flag_minus))
                        string_fill_char(&str, ' ', width);
                    while (n_prefix > 0)
                        string_put_char(&str, prefix[--n_prefix]);
                    string_fill_char(&str, '0', n_pad);
                    while (n_buf > 0)
                        string_put_char(&str, buf[--n_buf]);
                    if (flag & flag_minus)
                        string_fill_char(&str, ' ', width);
                    ++s;
                }
                break;
            }
        }
    }

    if (str.len > 0)
        *str.cur = '\0';
    else if (len > 0)
        str.base[len - 1] = '\0';
    return str.cur - str.base;
}
