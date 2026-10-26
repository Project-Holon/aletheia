/*
 * file:     nhttp_stdlib_ntr.c
 * unit:     yes
 * function: NHTTPi_memcpy, NHTTPi_strlen, NHTTPi_strnlen, NHTTPi_strcmp, NHTTPi_memclr, NHTTPi_strnicmp, NHTTPi_getUrlEncodedSize, NHTTPi_getUrlEncodedSize2, NHTTPi_encodeUrlChar, NHTTPi_strToHex, NHTTPi_strToInt, NHTTPi_intToStr, NHTTPi_compareToken, NHTTPi_strtonum, NHTTPi_memfind, NHTTPi_Base64Encode
 * address:  0x021BA100
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC/libdwcnd.TWL.HYB.a(dwci_nd.o).  decl_line 1812, params dst, src,
 * size; tail-calls MI_CpuCopy8(src, dst, size).
 *
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   sNHTTPBase64Chars     0x021CE3BC  data
 *   STD_GetStringNLength  0x0208CCFC  arm  arm9
 *   STD_CompareString  0x0208CD94  arm  arm9
 *   STD_GetStringLength  0x0208CC78  arm  arm9
 *   @12945 0x021CDFA4 data
 */
#include "../types.h"
#define NHTTPi_TOLOWER(c) ((((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c))

#include "../arm9/mi_memory.h"
#include "../arm9/std_string.h"
void NHTTPi_memcpy(void *dst, void *src, u32 size);
int NHTTPi_strlen(const char *s);
int NHTTPi_strnlen(const char *s, int maxLen);
int NHTTPi_strcmp(const char *s1, const char *s2);
void NHTTPi_memclr(void *dst_p, int size);
int NHTTPi_strnicmp(const char *p1_p, const char *p2_p, int size);
int NHTTPi_getUrlEncodedSize(char *s);
int NHTTPi_getUrlEncodedSize2(char *p_p, int len);
int NHTTPi_encodeUrlChar(char *dst, int c);
int NHTTPi_strToHex(char *p_p, int len);
int NHTTPi_strToInt(signed char *s, int len);
int NHTTPi_intToStr(char *p_p, unsigned long n);
int NHTTPi_compareToken(char *p1_p, char *p2_p);
int NHTTPi_strtonum(char *p_p, int size);
int NHTTPi_memfind(signed char *hay, int len1, signed char *needle, int len2);
int NHTTPi_Base64Encode(char *dst_p, const char *src_p);
extern char sNHTTPBase64Chars[];

void NHTTPi_memcpy(void *dst, void *src, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

/*
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 */
int NHTTPi_strlen(const char *s)
{
    return STD_GetStringLength(s);
}

int NHTTPi_strnlen(const char *s, int maxLen)
{
    return STD_GetStringNLength(s, maxLen);
}

int NHTTPi_strcmp(const char *s1, const char *s2)
{
    return STD_CompareString(s1, s2);
}

/*
 * ov114 tail-call thunk: g(a, 0, b) via `ldr ip,pool; bx ip`.
 */
void NHTTPi_memclr(void *dst_p, int size)
{
    MI_CpuFill8(dst_p, 0, size);
}

int NHTTPi_strnicmp(const char *p1_p, const char *p2_p, int size)
{
    char c2;
    char c1;

    while (size > 0) {
        c1 = *p1_p++;
        c2 = *p2_p++;
        if (c1 == 0 || c2 == 0) {
            if (c1 == 0 && c2 == 0) {
                size = 0;
                break;
            }
        }
        if (NHTTPi_TOLOWER(c1) != NHTTPi_TOLOWER(c2))
            break;
        size--;
    }
    return size;
}

int NHTTPi_getUrlEncodedSize(char *s)
{
    int w = 0;
    char c;

    while ((c = *s++) != 0)
    {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') || c == ' ')
            w += 1;
        else
            w += 3;
    }
    return w;
}

int NHTTPi_getUrlEncodedSize2(char *p_p, int len)
{
    int i;
    int n;
    int c;

    i = 0;
    n = 0;
    c = *p_p++;
    if (len > 0) {
        for (; i < len; i++) {
            if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') || c == ' ')
                n += 1;
            else
                n += 3;
            c = *p_p++;
        }
    }
    return n;
}

int NHTTPi_encodeUrlChar(char *dst, int c)
{
    int hi, lo;

    if (c == 0x20) {
        *dst = '+';
        return 1;
    }
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
        *dst = c;
        return 1;
    }
    hi = (c >> 4) & 0xf;
    lo = c & 0xf;
    *dst = '%';
    dst[1] = hi < 10 ? hi + '0' : hi + '7';
    dst[2] = lo < 10 ? lo + '0' : lo + '7';
    return 3;
}

/*
 * sdk:      NHTTPi_strToHex (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 */
