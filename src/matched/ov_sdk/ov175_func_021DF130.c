/*
 * function: DWC_ScSubmitReportAsync
 * address:  0x021DF130
 * packet:   pkt_ov175_021DF130
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DWC_ScSubmitReportAsync (TwlDWC/libdwcsc.TWL.HYB.a,
 * dwc_sc.o), ov175.  Store the report payload, then forward to scSubmitReport
 * with the fixed endpoint pair and this file's callback.
 *
 * symbols:
 *   gDwcScControl     0x021E4D08  data
 *   d_021E4D1C     0x021E4D1C  data
 *   d_021E4F34     0x021E4F34  data
 *   DWCi_ScSubmitReportCallback  0x021DF1A8  arm  ov175
 *   scSubmitReport  0x021DFBB8  arm  ov175
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm
 */

typedef unsigned int u32;

extern u32 gDwcScControl[];
extern char d_021E4D1C[];
extern char d_021E4F34[];
extern void DWCi_ScSubmitReportCallback(int a, int b, int c, int d);
extern int scSubmitReport(void *theInterface, void *theReport, int isAuthoritative, void *theCertificate, void *thePrivateData, void *theCallback, unsigned int theTimeoutMs, void *theUserData);
extern int DWCi_ScGetRequestErrorCode(int, int);
extern void func_02059F54(int, int);

int DWC_ScSubmitReportAsync(u32 a0, u32 a1, u32 a2, u32 a3, char *a4)
{
    int r;

    gDwcScControl[4] = a2;
    r = scSubmitReport((u32 *)gDwcScControl[1], (void *)a0, a1, (void *)((u32)d_021E4F34),
                      (void *)((u32)d_021E4D1C), (void *)((u32)DWCi_ScSubmitReportCallback), a3, (void *)a4);
    if (r != 0)
        func_02059F54(8, DWCi_ScGetRequestErrorCode(0xb, r));
    return r;
}
