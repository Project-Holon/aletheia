/*
 * function: DWC_ScSetReportIntentionAsync
 * address:  0x021DF09C
 * packet:   pkt_ov175_021DF09C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DWC_ScSetReportIntentionAsync (TwlDWC/libdwcsc.TWL.HYB.a,
 * dwc_sc.o), ov175.  Store the intention/console id, then forward to
 * scSetReportIntention with the fixed endpoint pair and this file's callback.
 *
 * symbols:
 *   gDwcScControl     0x021E4D08  data
 *   d_021E4D1C     0x021E4D1C  data
 *   d_021E4F34     0x021E4F34  data
 *   DWCi_ScSetReportIntentionCallback  0x021DF110  arm  ov175
 *   scSetReportIntention  0x021DFB18  arm  ov175
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm
 */

typedef unsigned int u32;

extern u32 gDwcScControl[];
extern char d_021E4D1C[];
extern char d_021E4F34[];
extern void DWCi_ScSetReportIntentionCallback(int a, int b, int c, int d);
extern int scSetReportIntention(int *ctx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern int DWCi_ScGetRequestErrorCode(int, int);
extern void func_02059F54(int, int);

int DWC_ScSetReportIntentionAsync(u32 a0, u32 a1, u32 a2, u32 a3)
{
    int r;

    gDwcScControl[3] = a1;
    r = scSetReportIntention((int *)gDwcScControl[1], 0, a0, (u32)d_021E4F34,
                      (u32)d_021E4D1C, (u32)DWCi_ScSetReportIntentionCallback, a2, a3);
    if (r != 0)
        func_02059F54(8, DWCi_ScGetRequestErrorCode(7, r));
    return r;
}
