/*
 * function: func_021DEE3C
 * address:  0x021DEE3C
 * packet:   pkt_ov175_021DEE3C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ScInitialize (libdwcsc.TWL.HYB.a dwc_sc.o)
 *
 * symbols:
 *   func_0217CA40  0x0217CA40  arm  ov009
 *   func_021DF734  0x021DF734  arm  ov175
 *   func_0216AA9C  0x0216AA9C  arm  ov009
 *   func_021E2510  0x021E2510  arm  ov175
 *   func_021DF4A4  0x021DF4A4  arm  ov175
 *   func_021DF644  0x021DF644  arm  ov175
 *   func_02059F54  0x02059F54  arm
 *   func_02085A38  0x02085A38  arm
 *   func_0217CCCC  0x0217CCCC  arm  ov009
 *   func_02059E18  0x02059E18  arm
 *   func_021DF9D8  0x021DF9D8  arm  ov175
 *   func_021DF5E4  0x021DF5E4  arm  ov175
 *   func_021DF4FC  0x021DF4FC  arm  ov175
 *   g_021E4D08  0x021E4D08  data
 *   g_021E3F48  0x021E3F48  data
 *   g_021E4D0C  0x021E4D0C  data
 */

extern void func_0217CA40(void);
extern void func_021DF734(int ssl_type);
extern int func_0216AA9C(char **authToken, char **partnerChallenge);
extern int func_021E2510(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge,
                         void (*userCallback)(int, void *, void *), void *userData);
extern void func_021DF4A4(int line, char *fmt, ...);
extern int func_021DF644(int process, int error);
extern void func_02059F54(int error, int errorCode);
extern void func_02085A38(unsigned long msec);
extern void func_0217CCCC(unsigned int theMS);
extern int func_02059E18(int *errorCode);
extern int func_021DF9D8(int theGameId, void **theInterfaceOut);
extern int func_021DF5E4(int result);
extern void func_021DF4FC(int httpResult, void *theResponse);
extern int g_021E4D08;
extern char g_021E3F48[];
extern void *g_021E4D0C;

int func_021DEE3C(int theGameId, int ssl_type)
{
    unsigned int gsResult;
    int result;
    char *authToken;
    char *partnerChallenge;

    func_0217CA40();
    func_021DF734(ssl_type);
    func_0216AA9C(&authToken, &partnerChallenge);
    g_021E4D08 = 0;
    result = func_021E2510(0, theGameId, authToken, partnerChallenge,
                           (void (*)(int, void *, void *))func_021DF4FC, 0);
    if (result != 0) {
        func_021DF4A4(0x8e, g_021E3F48, result);
        func_02059F54(0x14, func_021DF644(1, 0));
        return 7;
    }
    while (g_021E4D08 == 0) {
        func_02085A38(10);
        func_0217CCCC(0);
    }
    if (func_02059E18(0) != 0)
        return 7;
    gsResult = func_021DF9D8(theGameId, &g_021E4D0C);
    if (gsResult != 0) {
        result = func_021DF5E4(gsResult);
        func_02059F54(result, func_021DF644(2, gsResult));
    }
    return gsResult;
}
