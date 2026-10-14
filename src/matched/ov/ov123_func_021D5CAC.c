/*
 * function: GSYNC_DOWNLOAD_CancelAsync
 * address: 0x021D5CAC
 * packet: pkt_ov123_021D5CAC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_NdCancelAsync 0x021C5DB4 arm ov114
 */
#include "../include/Obj06460.h"
extern int DWC_NdCancelAsync(void);
int GSYNC_DOWNLOAD_CancelAsync(char *p)
{
    if (((struct Obj06460 *)p)->fD0) return 0;
    if (((struct Obj06460 *)p)->fCC) {
        if (++((struct Obj06460 *)p)->fCC>3600) {
            ((struct Obj06460 *)p)->fD0=1;
            if (!DWC_NdCancelAsync()) ((struct Obj06460 *)p)->fC8=1;
            return 0;
        }
    }
    return 1;
}
