/*
 * function: DWCi_ScPrintf
 * address:  0x021DF4A4
 * packet:   pkt_ov175_021DF4A4
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ScPrintf (libdwcsc.TWL.HYB.a(dwc_sc.o))
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm
 *   OS_VSNPrintf  0x02084FA8  arm
 *   sDwcScPrintfPrefix  0x021E3F68  data
 */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))

extern int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);
extern int OS_VSNPrintf(char *s, unsigned int n, const char *format, void *arg);
extern char sDwcScPrintfPrefix[];

void DWCi_ScPrintf(int line, char *fmt, ...)
{
	char str_buf[256];
	int str_len;
	va_list args;
	str_len = OS_SNPrintf(str_buf, 256, sDwcScPrintfPrefix, line);
	va_start(args, fmt);
	OS_VSNPrintf(str_buf + str_len, 256 - str_len, fmt, args);
}
