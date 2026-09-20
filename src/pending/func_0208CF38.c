/*
 * function: func_0208CF38
 * address:  0x0208CF38
 * packet:   pkt_0208CF38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208CFD8  0x0208CFD8  arm
 */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)((char *)&(l) + sizeof(l)))
#define va_end(v)

extern int func_0208CFD8(char *dst, const char *fmt, va_list vlist);

int func_0208CF38(char *dst, const char *fmt, ...)
{
    va_list vlist;
    va_start(vlist, fmt);
    return func_0208CFD8(dst, fmt, vlist);
}
