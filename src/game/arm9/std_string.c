/*
 * file:     std_string.c
 * unit:     yes
 * function: STD_CopyString, STD_CopyLString, STD_SearchString, STD_GetStringLength, STD_GetStringNLength, STD_CompareString, STD_CompareNString, STD_TSScanf, STDi_IsSpace, STDi_FillBitset, STD_TVSScanf
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
#define GAME_TYPES_U32_LONG
#include "../types.h"

#include "../sdk_stdarg.h"

#include "mi_memory.h"
char *STD_CopyString(char *destp, const char *srcp);
int STD_CopyLString(char *destp, const char *srcp, int siz);
char *STD_SearchString(const char *srcp, const char *str);
int STD_GetStringLength(const char *str);
int STD_GetStringNLength(const char *str, int len);
int STD_CompareString(const char *str1, const char *str2);
int STD_CompareNString(const char *str1, const char *str2, int len);
int STD_TSScanf(char *dst, const char *fmt, ...);
int STDi_IsSpace(int c);
void STDi_FillBitset(unsigned long *bitset, unsigned long a, unsigned long b);
int STD_TVSScanf(const char *src, const char *fmt, va_list vlist);

/*
 * sdk:      STD_CopyString (std_string.o)
 */
char *STD_CopyString(char *destp, const char *srcp)
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
int STD_CopyLString(char *destp, const char *srcp, int siz)
{
    const char *source;
    unsigned long zeroMask;
    unsigned long val32;
    int index;
    unsigned long dstalign;

    source = srcp;
    index = 0;
    dstalign = (uptr)destp & 3;

    if ((dstalign ^ ((uptr)srcp & 3)) == 0) {
        if (dstalign != 0) {
            for (; index + dstalign < 4 && index < siz - 1; source++, index++) {
                destp[index] = *source;
                if (*source == '\0') {
                    goto end;
                }
            }
        }
        for (; index < siz - 4; index += 4) {
            val32 = *(const unsigned long *)(srcp + index);
            zeroMask = ~(((val32 & 0x7f7f7f7f) + 0x7f7f7f7f) | val32 | 0x7f7f7f7f);
            if (zeroMask != 0) {
                break;
            }
            *(unsigned long *)(destp + index) = val32;
        }
        source = srcp + index;
    }

    for (; index < siz - 1; index++, source++) {
        destp[index] = *source;
        if (*source == '\0') {
            goto end;
        }
    }

end:
    if (index >= siz - 1 && siz > 0) {
        destp[index] = '\0';
    }
    if (*source != '\0') {
        index += STD_GetStringLength(source);
    }
    return index;
}

/*
 * sdk:      STD_SearchString (std_string.o)
 */
char *STD_SearchString(const char *srcp, const char *str)
{
    int index;
    int matchLength;

    for (index = 0; srcp[index] != '\0'; index++) {
        matchLength = 0;
        while (str[matchLength] != '\0' && srcp[index + matchLength] == str[matchLength]) {
            matchLength++;
        }
        if (str[matchLength] == '\0') {
            return (char *)&srcp[index];
        }
    }
    return 0;
}

int STD_GetStringLength(const char *str)
{
    int length = 0;

    while (((uptr)(str + length) & 3) != 0) {
        if (str[length] == '\0')
            return length;
        ++length;
    }
    {
        const u32 *p32 = (const u32 *)(str + length);

        for (;;) {
            u32 zeroMask = *p32;

            zeroMask = ~(((zeroMask & 0x7F7F7F7F) + 0x7F7F7F7F) | zeroMask | 0x7F7F7F7F);
            if (zeroMask != 0)
                break;
            ++p32;
            length += 4;
        }
    }
    while (str[length] != '\0')
        ++length;
    return length;
}

/*
 * sdk:      STD_GetStringNLength (std_string.o)
 */
int STD_GetStringNLength(const char *str, int len)
{
    int length;
    const unsigned long *p32;
    unsigned long zeroMask;

    for (length = 0; ((uptr)(str + length) & 3) != 0 && length < len; length++) {
        if (str[length] == '\0') {
            return length;
        }
    }

    p32 = (const unsigned long *)(str + length);
    for (; length < len - 4; length += 4, p32++) {
        zeroMask = *p32;
        zeroMask = ~(((zeroMask & 0x7f7f7f7f) + 0x7f7f7f7f) | zeroMask | 0x7f7f7f7f);
        if (zeroMask != 0) {
            break;
        }
    }

    while (str[length] != '\0' && length < len) {
        length++;
    }
    return length;
}

