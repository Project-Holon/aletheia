/*
 * function: func_021DF4FC
 * address:  0x021DF4FC
 * packet:   pkt_ov175_021DF4FC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ScLoginCallback (libdwcsc.TWL.HYB.a(dwc_sc.o))
 *
 * symbols:
 *   func_021DF4A4  0x021DF4A4  arm  ov175
 *   func_021DF644  0x021DF644  arm  ov175
 *   func_02059F54  0x02059F54  arm
 *   func_021BF8C0  0x021BF8C0  arm  ov114
 *   func_021DF65C  0x021DF65C  arm  ov175
 *   unit_02092344  0x02092344  arm
 *   g_021E3F74  0x021E3F74  data
 *   g_021E3FA0  0x021E3FA0  data
 *   g_021E4F34  0x021E4F34  data
 *   g_021E4D1C  0x021E4D1C  data
 *   g_021E3FCC  0x021E3FCC  data
 *   g_021E4D08  0x021E4D08  data
 */

typedef struct {
	int result;
	int pad;
	char cert[0x380];
	char priv[0x218];
} WSLoginResponse;

extern void func_021DF4A4(int line, char *fmt, ...);
extern int func_021DF644(int process, int error);
extern void func_02059F54(int error, int errorCode);
extern int func_021BF8C0(int result);
extern int func_021DF65C(int result);
extern void *unit_02092344(void *dst, void *src, unsigned long n);
extern char g_021E3F74[];
extern char g_021E3FA0[];
extern char g_021E4F34[];
extern char g_021E4D1C[];
extern char g_021E3FCC[];
extern int g_021E4D08;

void func_021DF4FC(int httpResult, WSLoginResponse *theResponse)
{
	if (httpResult != 0) {
		func_021DF4A4(0x315, g_021E3F74, httpResult);
		if (httpResult == 1)
			func_02059F54(9, func_021DF644(1, 5));
		else
			func_02059F54(0x14, func_021DF644(1, 7));
		func_021BF8C0(httpResult);
	} else if (theResponse->result != 0) {
		func_021DF4A4(0x323, g_021E3FA0, theResponse->result);
		func_021DF65C(theResponse->result);
	} else {
		unit_02092344(g_021E4F34, theResponse->cert, 0x380);
		unit_02092344(g_021E4D1C, theResponse->priv, 0x218);
		func_021DF4A4(0x32b, g_021E3FCC, (char *)theResponse + 0x47);
	}
	g_021E4D08 = 1;
}
