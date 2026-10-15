/*
 * function: DWC_ScInitialize
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
 *   gsCoreInitialize  0x0217CA40  arm  ov009
 *   DWCi_ScSetUseSSL  0x021DF734  arm  ov175
 *   DWCi_GetAuthInfo  0x0216AA9C  arm  ov009
 *   wsLoginRemoteAuth  0x021E2510  arm  ov175
 *   DWCi_ScPrintf  0x021DF4A4  arm  ov175
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm  ov175
 *   func_02059F54  0x02059F54  arm
 *   OS_Sleep  0x02085A38  arm
 *   gsCoreThink  0x0217CCCC  arm  ov009
 *   func_02059E18  0x02059E18  arm
 *   scInitialize  0x021DF9D8  arm  ov175
 *   DWCi_DWCScResultToDWCError  0x021DF5E4  arm  ov175
 *   DWCi_ScLoginCallback  0x021DF4FC  arm  ov175
 *   gDwcScControl  0x021E4D08  data
 *   sDwcScLoginFailedFormat  0x021E3F48  data
 *   g_021E4D0C  0x021E4D0C  data
 */

extern void gsCoreInitialize(void);
extern void DWCi_ScSetUseSSL(int ssl_type);
extern int DWCi_GetAuthInfo(char **authToken, char **partnerChallenge);
extern int wsLoginRemoteAuth(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge, void *userCallback, void *userData);
extern void DWCi_ScPrintf(int line, char *fmt, ...);
extern int DWCi_ScGetRequestErrorCode(int process, int error);
extern void func_02059F54(int error, int errorCode);
extern void OS_Sleep(unsigned long msec);
extern void gsCoreThink(unsigned int theMS);
extern int func_02059E18(int *errorCode);
typedef unsigned int   u32;
extern int scInitialize(u32 *p, u32 *out);
extern int DWCi_DWCScResultToDWCError(int result);
extern void DWCi_ScLoginCallback(int httpResult, void *theResponse);
extern int gDwcScControl;
extern char sDwcScLoginFailedFormat[];
extern void *g_021E4D0C;

int DWC_ScInitialize(int theGameId, int ssl_type)
{
    unsigned int gsResult;
    int result;
    char *authToken;
    char *partnerChallenge;

    gsCoreInitialize();
    DWCi_ScSetUseSSL(ssl_type);
    DWCi_GetAuthInfo(&authToken, &partnerChallenge);
    gDwcScControl = 0;
    result = wsLoginRemoteAuth(0, theGameId, authToken, partnerChallenge,
                           (void (*)(int, void *, void *))DWCi_ScLoginCallback, 0);
    if (result != 0) {
        DWCi_ScPrintf(0x8e, sDwcScLoginFailedFormat, result);
        func_02059F54(0x14, DWCi_ScGetRequestErrorCode(1, 0));
        return 7;
    }
    while (gDwcScControl == 0) {
        OS_Sleep(10);
        gsCoreThink(0);
    }
    if (func_02059E18(0) != 0)
        return 7;
    gsResult = scInitialize((u32 *)theGameId, (u32 *)(&g_021E4D0C));
    if (gsResult != 0) {
        result = DWCi_DWCScResultToDWCError(gsResult);
        func_02059F54(result, DWCi_ScGetRequestErrorCode(2, gsResult));
    }
    return gsResult;
}
