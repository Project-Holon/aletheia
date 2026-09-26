/*
 * function: OS_SPrintf
 * address:  0x02084F40
 * packet:   pkt_02084F44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     true entry of the mis-seeded open row 0x02084F44 (disasm.py labels
 *           the second push; the real function opens with the four-word
 *           argument home area at 0x02084F40).  See
 *           docs/idioms/a-varargs-function-is-seeded-four-bytes-late-and-va-start-masks-before-it-adds.md
 *
 * symbols:
 *   OS_VSPrintf  0x02084F68  arm
 */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_end(v)

extern int OS_VSPrintf(char *dst, const char *fmt, va_list vlist);

int OS_SPrintf(char *dst, const char *fmt, ...)
{
    va_list vlist;
    va_start(vlist, fmt);
    return OS_VSPrintf(dst, fmt, vlist);
}
