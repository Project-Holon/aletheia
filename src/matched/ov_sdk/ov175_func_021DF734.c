/*
 * function: DWCi_ScSetUseSSL
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
 *   OS_SNPrintf  0x02084F80  arm
 *   func_021BF520  0x021BF520  arm  ov114
 *   gScStatsServiceUrl  0x021E52B4  data
 *   g_021AE01C  0x021AE01C  data
 *   sDwcScStatsUrlFormatSecure2  0x021E3FE8  data
 *   gWsAuthServiceUrl  0x021E53BC  data
 *   sDwcScAuthUrlFormatSecure2  0x021E4040  data
 *   sDwcScStatsUrlFormatSecure  0x021E408C  data
 *   sDwcScAuthUrlFormatSecure  0x021E40E4  data
 */

extern int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);
extern int func_021BF520(int a);
extern char gScStatsServiceUrl[];
extern char g_021AE01C[];
extern char sDwcScStatsUrlFormatSecure2[];
extern char gWsAuthServiceUrl[];
extern char sDwcScAuthUrlFormatSecure2[];
extern char sDwcScStatsUrlFormatSecure[];
extern char sDwcScAuthUrlFormatSecure[];

void DWCi_ScSetUseSSL(int ssl_type)
{
	switch (ssl_type) {
	case 1:
		OS_SNPrintf(gScStatsServiceUrl, 128, sDwcScStatsUrlFormatSecure2, g_021AE01C);
		func_021BF520((int)gScStatsServiceUrl);
		OS_SNPrintf(gWsAuthServiceUrl, 128, sDwcScAuthUrlFormatSecure2, g_021AE01C);
		func_021BF520((int)gWsAuthServiceUrl);
		break;
	case 0:
	default:
		OS_SNPrintf(gScStatsServiceUrl, 128, sDwcScStatsUrlFormatSecure, g_021AE01C);
		func_021BF520((int)gScStatsServiceUrl);
		OS_SNPrintf(gWsAuthServiceUrl, 128, sDwcScAuthUrlFormatSecure, g_021AE01C);
		func_021BF520((int)gWsAuthServiceUrl);
		break;
	}
}
