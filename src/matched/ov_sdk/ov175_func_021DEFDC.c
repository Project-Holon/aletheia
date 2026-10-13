/*
 * function: DWC_ScProcess
 * address:  0x021DEFDC
 * packet:   pkt_021DEFDC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   scThink  0x021DFA6C  arm
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *   gDwcScControl     0x021E4D08  data
 *
 * Same post shape as the DWC_ScReportEnd triplet, driven by the head of the
 * 0x021E4D08 control block instead of an incoming handle.
 */

typedef int s32;
typedef unsigned int u32;

extern int scThink(int *p);
extern s32 DWCi_ScGetRequestErrorCode(s32, s32);
extern void func_02059F54(s32, s32);
extern u32 gDwcScControl[];

s32 DWC_ScProcess(void)
{
    s32 v = scThink((int *)gDwcScControl[1]);

    if (v != 0)
        func_02059F54(8, DWCi_ScGetRequestErrorCode(4, v));
    return v;
}
