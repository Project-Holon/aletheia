/*
 * function: func_02084F44
 * address:  0x02084F44
 * packet:   pkt_02084F44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (9 concrete bytes out)
 *
 * symbols:
 *   func_02084F68  0x02084F68  arm
 */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)((char *)&(l) + sizeof(l)))
#define va_end(v)

extern int func_02084F68(char *dst, const char *fmt, va_list vlist);

int func_02084F44(char *dst, const char *fmt, ...)
{
    va_list vlist;
    va_start(vlist, fmt);
    return func_02084F68(dst, fmt, vlist);
}
