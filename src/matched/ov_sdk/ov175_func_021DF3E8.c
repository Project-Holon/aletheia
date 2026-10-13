/*
 * function: DWC_ScReportAddIntValue
 * address:  0x021DF3E8
 * packet:   pkt_021DF3E8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   scReportAddIntValue  0x021DFDFC  arm
 *   DWCi_DWCScResultToDWCError  0x021DF5E4  arm
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *
 * Sibling of DWC_ScReportEnd against the scReportAddIntValue probe: post
 * DWCi_ScGetRequestErrorCode(10, v) against DWCi_DWCScResultToDWCError(v) when the probe reports.
 */

typedef int s32;

extern s32 scReportAddIntValue(s32);
extern s32 DWCi_DWCScResultToDWCError(s32);
extern s32 DWCi_ScGetRequestErrorCode(s32, s32);
extern void func_02059F54(s32, s32);

s32 DWC_ScReportAddIntValue(s32 a, int a1, int a2)
{
    s32 v = scReportAddIntValue(a);

    if (v != 0)
        func_02059F54(DWCi_DWCScResultToDWCError(v), DWCi_ScGetRequestErrorCode(10, v));
    return v;
}
