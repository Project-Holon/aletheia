/*
 * function: func_021DF110
 * address:  0x021DF110
 * packet:   pkt_ov175_021DF110
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DWCi_ScSetReportIntentionCallback
 * (TwlDWC/libdwcsc.TWL.HYB.a, dwc_sc.o), ov175.  Callback trampoline: the two
 * trailing arguments are forwarded to the stored +0xc handler.
 *
 * symbols:
 *   g_021E4D08  0x021E4D08  data
 */

typedef unsigned int u32;

extern u32 g_021E4D08[];

void func_021DF110(int a, int b, int c, int d)
{
    ((void (*)(int, int))g_021E4D08[3])(c, d);
}
