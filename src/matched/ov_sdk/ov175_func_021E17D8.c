/*
 * function: DWCi_GdbPrintf
 * address:  0x021E17D8
 * packet:   pkt_ov175_021E17D8
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GdbPrintf (dwc_gdb.o)
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   OS_VSNPrintf  0x02084FA8  arm
 *   sDwcGdbPrintfPrefix     0x021E4640  data
 */

extern char sDwcGdbPrintfPrefix[];
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern int OS_VSNPrintf(char *s, unsigned int n, const char *format, void *arg);

void DWCi_GdbPrintf(int line, char *fmt, ...)
{
    char str_buf[256];
    int str_len;
    char *args;

    str_len = func_02084F80(str_buf, 256, sDwcGdbPrintfPrefix, line);
    args = (char *)((((unsigned int)&fmt) & ~3) + 4);
    OS_VSNPrintf(str_buf + str_len, 256 - str_len, fmt, args);
}