/*
 * sdk:      STD_CompareString (std_string.o)
 */
int STD_CompareString(const char *str1, const char *str2)
{
    unsigned long dstalign;
    unsigned char chr1;
    unsigned char chr2;
    unsigned long word1;
    unsigned long zeroMask;
    int index;

    index = 0;
    dstalign = (uptr)str1 & 3;

    if ((dstalign ^ ((uptr)str2 & 3)) == 0) {
        if (dstalign != 0) {
            for (; index + dstalign < 4; index++) {
                chr1 = (unsigned char)str1[index];
                chr2 = (unsigned char)str2[index];
                if (chr1 != chr2 || chr1 == 0) {
                    return chr1 - chr2;
                }
            }
        }
        for (;;) {
            word1 = *(const unsigned long *)(str1 + index);
            if (word1 != *(const unsigned long *)(str2 + index)) {
                break;
            }
            zeroMask = ~(((word1 & 0x7f7f7f7f) + 0x7f7f7f7f) | word1 | 0x7f7f7f7f);
            if (zeroMask != 0) {
                break;
            }
            index += 4;
        }
    }

    for (;;) {
        chr1 = (unsigned char)str1[index];
        chr2 = (unsigned char)str2[index];
        if (chr1 != chr2 || chr1 == 0) {
            return chr1 - chr2;
        }
        index++;
    }
}

/*
 * sdk:      STD_CompareNString (std_string.o)
 */
int STD_CompareNString(const char *str1, const char *str2, int len)
{
    unsigned long dstalign;
    unsigned char chr1;
    unsigned char chr2;
    unsigned long word1;
    unsigned long zeroMask;
    int index;

    if (len != 0) {
        index = 0;
        dstalign = (uptr)str1 & 3;

        if ((dstalign ^ ((uptr)str2 & 3)) == 0) {
            if (dstalign != 0) {
                for (; index + dstalign < 4 && index < len; index++) {
                    chr1 = (unsigned char)str1[index];
                    chr2 = (unsigned char)str2[index];
                    if (chr1 != chr2 || chr1 == 0) {
                        return chr1 - chr2;
                    }
                }
            }
            for (; index <= len - 4; index += 4) {
                word1 = *(const unsigned long *)(str1 + index);
                if (word1 != *(const unsigned long *)(str2 + index)) {
                    break;
                }
                zeroMask = ~(((word1 & 0x7f7f7f7f) + 0x7f7f7f7f) | word1 | 0x7f7f7f7f);
                if (zeroMask != 0) {
                    break;
                }
            }
        }

        for (; index < len; index++) {
            chr1 = (unsigned char)str1[index];
            chr2 = (unsigned char)str2[index];
            if (chr1 != chr2 || chr1 == 0) {
                return chr1 - chr2;
            }
        }
    }
    return 0;
}

int STD_TSScanf(char *dst, const char *fmt, ...)
{
    int result;
    va_list vlist;
    va_start(vlist, fmt);
    result = STD_TVSScanf(dst, fmt, vlist);
    va_end(vlist);
    return result;
}

int STDi_IsSpace(int c)
{
    int result = 0;
    unsigned int offset = (unsigned int)(c - 9);
    if (offset <= 0x17 && (0x0080001F & (1 << offset)))
        result = 1;
    return result;
}

void STDi_FillBitset(unsigned long *bitset, unsigned long start, unsigned long end)
{
    while (start < end) {
        unsigned long pos = start >> 5;
        unsigned long mask = ~0UL << (start & 31);
        start = (pos + 1) << 5;
        if (end < start)
            mask &= (1UL << (end & 31)) - 1;
        bitset[pos] |= mask;
    }
}

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
    u32 matchCondition;
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
                        u32 digitValue = (u32)(c - '0');
                        if (digitValue >= 10) {
                            if (digitValue - ('a' - '0') < 6)
                                digitValue = digitValue - ('a' - '0') + 10;
                            else {
                                digitValue -= 'A' - '0';
                                if (digitValue < 6)
                                    digitValue += 10;
                            }
                        }
                        if (digitValue >= radix)
                            break;
                        c = *++src;
                        val = val * radix + digitValue;
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

                    matchCondition = 1;
                    MIi_CpuClear32(0, bitset, sizeof(bitset));
                    if (*++fmt == '^') {
                        ++fmt;
                        matchCondition = 0;
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
                            if (((bitset[(u32)(u8)ch >> 5] >> ((u32)(u8)ch & 31)) & 1) != matchCondition)
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