int NHTTPi_strToHex(char *p_p, int len)
{
    int i;
    int n;
    int e;
    char c;

    if (len > 8) {
        return -1;
    }
    if (len == 8 && *p_p > '7') {
        return -1;
    }
    n = 0;
    e = 0;
    for (i = 0; i < len; i++) {
        c = NHTTPi_TOLOWER(p_p[i]);
        if (c >= '0' && c <= '9') {
            n = c + n * 16 - '0';
            e = 1;
        } else if (c >= 'a' && c <= 'f') {
            n = c + n * 16 - 'W';
            e = 1;
        } else {
            if (e != 0 && (c == ' ' || c == 0)) {
                break;
            }
            if (e != 0 || c != ' ') {
                return -1;
            }
        }
    }
    return n;
}

int NHTTPi_strToInt(signed char *s, int len)
{
    int i;
    int acc;
    int started;
    int old;
    signed char c;

    if (len > 10) return -1;
    acc = 0;
    started = 0;
    for (i = 0; i < len; i++) {
        c = s[i];
        if (started && (c == ' ' || c == 0)) break;
        if (!started && c == ' ') continue;
        if (c < '0' || c > '9') return -1;
        started = 1;
        old = acc;
        acc = acc * 10 + c - '0';
        if (old > acc) return -1;
    }
    return acc;
}

int NHTTPi_intToStr(char *p_p, unsigned long n)
{
    unsigned int rdx[9] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10};
    int len = 0;
    int b = 0;
    int i;
    unsigned int x;

    for (i = 0; i < 9; i++) {
        if (n >= rdx[i]) {
            x = n / rdx[i];
            p_p[len] = x + '0';
            b = 1;
            n -= x * rdx[i];
            len++;
        } else if (b) {
            p_p[len++] = '0';
        }
    }
    p_p[len] = n + '0';
    return len + 1;
}

int NHTTPi_compareToken(char *p1_p, char *p2_p)
{
    while (NHTTPi_TOLOWER(*p1_p) == NHTTPi_TOLOWER(*p2_p)) {
        if (*p1_p == '\0' || *p1_p == ' ')
            return 0;
        p1_p++;
        p2_p++;
    }
    return -1;
}

/*
 * sdk:      NHTTPi_strtonum (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 */
int NHTTPi_strtonum(char *p_p, int size)
{
    int numFound = 0;
    int n = 0;

    while (size-- != 0) {
        if (*p_p != ' ' && *p_p >= '0' && *p_p <= '9') {
            n = n * 10 + *p_p - '0';
            numFound++;
            if (numFound > 9) {
                return -1;
            }
        }
        p_p++;
    }
    if (numFound == 0) {
        n = -1;
    }
    return n;
}

/*
 * Substring search: if len1 < len2 return -1; scan hay for needle.  On a
 * first-char match, compare the remaining len2-1 chars; a full match returns
 * 0, else -1.
 *
 * Closed 2026-09-28: the residue was two register-allocation/scheduling
 * effects.  Inlining the loop bound as `(len1 - len2) + 1` (the now-dead
 * `n = ...` store stays, it is what reserves r8 for the bound) and spelling
 * the pointer as `p = hay; p = p + i;` instead of `p = hay + i;` makes this
 * front end put the bound in r8 and the pointer in r6 and compute the pointer
 * after the primer compare instead of hoisting `add r8, r0, r4` above it.
 * Found with permuter.py (`split-assign(p); expand(n)`); the two levers are
 * the declaration/allocation-order family of
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 */
int NHTTPi_memfind(signed char *hay, int len1, signed char *needle, int len2)
{
    int i;
    int j;
    int n;
    signed char *p;

    if (len1 < len2) return -1;
    n = len1 - len2 + 1;
    for (i = 0; i < (len1 - len2 + 1); i++) {
        if (hay[i] != needle[0]) continue;
        p = hay;
        p = p + i;
        for (j = 1; j < len2; j++) {
            if (p[j] != needle[j]) break;
        }
        if (j == len2) return 0;
    }
    return -1;
}

/*
 * sdk:      NHTTPi_Base64Encode (libnhttp.TWL.HYB.a(nhttp_stdlib_ntr))
 */
int NHTTPi_Base64Encode(char *dst_p, const char *src_p)
{
    char *tbl;
    char *wp;
    int i;
    int len;

    wp = dst_p;
    tbl = sNHTTPBase64Chars;
    len = NHTTPi_strlen((char *)src_p);

    for (i = 0; i < len; i += 3, src_p += 3, wp += 4) {
        wp[0] = tbl[src_p[0] >> 2];
        wp[1] = tbl[((src_p[0] & 3) << 4) + (src_p[1] >> 4)];
        wp[2] = tbl[((src_p[1] & 15) << 2) + (src_p[2] >> 6)];
        wp[3] = tbl[src_p[2] & 63];
    }
    if (i == len + 1) {
        wp[-1] = '=';
    } else if (i == len + 2) {
        wp[-2] = '=';
        wp[-1] = '=';
    }
    *wp = 0;
    return NHTTPi_strlen(dst_p);
}
