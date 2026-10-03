/*
 * function: func_021DF23C
 * address:  0x021DF23C
 * packet:   pkt_ov175_021DF23C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DWC_ScCreateReport (TwlDWC/libdwcsc.TWL.HYB.a, dwc_sc.o),
 * ov175.  Forward to scCreateReport on the live session and log a failure.
 *
 * symbols:
 *   g_021E4D08     0x021E4D08  data
 *   func_021DFC8C  0x021DFC8C  arm  ov175
 */

typedef unsigned int u32;

extern u32 g_021E4D08[];
extern int func_021DFC8C(u32 *p, int a1, int a2, int a3, void **out);
extern int func_021DF644(int, int);
extern void func_02059F54(int, int);

int func_021DF23C(u32 a0, u32 a1, u32 a2, u32 a3)
{
    int r;

    r = func_021DFC8C((u32 *)g_021E4D08[1], a0, a1, a2, (void **)a3);
    if (r != 0)
        func_02059F54(8, func_021DF644(9, r));
    return r;
}
