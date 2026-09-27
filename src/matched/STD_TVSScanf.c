/*
 * function: STD_TVSScanf
 * address:  0x0208CFD8
 * packet:   pkt_0208CFD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libstd std_string.o (tools/sdkobj.py: .comment stamp 4.0.0.1024,
 * the dsi/1.1p1 front end).  Parameter and local names from the member's
 * DWARF.
 *
 * Three shape facts closed it: the '[' set loop is a top-tested for(;;)
 * with the exit block inside the test (a for with a condition rotates);
 * dst and dst_bak are both initialised and assigned together, which
 * if-converts into both arms; and matchcond lives at function scope ahead
 * of `stored`, which puts `stored` at sp+4 and matchcond at sp+8 (declared
 * in the '[' block the two spill slots swap).
 *
 * symbols:
 *   STDi_IsSpace     0x0208CF5C  arm
 *   STDi_FillBitset  0x0208CF84  arm
 *   MIi_CpuClear32   0x02082A7C  arm
 */

typedef char *va_list;
#define __va_size(t) ((sizeof(t) + 3) & ~3)
#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))

typedef unsigned long long u64;
typedef long long s64;
typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int STDi_IsSpace(int c);
extern void STDi_FillBitset(u32 *bitset, u32 a, u32 b);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);

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
