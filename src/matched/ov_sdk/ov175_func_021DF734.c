/*
 * function: func_021DF734
 * address:  0x021DF734
 * packet:   pkt_ov175_021DF734
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ScSetUseSSL (libdwcsc.TWL.HYB.a(dwc_sc.o))
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   func_021BF520  0x021BF520  arm  ov114
 *   g_021E52B4  0x021E52B4  data
 *   g_021AE01C  0x021AE01C  data
 *   g_021E3FE8  0x021E3FE8  data
 *   g_021E53BC  0x021E53BC  data
 *   g_021E4040  0x021E4040  data
 *   g_021E408C  0x021E408C  data
 *   g_021E40E4  0x021E40E4  data
 */

extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
extern int func_021BF520(char *url);
extern char g_021E52B4[];
extern char g_021AE01C[];
extern char g_021E3FE8[];
extern char g_021E53BC[];
extern char g_021E4040[];
extern char g_021E408C[];
extern char g_021E40E4[];

void func_021DF734(int ssl_type)
{
	switch (ssl_type) {
	case 1:
		func_02084F80(g_021E52B4, 128, g_021E3FE8, g_021AE01C);
		func_021BF520(g_021E52B4);
		func_02084F80(g_021E53BC, 128, g_021E4040, g_021AE01C);
		func_021BF520(g_021E53BC);
		break;
	case 0:
	default:
		func_02084F80(g_021E52B4, 128, g_021E408C, g_021AE01C);
		func_021BF520(g_021E52B4);
		func_02084F80(g_021E53BC, 128, g_021E40E4, g_021AE01C);
		func_021BF520(g_021E53BC);
		break;
	}
}
