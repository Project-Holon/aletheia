/*
 * function: DWC_GetServerAID
 * address:  0x0216B9B0
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_GetServerAID: the aid of node 0 while a match is running, else 0xff.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);

unsigned char DWC_GetServerAID(void)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);
    unsigned char *node;

    if (p == 0 || *(int *)(p + 0x96c) == 0 || *(int *)(p + 0x96c) == 9 ||
        *(int *)(p + 0x96c) == 10 || *(int *)(p + 0x96c) == 11 ||
        *(unsigned char *)(p + 0x35d) == 0 || *(unsigned char *)(p + 0x366) == 0) {
        return 0xff;
    }
    node = (unsigned char *)DWCi_NodeInfoList_GetNodeInfoForIndex(0);
    if (node == 0) {
        return 0xff;
    }
    return node[0x16];
}
