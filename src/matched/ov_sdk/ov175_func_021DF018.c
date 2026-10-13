/*
 * function: DWC_ScCreateSessionAsync
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
 *   gDwcScControl     0x021E4D08  data
 *   d_021E4F34     0x021E4F34  data
 *   d_021E4D1C     0x021E4D1C  data
 *   DWCi_ScCreateSessionCallback  0x021DF07C  arm  ov175
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm
 *   scCreateSession  0x021DFAB8  arm
 */

typedef unsigned int u32;

extern u32 gDwcScControl[];
extern char d_021E4F34[];
extern char d_021E4D1C[];
extern void DWCi_ScCreateSessionCallback(u32 a, u32 b, u32 c, u32 d);
extern int scCreateSession(u32 *, u32, u32, u32, u32, u32);
extern int DWCi_ScGetRequestErrorCode(int, int);
extern void func_02059F54(int, int);

int DWC_ScCreateSessionAsync(u32 a0, u32 a1, u32 a2)
{
    int r;

    gDwcScControl[2] = a0;
    r = scCreateSession((u32 *)gDwcScControl[1], (u32)d_021E4F34, (u32)d_021E4D1C,
                      (u32)DWCi_ScCreateSessionCallback, a1, a2);
    if (r != 0)
        func_02059F54(8, DWCi_ScGetRequestErrorCode(5, r));
    return r;
}
