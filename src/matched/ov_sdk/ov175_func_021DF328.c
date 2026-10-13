/*
 * function: DWC_ScReportBeginNewPlayer
 * address:  0x021DF328
 * packet:   pkt_021DF328
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
 *   scReportBeginNewPlayer  0x021DFD0C  arm
 *
 * Open the 0x021DFD0C slot; when it hands back a handle, queue it under category
 * 0x0a and post an 8-byte message.
 */

typedef unsigned char  u8;
extern int scReportBeginNewPlayer(u8 *a0);
extern int DWCi_ScGetRequestErrorCode(int, int);
extern void func_02059F54(int, int);

int DWC_ScReportBeginNewPlayer(u8 *a0)
{
    int r = scReportBeginNewPlayer(a0);

    if (r)
        func_02059F54(8, DWCi_ScGetRequestErrorCode(0xa, r));
    return r;
}

