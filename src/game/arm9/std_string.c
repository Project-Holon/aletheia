/*
 * file:     std_string.c
 * unit:     yes
 * function: func_0208CADC, func_0208CB10, func_0208CC14, func_0208CC78, func_0208CCFC, func_0208CD94, func_0208CE4C, func_0208CF34, func_0208CF5C, func_0208CF84, func_0208CFD8
 * address:  0x0208CADC
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
 *   MIi_CpuClear32   0x02082A7C  arm
 */
typedef unsigned long u32;

typedef char *va_list;

typedef unsigned long long u64;

typedef long long s64;

typedef unsigned short u16;

typedef unsigned char u8;

extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
char *func_0208CADC(char *destp, const char *srcp);
int func_0208CB10(char *destp, const char *srcp, int siz);
char *func_0208CC14(const char *srcp, const char *str);
int STD_GetStringLength(const char *str);
int func_0208CCFC(const char *str, int len);
int func_0208CD94(const char *str1, const char *str2);
int func_0208CE4C(const char *str1, const char *str2, int len);
int STD_TSScanf(char *dst, const char *fmt, ...);
int STDi_IsSpace(int c);
void STDi_FillBitset(unsigned long *bitset, unsigned long a, unsigned long b);
int STD_TVSScanf(const char *src, const char *fmt, va_list vlist);

/*
 * sdk:      STD_CopyString (std_string.o)
 */
char *func_0208CADC(char *destp, const char *srcp)
{
    char *retval = destp;

    while (*srcp != '\0') {
        *destp++ = *srcp++;
    }
    *destp = '\0';
    return retval;
}


/*
 * sdk:      STD_CopyLString (std_string.o)
 */
int func_0208CB10(char *destp, const char *srcp, int siz)
{
    const char *s;
    unsigned long y;
    unsigned long val32;
    int i;
    unsigned long dstalign;

    s = srcp;
    i = 0;
    dstalign = (unsigned long)destp & 3;

    if ((dstalign ^ ((unsigned long)srcp & 3)) == 0) {
        if (dstalign != 0) {
            for (; i + dstalign < 4 && i < siz - 1; s++, i++) {
                destp[i] = *s;
                if (*s == '\0') {
                    goto end;
                }
            }
        }
        for (; i < siz - 4; i += 4) {
            val32 = *(const unsigned long *)(srcp + i);
            y = ~(((val32 & 0x7f7f7f7f) + 0x7f7f7f7f) | val32 | 0x7f7f7f7f);
            if (y != 0) {
                break;
            }
            *(unsigned long *)(destp + i) = val32;
        }
        s = srcp + i;
    }

    for (; i < siz - 1; i++, s++) {
        destp[i] = *s;
        if (*s == '\0') {
            goto end;
        }
    }

end:
    if (i >= siz - 1 && siz > 0) {
        destp[i] = '\0';
    }
    if (*s != '\0') {
        i += STD_GetStringLength(s);
    }
    return i;
}

/*
 * sdk:      STD_SearchString (std_string.o)
 */
char *func_0208CC14(const char *srcp, const char *str)
{
    int i;
    int n;

    for (i = 0; srcp[i] != '\0'; i++) {
        n = 0;
        while (str[n] != '\0' && srcp[i + n] == str[n]) {
            n++;
        }
        if (str[n] == '\0') {
            return (char *)&srcp[i];
        }
    }
    return 0;
}


int STD_GetStringLength(const char *str)
{
    int n = 0;

    while (((u32)(str + n) & 3) != 0) {
        if (str[n] == '\0')
            return n;
        ++n;
    }
    {
        const u32 *p32 = (const u32 *)(str + n);

        for (;;) {
            u32 y = *p32;

            y = ~(((y & 0x7F7F7F7F) + 0x7F7F7F7F) | y | 0x7F7F7F7F);
            if (y != 0)
                break;
            ++p32;
            n += 4;
        }
    }
    while (str[n] != '\0')
        ++n;
    return n;
}

