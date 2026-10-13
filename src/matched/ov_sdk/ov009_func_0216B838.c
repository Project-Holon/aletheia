/*
 * function: DWC_GetMyAID
 * address:  0x0216B838
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_GetMyAID: this host's aid, or 0xff when none is valid.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   DWCi_IsGetAIDValid  0x0216C82C  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID  0x021763AC  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;
extern int DWCi_IsGetAIDValid(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForProfileID(int pid);

unsigned char DWC_GetMyAID(void)
{
    unsigned char *node;

    if (*(char **)(((char *)&g_021AA878) + 4) == 0 || DWCi_IsGetAIDValid() == 0) {
        return 0xff;
    }
    node = (unsigned char *)DWCi_NodeInfoList_GetNodeInfoForProfileID(*(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x64));
    if (node == 0) {
        return 0xff;
    }
    return node[0x16];
}
