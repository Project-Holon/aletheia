/*
 * function: func_021DF130
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
 *   g_021E4D08     0x021E4D08  data
 *   d_021E4D1C     0x021E4D1C  data
 *   d_021E4F34     0x021E4F34  data
 *   func_021DF1A8  0x021DF1A8  arm  ov175
 *   func_021DFBB8  0x021DFBB8  arm  ov175
 */

typedef unsigned int u32;

extern u32 g_021E4D08[];
extern char d_021E4D1C[];
extern char d_021E4F34[];
extern void func_021DF1A8(int a, int b, int c, int d);
extern int func_021DFBB8(void *theInterface, void *theReport, int isAuthoritative, void *theCertificate, void *thePrivateData, void *theCallback, unsigned int theTimeoutMs, void *theUserData);
extern int func_021DF644(int, int);
extern void func_02059F54(int, int);

int func_021DF130(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    int r;

    g_021E4D08[4] = a2;
    r = func_021DFBB8((u32 *)g_021E4D08[1], (void *)a0, a1, (void *)((u32)d_021E4F34),
                      (void *)((u32)d_021E4D1C), (void *)((u32)func_021DF1A8), a3, (void *)a4);
    if (r != 0)
        func_02059F54(8, func_021DF644(0xb, r));
    return r;
}
