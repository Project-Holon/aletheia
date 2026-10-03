/*
 * function: func_021E17D8
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
 *   func_02084FA8  0x02084FA8  arm
 *   g_021E4640     0x021E4640  data
 */

extern char g_021E4640[];
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern int func_02084FA8(char *s, unsigned int n, const char *format, void *arg);

void func_021E17D8(int line, char *fmt, ...)
{
    char str_buf[256];
    int str_len;
    char *args;

    str_len = func_02084F80(str_buf, 256, g_021E4640, line);
    args = (char *)((((unsigned int)&fmt) & ~3) + 4);
    func_02084FA8(str_buf + str_len, 256 - str_len, fmt, args);
}
