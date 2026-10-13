/*
 * file:     unit_02084F40.c
 * unit:     yes
 * function: func_02084F40, func_02084F68, func_02084F80
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
 *   OS_VSNPrintf_Alt   0x02084FA8  arm
 *   OS_VSNPrintf  0x02084FA8  arm
 */
typedef char *va_list;

extern int OS_VSPrintf(char *dst, const char *fmt, va_list vlist);
extern void OS_VSNPrintf_Alt(void *a0, int a1, int a2, int a3);
extern int OS_VSNPrintf(char *dst, unsigned int len, const char *fmt, va_list vlist);
int OS_SPrintf(char *dst, const char *fmt, ...);
void func_02084F68(void *a0, int a1, int a2);
int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))

#define va_end(v)


int OS_SPrintf(char *dst, const char *fmt, ...)
{
    va_list vlist;
    va_start(vlist, fmt);
    return OS_VSPrintf(dst, fmt, vlist);
}


void func_02084F68(void *a0, int a1, int a2)
{
    OS_VSNPrintf_Alt(a0, 0x7fffffff, a1, a2);
}

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))

#define va_end(v)


/*
 * note:     os_printf.o OS_SNPrintf.
 */
int func_02084F80(char *dst, unsigned int len, const char *fmt, ...)
{
    int ret;
    va_list va;
    va_start(va, fmt);
    ret = OS_VSNPrintf(dst, len, fmt, va);
    va_end(va);
    return ret;
}
