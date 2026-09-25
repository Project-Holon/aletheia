/*
 * function: func_0217D254
 * address:  0x0217D254
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Variadic logging thunk: capture the anonymous arguments with va_start and
 * forward (index, table, mask, fmt, args) to the filtering dispatcher
 * func_0217D19C.  Callers use it as a printf-style logger over one of the
 * DWC category tables.
 *
 * symbols:
 *   func_0217D19C  0x0217D19C  arm  ov009
 */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))

extern int func_0217D19C(int index, char *table, int mask, const char *fmt, va_list args);

int func_0217D254(int index, char *table, int mask, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    return func_0217D19C(index, table, mask, fmt, args);
}
