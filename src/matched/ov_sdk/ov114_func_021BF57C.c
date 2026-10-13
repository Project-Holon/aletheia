/*
 * function: DWC_ShutdownGHTTP
 * address:  0x021BF57C
 * packet:   pkt_ov114_021BF57C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ShutdownGHTTP (dwc_ghttp.o)
 *
 * symbols:
 *   ghttpCleanup  0x021C204C  arm  ov114
 *   DWCi_RemoveAllDWCGHTTPParamEntry  0x021BFB20  arm  ov114
 *   gDwcGhttpParamList     0x021D3B20  data
 */

#include "../include/G_Init.h"

extern struct Init gDwcGhttpParamList;
extern void ghttpCleanup(void);
extern void DWCi_RemoveAllDWCGHTTPParamEntry(void);

int DWC_ShutdownGHTTP(void)
{
    if ((*(int *)&gDwcGhttpParamList) <= 0) {
        return 1;
    }
    ghttpCleanup();
    if (--(*(int *)&gDwcGhttpParamList) == 0) {
        DWCi_RemoveAllDWCGHTTPParamEntry();
    }
    return 1;
}
