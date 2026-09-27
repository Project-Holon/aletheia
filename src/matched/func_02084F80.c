/*
 * function: func_02084F80
 * address:  0x02084F80
 * packet:   pkt_02084F80
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_printf.o OS_SNPrintf.
 *
 * symbols:
 *   OS_VSNPrintf  0x02084FA8  arm
 */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_end(v)

extern int OS_VSNPrintf(char *dst, unsigned int len, const char *fmt, va_list vlist);

int func_02084F80(char *dst, unsigned int len, const char *fmt, ...)
{
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = OS_VSNPrintf(dst, len, fmt, va);
    va_end(va);
    return ret;
}
