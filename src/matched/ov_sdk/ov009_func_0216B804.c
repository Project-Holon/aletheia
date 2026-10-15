/*
 * function: DWC_GetNumConnectionHost
 * address:  0x0216B804
 * packet:   pkt_ov009_0216B804
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetNumConnectionHost (dwc_main.o)
 *
 * symbols:
 *   DWCi_IsGetAIDValid  0x0216C82C  arm  ov009
 *   DWCi_NodeInfoList_GetCount  0x0217603C  arm  ov009
 *   gDwcGlobalState     0x021AA878  data
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal gDwcGlobalState;
extern int DWCi_IsGetAIDValid(void);
extern int DWCi_NodeInfoList_GetCount(void);

int DWC_GetNumConnectionHost(void)
{
    int num;

    if (*(char **)(((char *)&gDwcGlobalState) + 4) == 0 || DWCi_IsGetAIDValid() == 0) {
        num = 0;
    } else {
        num = DWCi_NodeInfoList_GetCount();
    }
    return num;
}