/*
 * sdk:      STD_GetStringNLength (std_string.o)
 */
int func_0208CCFC(const char *str, int len)
{
    int n;
    const unsigned long *p32;
    unsigned long y;

    for (n = 0; ((unsigned long)(str + n) & 3) != 0 && n < len; n++) {
        if (str[n] == '\0') {
            return n;
        }
    }

    p32 = (const unsigned long *)(str + n);
    for (; n < len - 4; n += 4, p32++) {
        y = *p32;
        y = ~(((y & 0x7f7f7f7f) + 0x7f7f7f7f) | y | 0x7f7f7f7f);
        if (y != 0) {
            break;
        }
    }

    while (str[n] != '\0' && n < len) {
        n++;
    }
    return n;
}

/*
 * sdk:      STD_CompareString (std_string.o)
 */
int func_0208CD94(const char *str1, const char *str2)
{
    unsigned long dstalign;
    unsigned char chr1;
    unsigned char chr2;
    unsigned long lng1;
    unsigned long y;
    int i;

    i = 0;
    dstalign = (unsigned long)str1 & 3;

    if ((dstalign ^ ((unsigned long)str2 & 3)) == 0) {
        if (dstalign != 0) {
            for (; i + dstalign < 4; i++) {
                chr1 = (unsigned char)str1[i];
                chr2 = (unsigned char)str2[i];
                if (chr1 != chr2 || chr1 == 0) {
                    return chr1 - chr2;
                }
            }
        }
        for (;;) {
            lng1 = *(const unsigned long *)(str1 + i);
            if (lng1 != *(const unsigned long *)(str2 + i)) {
                break;
            }
            y = ~(((lng1 & 0x7f7f7f7f) + 0x7f7f7f7f) | lng1 | 0x7f7f7f7f);
            if (y != 0) {
                break;
            }
            i += 4;
        }
    }

    for (;;) {
        chr1 = (unsigned char)str1[i];
        chr2 = (unsigned char)str2[i];
        if (chr1 != chr2 || chr1 == 0) {
            return chr1 - chr2;
        }
        i++;
    }
}

/*
 * sdk:      STD_CompareNString (std_string.o)
 */
int func_0208CE4C(const char *str1, const char *str2, int len)
{
    unsigned long dstalign;
    unsigned char chr1;
    unsigned char chr2;
    unsigned long lng1;
    unsigned long y;
    int i;

    if (len != 0) {
        i = 0;
        dstalign = (unsigned long)str1 & 3;

        if ((dstalign ^ ((unsigned long)str2 & 3)) == 0) {
            if (dstalign != 0) {
                for (; i + dstalign < 4 && i < len; i++) {
                    chr1 = (unsigned char)str1[i];
                    chr2 = (unsigned char)str2[i];
                    if (chr1 != chr2 || chr1 == 0) {
                        return chr1 - chr2;
                    }
                }
            }
            for (; i <= len - 4; i += 4) {
                lng1 = *(const unsigned long *)(str1 + i);
                if (lng1 != *(const unsigned long *)(str2 + i)) {
                    break;
                }
                y = ~(((lng1 & 0x7f7f7f7f) + 0x7f7f7f7f) | lng1 | 0x7f7f7f7f);
                if (y != 0) {
                    break;
                }
            }
        }

        for (; i < len; i++) {
            chr1 = (unsigned char)str1[i];
            chr2 = (unsigned char)str2[i];
            if (chr1 != chr2 || chr1 == 0) {
                return chr1 - chr2;
            }
        }
    }
    return 0;
}

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))

#define va_end(v)


int STD_TSScanf(char *dst, const char *fmt, ...)
{
    int r;
    va_list vlist;
    va_start(vlist, fmt);
    r = STD_TVSScanf(dst, fmt, vlist);
    va_end(vlist);
    return r;
}

int STDi_IsSpace(int c)
{
    int ret = 0;
    unsigned int d = (unsigned int)(c - 9);
    if (d <= 0x17 && (0x0080001F & (1 << d)))
        ret = 1;
    return ret;
}

