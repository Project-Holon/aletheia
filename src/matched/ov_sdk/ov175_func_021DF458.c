/*
 * function: DWC_ScDestroyReport
 * address:  0x021DF458
 * packet:   pkt_021DF458
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   scDestroyReport  0x021DFE14  arm
 *   DWCi_DWCScResultToDWCError  0x021DF5E4  arm
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *
 * Sibling of DWC_ScReportEnd against the scDestroyReport probe, with warning code
 * 0xd instead of 0xa.
 */

typedef int s32;

typedef unsigned int   u32;
extern int scDestroyReport(u32 *a0);
extern s32 DWCi_DWCScResultToDWCError(s32);
extern s32 DWCi_ScGetRequestErrorCode(s32, s32);
extern void func_02059F54(s32, s32);

s32 DWC_ScDestroyReport(u32 *a)
{
    s32 v = scDestroyReport(a);

    if (v != 0)
        func_02059F54(DWCi_DWCScResultToDWCError(v), DWCi_ScGetRequestErrorCode(0xd, v));
    return v;
}
