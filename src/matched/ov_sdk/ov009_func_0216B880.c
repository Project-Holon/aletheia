/*
 * function: DWC_GetAIDList
 * address:  0x0216B880
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_GetAIDList: fills the static aid list from the node list and returns the node count.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   g_021AA880  0x021AA880  data
 *   DWCi_IsGetAIDValid  0x0216C82C  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWCi_NodeInfoList_GetCount  0x0217603C  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;
extern unsigned char g_021AA880[];
extern int DWCi_IsGetAIDValid(void);
extern void MI_CpuFill8(void *p, int v, int n);
extern int DWCi_NodeInfoList_GetCount(void);
extern unsigned char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);

int DWC_GetAIDList(unsigned char **out)
{
    int i;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0 || DWCi_IsGetAIDValid() == 0) {
        return 0;
    }
    MI_CpuFill8(g_021AA880, 0, 0x20);
    for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
        g_021AA880[i] = DWCi_NodeInfoList_GetNodeInfoForIndex(i)[0x16];
    }
    *out = g_021AA880;
    return DWCi_NodeInfoList_GetCount();
}
