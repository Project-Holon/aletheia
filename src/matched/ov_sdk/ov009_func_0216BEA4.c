/*
 * function: DWCi_CloseConnectionHard
 * address:  0x0216BEA4
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_CloseConnectionHard: closes an aid's connection, or runs the closed path for a node with none.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   DWCi_IsError  0x02059F38  arm
 *   DWCi_GetGT2Connection  0x0216BAF4  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForAID  0x02176410  arm  ov009
 *   DWCi_GT2ClosedProcess  0x0216C230  arm  ov009
 *   gt2CloseConnectionHard  0x02195DC4  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;
extern int DWCi_IsError(void);
struct GTI2Connection;
extern int DWCi_GetGT2Connection(int aid);
extern char *DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
extern void DWCi_GT2ClosedProcess(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
extern void gt2CloseConnectionHard(int conn);

int DWCi_CloseConnectionHard(unsigned char aid)
{
    int conn;
    unsigned char *node;

    if (*(char **)(((char *)&g_021AA878) + 4) == 0 || DWCi_IsError() != 0 ||
        (*(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x24) != 4 &&
         *(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x24) != 5)) {
        return -1;
    }
    conn = DWCi_GetGT2Connection(aid);
    if (conn == 0) {
        node = (unsigned char *)DWCi_NodeInfoList_GetNodeInfoForAID(aid);
        if (node == 0) {
            return -2;
        }
        DWCi_GT2ClosedProcess(0, 0, 1, node[0x16]);
        return 0;
    }
    gt2CloseConnectionHard(conn);
    return 0;
}
