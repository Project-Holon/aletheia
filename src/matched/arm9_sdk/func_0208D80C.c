/*
 * function: OS_SNPrintf
 * address:  0x0208D80C
 * packet:   pkt_02087AE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_printf.o.  The worklist seeded this at 0x0208D810, four
 * bytes in; the real entry is the `push {r0,r1,r2,r3}` argument-home store at
 * 0x0208D80C, which layout/symbols_sdk.txt names OS_SNPrintf.
 *
 * The bounded form: n comes straight from the caller, so unlike STD_TSPrintf
 * there is no INT_MAX to materialise and the body is one instruction shorter.
 *
 * symbols:
 *   STD_TVSNPrintf  0x0208D834  arm
 */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_end(v)

extern int STD_TVSNPrintf(char *dst, int n, const char *fmt, va_list vlist);

int OS_SNPrintf(char *dst, int n, const char *fmt, ...)
{
    int r;
    va_list vlist;
    va_start(vlist, fmt);
    r = STD_TVSNPrintf(dst, n, fmt, vlist);
    va_end(vlist);
    return r;
}
