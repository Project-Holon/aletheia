/*
 * function: DWC_ScReportBeginPlayerData
 * address:  0x021DF2C8
 * packet:   pkt_021DF2C8
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
 *   scReportBeginPlayerData  0x021DFCF4  arm
 *
 * Open the 0x021DFCF4 slot; when it hands back a handle, queue it under
 * category 0x0a and post an 8-byte message.
 */

typedef unsigned int   u32;
extern int scReportBeginPlayerData(u32 *a0);
extern int DWCi_ScGetRequestErrorCode(int, int);
extern void func_02059F54(int, int);

int DWC_ScReportBeginPlayerData(u32 *a0)
{
    int r = scReportBeginPlayerData(a0);

    if (r)
        func_02059F54(8, DWCi_ScGetRequestErrorCode(0xa, r));
    return r;
}

