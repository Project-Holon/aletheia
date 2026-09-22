/*
 * function: STD_TSPrintf
 * address:  0x0208D7E0
 * packet:   pkt_02087AE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libstd std_sprintf.o.  The worklist seeded this at 0x0208D7E4, four
 * bytes in; the real entry is the `push {r0,r1,r2,r3}` argument-home store at
 * 0x0208D7E0, which layout/symbols_sdk.txt names STD_TSPrintf.
 *
 * The unbounded form: it is STD_TVSNPrintf with n = INT_MAX, which the image
 * materialises as `mvn r1, #0x80000000`.
 *
 * symbols:
 *   STD_TVSNPrintf  0x0208D834  arm
 */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_end(v)

extern int STD_TVSNPrintf(char *dst, int n, const char *fmt, va_list vlist);

int STD_TSPrintf(char *dst, const char *fmt, ...)
{
    int r;
    va_list vlist;
    va_start(vlist, fmt);
    r = STD_TVSNPrintf(dst, 0x7FFFFFFF, fmt, vlist);
    va_end(vlist);
    return r;
}
