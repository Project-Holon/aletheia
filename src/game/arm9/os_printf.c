/*
 * file:     os_printf.c
 * unit:     yes
 * function: OS_SPrintf, OS_VSPrintf, OS_SNPrintf, OS_VSNPrintf
 * address:  0x02084F40
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
 *   OS_VSPrintf  0x02084F68  arm
 *   OS_VSNPrintf  0x02084FA8  arm
 *   STD_TVSNPrintf  0x0208D834  arm
 */
#include "../sdk_stdarg.h"

extern int OS_VSPrintf(char *dst, const char *fmt, va_list vlist);
extern int STD_TVSNPrintf(char *dst, unsigned int len, const char *format, va_list vlist);
int OS_SPrintf(char *dst, const char *fmt, ...);
int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);
int OS_VSNPrintf(char *dst, unsigned int len, const char *format, va_list vlist);

int OS_SPrintf(char *dst, const char *fmt, ...)
{
    va_list vlist;
    va_start(vlist, fmt);
    return OS_VSPrintf(dst, fmt, vlist);
}

int OS_VSPrintf(char *dst, const char *fmt, va_list vlist)
{
    return OS_VSNPrintf(dst, 0x7fffffff, fmt, vlist);
}

/*
 * note:     os_printf.o OS_SNPrintf.
 */
int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...)
{
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = OS_VSNPrintf(dst, len, fmt, va);
    va_end(va);
    return ret;
}

int OS_VSNPrintf(char *dst, unsigned int len, const char *format, va_list vlist)
{
    return STD_TVSNPrintf(dst, len, format, vlist);
}
