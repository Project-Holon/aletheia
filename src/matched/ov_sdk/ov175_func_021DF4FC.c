/*
 * function: DWCi_ScLoginCallback
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
 *   DWCi_ScPrintf  0x021DF4A4  arm  ov175
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm  ov175
 *   func_02059F54  0x02059F54  arm
 *   DWCi_HandleGHTTPError  0x021BF8C0  arm  ov114
 *   DWCi_HandleWSLoginError  0x021DF65C  arm  ov175
 *   unit_02092344  0x02092344  arm
 *   sDwcScLoginHttpErrorFormat  0x021E3F74  data
 *   sDwcScLoginResultErrorFormat  0x021E3FA0  data
 *   gDwcScLoginCertificate  0x021E4F34  data
 *   gDwcScLoginPrivateData  0x021E4D1C  data
 *   sDwcScLoggedInFormat  0x021E3FCC  data
 *   gDwcScControl  0x021E4D08  data
 */

typedef struct {
	int result;
	int pad;
	char cert[0x380];
	char priv[0x218];
} WSLoginResponse;

extern void DWCi_ScPrintf(int line, char *fmt, ...);
extern int DWCi_ScGetRequestErrorCode(int process, int error);
extern void func_02059F54(int error, int errorCode);
extern int DWCi_HandleGHTTPError(int result);
extern int DWCi_HandleWSLoginError(int result);
extern void *unit_02092344(void *dst, void *src, unsigned long n);
extern char sDwcScLoginHttpErrorFormat[];
extern char sDwcScLoginResultErrorFormat[];
extern char gDwcScLoginCertificate[];
extern char gDwcScLoginPrivateData[];
extern char sDwcScLoggedInFormat[];
extern int gDwcScControl;

void DWCi_ScLoginCallback(int httpResult, WSLoginResponse *theResponse)
{
	if (httpResult != 0) {
		DWCi_ScPrintf(0x315, sDwcScLoginHttpErrorFormat, httpResult);
		if (httpResult == 1)
			func_02059F54(9, DWCi_ScGetRequestErrorCode(1, 5));
		else
			func_02059F54(0x14, DWCi_ScGetRequestErrorCode(1, 7));
		DWCi_HandleGHTTPError(httpResult);
	} else if (theResponse->result != 0) {
		DWCi_ScPrintf(0x323, sDwcScLoginResultErrorFormat, theResponse->result);
		DWCi_HandleWSLoginError(theResponse->result);
	} else {
		unit_02092344(gDwcScLoginCertificate, theResponse->cert, 0x380);
		unit_02092344(gDwcScLoginPrivateData, theResponse->priv, 0x218);
		DWCi_ScPrintf(0x32b, sDwcScLoggedInFormat, (char *)theResponse + 0x47);
	}
	gDwcScControl = 1;
}
