/*
 * function: func_021DF09C
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
 *   g_021E4D08     0x021E4D08  data
 *   d_021E4D1C     0x021E4D1C  data
 *   d_021E4F34     0x021E4F34  data
 *   func_021DF110  0x021DF110  arm  ov175
 *   func_021DFB18  0x021DFB18  arm  ov175
 */

typedef unsigned int u32;

extern u32 g_021E4D08[];
extern char d_021E4D1C[];
extern char d_021E4F34[];
extern void func_021DF110(void);
extern int func_021DFB18(u32 *, u32, u32, u32, u32, u32, u32, u32);
extern int func_021DF644(int, int);
extern void func_02059F54(int, int);

int func_021DF09C(u32 a0, u32 a1, u32 a2, u32 a3)
{
    int r;

    g_021E4D08[3] = a1;
    r = func_021DFB18((u32 *)g_021E4D08[1], 0, a0, (u32)d_021E4F34,
                      (u32)d_021E4D1C, (u32)func_021DF110, a2, a3);
    if (r != 0)
        func_02059F54(8, func_021DF644(7, r));
    return r;
}
