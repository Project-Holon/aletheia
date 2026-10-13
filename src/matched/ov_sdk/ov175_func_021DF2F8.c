/*
 * function: DWC_ScReportBeginTeamData
 * address:  0x021DF2F8
 * packet:   pkt_021DF2F8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02059F54  0x02059F54  arm
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm
 *   scReportBeginTeamData  0x021DFD00  arm
 *
 * Open the 0x021DFD00 slot; when it hands back a handle, queue it under
 * category 0x0a and post an 8-byte message.
 */

typedef unsigned int   u32;
extern int scReportBeginTeamData(u32 *a0);
extern int DWCi_ScGetRequestErrorCode(int, int);
extern void func_02059F54(int, int);

int DWC_ScReportBeginTeamData(u32 *a0)
{
    int r = scReportBeginTeamData(a0);

    if (r)
        func_02059F54(8, DWCi_ScGetRequestErrorCode(0xa, r));
    return r;
}