void STDi_FillBitset(unsigned long *bitset, unsigned long a, unsigned long b)
{
    while (a < b) {
        unsigned long pos = a >> 5;
        unsigned long mask = ~0UL << (a & 31);
        a = (pos + 1) << 5;
        if (b < a)
            mask &= (1UL << (b & 31)) - 1;
        bitset[pos] |= mask;
    }
}

#define __va_size(t) ((sizeof(t) + 3) & ~3)

#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))


enum {
    flag_plus = 0x0002,
    flag_minus = 0x0008,
    flag_l1 = 0x0020,
    flag_h1 = 0x0040,
    flag_l2 = 0x0080,
    flag_h2 = 0x0100,
    flag_unsigned = 0x1000,
    flag_ignored = 0x2000
};


#define SET_BIT(set, n) ((set)[(u32)(n) >> 5] |= (1 << ((u32)(n) & 31)))


int STD_TVSScanf(const char *src, const char *fmt, va_list vlist)
{
    const char *src_base = src;
    int matched = 0;
    u32 matchcond;
    int stored = 0;
    char c;

    while ((c = *fmt) != '\0') {
        if (STDi_IsSpace(c)) {
            while (STDi_IsSpace(*fmt))
                ++fmt;
            while (STDi_IsSpace(*src))
                ++src;
        } else if (c != '%') {
            if (c != *src)
                break;
            if ((unsigned int)(((unsigned char)c ^ 0x20) - 0xA1) < 0x3C) {
                if (c != *++src)
                    break;
            }
            ++src;
            ++fmt;
        } else if (fmt[1] == '%') {
            if (c != *src)
                break;
            fmt += 2;
        } else {
            u64 val = 0;
            int flag = 0, width = 0, radix;

            c = *++fmt;
            if (c == '*') {
                flag |= flag_ignored;
                c = *++fmt;
            }
            while ((c >= '0') && (c <= '9')) {
                width = (width * 10) + c - '0';
                c = *++fmt;
            }
            switch (c) {
            case 'h':
                c = *++fmt;
                if (c != 'h')
                    flag |= flag_h1;
                else
                    flag |= flag_h2, c = *++fmt;
                break;
            case 'l':
                c = *++fmt;
                if (c != 'l')
                    flag |= flag_l1;
                else
                    flag |= flag_l2, c = *++fmt;
                break;
            }

            switch (c) {
            case 'd':
                radix = 10;
                goto get_integer;
            case 'i':
                radix = -1;
                goto get_integer;
            case 'o':
                radix = 8;
                goto get_integer;
            case 'u':
                flag |= flag_unsigned;
                radix = 10;
                goto get_integer;
            case 'X':
            case 'x':
            case 'p':
                flag |= flag_unsigned;
                radix = 16;
                goto get_integer;
            case 'n':
                if (!(flag & flag_ignored))
                    --stored;
                ++fmt;
                val = (u64)(s64)(src - src_base);
                goto store_integer;

            get_integer:
                ++fmt;
                c = *src;
                while (STDi_IsSpace(c))
                    c = *++src;
                for (;;) {
                    if (c == '+')
                        flag |= flag_plus;
                    else if (c == '-')
                        flag |= flag_minus;
                    else
                        break;
                    c = *++src;
                }
                if (radix == -1) {
                    if (c != '0')
                        radix = 10;
                    else if ((src[1] == 'x') || (src[1] == 'X'))
                        radix = 16;
                    else
                        radix = 8;
                }
                if ((radix == 16) && (c == '0') && ((src[1] == 'x') || (src[1] == 'X'))) {
                    src += 2;
                    c = *src;
                }
                if (width == 0)
                    width = 0x7FFFFFFF;
                {
                    int digit;
                    for (digit = 0; digit < width; ++digit) {
                        u32 d = (u32)(c - '0');
                        if (d >= 10) {
                            if (d - ('a' - '0') < 6)
                                d = d - ('a' - '0') + 10;
                            else {
                                d -= 'A' - '0';
                                if (d < 6)
                                    d += 10;
                            }
                        }
                        if (d >= radix)
                            break;
                        c = *++src;
                        val = val * radix + d;
                    }
                    if (digit == 0)
                        goto end;
                }
                if (flag & flag_minus)
                    val = (u64)(-(s64)val);
                matched = 1;

            store_integer:
                if (!(flag & flag_ignored)) {
                    ++stored;
                    if (flag & flag_h2)
                        *va_arg(vlist, u8 *) = (u8)val;
                    else if (flag & flag_h1)
                        *va_arg(vlist, u16 *) = (u16)val;
                    else if (flag & flag_l2)
                        *va_arg(vlist, u64 *) = val;
                    else
                        *va_arg(vlist, u32 *) = (u32)val;
                }
                break;

            case 'c':
            case 's':
                {
                    char *dst = 0, *dst_bak = 0;
                    ++fmt;
                    if (!(flag & flag_ignored))
                        dst_bak = dst = va_arg(vlist, char *);
                    if (c == 's') {
                        char ch = *src;
                        if (width == 0)
                            width = 0x7FFFFFFF;
                        while (STDi_IsSpace(ch))
                            ch = *++src;
                        while (ch && !STDi_IsSpace(ch) && (width > 0)) {
                            if (dst)
                                *dst++ = ch;
                            ch = *++src;
                            --width;
                        }
                        if (dst != dst_bak) {
                            *dst = '\0';
                            ++stored;
                            matched = 1;
                        }
                    } else {
                        char ch;
                        if (width == 0)
                            width = 1;
                        ch = *src;
                        while (ch && (width > 0)) {
                            if (dst)
                                *dst++ = ch;
                            ch = *++src;
                            --width;
                        }
                        if (dst != dst_bak) {
                            ++stored;
                            matched = 1;
                            if (width > 0)
                                *dst = '\0';
                        }
                    }
                }
                break;

            case '[':
                {
                    char *dst = 0;
                    u32 bitset[256 / 32];
                    u32 from = 0;
                    int in_range = 0;

                    matchcond = 1;
                    MIi_CpuClear32(0, bitset, sizeof(bitset));
                    if (*++fmt == '^') {
                        ++fmt;
                        matchcond = 0;
                    }
                    if (*fmt == ']') {
                        SET_BIT(bitset, (u8)*fmt);
                        ++fmt;
                    }
                    for (;;) {
                        if ((*fmt == '\0') || (*fmt == ']')) {
                            if (in_range) {
                                SET_BIT(bitset, from);
                                SET_BIT(bitset, '-');
                            }
                            if (*fmt == ']')
                                ++fmt;
                            break;
                        }
                        if (!in_range) {
                            if ((from != 0) && (*fmt == '-'))
                                in_range = 1;
                            else {
                                SET_BIT(bitset, (u8)*fmt);
                                from = (u8)*fmt;
                            }
                        } else {
                            u32 to = (u8)*fmt;
                            if (from > to) {
                                SET_BIT(bitset, from);
                                SET_BIT(bitset, '-');
                                SET_BIT(bitset, to);
                            } else {
                                STDi_FillBitset(bitset, from, to + 1);
                            }
                            in_range = 0;
                            from = 0;
                        }
                        ++fmt;
                    }

                    matched = 1;
                    if (!(flag & flag_ignored)) {
                        dst = va_arg(vlist, char *);
                        ++stored;
                    }
                    if (width == 0)
                        width = 0x7FFFFFFF;
                    {
                        char ch = *src;
                        while (ch && (width > 0)) {
                            if (((bitset[(u32)(u8)ch >> 5] >> ((u32)(u8)ch & 31)) & 1) != matchcond)
                                break;
                            if (dst)
                                *dst++ = ch;
                            ch = *++src;
                            --width;
                        }
                    }
                    if (dst)
                        *dst = '\0';
                }
                break;

            default:
                goto end;
            }
        }
    }
end:
    if ((*src == '\0') && !matched)
        stored = -1;
    return stored;
}
