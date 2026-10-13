/*
 * function: DWC_ScReportEnd
 * address:  0x021DF3B0
 * packet:   pkt_021DF3B0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   scReportEnd  0x021DFD18  arm
 *   DWCi_DWCScResultToDWCError  0x021DF5E4  arm
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *
 * Probe-then-post: ask the byte-read entry for the record, and when it came
 * back non-zero post the warning (DWCi_ScGetRequestErrorCode(10, v)) against the value
 * DWCi_DWCScResultToDWCError picked.  The record handle is the return value either way.
 */

typedef int s32;

extern s32 scReportEnd(s32);
extern s32 DWCi_DWCScResultToDWCError(s32);
extern s32 DWCi_ScGetRequestErrorCode(s32, s32);
extern void func_02059F54(s32, s32);

s32 DWC_ScReportEnd(s32 a)
{
    s32 v = scReportEnd(a);

    if (v != 0)
        func_02059F54(DWCi_DWCScResultToDWCError(v), DWCi_ScGetRequestErrorCode(10, v));
    return v;
}
