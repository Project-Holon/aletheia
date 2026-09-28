/*
 * function: func_021DF018
 * address:  0x021DF018
 * packet:   pkt_ov175_021DF018
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DWC_ScCreateSessionAsync (TwlDWC/libdwcsc.TWL.HYB.a,
 * dwc_sc.o), ov175.  Store the console/player context, then forward to
 * scCreateMatchlessSession with the fixed report endpoint and this file's
 * session callback.
 *
 * symbols:
 *   g_021E4D08     0x021E4D08  data
 *   d_021E4F34     0x021E4F34  data
 *   d_021E4D1C     0x021E4D1C  data
 *   func_021DF07C  0x021DF07C  arm  ov175
 */

typedef unsigned int u32;

extern u32 g_021E4D08[];
extern char d_021E4F34[];
extern char d_021E4D1C[];
extern void func_021DF07C(void);
extern int func_021DFAB8(u32 *, u32, u32, u32, u32, u32);
extern int func_021DF644(int, int);
extern void func_02059F54(int, int);

int func_021DF018(u32 a0, u32 a1, u32 a2)
{
    int r;

    g_021E4D08[2] = a0;
    r = func_021DFAB8((u32 *)g_021E4D08[1], (u32)d_021E4F34, (u32)d_021E4D1C,
                      (u32)func_021DF07C, a1, a2);
    if (r != 0)
        func_02059F54(8, func_021DF644(5, r));
    return r;
}
